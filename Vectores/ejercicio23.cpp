#include <iostream>
using namespace std;
#define CANT_MAX_ELEMENTOS 10

bool esElementoDelVector(int enteros[], int dato, int cantElementos){
   
   for(int i = 0; i < cantElementos; i++)
   {
       if (dato == enteros[i])
       {
           return true;
       }
   }
   return false;
}

int buscarPosicionSecuencial(int enteros[], int dato, int cantElementos)
{
    for (int i = 0; i < cantElementos; i++)
    {
        if(dato == enteros[i])
        {
            return i;
        }
    }
    return -1;
}

void buscarPosiciones(int enteros[], int dato, int cantElementos)
{
    for (int i = 0; i < cantElementos; i++)
    {
        if(dato == enteros[i])
        {
            cout << "Dato aparece en la posicion " << i << endl;
        }
    }
    
    return;
}

void buscarPrimeraYUltimaPos(int enteros[], int dato, int cantElementos, int &primeraPos, int &ultimaPos){
    
    for (int i = 0; i < cantElementos; i++)
    {
        if(primeraPos == -1 && dato == enteros[i])
        {
            primeraPos = i;
        }
        else if(dato == enteros[i])
        {
            ultimaPos = i;
        }
    }
    
    return;

}

int main () {
 
    int dato = 0;
    int enteros[CANT_MAX_ELEMENTOS] = {0,1,2,3,4,5,2,6,7,2};
    int numero = 0;
    int posDato;
    int cantElementos = CANT_MAX_ELEMENTOS;
    int primeraPos = -1;
    int ultimaPos = primeraPos;
    
    /*for (int i = 0; i < CANT_MAX_ELEMENTOS; i++)
    {
        enteros[i] = numero;
        numero++;
    }*/

    cout << "Ingrese el dato: ";
    cin >> dato;

    cout << "Item a): " << endl;
    if(esElementoDelVector(enteros, dato, cantElementos))
    {
        cout << dato << " es elemento del arreglo." << endl;
    }
    else
    {
        cout << dato << " no es elemento del arreglo." << endl;
    }

    cout << "Item b): " << endl;
    posDato = buscarPosicionSecuencial(enteros, dato, cantElementos);
    if(posDato != -1)
    {
        cout << dato << " es elemento del arreglo y se encuentra en la posicion " << posDato << endl;
    }

    cout << "Item c): " << endl;
    buscarPosiciones(enteros, dato, cantElementos);

    buscarPrimeraYUltimaPos(enteros,dato, cantElementos, primeraPos, ultimaPos);
    if(primeraPos == -1)
    {
        cout << "El dato no pertenece al arreglo." << endl;
    }
    else if (primeraPos == ultimaPos)
    {
        cout << dato << " solo aparece en la posicion " << primeraPos << " del arreglo." << endl;
    }
    else
    {
        cout << dato << " aparece por primera vez en la posicion " << primeraPos << " y por ultima vez en la posicion " << ultimaPos << " del arreglo." << endl;
    }
   

    system("pause");
    return 0;
}