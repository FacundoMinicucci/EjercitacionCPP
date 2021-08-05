#include <iostream>
using namespace std;

struct Empleado {
    int legajo;
    int presentismo[5];
    int sumaPresentismo;
};

void ordenarVectorXPresentismo(Empleado empleados[], int cantidadEmpleados){

    int i = 0;
    Empleado aux;
    bool ordenado = false;

    while(i < cantidadEmpleados && !ordenado)
    {
        ordenado = true;
        
        for (int j = 0; j < cantidadEmpleados-j-1; j++)
        {
            if(empleados[j].sumaPresentismo > empleados[j+1].sumaPresentismo)
            {
                aux = empleados[j];
                empleados[j] = empleados[j+1];
                empleados[j+1] = aux;
                ordenado = false;
            }
        }        
        i++;
    }
    return;
}

void imprimir3MejoresPresentismos(Empleado empleados[], int cantidadEmpleados, int cantidadMejorPresentismo){

    cout << "Los 3 empleados con mejor presentismo son los que corresponden a los legajos: " << endl;
    for (int i = 0; i < cantidadMejorPresentismo; i++)
    {
        cout << empleados[cantidadEmpleados-i-1].legajo << endl;
        cout << "Con un presentismo de " << empleados[cantidadEmpleados-i-1].sumaPresentismo << endl;
    }
    return;    
}

void obtenerDiaMayorAusentismo(Empleado empleados[], int cantidadEmpleados, int diasDelMes, int &diaMayorAusentismo, int &numDiaMayorAusentismo){

    for (int i = 0; i < diasDelMes; i++)
    {
        int sumaPresentismo = 0;
        for (int j = 0; j < cantidadEmpleados; j++)
        {
            sumaPresentismo += empleados[j].presentismo[i];
        }

        if(sumaPresentismo < diaMayorAusentismo || i == 0)
        {
            diaMayorAusentismo = sumaPresentismo;
            numDiaMayorAusentismo = i;
        }              
    }
    return;    
}

int main () {
    
    Empleado empleado;
    int cantidadEmpleados = 0;
    int cantidadPresentismos = 0;
    int diasDelMes = 5;
    int cantidadMejorPresentismo = 3;
    int sumaPresentismo = 0;
    int diaMayorAusentismo = 0;
    int numDiaMayorAusentismo = 0;  

    cout << "Ingrese la cantidad de empleados a cargar: ";
    cin >> cantidadEmpleados;

    Empleado empleados[cantidadEmpleados];

    // cargarEmpleados(empleados, cantidadEmpleados, diasDelMes)
    for (int i = 0; i < cantidadEmpleados; i++)
    {
        cout << "Ingrese el legajo del empleado: ";
        cin >> empleado.legajo;

        cantidadPresentismos = 0;
        while (cantidadPresentismos < diasDelMes)
        {
            cout << "Ingrese el presentismo del dia " << cantidadPresentismos+1 << ": ";
            cin >> empleado.presentismo[cantidadPresentismos];
            cantidadPresentismos++;           
        }
        empleados[i] = empleado;        
    }

    // sumo presentismos.
    for (int i = 0; i < cantidadEmpleados; i++)
    {
        sumaPresentismo = 0;
        for (int j = 0; j < diasDelMes; j++)
        {
            sumaPresentismo += empleados[i].presentismo[j];
        }
        empleados[i].sumaPresentismo = sumaPresentismo;
    }

    ordenarVectorXPresentismo(empleados, cantidadEmpleados);
    
    // imprimir 3 mejores presentismos
    imprimir3MejoresPresentismos(empleados, cantidadEmpleados, cantidadMejorPresentismo);
    
    // obtener dia mayor ausentismo
    obtenerDiaMayorAusentismo(empleados, cantidadEmpleados, diasDelMes, diaMayorAusentismo, numDiaMayorAusentismo);    

    cout << "El dia de mayor ausentismo fue el dia " << numDiaMayorAusentismo << " con un presentismo de " << diaMayorAusentismo << endl;

    system("pause");
    return 0;
}