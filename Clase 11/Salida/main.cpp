#include <iostream>
using namespace std;
#include <iomanip>


int main(){
    int num = 16;
    cout << setw(5);
    cout << right;
    cout << setfill('-');
    cout << num << endl;


    return 0;
}
