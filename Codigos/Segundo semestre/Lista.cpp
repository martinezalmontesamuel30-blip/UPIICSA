#include <iostream>
#include <list> // Libreria de lista ya hecha
#include <iterator>
using namespace std;

// Clase sencilla
class Lista
{
    private:
        list<int> listaDatos;

    public:
        // Meter valor en una posicion
        void agregar(int numero, int posicion)
        {
            if(posicion < 1 || posicion > (int)listaDatos.size() + 1)
            {
                cout << "Posicion incorrecta" << endl;
            }
            else
            {
                list<int>::iterator it = listaDatos.begin();
                advance(it, posicion - 1);
                listaDatos.insert(it, numero);
                cout << "Se agrego el numero: " << numero << endl;
            }
        }

        // Quitar valor de una posicion
        void quitar(int posicion)
        {
            if(posicion < 1 || posicion > (int)listaDatos.size())
            {
                cout << "Posicion incorrecta" << endl;
            }
            else
            {
                list<int>::iterator it = listaDatos.begin();
                advance(it, posicion - 1);
                cout << "Se quito el numero: " << *it << endl;
                listaDatos.erase(it);
            }
        }

        // Mostrar todos los valores
        void mostrar()
        {
            if(listaDatos.empty())
            {
                cout << "La lista esta vacia" << endl;
            }
            else
            {
                cout << "Elementos: ";
                for(int numero : listaDatos)
                {
                    cout << numero << " ";
                }
                cout << endl;
            }
        }

        // Contar elementos
        void contar()
        {
            cout << "Total de elementos: " << listaDatos.size() << endl;
        }
};

// Main con menu simple
int main()
{
    Lista miLista;
    int opcion, valor, posicion;

    do
    {
        cout << "\n==== MENU LISTA (LIBRERIA) ====" << endl;
        cout << "1. Agregar a la lista" << endl;
        cout << "2. Quitar de la lista" << endl;
        cout << "3. Mostrar lista" << endl;
        cout << "4. Contar elementos" << endl;
        cout << "5. Salir" << endl;
        cout << "Escribe la opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Numero a agregar: ";
                cin >> valor;
                cout << "Posicion: ";
                cin >> posicion;
                miLista.agregar(valor, posicion);
                break;
            case 2:
                cout << "Posicion a quitar: ";
                cin >> posicion;
                miLista.quitar(posicion);
                break;
            case 3:
                miLista.mostrar();
                break;
            case 4:
                miLista.contar();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
        }

    }while(opcion != 5);

    return 0;
}
