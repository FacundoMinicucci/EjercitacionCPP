#include <iostream>
using namespace std;

void leer(string mensaje, string &valor){
    cout << mensaje << endl;
    cin >> valor;  
}

void leer(string mensaje, char &valor){
    cout << mensaje << endl;
    cin >> valor;    
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

float calcularPorcentaje(float numerador, float denominador){
    return numerador/denominador * 100;
}

int main(){

    int cantidadDeVuelos = 0;
    int numeroDeVuelo = 0;
    string destino = "";
    int cantidadDeAsientos = 0;
    int numeroDePasaporte = 1;
    int valorPasajeEnDolares = 0;
    int totalRecaudadoVuelo = 0;
    int asientosLibres = 0;
    int asientosOcupados = 0;
    float porcentajeAsientosLibres = 0;
    float porcentajeAsientosOcupados = 0;
    int vuelosCompletosSucesivos = 0;
    bool esVueloCompleto = false;
    bool esVueloCompletoAnterior = false;
    int totalRecaudadoMes = 0;
    int vueloMasRecaudacionMensual = 0;
    int numeroVueloMasRecaudacion = 0;
    
    leer("Ingrese la cantidad de vuelos que va a ingresar: ", cantidadDeVuelos);

    for(int i = 0; i < cantidadDeVuelos; i++)
    {
        leer("Ingrese el numero de vuelo: ", numeroDeVuelo);
        leer("Ingrese el destino: ", destino);
        leer("Ingrese la cantidad de asientos: ", cantidadDeAsientos);        

        while(numeroDePasaporte > 0 && cantidadDeAsientos > asientosOcupados)
        {      
            leer("Ingrese el numero de pasaporte: ", numeroDePasaporte);

            if(numeroDePasaporte >0)
            {
            leer("Ingrese el valor del pasaje (en dolares): ", valorPasajeEnDolares);

            totalRecaudadoVuelo += valorPasajeEnDolares;
            asientosOcupados++; 

            cout << "Numero de pasaporte: " << numeroDePasaporte << "   " << "Importe en u$s: " << valorPasajeEnDolares << endl;
            }              
            
        }

        asientosLibres = cantidadDeAsientos - asientosOcupados;

        cout << "Numero de vuelo: " << numeroDeVuelo << "         " << "Destino: " << destino << endl;
        cout << "Total recaudado del vuelo: " << totalRecaudadoVuelo << endl;


        porcentajeAsientosOcupados = calcularPorcentaje(asientosOcupados, cantidadDeAsientos);

        if(asientosLibres > 0)
        {
            porcentajeAsientosLibres = calcularPorcentaje(asientosLibres, cantidadDeAsientos);
        }
        
        cout << "% de asientos libres del vuelvo: " << porcentajeAsientosLibres << "%" << endl;
        cout << "% de asientos ocupados del vuelvo: " << porcentajeAsientosOcupados << "%" << endl;

        if(asientosOcupados == cantidadDeAsientos)
        {
            esVueloCompleto = true;
        }
        else if(asientosOcupados != cantidadDeAsientos)
        {
            esVueloCompleto = false;
        }

        if(vuelosCompletosSucesivos == 0 && esVueloCompleto == true && esVueloCompletoAnterior == false)
        {
            esVueloCompletoAnterior = true;
        }
        else if(esVueloCompleto == false && esVueloCompletoAnterior == true)
        {
            esVueloCompletoAnterior = false;
        }
        else if(esVueloCompletoAnterior == true && esVueloCompleto == true)
        {
            vuelosCompletosSucesivos++;
        }

        if(totalRecaudadoVuelo > vueloMasRecaudacionMensual)
        {
            vueloMasRecaudacionMensual = totalRecaudadoVuelo;
            numeroVueloMasRecaudacion = numeroDeVuelo;
        }
        
        totalRecaudadoMes += totalRecaudadoVuelo;

        totalRecaudadoVuelo = 0;
        asientosOcupados = 0;
        
    }

    cout << "-----------------------------------" << endl;
    
    cout << "Total recaudado en el mes: " << totalRecaudadoMes << endl;    
    cout << "Cantidad de vuelos sucesivos completos: " << vuelosCompletosSucesivos << endl;    
    cout << "Numero de vuelo con mayor recaudacion del mes: " << numeroVueloMasRecaudacion << endl;    

 system("pause");
 return 0;
}