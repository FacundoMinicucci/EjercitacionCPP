#include <iostream>
using namespace std;

float promedio(float sumatoria, int cantidad)
{
    float promedio = 0;

    promedio = sumatoria / cantidad;

    return promedio;

}

int main () {

    int valorIngresado;
    int cantidadCeros;
    float promedioPositivos;    
    int sumatoriaNegativos;
    int cantidadPositivos;
    int sumatoriaPositivos;
    int cantidadNumeros;    

    valorIngresado = 0;
    cantidadCeros = 0;
    promedioPositivos = 0;
    sumatoriaNegativos = 0;
    cantidadPositivos = 0;
    sumatoriaPositivos = 0;
    cantidadNumeros = 0;

    cout << "Ingrese la cantidad de numeros que desea ingresar: " << endl;
    cin >> cantidadNumeros;

    for(int i = 0; i < cantidadNumeros; i++)
    {
        cout << "Ingrese un valor: " << endl;
        cin >> valorIngresado;

        if(valorIngresado == 0)
        {
            cantidadCeros++;
        }
        else if(valorIngresado > 0)
        {
            cantidadPositivos++;
            sumatoriaPositivos += valorIngresado;
        }
        else
        {
            sumatoriaNegativos += valorIngresado;
        }

    }

    promedioPositivos = promedio(sumatoriaPositivos,cantidadPositivos);

    cout << "Se ingresaron " << cantidadCeros << " ceros." << endl;
    cout << "El promedio de valores positivos es: " << promedioPositivos << endl;
    cout << "La sumatoria de numeros negativos es: " << sumatoriaNegativos << endl;

 system("pause");
 return 0;
}