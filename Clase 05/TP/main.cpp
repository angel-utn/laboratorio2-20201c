#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "inc/rlutil.h"
using namespace rlutil;
#include "inc/funciones.h"
#include "inc/producto.h"

int main(){
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
        nuevo_producto();
      break;
      case 2:
        editar_producto();
      break;
      case 3:
        listar_producto_x_id();
      break;
      case 4:
        listar_productos();
      break;
      case 0:
        return 0;
      break;
    }
  }

  gotoxy(1,25);
  return 0;
}
