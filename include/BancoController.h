#ifndef BANCOCONTROLLER_H
#define BANCOCONTROLLER_H

#include "MenuPrinc.h"
#include <string>
/**
 *  This class is a Singleton pattern. We cannot instance it,
 *  we can only obtain one instance by calling getInstance method
 */
class BancoController
{

    private:
        MenuPrinc *menu;
        Servicios *servicios;
        LinkedList<TipoVentanilla> * listaTipoVent;

        // Private constructor
        BancoController()
        {
            menu = new MenuPrinc();
            servicios = new Servicios();
            listaTipoVent = new LinkedList<TipoVentanilla>();
        }

        BancoController(BancoController const&); // Don't implement
        void operator=(BancoController const&); // Don't implement

    public:

        /* Is used for creating instance for the first time and returning
         * it for every other call. That is the Singleton = initialized
         * only for the first time.
         */
        static BancoController& getInstance()
        {
            static BancoController instance;
            return instance;
        }

        void mainMenu()
        {
            MenuPrinc::OPCION_ELEGIDA userResponse = menu->menuPrin();
            switch(userResponse)
            {
            case MenuPrinc::VER_ESTADO:
                //TODO todavia se tiene que programar
                break;
            case MenuPrinc::SOLICITAR_TIQUETE:
                solicitarTiquete(menu->menuSolicTiquet());
                break;
            case MenuPrinc::ATENDER:
                //TODO todavia se tiene que programar
                break;
            case MenuPrinc::ADMINISTRACION:
                administracion(menu->menuAdmin());
                break;
            case MenuPrinc::ESTADISTICAS:
                //TODO estatistica se tiene que programar
                menu->menuStats();
                break;
            case MenuPrinc::SALIR:
                //EXIT
                exit(EXIT_SUCCESS);
                break;
            default:
                errorHandler(userResponse);
            }
        }

        void errorHandler(MenuPrinc::OPCION_ELEGIDA response)
        {
            if(response == MenuPrinc::ERROR)
            {
                cout << "APPLICATION HAVE ENCOUNTERED AN ERROR!";
                exit(EXIT_FAILURE);
            }
        }

        void solicitarTiquete(MenuPrinc::OPCION_ELEGIDA userResponse)
        {
            servicios->imprimeServicios();
            int choosedService = elegirServicio();
            switch(userResponse)
            {
            case MenuPrinc::SOLICITAR_TIQUETE:
                empujeEnCola(servicios->getServElement(choosedService), false);
                break;
            case MenuPrinc::SOLICITAR_TIQUETE_PRIORIDAR:
                empujeEnCola(servicios->getServElement(choosedService), true);
                break;
            default:
                errorHandler(userResponse);
                if(userResponse == MenuPrinc::MENU_ANTERIOR)
                {
                    mainMenu();
                }
            }
        }

        void administracion(MenuPrinc::OPCION_ELEGIDA userResponse)
        {
            switch(userResponse)
            {
            case MenuPrinc::AGREGAR_VENTANILLA:
                crearVentanilla();
                break;
            case MenuPrinc::ELIMINAR_VENTANILLA:
                eliminarVentanilla();//TODO programar funcion eliminar ventanilla
                break;
            case MenuPrinc::AGREGAR_SERVICIO:
                crearServicio();
                break;
            case MenuPrinc::ELIMINAR_SERVICIO:
                eliminarServicio();
                break;
            case MenuPrinc::REORDENAR_SERVICIOS:
                reordenarServicios();
                break;
            default:
                errorHandler(userResponse);
                if(userResponse == MenuPrinc::MENU_ANTERIOR)
                {
                    mainMenu();
                }
            }
        }

        void crearVentanilla()
        {
            string nombre;
            string codigo;
            int opcServ;
            int cantVent;
            cout << "agregar ventanilla" << endl;
            cout << "Por favor elige un servicio de la siguiente lista" << endl;
            servicios->imprimeServicios();
            cout << "Digite el numero del servicio" << endl;
            cin >> opcServ;
            opcServ = opcServ - 1;
            Servicio servPtr;
            servPtr = servicios->getServElement(opcServ);
            codigo = servPtr.getTypo();
            cout << "Por favor Digite una descripcion para un nuevo tipo de ventanilla" << endl;
            cin.ignore();
            getline(cin, nombre);
            cout << "Por favor Digite la cantidad de ventanillas para este tipo" << endl;
            cin >> cantVent;
            TipoVentanilla * tipoVent = new TipoVentanilla(nombre, codigo, cantVent, servPtr);
            listaTipoVent->append(*tipoVent);
            cout << listaTipoVent->getSize() << endl;
            delete tipoVent;
            system("pause");
            //Agrega un nuevo tipo de ventanillas con su descripción, código y cantidad.
            administracion(menu->menuDefVent());
        }

        void eliminarVentanilla()
        {
            string codigVent;
            cout << "Por favor ingrese el nombre del tipo de ventanilla que desea eliminar" << endl;
            cin >> codigVent;
            listaTipoVent->goToStart();
            for(;listaTipoVent->getPos()<listaTipoVent->getSize();listaTipoVent->next()){
                TipoVentanilla temp = listaTipoVent->getElement();
                if(temp.getCodigo().compare(codigVent)==0){
                    listaTipoVent->remove();
                }
            }
            cout << "Se elimino el tipo de ventanilla con el codigo: " << codigVent << endl;
            system("pause");
            administracion(menu->menuDefVent());
        }

        void crearServicio()
        {
            string servicioNombre;
            string servicioDesc;
            string servicioTypo;
            cout << "Por favor entrega un nombre de nuevo servicio:" << endl;
            cin >> servicioNombre;
            cout << "Por favor entrega un typo de nuevo servicio:" << endl;
            cin >> servicioTypo;
            cout << "Por favor entrega una descripcion de nuevo servicio:" << endl;
            //TODO not working with whole sentance REPAIR
            cin.ignore();
            getline(cin, servicioDesc);
            Servicio * nuevoServicio = new Servicio(servicioNombre,servicioTypo,servicioDesc);
            servicios->agregarServicio(*nuevoServicio);
            servicios->imprimeServicios();
            delete nuevoServicio;
            system("pause");
            //TODO Agrega un nuevo tipo de servicio con su descripcion y tipo de ventana asignada
            administracion(menu->menuDefServic());
        }

        void eliminarServicio()
        {
            string servicioNombre;
            cout << "Por favor entrega un nombre de nuevo servicio:" << endl;
            cin >> servicioNombre;
            try
            {
                servicios->borarServicio(servicioNombre);
            }
            catch (exception& e)
            {
                cout << "There is no such service in the list." << endl;
                system("pause");
                administracion(menu->menuDefServic());
            }
            cout << "Sucessfully deleted service \"" << servicioNombre << "\"" << endl;
            system("pause");
            administracion(menu->menuDefServic());
        }

        void reordenarServicios()
        {
            servicios->imprimeServicios();
            int pos1;
            int pos2;
            cout << "Por favor elige dos servicios cuales serán intercambios." << endl;
            cout << "Numero de primer servicio para intercambiar: ";  cin >> pos1;
            cout << "Numero de segundo servicio para intercambiar: ";  cin >> pos2;
            if(pos1 == pos2)
            {
                cout << "No se pueden intercambiar los mismos servicios!" << endl;
                system("pause");
                administracion(menu->menuDefServic());
                return;
            }
            servicios->reordenarServicios(pos1, pos2);
            servicios->imprimeServicios();
            system("pause");
            administracion(menu->menuDefServic());
        }

        int elegirServicio()
        {
            int opcServ;
            cout << "Por favor elige un servicio de la siguiente lista" << endl;
            servicios->imprimeServicios();
            cout << "Digite el numero del servicio: ";
            cin >> opcServ;
            opcServ--;
            return opcServ;
        }

        void empujeEnCola(Servicio servicio, bool priority)
        {
            //TODO implement queue push
//            Tiquetes  = new Tiquetes()
        }

        void imprimirTipoVent()
        {
            listaTipoVent->goToStart();
            for (int i = 1; listaTipoVent->getPos()<listaTipoVent->getSize();listaTipoVent->next())
            {
                cout << listaTipoVent->getElement() << endl;
            }
        }
};

#endif // BANCOCONTROLLER_H
