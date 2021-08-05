#include <iostream>
using namespace std;
#define CANT_VALORES_MAX 40

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void cargarVector(int cantidadValores, int valoresIngresados[]){

    int valor = 0;

    for (int i = 0; i < cantidadValores; i++)
    {
        leer("Ingrese un valor: ", valor);
        valoresIngresados[i] = valor;
    }
    
    return;
}

int main () {
 
    int cantidadValores = 0;
    int valorMaximo = 0;    
        
    leer("Ingrese la cantidad de valores a ingresar: ", cantidadValores);

    int valoresIngresados[cantidadValores] = {0};

    if(cantidadValores <= CANT_VALORES_MAX)
    {
        cargarVector(cantidadValores, valoresIngresados);
            
        for (int i = 0; i < cantidadValores; i++)
        {
            if(valoresIngresados[i] > valorMaximo || i == 0)
            {
                valorMaximo = valoresIngresados[i];
            }
        }

        for (int i = 0; i < cantidadValores; i++)
        {
            if(valoresIngresados[i] == valorMaximo)
            {
                cout << valoresIngresados[i] << " es maximo ingresado en la posicion " << i << endl;
            }
            }
        }
    else
    {
        cout << "La cantidad de valores ingresados no esta permitida." << endl;        
    }
    
 system("pause");
 return 0;
}