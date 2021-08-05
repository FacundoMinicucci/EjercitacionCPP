#include <iostream>
using namespace std;

void imprimirVector(int valores[], int cantidad)
{

    for (int i = 0; i < cantidad; i++)
    {
        cout << valores[i] << "\t";
    }
    cout << endl;
}

void intercambiarSimetrico(int valores[], int cantidadValores)
{
    int i = 0;
    int aux = 0;
    int cantAux = 5;

    if (cantidadValores % 2 == 0)
    {
        for (int i = 0; i < (cantidadValores / 2); i++)
        {
            aux = valores[i];
            valores[i] = valores[cantAux - 1];
            valores[cantAux - 1] = aux;
            cantAux--;
        }
    }
    else
    {
        for (int i = 0; i < (cantidadValores / 2 + 1); i++)
        {
            aux = valores[i];
            valores[i] = valores[cantAux - 1];
            valores[cantAux - 1] = aux;
            cantAux--;
        }
    }
    return;
}

void ordenarVector(int valores[], int cantidadValores)
{
    int i = 0;
    int aux = 0;
    bool ordenado = false;

    while (i < cantidadValores && !ordenado)
    {
        ordenado = true;

        for (int j = 0; j < cantidadValores - i - 1; j++)
        {
            if (valores[j] > valores[j+1])
            {
                cout << "Se intercambia el elemento " << valores[j] << " en posicion " << j << " con el elemento " << valores[j + 1] << " en posicion " << j + 1 << endl;
                aux = valores[j];
                valores[j] = valores[j+1];
                valores[j+1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
    return;
}

int main()
{

    int cantidadValores = 5;
    int valores[5] = {2, 5, 3, 1, 4}; // {4,1,3,5,2}

    // a) Intercambiar cada elemento por su simétrico.
    intercambiarSimetrico(valores, cantidadValores);

    imprimirVector(valores, cantidadValores);

    // b) ordenar de mayor a menor e indicar posicion original de cada elemento.
    ordenarVector(valores, cantidadValores);

    imprimirVector(valores, cantidadValores);

    system("pause");
    return 0;
}