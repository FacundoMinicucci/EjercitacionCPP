#include <iostream>
using namespace std;
#define CANT_MAX_ARTICULOS 3
#define CANT_MAX_SUCURSALES 5

struct Articulo {
    int codigoArticulo;
    int codigoSucursal;
    string tipoMovimiento;
    int cantidad;
};

int main () {
    
    int articulos[CANT_MAX_ARTICULOS][CANT_MAX_SUCURSALES] = {
        {0,10,15,20,25},
        {1,15,20,25,30},
        {2,20,25,30,35}               
    };    

    // Cargar movimientos semanales de sucursales.
    Articulo articulo;
    cout << "Ingrese el codigo del sucursal a cargar(-1 para terminar): ";
    cin >> articulo.codigoSucursal;

    while(articulo.codigoSucursal != -1)
    {
        int keySucursal = articulo.codigoSucursal;
        while(articulo.codigoArticulo != -1 && articulo.codigoSucursal == keySucursal)
        {
            cout << "Ingresa el codigo de articulo: ";
            cin >> articulo.codigoArticulo;
            cout << "Ingresa el tipo de movimiento: ";
            cin >> articulo.tipoMovimiento;
            cout << "Ingresa la cantidad: ";
            cin >> articulo.cantidad;

            if(articulo.tipoMovimiento == "E")
            {
                articulos[articulo.codigoArticulo][articulo.codigoSucursal+1] += articulo.cantidad;
            }
            else if(articulo.tipoMovimiento == "S")
            {
                articulos[articulo.codigoArticulo][articulo.codigoSucursal+1] += (articulo.cantidad*(-1));
            }

            cout << "Ingrese el codigo del sucursal a cargar(-1 para terminar): ";
            cin >> articulo.codigoSucursal;
        }
    }
    
    // imprimir informe de stock de cada sucursal.
    cout << "Cod.Articulo\t\tSucursal 0\t\tSucursal 1\t\tSucursal 2\t\tSucursal 3" << endl;
    for (int i = 0; i < CANT_MAX_ARTICULOS; i++)
    {
        for (int j = 0; j < CANT_MAX_SUCURSALES; j++)
        {
            cout << articulos[i][j] << "\t\t\t";
        }
        cout << endl;
    }

    // imprimir lista de stock por codigo de articulo cuya cantidad sea 0 o menor que cero
    int sumaStock = 0;
    cout << "Cod.Articulo\t\tStock" << endl;
    for (int i = 0; i < CANT_MAX_ARTICULOS; i++)
    {
        sumaStock = 0;
        for (int j = 1; j < CANT_MAX_SUCURSALES; j++)
        {
            sumaStock += articulos[i][j];
        }
        
        if(sumaStock <= 0)
        {
            cout << i << "\t\t\t" << sumaStock;
        }
        cout << endl;            
    }
    

    system("pause");
    return 0;
}

/* Una casa de venta de repuestos automotores comercializa 30 artículos diferentes los que vende en
cada una de sus 4 sucursales. Al finalizar cada semana, se recibe la siguiente información de los movimientos
de artículos:
- Código de artículo (Entero entre 0 y 29).
- Código de sucursal (Entero entre 0 y 3).
- Tipo de movimiento (‘E’=>Entrada, ‘S’=>Salida).
- Cantidad (Entero mayor a cero).
El dueño desea un informe que muestre la cantidad en stock de cada artículo en cada sucursal y además una
lista de los artículos indicando el Código cuyo stock total sea igual a cero o menor que cero (se acepta stock
negativo).
Nota: El stock inicial debe venir cargado en una matriz de artículos por sucursales cuyas celdas contienen un
valor entero que indica el stock de cada artículo en cada sucursal. */