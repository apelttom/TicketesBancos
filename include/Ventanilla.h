#ifndef VENTANILLA_H
#define VENTANILLA_H

#include "Node.h"
#include "Tiquetes.h"
#include <stdexcept>
#include <string.h>
using namespace std;

class Ventanilla
{
    private:
        string iD;
        Tiquetes tiquete;

    public:
        Ventanilla()
        {
            iD = "Undefined";
//            tiquete = ;
        }

        Ventanilla(string pID)
        {
            iD = pID;
        }

        Ventanilla(string pID, Tiquetes & pTiquete)
        {
            iD = pID;
            tiquete = pTiquete;
        }

        ~Ventanilla(){}
        //virtual void Atender();

        string getID() const { return iD; }

        void setID(string pID){ iD = pID; }

        Tiquetes const& getTiquete() const { return tiquete; }

        void setTiquete(const Tiquetes & pTiquete){ tiquete = pTiquete; }

        bool hasAssignTicquet() const
        {
            //TODO test this
            if(tiquete.getNumero() != "UNDEFINED")
            {
                return true;
            }
            else
            {
                return false;
            }
        }

};

std::ostream& operator<<(std::ostream &strm, const Ventanilla &ventanilla) {
  if(ventanilla.hasAssignTicquet())
  {
    return strm << "Ventanilla(" << "ID = " << ventanilla.getID() << ",  Ticket number: " << ventanilla.getTiquete().getNumero() << ")";
  }
  else
  {
    return strm << "Ventanilla(" << "ID = " << ventanilla.getID() << ",  Esa ventanilla esta libre."<< ")";
  }
}

#endif // VENTANILLA_H
