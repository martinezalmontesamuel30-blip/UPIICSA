#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Ordenador {
private:
    vector<T> datos;

    // Lógica interna del burbuja (privada)
    void burbuja(bool ascendente) {
        int n = datos.size();
        for (int i = 0; i < n - 1; i++) {
            bool huboIntercambio = false;
            for (int j = 0; j < n - 1 - i; j++) {
                bool condicion = ascendente ? (datos[j] > datos[j + 1])
                                            : (datos[j] < datos[j + 1]);
                if (condicion) {
                    T temp = datos[j];
                    datos[j] = datos[j + 1];
                    datos[j + 1] = temp;
                    huboIntercambio = true;
                }
            }
            if (!huboIntercambio) break;
        }
    }

public:
    Ordenador() {}
    Ordenador(const vector<T>& v) : datos(v) {}

    void cargar(const vector<T>& v) { datos = v; }

    void ordenarAscendente() { burbuja(true); }
    void ordenarDescendente() { burbuja(false); }

    void mostrar() const {
        for (const T& x : datos) cout << x << " ";
        cout << endl;
    }

    vector<T> getDatos() const { return datos; }
};

#endif
