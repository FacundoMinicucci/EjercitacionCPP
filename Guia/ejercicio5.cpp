#include <iostream>
using namespace std;

int main() {

    int num1;
    int num2;
    num1 = 0;
    num2 = 0;

    cout << "Ingrese dos numeros enteros: " << endl;
    cin >> num1 >> num2;

    if (num1 > num2)
    {
        cout << "El numero " << num1 <<  " es el mayor." << endl;

    }
    else
    {
        cout << "El numero " << num2 <<  " es el mayor." << endl;
    }

 system("pause"); 
 return 0;
}