#include <iostream>
using namespace std;

struct Venta {
    int legajoPromotor;
    int idTelefono;
    int cantidadVendida;
    int dia;
};

struct Promotor {
    int legajoPromotor;
    string nombrePromotor;
    float porcentajeComision;
};

struct ModeloTelefono {
    int idTelefono;
    string descripcion;
    float precio;
};

int busquedaBinaria(Venta ventasDelMes[], int cantidadVentas, int telBuscado) {
    
    int inicio = 0;
    int fin = cantidadVentas -1;
    while (fin >= inicio) 
    {
        int mitad = inicio + (fin - inicio) / 2;
        
        if (ventasDelMes[mitad].idTelefono == telBuscado)
        {
            return mitad;
        }        
        else if (ventasDelMes[mitad].idTelefono > telBuscado) 
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
    int cantidadVentas = 6;
    int cantidadPromotores = 3;
    int cantidadModelos = 3;    

    Venta ventasDelMes[cantidadVentas] = {      
        {1,1,5,1},
        {1,2,4,2},
        {2,1,5,2},
        {2,2,4,3},
        {3,3,6,3},
        {3,1,4,4}
    };

    Promotor promotores[cantidadPromotores] = {
        {1,"Jorge",0.5},
        {2,"Jose",0.5},
        {3,"Hijoderemilputa",0.5}
    };

    ModeloTelefono modelosTelefonos[cantidadModelos]{
        {1,"Samsung",150.50},
        {2,"Motorola",175.50},
        {3,"Iphone",650.50}
    };    

    // Calcular comision por promotor y mas vendido.
    float comisionVendedor = 0;
    int idTelefonoMasVendido = 0;
    int cantidadMasVendido = 0;
    int idTelefonoMasVendidoTotal = 0;
    int cantidadMasVendidoTotal = 0;
    for (int i = 0; i < cantidadPromotores; i++)
    {
        idTelefonoMasVendido = 0;
        cantidadMasVendido = 0;
        for (int j = 0; j < cantidadVentas; j++)
        {   
            if (promotores[i].legajoPromotor == ventasDelMes[j].legajoPromotor)
            {
                comisionVendedor += (modelosTelefonos[ventasDelMes[j].idTelefono - 1].precio * ventasDelMes[j].cantidadVendida) * promotores[i].porcentajeComision;                
                // b) mas vendido de cada promotor.
                if(ventasDelMes[j].cantidadVendida > cantidadMasVendido)
                {
                    cantidadMasVendido = ventasDelMes[j].cantidadVendida;
                    idTelefonoMasVendido = ventasDelMes[j].idTelefono;                   
                }

                // c) mas vendido entre todos
                if (ventasDelMes[j].cantidadVendida > cantidadMasVendidoTotal)
                {
                    cantidadMasVendidoTotal = ventasDelMes[j].cantidadVendida;
                    idTelefonoMasVendidoTotal = ventasDelMes[j].idTelefono;
                }
                
            }
        } 
        cout << "Promotor " << promotores[i].legajoPromotor << endl;
        cout << "Comision: " << comisionVendedor << endl;
        cout << "Descripcion telefono mas vendido: " << modelosTelefonos[idTelefonoMasVendido - 1].descripcion << endl;       
    }

    cout << "Descripcion del mas vendido: " << modelosTelefonos[idTelefonoMasVendidoTotal - 1].descripcion << endl;
    cout << "Cantidad mas vendido: " << cantidadMasVendidoTotal << endl;   
    

    // d) nombre de los promotores que no vendieron.
    int posTelBuscado = 0;  
    for (int i = 0; i < cantidadModelos; i++)
    {   
        cout << "Modelo: " << i+1 << endl;
        for (int j = 0; j < cantidadVentas; j++)
        {
            if (busquedaBinaria(ventasDelMes, cantidadVentas, modelosTelefonos[i].idTelefono == -1))
            {
                cout << promotores[ventasDelMes[j].legajoPromotor - 1].nombrePromotor << endl;
            }
        }
        
    }
    

    system("pause");
    return 0;
}

/* Una empresa de telefonía celular cuenta con un grupo de promotores que se dedican a vender sus 10
modelos de teléfonos. La empresa cuenta con la información de las ventas realizadas en un mes, organizada en
una tabla donde por cada una de las ventas se informa lo siguiente:
● Legajo del promotor (numérico entero > 0 y < 100)
● Id del teléfono (numérico entero > 0 y <= 10)
● Cantidad Vendida (numérico entero > 0).
● Día del mes en que se realizó la venta (1 a 31)
Se cuenta además con la información correspondiente a los 40 promotores:
● Legajo del promotor (numérico entero > 0 y <= 40)
● Nombre del promotor (string)
● Porcentaje de comisión (numérico real)
Y con la información correspondiente a los 10 modelos de teléfonos:
● Id del teléfono (numérico entero > 0 y <= 10)
● Descripción del teléfono (string)
● Precio (numérico real)
Se pide informar al final del mes:
a) Importe a cobrar por cada promotor en concepto de comisión.
b) Descripción del teléfono más vendido por cada promotor.
c) Descripción del teléfono más vendido entre todos los promotores.
d) Para cada teléfono, el nombre de los promotores que no lo vendieron ese mes */