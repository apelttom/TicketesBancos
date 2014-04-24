#ifndef BANCOCONTROLLER_H
#define BANCOCONTROLLER_H

#include "MenuPrinc.h"

/**
 *  This class is a Singleton pattern. We cannot instance it,
 *  we can only obtain one instance by calling getInstance method
 */
class BancoController{

    private:
        MenuPrinc *menu;
        Servicios *servicios;

        // Private constructor
        BancoController()
        {
            menu = new MenuPrinc();
            servicios = new Servicios();
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
                solicitarTiquete();
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
            if(response == MenuPrinc::ERROR){
                cout << "APPLICATION HAVE ENCOUNTERED AN ERROR!";
                exit(EXIT_FAILURE);
            }
        }

        void solicitarTiquete()
        {
            MenuPrinc::OPCION_ELEGIDA userResponse = menu->menuSolicTiquet();
            switch(userResponse)
            {
                // Add more cases here
            default:
                errorHandler(userResponse);
                if(userResponse == MenuPrinc::MENU_ANTERIOR){
                    mainMenu();
                }
            }
        }

        void administracion(MenuPrinc::OPCION_ELEGIDA userResponse)
        {
            string foo;
            switch(userResponse)
            {
            case MenuPrinc::AGREGAR_VENTANILLA:
                crearVentanilla();
                break;
            case MenuPrinc::ELIMINAR_VENTANILLA:
                //TODO programar funcion eliminar ventanilla
                break;
            case MenuPrinc::AGREGAR_SERVICIO:
                crearServicio();
                break;
            case MenuPrinc::ELIMINAR_SERVICIO:
                eliminarServicio();
                break;
            case MenuPrinc::REORDENAR_SERVICIOS:
                servicios->imprimeServicios();
                cin >> foo;
                administracion(menu->menuAdmin());
                break;
            default:
                errorHandler(userResponse);
                if(userResponse == MenuPrinc::MENU_ANTERIOR){
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
            cin >> opcServ;
            opcServ--;
            Servicio servPtr;
            servPtr = servicios->getServElement(opcServ);
            codigo = servPtr.getTypo();
            cout << "Por favor Digite una descripcion para un nuevo tipo de ventanilla" << endl;
            cin.ignore();
            getline(cin, nombre);
            cout << "Por favor Digite la cantidad de ventanillas para este tipo" << endl;
            cin >> cantVent;
            TipoVentanilla * tipoVent = new TipoVentanilla(nombre, codigo, cantVent);
            //Agrega un nuevo tipo de ventanillas con su descripción, código y cantidad.
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
            cin >> servicioDesc;
            Servicio * nuevoServicio = new Servicio(servicioNombre,servicioTypo,servicioDesc);servicios->agregarServicio(*nuevoServicio);
            servicios->imprimeServicios();
            delete nuevoServicio;
            //TODO Agrega un nuevo tipo de servicio con su descripcion y tipo de ventana asignada
            administracion(menu->menuDefServic());
        }

        void eliminarServicio()
        {
            string servicioNombre;
            cout << "Por favor entrega un nombre de nuevo servicio:" << endl;
            cin >> servicioNombre;
            servicios->borarServicio(servicioNombre);
            cout << "Sucessfully deleted service \"" << servicioNombre << "\"" << endl;
            administracion(menu->menuDefServic());
        }
};

#endif // BANCOCONTROLLER_H
