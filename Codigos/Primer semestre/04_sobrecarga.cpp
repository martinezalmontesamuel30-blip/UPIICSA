#include <iostream>
using namespace std;

class Calculadora {
public:
    double operar() {
        return 0;
    }

    double operar(double a, double b) {
        return a + b;
    }

    double operar(double a, double b, double c) {
        return a + b + c;
    }
};

int main() {
    Calculadora calc;

    cout << "Sin parametros: " << calc.operar() << "\n";
    cout << "Con dos parametros (4 + 5): " << calc.operar(4, 5) << "\n";
    cout << "Con tres parametros (4 + 5 + 6): " << calc.operar(4, 5, 6) << "\n";
    return 0;
}
