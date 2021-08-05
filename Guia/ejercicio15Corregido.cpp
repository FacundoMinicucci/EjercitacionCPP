#include <iostream>
using namespace std;

int main() {

    // Entrada
    int tipoInfraccion;
    string motivoInfraccion;    
    char gravedadInfraccion;
    int valorMulta;

    tipoInfraccion = 0;
    motivoInfraccion = "";    
    gravedadInfraccion = 0;
    valorMulta = 0;

    // Salida
    float valorTotalMulta;

    valorTotalMulta = 0;

    // Auxiliares
    float valorMultaL;
    float valorMultaM;
    float valorMultaG;
    int contadorMultas3y4;

    contadorMultas3y4 = 0;
    valorMultaL = 0;
    valorMultaM = 0;
    valorMultaG = 0;
    

    for(int i = 0; i < 5; i++)
    {
        cout << "Ingrese el tipo de infraccion (1, 2, 3 o 4): " << endl;
        cin >> tipoInfraccion;
        
        cout << "Ingrese el motivo de la infraccion: " << endl;
        cin.ignore();
        getline (cin, motivoInfraccion);

        cout << "Ingrese la gravedad de la multa (L, M o G): " << endl;
        cin >> gravedadInfraccion;

        cout << "Ingrese el valor de la multa: " << endl;
        cin >> valorMulta;       

        if(gravedadInfraccion == 'L')
        {
            valorMultaL = valorMultaL + valorMulta;    
        }
        else if (gravedadInfraccion == 'M')
        {
            valorMultaM = valorMultaM + valorMulta;
        }
        else if(gravedadInfraccion == 'G')
        {
            valorMultaM = valorMultaM + valorMulta;
        }       

        if (tipoInfraccion == 3 || tipoInfraccion == 4 && (gravedadInfraccion == 'G'))
        {
            contadorMultas3y4 = contadorMultas3y4 + 1;
        }

        
    } 

    cout << "El valor total de las multas L es de $" << valorMultaL << endl;
    cout << "El valor total de las multas M es de $" << valorMultaM << endl;
    cout << "El valor total de las multas G es de $" << valorMultaG << endl;

    if(contadorMultas3y4 > 3)
    {
        cout << "Clausurar fabrica." << endl;
    }


 system("pause");
 return 0;
}