#ifndef BANCOCONTROLLER_H
#define BANCOCONTROLLER_H

/**
 *  This class is a Singleton pattern. We cannot instance it,
 *  we can only obtain one instance by calling getInstance method
 */
class BancoController{

    private:
        MenuPrinc *menu;
        Servicios *servicios;

        // Private constructor
        BancoController(){
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

        void startApplication(){
            menu->menuPrin()
        }

};

#endif // BANCOCONTROLLER_H
