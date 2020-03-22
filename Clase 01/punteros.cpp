#include <iostream>
using namespace std;

void poner0_vector(int *p, int tam){
  int i;
  for(i=0; i<tam; i++){
    p[i] = 0;
  }
}
void cargar_vector(int *p, int tam){
  int i;
  for(i=0; i<tam; i++){
    cout << "Valor: ";
    cin >> *(p+i);
  }
}
void mostrar_vector(int *p, int tam){
  int *i;
  for(i=p; i<p+tam; i++){
    cout << *i << endl;
  }
}

int main(){
  const int a= 4;
  int v[a]={0};

  cargar_vector(v, a);
  cout << endl;
  mostrar_vector(v, a);
  return 0;
}


