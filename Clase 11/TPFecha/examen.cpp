#include <iostream>
using namespace std;
#include "examen.h"

void Examen::cargar(){
    cout << "Fecha: ";
    f.cargar();
    cout << "Nota: ";
    cin >> nota;
}

void Examen::mostrar(){
    cout << "Fecha: ";
    f.mostrar();
    cout << "Nota: " << nota << endl;
}
float Examen::getNota(){
    return nota;
}
Fecha Examen::getFecha(){
    return f;
}
