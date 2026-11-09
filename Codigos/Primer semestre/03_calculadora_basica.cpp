#include <iostream>
using namespace std;

class CalculadoraBasica {
public:
    double sumar(double a, double b) { return a + b; }
    double restar(double a, double b) { return a - b; }
    double multiplicar(double a, double b) { return a * b; }

    bool dividir(double a, double b, double &resultado) {
        if (b == 0) return false;
        resultado = a / b;
        return true;
    }
};

int main() {
    CalculadoraBasica calc;
    double a, b, resultado;
    int opcion;

    cout << "Ingresa dos numeros: ";
    cin >> a >> b;
    cout << "1 Suma  2 Resta  3 Multiplicacion  4 Division\nOpcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1: cout << calc.sumar(a, b); break;
        case 2: cout << calc.restar(a, b); break;
        case 3: cout << calc.multiplicar(a, b); break;
        case 4:
            if (calc.dividir(a, b, resultado)) cout << resultado;
            else cout << "No se puede dividir entre cero.";
            break;
        default: cout << "Opcion no valida.";
    }
    cout << "\n";
    return 0;
}
