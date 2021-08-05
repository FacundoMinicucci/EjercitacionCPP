#include <iostream>
using namespace std;
#define CANT_MAX_ENTEROS 10

void eliminarElemento(int enteros[], int &cantidadElementos, int dato){
    
  
    bool elementoEliminado = true;

    while (elementoEliminado != false)
    {
        elementoEliminado = false;

        for(int j = 0; j < cantidadElementos; j++)
        {            
            if(enteros[j] == dato)
            {
                while(j < cantidadElementos)
                {
                    enteros[j] = enteros[j+1];
                    j++;
                }
            }            
        } 

        cantidadElementos--;

        for (int k = 0; k < cantidadElementos; k++)
        {
            if(enteros[k] == dato)
            {
                elementoEliminado = true;
            }
        }
               
    }    
    return;
}

int main () {
 
    int dato = 0;
    int cantidadElementos = CANT_MAX_ENTEROS;
    int enteros[CANT_MAX_ENTEROS] = {1,2,3,4,5,6,3,8,3,10};

    cout << "Ingrese el elemento a eliminar: ";
    cin >> dato;     
   
    cout << "El elemento a eliminar es " << dato << endl;
    eliminarElemento(enteros, cantidadElementos, dato);   

    for (int i = 0; i < cantidadElementos; i++)
    {
        cout << enteros[i] << "\t";
    }
    
    cout << endl;

    system("pause");
    return 0;
}