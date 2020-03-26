#include <iostream>
using namespace std;

int main(){
  int v[5] = {10, 20, 30, 40, 50};
  /**

    v+0 --> &v[0]
    v+1 --> &v[1]
    v+N --> &v[N]

    *(v+0) --> *&v[0]
    *(v+N) --> *&v[N]

  */
  for(int *p=v; p < v+5; p++){
    cout << *p << endl;
  }


  return 0;
}
