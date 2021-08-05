#include <iostream>
using namespace std;
#define CANT_VALORES_MAX 40

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void cargarVector(int cantidadValores, int valoresIngresados[]){

    int valor = 0;

    for(int i = 0; i < cantidadValores; i++)
    {
        leer("Ingrese un valor: ", valor);

        valoresIngresados[i] = valor;
    }
    return;
}


int main () {
 
    int cantidadValores = 0;

    leer("Ingrese la cantidad de valores a ingresar: ", cantidadValores);

    int conjuntoA[cantidadValores] = {0}; 
    int conjuntoB[cantidadValores] = {0}; 
    int conjuntoC[cantidadValores] = {0};

    cout << "Valores del conjunto A: " << endl;
    cargarVector(cantidadValores, conjuntoA);

    cout << "Valores del conjunto B: " << endl;
    cargarVector(cantidadValores, conjuntoB);

    for (int i = 0; i < cantidadValores; i++)
    {
        conjuntoC[i] = conjuntoA[i] + conjuntoB[cantidadValores - 1 - i];
    }

    for (int i = 0; i < cantidadValores; i++)
    {
        cout << conjuntoC[i] << endl;
    }

 system("pause");
 return 0;
}