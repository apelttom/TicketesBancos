#ifndef TIQUETES_H
#define TIQUETES_H

#include "Servicio.h"

class Tiquetes
{
    protected:
    private:
        string numero;
        Servicio servicio;
    public:

        Tiquetes()
        {
            numero  = "UNDEFINED";
            servicio = *(new Servicio());
        }

        Tiquetes(string pNumero, Servicio &pServicio)
        {
            numero = pNumero;
            servicio = pServicio;
        }
        ~Tiquetes()
        {
        }

        string getNumero() const { return numero; }

};

std::ostream& operator<<(std::ostream &strm, const Tiquetes &tiquete) {
  return strm << "" << ")";
}

#endif // TIQUETES_H
