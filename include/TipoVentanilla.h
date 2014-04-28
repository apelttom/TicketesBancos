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
#include <stddef.h>

using namespace std;


class TipoVentanilla
{
    protected:
    private:
        string descripcion;
        string codigo;              //codigo de la ventanilla
        int cantVentAsoc;           // Numero de ventanillas que estan abiertas de este tipo
        Servicio servicio;
        LinkedList<Ventanilla>* ventanillas;
        Queue<Tiquetes>* tiquetesNormales;
        Queue<Tiquetes>* tiquetesPrior;

    public:
        TipoVentanilla()
        {
            descripcion = "UNDEFINED";
            codigo = "UNDEFINED";
            cantVentAsoc = 0;
            ventanillas = new LinkedList<Ventanilla>();
            tiquetesNormales = new Queue<Tiquetes>();
            tiquetesPrior = new Queue<Tiquetes>();
        }
        // El constructor recibe una descripcion sobre que va a hacer
        TipoVentanilla(string pDesc, string pCodigo, int pCantV_A, Servicio pServicio)
        {
            descripcion = pDesc;
            codigo = pCodigo;
            cantVentAsoc = pCantV_A;
            servicio = pServicio;
            ventanillas = new LinkedList<Ventanilla>();
            tiquetesNormales = new Queue<Tiquetes>();
            tiquetesPrior = new Queue<Tiquetes>();                   //cola solo de  usuarios preferenciales
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

        string getCodigo()
        {
            return codigo;
        }
/*
        Ventanilla borraTipoVent(string nombre)
        {
            ventanillas->goToStart();
            for(;ventanillas->getPos()<ventanillas->getSize();ventanillas->next()){
                TipoVentanilla temp = ventanillas->getElement();
                if(temp.getNombre().compare(nombre)==0){
                    return ventanillas->remove();
                }
            }
        }

        void imprimeTipoVent(){
            ventanillas->goToStart();
            for(int i = 1;ventanillas->getPos()<ventanillas->getSize();ventanillas->next()){
                cout << i++ << " " << ventanillas->getElement() << endl;
            }
        }
*/
};

#endif // TIPOVENTANILLA_H
