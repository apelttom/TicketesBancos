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

        Servicio getServElement(int pos)
        {
            servicios->goToPos(pos);
            Servicio temp = servicios->getElement();
            cout << temp << endl;
            return temp;
        }

        Servicio borarServicio(string nombre) throw (runtime_error)
        {
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
            for(int i = 1;servicios->getPos()<servicios->getSize();servicios->next()){
                cout << i++ << " " << servicios->getElement() << endl;
            }
        }

        /*
         *
         */
        void reordenarServicios(int pos1, int pos2)
        {
            if(pos1>pos2){
                int temp = pos1;
                pos1 = pos2;
                pos2 = temp;
            }
            if(pos1 > 0 && pos2 > 0 && pos1 <= servicios->getSize() && pos2 <= servicios->getSize()){
                pos1--;
                pos2--;
                servicios->goToPos(pos1);
                Servicio elem1 = servicios->getElement();
                servicios->goToPos(pos2);
                Servicio elem2 = servicios->getElement();
                servicios->goToStart();
                LinkedList<Servicio> *swappedServicios = new LinkedList<Servicio>();
                for(;servicios->getPos()<servicios->getSize();servicios->next()){
                    if(servicios->getPos() == pos1){
                        swappedServicios->append(elem2);
                    }
                    else if(servicios->getPos() == pos2){
                        swappedServicios->append(elem1);
                    }
                    else{
                        swappedServicios->append(servicios->getElement());
                    }
                }
//                cout << "Just swapped. Size of swapped: " << swappedServicios->getSize() << "Result:" << endl;
//                swappedServicios->goToStart();
//                for(int i = 1;swappedServicios->getPos()<swappedServicios->getSize();swappedServicios->next()){
//                    cout << i++ << " " << swappedServicios->getElement() << endl;
//                }
                delete servicios;
                servicios = swappedServicios;
                return;
            }
            cout << "No hay servicios en estos positiones." << endl;
        }
};

#endif // SERVICIOS_H
