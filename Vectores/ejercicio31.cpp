#include <iostream>
using namespace std;
#define CANT_MAX_ENTEROS 1000

void ordenarEnteros(int enteros[], int cantidadElementos){

    int i = 0;
    int aux = 0;
    bool ordenado = false;

    while(i < cantidadElementos && !ordenado)
    {
        ordenado = true;

        for (int j = 0; j < cantidadElementos-i-1; j++)
        {
            if(enteros[j] > enteros[j+1])
            {
                aux = enteros[j];
                enteros[j] = enteros[j+1];
                enteros[j+1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
    return;
}

int main () {
    
    int valorEntero = 0;
    int cantidadElementos = 0;
    int enteros[CANT_MAX_ENTEROS] = {0};
    int cantidadMayores = 20;   

    cout << "Ingrese un valor entero (-1 para terminar): ";
    cin >> valorEntero;

    while (valorEntero > 0)
    {
        enteros[cantidadElementos] = valorEntero;
        cantidadElementos++;

        cout << "Ingrese un valor entero (-1 para terminar): ";
        cin >> valorEntero;
    }
    
    ordenarEnteros(enteros, cantidadElementos);
   
    for (int i = 0; i < cantidadMayores; i++)
    {
        cout << enteros[cantidadElementos-i-1] << endl;
    }  

    system("pause");
    return 0;
}