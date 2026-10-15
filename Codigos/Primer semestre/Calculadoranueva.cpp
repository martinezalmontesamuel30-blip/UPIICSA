#include <iostream>
#include <cmath>
using namespace std;

class Calculadora {
public:
    int sumar(int a, int b) {
        return a + b;
    }

    int restar(int a, int b) {
        return a - b;
    }

    int multiplicar(int a, int b) {
        return a * b;
    }

    float dividir(float a, float b) {
        return a / b;
    }
};

class CalculadoraNueva : public Calculadora {
public:
    int potencia(int a, int b) {
        int r = 1;

        for (int i = 0; i < b; i++) {
            r = r * a;
        }

        return r;
    }

    double raiz(double a) {
        return sqrt(a);
    }
};

int main() {
    CalculadoraNueva c;

    cout << "Suma: " << c.sumar(5, 3) << endl;
    cout << "Resta: " << c.restar(5, 3) << endl;
    cout << "Multiplicacion: " << c.multiplicar(5, 3) << endl;
    cout << "Division: " << c.dividir(6, 3) << endl;
    cout << "Potencia: " << c.potencia(2, 3) << endl;
    cout << "Raiz: " << c.raiz(25) << endl;

    return 0;
}
