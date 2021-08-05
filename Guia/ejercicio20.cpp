#include <iostream>
using namespace std;

int main() {

    float numero;
    float valorAInformar;

    numero = 0;
    valorAInformar = 0;

    for(int i = 0; i < 10; i++)
    {
        cout << "Ingrese un valor: " << endl;
        cin >> numero;

        if(numero > valorAInformar)
        {
            valorAInformar = numero;
        }
    }

    cout << "El mayor valor es: " << valorAInformar << endl;

 system("pause");
 return 0;
}