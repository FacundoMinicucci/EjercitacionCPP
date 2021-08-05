#include <iostream>
using namespace std;
#define CANT_MAX_ENTEROS 10

void insertarDato(int enteros[], int &cantidadElementos, int dato){
         
    int aux = 0;   
    enteros[cantidadElementos] = dato;    
   
    for (int i = cantidadElementos; i >= 0; i--)
    {
        if(dato < enteros[i-1])
        {
            aux = enteros[i-1];
            enteros[i-1] = enteros[i];
            enteros[i] = aux;                        
        }
    }    
    return;
}

int main () {
    
    int dato = 0;
    int cantidadElementos = CANT_MAX_ENTEROS;
    int enteros[cantidadElementos] = {1,2,3,5,6,7,8,9,10,11};
        
    cout << "Ingrese el dato: ";
    cin >> dato;      

    cantidadElementos++;    

    insertarDato(enteros, cantidadElementos, dato);

    for (int i = 0; i < cantidadElementos; i++)
    {
        cout << enteros[i] << endl;
    }    

    system("pause");
    return 0;
}