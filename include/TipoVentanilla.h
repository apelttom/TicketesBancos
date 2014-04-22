#ifndef TIPOVENTANILLA_H
#define TIPOVENTANILLA_H

#include <stdexcept>
#include "LinkedList.h"
#include "Queue.h"
#include "Ventanilla.h"

using namespace std;

template <typename E>
class TipoVentanilla
{
    protected:
    private:
        string descripcion;
        string nombre;              //codigo de la ventanilla
        int cantVentAsoc;           // Numero de ventanillas que estan abiertas de este tipo
        //Servicio servicio;
    public:
        // El constructor recibe una descripcion sobre que va a hacer
        TipoVentanilla(string pDesc, string pNombre, int pCantV_A)
        {
            descripcion = pDesc;
            nombre = pNombre;
            cantVentAsoc = pCantV_A;
            //servicio = pServicio;
            LinkedList <Ventanilla>* ventanillas = new LinkedList<Ventanilla>();
            Queue <Usuario>* usuariosNormales = new Queue<Usuario>();
            Queue <Usuario>* usuariosPrior = new Queue<Usuario>();                   //cola solo de  usuarios preferenciales
            CrearVentanillas(cantVentAsoc);
        }
        virtual ~TipoVentanilla();


        // crea la cantidad de ventanillas que se pasaron como parametro en el constructor
        void CrearVentanillas(int pCantV)
        {
            int cont = 1;
            for (int cant = pCantV; cant != 0; cant--)
            {
                //string iD = (servicio->getTypo()) + cont;    parchar contador
                Ventanilla tmp = new Ventanilla(ID);
                ventanillas->insert(tmp);
            }
        }

};

#endif // TIPOVENTANILLA_H
