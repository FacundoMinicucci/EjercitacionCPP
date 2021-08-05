#include <iostream>
using namespace std;
#define CANT_MAX_ENTEROS 10

int encontrarMenor(int enteros[], int cantidadElementos){

    int menor;

    for (int i = 0; i < cantidadElementos - 1; i++)
    {
        if(enteros[i] < menor || i == 0)
        {
            menor = enteros[i];
        }
    }
    return menor;    
}

void eliminarMultiplos(int enteros[], int &cantidadElementos, int menor){

    bool multiplosEliminados = false;
  
    while(multiplosEliminados != true)
    {
        multiplosEliminados = true;

        for (int i = 0; i < cantidadElementos; i++)
        {          
            if(enteros[i] % menor == 0)
            {
                while(i < cantidadElementos)
                {
                    enteros[i] = enteros[i+1];
                    i++;
                    
                }
            }
        }
        cantidadElementos--;

        for (int j = 0; j < cantidadElementos; j++)
        {
            if(enteros[j] % menor == 0)
            {
                multiplosEliminados = false;
            }
        }        
    }
    return; 
}

int main () {
    
    int menor = 0;
    int cantidadElementos = CANT_MAX_ENTEROS;
    int enteros[cantidadElementos] = {2,3,4,5,6,7,8,9,10,11};  

    menor = encontrarMenor(enteros, cantidadElementos);

    eliminarMultiplos(enteros, cantidadElementos, menor);

    for (int i = 0; i < cantidadElementos; i++)
    {
        cout << enteros[i] << "\t";
    }
    cout << endl;

    system("pause");
    return 0;
}