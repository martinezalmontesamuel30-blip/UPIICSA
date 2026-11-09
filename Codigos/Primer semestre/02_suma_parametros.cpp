#include <iostream>
using namespace std;

class Operacion {
public:
    int sumar(int a, int b) {
        return a + b;
    }
};

int main() {
    Operacion op;
    int a, b;

    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    cout << "Resultado: " << op.sumar(a, b) << "\n";
    return 0;
}
