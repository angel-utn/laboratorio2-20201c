#include <iostream>
using namespace std;

void listar(int *v, int t){
    for(int i=0; i<t; i++){
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

void ordenar(int *v, int t){
    int i, j, aux, pos;
    for(i=0; i<t-1; i++){
        pos = i;

        for(j=i+1; j<t; j++){
            if (v[j] > v[pos]){
                pos = j;
            }
        }
        aux = v[i];
        v[i] = v[pos];
        v[pos] = aux;
    }

}

int main(){
    int v[10] = {90, 5, 66, 44, 32, 1, 67, 88, 5, -3};
    listar(v, 10);
    ordenar(v, 10);
    listar(v, 10);

    return 0;
}
