#include <iostream>
using namespace std;
#define CANT_ALUMNOS_MAX 100
#define LEGAJO_INICIAL 80001

struct Boleta {
    string apellidoNombre;
    int legajo;
    int codigoMateria;
    int dia;
    int mes;
    int anio;
};

struct Alumno {
    string apellidoNombre;
    int numeroLegajo;
};

void cargarBoleta(Boleta inscripcionFinales[], int &cantidadBoletas, Boleta alumno){

    cout << "Ingrese el legajo del alumno: ";
    cin >> alumno.legajo;

    while(alumno.legajo != 0 && cantidadBoletas < CANT_ALUMNOS_MAX)
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
        cin >> alumno.apellidoNombre;

        inscripcionFinales[cantidadBoletas] = alumno;

        cantidadBoletas++;
        
        cout << "Ingrese el legajo del alumno: ";
        cin >> alumno.legajo;
    }
    return;
}

void ordenarPorLegajo(Boleta inscripcionFinales[], int cantidadBoletas){
    int k = 0;    
    Boleta aux;
    bool ordenado = false;

    while (k < cantidadBoletas && !ordenado) 
    {
        ordenado = true; 

        for (int j = 0; j < cantidadBoletas-k-1; j++) 
        {
            if (inscripcionFinales[j].legajo > inscripcionFinales[j+1].legajo) 
            {
                aux = inscripcionFinales[j];
                inscripcionFinales[j] = inscripcionFinales[j+1];
                inscripcionFinales[j+1] = aux;
                ordenado = false; 
            }
        }              
        k++;
    }
    return;
}

void imprimirMateria(Boleta inscripcionFinales[], int cantidadBoletas, Boleta alumno){

    cout << "Ingrese el codigo de materia de las inscripciones que desea obtener: ";
    cin >> alumno.codigoMateria;
    
    cout << "Legajo\tNombre y Apellido\tFecha\t\tCodigo de materia" << endl;
    for (int j = 0; j < cantidadBoletas; j++)
    {
        if (alumno.codigoMateria == inscripcionFinales[j].codigoMateria)
        {
            cout << inscripcionFinales[j].legajo << "\t" << inscripcionFinales[j].apellidoNombre << "\t\t" << inscripcionFinales[j].dia << "/" << inscripcionFinales[j].mes << "/" << inscripcionFinales[j].anio << "\t" << inscripcionFinales[j].codigoMateria << endl;
        }
    }
    return;
}

void imprimirAlumno(Alumno alumnos[], int cantidad){
    cout << "Alumnos cargados" << endl;
    cout << "Legajo\t\tApellido" << endl;
    for (int i = 0; i < cantidad; i++)
    {
      
        cout << alumnos[i].numeroLegajo << "\t\t" << alumnos[i].apellidoNombre << endl;
        
    }
    return;
}

void cargarAlumnos(Boleta inscripcionFinales[], Alumno alumnos[], int cantidadBoletas){
    for (int i = 0; i < cantidadBoletas; i++)
    {
        int pos = inscripcionFinales[i].legajo - LEGAJO_INICIAL;
        alumnos[pos].numeroLegajo = inscripcionFinales[i].legajo;
        alumnos[pos].apellidoNombre = inscripcionFinales[i].apellidoNombre;
    }
    return;    
}

int main () {

    Boleta alumno;
    Boleta inscripcionFinales[CANT_ALUMNOS_MAX];
    int cantidadBoletas = 0; // Cantidad de boletas cargadas.
    Alumno alumnos[CANT_ALUMNOS_MAX];
    
    cargarBoleta(inscripcionFinales, cantidadBoletas, alumno);
    
    ordenarPorLegajo(inscripcionFinales, cantidadBoletas);

    cargarAlumnos(inscripcionFinales, alumnos, cantidadBoletas);    
    
    imprimirAlumno(alumnos, cantidadBoletas);

    system("pause");
    return 0;
}