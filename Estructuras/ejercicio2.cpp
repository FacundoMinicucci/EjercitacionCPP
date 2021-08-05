#include <iostream>
using namespace std;

struct Persona{
    string nombre;
    int fechaNacimiento[3];
};

struct Alumno{
    int legajo;
    string apellidoNombre[2];
    int notas[3];
};

void cargarPersonas(Persona personas[], int cantidad, Persona persona){
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Ingrese el nombre de la persona: ";
        cin >> persona.nombre;

        cout << "Ingrese el dia, mes y anio de nacimiento: " << endl;
        for (int j = 0; j < 3; j++)
        {
            cin >> persona.fechaNacimiento[j];        
        }              

        personas[i] = persona;        
    }
    return;
}

void cargarAlumnos(Alumno alumnos[], int cantidad, Alumno alumno){
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Ingrese el legajo del alumno: ";
        cin >> alumno.legajo;

        cout << "Ingrese el apellido y nombre del alumno respectivamente: " << endl;
        for (int k = 0; k < 2; k++)
        {
            cin >> alumno.apellidoNombre[k];
        }        

        cout << "Ingrese las notas del alumno: " << endl;
        for (int j = 0; j < 3; j++)
        {
            cin >> alumno.notas[j];
        }

        alumnos[i] = alumno;
    }
    return;            
}

void imprimirPersonas(Persona personas[], int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Nombre: " << personas[i].nombre << endl;

        cout << "Fecha: ";
        for (int j = 0; j < 3; j++)
        {
            cout << personas[i].fechaNacimiento[j];
        }
        
        cout << endl;
    }
    return;
}

void imprimirAlumnos(Alumno alumnos[], int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Legajo: " << alumnos[i].legajo << endl;

        cout << "Apellido y nombre: ";
        for (int j = 0; j < 2; j++)
        {
            cout << alumnos[i].apellidoNombre[j] << " ";
        }

        cout << endl << "Notas: " << endl;
        for (int k = 0; k < 3; k++)
        {
            cout << alumnos[i].notas[k] << endl;
        }
    }                
}

int main () {
 
    int cantidadPersonas = 0;
    int cantidadAlumnos = 0;
    Persona persona;
    Alumno alumno;

    cout << "Ingrese la cantidad de personas: ";
    cin >> cantidadPersonas;

    Persona personas[cantidadPersonas];

    cout << "Ingrese la cantidad de alumnos: ";
    cin >> cantidadAlumnos;

    Alumno alumnos[cantidadAlumnos];
    
    cargarPersonas(personas, cantidadPersonas, persona);    
    
    cargarAlumnos(alumnos, cantidadAlumnos, alumno);
    
    imprimirPersonas(personas, cantidadPersonas);
    
    imprimirAlumnos(alumnos, cantidadAlumnos);    

    system("pause");
    return 0;
}