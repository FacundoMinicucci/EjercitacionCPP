#include <iostream>
using namespace std;

int main() {

    int valorIngresado = 0;
    int sumaValoresSublote = 0;
    int cantidadValoresSublote = 0;
    float promedioSublote = 0;
    int totalSublotes = 0;
    int valorMaximoLote = 0;
    int numeroDeSublote = 0;
    int posicionValorMaxEnSublote = 0;
    int valorMinimoSublote = 0;
    int posicionEnSublote = 0;
    int subloteDelValorMax = 0;
    int valor = 0;

    cout << "Ingrese un valor (-1 para terminar): " << endl;
    cin >> valorIngresado;

    while(valorIngresado >= 0)
    {
        totalSublotes++;    
            
        if(valorIngresado > 0)
        {
            promedioSublote = 0;
            sumaValoresSublote = 0;
            cantidadValoresSublote = 0;
            posicionEnSublote = 0;            

            while(valorIngresado > 0)
            {
                        
            cantidadValoresSublote++;

            sumaValoresSublote = sumaValoresSublote + valorIngresado;

            posicionEnSublote++;

            if(totalSublotes == 1 && cantidadValoresSublote == 1)
            {              
                valorMaximoLote = valorIngresado;
                posicionValorMaxEnSublote = posicionEnSublote;
                subloteDelValorMax = totalSublotes;
            }
            else if (valorIngresado > valorMaximoLote)
            {                
                valorMaximoLote = valorIngresado;
                posicionValorMaxEnSublote = posicionEnSublote;
                subloteDelValorMax = totalSublotes;
            }
            
            if (posicionEnSublote == 1)
            {
                valorMinimoSublote = valorIngresado;
            }
            else if(valorIngresado < valorMinimoSublote)
            {
                valorMinimoSublote = valorIngresado;
            }

            cout << "Ingrese un valor (0 para terminar el sublote): ";
            cin >> valorIngresado;            
            
        }

        promedioSublote = sumaValoresSublote / cantidadValoresSublote;            
        cout << "El promedio del sublote " << totalSublotes << " es: " << promedioSublote << endl; 

        cout << "El valor minimo del sublote " << totalSublotes << " es: " << valorMinimoSublote << endl;       
        
        }       
             
        cout << "Ingrese un valor (-1 para terminar): " << endl;
        cin >> valorIngresado;

    } 
    
    if(totalSublotes > 0 && cantidadValoresSublote != 0)
    {
        cout << "Se procesaron " << totalSublotes << " sublotes." << endl;

        cout << "El valor maximo del conjunto es el " << valorMaximoLote << ", ingresado en el sublote " << subloteDelValorMax << ", en la posicion " << posicionValorMaxEnSublote << endl;
    }    
    else if (totalSublotes == 0)
    {
        cout << "El lote esta vacio." << endl;
    }
    else if(totalSublotes > 0 && cantidadValoresSublote == 0)
    {
        cout << "Se evaluaron " << totalSublotes << " sublotes y todos estan vacios." << endl;
    }

 system("pause");
 return 0;
}