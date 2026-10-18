#include <iostream>
using namespace std;

// PRACTICA 8: 5 NUMEROS SIN ARREGLO, EN POO
class Estadisticas
{
private:
    float a, b, c, d, e;

public:
    void capturar()
    {
        cout << "Ingresa el numero 1: "; cin >> a;
        cout << "Ingresa el numero 2: "; cin >> b;
        cout << "Ingresa el numero 3: "; cin >> c;
        cout << "Ingresa el numero 4: "; cin >> d;
        cout << "Ingresa el numero 5: "; cin >> e;
    }

    float suma()
    {
        return a + b + c + d + e;
    }

    float promedio()
    {
        return suma() / 5;
    }

    float maximo()
    {
        float mayor = a;
        if(b > mayor) mayor = b;
        if(c > mayor) mayor = c;
        if(d > mayor) mayor = d;
        if(e > mayor) mayor = e;
        return mayor;
    }

    float minimo()
    {
        float menor = a;
        if(b < menor) menor = b;
        if(c < menor) menor = c;
        if(d < menor) menor = d;
        if(e < menor) menor = e;
        return menor;
    }

    void mostrar()
    {
        cout << "\nSuma: " << suma() << endl;
        cout << "Promedio: " << promedio() << endl;
        cout << "Media aritmetica: " << promedio() << endl;
        cout << "Maximo: " << maximo() << endl;
        cout << "Minimo: " << minimo() << endl;
    }
};

int main()
{
    Estadisticas ejercicio;
    cout << "PRACTICA 8 - CINCO NUMEROS EN POO" << endl;
    ejercicio.capturar();
    ejercicio.mostrar();
    return 0;
}
