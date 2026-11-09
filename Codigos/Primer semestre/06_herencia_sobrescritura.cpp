#include <iostream>
using namespace std;

class Calculadora {
public:
    virtual double multiplicar(double a, double b) {
        return a * b;
    }

    virtual double potencia(double base, int exponente) {
        double resultado = 1;
        for (int i = 0; i < exponente; i++) resultado *= base;
        return resultado;
    }

    virtual int dividir(int a, int b) {
        if (b == 0) return 0;
        return a / b;
    }

    virtual ~Calculadora() {}
};

class CalculadoraNueva : public Calculadora {
public:
    double multiplicar(double a, double b) override {
        double resultado = 0;
        bool negativo = (a < 0) != (b < 0);
        int veces = static_cast<int>(b < 0 ? -b : b);
        for (int i = 0; i < veces; i++) resultado += (a < 0 ? -a : a);
        if (negativo) resultado = -resultado;
        return resultado;
    }

    double potencia(double base, int exponente) override {
        if (exponente < 0) return 1.0 / potencia(base, -exponente);
        if (exponente == 0) return 1;
        return base * potencia(base, exponente - 1);
    }

    int dividir(int a, int b) override {
        if (b == 0) return 0;
        int dividendo = (a < 0) ? -a : a;
        int divisor = (b < 0) ? -b : b;
        int resultado = 0;
        while (dividendo >= divisor) {
            dividendo -= divisor;
            resultado++;
        }
        return ((a < 0) != (b < 0)) ? -resultado : resultado;
    }
};

int main() {
    CalculadoraNueva calc;
    cout << "Multiplicacion por sumas: " << calc.multiplicar(4, 3) << "\n";
    cout << "Potencia recursiva: " << calc.potencia(2, 4) << "\n";
    cout << "Division por restas: " << calc.dividir(17, 5) << "\n";
    return 0;
}
