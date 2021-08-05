#include <iostream>
using namespace std;
#define CANT_MAX_ELEMENTOS 30

void leer(string mensaje, string &valor){
    cout << mensaje << endl;
    cin >> valor;  
}

void leer(string mensaje, float &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

int sumarVector(float vector[], int cantElementos)
{
    int suma = 0;
    for (int i = 0; i < cantElementos; i++)
    {
        suma += vector[i];
    }
    return suma;
}

int main () {

    float valor = 0;
    int cantidadElementosP = 0;
    int cantidadElementosQ = 0;
    float vectorP[CANT_MAX_ELEMENTOS] = {0};
    float vectorQ[CANT_MAX_ELEMENTOS] = {0};
    string letraVector = "";
    string keyLetra = "";
    int cantidadElementosTotales = 0;
    int sumaVectores = 0;     

    cout << "Ingrese el vector al que pertenece el valor(F para terminar): ";
    cin >> letraVector;
   
    // Crear funcion cargar vectores con este while.
    while((letraVector == "P" || letraVector == "Q") && cantidadElementosTotales < CANT_MAX_ELEMENTOS)
    {
        keyLetra = letraVector;
        
        while((letraVector == "P" || letraVector == "Q") && cantidadElementosTotales < CANT_MAX_ELEMENTOS && letraVector == keyLetra)
        {
            cout << "Ingrese un valor:";
            cin >> valor;
            if(letraVector == "P")
            {
                vectorP[cantidadElementosP] = valor;
                cantidadElementosP++;
            }
            else if(letraVector == "Q")
            {
                vectorQ[cantidadElementosQ] = valor;
                cantidadElementosQ++;
            }

            cantidadElementosTotales++;

            cout << "Ingrese el vector al que pertenece el valor(F para terminar): ";
            cin >> letraVector;
        }        
    }

    sumaVectores += sumarVector(vectorP, cantidadElementosP);
    sumaVectores += sumarVector(vectorQ, cantidadElementosQ);

    cout << "Suma de vectores: " << sumaVectores << endl;

    system("pause");
    return 0;
}