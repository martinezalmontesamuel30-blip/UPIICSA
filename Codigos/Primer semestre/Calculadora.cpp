#include <iostream>
using namespace std;

class Calculadora {
public:
    virtual int multiplicar(int a, int b) {
        return a * b;
    }
};

class CalculadoraNueva : public Calculadora {
public:
    int multiplicar(int a, int b) override {
        int r = 0;
        int signo = 1;

        if (b < 0) {
            b = -b;
            signo = -1;
        }

        for (int i = 0; i < b; i++)
            r += a;

        return r * signo;
    }

    int potencia(int a, int b) {
        if (b < 0) return 0;

        int r = 1;

        for (int i = 0; i < b; i++)
            r = multiplicar(r, a);

        return r;
    }

    int dividir(int a, int b) {
        if (b == 0) {
            cout << "No se puede dividir entre cero" << endl;
            return 0;
        }

        int r = 0;
        int signo = 1;

        if (a < 0) {
            a = -a;
            signo = -signo;
        }

        if (b < 0) {
            b = -b;
            signo = -signo;
        }

        while (a >= b) {
            a -= b;
            r++;
        }

        return r * signo;
    }
};

int main() {
    CalculadoraNueva c;

    cout << c.multiplicar(-4, 3) << endl;
    cout << c.multiplicar(4, -3) << endl;
    cout << c.potencia(-2, 3) << endl;
    cout << c.dividir(-10, 2) << endl;
    cout << c.dividir(10, -2) << endl;

    return 0;
}
