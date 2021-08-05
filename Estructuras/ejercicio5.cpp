#include <iostream>
using namespace std;
#define CANT_ALUMNOS_MAX 100

struct Boleta {
    string apellido;
    int legajo;
    int codigoMateria;
    int dia;
    int mes;
    int anio;
};

void cargarBoleta(Boleta inscripcionFinales[], int &i, Boleta alumno){

    cout << "Ingrese el legajo del alumno: ";
    cin >> alumno.legajo;

    while(alumno.legajo != 0 && i < CANT_ALUMNOS_MAX)
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

        inscripcionFinales[i] = alumno;

        i++;
        
        cout << "Ingrese el legajo del alumno: ";
        cin >> alumno.legajo;
    }
    return;
}

void imprimirMateria(Boleta inscripcionFinales[], int i, Boleta alumno){
     cout << "Ingrese el codigo de materia de las inscripciones que desea obtener: ";
    cin >> alumno.codigoMateria;
    
    cout << "Legajo\tNombre y Apellido\tFecha\t\tCodigo de materia" << endl;
    for (int j = 0; j < i; j++)
    {
        if (alumno.codigoMateria == inscripcionFinales[j].codigoMateria)
        {
            cout << inscripcionFinales[j].legajo << "\t" << inscripcionFinales[j].apellido << "\t\t" << inscripcionFinales[j].dia << "/" << inscripcionFinales[j].mes << "/" << inscripcionFinales[j].anio << "\t" << inscripcionFinales[j].codigoMateria << endl;
        }
    }
    return;
}

int main () {

    Boleta alumno;
    Boleta inscripcionFinales[CANT_ALUMNOS_MAX];
    int i = 0;
    
    cargarBoleta(inscripcionFinales, i, alumno);    

    // aca se resuelve el ejercicio 5
    imprimirMateria (inscripcionFinales, i, alumno);

    system("pause");
    return 0;
}