#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "menu.h"
#include "funciones.h"
#include "alumno.h"

void MenuPrincipal(){
    int opc;
    setColor(WHITE);
    while(true){
        cls();
        cout << "Menú principal" << endl;
        cout << "-------------------------" << endl;
        cout << "1) Alumnos" << endl;
        cout << "2) Exámenes" << endl;
        cout << "-------------------------" << endl;
        cout << "0) Salir del programa" << endl;
        cout << endl << "Opción: ";
        cin >> opc;


        switch(opc){
            case 1:
                MenuAlumno();
            break;
            case 2:
                MenuExamen();
            break;
            case 0:
                return;
            break;
            default:
                error_msj("Opción incorrecta");
            break;
        }
        cin.ignore();
        anykey();
    }
}

void MenuAlumno(){
int opc;
    setColor(WHITE);
    while(true){
        cls();
        cout << "Menú Alumno" << endl;
        cout << "-------------------------" << endl;
        cout << "1) Nuevo alumno" << endl;
        cout << "2) Modificar alumno" << endl;
        cout << "3) Listar alumno" << endl;
        cout << "4) Listar todos los alumnos" << endl;
        cout << "5) Eliminar alumno" << endl;
        cout << "-------------------------" << endl;
        cout << "0) Salir del programa" << endl;
        cout << endl << "Opción: ";
        cin >> opc;


        switch(opc){
            case 1:
                if (nuevo_alumno()){
                    ok_msj("Alumno guardado correctamente");
                }
                else{
                    error_msj("No se pudo guardar el alumno");
                }
            break;
            case 2:
                modificar_alumno();
            break;
            case 3:
                listar_alumno();
            break;
            case 4:
                listar_alumnos();
            break;
            case 0:
                return;
            break;
            default:
                error_msj("Opción incorrecta");
            break;
        }
        cin.ignore();
        anykey();
    }
}
void MenuExamen(){
int opc;
    setColor(WHITE);
    while(true){
        cls();
        cout << "Menú Examen" << endl;
        cout << "-------------------------" << endl;
        cout << "1) Nuevo examen" << endl;
        cout << "2) Modificar examen" << endl;
        cout << "3) Listar examen" << endl;
        cout << "4) Listar todos los exámenes" << endl;
        cout << "5) Eliminar examen" << endl;
        cout << "-------------------------" << endl;
        cout << "0) Salir del programa" << endl;
        cout << endl << "Opción: ";
        cin >> opc;


        switch(opc){
            case 1:

            break;
            case 2:

            break;
            case 0:
                return;
            break;
            default:
                error_msj("Opción incorrecta");
            break;
        }
        cin.ignore();
        anykey();
    }
}
