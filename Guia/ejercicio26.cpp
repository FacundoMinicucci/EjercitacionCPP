#include <iostream>
using namespace std;

int main() {

    int cantidadContenedores;
    int identificacionDelPuerto;
    float pesoDelContenedor;
    int identificacionDelContenedor;
    float pesoTotalBuque;
    int contenedorMayorPeso;
    int identificacionContenedorMayorPeso;
    int cantidadContenedoresPuerto1;
    int cantidadContenedoresPuerto2;
    int cantidadContenedoresPuerto3;

    cantidadContenedores = 5;
    identificacionDelPuerto = 0;
    pesoDelContenedor = 0;
    identificacionDelContenedor = 0;
    pesoTotalBuque = 0;
    contenedorMayorPeso = 0;
    identificacionContenedorMayorPeso = 0;
    cantidadContenedoresPuerto1 = 0;
    cantidadContenedoresPuerto2 = 0;
    cantidadContenedoresPuerto3 = 0;

    for(int i = 0; i < cantidadContenedores; i++)
    {
        cout << "Ingrese la identificacion del contenedor: " << endl;
        cin >> identificacionDelContenedor;

        cout << "Ingrese el peso del contenedor (en kg): " << endl;
        cin >> pesoDelContenedor;

        cout << "Ingrese el puerto de arribo del contendor: " << endl;
        cin >> identificacionDelPuerto; 

        pesoTotalBuque = pesoTotalBuque + pesoDelContenedor;

        if(contenedorMayorPeso < pesoDelContenedor)
        {
            contenedorMayorPeso = pesoDelContenedor;
            identificacionContenedorMayorPeso = identificacionDelContenedor;

        }

    
        if(identificacionDelPuerto == 1)
        {
            cantidadContenedoresPuerto1++;
        }
        else if(identificacionDelPuerto == 2)
        {
            cantidadContenedoresPuerto2++;
        }
        else if(identificacionDelPuerto == 3)
        {
        cantidadContenedoresPuerto3++;
        }

    }

    cout << "El peso total que el buque debe trasladar es : " << pesoTotalBuque << " kg." << endl;

    cout << "El contenedor de mayor peso es el contenedor identificado con: " << identificacionContenedorMayorPeso << endl;

    cout << "Al puerto 1 se deben trasladar " << cantidadContenedoresPuerto1 << " contenedores." << endl;

    cout << "Al puerto 2 se deben trasladar " << cantidadContenedoresPuerto2 << " contenedores." << endl;

    cout << "Al puerto 3 se deben trasladar " << cantidadContenedoresPuerto3 << " contenedores." << endl;
    

 system ("pause");
 return 0;
}