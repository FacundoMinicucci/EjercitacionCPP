#include <iostream>
using namespace std;
#define CANT_MAX_ELEMENTOS 1000

int main () {
 
    int numero = 0;
    int numeros[CANT_MAX_ELEMENTOS] = {0};

    for (int i = 0; i < CANT_MAX_ELEMENTOS; i++)
    {
        numeros[i] = numero;
        numero++;
    }

    for (int i = CANT_MAX_ELEMENTOS - 1; i >= 0; i--)
    {
        cout << numeros[i] << "\t";
    }
    
    cout << endl;
    


    system("pause");
    return 0;
}