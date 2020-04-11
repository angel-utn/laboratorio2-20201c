#include <iostream>
using namespace std;
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "inc/rlutil.h"
using namespace rlutil;
#include "inc/funciones.h"
#include "inc/producto.h"

int main(){
  Producto lista[TAM];
  unsigned short c = 0;
  fputs( "\x1b[8;25;80t", stdout );
  ui::draw_lines();
  ui::draw_brand();
  while(true)
  {
    unsigned short opt = -1;
    ui::clear_panel(LEFT_PANEL);
    opt = ui::draw_menu(opt);
    switch(opt){
      case 1:
        if (c < TAM){
          if (cargar_producto(&lista[c]) == true){
            c++;
          }
          else{
            ui::show_error("El producto no pudo ser cargado.");
          }
        }
      break;
      case 2:
      break;
      case 3:
      break;
      case 4:
      break;
      case 0:
        return 0;
      break;
    }
  }

  gotoxy(1,25);
  return 0;
}
