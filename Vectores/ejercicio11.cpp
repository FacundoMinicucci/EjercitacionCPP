#include <iostream>
using namespace std;
#define CANT_MAX_M 25
#define CANT_MAX_N 10

void ordenarVector(int vector[], int cantidadElementos){
    int i = 0;
    int aux = 0;
    bool ordenado = false;

    while(i < cantidadElementos && !ordenado)
    {
        ordenado = true;

        for(int j = 0; j < cantidadElementos - i - 1; j++)
        {
            if(vector[j] > vector[j+1])
            {
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
    return;
}

void anexarVectores(int conjuntoA[], int cantidadElementosA, int conjuntoB[], int cantidadElementosB, int conjuntoC[], int &cantidadElementosC){

    int i = 0;
    int j = 0;
    cantidadElementosC = 0;

    while(i < cantidadElementosA && j < cantidadElementosB)
    {
        if(conjuntoA[i] < conjuntoB[j])
        {
            conjuntoC[cantidadElementosC] = conjuntoA[i];
            i++;
        }
        else
        {
            conjuntoC[cantidadElementosC] = conjuntoB[j];
            j++;
        }

        cantidadElementosC++;
    }

    while(i < cantidadElementosA)
    {
        conjuntoC[cantidadElementosC] = conjuntoA[i];
        i++;
        cantidadElementosC++;
    }

    while(j < cantidadElementosB)
    {
        conjuntoC[cantidadElementosC] = conjuntoB[j];
        j++;
        cantidadElementosC++;
    }

    return;
}

void imprimirVector(int conjuntoC[], int cantidadElementosC)
{
    cout << "Vector C: " << endl;

    for (int i = 0; i < cantidadElementosC; i++)
    {
        cout << conjuntoC[i] << endl;
    }
    
}

int main () {

    int conjuntoA[CANT_MAX_M] = {1,4,2,7,6};
    int cantidadElementosA = 5;   

    int conjuntoB[CANT_MAX_N] = {3,5,0,9,8};
    int cantidadElementosB = 5;

    int cantidadElementosC = 0;
    int conjuntoC[CANT_MAX_N + CANT_MAX_M] = {0};

    // Ordeno vectores en forma creciente.
    ordenarVector(conjuntoA, cantidadElementosA);

    ordenarVector (conjuntoB, cantidadElementosB);

    // Apareo vectores luego de ordenarlos por orden creciente.
    anexarVectores(conjuntoA, cantidadElementosA, conjuntoB, cantidadElementosB, conjuntoC, cantidadElementosC);

    imprimirVector(conjuntoC, cantidadElementosC);

    system("pause");
    return 0;
}

/* Ingresar dos valores enteros M (< 25) y N (< 10) A continuación ingresar un conjunto A de M
elementos y luego otro B de N elementos, ambos ordenados en forma creciente por magnitud.
Generar e imprimir el conjunto TOTAL resultante del apareo por magnitud de los conjuntos A y B. */