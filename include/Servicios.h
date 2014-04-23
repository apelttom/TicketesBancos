#ifndef SERVICIOS_H
#define SERVICIOS_H

#include "Servicio.h"
#include <string>
class Servicios
{
    private:
        LinkedList<Servicio> *servicios;

    public:
        Servicios(){
            servicios = new LinkedList<Servicio>();
        }

        Servicios(Servicio& pServicio){
            servicios = new LinkedList<Servicio>();
            servicios->append(pServicio);
        }

        ~Servicios(){
            servicios->~LinkedList();
        }

        void agregarServicio(Servicio& serv){
            servicios->append(serv);
        }

        Servicio borarServicio(string nombre) throw (runtime_error){
            servicios->goToStart();
            for(;servicios->getPos()<servicios->getSize();servicios->next()){
                Servicio temp = servicios->getElement();
                if(temp.getNombre().compare(nombre)==0){
                    return servicios->remove();
                }
            }
            throw runtime_error("There is no such service in the list.");
        }

        void imprimeServicios(){
            servicios->goToStart();
            for(;servicios->getPos()<servicios->getSize();servicios->next()){
                cout << servicios->getElement() << endl;
            }
        }

};

#endif // SERVICIOS_H
