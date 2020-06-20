#include <iostream>
#include "rlutil.h"
using namespace rlutil;
using namespace std;

#include "Examen.h"
#include "funciones.h"


const char* FILE_EXAMEN = "../datos/examenes.dat";

int Examen::getLegajo() {
	return legajo;
}

void Examen::setLegajo(int legajo) {
	this->legajo = legajo;
}

int Examen::getIdMateria() {
	return idMateria;
}

void Examen::setIdMateria(int idMateria) {
	this->idMateria = idMateria;
}

float Examen::getNota() {
	return nota;
}

void Examen::setNota(float nota) {
	this->nota = nota;
}

bool Examen::cargar() {
	cout << "Legajo: ";
	cin >> legajo;

	cout << "Id Materia: ";
	cin >> idMateria;

	cout << "Nota: ";
	cin >> nota;

	return true;
}

void Examen::mostrar() {
	cout << "Legajo     : " << legajo << endl;
	cout << "Id Materia : " << idMateria << endl;
	cout << "Nota       : " << nota << endl;
}

bool Examen::guardar() {
	bool resultado;
	FILE* p;
	p = fopen(FILE_EXAMEN, "ab");
	if (p == NULL) {
		return false;
	}
	resultado = fwrite(this, sizeof(Examen), 1, p);
	fclose(p);
	return resultado;
}

bool Examen::guardar(int pos) {
	bool resultado = false;
	FILE* p;
	p = fopen(FILE_EXAMEN, "rb+");
	if (p == NULL) {
		return false;
	}
	if (pos >= 0) {
		fseek(p, pos * sizeof(Examen), SEEK_SET);
		resultado = fwrite(this, sizeof(Examen), 1, p);
	}
	fclose(p);
	return resultado;
}

bool Examen::leer(int pos) {
	bool resultado = false;
	FILE* p;
	p = fopen(FILE_EXAMEN, "rb");
	if (p == NULL) {
		return false;
	}
	if (pos >= 0) {
		fseek(p, pos * sizeof(Examen), SEEK_SET);
		resultado = fread(this, sizeof(Examen), 1, p);
	}
	fclose(p);
	return resultado;
}

bool nuevo_examen()
{
	Examen reg;
	if (reg.cargar()) {
		if (reg.guardar()) {
			return true;
		}
	}
	return false;
}

void listar_examenes()
{
	Examen reg;
	int i = 0;
	cls();
	cout << "Listado de examenes" << endl;
	cout << "------------------------" << endl;

	while (reg.leer(i++)) {
		//TODO: Listarlo con setw
		reg.mostrar();
		cout << endl;
	}
	cin.ignore();
	anykey();
}

void listar_examen()
{
	cls();
	int legajo, idMateria;
	int pos;
	cout << "Legajo de alumno: ";
	cin >> legajo;

	cout << "Id Materia del examen: ";
	cin >> idMateria;

	pos = buscar_examen(legajo, idMateria);
	if (pos >= 0) {
		cls();
		Examen reg;
		reg.leer(pos);
		reg.mostrar();
	}
	else {
		error_msj("No existe el examen");
	}
}

int buscar_examen(int legajo, int idMateria)
{
	Examen reg;
	int i = 0;
	while (reg.leer(i)) {
		if (reg.getLegajo() == legajo 
			&& reg.getIdMateria() == idMateria) {
			return i;
		}
		i++;
	}
	return -1;
}
