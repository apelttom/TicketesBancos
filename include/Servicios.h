#ifndef SERVICIOS_H
#define SERVICIOS_H

#include "Servicio.h"
#include <string>
class Servicios
{
    private:
        LinkedList<Servicios> *servicios;

    public:
        Servicios(){
            servicios = new LinkedList<Servicios>();
        }

        Servicios(Servicio& pServicio){
            servicios = new LinkedList<Servicios>();
            servicios->append(pServicio);
        }

        ~Servicios(){
            servicios->~LinkedList();
        }

        void agregarServicio(Servicio& nuevo){
            servicios->append(nuevo);
        }

/*
        Servicio borarServicio(string nombre){
            servicios->goToStart();
            for(;servicios->getPos()+1<servicios->getSize();servicios->next()){
                Servicio temp = (Servicio) servicios->getElement();
                if(temp->getNombre().compare(nombre)==0){
                    servicios->remove();
                    return temp;
                }
            }

        } */

};

#endif // SERVICIOS_H
