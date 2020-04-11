#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

struct Producto
{
    int id;
    char nombre[30];
    float precio;
    int stock;
    int stock_min;
};

const int PRODUCTOS=10;

///Declaración de funciones
int buscar_producto(Producto *, int, int);

/// Definición de funciones

int datos_manuales(Producto *v)
{
    int c=0;
    v[c].id = 10;
    strcpy(v[c].nombre, "Naranja");
    v[c].precio = 50;
    v[c].stock = 80;
    v[c].stock_min = 50;
    c++;
    v[c].id = 20;
    strcpy(v[c].nombre, "Manzana roja");
    v[c].precio = 80;
    v[c].stock = 30;
    v[c].stock_min = 20;
    c++;
    v[c].id = 30;
    strcpy(v[c].nombre, "Kiwi");
    v[c].precio = 250;
    v[c].stock = 8;
    v[c].stock_min = 3;
    c++;
    v[c].id = 40;
    strcpy(v[c].nombre, "Manzana verde");
    v[c].precio = 50;
    v[c].stock = 80;
    v[c].stock_min = 50;
    c++;
    v[c].id = 50;
    strcpy(v[c].nombre, "Mandarina");
    v[c].precio = 30;
    v[c].stock = 100;
    v[c].stock_min = 50;
    c++;
    v[c].id = 60;
    strcpy(v[c].nombre, "Tomate");
    v[c].precio = 70;
    v[c].stock = 30;
    v[c].stock_min = 50;
    c++;
    return c;
}
void listar_producto(Producto reg){
    cout << "ID      :  " << reg.id << endl;
    cout << "NOMBRE  :  " << reg.nombre << endl;
    cout << "PRECIO  : $" << reg.precio << endl;
    cout << "STOCK   :  " << reg.stock << endl;
    cout << "STOCK M :  " << reg.stock_min << endl;
}

bool cargar_producto(Producto *p, int c){
    int id, pos;
    cout << "ID      : " ;
    cin >> id;

    ///validación para no repetir ID
    pos = buscar_producto(p, c, id);
    if (pos >= 0){
        cout << "El producto ya existe." << endl << endl;
        return false;
    }

    p[c].id = id;

    cout << "NOMBRE  : " ;
    cin.ignore();
    cin.getline(p[c].nombre, 30);
    cout << "PRECIO  : $";
    cin >> p[c].precio;

    if (p[c].precio < 0){
        return false;
    }
    cout << "STOCK   : " ;
    cin >> p[c].stock;

    if(p[c].stock < 0){
        return false;
    }
    cout << "STOCK M : " ;
    cin >> p[c].stock_min;

    if(p[c].stock_min < 0){
        return false;
    }

    return true;
}

void ordenar_productos(Producto *v, int tam){
    int i, j, pos;
    Producto aux;
    for(i=0; i<tam-1; i++){
        pos = i;
        for(j=i+1; j<tam; j++){
            //if(v[j].precio < v[pos].precio){
            if(strcasecmp(v[j].nombre, v[pos].nombre) > 0){
                pos = j;
            }
        }
        aux = v[i];
        v[i] = v[pos];
        v[pos] = aux;
    }
}

void listar_productos(Producto *v, int tam){
    int i;
    gotoxy(1, 1);
    cout << "ID";
    gotoxy(5, 1);
    cout << "NOMBRE";
    gotoxy(30, 1);
    cout << "PRECIO";
    gotoxy(1,2);
    cout << "---------------------------------------";

    ordenar_productos(v, tam);

    for(i=0; i<tam; i++){
        gotoxy(1, 3+i);
        cout << v[i].id;
        gotoxy(5, 3+i);
        cout << v[i].nombre;
        gotoxy(30, 3+i);
        cout << v[i].precio;
    }
}

int buscar_producto(Producto *v, int tam, int valorBuscado){
    int i;
    for(i=0; i<tam; i++){
        if (v[i].id == valorBuscado){
            return i;
        }
    }
    return -1;
}

void listar_productoxID(Producto *v, int tam){
    int id, pos;
    cout << "Ingresar ID Producto: ";
    cin >> id;
    cout << endl;
    pos=buscar_producto(v, tam, id);
    if (pos >= 0){
        listar_producto(v[pos]);
    }
    else{
        cout << "No existe el producto.";
    }
}
void editar_producto(Producto *v, int tam){
    int id, pos;
    cout << "Ingresar ID Producto: ";
    cin >> id;
    cout << endl;
    pos=buscar_producto(v, tam, id);
    if (pos >= 0){
        listar_producto(v[pos]);
        cout << "Ingresar el nuevo nombre: ";
        cin.ignore();
        cin.getline(v[pos].nombre, 30);
        cout << endl << "Producto modificado";
    }
    else{
        cout << "No existe el producto.";
    }
}















#endif // PRODUCTO_H_INCLUDED
