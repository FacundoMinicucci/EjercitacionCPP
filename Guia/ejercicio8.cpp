#include <iostream>
using namespace std;

int main() {

    float lado1;
    float lado2;
    float lado3;

    lado1 = 0;
    lado2 = 0;
    lado3 = 0;

    cout << "Ingrese la longitud de los tres lados del triangulo: " << endl;
    cin >> lado1 >> lado2 >> lado3;

    if ((lado1 + lado2) > lado3 && (lado1 + lado3) > lado2 && (lado2 + lado3) > lado1)
    {
        if (lado1 == lado2 && lado1 == lado3 && lado2 == lado3)
        {
        cout << "Es un triangulo equilatero." << endl;
        }
        else if (lado1 != lado2 && lado1 != lado3 && lado2 != lado3)
        {
        cout << "Es un triangulo escaleno." << endl;
        }
        else
        {
        cout << "Es un triangulo isosceles." << endl;
        }
    }
    else
    {
        cout << "No es un triangulo." << endl;
    }
        

 system("pause");
 return 0;
}