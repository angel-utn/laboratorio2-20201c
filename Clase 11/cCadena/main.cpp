#include <iostream>
using namespace std;
#include "Cadena.h"

int main()
{
    Cadena s(10);
    s.setCadena("Angel");
    cout << s.getCadena();
    return 0;
}
