#ifndef MENUPRINC_H
#define MENUPRINC_H


class MenuPrinc
{
    protected:
    private:
    public:
        MenuPrinc() {}
        virtual ~MenuPrinc() {}

    //plantilla de menu
    void menuPrin()
    {
        //system("pause");
        //system("cls");
        int opc;
        cout << "Bienvenido al Menu Principal del Sistema!!" << endl;
        cout << "Por favor. Digite el número de la opcion que desea: " << endl;
        cout << "   1. Ver el estado de las colas" << endl;
        cout << "   2. Solicitar tiquete" << endl;
        cout << "   3. Atender" << endl;
        cout << "   4. Administración" << endl;
        cout << "   5. Estadísticas del sistema" << endl;
        cout << "   6. Salir del sistema" << endl;
        cin >> opc;
        if (opc > 6 || opc == 0)
        {
            cout << "Por favor digite una opcion valida" << endl;
            menuPrin();
        }
        else
        {
            switch (opc)
            {
                case 1:
                    cout << "Debe mostrar los tipos de ventanillas existentes, la cantidad de 	ventanillas definidas para cada tipo y los códigos de los tiquetes presentes en las diferentes colas." << endl;
                    break;
                case 2:
                    cout << "tiq" << endl;
                    menuSolicTiquet();
                    break;
                case 3:
                    cout << "Proceso de atender personas" << endl;
                    break;
                case 4:
                    menuAdmin();
                    break;
                case 5:
                    menuStats();
                    break;
                case 6:
                    exit(0);
                default:
                    menuPrin();
            }
        }
    }

    void menuSolicTiquet()
    {
        system("cls");
        string opcST;
        cout << "Usted se encuentra en el menu de seleccion de tiquetes." << endl;
        cout << "Por favor. Digite la letra de la opcion que desea: " << endl;
        cout << "   a. Seleccionar Servicio" << endl;
        cout << "   b. Seleccionar Servicio Preferencial" << endl;
        cout << "   c. Volver al Menu Principal" << endl;
        cin >> opcST;
        if (opcST != "a" && opcST != "A" && opcST != "b" && opcST != "B" && opcST != "c" && opcST != "C")
        {
            cout << "Por favor digite una opcion valida" << endl;
            menuSolicTiquet();
        }
        else
        {
            if (opcST == "a" || opcST == "A")
            {
                cout << "Mostrar lista de servicios disponibles" << endl;
            }
            if (opcST == "b" || opcST == "B")
            {
                cout <<"Muestra lo mismo que la opcion anterior solo que para preferenciales" << endl;
            }
            if (opcST == "c" || opcST == "C")
            {
                menuPrin();
            }
        }
    }

    void menuAdmin()
    {
        system("cls");
        string opcAD;
        cout << "Usted se encuentra en el menu de administracion." << endl;
        cout << "Por favor. Digite la letra de la opcion que desea: " << endl;
        cout << "   a. Definir tipos de ventanillas" << endl;
        cout << "   b. Definir servicios disponibles" << endl;
        cin >> opcAD;
        if (opcAD != "a" && opcAD != "A" && opcAD != "b" && opcAD != "B")
        {
            cout << "Por favor digite una opcion valida" << endl;
            menuAdmin();
        }
        else
        {
            if (opcAD == "a" || opcAD == "A")
            {
                menuDefVent();
            }
            else
            {
                if (opcAD == "b" || opcAD == "B")
                {
                    menuDefServic();
                }
            }
        }
    }

    void menuDefVent()
    {
        system("cls");
        string opcDV;
        cout << "Usted se encuentra en el menu para definir tipos de ventanas." << endl;
        cout << "Por favor. Digite la letra de la opcion que desea: " << endl;
        cout << "   a. Agregar un nuevo tipo de ventanilla." << endl;
        cout << "   b. Eliminar un tipo de ventanilla" << endl;
        cin >> opcDV;
        if (opcDV != "a" && opcDV != "A" && opcDV != "b" && opcDV != "B")
        {
            cout << "Por favor digite una opcion valida" << endl;
            menuDefVent();
        }
        else
        {
            if (opcDV == "a" || opcDV == "A")
            {
                cout << "agregar ventanilla" << endl;
                    //Agrega un nuevo tipo de ventanillas con su descripción, código y cantidad.
            }
            if (opcDV == "b" || opcDV == "B")
            {
                cout << "Eliminar ventanilla" << endl;
                // eliminar un tipo de ventanilla
            }
        }
    }

    void menuDefServic()
    {
        system("cls");
        string opcDS;
        cout << "Usted se encuentra en el menu para definir servicios disponibles." << endl;
        cout << "Por favor. Digite la letra de la opcion que desea: " << endl;
        cout << "   a. Agregar un nuevo tipo de servicio." << endl;
        cout << "   b. Eliminar un tipo de servicio." << endl;
        cout << "   c. Reordenar." << endl;
        cin >> opcDS;
        if (opcDS != "a" && opcDS != "A" && opcDS != "b" && opcDS != "B" && opcDS != "c" && opcDS != "C")
        {
            cout << "Por favor digite una opcion valida" << endl;
            menuDefServic();
        }
        else
        {
            if (opcDS == "a" || opcDS == "A")
            {
                cout << "agregar un tipo de servicio" << endl;
                //Agrega un nuevo tipo de servicio con su descripcion y tipo de ventana asignada
            }
            else
            {
                if (opcDS == "b" || opcDS == "B")
                {
                    cout << "Eliminar servicio" << endl;
                    // eliminar un tipo de servicio
                }
                else
                {
                    if (opcDS == "c" || opcDS == "C")
                    {
                        cout << "Reordenar la lista" << endl;
                        // reordenar los elementos en la lista de servicios
                    }
                }
            }
        }
    }

    void menuStats()
    {
        system("cls");
        string opcStats;
        cout << "Usted se encuentra en el menu de administracion." << endl;
        cout << "Por favor. Digite la letra de la opcion que desea: " << endl;
        cout << "   a. Tiempo promedio de espera por tipo de ventanilla" << endl;
        cout << "   b. Total de tiquetes dispensados por tipo de ventanilla" << endl;
        cout << "   c. Total de tiquetes atendidos por ventanilla" << endl;
        cout << "   d. Total de tiquetes dispensados por tipo de transacción" << endl;
        cout << "   e. Total de tiquetes preferenciales dispensados en todo el sistema" << endl;
        cin >> opcStats;
        if (opcStats != "a" && opcStats != "A" && opcStats != "b" && opcStats != "B" && opcStats != "c" && opcStats != "C"
            && opcStats != "d" && opcStats != "D" && opcStats != "e" && opcStats != "E")
        {
            cout << "Por favor digite una opcion valida" << endl;
            menuStats();
        }
        else
        {
            if (opcStats == "a" || opcStats == "A")
            {
                cout << "Tiempo promedio de espera por tipo de ventanilla" << endl;
            }
            else
            {
                if (opcStats == "b" || opcStats == "B")
                {
                    cout << "Total de tiquetes dispensados por tipo de ventanilla" << endl;
                }
                else
                {
                    if (opcStats == "c" || opcStats == "C")
                    {
                        cout << "Total de tiquetes atendidos por ventanilla" << endl;
                    }
                    else
                    {
                        if (opcStats == "d" || opcStats == "D")
                        {
                            cout << "Total de tiquetes dispensados por tipo de transacción" << endl;
                        }
                        else
                        {
                            if (opcStats == "e" || opcStats == "E")
                            {
                                cout << "Total de tiquetes preferenciales dispensados en todo el sistema" << endl;
                            }
                        }
                    }
                }
            }
        }
    }
};

#endif // MENUPRINC_H
