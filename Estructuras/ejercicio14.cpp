#include <iostream>
using namespace std;
#define MAX_ANIOS 10
#define MAX_DISCOS 1000
#define CANT_BANDAS 101

struct Venta {
    string idDisco;
    int cantidad;
};

struct Disco {
    string idDisco;
    string nombre;
    int idBanda;
    string nombreBanda;
};

struct VentasXBanda {
    string nombre;
    int ventas;
};

int buscarBin(Disco discos[], int cantidad, string idDisco){
    int inicio = 0;
    int fin = cantidad -1;
    while (fin >= inicio) 
    {
        int mitad = inicio + (fin - inicio) / 2;
        
        if (discos[mitad].idDisco == idDisco)
        {
            return mitad ;
        }        
        else if (discos[mitad].idDisco > idDisco) 
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

void ordenarXNombre(VentasXBanda vtasBandas[], int cant){
   
    int i = 0;    
    VentasXBanda aux;
    bool ordenado = false;

    while (i < cant && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cant-i-1; j++) 
        {
            if (vtasBandas[j].nombre > vtasBandas[j+1].nombre) 
            {
                aux = vtasBandas[j];
                vtasBandas[j] = vtasBandas[j+1];
                vtasBandas[j+1] = aux;
                ordenado = false; 
            }
        }              
        i++;
    }
    return;
}

void imprimir(VentasXBanda vtasBandas[], int cant){
    cout << "Banda\t\tVentas" << endl;
    for (int i = 0; i < cant; i++)
    {
        cout << vtasBandas[i].nombre << "\t\t" << vtasBandas[i].ventas << endl;
    }
    return;
}

int main () {
    
    Venta ventas[MAX_DISCOS][MAX_ANIOS];    
    Disco discos[MAX_DISCOS];

    VentasXBanda vtasBandas[CANT_BANDAS] = {0};
    

    for (int i = 0; i < MAX_DISCOS; i++)
    {
        for (int j = 0; j < MAX_ANIOS; j++)
        {
            Venta venta = ventas[i][j];
            int pos = buscarBin(discos, MAX_DISCOS, ventas[i][j].idDisco); // La busqueda binaria devuelve la posición.
            Disco disco = discos[pos];
            vtasBandas[disco.idBanda].nombre = disco.nombreBanda; 
            vtasBandas[disco.idBanda].ventas += venta.cantidad;
        }        
    }
        
    ordenarXNombre(vtasBandas, CANT_BANDAS);
    imprimir(vtasBandas, CANT_BANDAS);

    system("pause");
    return 0;
}