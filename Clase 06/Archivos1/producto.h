#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

struct Producto{
    int id;
    char nombre[50];
    float precio;
    int stock;
    int stock_min;
    bool estado;
};

const char *PATH_PRODUCTO = "datos/productos.dat";

/* Prototipos/Declaraciones */
void listar_producto_x_id();

void editar_producto();

void listar_producto(Producto);

bool cargar_producto(Producto *);

bool guardar_producto(Producto);

bool sobrescribir_producto(Producto, int);

void nuevo_producto();

void listar_productos();

int buscar_producto(int);

int cantidad_productos();

Producto leer_producto(int);

/* Definiciones */

void editar_producto(){
    int id_buscado, pos;

    cout << "ID a editar: ";
    cin >> id_buscado;
    pos = buscar_producto(id_buscado);
    if (pos >= 0){
        Producto reg = leer_producto(pos);
        cout << endl;
        listar_producto(reg);
        cout << endl << "Nuevo precio: ";
        cin >> reg.precio;
        if (sobrescribir_producto(reg, pos)){
            cout << "Producto modificado.";
        }
        else{
            cout << "No se modificó el producto.";
        }
    }
    else{
        cout << "No existe el producto.";
    }
}

Producto leer_producto(int pos){
    Producto reg;
    FILE *p;
    p = fopen(PATH_PRODUCTO, "rb");
    if (p == NULL){
        reg.id = -1;
        return reg;
    }
    fseek(p, pos * sizeof(Producto),SEEK_SET);
    fread(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return reg;
}

int cantidad_productos(){
    int bytes, cr;
    FILE *p;
    p = fopen(PATH_PRODUCTO, "rb");
    if (p == NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Producto);
    fclose(p);
    return cr;
}

int buscar_producto(int id_buscado){
    Producto reg;
    int i=0;
    FILE *p;
    p = fopen(PATH_PRODUCTO, "rb");
    if (p == NULL){
        return -2;
    }
    while (fread(&reg, sizeof(Producto), 1, p)){
        if (reg.id == id_buscado){
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

void listar_productos(){
    cls();
    Producto reg;
    int cant = cantidad_productos(), i;
    for(i=0; i<cant; i++){
        cout << "#" << i+1 << endl;
        reg = leer_producto(i);
        listar_producto(reg);
        cout << endl;
    }

}

void listar_producto_x_id(){
    cls();
    int id_buscado, pos;
    cout << "ID a buscar: ";
    cin >> id_buscado;
    pos = buscar_producto(id_buscado);
    if (pos >= 0){
        Producto reg = leer_producto(pos);
        listar_producto(reg);
    }
    else{
        cout << "No existe el id buscado.";
    }
}

void nuevo_producto(){
    cls();
    Producto reg;
    if (cargar_producto(&reg)){
        if (guardar_producto(reg)){
            cout << "Producto cargado correctamente.";
        }
        else{
            cout << "No se pudo guardar el producto en el archivo.";
        }
    }
    else{
        cout << "No se pudo cargar el producto.";
    }
}

void listar_producto(Producto reg){
    cout << "ID      :   " << reg.id << endl;
    cout << "NOMBRE  :   " << reg.nombre << endl;
    cout << "PRECIO  : $ " << reg.precio << endl;
    cout << "STOCK   :   " << reg.stock << endl;
    cout << "STOCK M :   " << reg.stock_min << endl;
}

bool cargar_producto(Producto *p){
    int i;
    cout << "ID: ";
    cin >> p->id;
    i = buscar_producto(p->id);
    if (i >= 0){
        return false;
    }

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

    p->estado = true;

    return true;
}

bool guardar_producto(Producto reg){
    bool escribio;
    FILE *p;
    p = fopen(PATH_PRODUCTO, "ab");
    if (p == NULL){
        return false;
    }
    escribio = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return escribio;
}

bool sobrescribir_producto(Producto reg, int pos){
    bool escribio;
    FILE *p;
    p = fopen(PATH_PRODUCTO, "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, pos * sizeof(Producto), SEEK_SET);
    escribio = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return escribio;
}










#endif // PRODUCTO_H_INCLUDED
