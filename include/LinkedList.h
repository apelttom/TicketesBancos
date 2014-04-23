#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <stdexcept>
using namespace std;

template <typename E>
class LinkedList
{
    private:
        Node<E>* head;
        Node<E>* tail;
        Node<E>* current;
        int size;

        // M�todo auxiliar que recibe un puntero a un nodo
        // y retorna el elemento anterior en la lista
        Node<E>* searchPrevious(Node<E>* pNode) {
            if (current == head) {
                return NULL;
            }
            Node<E> *res = head;
            while (res->next != current) {
                res = res->next;
            }
            return res;
        }
    public:
        // Inicializa la estructura
        // Inicializa la estructura vacia
        LinkedList()
        {
            head = tail = current = new Node<E>;
            size = 0;
        }

        // Libera la memoria solicitada por la estructura
        ~LinkedList()
        {
            clear();
            delete head;
            delete current;
            delete tail;
        }
        // Inserta un elemento en la posici�n actual
        void insert(E pElement)
        {
            current -> next = new Node<E>(pElement, current->next);
            if (current == tail)
            {
                tail = current->next;
            }
            size++;
        }
        // Inserta un elemento en el final de la lista
        void append(E pElement)
        {
            tail->next = new Node<E>(pElement, NULL);
            tail = tail->next;
            size++;
        }
        // Elimina el elemento actual, si no hay elemento levanta una excepci�n
        E remove() throw(runtime_error)
        {
            if (current->next == NULL)
            {
                throw runtime_error("No element to remove");
            }
            Node<E> * tmp = current->next;
            E result = tmp->element;
            if(tmp == tail) tail = current;
            current->next = tmp->next;
            delete tmp;
            size --;
            return result;
        }
        // Elimina todos los elementos de la lista e inicializa el nodo especial
        void clear()
        {
            current = head;
            while (head != NULL)
            {
                head = head->next;
                delete current;
                current = head;
            }
            head = tail = current = new Node<E>();
            size = 0;
        }
        // Obtiene el valor del elemento actual
        E getElement() throw(runtime_error)
        {
            if (current->next == NULL) {
                throw runtime_error("No element to get.");
            }
            Node <E> * tmp = current -> next;
            return tmp->element;
        }
        // Mueve la posici�n actual al inicio de la lista
        void goToStart()
        {
            current = head;
        }
        // Mueve la posici�n actual al final de la lista
        void goToEnd()
        {
            current = tail -> previous();
        }
        // Mueve la posici�n actual al �ndice indicado en el par�metro
        void goToPos(int nPos) throw(range_error)
        {
            if ((nPos < 0) || (nPos > size))
            {
                throw range_error("Index out of bounds");
            }
            for (int i = nPos; i > 0; i--)
            {
                current -> next;
            }
        }
        // Mueve la posici�n actual al elemento anterior,
        // no se mueve si ya se encuentra al inicio de la lista
        void previous()
        {
            if (current == head)
            {
                cout << "Ya se encuentra al inicio de la lista" << endl;
            }
            Node <E> * tmp = head;
            while (tmp ->next != current)
            {
                tmp ->next;
            }
            current = tmp;
        }
        // Mueve la posici�n actual al elemento siguiente,
        // no se mueve si ya se encuentra al final de la lista
        void next()
        {
            if (current -> next == tail)
            {
                cout << "Ya se encuentra al final de la lista" << endl;
            }
            current = current->next;
        }
        // Obtiene el �ndice de la posici�n actual
        int getPos()
        {
            int pos = 0;
            Node <E> * tmp = head;
            while (tmp != current)
            {
                tmp = tmp->next;
                pos++;
            }
            return pos;
        }
        // Obtiene la cantidad de elementos en la lista
        int getSize()
        {
            return size;
        }

        void imprimirLista(LinkedList* lista)
        {
            for (lista->goToStart(); lista->getPos() < lista->getSize(); lista->next())
            {
                cout << lista->getElement() << endl;
            }
        }
};

#endif // LINKEDLIST_H
