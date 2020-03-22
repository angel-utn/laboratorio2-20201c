#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargar_ventas(float m[15][10]){
  int dia;
  int prod;
  int suc;
  float importe;

  cout << "Día: ";
  cin >> dia;
  while (dia != 0){
    cout << "Producto: ";
    cin >> prod;
    cout << "Sucursal: ";
    cin >> suc;
    cout << "Importe: $";
    cin >> importe;
    m[prod-1][suc-1]+=importe;
    cout << endl;
    cout << "Día: ";
    cin >> dia;
  }

}
void puntoA(float m[15][10]){
  int i, j;
  for(i=0; i<15; i++){
    cout << "Producto " << i + 1 << endl;
    for(j=0; j<10; j ++){
      if (m[i][j] > 0){
        cout << "\tSucursal " << j + 1 << " : "; /// \t hace una tabulación
        cout << m[i][j] << endl;
      }
    }
    cout << endl;
  }
}
#endif // FUNCIONES_H_INCLUDED
