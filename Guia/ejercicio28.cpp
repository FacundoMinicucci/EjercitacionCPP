#include <iostream>
using namespace std;

int main() {

    char caracter;
    int contadorA;
    int contadorE;
    int contadorI;
    int contadorO;
    int contadorU;
    int cantidadPalabras;
    int letrasPalabra;
    int letrasPalabraMasLarga;

    caracter = 0;
    contadorA = 0;
    contadorE = 0;
    contadorI = 0;
    contadorO = 0;
    contadorU = 0;
    cantidadPalabras = 0;
    letrasPalabra = 0;
    letrasPalabraMasLarga = 0; 
    
    
    while(caracter != '.')
    {   
        cout << "Ingrese un caracter: " << endl;
        cin.get(caracter);
        cin.ignore();           

        while(caracter != ' ' && caracter != '.')
        {
            letrasPalabra++;
            
            switch(caracter)
            {
                case 'a':
                    contadorA++;
                    break;                    
                case 'e': 
                    contadorE++;
                    break;
                case 'i':
                    contadorI++;
                    break;
                case 'o':
                    contadorO++;
                    break;
                case 'u':
                    contadorU++;
                    break;
                default:
                    break;                    
            }

            if(letrasPalabra > letrasPalabraMasLarga)
            {
             letrasPalabraMasLarga = letrasPalabra;
            }            
            
            cout << "Ingrese un caracter: " << endl;
            cin.get(caracter);
            cin.ignore();   

        }    
             
        cantidadPalabras++;       

        letrasPalabra = 0;        

    }
    
    cout << "La vocal A aparecio " << contadorA << " veces." << endl;
    cout << "La vocal E aparecio " << contadorE << " veces." << endl;
    cout << "La vocal I aparecio " << contadorI << " veces." << endl;
    cout << "La vocal O aparecio " << contadorO << " veces." << endl;
    cout << "La vocal U aparecio " << contadorU << " veces." << endl;    
    
    if(letrasPalabraMasLarga == 0)
    {
        cout << "No se ingresaron palabras.";
    }
    else
    {
        cout << "La oracion contiene " << cantidadPalabras << " palabras." << endl;
    }
            
    cout << "La palabra mas larga contiene " << letrasPalabraMasLarga << " letras." << endl;


 system("pause");
 return 0;
}