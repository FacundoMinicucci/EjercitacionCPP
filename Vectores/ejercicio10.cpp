#include <iostream>
using namespace std;

void leer(string mensaje, int &valor)
{
    cout << mensaje << endl;
    cin >> valor;
    return;
}

void cargarVector(int vector[], int longitud, string mensaje)
{
    cout << mensaje << endl;
    for (int i = 0; i < longitud; i++)
    {
        cin >> vector[i];
    }
    return;
}

void apareoVectores(int vectorA[], int longitudA, int vectorB[], int longitudB, int vectorC[], int &longitudC){

    int i = 0;
    int j = 0;


    while (i < longitudA && j < longitudB)
    {
        if(vectorA[i] < vectorB[j])
        { 
            vectorC[longitudC] = vectorA[i];

            i++;
        }
        else
        {
            vectorC[longitudC] = vectorB[j];

            j++;
        }

        longitudC++;
    }

    while (i < longitudA)
    {
        vectorC[longitudC] = vectorA[i];
        i++;
        longitudC++;
    }

    while (j < longitudB)
    {
        vectorC[longitudC] = vectorB[j];
        j++;
        longitudC++;
    }
    
    return;
}

void imprimirVector(int vector[], int longitud){

    for (int i = 0; i < longitud; i++)
    {
        cout << vector[i] << endl;
    }
    return;
}

void apareoVectoresDistintoCero(int vectorA[], int longitudA, int vectorB[], int longitudB, int vectorD[], int &longitudD){
    
    int i = 0;
    int j = 0;

    while (i < longitudA && j < longitudB)
    {
        if(vectorA[i] < vectorB[j])
        {
            if(vectorA[i] != 0)
            {
                vectorD[longitudD] = vectorA[i];
                longitudD++;
            }

            i++;
        }
        else
        {
            if(vectorB[j] != 0)
            {
                vectorD[longitudD] = vectorB[j];
                longitudD++;
            }

            j++;
        }

        
    }

    while (i < longitudA)
    {
        if(vectorA[i] != 0)
        {
            vectorD[longitudD] = vectorA[i];
            longitudD++;
        }
        i++;        
    }

    while (j < longitudB)
    {
        if (vectorB[j] != 0)
        {
            vectorD[longitudD] = vectorB[j];
            longitudD++;            
        }
        
        j++;
    }
    
    return;
}

int main () {
 
    int cantidadElementosA = 0;
    int cantidadElementosB = 0;
    int cantidadElementosC = 0;
    int cantidadElementosD = 0;
    int vectorC[cantidadElementosC] = {0};
    int vectorD[cantidadElementosD] = {0};

    leer("Ingrese la cantidad de elementos de A: ", cantidadElementosA);
    leer("Ingrese la cantidad de elementos de B: ", cantidadElementosB);

    int vectorA[cantidadElementosA] = {0};
    int vectorB[cantidadElementosB] = {0};
    
    cargarVector(vectorA, cantidadElementosA, "Ingrese los valores del vector A: ");

    cargarVector(vectorB, cantidadElementosB, "Ingrese los valores del vector B: " );
  
    apareoVectores(vectorA, cantidadElementosA, vectorB, cantidadElementosB, vectorC, cantidadElementosC);

    apareoVectoresDistintoCero(vectorA, cantidadElementosA, vectorB, cantidadElementosB, vectorD, cantidadElementosD);

    cout << "Elementos de A: " << endl;
    imprimirVector(vectorA, cantidadElementosA);

    cout << "Elementos de B: " << endl;
    imprimirVector(vectorB, cantidadElementosB);

    cout << "Elementos de C: " << endl;
    imprimirVector(vectorC, cantidadElementosC);

    cout << "Elementos de D: " << endl;
    imprimirVector(vectorD, cantidadElementosD);

    system("pause");
    return 0;
}