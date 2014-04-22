#ifndef VENTANILLA_H
#define VENTANILLA_H

#include "Node.h"
#include <stdexcept>
using namespace std;

template <typename E>
class Ventanilla
{
    protected:
    private:
        string iD;
        // tipo
        //Node <Usuario>* ultimoUsuario;

    public:
        Ventanilla(string pID)
        {
            iD = pID;
        }

        virtual ~Ventanilla();
        virtual void Atender();


};

#endif // VENTANILLA_H
