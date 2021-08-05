#include <iostream>
using namespace std;

int main() {

    int numero;
    int cantidadMayores100;
    int sumaMayores100;
    int promedioMayores100;
    int sumaMenoresMenos10;
    int cantidadMenoresMenos10;

    numero = 0;
    cantidadMayores100 = 0;
    sumaMayores100 = 0;
    promedioMayores100 = 0;
    sumaMenoresMenos10 = 0;
    cantidadMenoresMenos10 = 0;

    cout << "Ingrese 50 valores: " << endl;

    for(int i = 0; i < 50; i++)
    {   
        cin >> numero;
        if(numero > 100)
        {
            cantidadMayores100 = cantidadMayores100 + 1;
            sumaMayores100 = sumaMayores100 + numero;
        }
        else if (numero < -10)
        {
            cantidadMenoresMenos10 = cantidadMenoresMenos10 + 1;
            sumaMenoresMenos10 = sumaMenoresMenos10 + numero;
        }
    }

    if(cantidadMayores100 > 0)
    {
        promedioMayores100 = sumaMayores100 / cantidadMayores100;
        cout << "El promedio de los numeros mayores que 100 ingresados es: " << promedioMayores100 << endl;
    }
    else
    {
        cout << "No se ingresaron numeros mayores a 100." << endl;
    }

    if(cantidadMenoresMenos10 > 0)
    {
        cout << "La suma de los numeros menores que -10 ingresados es: " << sumaMenoresMenos10 << endl;
    }
    else
    {
        cout << "No se ingresaron numeros menores que -10." << endl;
    }

 system("pause");
 return 0;
}