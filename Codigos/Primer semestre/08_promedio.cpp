#include <iostream>
using namespace std;

class Estadisticas {
public:
    void calcular() {
        double n, suma = 0, maximo, minimo;
        cout << "Ingresa 5 numeros:\n";

        for (int i = 0; i < 5; i++) {
            cin >> n;
            if (i == 0) maximo = minimo = n;
            if (n > maximo) maximo = n;
            if (n < minimo) minimo = n;
            suma += n;
        }

        cout << "Suma: " << suma << "\n";
        cout << "Promedio: " << suma / 5 << "\n";
        cout << "Maximo: " << maximo << "\n";
        cout << "Minimo: " << minimo << "\n";
    }
};

int main() {
    Estadisticas e;
    e.calcular();
    return 0;
}
