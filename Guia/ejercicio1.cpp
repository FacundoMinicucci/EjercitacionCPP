#include <iostream>
using namespace std;

int main () {

    int num1;
    int num2;
    int suma;
    int resta;
    int producto;    

    num1 = 0;
    num2 = 0;
    suma = 0;
    resta = 0;
    producto = 0;

    cout << "Ingrese el primer numero: " << endl;
    cin >> num1;

    cout << "Ingrese el segundo numero: " << endl;
    cin >> num2;
    
    suma = num1 + num2;
    resta = num1 - num2;
    producto = num1 * num2;

    cout << "El resultado de la suma es: " << suma << endl;
    cout << "El resultado de la resta es: " << resta << endl;
    cout << "El resultado de la producto es: " << producto << endl;

   system("pause");
   return 0; 
}

