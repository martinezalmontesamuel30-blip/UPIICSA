#include <iostream>
#include <stack> // Libreria de la pila ya hecha
using namespace std;

// Clase sencilla
class Pila
{
    private:
        stack<int> pilaDatos;

    public:
        // Meter valor
        void agregar(int numero)
        {
            pilaDatos.push(numero);
            cout << "Se metio el numero: " << numero << endl;
        }

        // Quitar valor
        void quitar()
        {
            if(pilaDatos.empty())
            {
                cout << "La pila esta vacia" << endl;
            }
            else
            {
                cout << "Se quito el numero: " << pilaDatos.top() << endl;
                pilaDatos.pop();
            }
        }

        // Ver el tope
        void verTope()
        {
            if(pilaDatos.empty())
            {
                cout << "Sin elementos en la pila" << endl;
            }
            else
            {
                cout << "El tope es: " << pilaDatos.top() << endl;
            }
        }
};

// Main con menu simple
int main()
{
    Pila miPila;
    int opcion, valor;

    do
    {
        cout << "\n==== MENU PILA (LIBRERIA) ====" << endl;
        cout << "1. Agregar a la pila" << endl;
        cout << "2. Quitar de la pila" << endl;
        cout << "3. Ver el tope" << endl;
        cout << "4. Salir" << endl;
        cout << "Escribe la opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Numero a agregar: ";
                cin >> valor;
                miPila.agregar(valor);
                break;
            case 2:
                miPila.quitar();
                break;
            case 3:
                miPila.verTope();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
        }

    }while(opcion != 4);

    return 0;
}
