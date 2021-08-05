#include <iostream>
using namespace std;

struct Alumno {
    int legajo;
    string apellidoNombre;
    int nota;
};

void cargarAlumnos(Alumno alumnos[], int cantidad, Alumno alumno){
    for (int i = 0; i < cantidad; i++)
    {                
        cout << "Ingrese el legajo del alumno: ";
        cin >> alumno.legajo;

        cout << "Ingrese el apellido y nombre del alumno (sin espacios): ";
        cin >> alumno.apellidoNombre;

        cout << "Ingrese la nota del alumno: ";
        cin >> alumno.nota;        
        
        alumnos[i] = alumno;
    }
    return;
}

void imprimirAlumnos(Alumno alumnos[], int cantidad){

    cout << "Legajo\t\tApellido y nombre\t\tNota " << endl;

    for (int i = 0; i < cantidad; i++)
    {
        cout << alumnos[i].legajo << "\t\t" << alumnos[i].apellidoNombre << "\t\t" << alumnos[i].nota;                
        cout << endl;
    }
    return;    
}

int main () {
 
    Alumno alumno;
    int cantidadAlumnos = 0;    

    cout << "Ingrese la cantidad de alumnos a cargar: ";
    cin >> cantidadAlumnos;

    Alumno alumnos[cantidadAlumnos];

    // Carga de alumnos.
    cargarAlumnos(alumnos, cantidadAlumnos, alumno);
    
    cout << "     ALUMNOS INGRESADOS AL SISTEMA     " << endl;
    cout << "----------------------------------------" << endl;

    // Impresión de alumnos.
    imprimirAlumnos(alumnos, cantidadAlumnos);     

    system("pause");
    return 0;
}

