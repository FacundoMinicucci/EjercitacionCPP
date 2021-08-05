#include<iostream>
using namespace std;

void leer(string mensaje, int &valor) {
    cout << mensaje << endl;
    cin >> valor;    
}

void cargarValores(int cantidadValores, int valoresIngresados[]){

    int valor = 0;
    
    for(int i = 0; i < cantidadValores; i++)
    {
        leer("Ingrese un valor: ", valor);

        valoresIngresados[i] = valor;
    }
    return;
}

bool validarUltimoValorCargado(int cantidadValores, int valoresIngresados[]){
    return (valoresIngresados[cantidadValores - 1] < 10);
}

void imprimirValoresNegativos(int cantidadValores, int valoresIngresados[]){
    
    cout << "Valores negativos ingresados: " << endl;
    for(int i = 0; i < cantidadValores; i++)
    {
        if(valoresIngresados[i] < 0)
        { 
            cout << valoresIngresados[i] << endl;
        }               
    }  
}

void imprimirValoresPositivos(int cantidadValores, int valoresIngresados[]){
    
    cout << "valores mayores o iguales a cero ingresados: " << endl;
    for (int i = 0; i < cantidadValores; i++)
    {
        if(valoresIngresados[i] >= 0)
        {
            cout << valoresIngresados[i] << endl;
        }
        
    }
}

int main()
{
    int cantidadValores = 0;
    int valorIngresado = 0;

    leer("Ingrese la cantidad de valores a ingresar: ", cantidadValores);

    int valoresIngresados[cantidadValores] = {0};

    if(cantidadValores < 30)
    {
        cargarValores(cantidadValores, valoresIngresados);

        if(validarUltimoValorCargado(cantidadValores, valoresIngresados))
        {
            imprimirValoresNegativos(cantidadValores, valoresIngresados);
        }
        else
        {
            imprimirValoresPositivos(cantidadValores, valoresIngresados);            
        }
        
    }    

 system("pause");
 return 0;
}


