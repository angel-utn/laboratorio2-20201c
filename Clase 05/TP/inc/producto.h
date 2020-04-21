#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

struct Producto{
  int id;
  char nombre[30];
  float precio;
  int stock;
  int stock_min;
};

const char *PATH_PRODUCTOS = "datos/productos.dat";

/// Declaraciones
bool cargar_producto(Producto *, int);
bool guardar_producto(Producto, int);
Producto leer_producto(int);
void listar_producto(Producto);
int contar_productos();
int buscar_producto(int);

/// Funciones de archivo
Producto leer_producto(int pos){
    Producto reg;
    FILE *p;
    p = fopen(PATH_PRODUCTOS, "rb");
    fseek(p, pos * sizeof(Producto), SEEK_SET);
    fread(&reg, sizeof(Producto), 1, p);
    return reg;
}

int contar_productos(){
    int bytes;
    FILE *p;
    p = fopen(PATH_PRODUCTOS, "rb");
    if (p == NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Producto);
}

int buscar_producto(int codigoBuscado){
    Producto reg;
    int pos = 0;
    FILE *p;
    p = fopen(PATH_PRODUCTOS, "rb");
    if (p == NULL){
        return -2;
    }
    while(fread(&reg, sizeof(Producto), 1, p) == 1){
        if (reg.id == codigoBuscado){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool guardar_producto(Producto reg, int pos){
    bool estado;
    FILE *p;
    if (pos >= 0){
        p = fopen(PATH_PRODUCTOS, "rb+");
        if (p == NULL){
            return false;
        }
        fseek(p, pos * sizeof(Producto), SEEK_SET);
    }
    else{
        p = fopen(PATH_PRODUCTOS, "ab");
        if (p == NULL){
            return false;
        }
    }
    estado = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return estado;
}

/// Funciones de interfaz

bool cargar_producto(Producto *p, int codigo = 0){
  int i;
  setColor(TEXT_COLOR);
  gotoxy(40, 10);
  cout << "ID";
  ui::textbox(55, 10, 2);

  gotoxy(40, 12);
  cout << "NOMBRE";
  ui::textbox(55, 12, 20);

  gotoxy(40, 14);
  cout << "PRECIO";
  ui::textbox(55, 14, 4);

  gotoxy(40, 16);
  cout << "STOCK";
  ui::textbox(55, 16, 4);

  gotoxy(40, 18);
  cout << "STOCK MÍNIMO";
  ui::textbox(55, 18, 4);

  setBackgroundColor(BLUE);
  gotoxy(55, 10);
  if (codigo != 0){
    cout << codigo;
  }
  else{
    cin >> p->id;
    if (buscar_producto(p->id) >= 0){
        ui::show_msg("Código de producto repetido", ERROR_COLOR);
        return false;
    }
    cin.ignore();
  }

  gotoxy(55, 12);
  cin.getline(p->nombre, 30);

  gotoxy(55, 14);
  cin >> p->precio;
  if (p->precio < 0){
    return false;
  }

  gotoxy(55, 16);
  cin >> p->stock;
  if (p->stock < 0){
    return false;
  }

  gotoxy(55, 18);
  cin >> p->stock_min;
  if (p->stock_min < 0){
    return false;
  }

  resetColor();
  setColor(TEXT_COLOR);
  return true;
}

void listar_producto(Producto reg){
    int i;
    ui::reset_color();
    gotoxy(40, 10);
    cout << "ID";
    ui::textbox(55, 10, 2);

    gotoxy(40, 12);
    cout << "NOMBRE";
    ui::textbox(55, 12, 20);

    gotoxy(40, 14);
    cout << "PRECIO";
    ui::textbox(55, 14, 4);

    gotoxy(40, 16);
    cout << "STOCK";
    ui::textbox(55, 16, 4);

    gotoxy(40, 18);
    cout << "STOCK MÍNIMO";
    ui::textbox(55, 18, 4);

    setBackgroundColor(BLUE);
    gotoxy(55, 10);
    cout << reg.id;

    gotoxy(55, 12);
    cout << reg.nombre;

    gotoxy(55, 14);
    cout << reg.precio;

    gotoxy(55, 16);
    cout << reg.stock;

    gotoxy(55, 18);
    cout << reg.stock_min;
}

void listar_productos(){
    Producto reg;
    int i=0, cant;
    cant = contar_productos();
    ui::show_msg("Presiona una tecla para avanzar de registro.", DEFAULT_BACKCOLOR);
    for(i=0; i<cant; i++){
        reg = leer_producto(i);
        listar_producto(reg);
        anykey();
    }
    ui::reset_color();
    ui::clear_panel(MAIN_PANEL);
}

void editar_producto(){
    int codigoBuscado, pos;
    Producto reg;

    ui::reset_color();
    gotoxy(40, 10);
    cout << "ID";
    ui::textbox(55, 10, 2);

    setBackgroundColor(BLUE);
    gotoxy(55, 10);
    cin >> codigoBuscado;

    pos = buscar_producto(codigoBuscado);
    if (pos >= 0){
        reg = leer_producto(pos);
        listar_producto(reg);
        ui::show_msg("Presione una tecla para editar el producto", DEFAULT_BACKCOLOR);
        if (cargar_producto(&reg, codigoBuscado) == true){
            if (guardar_producto(reg, pos) == true){
                ui::show_msg("Producto editado correctamente", SUCCESS_COLOR);
            }
            else{
                ui::show_msg("No se pudo editar el producto correctamente", ERROR_COLOR);
            }
        }
        else{
            ui::show_msg("Hubo un error al cargar el producto.", ERROR_COLOR);
        }
        cin.ignore();
        anykey();
    }
    else{
        ui::show_msg("El producto buscado no existe.", ERROR_COLOR);
    }
    ui::reset_color();
    ui::clear_panel(MAIN_PANEL);
}

void listar_producto_x_id(){
    int codigoBuscado, pos;
    Producto reg;

    ui::reset_color();
    gotoxy(40, 10);
    cout << "ID";
    ui::textbox(55, 10, 2);

    setBackgroundColor(BLUE);
    gotoxy(55, 10);
    cin >> codigoBuscado;

    pos = buscar_producto(codigoBuscado);
    if (pos >= 0){
        reg = leer_producto(pos);
        listar_producto(reg);
        cin.ignore();
        anykey();
    }
    else{
        ui::show_msg("El producto buscado no existe.", ERROR_COLOR);
    }
    ui::reset_color();
    ui::clear_panel(MAIN_PANEL);
}

void nuevo_producto(){
    Producto reg;
    if (cargar_producto(&reg) == true){
        if (guardar_producto(reg, -1) == true){
            ui::show_msg("El producto se guardó correctamente.", SUCCESS_COLOR);
        }
        else{
            ui::show_msg("El producto no se pudo guardar correctamente", ERROR_COLOR);
        }
    }
    else{
        ui::show_msg("El producto no pudo ser cargado.", ERROR_COLOR);
    }
    ui::clear_panel(MAIN_PANEL);
}

#endif // PRODUCTO_H_INCLUDED
