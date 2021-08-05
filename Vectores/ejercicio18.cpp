#include <iostream>
using namespace std;
#define CANT_MAX_FIL_COL 24

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
    return;
}

void cargarMatriz(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){

    for(int i = 0; i < filasColumnas; i++)
    {   
        cout << "Ingrese los valores de la fila " << i + 1 << ":" << endl;
        for (int j = 0; j < filasColumnas; j++)
        {            
            cin >> matriz[i][j];
        }
              
    }  
    return;  
}

void sumarValoresDeDiagonales(int matriz[][CANT_MAX_FIL_COL], int filasColumnas, int &sumaDiagonalPrincipal, int &sumaDiagonalSecundaria){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j)
            {
                sumaDiagonalPrincipal += matriz[i][j];
            }

            if(i + j == filasColumnas - 1)
            {
                sumaDiagonalSecundaria += matriz[i][j];
            }
        }        
    }
    return;
}

void imprimirDiagonalPrincipal(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j)
            {
                cout << matriz[i][j] << " ";
            }            
        }                   
    }
    return;        
}

void imprimirDiagonalSecundaria(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i + j == filasColumnas - 1)
            {
                cout << matriz[i][j] << " ";
            }
        }                   
    }       
}

void sumarCuadrantes(int matriz[][CANT_MAX_FIL_COL], int filasColumnas, int &sumatoriaCuadrante1, int &sumatoriaCuadrante2, int &sumatoriaCuadrante3, int &sumatoriaCuadrante4){
    for(int i = 0; i < filasColumnas; i++)
    {
        for(int j = 0; j < filasColumnas; j++)
        {            
            if(i < filasColumnas/2 && j < filasColumnas/2)
            {
                sumatoriaCuadrante1 += matriz[i][j];
            }            
            else if(i < filasColumnas/2 && j >= filasColumnas/2)
            {
                sumatoriaCuadrante2 += matriz[i][j];
            }
            else if(i >= filasColumnas/2 && j < filasColumnas/2)
            {
                sumatoriaCuadrante3 += matriz[i][j];
            }
            else
            {
                sumatoriaCuadrante4 += matriz[i][j];
            }
        }
    }
    return;
}

void imprimirCuadrante1(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    // int mitad = (filasColumnas / 2) + 1;

    for (int i = 0; i < filasColumnas; i++)
    {        
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i < filasColumnas/2 && j < filasColumnas/2)
            {
                cout << matriz[i][j] << " ";
            }
        }             
    }
    return;        
}

void imprimirCuadrante2(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i < filasColumnas/2 && j >= filasColumnas/2)
            {
                cout << matriz[i][j] << " ";
            }
        }             
    }
    return;
}

void imprimirCuadrante3(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i >= filasColumnas/2 && j < filasColumnas/2)
            {
                cout << matriz[i][j] << " ";
            }
        }             
    }
    return;        
}

void imprimirCuadrante4(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i >= filasColumnas/2 && j >= filasColumnas/2)
            {
                cout << matriz[i][j] << " ";
            }
        }             
    }
    return;        
}

void sumarTriangularSuperior(int matriz[][CANT_MAX_FIL_COL], int filasColumnas, int &sumatoriaTriangularSuperior){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j || i <= j)
            {
                sumatoriaTriangularSuperior += matriz[i][j];
            }
        }        
    }
    return;
}

void sumarTriangularInferior(int matriz[][CANT_MAX_FIL_COL], int filasColumnas, int &sumatoriaTriangularInferior){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j || i >= j)
            {
                sumatoriaTriangularInferior += matriz[i][j];
            }
        }        
    }
    return;
}

void imprimirTriangularSuperior(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j || i <= j)
            {
                cout << matriz[i][j] << " ";
            }            
        }            
    }
    return;
}

void imprimirTriangularInferior(int matriz[][CANT_MAX_FIL_COL], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++)
    {
        for (int j = 0; j < filasColumnas; j++)
        {
            if(i == j || i >= j)
            {
                cout << matriz[i][j] << " ";
            }
        }              
    }
    return;
}

int main () {
 
    int numeroFilasColumnas = 0;
    int sumaValoresDiagonalPrincipal = 0;
    int sumaValoresDiagonalSecundaria = 0;  
    int sumatoriaCuadrante1 = 0;
    int sumatoriaCuadrante2 = 0;
    int sumatoriaCuadrante3 = 0;
    int sumatoriaCuadrante4 = 0;
    int sumatoriaTriangularSuperior = 0;
    int sumatoriaTriangularInferior = 0; 
    
    leer("Ingrese el numero de filas y columnas de la matriz cuadrada: ", numeroFilasColumnas);
  
    int matrizCuadrada[numeroFilasColumnas][CANT_MAX_FIL_COL];

    cargarMatriz(matrizCuadrada, numeroFilasColumnas);

    // a) Imprimir valores de la diagonal principal o secundaria.
    sumarValoresDeDiagonales(matrizCuadrada, numeroFilasColumnas, sumaValoresDiagonalPrincipal, sumaValoresDiagonalSecundaria);

    if(sumaValoresDiagonalPrincipal > sumaValoresDiagonalSecundaria)
    {
        cout << "Los elementos de la diagonal principal son: ";
        imprimirDiagonalPrincipal(matrizCuadrada, numeroFilasColumnas);
    }
    else if(sumaValoresDiagonalSecundaria > sumaValoresDiagonalPrincipal)
    {
        cout << "Los elementos de la diagonal secundaria son: ";
        imprimirDiagonalSecundaria(matrizCuadrada, numeroFilasColumnas);
    }    

    // b) Imprimir elementos del cuadrante con la mayor sumatoria.
    sumarCuadrantes(matrizCuadrada, numeroFilasColumnas, sumatoriaCuadrante1, sumatoriaCuadrante2, sumatoriaCuadrante3, sumatoriaCuadrante4);

    cout << endl;
    
    if(sumatoriaCuadrante1 > sumatoriaCuadrante2 && sumatoriaCuadrante1 > sumatoriaCuadrante3 && sumatoriaCuadrante1 > sumatoriaCuadrante4)
    {
        cout << "El cuadrante con la mayor sumatoria es el cuadrante 1 y sus elementos son: ";
        imprimirCuadrante1(matrizCuadrada, numeroFilasColumnas);
    }
    else if(sumatoriaCuadrante2 > sumatoriaCuadrante1 && sumatoriaCuadrante2 > sumatoriaCuadrante3 && sumatoriaCuadrante2 > sumatoriaCuadrante4)
    {
        cout << "El cuadrante con la mayor sumatoria es el cuadrante 2 y sus elementos son: ";
        imprimirCuadrante2(matrizCuadrada, numeroFilasColumnas);
    }
    else if(sumatoriaCuadrante3 > sumatoriaCuadrante1 && sumatoriaCuadrante3 > sumatoriaCuadrante2 && sumatoriaCuadrante3 > sumatoriaCuadrante4)
    {
        cout << "El cuadrante con la mayor sumatoria es el cuadrante 3 y sus elementos son: ";
        imprimirCuadrante3(matrizCuadrada, numeroFilasColumnas);
    }
    else
    {
        cout << "El cuadrante con la mayor sumatoria es el cuadrante 4 y sus elementos son: ";
        imprimirCuadrante4(matrizCuadrada, numeroFilasColumnas);
    }    

    // c) Imprimir triangular superior o inferior segun sumatoria.
    sumarTriangularSuperior(matrizCuadrada, numeroFilasColumnas, sumatoriaTriangularSuperior);
    
    sumarTriangularInferior(matrizCuadrada, numeroFilasColumnas, sumatoriaTriangularInferior);

    cout << endl;

    if(sumatoriaTriangularSuperior > sumatoriaTriangularInferior)
    {
        cout << "Los elementos de la triangular superior son: ";
        imprimirTriangularSuperior(matrizCuadrada, numeroFilasColumnas);
    }
    else if(sumatoriaTriangularInferior > sumatoriaTriangularSuperior)
    {   
        cout << "Los elementos de la triangular inferior son: ";
        imprimirTriangularInferior(matrizCuadrada, numeroFilasColumnas);
    }
    return 0;
}