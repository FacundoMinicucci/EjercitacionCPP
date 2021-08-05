#include <iostream>
using namespace std;

int main() {

    int fecha1;
    int fecha2;

    fecha1 = 0;
    fecha2 = 0;

    cout << "Ingrese la primer fecha (en formato AAAAMMDD): " << endl;
    cin >> fecha1;

    cout << "Ingrese la segunda fecha (en formato AAAAMMDD): " << endl;
    cin >> fecha2;

    // Desmenuzado de fecha 1.
    int restoFecha1;
    int diaFecha1;
    int mesFecha1;
    int anioFecha1;

    restoFecha1 = 0;
    diaFecha1 = 0;
    anioFecha1 = 0;

    restoFecha1 = (fecha1 % 10000);
    diaFecha1 = fecha1 % 100;
    mesFecha1 = (restoFecha1 - diaFecha1) / 100;
    anioFecha1 = (fecha1 - restoFecha1) / 10000;

    // Desmenuzado de fecha 2.
    int restoFecha2;
    int diaFecha2;
    int mesFecha2;
    int anioFecha2;

    restoFecha2 = 0;
    diaFecha2 = 0;
    anioFecha2 = 0;

    restoFecha2 = (fecha2 % 10000);
    diaFecha2 = fecha2 % 100;
    mesFecha2 = (restoFecha2 - diaFecha2) / 100;
    anioFecha2 = (fecha2 - restoFecha2) / 10000;

    if (fecha1 > fecha2) 
    {
        cout << "La fecha mas reciente es la que corresponde al dia " << diaFecha1 << " del mes " << mesFecha1 << " del anio " << anioFecha1 << endl;
    }
    else if (fecha1 == fecha2)
    {
        cout << "Las fechas son iguales." << endl;
    }
    else
    {
        cout << "La fecha mas reciente es la que corresponde al dia " << diaFecha2 << " del mes " << mesFecha2 << " del anio " << anioFecha2 << endl;
    }

    
 system("pause");
 return 0;
}