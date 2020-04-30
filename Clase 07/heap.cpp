#include <iostream>
using namespace std;

int main(){
  int n, *p, i;

  cout << "Ingresar la cantidad de elementos del vector (pueden ser millones de elementos): " << endl;
  cin >> n;

  /**
      void * malloc (long int);

      malloc devuelve un puntero a void distinto de NULL si la memoria fue otorgada. Dicho puntero
      debe ser casteado al tipo de dato del vector que queremos: int, float, char, Producto, etc.
  */
  p = (int *) malloc(n * sizeof(int));

  if (p == NULL){
    cout << "No hay memoria suficiente.";
    return 1;
  }
  // Se carga el vector con su índice + 1
  for(i=0; i<n; i++){
    p[i] = i + 1;
  }
  // Se muestran todos los elementos del vector
  for(i=0; i<n; i++){
    cout << p[i] << " ";
  }
  // Se libera la memoria
  free(p);


  return 0;
}
