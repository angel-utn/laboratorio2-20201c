//#ifndef EXAMEN_H_INCLUDED
//#define EXAMEN_H_INCLUDED
#pragma once
#include "fecha.h"
class Examen{
    private:
    float nota;
    Fecha f;
    public:
        void cargar();
        void mostrar();
        float getNota();
        Fecha getFecha();
};


//#endif // EXAMEN_H_INCLUDED
