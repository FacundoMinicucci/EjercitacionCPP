#include <iostream>
using namespace std;
#define CANT_MAX_FILAS 30
#define CANT_MAX_COLUMNAS 25

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void cargarMatriz(int matriz[CANT_MAX_FILAS][CANT_MAX_COLUMNAS], int filas, int columnas){
        
    for(int i = 0; i < filas; i++)
    {   
        cout << "Ingrese los valores de la fila " << i + 1 << ": " << endl;
        for (int j = 0; j < columnas; j++)
        {
            cin >> matriz[i][j];
        }        
    }    
}

int main () {
 
    int numeroFilas;
    int numeroColumnas;
    int matrizA[CANT_MAX_FILAS][CANT_MAX_COLUMNAS] = {0};
    float promedioMatrizA = 0;
    int cantidadElementos = 0;
    float sumaElementos = 0;

    leer("Ingrese el numero de filas: ", numeroFilas);
    leer("Ingrese el numero de columnas: ", numeroColumnas);

    if(numeroFilas < 31 && numeroColumnas < 26)
    {
        cargarMatriz(matrizA, numeroFilas, numeroColumnas);    

        // a) Imprimir la matriz A por columnas.
        for(int i = 0; i < numeroFilas; i++)
        {
            for(int j = 0; j < numeroColumnas; j++)
            {
                cout << matrizA[i][j];
            }
            cout << endl;
        } 

        // b) Calcular e imprimir el valor promedio de los componentes de la matriz.
        for(int i = 0; i < numeroFilas; i++)
        {
            for(int j = 0; j < numeroColumnas; j++)
            {
                sumaElementos += matrizA[i][j];
                cantidadElementos++;
            }
            
        } 
        promedioMatrizA = sumaElementos/cantidadElementos;
        cout << "El promedio de la matriz A es: " << promedioMatrizA << endl;
    }
    else
    {
        cout << "El numero de filas o columnas ingresado es incorrecto." << endl;
    }
    return 0;
}

/*Ingresar dos valores, M (< 30) y N (< 25) y a continuación por filas todos los componentes de
una matriz MATRIZA de M filas y N columnas. Desarrollar un programa que:
a) Imprima la matriz MATRIZA por columnas.
b) Calcule e imprima el valor promedio de los componentes de la matriz.
c) Genere e imprima un vector VECSUMCOL donde cada componente sea la suma de la columna
homóloga.
d) Genere e imprima un vector VECMAXFIL donde cada componente sea el valor máximo de cada
fila.*/
