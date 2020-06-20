#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"

void error_msj(const char *msj, int x, int y){
    if (x==-1 && y==-1){
            y = trows()-1;
            x = 0;
    }
    gotoxy(x,y);
    setColor(LIGHTRED);
    cout << "> " << msj << endl;
    setColor(WHITE);
}
void ok_msj(const char *msj, int x, int y){
    if (x==-1 && y==-1){
            y = trows()-1;
            x = 0;
    }
    gotoxy(x,y);
    setColor(LIGHTBLUE);
    cout << "> " << msj << endl;
    setColor(WHITE);
}
