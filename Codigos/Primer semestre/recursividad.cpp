#include <iostream>
using namespace std;

// PRACTICA 14: FACTORIAL, FIBONACCI Y CALCULADORA RECURSIVA
class Recursividad
{
public:
    int factorial(int n)
    {
        if(n == 0) return 1;
        return n * factorial(n - 1);
    }

    int fibonacci(int n)
    {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    // Multiplicar por sumas sucesivas recursivas
    int multiplicar(int a, int b)
    {
        if(b == 0) return 0;
        return a + multiplicar(a, b - 1);
    }

    // Potencia por multiplicaciones sucesivas recursivas
    int potencia(int a, int b)
    {
        if(b == 0) return 1;
        return multiplicar(a, potencia(a, b - 1));
    }

    // Division por restas sucesivas recursivas
    int dividir(int a, int b)
    {
        if(a < b) return 0;
        return 1 + dividir(a - b, b);
    }
};

int main()
{
    Recursividad calc;
    int opcion, a, b;

    do
    {
        cout << "\nPRACTICA 14 - RECURSIVIDAD" << endl;
        cout << "1. Factorial" << endl;
        cout << "2. Fibonacci" << endl;
        cout << "3. Multiplicacion recursiva" << endl;
        cout << "4. Potencia recursiva" << endl;
        cout << "5. Division recursiva" << endl;
        cout << "6. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Ingresa n (de 0 a 12): "; cin >> a;
                if(a >= 0 && a <= 12)
                    cout << "Factorial: " << calc.factorial(a) << endl;
                else
                    cout << "Numero fuera del rango" << endl;
                break;

            case 2:
                cout << "Ingresa n (de 0 a 30): "; cin >> a;
                if(a >= 0 && a <= 30)
                    cout << "Fibonacci: " << calc.fibonacci(a) << endl;
                else
                    cout << "Numero fuera del rango" << endl;
                break;

            case 3:
                cout << "Ingresa dos enteros no negativos: ";
                cin >> a >> b;
                if(a >= 0 && b >= 0)
                    cout << "Resultado: " << calc.multiplicar(a, b) << endl;
                else
                    cout << "Solo se aceptan enteros no negativos" << endl;
                break;

            case 4:
                cout << "Ingresa base y exponente no negativos: ";
                cin >> a >> b;
                if(a >= 0 && b >= 0)
                    cout << "Resultado: " << calc.potencia(a, b) << endl;
                else
                    cout << "Solo se aceptan enteros no negativos" << endl;
                break;

            case 5:
                cout << "Ingresa dividendo y divisor positivos: ";
                cin >> a >> b;
                if(a >= 0 && b > 0)
                    cout << "Cociente entero: " << calc.dividir(a, b) << endl;
                else
                    cout << "Dividendo >= 0 y divisor > 0" << endl;
                break;

            case 6:
                cout << "Fin del programa" << endl;
                break;

            default:
                cout << "Opcion no valida" << endl;
        }
    } while(opcion != 6);

    return 0;
}
