#include <iostream>
using namespace std;

int main () {

    int dia;
    int mes; 
    int anio;

    dia = 0;
    mes = 0;
    anio = 0;

    cout << "Ingrese el dia: " << endl;
    cin >> dia;

    cout << "Ingrese el mes" << endl;
    cin >> mes;

    cout << "Ingrese el anio" << endl;
    cin >> anio;

    cout << "Usted ingreso la fecha: " << anio << mes << dia << endl;

    system("pause");
    return 0;
}