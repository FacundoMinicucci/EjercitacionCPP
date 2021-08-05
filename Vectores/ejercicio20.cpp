#include <iostream>
using namespace std;

void leer(string mensaje, int &valor)
{
    cout << mensaje << endl;
    cin >> valor;
    return;
}

int main()
{

    int filas = 0;
    int caras = 0;
    int columnas = 0;
    int num = 0;
    int sumaValoresMatriz = 0;
    float promedioMatriz = 0;
    int mayorValorMatriz = 0;
    int filaMayorValor = 0;
    int caraMayorValor = 0;
    int columnaMayorValor = 0;
    int valorMaximoFila = 0;
    int columnaMaximoFilaAux = 0;
    int contadorAuxMaximoFila = 0;

    leer("Ingrese el numero de caras: ", caras);
    leer("Ingrese el numero de filas: ", filas);
    leer("Ingrese el numero de columnas: ", columnas);

    int cantValoresMatriz = filas * caras * columnas;
    int matrizDimensional[filas][caras][columnas] = {0,0,0};
    int matrizSumaColumnas[filas][columnas] = {0,0,0};
    int matrizMaximosFilas[filas][columnas] = {0,0,0};

    /**
     * a) 3 for anidados para cargar la matriz.
     * b) recorrer la matriz con 3 for, contador para sumar cant de valores y acumulador para sumar
     *    la cantidad de valores, calcular promedio e imprimir.
     * c) 3 for para recorrer matriz y sacar el mayor valor con su posición. También puedo hacerlo 
     *    en cada ingreso de un nuevo valor comparandolo con el anterior.
     * d) Recorro la matriz con los 3 for pero usando J y K para acumular la suma de valores de cada pos
     *    en la nueva matriz.
     * e) idem d pero tomando mayor valor de la fila de cada cara.
     */

    // Cargo matriz
    for (int i = 0; i < caras; i++)
    {
        for (int j = 0; j < filas; j++)
        {
            contadorAuxMaximoFila = 0;
            
            for (int k = 0; k < columnas; k++)
            {
                cout << "Ingrese un valor de la cara " << i + 1 << " posicion [" << j << "][" << k << "]" << endl;
                cin >> num;
                matrizDimensional[i][j][k] = num;
                sumaValoresMatriz += num; // Acumulo cada valor ingresado para sacar promedio de matriz.

                // Determino mayor valor y su pos en la matriz.
                if(num > mayorValorMatriz || (i == 0 && j == 0 && k == 0)) 
                {
                    mayorValorMatriz = num;
                    filaMayorValor = j;
                    caraMayorValor = i; 
                    columnaMayorValor = k;
                }

                if(num > valorMaximoFila || contadorAuxMaximoFila == 0)
                {
                    valorMaximoFila = num;
                }

                // Sumo columnas homólogas en la nueva matriz que guarda estas sumas.
                matrizSumaColumnas[j][k] += matrizDimensional[i][j][k];

            }
            matrizMaximosFilas[j][columnaMaximoFilaAux] = valorMaximoFila;            
        }
        columnaMaximoFilaAux++;
    }

    promedioMatriz = sumaValoresMatriz / cantValoresMatriz; // b) calcular promedio de matriz.
    
    // a) Imprimir matriz por columna, fila, plano
    for (int i = 0; i < caras; i++)
    {
        cout << "Cara :" << i + 1 << endl;

        for (int j = 0; j < filas; j++)
        {
            for (int k = 0; k < columnas; k++)
            {
                cout << matrizDimensional[i][j][k] << "\t";

                if (k == columnas - 1)
                {
                    cout << endl;
                }
            }
        }
    }

    // d) Imprimir matriz con suma de cada columna por su homologa.
    cout << "Suma de columnas de matriz por columnas homologas: " << endl;
    for (int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            cout << matrizSumaColumnas[i][j] << "\t";
            
            if(j == columnas - 1)
            {
                cout << endl;
            }
        }
    }

    // e) Imprimir matriz con el maximo de cada fila.
    cout << "Matriz formada por los mayores de cada fila de la matriz tridimensional: " << endl;
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            cout << matrizMaximosFilas[i][j] << "\t";

            if(j == columnas - 1)
            {
                cout << endl;
            }
        }
    }

    cout << "Promedio de la matriz: " << promedioMatriz << endl; // b) imprimir promedio de matriz
    cout << "El mayor valor de la matriz es " << mayorValorMatriz << " y se encuentra en la cara " << caraMayorValor << ", en la fila " << caraMayorValor << " y columna " << columnaMayorValor << endl; // c) imprimo mayor valor

    system("pause");
    return 0;
}