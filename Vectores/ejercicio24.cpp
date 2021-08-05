#include <iostream>
using namespace std;
#define CANT_MAX_ELEMENTOS 10

int buscarPrimerPosicion(int enteros[], int cantidadElementos, int &mayorValor){
        
    int cantidadVecesMayor = 0;

    for (int i = 0; i < cantidadElementos; i++)
    {
        if(i == 0)
        {
           mayorValor = enteros[i];
        }
        else if(enteros[i] > mayorValor)
        {
           mayorValor = enteros[i];           
        }        
    }
    
    for (int i = 0; i < cantidadElementos; i++)
    {
        if(enteros[i] == mayorValor)
        {
            return i;
        }
    }
    
}

void buscarPosicionesDelMayor(int posicionesDelMayor[], int enteros[], int cantidadElementos, int mayorValor, bool &todosIguales, int &cantidadElementosRepetidos){

    int posMayor = 0;    

    for (int i = 0; i < cantidadElementos; i++)
    {
        if(mayorValor == enteros[i])
        {
            posicionesDelMayor[cantidadElementosRepetidos] = i;
            cantidadElementosRepetidos++;
        }

        if(mayorValor != enteros[i])
        {
            todosIguales = false;
        }
    }
    return;
}

int main () {
 

    int enteros[CANT_MAX_ELEMENTOS] = {2,5,4,3,10,8,9,1,10,6};
    int cantidadElementos = CANT_MAX_ELEMENTOS;
    int posMayorValor = 0;
    int mayorValor = 0;
    int posicionesDelMayor[CANT_MAX_ELEMENTOS];
    bool todosIguales = true;
    int cantidadElementosRepetidos = 0;
   
    posMayorValor = buscarPrimerPosicion(enteros, cantidadElementos, mayorValor);

    buscarPosicionesDelMayor(posicionesDelMayor, enteros, cantidadElementos, mayorValor, todosIguales, cantidadElementosRepetidos);

    cout << "La primera posicion del valor dentro del arreglo es: " << posMayorValor << endl;
    
    if(todosIguales)
    {
        cout << "Todos los elementos del arreglo son iguales." << endl;
    }
    else
    {
        cout << "El elemento mayor se repite en las siguientes posiciones: ";
        for (int i = 0; i < cantidadElementosRepetidos; i++)
        {
            cout << posicionesDelMayor[i] << "\t";
        }
        cout << endl;
    }

    /**
     * a) - Recorrer el arreglo secuencialmente (porque nose si está ordenado) para ver todos los elementos.
     *    - Guardo la primer posicion que aparece el elemento mayor y dejo que se termine de recorrer el vector.
     * b) - Recorrer secuencialmente el vector, guardando las posiciones donde aparece el elemento buscado.
     *    - Devolver un booleano que indique si todos los elementos del vector son iguales o no.
    */

    system("pause");
    return 0;
}

/* 24.Dado un arreglo de enteros (Max = 1000) se pide desarrollar:
a) Una rutina que devuelva la posición del elemento mayor en el arreglo. Si el mayor aparece
varias veces devolver la posición de la primera aparición del mismo.
b) Una rutina que devuelva todas las posiciones en que aparece el elemento que es el mayor del
arreglo (no olvide considerar el caso en que todos los elementos sean iguales) */
