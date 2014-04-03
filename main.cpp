#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Queue.h"

using namespace std;

int main()
{
    // Here we will start our application
    cout << "Hello world!" << endl;
    // Probamos crear una lista
        cout << endl;
    cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
    cout << endl;
    cout << "Prueba de operaciones de lista " << endl;
    LinkedList<int> * lista = new LinkedList<int>();
    lista->insert(10);
    lista->insert(5);
    lista->append(20);
    cout << lista->getPos() << endl;
    cout << "Imprimir lista " << endl;
    lista->imprimirLista(lista);
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    //Probamos creando una cola sus operaciones
    cout << "Prueba de operaciones de cola " << endl;
    Queue<int> * cola = new Queue<int>();
    cola->Enqueue(0);
    cola->Enqueue(1);
    cola->Enqueue(2);
    cola->Enqueue(3);
    cola->Enqueue(4);
    cola->Enqueue(5);
    cout << "Desencolado:  " << cola->Dequeue() << endl;
    cout << "Imprimir Front value " << endl;
    cout << cola->getFrontValue()<< endl;
    cout << "Imprimir cola " << endl;
    cola->imprimirCola();
    //cola->imprimirCola();
    return 0;
}
