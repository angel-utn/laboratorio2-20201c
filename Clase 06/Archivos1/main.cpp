#include <iostream>
using namespace std;
#include <cstdio>
#include "rlutil.h"
using namespace rlutil;
#include "producto.h"

int main()
{
    int opc;
    setColor(WHITE);
    while(true){
        cls();
        cout << "Menú productos" << endl << "---------------" << endl;
        cout << "1 - Cargar producto" << endl;
        cout << "2 - Listar productos" << endl;
        cout << "3 - Editar producto" << endl;
        cout << "4 - Listar producto x ID" << endl;
        cout << "5 - Eliminar producto" << endl;
        cout << "------------------------" << endl;
        cout << "0 - Salir" << endl;
        cout << "Opción: ";
        cin >> opc;

        switch(opc){
            case 1:
                nuevo_producto();
            break;
            case 2:
                listar_productos();
            break;
            case 3:
                editar_producto();

            break;
            case 4:
                listar_producto_x_id();
            break;

            case 0:
                return 0;
            break;
        }
        cin.ignore();
        anykey();
    }
    return 0;
}
