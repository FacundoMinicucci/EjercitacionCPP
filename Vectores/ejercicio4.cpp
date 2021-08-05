#include <iostream>
using namespace std;
#define CANT_VALORES_MAX 25

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
    int sumaValores = 0;

    leer("Ingrese la cantidad de valores a ingresar: ", cantidadValores);

    int valoresIngresados[cantidadValores] = {0};

    if(cantidadValores <= CANT_VALORES_MAX)
    {
        cargarVector(cantidadValores, valoresIngresados);

        for (int i = 0; i < cantidadValores; i++)
        {
            sumaValores += valoresIngresados[i];
        }

        if(sumaValores > 0)
        {
            for (int i = 0; i < cantidadValores; i++)
            {
                if(i % 2 != 0)
                {
                    cout << valoresIngresados[i] << endl;
                }
            }            
        }
        else
        {
            for (int i = 0; i < cantidadValores; i++)
            {
                if(i % 2 == 0)
                {
                    cout << valoresIngresados[i] << endl;
                }
            }        
        }        
        
    }


 system("pause");
 return 0;
}