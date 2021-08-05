#include <iostream>
using namespace std;

int main(){

    float sueldo;
    int cantidadMenos1520; // empleados que ganan menos de $1520.
    int cantidadMenos2780; // empleados que ganan $1520 o más pero menos de $2780.
    int cantidadMenos5999; // empleados que ganan $2780 o más pero menos de $5999.
    int cantidadMas5999; // empleados que ganan $5999 o más.

    sueldo = 0;
    cantidadMenos1520 = 0;
    cantidadMenos2780 = 0;
    cantidadMenos5999 = 0;
    cantidadMas5999 = 0;

    cout << "Ingrese el sueldo de un empleado: " << endl;
    cin >> sueldo;

    while(sueldo > 0)
    {
        
        if(sueldo < 1520)
        {
            cantidadMenos1520++;
        }
        else if (sueldo < 2780)
        {
            cantidadMenos2780++;
        }
        else if (sueldo < 5999)
        {
            cantidadMenos5999++;
        }
        else
        {
            cantidadMas5999++;
        }

        cout << "Ingrese el sueldo de un empleado: " << endl;
        cin >> sueldo;
    }

    if(cantidadMenos1520 > 0)
    {
        cout << cantidadMenos1520 << " empleados ganan menos de $1520." << endl;
    }
    else
    {
        cout << "No hay empleados que ganen menos de $1520." << endl;
    }

    if(cantidadMenos2780 > 0)
    {
        cout << cantidadMenos2780 << " empleados ganan menos de $2780." << endl;
    }
    else
    {
        cout << "No hay empleados que ganen menos de $2780." << endl;
    }

    if(cantidadMenos5999 > 0)
    {
        cout << cantidadMenos5999 << " empleados ganan menos de $5990." << endl;
    }
    else
    {
        cout << "No hay empleados que ganen menos de $5990." << endl;
    }

    if(cantidadMas5999 > 0)
    {
        cout << cantidadMas5999 << " empleados ganan mas de $5999." << endl;
    } 
    else
    {
        cout << "No hay empleados que ganen mas de $5999." << endl;
    }



 system("pause");
 return 0;
}