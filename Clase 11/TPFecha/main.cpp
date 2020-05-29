#include <iostream>
using namespace std;
#include "fecha.h"

int main(){
    Fecha f1;
    f1.mostrar();

    Fecha f2(1, 1, 2019);;
    f2.mostrar();


    return 0;
}
