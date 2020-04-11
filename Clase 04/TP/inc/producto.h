#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

struct Producto{
  int id;
  char descripcion[30];
  float precio;
  int stock;
  int stock_min;
};

const int TAM = 10;

bool cargar_producto(Producto *p){
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
  cin >> i;
  resetColor();
  setColor(TEXT_COLOR);
  //return false;
}

#endif // PRODUCTO_H_INCLUDED
