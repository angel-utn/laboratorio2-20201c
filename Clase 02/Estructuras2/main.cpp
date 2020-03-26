#include <iostream>
using namespace std;

struct Alumno{
  int legajo, edad;
  char apellido[50], nombre[50];
};

void cargarAlumnos(Alumno *vec, int tam){
  int i;
  for(i=0; i<tam; i++){
    cout << "Legajo: ";
    cin >> vec[i].legajo;
    cout << "Apellido: ";
    cin >> vec[i].apellido;
    cout << "Nombre: ";
    cin >> vec[i].nombre;
    cout << "Edad: ";
    cin >> (vec+i)->edad;
    cout << endl;
  }
}

void mostrarAlumnos(struct Alumno *vec, int tam){
 int i;
 for(i=0; i<tam; i++){
    cout << "Legajo: " << vec[i].legajo << endl;
    cout << "Apellido: " << vec[i].apellido << endl;
    cout << "Nombre: " << vec[i].nombre << endl;
    cout << "Edad: " << vec[i].edad << endl;
    cout << endl;
 }
}

int main(){
  const int TAM = 4;
  struct Alumno a[TAM];
  cargarAlumnos(a, TAM);
  cout << endl << endl;
  mostrarAlumnos(a, TAM);

  return 0;
}
