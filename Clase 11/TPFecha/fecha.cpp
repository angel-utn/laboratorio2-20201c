#include <iostream>
using namespace std;
#include <ctime>
#include "fecha.h"

void Fecha::cargar(){
    cout << "Día: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Anio: ";
    cin >> anio;
}
void Fecha::mostrar(){
    cout << dia << "/" << mes << "/" << anio << endl;
}

int Fecha::getDia(){
    return dia;
}
Fecha::Fecha(){
    time_t timestamp; //Googleen
    timestamp = time(NULL);
    tm *f;
    f = localtime(&timestamp);
    dia = f->tm_mday;
    mes = f->tm_mon + 1;
    anio = f->tm_year + 1900;
}
Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}
