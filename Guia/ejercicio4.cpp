#include <iostream>
using namespace std;

int main() {

    int num1;
    float quintaParte;
    int restoCinco;
    float septimaParte;
    num1 = 0;
    quintaParte = 0;
    restoCinco = 0;
    septimaParte = 0;

    cout << "Ingrese un valor entero: " << endl;
    cin >> num1;

    quintaParte = (num1 / 5);
    restoCinco = (num1 % 5);
    septimaParte = (quintaParte / 7);

    cout << "La quinta parte del numero ingresado es: " << quintaParte << endl;
    cout << "El resto de la division por 5 es: " << restoCinco << endl;
    cout << "La septima parte de la division por cinco es: " << septimaParte << endl;
    
    

 system("pause");
 return 0;
}