#include <iostream>
using namespace std;

struct ST_Examenes {
    int legajo;
    int codigoMateria;
    string apellidoNombre;
};

void anexarVectores(ST_Examenes maestroFinales[], int cantidadExamenesAnteriores, ST_Examenes finalesDelDia[], int cantidadExamenesDelDia, ST_Examenes finalesActualizados[], int &cantidadFinalesActualizados) {
    
    int i = 0, j = 0;    
    cantidadFinalesActualizados = 0;

    while (i < cantidadExamenesAnteriores && j < cantidadExamenesDelDia)
    { 
        
        if (maestroFinales[i].codigoMateria < finalesDelDia[j].codigoMateria)
        { 
            finalesActualizados[cantidadFinalesActualizados] = maestroFinales[i];
        
            i++;
        }        
        else 
        {
            finalesActualizados[cantidadFinalesActualizados] = finalesDelDia[j];
            j++;
        }
    
        cantidadFinalesActualizados++;
    }
    
    while(i < cantidadExamenesAnteriores)
    {
        finalesActualizados[cantidadFinalesActualizados] = maestroFinales[i];
        i++;
        cantidadFinalesActualizados++;
    }
    
    while(j < cantidadExamenesDelDia)
    {
        finalesActualizados[cantidadFinalesActualizados] = finalesDelDia[j];
        j++;
        cantidadFinalesActualizados++;
    }
    
    return;
}

void imprimirVector(ST_Examenes vectorExamenes[], int cantidadExamenes){
    for (int i = 0; i < cantidadExamenes; i++)
    {
        cout << "Codigo de materia: " << vectorExamenes[i].codigoMateria << endl;
        cout << "Legajo: " << vectorExamenes[i].legajo << endl;
        cout << "Apellido y nombre: " << vectorExamenes[i].apellidoNombre << endl;
    }
    return;
}

int main () {
    int cantidadExamenesAnteriores = 3;
    ST_Examenes maestroFinales[cantidadExamenesAnteriores] = {
        {20101,200,"MinicucciFacundo"},
        {20102,201,"AzarioGalliMalen"},
        {20103,202,"MinicucciDario"}
    };

    int cantidadExamenesDelDia = 5;
    ST_Examenes finalesDelDia[cantidadExamenesDelDia] = {
        {20104,203,"GalliMagdalena"},
        {20105,204,"CarusoGraciela"},
        {20106,205,"AzarioGalliZahira"},
        {20107,206,"MolinariSantiago"},
        {20108,207,"CocciaEsteban"}
    };

    int cantidadFinalesActualizados = 8;
    ST_Examenes finalesActualizados[cantidadFinalesActualizados];

    // Ordenar vectores    
    anexarVectores(maestroFinales, cantidadExamenesAnteriores, finalesDelDia, cantidadExamenesDelDia, finalesActualizados, cantidadFinalesActualizados);
        
    imprimirVector(finalesActualizados, cantidadFinalesActualizados);

    system("pause");
    return 0;
}

/* Se dispone un vector de inscripción de alumnos a exámenes finales MAESTROFINALES y otro con
las inscripciones del día de hoy DIAFINALES, ambos ordenados ascendente por código de materia y con el
siguiente diseño:
Nro de legajo (8 dígitos) Código de materia (6 dígitos) ApellidoNombre(cadena)
Se pide desarrollar un procedimiento que complete un nuevo vector de inscripciones a finales
FINALESACT resultante del apareo de los dos vectores anteriores, con el mismo orden y diseño. */