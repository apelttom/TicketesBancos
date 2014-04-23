#ifndef TIQUETES_H
#define TIQUETES_H


class Tiquetes
{
    protected:
    private:
        string numero;
        string servicio;
        string ventanilla;
    public:
        Tiquetes(string pNumero, string pServicio, string pVentanilla)
        {
            numero = pNumero;
            servicio = pServicio;
            ventanilla = pVentanilla;
        }
        virtual ~Tiquetes();

};

#endif // TIQUETES_H
