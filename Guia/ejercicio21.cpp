#include <iostream>
using namespace std;

int main () {

    int valoresAEvaluar;
    int numero;
    int numeroMenor;
    int numeroMayor;
    int posicionNumeroMayor;
    int posicionNumeroMenor;
   
    valoresAEvaluar = 0;
    numero = 0;
    numeroMenor = 0;
    numeroMayor = 0;
    posicionNumeroMayor = 0;
    posicionNumeroMenor = 0;

    cout << "Ingrese la cantidad de valores a evaluar: " << endl;
    cin >> valoresAEvaluar;

    for(int i = 0; i < valoresAEvaluar ; i++)
    {
        cout << "Ingrese un valor: " << endl;
        cin >> numero;
                
        if(numero > numeroMayor)
        {
            numeroMayor = numero;
            posicionNumeroMayor = i + 1;
        }
        
        if(i == 0 && numero != 0)
        {
            numeroMenor = numero;
            posicionNumeroMenor = i + 1;
        }

        if (numero < numeroMenor)
        {
            numeroMenor = numero;
            posicionNumeroMenor = i + 1;
        }
    }

    cout << "El mayor valor ingresado es " << numeroMayor << " y su posicion es " << posicionNumeroMayor << endl;
    cout << "El menor valor ingresado es: " << numeroMenor << " y su posicion es " << posicionNumeroMenor << endl;

 system("pause");
 return 0;
}