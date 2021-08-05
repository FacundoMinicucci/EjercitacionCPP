#include <iostream>
using namespace std;
#define CANT_VALORES_MAX 40

void leer(string mensaje, float &valor){
    cout << mensaje << endl;
    cin >> valor;
    return;
}

int busquedaBinaria(float valoresReales[], int cantidadValoresReales, float valorPesquisa){

    int inicio = 0;
    int fin = cantidadValoresReales - 1;

    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;

        if(valoresReales[mitad] == valorPesquisa)
        {
            return mitad;
        }
        else if(valoresReales[mitad] > valorPesquisa)
        {
            fin = mitad - 1;
        }
        else
        {
            inicio = mitad + 1;
        }
    }
    return -1;
}

int main () {
    
    int cantidadValoresReales = 5;
    float valoresReales[CANT_VALORES_MAX] = {1,3,4,6,9};
    float valorPesquisa = 0;
    int posValorPesquisa = 0;

    leer("Ingrese el valor pesquisa: ", valorPesquisa);   

    // a) Con cual elemento (posición) del conjunto coincide
    posValorPesquisa = busquedaBinaria(valoresReales, cantidadValoresReales, valorPesquisa);
    if(posValorPesquisa != -1 && posValorPesquisa != 0 && posValorPesquisa != cantidadValoresReales-1)
    {
        cout << "Coincide con el elemento de la posicion " << posValorPesquisa << endl;
        cout << "Se encuentra entre los elementos " << valoresReales[posValorPesquisa - 1] << " y " << valoresReales[posValorPesquisa + 1] << endl;
    }

    if(valoresReales[0] > valorPesquisa && posValorPesquisa != 0)
    {
        cout << "Es menor que el primer elemento del vector." << endl;
    }
    else if(valoresReales[cantidadValoresReales - 1] < valorPesquisa && posValorPesquisa != cantidadValoresReales-1)
    {
        cout << "Es mayor que el ultimo elemento del vector." << endl;
    }

    system("pause");
    return 0;
}