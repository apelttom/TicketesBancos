#ifndef SERVICIO_H
#define SERVICIO_H

class Servicio{

    private:
        string nombre;
        string typo;
        string descripcion;

    public:
        Servicio(string pNombre, string pTypo, string pDescripcion){
            nombre = pNombre;
            typo = pTypo;
            descripcion = pDescripcion;
        }

        ~Servicio(){
        }

        string getNombre() const{
            return nombre;
        }

        string getTypo() const{
            return typo;
        }

        string getDescripcion() const{
            return descripcion;
        }
};

/*
 * TODO make the class working with cout
 */
std::ostream& operator<<(std::ostream &strm, const Servicio &servicio) {
  return strm << "Servicio(" << "Nombre = " << servicio.getNombre() << ", " << "Typo = " << servicio.getTypo() << ", " << "Descripcion = " << servicio.getDescripcion() << ")";
}

#endif // SERVICIO_H