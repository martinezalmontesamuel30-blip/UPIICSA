#include <iostream>
using namespace std;

class Recursividad {
public:
    long long factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }

    long long fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    int multiplicar(int a, int b) {
        if (b == 0) return 0;
        if (b < 0) return -multiplicar(a, -b);
        return a + multiplicar(a, b - 1);
    }
};

int main() {
    Recursividad r;
    int n;
    cout << "Ingresa un numero entre 0 y 20 para factorial: ";
    cin >> n;
    if (n >= 0 && n <= 20) cout << "Factorial: " << r.factorial(n) << "\n";
    else cout << "Numero fuera de rango.\n";

    cout << "Posicion de Fibonacci (0 a 40): ";
    cin >> n;
    if (n >= 0 && n <= 40) cout << "Fibonacci: " << r.fibonacci(n) << "\n";
    else cout << "Numero fuera de rango.\n";

    cout << "Multiplicacion de 6 por 4: " << r.multiplicar(6, 4) << "\n";
    return 0;
}
