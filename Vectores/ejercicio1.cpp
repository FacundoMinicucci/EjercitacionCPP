#include <iostream>
using namespace std;

int main() {
 
    int cantidadValores = 0;    

    cout << "Ingrese la cantidad de valores pares que desea obtener: " << endl;
    cin >> cantidadValores;

    int miArray[cantidadValores];

    for (int i = 1; i <= cantidadValores; i++)
    {                
        miArray[i] = (i * 2);
        
        cout << miArray[i] << endl;        
    }    
    
 system("pause");
 return 0;
}