#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <stdexcept>
using namespace std;

template <typename E>
class Queue
{
    private:
        Node<E>* Front;
        Node<E>* rear;
        int Qsize;
    public:

    Queue()
    {
        //ctor
        Front = rear = new Node<E>();
        Qsize = 0;
    }

    ~Queue()
    {
        //dtor
        EmptyQueue();
        delete Front;
    }

    void Enqueue(const E& element)
    {
        rear->next = new Node<E>(element, NULL);
        rear = rear->next;
        Qsize++;
    }

    E Dequeue()
    {
        if (Qsize == 0)
        {
            cout << "Queue is empty" << endl;
        }
        E it = Front->next->element;
        Node<E>* tmp = Front->next;
        Front->next = tmp->next;
        if (rear == tmp)
        {
                rear = Front;
        }
        delete tmp;
        Qsize --;
        return it;
    }

    void EmptyQueue()
    {
        rear = Front->next;
        while (Front->next != NULL)
        {
            Front->next = Front->next->next;
            delete rear;
            rear = Front->next;
        }
        rear = Front;
        Qsize = 0;
    }

    const E& getFrontValue() const
    {
        if (Qsize == 0)
        {
            cout << "La cola esta vacia" << endl;
        }
        return Front->next->element;
    }

    int getSize()
    {
        return Qsize;
    }

    void imprimirCola()
    {
        Node<E>* recorredor = Front;
        for (int rSize = Qsize; rSize > 0; rSize--)
        {
            cout << recorredor->next->element << endl;
            recorredor = recorredor -> next;
        }
    }
};

#endif // QUEUE_H
