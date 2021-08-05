#include <iostream>
using namespace std;
#define CANT_VALORES_MAX 25

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
    int valoresImpresosCount = 0;

    leer("Ingrese la cantidad de valores a ingresar: ", cantidadValores);

    int valoresIngresados[cantidadValores] = {0};

    if(cantidadValores <= CANT_VALORES_MAX)
    {
        cargarVector(cantidadValores, valoresIngresados);

        // Uno por línea
        cout << "Impresion uno por linea." << endl;
        for(int i = cantidadValores - 1; i >= 0; i--)
        {
            cout << valoresIngresados[i] << endl;
        }

        // Diez por línea
        cout << "Impresion diez por linea." << endl;
        for(int i = cantidadValores - 1; i >= 0; i--)
        {            
            valoresImpresosCount++;

            cout << valoresIngresados[i] << " ";

            if(valoresImpresosCount == 10)
            {
                cout << endl;
                valoresImpresosCount = 0;
            }

        }

        // Cinco por línea
        cout << endl << "Impresion cinco por linea." << endl;
        valoresImpresosCount = 0;

        for(int i = cantidadValores - 1; i >= 0; i--)
        {            
            valoresImpresosCount++;

            cout << valoresIngresados[i] << " ";

            if(valoresImpresosCount == 5)
            {
                cout << endl;
                valoresImpresosCount = 0;
            }

        }

    }
    else
    {
        cout << "La cantidad de valores a ingresar no esta permitida." << endl;
    }

 system("pause");
 return 0;
}