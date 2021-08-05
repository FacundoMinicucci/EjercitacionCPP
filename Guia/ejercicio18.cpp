#include <iostream>
using namespace std;

int main() {

    int cuantosMultiplos;
    int numero;

    cuantosMultiplos = 0;
    numero = 1;

    cout << "Cuantos multiplos de 3 pero no de 5 quiere evaluar?" << endl;
    cin >> cuantosMultiplos;

    int i = 0;
    while(i < cuantosMultiplos)
    {
        if((numero % 3) == 0 && (numero % 5) != 0)
        {
            cout << numero << endl;
            i++;
        }
        numero++;
    }




 system("pause");
 return 0;
}