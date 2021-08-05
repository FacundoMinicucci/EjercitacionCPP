#include <iostream>
using namespace std;

int main () {

    int fecha;
    int restoFecha;
    int dia;
    int mes;
    int anio;

    cout << "Ingrese una fecha valida (en formato AAAAMMDD): " << endl;
    cin >> fecha;

    restoFecha = fecha % 10000;
    dia = fecha % 100;
    mes = (restoFecha - dia) / 100;
    anio = (fecha - restoFecha) / 10000;

    cout << "La fecha ingresada representa el dia " << dia << " del mes " << mes << " del anio " << anio << endl;



    system("pause");
    return 0;
}