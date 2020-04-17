#include <iostream>
using namespace std;
#include <cstdio>

#include "rlutil.h"

using namespace rlutil;

struct Producto {
	int id;
	char nombre[50];
	float precio;
	int stock;
	int stock_min;
};

void listar_producto(Producto reg) {

	setColor(BLUE);

	cout << "ID      :   " << reg.id << endl;
	setColor(WHITE);


	cout << "NOMBRE  :   " << reg.nombre << endl;
	cout << "PRECIO  : $ " << reg.precio << endl;
	cout << "STOCK   :   " << reg.stock << endl;
	cout << "STOCK M :   " << reg.stock_min << endl;
}

bool cargar_producto(Producto* p) {
	cout << "ID: ";
	cin >> p->id;

	cout << "NOMBRE  : ";
	cin.ignore();
	cin.getline(p->nombre, 30);

	cout << "PRECIO  : $";
	cin >> p->precio;

	if (p->precio < 0) {
		return false;
	}
	cout << "STOCK   : ";
	cin >> p->stock;

	if (p->stock < 0) {
		return false;
	}
	cout << "STOCK M : ";
	cin >> p->stock_min;

	if (p->stock_min < 0) {
		return false;
	}

	return true;
}


bool guardarProductoEnArchivo(Producto reg) {
	FILE* p;
	p = fopen("productos.dat", "ab");

	if (p == NULL) {
		cout << "No se pudo abrir el archivo.";
		return false;
	}

	fwrite(&reg, sizeof(Producto), 1, p);
	fclose(p);

	return true;
}

bool listarProductosDeArchivo() {
	FILE* p;
	Producto reg;

	int cantidad = 0;

	p = fopen("productos.dat", "rb");
	if (p == NULL) {
		cout << "No se pudo abrir el archivo.";
		return false;
	}

	while (fread(&reg, sizeof(Producto), 1, p) == 1)
	{
		cout << "----------------------------------" << endl;
		listar_producto(reg);
		cantidad++;
	}

	fclose(p);

	return true;
}

int buscarProductoEnArchivo(int id, Producto *preg) {
	
	FILE* p;
	Producto reg;

	p = fopen("productos.dat", "rb");
	if (p == NULL) {
		cout << "No se pudo abrir el archivo.";

		return -1;
	}

	while (fread(&reg, sizeof(Producto), 1, p) == 1)
	{
		if (reg.id == id) {
			*preg = reg;
			fclose(p);
			return 1;
		}
	}

	fclose(p);

	return 0;

}




int main()
{
	/*
	Producto reg;
	
	if (cargar_producto(&reg) == true){
		if (guardarProductoEnArchivo(reg) == false)
		{
			return 1;
		}
	}
	*/

	/*
	if (listarProductosDeArchivo() == false)
	{
		return -1;
	}
	*/

	Producto reg;

	switch (buscarProductoEnArchivo(2, &reg))
	{
	case 1:
		listar_producto(reg);
		break;
	case 0:
		cout << "No se encontro el producto." << endl;
		break;
	case -1:
		return -1;
	}


	



	/*
	FILE* p;
	p = fopen("productos.dat", "rb");
	if (p == NULL) {
		cout << "No se pudo abrir el archivo.";
		return 1;
	}
	
	while (fread(&reg, sizeof(Producto), 1, p) == 1)
	{
		cout << "----------------------------------" << endl;
		listar_producto(reg);
	}
	
	fclose(p);

	*/


	return 0;
}
