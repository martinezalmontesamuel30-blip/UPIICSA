#include <iostream>
using namespace std;

class Estadisticas {
private:
    double numeros[5];

public:
    void leer() {
        cout << "Ingresa 5 numeros:\n";
        for (int i = 0; i < 5; i++) cin >> numeros[i];
    }

    void calcular() {
        double suma = 0, maximo = numeros[0], minimo = numeros[0];
        for (int i = 0; i < 5; i++) {
            suma += numeros[i];
            if (numeros[i] > maximo) maximo = numeros[i];
            if (numeros[i] < minimo) minimo = numeros[i];
        }
        cout << "Suma: " << suma << "\nPromedio: " << suma / 5
             << "\nMaximo: " << maximo << "\nMinimo: " << minimo << "\n";
    }
};

int main() {
    Estadisticas e;
    e.leer();
    e.calcular();
    return 0;
}
