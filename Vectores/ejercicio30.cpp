#include <iostream>
using namespace std;
#define CANT_MAX_ENTEROS 10

void eliminarRepetidos(int enteros[], int &cantidadElementos){
  
    for (int i = 0; i < cantidadElementos; i++)
    {
        for (int j = i+1; j < cantidadElementos; j++)
        {
            if(enteros[i] == enteros[j])
            {
                for (int k = j; k < cantidadElementos - 1; k++)
                {
                    enteros[k] = enteros[k+1];
                    
                    j = i;
                }                
                cantidadElementos--;
            }            
        }
    }    
    return;
}

int main () {
 
    int cantidadElementos = CANT_MAX_ENTEROS;
    int enteros[cantidadElementos] = {1,2,1,2,3,4,3,4,5,6};
                                    
    eliminarRepetidos(enteros, cantidadElementos);

    for (int i = 0; i < cantidadElementos; i++)
    {
        cout << enteros[i] << "\t";
    }
    cout << endl;

    system("pause");
    return 0;
}