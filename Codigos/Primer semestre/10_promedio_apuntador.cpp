#include <iostream>
using namespace std;

class Estadisticas {
private:
    double numeros[5];

public:
    void leer() {
        cout << "Ingresa 5 numeros:\n";
        for (int i = 0; i < 5; i++) cin >> *(numeros + i);
    }

    void calcular() {
        double *p = numeros;
        double suma = 0, maximo = *p, minimo = *p;

        for (int i = 0; i < 5; i++) {
            double valor = *(p + i);
            suma += valor;
            if (valor > maximo) maximo = valor;
            if (valor < minimo) minimo = valor;
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
