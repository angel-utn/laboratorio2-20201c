#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

class Alumno{
    public:
        bool cargar();
        void mostrar();
        bool guardar();
        bool guardar(int);
        bool leer(int);

        ///Gets
        int getLegajo();
        char* getApellidos();
        char* getNombres();
        int getIDCarrera();
        ///Sets
        void setLegajo(int);
        void setApellidos(char *);
        void setNombres(char *);
        void setIDCarrera(int);

    private:
        int legajo;
        char apellidos[50];
        char nombres[50];
        int idcarrera;
};
/* Funciones globales de alumno */
bool nuevo_alumno();
void listar_alumnos();
void listar_alumno();
bool modificar_alumno();
int buscar_alumno(int);

#endif // ALUMNO_H_INCLUDED
