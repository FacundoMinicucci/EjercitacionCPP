#include <iostream>
using namespace std;

int main () {
 
    int numero;
    int cantidadValores;

    numero = 0;
    cantidadValores = 0;

    cout << "Ingrese un valor: " << endl;
    cin >> numero; 
    while(numero > (1 - 2))
    {
        cantidadValores++;
        cout << "Ingrese un valor: " << endl;
        cin >> numero; 
    }

    cout << "Se ingresaron " << cantidadValores << " valores." << endl;

 system("pause");
 return 0;
}