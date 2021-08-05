#include <iostream>
#include <ctime>
using namespace std;

int main() {

    int numeroAleatorio;
    string color;
    int tirosRuleta;
    int cantidadTiros;
    int cantidadNumeroCero;
    int numeroAnteriorAlCero;
    int numeroAnterior;
    int cantidadRepetidaNegro;
    int cantidadMayorRepetidaNegro;
    int numeroRepetido;
    int numeroMasRepetido;   
    int cantidadNumeroRepetido;
    int cantidadNumeroMasRepetido;
    int cantidadColoresAlternados;
    int cantidadMayorColoresAlternados;
    int cantidadSegundaDocenaNegada;
    int cantidadMayorSegundaDocenaNegada;
    

    numeroAleatorio = 0;
    color = "";
    tirosRuleta = 0;
    cantidadTiros = 0;
    cantidadNumeroCero = 0;
    numeroAnteriorAlCero = 0;
    numeroAnterior = 0;
    cantidadRepetidaNegro = 0;
    cantidadMayorRepetidaNegro = 0;
    numeroRepetido = 0;    
    numeroMasRepetido = 0;
    cantidadNumeroRepetido = 0;
    cantidadNumeroMasRepetido = 0;
    cantidadColoresAlternados = 0;
    cantidadMayorColoresAlternados = 0;
    cantidadSegundaDocenaNegada = 0;
    cantidadMayorSegundaDocenaNegada = 0;
    

    cout << "Cuantos tiros de ruleta desea realizar ?" << endl;
    cin >> tirosRuleta;

    cout << "Tiros de la ruleta: " << endl;

    srand(time(0));
    while(cantidadTiros < tirosRuleta)
    {  
      cantidadTiros++;

      numeroAleatorio = (rand() % 36);
      cout << numeroAleatorio << endl;            

      // Color que corresponde al numero.
      if(numeroAleatorio == 0)
      {
        color = "Verde";
      }
      else if(numeroAleatorio % 2 == 0)
      {
        color = "Negro";
      }
      else
      {
        color = "Rojo";
      }    

      // Cantidad de veces que salio el cero.
      if(numeroAleatorio == 0 && cantidadTiros == 1)
      {
        cantidadNumeroCero++;
        cout << "Es el primer tiro, no hay numeros anteriores a cero." << endl;
      }
      else if (numeroAleatorio == 0 )
      {
        cantidadNumeroCero++;
        
        cout << "El numero " << numeroAnterior << " salio antes de un cero." << endl;

      }

      // Cantidad de veces seguidas que salio el negro.
      if(color == "Negro" && (numeroAnterior % 2 == 0))
      {
        cantidadRepetidaNegro++;
      }      

      if(cantidadMayorRepetidaNegro < cantidadRepetidaNegro)
      {
        cantidadMayorRepetidaNegro = cantidadRepetidaNegro;
      }

      if(color != "Negro")
      {
        cantidadRepetidaNegro = 0;
      }
 
      // Cuantas veces seguidas llego a repetirse el mismo numero y cual fue.
      if(numeroAleatorio == numeroAnterior)
      {
        numeroRepetido = numeroAleatorio;
        cantidadNumeroRepetido++;
      }

      if(cantidadNumeroMasRepetido < cantidadNumeroRepetido)
      {
        cantidadNumeroMasRepetido = cantidadNumeroRepetido;
        numeroMasRepetido = numeroRepetido;
      }

      if(numeroAleatorio != numeroAnterior)
      {
        cantidadNumeroRepetido = 0;
      }

      // Mayor numero de veces seguidas que salieron rojo y negro alternados.
      if(numeroAleatorio % 2 == 0 && numeroAnterior % 2 != 0)
      {
        cantidadColoresAlternados++;
      }
      else if (numeroAleatorio % 2 != 0 && numeroAnterior % 2 == 0)
      {
        cantidadColoresAlternados++;
      }

      if(cantidadMayorColoresAlternados < cantidadColoresAlternados && cantidadColoresAlternados > 0)
      {
        cantidadMayorColoresAlternados = cantidadColoresAlternados;
      }

      if(numeroAleatorio % 2 == 0 && numeroAnterior % 2 == 0)
      {
        cantidadColoresAlternados = 0;
      }
      else if (numeroAleatorio % 2 != 0 && numeroAnterior % 2 != 0)
      {
        cantidadColoresAlternados = 0;
      }

      // Mayor numero de veces seguidas que se nego la segunda.
      if(numeroAleatorio < 13 || numeroAleatorio > 24)
      {
        cantidadSegundaDocenaNegada++;
      }

      if(cantidadMayorSegundaDocenaNegada < cantidadSegundaDocenaNegada)
      {
        cantidadMayorSegundaDocenaNegada = cantidadSegundaDocenaNegada;
      }

      if((numeroAleatorio >= 13 && numeroAleatorio <= 24) && (numeroAnterior < 13 || numeroAnterior > 24))
      {
        cantidadSegundaDocenaNegada = 0;
      }

      numeroAnterior = numeroAleatorio;
      
    }

    if(cantidadNumeroCero == 0)
    {
      cout << "No salio el numero cero." << endl;
    }
    else
    {
      cout << "El cero salio  " << cantidadNumeroCero << " veces." << endl;
    }
    
    if(cantidadMayorRepetidaNegro >= 1)
    {
      cout << "El color negro llego a repetirse " << cantidadMayorRepetidaNegro << " veces." << endl;      
    }
    else
    {
      cout << "No se repitio el color negro." << endl;
    }
    
    if(cantidadNumeroMasRepetido == 0)
    {
      cout << "No se repitieron numeros." << endl;
    }
    else
    {
      cout << "El numero que se repitio mas veces seguidas fue el " << numeroMasRepetido << " y se repitio " << cantidadNumeroMasRepetido << " veces." << endl;
    }
    
    if(cantidadMayorColoresAlternados == 0)
    {
      cout << "No salieron rojos y negros alternados." << endl;    
    }
    else
    {
      cout << "La cantidad de veces seguidas que salieron rojo y negro alternados fue " << cantidadMayorColoresAlternados << " veces." << endl;
    }

    if(cantidadMayorSegundaDocenaNegada == 0)
    {
      cout << "No se nego de forma seguida la segunda docena." << endl;
    }
    else
    {
      cout << "La mayor cantidad seguida de veces que se nego la segunda docena fue " << cantidadMayorSegundaDocenaNegada << " veces." << endl;
    }


 system("pause");
 return 0;
}