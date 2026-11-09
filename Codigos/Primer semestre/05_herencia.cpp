#include <iostream>
using namespace std;

class Calculadora {
public:
    double sumar(double a, double b) { return a + b; }
    double restar(double a, double b) { return a - b; }
};

class CalculadoraNueva : public Calculadora {
public:
    double multiplicar(double a, double b) { return a * b; }
    double dividir(double a, double b) {
        if (b == 0) {
            cout << "No se puede dividir entre cero.\n";
            return 0;
        }
        return a / b;
    }
};

int main() {
    CalculadoraNueva calc;
    cout << "Suma: " << calc.sumar(8, 2) << "\n";
    cout << "Resta: " << calc.restar(8, 2) << "\n";
    cout << "Multiplicacion: " << calc.multiplicar(8, 2) << "\n";
    cout << "Division: " << calc.dividir(8, 2) << "\n";
    return 0;
}
