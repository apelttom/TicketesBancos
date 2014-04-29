#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Queue.h"
#include "MenuPrinc.h"
#include "BancoController.h"
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>

////using namespace std;

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

    cout << "////////////////////////////////////////////////////////////////////" << endl;

    // De int a String
    int cont = 29;
    stringstream stream;
    string iD;
    stream << cont;
    iD = stream.str();
    iD += "ASC";
    cout << "EL convertido es: " << iD << endl;

    //De char a String
    char arr[ ] = "This is a test";
    string str(arr);
    str += " si sirvio";
    cout << "El convertido de char a string es: " << str << endl;

    /* guardar un char con espacios
    char pruebaEsp[90];
    cout << "digite una palabra cn espacios: " << endl;
    cin.getline(pruebaEsp, 30);
    cout << "esta es: " << pruebaEsp << endl;
    */

    cout << "////////////////////////////////////////////////////////////////////" << endl;

    // prueba de menu princ
//    MenuPrinc * tmp = new MenuPrinc();
//    tmp->menuPrin();

    BancoController::getInstance().mainMenu();

    return 0;
}
