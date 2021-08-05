#include <iostream>
using namespace std;

int main () {
 
    int numero;
    int cantidadValores;

    numero = 0;
    cantidadValores = 0;

    int i = 0;
    while(i >= 0)
    {
        cout << "Ingrese un valor: " << endl;
        cin >> numero;   
        cantidadValores++;
        i = numero;
    }

    cout << "Se ingresaron " << cantidadValores << " valores." << endl;

 system("pause");
 return 0;
}