#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

struct Producto{
  int id;
  char nombre[30];
  float precio;
  int stock;
  int stockmin;
};
const int CANT_P=10;

void menuProducto(){
  int opc;
  int c=0; ///Contador de productos cargados
  Producto v[CANT_P];
  do{
    cls();
    cout << "MENÚ PRODUCTOS" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1 - Cargar producto" << endl;
    cout << "2 - Editar producto x ID" << endl;
    cout << "3 - Listar producto x ID" << endl;
    cout << "4 - Listar productos (ordenados por precio)" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "0 - Salir" << endl;

    cout << endl << "OPCIÓN: ";
    cin >> opc;
    switch(opc){
      case 1:
        /// Cargar productos
      break;
      case 2:
      break;
      case 3:
      break;
      case 4:
        /// Listar productos
      break;
      case 0:
        return;
      break;

    }
    cin.ignore();
    anykey();
  }while(opc != 0);
}

#endif // PRODUCTO_H_INCLUDED
