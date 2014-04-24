#ifndef TIPOVENTANILLA_H
#define TIPOVENTANILLA_H

#include <stdexcept>
#include "LinkedList.h"
#include "Queue.h"
#include "Ventanilla.h"
#include "Tiquetes.h"
#include "Servicios.h"
#include "Servicio.h"

#include <sstream>
#include <string>

using namespace std;


class TipoVentanilla
{
    protected:
    private:
        string descripcion;
        string codigo;              //codigo de la ventanilla
        int cantVentAsoc;           // Numero de ventanillas que estan abiertas de este tipo
        Servicio servicio;
    public:
        // El constructor recibe una descripcion sobre que va a hacer
        TipoVentanilla(string pDesc, string pCodigo, int pCantV_A)
        {
            descripcion = pDesc;
            codigo = pCodigo;
            cantVentAsoc = pCantV_A;
            //servicio = pServicio;
            LinkedList<Ventanilla>* ventanillas = new LinkedList<Ventanilla>();
            //Queue<Tiquetes>* tiquetesNormales = new Queue<Tiquetes>();
            //Queue<Tiquetes>* tiquetesPrior = new Queue<Tiquetes>();                   //cola solo de  usuarios preferenciales
            cout << "Se creo tipo ventanilla: " << codigo << endl;
            CrearVentanillas(cantVentAsoc, ventanillas);
        }
        ~TipoVentanilla()
        {
        }


        // crea la cantidad de ventanillas que se pasaron como parametro en el constructor
        void CrearVentanillas(int pCantV, LinkedList <Ventanilla>* pVentanillas)
        {
            LinkedList<Ventanilla>* ventanillas = pVentanillas;
            int cantV = pCantV;
            for (int cont = 0; cont < cantV; cont++)
            {
                stringstream stream;
                string iD;
                stream << cont;
                iD = stream.str();
                Ventanilla * tmp = new Ventanilla(iD);
                ventanillas->insert(*tmp);
                cout << "Se creo ventanilla: " << iD << endl;
            }
        }

};

#endif // TIPOVENTANILLA_H
