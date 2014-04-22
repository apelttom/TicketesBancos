#ifndef USUARIO_H
#define USUARIO_H


class Usuario
{
    protected:
    private:
        string numero;
        string servicio;
        string ventanilla;
    public:
        Usuario(string pNumero, string pServicio, string pVentanilla)
        {
            numero = pNumero;
            servicio = pServicio;
            ventanilla = pVentanilla;
        }
        virtual ~Usuario();

};

#endif // USUARIO_H
