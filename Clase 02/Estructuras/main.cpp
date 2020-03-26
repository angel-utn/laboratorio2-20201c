#include <iostream>
using namespace std;

struct Alumno{
  int legajo, edad;
  char apellido[50], nombre[50];
};
/**
int cargarEntero(){
  int i;
  cin >> i;
  return i;
}
void mostrarEntero(int num){
  cout << num;
}

int main(){
 int x;
 x = cargarEntero();
 mostrarEntero(x);
 return 0;
}
*/

struct Alumno cargarAlumno(){
  struct Alumno reg;
  cout << "Legajo: ";
  cin >> reg.legajo;
  cout << "Apellido: ";
  cin >> reg.apellido;
  cout << "Nombre: ";
  cin >> reg.nombre;
  cout << "Edad: ";
  cin >> reg.edad;
  return reg;
}

void mostrarAlumno(struct Alumno reg){
  cout << "El alumno " << reg.apellido << ", " << reg.nombre;
  cout << " tiene " << reg.edad << " años y tiene ";
  cout << " el legajo nro " << reg.legajo;
}

int main(){
  struct Alumno a;
  a = cargarAlumno();
  cout << endl;
  mostrarAlumno(a);

  return 0;
}
