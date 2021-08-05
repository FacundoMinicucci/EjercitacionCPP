#include <iostream>
using namespace std;

int main() {

    int numEntero;
    int numUnidad;
    int numDecena;
    int numCentena;
    int numUnidadDeMil;
    string numeroRomano;  

    numEntero = 0;
    numUnidad = 0;
    numDecena = 0;
    numCentena = 0;
    numUnidadDeMil = 0; 
    numeroRomano = "";   

    cout << "Ingrese un numero entre 1 y 3999: " << endl;
    cin >> numEntero;

    if(numEntero < 1 || numEntero > 3999)
    {
        cout << "El numero ingresado es incorrecto." << endl;
        exit(-1);       
    }

    // Fraccionar numero.
    numUnidad = numEntero % 10;
    numDecena = ((numEntero - numUnidad) % 100) / 10;    
    numCentena = (numEntero % 1000 - numEntero % 100) / 100;
    numUnidadDeMil = numEntero / 1000;

    switch(numUnidadDeMil)
    {
        case 1:
            numeroRomano = "M";
            break;
        case 2:
            numeroRomano = "MM";
            break;
        case 3:
            numeroRomano = "MMM";
            break;
        default:
            numeroRomano = "";
            break;
    }

    switch(numCentena)
    {
        case 1:
            numeroRomano += "C";
            break;
        case 2:
            numeroRomano += "CC";
            break;
        case 3:
            numeroRomano += "CCC";
            break;
        case 4:
            numeroRomano += "CD";
            break;
        case 5:
            numeroRomano += "D";
            break;
        case 6:
            numeroRomano += "DC";
            break;
        case 7:
            numeroRomano += "DCC";
            break;
        case 8:
            numeroRomano += "DCCC";
            break;
        case 9:
            numeroRomano += "CM";
            break;
        default:
            numeroRomano += "";
            break;
    }

    switch(numDecena)
    {
        case 1:
            numeroRomano += "X";
            break;
        case 2:
            numeroRomano += "XX";
            break;
        case 3:
            numeroRomano += "XXX";
            break;
        case 4:
            numeroRomano += "XL";
            break;
        case 5:
            numeroRomano += "L";
            break;
        case 6:
            numeroRomano += "LX";
            break;
        case 7:
            numeroRomano += "LXX";
            break;
        case 8:
            numeroRomano += "LXXX";
            break;
        case 9:
            numeroRomano += "XC";
            break;
        default:
            numeroRomano += "";
            break;
    }

    switch(numUnidad)
    {
        case 1:
            numeroRomano += "I";
            break;
        case 2:
            numeroRomano += "II";
            break;
        case 3:
            numeroRomano += "III";
            break;
        case 4:
            numeroRomano += "IV";
            break;
        case 5:
            numeroRomano += "V";
            break;
        case 6:
            numeroRomano += "VI";
            break;
        case 7:
            numeroRomano += "VII";
            break;
        case 8:
            numeroRomano += "VIII";
            break;
        case 9:
            numeroRomano += "IX";
            break;
    }

    cout << numeroRomano << endl;



 system("pause");
 return 0;
}