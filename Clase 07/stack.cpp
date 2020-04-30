#include <iostream>
using namespace std;
int main(){
  const int TAM = 8000 * 1000; /// 8 millones de elementos
  int vec[TAM];

  cout << "Si ves esto, tu SO pudo generar un vector de int de 8 millones de elementos en la stack.";

  return 0;
}
