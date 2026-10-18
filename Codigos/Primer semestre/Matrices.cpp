#include <iostream>
using namespace std;

// PRACTICA 11: MATRIZ A POR CONSTANTE Y MATRIZ A POR B
class Matrices
{
private:
    int a[2][2], b[2][2];
    int constante;
    int porConstante[2][2], producto[2][2];

public:
    void capturar()
    {
        cout << "Ingresa los 4 valores de la matriz A:" << endl;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
            {
                cout << "A[" << i << "][" << j << "]: ";
                cin >> a[i][j];
            }

        cout << "Ingresa los 4 valores de la matriz B:" << endl;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
            {
                cout << "B[" << i << "][" << j << "]: ";
                cin >> b[i][j];
            }

        cout << "Ingresa la constante: ";
        cin >> constante;
    }

    void calcular()
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                porConstante[i][j] = a[i][j] * constante;
                producto[i][j] = 0;
                for(int k = 0; k < 2; k++)
                    producto[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    void mostrar()
    {
        cout << "\nMATRIZ A * CONSTANTE:" << endl;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
                cout << porConstante[i][j] << "\t";
            cout << endl;
        }

        cout << "\nMATRIZ A * B:" << endl;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
                cout << producto[i][j] << "\t";
            cout << endl;
        }
    }
};

int main()
{
    Matrices ejercicio;
    cout << "PRACTICA 11 - OPERACIONES CON MATRICES 2x2" << endl;
    ejercicio.capturar();
    ejercicio.calcular();
    ejercicio.mostrar();
    return 0;
}
