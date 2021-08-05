#include <iostream>
using namespace std;

int main () {
    
    int fechaNacimiento;
    int fechaNacimientoMayor;
    int fechaNacimientoMenor;      
    string nombre;
    string nombreMayor;
    string nombreMenor;
   
    fechaNacimiento = 0;
    fechaNacimientoMayor = 0;
    fechaNacimientoMenor = 0;
    nombre = "";    
    nombreMayor = "";
    nombreMenor = "";    
    
    cout << "Ingrese un nombre: " << endl;
    cin >> nombre;

    while(nombre != "Fin")
    {        
        cout << "Ingrese la fecha de nacimiento: " << endl;
        cin >> fechaNacimiento; 

        if(fechaNacimiento != 0 && fechaNacimientoMayor == 0 && fechaNacimientoMenor == 0)
        {
            fechaNacimientoMenor = fechaNacimiento;
            fechaNacimientoMayor = fechaNacimiento;
            nombreMayor = nombre;
            nombreMenor = nombre;
        }        

        if(fechaNacimiento < fechaNacimientoMayor)
        {
            fechaNacimientoMayor = fechaNacimiento;
            nombreMayor = nombre;
        }
       
        if(fechaNacimiento > fechaNacimientoMenor)
        {
            fechaNacimientoMenor = fechaNacimiento;
            nombreMenor = nombre;
        }        
        
        cout << "Ingrese un nombre:" << endl;
        cin >> nombre;        

    }

    cout << nombreMayor << " es la persona de mayor edad." << endl;
    cout << nombreMenor << " es la persona de menor edad." << endl;

 system("pause");
 return 0;
}