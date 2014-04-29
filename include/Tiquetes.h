#ifndef TIQUETES_H
#define TIQUETES_H

#include "Servicio.h"

class Tiquetes
{
    protected:
    private:
        string numero;
        Servicio servicio;
        string ventanilla;
    public:

        Tiquetes()
        {
            numero  = "UNDEFINED";
            ventanilla = "UNDEFINED";
        }

        Tiquetes(string pNumero, Servicio pServicio, string pVentanilla)
        {
            numero = pNumero;
            servicio = pServicio;
            ventanilla = pVentanilla;
        }
        ~Tiquetes()
        {
        }

};

#endif // TIQUETES_H
