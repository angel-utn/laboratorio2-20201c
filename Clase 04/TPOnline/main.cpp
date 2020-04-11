#include <iostream>
using namespace std;
#include <cstring>
#include "inc/rlutil.h"
using namespace rlutil;
#include "inc/producto.h"

int main(){
    int opc, c=0;
    Producto v[PRODUCTOS];
    setColor(WHITE);

    while(true){
        cls();
        cout << "Menú principal" << endl;
        cout << "-----------------------" << endl;
        cout << "1 - Cargar producto" << endl;
        cout << "2 - Editar producto" << endl;
        cout << "3 - Listar producto x ID" << endl;
        cout << "4 - Listar productos" << endl;
        cout << "-----------------------" << endl;
        cout << "0 - Salir" << endl;
        cout << endl << "Opción: ";
        cin >> opc;

        switch(opc){
            case 1:
                cls();
                if (c < PRODUCTOS){
                    if (cargar_producto(v, c) == true){
                        c++;
                        cout << "Producto cargado correctamente.";
                    }
                    else{
                        cout << "No se pudo cargar el producto.";
                    }
                }
                else{
                    cout << "No se pueden cargar más productos.";
                }

            break;
            case 2:
                cls();
                if (c > 0){
                    editar_producto(v, c);
                }
                else{
                    cout << "No hay productos cargados.";
                }
            break;
            case 3:
                cls();
                if (c > 0){
                    listar_productoxID(v, c);
                }
                else{
                    cout << "No hay productos cargados.";
                }
            break;
            case 4:
                cls();
                if (c > 0){
                    listar_productos(v, c);
                }
                else{
                    cout << "No hay productos cargados.";
                }
            break;
            case 5:
                c = datos_manuales(v);
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
