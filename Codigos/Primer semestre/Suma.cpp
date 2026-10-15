#include <iostream>
using namespace std;

class Calculadora {
public:
    int sumar(int num1, int num2) {
        return num1 + num2;
    }
};

int main() {
    Calculadora calculadora;
    int a, b;

    cout << "Ingresa el primer numero: ";
    cin >> a;

    cout << "Ingresa el segundo numero: ";
    cin >> b;

    cout << "La suma es: " << calculadora.sumar(a, b) << endl;

    return 0;
}
