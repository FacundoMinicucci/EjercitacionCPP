#include <iostream>
using namespace std;
#define MAX_CONSOLA 100

struct JuegosPorConsola {
    string Consola;
    int cantidadDeJuegos;
};

struct Juegos {
    int codigoDelJuego;
    int stock;
    string tituloDelJuego;
    string consola;
};

void ordenarPorConsola(Juegos juegos[], int cantidadJuegos){

    int i = 0;    
    Juegos aux;
    bool ordenado = false;

    while (i < cantidadJuegos && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cantidadJuegos-i-1; j++) 
        {
            if (juegos[j].consola > juegos[j+1].consola) 
            {
                aux = juegos[j];
                juegos[j] = juegos[j+1];
                juegos[j+1] = aux;
                ordenado = false; 
            }
        }              
        i++;
    }
    return;
}

void imprimirVector(JuegosPorConsola juegosPorConsola[], int cantidadConsola){
    for (int i = 0; i < cantidadConsola; i++)
    {
        cout << juegosPorConsola[i].Consola << endl;
        cout << juegosPorConsola[i].cantidadDeJuegos<< endl;
    }
    
}

void generarVector(Juegos juegos[], int cantidadJuegos, JuegosPorConsola juegosPorConsola[], int &cantidadConsola){
    
    int i = 0;  // uso i para moverme dentro del vector sobre los mismos tipos de consola.  
    cantidadConsola = 0;    
    int j = 0; // uso j para grabar adentro del vector de consolas una vez que i encuentra una consola diferente.
    int totalJuegos = 0 ;
    string keyConsola;

    while (i < cantidadJuegos)
    {
        keyConsola = juegos[i].consola;
        

        while (i < cantidadJuegos && keyConsola == juegos[i].consola)
        {                 
            totalJuegos += juegos[i].stock;
            i++;
        }
        juegosPorConsola[cantidadConsola].Consola = keyConsola; // Tengo que usar la clave porque adentro del while cambia de consola y necesito guardar la anterior, previo al cambio.
        juegosPorConsola[cantidadConsola].cantidadDeJuegos = totalJuegos;
        cantidadConsola++; // Esta variable reemplaza a la j, puedo usar j si el vector que viene está vacío o puedo usar la variable por referencia si ya viene cargado para no pisar posiciones anteriores.
        
    }
    return;
}

int main () {
 
    int cantidadJuegos = 5;
    Juegos juegos[5] = {
        {101,15,"The Last of Us","Ps3"},
        {102,25,"Pro Evolution Soccer 2019", "Ps3"},
        {103,10,"Mortal Kombat X","Ps4"},
        {104,7,"The Last of Us II","Ps4"},
        {105,3,"Mortal Kombat III Ultimate","Sega Genesis"}
    };
    int cantidadConsola = 0; 
    JuegosPorConsola juegosPorConsola[MAX_CONSOLA];
    // Ordenar vector Juegos por consola.
    ordenarPorConsola(juegos, cantidadJuegos);
    
    // Llenar vector juegosPorConsola con corte de control.
    generarVector(juegos, cantidadJuegos, juegosPorConsola, cantidadConsola);
    
    imprimirVector(juegosPorConsola, cantidadConsola);


    system("pause");
    return 0;
}