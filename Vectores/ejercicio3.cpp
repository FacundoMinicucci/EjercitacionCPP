#include <iostream>
using namespace std;
#define CANT_VALORES_MAX 20

void leer(string mensaje, int &valor) {
    cout << mensaje << endl;
    cin >> valor;

    return;    
}

int calcularFactorial(int valor){  
    
    int factorial = 1;

    for(int i = 1; i <= valor; i++)
    {
        factorial = factorial * i;        
    }

    return factorial;
}

void cargarValores(int cantidadValores, int valores[]){

    int valor = 0;

    for (int i = 0; i < cantidadValores; i++)
    {
        leer("Ingrese un valor: ", valor);

        valores[i] = valor;
    }    

    return;
}

void cargarFactoriales(int cantidadValores, int valores[], int factoriales[]){

    for (int i = 0; i < cantidadValores; i++)
    {
        factoriales[i] = calcularFactorial(valores[i]);
    }    

    return;
}

int main () {
 
    int valorIngresado = 0;
    int cantidadValores = 0;

    leer("Ingrese la cantidad de valores: ", cantidadValores);

    int valores[cantidadValores] = {0};
    int factoriales[cantidadValores] = {0};

    if(cantidadValores <= CANT_VALORES_MAX)
    {
        cargarValores(cantidadValores, valores);

        cargarFactoriales(cantidadValores, valores, factoriales);
        for (int i = 0; i < cantidadValores; i++)
        {
            cout << "En la posicion " << i << " se ingreso el valor " << valores[i] << " y su factorial es " << factoriales[i] << endl;    
        }
    }
    else
    {
        cout << "Ingresaste una cantidad de valores incorrecta." << endl;
    } 


 system("pause");
 return 0;
}

/* Ingresar un valor entero N (< 20). A continuación ingresar un conjunto VEC de N componentes.
A partir de este conjunto generar otro FACT en el que cada elemento sea el factorial del elemento
homólogo de VEC. Finalmente imprimir ambos vectores a razón de un valor de cada uno por
renglón */