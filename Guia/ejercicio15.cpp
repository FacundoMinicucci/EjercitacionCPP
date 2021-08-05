#include <iostream>
using namespace std;

int main() {

    // Entrada
    int tipoInfraccion;
    string motivoInfraccion;    
    char gravedadInfraccion;

    tipoInfraccion = 0;
    motivoInfraccion = "";    
    gravedadInfraccion = 0;

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

    cout << "Ingrese el valor de multa correspondiente a la gravedad L: " << endl;
    cin >> valorMultaL;

    cout << "Ingrese el valor de multa correspondiente a la gravedad M: " << endl;
    cin >> valorMultaM;

    cout << "Ingrese el valor de multa correspondiente a la gravedad G: " << endl;
    cin >> valorMultaG;

    for(int i = 0; i < 5; i++)
    {
        cout << "Ingrese el tipo de infraccion (1, 2, 3 o 4): " << endl;
        cin >> tipoInfraccion;
        
        cout << "Ingrese el motivo de la infraccion: " << endl;
        cin.ignore();
        getline (cin, motivoInfraccion);

        cout << "Ingrese la gravedad de la multa (L, M o G): " << endl;
        cin >> gravedadInfraccion;       

        if(gravedadInfraccion == 'L')
        {
            valorTotalMulta = valorTotalMulta + valorMultaL;    
        }
        else if (gravedadInfraccion == 'M')
        {
            valorTotalMulta = valorTotalMulta + valorMultaM;
        }
        else if(gravedadInfraccion == 'G')
        {
            valorTotalMulta = valorTotalMulta + valorMultaG;
        }       

        if (tipoInfraccion == 3 || tipoInfraccion == 4 && (gravedadInfraccion == 'G'))
        {
            contadorMultas3y4 = contadorMultas3y4 + 1;
        }

        cout << "Se ingreso una infraccion de tipo " << tipoInfraccion << " y de gravedad " << gravedadInfraccion << endl;
        cout << "El motivo de la misma fue: " << motivoInfraccion << endl;        

    } 

    cout << "El valor total de la multa a pagar es de $" << valorTotalMulta << endl;

    if(contadorMultas3y4 > 3)
    {
        cout << "Clausurar fabrica." << endl;
    }



 system("pause");
 return 0;
}