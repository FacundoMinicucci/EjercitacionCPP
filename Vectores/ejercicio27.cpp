#include <iostream>
using namespace std;
#define CANT_MAX_ENTEROS 10

void eliminarElemento(int enteros[], int cantidadElementos, int pos){
    
    for (int i = 0; i < cantidadElementos; i++)
    {
        if(i == pos)
        {
            while(i < cantidadElementos)
            {
                enteros[i] = enteros[i+1];
                i++;
            }
        }
    }
    return;
}

int main () {
 
    int pos = 0;
    int cantidadElementos = CANT_MAX_ENTEROS;
    int enteros[CANT_MAX_ENTEROS] = {1,2,3,4,5,6,7,8,9,10};

    cout << "Ingrese la posicion del elemento a eliminar: ";
    cin >> pos;

    int eliminado = enteros[pos];
    
    if(pos > cantidadElementos)
    {
        cout << "El elemento no pertenece al vector." << endl;
    }
    else
    {
        cout << "El elemento de la posicion " << pos << " es el elemento " << enteros[pos] << endl;
        eliminarElemento(enteros, cantidadElementos, pos);
    }

    for (int i = 0; i < cantidadElementos - 1; i++)
    {
        cout << enteros[i] << "\t";
    }
    
    cout << endl;

    system("pause");
    return 0;
}

/* Dado un arreglo de enteros (Max = 1000) y otro entero (POS) que representa la posición de un
elemento del arreglo, se pide desarrollar una rutina que elimine del arreglo el elemento que se
encuentra en la posición POS. */