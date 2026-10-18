#include <iostream>
using namespace std;

// PRACTICA 15: TRIANGULO DE SIERPINSKI Y POLVO DE CANTOR
class Fractales
{
private:
    char triangulo[32][64];
    char polvo[81][81];

    // Un triangulo se reemplaza por tres triangulos menores.
    void sierpinski(int nivel, int fila, int columna)
    {
        if(nivel == 0)
        {
            triangulo[fila][columna] = '*';
            return;
        }

        int salto = 1 << (nivel - 1);
        sierpinski(nivel - 1, fila, columna);
        sierpinski(nivel - 1, fila + salto, columna - salto);
        sierpinski(nivel - 1, fila + salto, columna + salto);
    }

    // El polvo de Cantor conserva las cuatro esquinas de un cuadrado.
    void cantor(int nivel, int fila, int columna, int tam)
    {
        if(nivel == 0)
        {
            polvo[fila][columna] = '#';
            return;
        }

        int tercio = tam / 3;
        cantor(nivel - 1, fila, columna, tercio);
        cantor(nivel - 1, fila, columna + 2 * tercio, tercio);
        cantor(nivel - 1, fila + 2 * tercio, columna, tercio);
        cantor(nivel - 1, fila + 2 * tercio, columna + 2 * tercio, tercio);
    }

public:
    void mostrarSierpinski(int nivel)
    {
        int alto = 1 << nivel;
        int ancho = alto * 2 - 1;

        for(int i = 0; i < 32; i++)
            for(int j = 0; j < 64; j++)
                triangulo[i][j] = ' ';

        sierpinski(nivel, 0, alto - 1);

        cout << "\nTRIANGULO DE SIERPINSKI" << endl;
        for(int i = 0; i < alto; i++)
        {
            for(int j = 0; j < ancho; j++)
                cout << triangulo[i][j];
            cout << endl;
        }
    }

    void mostrarCantor(int nivel)
    {
        int tam = 1;
        for(int i = 0; i < nivel; i++)
            tam *= 3;

        for(int i = 0; i < 81; i++)
            for(int j = 0; j < 81; j++)
                polvo[i][j] = ' ';

        cantor(nivel, 0, 0, tam);

        cout << "\nPOLVO DE CANTOR" << endl;
        for(int i = 0; i < tam; i++)
        {
            for(int j = 0; j < tam; j++)
                cout << polvo[i][j];
            cout << endl;
        }
    }
};

int main()
{
    Fractales figura;
    int opcion, nivel;

    do
    {
        cout << "\nPRACTICA 15 - FRACTALES RECURSIVOS" << endl;
        cout << "1. Triangulo de Sierpinski" << endl;
        cout << "2. Polvo de Cantor" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Nivel (0 a 5): ";
                cin >> nivel;
                if(nivel >= 0 && nivel <= 5)
                    figura.mostrarSierpinski(nivel);
                else
                    cout << "Nivel no valido" << endl;
                break;

            case 2:
                cout << "Nivel (0 a 3): ";
                cin >> nivel;
                if(nivel >= 0 && nivel <= 3)
                    figura.mostrarCantor(nivel);
                else
                    cout << "Nivel no valido" << endl;
                break;

            case 3:
                cout << "Fin del programa" << endl;
                break;

            default:
                cout << "Opcion no valida" << endl;
        }
    } while(opcion != 3);

    return 0;
}
