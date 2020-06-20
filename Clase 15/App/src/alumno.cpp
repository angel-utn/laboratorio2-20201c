#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace rlutil;
#include "alumno.h"
#include "funciones.h"

const char *FILE_ALUMNO = "../datos/alumnos.dat";

bool Alumno::cargar(){
    cls();
    cout << "Legajo: ";
    cin >> legajo;
    ///TODO: Validar legajo
    cout << "Apellidos: ";
    cin.ignore();
    cin.getline(apellidos, 50);
    cout << "Nombres: ";
    cin.getline(nombres, 50);
    cout << "ID Carrera: ";
    cin >> idcarrera;
    if (idcarrera <= 0){
        return false;
    }
    return true;
}
void Alumno::mostrar(){
    cout << "Legajo     : " << legajo << endl;
    cout << "Apellidos  : " << apellidos << endl;
    cout << "Nombres    : " << nombres << endl;
    cout << "ID Carrera : " << idcarrera << endl;
}
bool Alumno::guardar(){
    bool resultado;
    FILE *p;
    p = fopen(FILE_ALUMNO, "ab");
    if (p == NULL){
        return false;
    }
    resultado = fwrite(this, sizeof(Alumno), 1, p);
    fclose(p);
    return resultado;
}
bool Alumno::guardar(int pos){
    bool resultado = false;
    FILE *p;
    p = fopen(FILE_ALUMNO, "rb+");
    if (p == NULL){
        return false;
    }
    if (pos >= 0){
        fseek(p, pos * sizeof(Alumno), SEEK_SET);
        resultado = fwrite(this, sizeof(Alumno), 1, p);
    }
    fclose(p);
    return resultado;
}
bool Alumno::leer(int pos){
    bool resultado = false;
    FILE *p;
    p = fopen(FILE_ALUMNO, "rb");
    if (p == NULL){
        return false;
    }
    if (pos >= 0){
        fseek(p, pos * sizeof(Alumno), SEEK_SET);
        resultado = fread(this, sizeof(Alumno), 1, p);
    }
    fclose(p);
    return resultado;
}

int Alumno::getLegajo(){
    return legajo;
}
char* Alumno::getApellidos(){
    return apellidos;
}
char* Alumno::getNombres(){
    return nombres;
}
int Alumno::getIDCarrera(){
    return idcarrera;
}
void Alumno::setLegajo(int _legajo){
    legajo = _legajo;
}
void Alumno::setApellidos(char *_apellidos){
    strcpy(apellidos, _apellidos);
}
void Alumno::setNombres(char *_nombres){
    strcpy(nombres, _nombres);
}
void Alumno::setIDCarrera(int _idcarrera){
    idcarrera = _idcarrera;
}
int buscar_alumno(int legajo){
    Alumno reg;
    int i = 0;
    while(reg.leer(i)){
        if (reg.getLegajo() == legajo){
            return i;
        }
        i++;
    }
    return -1;
}
bool nuevo_alumno(){
    Alumno reg;
    if (reg.cargar()){
        if (reg.guardar()){
            return true;
        }
    }
    return false;
}
bool modificar_alumno(){
    cls();
    int legajo, idcarrera;
    int pos;
    cout << "Legajo de alumno: ";
    cin >> legajo;
    pos = buscar_alumno(legajo);
    if (pos >= 0){
        cls();
        Alumno reg;
        reg.leer(pos);
        reg.mostrar();

        cout << endl;
        cout << "Nueva carrera: ";
        cin >> idcarrera;
        if (idcarrera >= 0){
            reg.setIDCarrera(idcarrera);
            if (reg.guardar(pos)){
                ok_msj("Alumno modificado correctamente");
            }
            else{
                error_msj("No se pudo modificar el alumno");
            }
        }
    }
    else{
        error_msj("No existe el alumno");
    }

    return false;
}
void listar_alumno(){
    cls();
    int legajo;
    int pos;
    cout << "Legajo de alumno: ";
    cin >> legajo;
    pos = buscar_alumno(legajo);
    if (pos >= 0){
        cls();
        Alumno reg;
        reg.leer(pos);
        reg.mostrar();
    }
    else{
        error_msj("No existe el alumno");
    }
    //anykey();
}
void listar_alumnos(){
    Alumno reg;
    int i = 0;
    cls();
    cout << "Listado de alumnos" << endl;
    cout << "------------------------" << endl;

    cout << "Legajo\tCarrera\t\tApellidos\tNombres" << endl;

    while(reg.leer(i++)){
        //TODO: Listarlo con setw
        cout << reg.getLegajo() << "\t" << reg.getIDCarrera() << "\t\t" << reg.getApellidos() << "\t\t" << reg.getNombres();
        cout << endl;
    }
    cin.ignore();
    anykey();
}



















