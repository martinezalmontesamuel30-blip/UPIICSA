#include <iostream>
#include <vector>
using namespace std;

class Fractales {
public:
    void sierpinski(int nivel) {
        int ancho = 1 << nivel;
        vector<string> dibujo(ancho, string(2 * ancho - 1, ' '));

        for (int fila = 0; fila < ancho; fila++) {
            for (int col = 0; col <= fila; col++) {
                if ((col & fila) == col) {
                    int posicion = ancho - 1 - fila + 2 * col;
                    dibujo[fila][posicion] = '*';
                }
            }
        }

        for (const string &linea : dibujo) cout << linea << "\n";
    }

    void cantor(int longitud, int nivel) {
        if (longitud <= 0 || nivel <= 0) return;

        cout << string(longitud, '#') << "\n";
        if (longitud < 3) return;

        int tercio = longitud / 3;
        if (tercio == 0) return;

        cout << string(tercio, ' ')
             << string(tercio, ' ')
             << string(tercio, ' ') << "\n";
        cantor(tercio, nivel - 1);
    }
};

int main() {
    Fractales f;
    int nivel;
    cout << "Nivel del triangulo de Sierpinski (0 a 5): ";
    cin >> nivel;
    if (nivel >= 0 && nivel <= 5) {
        cout << "\nTriangulo de Sierpinski:\n";
        f.sierpinski(nivel);
    } else {
        cout << "Nivel no valido.\n";
    }

    cout << "\nRepresentacion sencilla del polvo de Cantor:\n";
    f.cantor(27, 4);
    return 0;
}
