#include <iostream>
using namespace std;
#define CANT_MAX_FIL 20
#define CANT_MAX_COL 25

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void ordenarCrecienteColumnas(int matriz[CANT_MAX_FIL][CANT_MAX_COL], int filas, int columnas){
    
    cout << "Matriz ordenada cada columna en forma creciente sobre si misma: " << endl; 
    int k = 0;
    int aux = 0;
    bool ordenado = false;

    while(k < columnas && !ordenado)
    {
        ordenado = true;
        
        for (int j = 0; j < columnas; j++)
        {            

            for (int i = 0; i < filas - k - 1; i++)
            {                            
                if(matriz[i][j] > matriz[i+1][j])
                {
                    aux = matriz[i][j];
                    matriz[i][j] = matriz[i+1][j];
                    matriz[i+1][j] = aux;
                    ordenado = false;
                }

            }
        }
        k++;        
    }
}

void ordenarCrecienteFilas(int matriz[CANT_MAX_FIL][CANT_MAX_COL], int filas, int columnas){
    
    cout << "Matriz ordenada cada fila en forma creciente sobre si misma: " << endl;

    int k = 0;
    int aux = 0;
    bool ordenado = false;

    while(k < filas && !ordenado)
    {
        ordenado = true;
        /*  {3,1,2,5,4},
            {7,13,15,12,11},
            {6,9,7,10,8}*/ 
        for (int i = 1; i < filas; i++)
        {
            for (int j = 1; j < columnas - k - 1; j++)
            {                          
                if(matriz[i][j] > matriz[i][j+1])
                {                   
                    aux = matriz[i][j];
                    matriz[i][j] = matriz[i][j+1];
                    matriz[i][j+1] = aux;
                    ordenado = false;
                }
            }
        }
        k++;
        
    }

}

void imprimirMatriz(int matriz[CANT_MAX_FIL][CANT_MAX_COL], int filas, int columnas){
    
    for (int j = 0; j < columnas; j++)
    {
        for (int i = 0; i < filas; i++)
        {
            cout << matriz[i][j] << " "; 
        }
        cout << endl;
    }
}

void imprimirMatrizPos1_1(int matriz[CANT_MAX_FIL][CANT_MAX_COL], int filas, int columnas){

    for (int i = 1; i < filas; i++)
    {
        for (int j = 1; j < columnas; j++)
        {
            cout << matriz[i][j] << " "; 
        }
        cout << endl;
    } 
}

int main () {
 
    int filas = 0;
    int columnas = 0;
    int matriz[CANT_MAX_FIL][CANT_MAX_COL] = {
        {3,1,2,5,4},
        {7,13,15,12,11},
        {6,9,7,10,8}
    };

    leer("Ingrese la cantidad de filas: ", filas);

    leer("Ingrese la cantidad de columnas: ", columnas);

    // a) Ordenar (creciente) cada columna de la matriz sobre si misma
    ordenarCrecienteColumnas(matriz, filas, columnas); 
    
    imprimirMatriz(matriz, filas, columnas),   
    
    // b) Ordenar (creciente) cada fila de la matriz sobre si misma
    ordenarCrecienteFilas(matriz, filas, columnas);
    
    imprimirMatrizPos1_1(matriz, filas, columnas);    

    system("pause");
    return 0;
}