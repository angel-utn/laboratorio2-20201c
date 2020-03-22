/**
2) Un empresa dispone de 15 productos que se comercializan en 10 sucursales.
Hacer un programa que permita cargar las ventas realizadas el día de ayer.
 Por cada venta se registra:
 - Día de la venta,
 - Código de producto (1 a 15),
 - Código de sucursal (1 a 10)
 - Importe de la venta.

El fin de la carga de datos se indica con un día de la venta igual a cero.
Calcular e informar:
- Por cada producto y sucursal, el total facturado.
- Las sucursales sin ventas el día de ayer.
- El producto que haya registrado la mayor cantidad de ventas.
*/
#include <iostream>
using namespace std;
#include "funciones.h"

int main(){
  float mv[15][10]={0};
  cargar_ventas(mv);
  puntoA(mv);
  /*puntoB();
  puntoC();*/

  return 0;
}
