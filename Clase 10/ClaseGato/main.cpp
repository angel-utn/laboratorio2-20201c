#include <iostream>
using namespace std;

class Gato{
    private:
        char nombre[30];
        int tipo;
        float peso;

    public:
        void cargar();
        void mostrar();
        void setPeso(float);
        float getPeso();
};
void Gato::cargar(){
    float p;
    cout << "Nombre: ";
    cin.getline(nombre, 30);
    cout << "Tipo  : ";
    cin >> tipo;
    cout << "Peso  : ";
    cin >> p;
    cin.ignore();
    setPeso(p);
}
void Gato::setPeso(float nuevoPeso){
    if (nuevoPeso > 0){
        peso = nuevoPeso;
    }
}
float Gato::getPeso(){
    return peso;
}
void Gato::mostrar(){
    cout << nombre << " es de tipo " << tipo << " y pesa " << peso << " kilos.";
}

bool guardarGato(Gato reg){
    FILE *p;
    p = fopen ("gatos.gat", "ab");
    if (p == NULL){
     return false;
    }
    fwrite(&reg, sizeof(Gato), 1, p);
    fclose(p);
    return true;
}

void listarGatos(){
    Gato aux;
    FILE *p;
    p = fopen("gatos.gat", "rb");
    if (p == NULL){
        return;
    }
    while(fread(&aux, sizeof(Gato), 1, p) == 1){
        aux.mostrar();
        cout << endl;
    }
    fclose(p);
}

int main()
{
    Gato g;
    g.cargar();
    g.mostrar();

    return 0;
}
