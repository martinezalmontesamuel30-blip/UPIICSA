#include <iostream>
using namespace std;

// PRACTICA 10: ACCESO INDIRECTO A ARREGLO CON PUNTERO, EN POO
class EstadisticasPunteros
{
private:
    float numeros[5];
    float *p;

public:
    EstadisticasPunteros()
    {
        p = numeros;
    }

    void capturar()
    {
        for(int i = 0; i < 5; i++)
        {
            cout << "Ingresa el numero " << i + 1 << ": ";
            cin >> *(p + i);
        }
    }

    float suma()
    {
        float total = 0;
        for(int i = 0; i < 5; i++)
            total += *(p + i);
        return total;
    }

    float promedio()
    {
        return suma() / 5;
    }

    float maximo()
    {
        float mayor = *p;
        for(int i = 1; i < 5; i++)
            if(*(p + i) > mayor) mayor = *(p + i);
        return mayor;
    }

    float minimo()
    {
        float menor = *p;
        for(int i = 1; i < 5; i++)
            if(*(p + i) < menor) menor = *(p + i);
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
    EstadisticasPunteros ejercicio;
    cout << "PRACTICA 10 - PUNTERO AL ARREGLO EN POO" << endl;
    ejercicio.capturar();
    ejercicio.mostrar();
    return 0;
}
