#include <iostream>
using namespace std;

int main() {

    int num1;
    int num2;    
    int sumaSucesiva;

    num1 = 0;
    num2 = 0;
    sumaSucesiva = 0;

    cout << "Ingrese un numero: " << endl;
    cin >> num1;

    cout << "Ingrese el valor por el que desea multiplicarlo: " << endl;
    cin >> num2;

    for(int i = 0; i < num2; i++)
    {        
        sumaSucesiva = sumaSucesiva + num1;     
    }

    cout << "El resultado del producto por sumas sucesivas es: " << sumaSucesiva << endl;

 system("pause");
 return 0;
}