#ifndef VENTANILLA_H
#define VENTANILLA_H

#include "Node.h"
#include <stdexcept>
using namespace std;


class Ventanilla
{
    protected:
    private:
        string iD;
        // tipo
        //Node <Usuario>* ultimoUsuario;

    public:
        Ventanilla()
        {
            iD = "Undefined";
        }
        Ventanilla(string pID)
        {
            iD = pID;
        }

        ~Ventanilla(){}
        //virtual void Atender();


};

#endif // VENTANILLA_H
