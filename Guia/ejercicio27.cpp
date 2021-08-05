#include <iostream>
using namespace std;

int main() {

    int cantidadDeEquipos = 0;
    int numeroDeEquipo = 0;
    char resultado = 0;
    int puntajeTotalEquipo = 0;    
    int cantidadDePartidos = 0;
    int puntajeMax = -1;
    int equipoCampeon = 0;
  
    cout << "Ingrese la cantidad de equipos: " << endl;
    cin >> cantidadDeEquipos;

    cantidadDePartidos = cantidadDeEquipos - 1;

    for(int i = 0; i < cantidadDeEquipos; i++)
    {
        puntajeTotalEquipo = 0;
        numeroDeEquipo = i + 1;
        cout << "Ingrese los resultados del equipo " << numeroDeEquipo << ": " << endl;     

        for(int j = 0; j < cantidadDePartidos; j++)
        {
            cout << "Ingrese el resultado (P, G, E): " << endl;
            cin >> resultado;

            switch(tolower(resultado))
            {
                case 'g':
                    puntajeTotalEquipo += 3;
                    break;
                case 'e':
                    puntajeTotalEquipo += 1;
                    break;
                default:
                    break;  

            }            
        }

        cout << "El equipo " << numeroDeEquipo << " obtuvo " << puntajeTotalEquipo << " puntos en total." << endl;
        
        if(puntajeTotalEquipo > puntajeMax)
        {
            puntajeMax = puntajeTotalEquipo;
            equipoCampeon = numeroDeEquipo;
        }

    }

    cout << "El campeon del torneo es el equipo " << equipoCampeon << " con " << puntajeMax << " puntos."<< endl;

 system("pause");
 return 0;

}