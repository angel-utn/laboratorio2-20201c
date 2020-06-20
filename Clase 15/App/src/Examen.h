#pragma once
class Examen
{
private:
	int idMateria;
	int legajo;
	float nota;

public:
	int getLegajo();
	void setLegajo(int legajo);

	int getIdMateria();
	void setIdMateria(int idMateria);

	float getNota();
	void setNota(float nota);


	bool cargar();
	void mostrar();
	bool guardar();
	bool guardar(int pos);
	bool leer(int pos);

};


/* Funciones globales de examen */
bool nuevo_examen();
void listar_examenes();
void listar_examen();
int buscar_examen(int legajo, int idMateria);

