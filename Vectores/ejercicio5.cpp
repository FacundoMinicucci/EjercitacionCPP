#include <iostream>
using namespace std;
#define CANT_VALORES_MAX 30

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void cargarVector(int cantidadValores, int valores[]){

    int valor = 0;

    for (int i = 0; i < cantidadValores; i++)
    {
        leer("Ingrese un valor: ", valor);

        valores[i] = valor;
    }    

    return;
}

int main () {
 
    int cantidadValores = 0;

    leer("Ingrese la cantidad de valores a ingresar: ", cantidadValores);

    int conjuntoValoresA[cantidadValores] = {0};
    int conjuntoValoresB[cantidadValores] = {0};
    int conjuntoValoresC[cantidadValores] = {0};

    if(cantidadValores <= CANT_VALORES_MAX)
    {
        cout << "Ingrese valores del primer conjunto: " << endl;
        cargarVector(cantidadValores, conjuntoValoresA);

        cout << "Ingrese valores del segundo conjunto: " << endl;
        cargarVector(cantidadValores, conjuntoValoresB);

        for (int i = 0; i < cantidadValores; i++)
        {
            if(i % 2 == 0)
            {
                conjuntoValoresC[i] = conjuntoValoresA[i];
            }
            else
            {
                conjuntoValoresC[i] = conjuntoValoresB[i];
            }
        }
        
        cout << "El conjunto C quedo conformado por los valores: " << endl;
        for (int i = 0; i < cantidadValores; i++)
        {
            cout << conjuntoValoresC[i] << endl;
        }
        

    }

 system("pause");
 return 0;
}