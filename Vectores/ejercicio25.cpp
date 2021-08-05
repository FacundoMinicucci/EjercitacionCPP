#include <iostream>
using namespace std;
#define CANT_ELEMENTOS_MAX 10

int buscarDatoSecuencial(int enteros[], int cantidadElementos, int dato){

    for (int i = 0; i < cantidadElementos; i++)
    {
        if(enteros[i] == dato)
        {
            return i;
        }
    }
    return -1;
}

int buscarPosDatoBinario(int enteros[], int cantidadElementos, int dato){
    
    int inicio = 0;
    int fin = cantidadElementos - 1;

    while(fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;

        if(enteros[mitad] == dato)
        {
            return mitad;
        }
        else if(enteros[mitad] > dato)
        {
            fin = mitad - 1;
        }
        else
        {
            inicio = mitad + 1;
        }
    }
    return -1;
}

int main () {

    int dato = 0;
    int enteros[CANT_ELEMENTOS_MAX] = {0,1,2,2,3,4,5,6,7,8};
    int cantidadElementos = CANT_ELEMENTOS_MAX;
    int primerPosDato = 0;
    int posDato = 0;

    cout << "Ingrese el dato: ";
    cin >> dato;

    primerPosDato = buscarDatoSecuencial(enteros, cantidadElementos, dato);

    if(primerPosDato != -1)
    {
        cout << "El dato aparece por primera vez en la posicion " << primerPosDato << " dentro del arreglo." << endl;       
    }
    
    posDato = buscarPosDatoBinario(enteros, cantidadElementos, dato);

    if(posDato == -1)
    {
        cout << "El dato no pertenece al arreglo." << endl;
    }
    else
    {
        cout << "El dato se encuentra en la posicion " << posDato << " del arreglo." << endl;
    }

    system("pause");
    return 0;
}