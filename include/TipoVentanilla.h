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
        int tiquetesCont;
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
            tiquetesCont = 1;
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
            tiquetesCont = 1;
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

        void solicitarTiqueteNormal(Tiquetes &tiquete)
        {

            tiquetesNormales->Enqueue(tiquete);
        }

        void solicitarTiquetePrior(Tiquetes &tiquete)
        {
            tiquetesPrior->Enqueue(tiquete);
        }

        void atenderTiquete()
        {
            tiquetesNormales->Dequeue();
        }

        void atenderTiquetePrior()
        {
            tiquetesPrior->Dequeue();
        }
        int getCounter() const
        {
            return tiquetesCont;
        }

        void incrementCounter(){ tiquetesCont++; }

        string getDescription() const { return descripcion; }

        string getCodigo(){ return codigo; }

        int getCantVentAsoc(){ return cantVentAsoc; }

        Servicio const& getServicio() const { return servicio; }

        void imprimirVentanillas() const
        {
            ventanillas->imprimirLista(ventanillas);
        }

        void imprimirColaNormal() const
        {
            tiquetesNormales->imprimirCola();
        }

        void imprimirColaPrior() const
        {
            tiquetesPrior->imprimirCola();
        }

};

std::ostream& operator<<(std::ostream &strm, const TipoVentanilla &typoVentanilla) {
    cout << "Grupo de ventanillas(" << "Description = " << typoVentanilla.getDescription() << ") Lista de ventanillas:" << endl << endl;
    typoVentanilla.imprimirVentanillas();
    cout << endl;
    cout << "Cola normal:" << endl;
    typoVentanilla.imprimirColaNormal();
    cout << "Cola prioridad:" << endl;
    typoVentanilla.imprimirColaPrior();
    return strm;
}

#endif // TIPOVENTANILLA_H
