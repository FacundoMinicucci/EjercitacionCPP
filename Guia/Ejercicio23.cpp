#include <iostream>
using namespace std;

int main() {

    int valorIngresado = 0;
    int valorMaximoNegativo = 0;
    int valorMinimoPositivo = 0;   
    int valorMinimoEnRango = 0;
    int cantidadValores = 0;
    int sumaValores = 0;
    int promedioValores = 0;  
    int cantidadValoresNegativos = 0;
    int cantidadValoresPositivos = 0;
    int cantidadValoresRango = 0;    

    cout << "Ingrese un valor: " << endl;
    cin >> valorIngresado;

    while(valorIngresado != 0)
    {   
        cantidadValores++;
        sumaValores = sumaValores + valorIngresado;

        if(valorIngresado < 0)
        {
            cantidadValoresNegativos++;
            if(cantidadValoresNegativos == 1)
            {
                valorMaximoNegativo = valorIngresado;                
            }
            else if (valorIngresado > valorMaximoNegativo)
            {
                valorMaximoNegativo = valorIngresado;
            }
        } 
    
        if(valorIngresado > 0)
        {
            cantidadValoresPositivos++;
            if(cantidadValores == 1)
            {
                valorMinimoPositivo = valorIngresado;
            }
            else if(valorIngresado < valorMinimoPositivo)
            {
                valorMinimoPositivo = valorIngresado;
            }
        }

        if(valorIngresado >= -17.3 && valorIngresado <= 26.9)
        {
            cantidadValoresRango++;
            if(cantidadValoresRango == 1)
            {
                valorMinimoEnRango = valorIngresado;
            }
            else if(valorIngresado < valorMinimoEnRango)
            {
                valorMinimoEnRango = valorIngresado;
            }
        }
        
        cout << "Ingrese un valor: " << endl;
        cin >> valorIngresado;

    }

    if(cantidadValores > 0)
    {
        if(cantidadValoresNegativos > 0)
        {
            cout << "El valor maximo negativo es: " << valorMaximoNegativo << endl;
        }
        else
        {
            cout << "No se ingresaron numeros negativos." << endl;
        }

        if(cantidadValoresPositivos > 0)
        {
            cout << "El valor minimo positivo es: " << valorMinimoPositivo << endl;
        }
        else
        {
            cout << "No se ingresaron valores positivos." << endl;
        }

        if(cantidadValoresRango > 0)
        {
            cout << "El valor minimo dentro del rango es: " << valorMinimoEnRango << endl;
        }
        else
        {
            cout << "No se ingresaron valores dentro del rango." << endl;
        }

        promedioValores = sumaValores / cantidadValores;
        cout << "El promedio de los valores ingresados es: " << promedioValores << endl;

    }
    else
    {
        cout << "No se ingresaron valores." << endl;
    }

   
   

 system("pause");
 return 0;
}