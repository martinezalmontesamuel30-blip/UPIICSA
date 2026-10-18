#include <iostream>
using namespace std;

// PRACTICA 9: 5 NUMEROS EN UN ARREGLO, EN POO
class EstadisticasArreglo
{
private:
    float numeros[5];

public:
    void capturar()
    {
        for(int i = 0; i < 5; i++)
        {
            cout << "Ingresa el numero " << i + 1 << ": ";
            cin >> numeros[i];
        }
    }

    float suma()
    {
        float total = 0;
        for(int i = 0; i < 5; i++)
            total += numeros[i];
        return total;
    }

    float promedio()
    {
        return suma() / 5;
    }

    float maximo()
    {
        float mayor = numeros[0];
        for(int i = 1; i < 5; i++)
            if(numeros[i] > mayor) mayor = numeros[i];
        return mayor;
    }

    float minimo()
    {
        float menor = numeros[0];
        for(int i = 1; i < 5; i++)
            if(numeros[i] < menor) menor = numeros[i];
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
    EstadisticasArreglo ejercicio;
    cout << "PRACTICA 9 - ARREGLO EN POO" << endl;
    ejercicio.capturar();
    ejercicio.mostrar();
    return 0;
}
