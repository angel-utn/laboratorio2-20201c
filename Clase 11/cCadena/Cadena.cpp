#include <cstdlib>
#include <cstring>
#include "Cadena.h"

Cadena::Cadena(int tam){
    //str = (char *) malloc(tam * sizeof(char));
    str = new char[tam];
}
Cadena::~Cadena(){
    if (str != NULL){
        delete str;
    }
}
void Cadena::setCadena(char *s){
    strcpy(str, s);
}
char * Cadena::getCadena(){
    return str;
}
