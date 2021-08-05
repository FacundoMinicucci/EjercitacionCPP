#include <iostream>
using namespace std;
#define CANT_ALUMNOS_MAX 100

struct Boleta {
    int legajo;
    string apellido;
    int codigoMateria;
    int dia;
    int mes;
    int anio;
};

void cargarBoleta(Boleta inscripcionesNuevas[], int &cantidadNuevos, Boleta alumno){

    cout << "Ingrese el legajo del alumno: ";
    cin >> alumno.legajo;

    while(alumno.legajo != 0 && cantidadNuevos < CANT_ALUMNOS_MAX)
    {
        cout << "Ingrese el codigo de materia: ";
        cin >> alumno.codigoMateria;

        cout << "Ingrese el dia del examen: ";
        cin >> alumno.dia;

        cout << "Ingrese el mes del examen: ";
        cin >> alumno.mes;

        cout << "Ingrese el anio del examen: ";
        cin >> alumno.anio;

        cout << "Ingrese el apellido del alumno: ";
        cin >> alumno.apellido;

        inscripcionesNuevas[cantidadNuevos] = alumno;

        cantidadNuevos++;
        
        cout << "Ingrese el legajo del alumno: ";
        cin >> alumno.legajo;
    }
    return;
}

// Necesito saber la longitud del vector de finales anteriores, asumo que solo tiene 1 final en pos. 0
void anexarVectores(Boleta inscripcionFinalesAnteriores[], int &cantidadAnteriores, Boleta inscripcionesNuevas[], int cantidadNuevos) {
    int k = 0;

    for (int i = 0; i < cantidadNuevos; i++)
    {
        inscripcionFinalesAnteriores[k] = inscripcionesNuevas[i];
        k++;
    }
    
    return;
}

void imprimirAlumnos(Boleta inscripcionFinalesAnteriores[], int cantidadAnteriores, Boleta alumno){
    for (int j = 0; j < cantidadAnteriores; j++) 
    {
        cout << "Legajo: " << inscripcionFinalesAnteriores[j].legajo << endl;
        cout << "Codigo de materia: " << inscripcionFinalesAnteriores[j].codigoMateria << endl;
        cout << "Fecha: " << inscripcionFinalesAnteriores[j].dia << "/" << inscripcionFinalesAnteriores[j].mes << "/" << inscripcionFinalesAnteriores[j].anio << endl;        
        cout << "Apellido: " << inscripcionFinalesAnteriores[j].apellido << endl;
    }
    return;
}

int main () {

    Boleta alumno;        
    Boleta inscripcionFinalesAnteriores[CANT_ALUMNOS_MAX] = {2154,"Minicucci", 2569, 25, 06, 2021};
    Boleta inscripcionesNuevas[CANT_ALUMNOS_MAX];
    int cantidadNuevos = 0;
    int cantidadAnteriores = 1;
    
    cargarBoleta(inscripcionesNuevas, cantidadNuevos, alumno);    

    // Acá se resuelve el ejercicio 6
    anexarVectores(inscripcionFinalesAnteriores, cantidadAnteriores, inscripcionesNuevas, cantidadNuevos);
    
    imprimirAlumnos(inscripcionFinalesAnteriores, cantidadAnteriores, alumno);

    system("pause");
    return 0;
}