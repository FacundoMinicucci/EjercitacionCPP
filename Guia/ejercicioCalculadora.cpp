// Pedir al usuario dos valores y que eliga la operación a realizar (suma, resta, producto o division).

#include <iostream>
using namespace std;


int suma(int num1, int num2)
{  
    return num1 + num2;
}

int resta(int num1, int num2)
{
    return num1 - num2;
}

int producto(int num1, int num2)
{   
    return num1 * num2;
}

float division(float num1, float num2)
{    
    return num1 / num2;
}

int main() {

    int num1;
    int num2;
    char operacion;
    float resultado;
    string operacionElegida;
    int sigue;

    num1 = 0;
    num2 = 0;
    operacion = 0;
    resultado = 0;
    operacionElegida = "";
    sigue = 0;

    cout << "Ingrese la opcion que desea realizar (1. Calculadora o 0. Salir): " << endl;
    cin >> sigue;

    while(sigue)
    {
        cout << "Ingrese el primer numero: " << endl;
        cin >> num1;

        cout << "Ingrese la operacion que desea realizar (+, -, * o /): " << endl;
        cin >> operacion;

        cout << "Ingrese el segundo numero: " << endl;
        cin >> num2;        

        switch(operacion)
        {
        case '+':
            {
                resultado = suma(num1,num2);
                operacionElegida = "suma";  
                cout << "La operacion elegida fue " << operacionElegida << " y el resultado es: " << resultado << endl;              
                break;
            }
        case '-':
            {
                resultado = resta(num1,num2);
                operacionElegida = "resta";
                cout << "La operacion elegida fue " << operacionElegida << " y el resultado es: " << resultado << endl;
                break;
            }
        case '*':
            {
                resultado = producto(num1,num2);
                operacionElegida = "producto";
                cout << "La operacion elegida fue " << operacionElegida << " y el resultado es: " << resultado << endl;
                break;
            }
        case '/':
            {
                if(num2 == 0)
                {
                    cout << "Math ERROR" << endl;
                    break;                    
                }
                resultado = division(num1,num2);
                operacionElegida = "division";
                cout << "La operacion elegida fue " << operacionElegida << " y el resultado es: " << resultado << endl;
                break;
            }
        default:
            {
                cout << "La opcion ingresada es incorrecta." << endl;
                break;
            }
        }  

        cout << "Desea realizar otra operacion? (1. Si o 0. No) " << endl;
        cin >> sigue;       
                
    } 
    
    if (sigue == 0)
    {
        cout << "Gracias por usar la calculadora." << endl;
    }

 system("pause");
 return 0;
}