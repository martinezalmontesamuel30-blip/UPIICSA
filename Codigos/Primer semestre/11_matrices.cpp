#include <iostream>
using namespace std;

class Matrices {
private:
    static const int N = 2;
    int A[N][N], B[N][N];

public:
    void leer() {
        cout << "Ingresa matriz A (4 valores):\n";
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> A[i][j];

        cout << "Ingresa matriz B (4 valores):\n";
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> B[i][j];
    }

    void mostrarOperaciones(int constante) {
        cout << "\nA por constante:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << A[i][j] * constante << " ";
            cout << "\n";
        }

        cout << "\nA por B:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int suma = 0;
                for (int k = 0; k < N; k++) suma += A[i][k] * B[k][j];
                cout << suma << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Matrices m;
    int constante;
    m.leer();
    cout << "Ingresa una constante: ";
    cin >> constante;
    m.mostrarOperaciones(constante);
    return 0;
}
