#include <iostream>
using namespace std;
#define CANT_MAX_PRODUCTOS 100

struct ST_Productos {
    int codigoProducto;
    int stock;
};

struct ST_Pedidos {
    int numeroPedido;
    int numeroCliente;
    int codigoProducto;
    int cantidadPedida;
};

void cargarAceptado(ST_Pedidos pedidos[], ST_Productos productos[], ST_Pedidos pedidosAceptados[], int cantidadPedidos, int &cantidadAceptados, int i){
    
    cout << "Pedido aceptado." << endl;
    pedidosAceptados[cantidadAceptados] = pedidos[i];
    productos[pedidos[i].codigoProducto - 1].stock -= pedidos[i].cantidadPedida;
    cantidadAceptados++;
    return;            
}

void cargarRechazado(ST_Pedidos pedidos[], ST_Productos productos[], ST_Pedidos pedidosRechazados[] ,int cantidadPedidos, int &cantidadRechazados, int i){
    
    cout << "La cantidad ingresada es superior al stock, el pedido fue rechazado." << endl;
    pedidosRechazados[cantidadRechazados] = pedidos[i];
    cantidadRechazados++;
    return;  
}

void imprimirAceptados(ST_Pedidos pedidosAceptados[], int cantidadAceptados){
    cout << "Pedidos Satisfechos" << endl;
    cout << "Numero de pedidos\tNumero de cliente\tCodigo de producto\tCantidad pedida" << endl;

    for (int i = 0; i < cantidadAceptados; i++)
    {
       cout << pedidosAceptados[i].numeroPedido << "\t" << pedidosAceptados[i].numeroCliente << "\t" << pedidosAceptados[i].codigoProducto << "\t" << pedidosAceptados[i].cantidadPedida << endl;
    }
    return;
}

void imprimirRechazados(ST_Pedidos pedidosRechazados[], int cantidadRechazados){
    
    cout << "Pedidos Rechazados" << endl;
    cout << "Numero de pedidos\tNumero de cliente\tCodigo de producto\tCantidad pedida" << endl;

    for (int i = 0; i < cantidadRechazados; i++)
    {
       cout << pedidosRechazados[i].numeroPedido << "\t" << pedidosRechazados[i].numeroCliente << "\t" << pedidosRechazados[i].codigoProducto << "\t" << pedidosRechazados[i].cantidadPedida << endl;
    }
    return;
}

int main () {
    
    ST_Productos producto;
    ST_Productos productos[CANT_MAX_PRODUCTOS] = {
        {1,100},
        {2,50},
        {3,150},
        {4,200}
    };
    int cantidadProductos = 0;

    ST_Pedidos pedido;
    int cantidadPedidos = 10;
    ST_Pedidos pedidos[cantidadPedidos] = {
       {200,20,1,98},
       {201,21,1,4},
       {202,22,2,35},
       {203,23,2,10},
       {204,24,2,10},
       {205,25,3,75},
       {206,26,3,100},
       {207,27,4,25},
       {208,28,4,75},
       {209,29,4,130}
    };

    int cantidadAceptados = 0;
    int cantidadRechazados = 0;
    ST_Pedidos pedidosRechazados[cantidadPedidos];
    ST_Pedidos pedidosAceptados[cantidadPedidos];       
   
    for (int i = 0; i < cantidadPedidos; i++)
    {       
        if (pedidos[i].codigoProducto == productos[pedidos[i].codigoProducto - 1].codigoProducto && pedidos[i].cantidadPedida <= productos[pedidos[i].codigoProducto - 1].stock)
        {
            cargarAceptado(pedidos, productos, pedidosAceptados, cantidadPedidos, cantidadAceptados, i);            
        }
        else if (pedidos[i].cantidadPedida > productos[pedidos[i].codigoProducto - 1].stock)
        {
            cargarRechazado(pedidos, productos, pedidosRechazados, cantidadPedidos, cantidadRechazados, i);                     
        }        
    }
         
    imprimirAceptados(pedidosAceptados, cantidadAceptados);
  
    imprimirRechazados(pedidosRechazados, cantidadRechazados);       

    system("pause");
    return 0;
}