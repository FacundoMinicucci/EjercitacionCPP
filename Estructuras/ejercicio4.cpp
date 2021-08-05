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

void imprimirAlumnos(Boleta inscripcionFinales[], int i, Boleta alumno){
    for (int j = 0; j < i; j++)
    {
        cout << "Legajo: " << inscripcionFinales[j].legajo << endl;
        cout << "Codigo de materia: " << inscripcionFinales[j].codigoMateria << endl;
        cout << "Fecha: " << inscripcionFinales[j].dia << "/" << inscripcionFinales[j].mes << "/" << inscripcionFinales[j].anio << endl;        
        cout << "Apellido: " << inscripcionFinales[j].apellido << endl;
    }
    return;
}

int main () {

    Boleta alumno;
    Boleta inscripcionFinales[CANT_ALUMNOS_MAX];
    int i = 0;
    
    cargarBoleta(inscripcionFinales, i, alumno);    

    imprimirAlumnos(inscripcionFinales, i, alumno);

    system("pause");
    return 0;
}

/* Se dispone de un conjunto de boletas de inscripción de alumnos (100 como máximo) a examen en el mes de
mayo. Cada boleta tiene los siguientes datos: apellido, número de legajo, código de materia, día, mes y año del
examen. Los datos finalizan con un legajo igual a 0.
Desarrollar un programa que, a partir del ingreso de las boletas mencionadas, por teclado genere un vector de
inscripción de alumnos a exámenes finales según el siguiente diseño:
a.1 Nro. de legajo (8 dígitos) a.2 Código de materia (6 dígitos)
a.3 Día del examen (1..31) a.4 Mes del examen (1..12)
a.5 Año del examen (4 dígitos) a.6 Apellido (25 caract) */