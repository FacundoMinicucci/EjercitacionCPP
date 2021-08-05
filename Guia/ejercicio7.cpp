#include <iostream>
using namespace std;

int main() {

    float lado1;
    float lado2;
    float lado3;

    lado1 = 0;
    lado2 = 0;
    lado3 = 0;

    cout << "Ingrese el primer lado del triangulo: " << endl;
    cin >> lado1;
    
    cout << "Ingrese el segundo lado del triangulo: " << endl;
    cin >> lado2;
    
    cout << "Ingrese el tercer lado del triangulo: " << endl;
    cin >> lado3;

    if ((lado1 + lado2) > lado3 && 
        (lado1 + lado3) > lado2 && 
        (lado2 + lado3) > lado1)
    {
        cout << "Es un triangulo." << endl;
    }
    else
    {
        cout << "No es triangulo." << endl;
    }

 system("pause");
 return 0;
}