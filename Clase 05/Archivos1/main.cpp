#include <iostream>
using namespace std;
#include <cstdio>
struct Producto{
    int id;
    char nombre[50];
    float precio;
    int stock;
    int stock_min;
};

void listar_producto(Producto reg){
    cout << "ID      :   " << reg.id << endl;
    cout << "NOMBRE  :   " << reg.nombre << endl;
    cout << "PRECIO  : $ " << reg.precio << endl;
    cout << "STOCK   :   " << reg.stock << endl;
    cout << "STOCK M :   " << reg.stock_min << endl;
}

bool cargar_producto(Producto *p){
    cout << "ID: ";
    cin >> p->id;

    cout << "NOMBRE  : " ;
    cin.ignore();
    cin.getline(p->nombre, 30);

    cout << "PRECIO  : $";
    cin >> p->precio;

    if (p->precio < 0){
        return false;
    }
    cout << "STOCK   : " ;
    cin >> p->stock;

    if(p->stock < 0){
        return false;
    }
    cout << "STOCK M : " ;
    cin >> p->stock_min;

    if(p->stock_min < 0){
        return false;
    }

    return true;
}

int main()
{
    Producto reg;
    int x;
    /*if (cargar_producto(&reg) == true){
        FILE *p;
        p = fopen("productos.dat", "ab");
        if (p == NULL){
            cout << "No se pudo abrir el archivo.";
            return 1;
        }
        fwrite(&reg, sizeof(Producto), 1, p);
        fclose(p);
    }*/

    FILE *p;
    p = fopen("productos.dat", "rb");
    if (p == NULL){
        cout << "No se pudo abrir el archivo.";
        return 1;
    }
    x = fread(&reg, sizeof(Producto), 1, p);
    listar_producto(reg);
    fclose(p);



    return 0;
}
