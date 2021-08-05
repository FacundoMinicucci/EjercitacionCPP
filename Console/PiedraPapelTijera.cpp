#include <iostream>
#include <ctime>
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

// Pide al usario que ingrese una opción y retorna booleano según sea válida o no.
bool validarOpcion(int &valor){
    leer("1. Piedra, 2. Papel o 3. Tijera", valor);
    return !(valor < 1 || valor > 3);
}

// Imprime la jugada y el nombre del usuario.
int mostrarJugadaUsuario (int jugadaUsuario, string nickname) {    

    if(jugadaUsuario == 1)
    {
      cout << nickname + " eligio piedra." << endl;
    }
    else if(jugadaUsuario == 2)
    {
       cout << nickname + " eligio papel." << endl;
    }
    else if(jugadaUsuario == 3)
    {
       cout << nickname + " eligio tijera." << endl;
    }
    
}

// Genera un valor al azar e imprime jugada de la computadora.
void mostrarJugadaComputadora (int &valor) {

    valor = rand() % 3 + 1;

    if(valor == 1)
    {
        cout << "La computadora eligio piedra." << endl;
    }
    else if(valor == 2)
    {
        cout << "La computadora eligio papel." << endl;
    }
    else if(valor == 3)
    {
        cout << "La computadora eligio tijera." << endl;
    }
        
}

// Calcula puntos del ganador y pasa por referencia los puntos obtenidos al que corresponda.
void calcularPuntos(int opcionUsuario, int opcionComputadora, string nickname, int &puntosUsuario, int &puntosComputadora) {
    
    if(opcionUsuario == opcionComputadora)
    {
        cout << "Empate, nadie suma puntos." << endl;
        cout << "Sigue el juego." << endl;
           
    }
    else if(opcionUsuario == 1 && opcionComputadora == 3)
    {
        cout << "Gana piedra." << endl;
        cout << nickname << " suma 1 punto." << endl;
        puntosUsuario++;     
    }
    else if(opcionUsuario == 2 && opcionComputadora == 1)
    {
        cout << "Gana papel." << endl;
        cout << nickname << " suma 1 punto." << endl;
        puntosUsuario++;        
    }
    else if(opcionUsuario == 3 && opcionComputadora == 2)
    {
        cout << "Gana tijera." << endl;
        cout << nickname << " suma 1 punto." << endl;
        puntosUsuario++;        
    }
    else if(opcionUsuario == 3 && opcionComputadora == 1)
    {
        cout << "Gana piedra." << endl;
        cout << "La computadora suma 1 punto." << endl;
        puntosComputadora++;        
    }
    else if(opcionUsuario == 1 && opcionComputadora == 2)
    {
        cout << "Gana papel." << endl;
        cout << "La computadora suma 1 punto." << endl;
        puntosComputadora++;        
    }
    else if(opcionUsuario == 2 && opcionComputadora == 3)
    {
        cout << "Gana tijera." << endl;
        cout << "La computadora suma 1 punto." << endl;
        puntosComputadora++;        
    }    
        
}

string imprimirResultadoParcial(string nickname, int puntosUsuario, int puntosComputadora){
    cout << "Resultado parcial: " << nickname << " " << puntosUsuario << " - Computadora " << puntosComputadora << endl;  
    cout << endl;
}

// Recibe puntos de cada jugador, determina si alguno tiene 3 puntos y devuelve true si hay un ganador.
bool determinarGanador(int ganadasUsuario, int ganadasComputadora, string nickname){

    if(ganadasUsuario == 3)
    {
        cout << "-------------------------------------------" << endl;
        cout << "Felicidades " << nickname << ", has ganado!" << endl;
        return true;                      
    }
    
    if(ganadasComputadora == 3)
    {
        cout << "-------------------------------------------" << endl;
        cout << "Ha ganado la computadora, mejor suerte para la proxima! " << endl;
        return true;               
    }  
     
    return false;
}

int main(){

    string nombreUsuario = "";
    int opcionUsuario = 0;    
    int opcionComputadora = 0;    
    int ganadasUsuario = 0;
    int ganadasComputadora = 0;
    bool jugar = true;    
    
    system("cls");
    
    cout << ("Bienvenido a Piedra, Papel o Tijera") << endl;

    leer("Ingrese su usuario", nombreUsuario);

    srand(time(0));
    while(jugar)
    {
        if(validarOpcion(opcionUsuario))
        {
            mostrarJugadaUsuario(opcionUsuario, nombreUsuario);       
           
            mostrarJugadaComputadora(opcionComputadora);            

            calcularPuntos(opcionUsuario,opcionComputadora, nombreUsuario, ganadasUsuario, ganadasComputadora);                     
            
            // Finaliza while cuando hay un ganador (jugador o computadora obtuvo 3 puntos).               
            if(determinarGanador(ganadasUsuario, ganadasComputadora, nombreUsuario))
            {
                break;
            }                 

            imprimirResultadoParcial(nombreUsuario, ganadasUsuario, ganadasComputadora);
            
        }
        else
        {
            cout << "La opcion ingresada es incorrecta. Por favor, ingrese una opcion valida." << endl;
        }        
    }

    cout << "Gracias por jugar a Piedra, Papel o Tijera." << endl;
    
 system("pause");
 return 0;
}