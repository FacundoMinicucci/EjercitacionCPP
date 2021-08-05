#include <iostream>
using namespace std;

int main() {
    
    int numero;
    int sumatoria;

    numero = 0;
    sumatoria = 0;

    for(int i = 1; i <= 100; i++)
    {
        sumatoria = sumatoria + i;   

        numero++;
        
        cout << numero << endl;

    }

    cout << "La sumatoria de los primeros cien numeros naturales es: " << sumatoria << endl;

 system("pause");
 return 0;
}