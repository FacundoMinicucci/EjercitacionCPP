#include <iostream>
using namespace std;
#define CANT_PERSONAS_MAX 100

struct Persona{
    string nombre;
    int edad;
};

void cargarPersonas(Persona personas[], int &cantidad, Persona persona) {
    cout << "Nombre: ";
    cin >> persona.nombre;  

    while(persona.nombre != "FIN" && cantidad < CANT_PERSONAS_MAX)
    {
        cout << "Ingrese edad: ";
        cin >> persona.edad;      

        personas[cantidad] = persona;

        cantidad++;

        if(cantidad < CANT_PERSONAS_MAX)
        {
            cout << "Nombre: ";
            cin >> persona.nombre;
        }        
    }
    return;
}

void encontrarPersonaMayor(Persona personas[], int cantidadPersonas, Persona &personaMayorEdad){
    for (int j = 0; j < cantidadPersonas; j++)
    {
        if(j == 0)
        {
            personaMayorEdad = personas[j];
        }
        else if(personas[j].edad > personaMayorEdad.edad)
        {
            personaMayorEdad = personas[j];
        }
    }
    return;
}

int main () {
 
    Persona persona;    
    Persona personas[CANT_PERSONAS_MAX];    
    Persona personaMayorEdad;
    int cantidadPersonas = 0;
    
    cargarPersonas(personas, cantidadPersonas, persona);
    
    encontrarPersonaMayor(personas, cantidadPersonas, personaMayorEdad);    

    cout << "La persona de mayor edad es " << personaMayorEdad.nombre << " con " << personaMayorEdad.edad << " anios." << endl;

    system("pause");
    return 0;
}