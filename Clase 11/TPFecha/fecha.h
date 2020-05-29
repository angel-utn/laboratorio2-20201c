#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha();
        Fecha(int, int, int);
        void cargar();
        void mostrar();
        int getDia();
};


#endif // FECHA_H_INCLUDED
