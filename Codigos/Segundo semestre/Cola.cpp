#include <iostream>
#include <queue> // Libreria de cola ya hecha
using namespace std;

// Clase sencilla
class Cola
{
    private:
        queue<int> colaDatos;

    public:
        // Meter valor
        void agregar(int numero)
        {
            colaDatos.push(numero);
            cout << "Se agrego el numero: " << numero << endl;
        }

        // Quitar valor
        void quitar()
        {
            if(colaDatos.empty())
            {
                cout << "La cola esta vacia" << endl;
            }
            else
            {
                cout << "Se quito el numero: " << colaDatos.front() << endl;
                colaDatos.pop();
            }
        }

        // Ver el primero
        void verFrente()
        {
            if(colaDatos.empty())
            {
                cout << "Sin elementos en la cola" << endl;
            }
            else
            {
                cout << "El primero es: " << colaDatos.front() << endl;
            }
        }
};

// Main con menu simple
int main()
{
    Cola miCola;
    int opcion, valor;

    do
    {
        cout << "\n==== MENU COLA (LIBRERIA) ====" << endl;
        cout << "1. Agregar a la cola" << endl;
        cout << "2. Quitar de la cola" << endl;
        cout << "3. Ver el primero" << endl;
        cout << "4. Salir" << endl;
        cout << "Escribe la opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Numero a agregar: ";
                cin >> valor;
                miCola.agregar(valor);
                break;
            case 2:
                miCola.quitar();
                break;
            case 3:
                miCola.verFrente();
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
