#include <iostream>
using namespace std;
#define CANT_MAX_ALUMNOS 50

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

int main () {
    
    int edad = 0;
    int cantidadAlumnos = 0;
    int sumaEdades = 0;
    float edadPromedio = 0;
    int edadAlumnos[CANT_MAX_ALUMNOS] = {0};

    leer("Ingrese la edad del alumno (-1 para terminar): ", edad);
    
    while(edad != -1 && cantidadAlumnos < CANT_MAX_ALUMNOS)
    {
        edadAlumnos[cantidadAlumnos] = edad;
        sumaEdades += edad;
        cantidadAlumnos++;

        if(cantidadAlumnos < CANT_MAX_ALUMNOS)
        {
            leer("Ingrese la edad del alumno (-1 para terminar): ", edad);
        }
    }

    edadPromedio = sumaEdades / cantidadAlumnos;

    cout << "Edades de los alumnos con edad mayor a la edad promedio: " << endl;
    for (int i = 0; i < cantidadAlumnos; i++)
    {
        if (edadAlumnos[i] > edadPromedio)
        {
            cout << edadAlumnos[i] << endl;
        }
        
    }
    
    
    
    system("pause");
    return 0;
}

/*  Ingresar las edades de los alumnos de un curso e informar cuántos alumnos tienen una edad
    que supera la edad promedio. Se desconoce la cantidad de alumnos a procesar pero se sabe que
    a lo sumo se inscriben 50 alumnos en un curso. */