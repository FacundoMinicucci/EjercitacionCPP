#include <iostream>
using namespace std;
#define CANT_VALORES_MAX 15

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
    int segundoValorMaximo = 0;
    int posicionValorMaximo = 0;
    int posicionSegundoValorMaximo = 0;

    leer("Ingrese la cantidad de valores a ingresar: ", cantidadValores);

    int conjuntoA[cantidadValores] = {0};
    int conjuntoMayoresA[2];

    cargarVector(cantidadValores, conjuntoA);

    for(int i = 0; i < cantidadValores; i++)
    {
        if(conjuntoA[i] > conjuntoMayoresA[0] || i == 0)
        {            
            conjuntoMayoresA[0] = conjuntoA[i];
            posicionValorMaximo = i;            
        }   
                
    }

    for(int i = 0; i < cantidadValores; i++)
    {
        if((conjuntoA[i] < conjuntoMayoresA[0] && conjuntoA[i] > segundoValorMaximo) || i == 0)
        {
            segundoValorMaximo = conjuntoA[i];
            conjuntoMayoresA[1] = conjuntoA[i];
            posicionSegundoValorMaximo = i;
        }
        else if(conjuntoA[i] == conjuntoMayoresA[0] && i != posicionValorMaximo)
        {
            segundoValorMaximo = conjuntoMayoresA[0];
            conjuntoMayoresA[1] = conjuntoMayoresA[0];
            posicionSegundoValorMaximo = i;
        }        
    }
        
    cout << "El mayor valor ingresado es " << conjuntoMayoresA[0] << " en la posicion " << posicionValorMaximo << endl;
        
    cout << "El segundo mayor valor ingresado es " << conjuntoMayoresA[1] << " en la posicion " << posicionSegundoValorMaximo << endl;
          
 system("pause");
 return 0;
}

/* Ingresar un valor entero N (< 15). A continuación ingresar un conjunto DATO de N elementos.
Generar otro conjunto de dos componentes MEJORDATO donde el primer elemento sea el mayor
valor de DATO y el segundo el siguiente mayor (puede ser el mismo si está repetido). Imprimir el
conjunto MEJORDATO con identificación. */

                