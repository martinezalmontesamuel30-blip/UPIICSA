#include <iostream>
using namespace std;

// Clase que administra la pila
class Pila {
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;

        Nodo(int valor, Nodo* sig) {
            dato = valor;
            siguiente = sig;
        }
    };

    Nodo* cima;
    int cantidadElementos;

public:
    Pila() {
        cima = nullptr;
        cantidadElementos = 0;
    }

    // Insertar un elemento
    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor, cima);
        cima = nuevo;
        cantidadElementos++;
    }

    // Extraer el elemento de la cima
    bool extraer(int& valor) {
        if (cima == nullptr)
            return false;

        Nodo* auxiliar = cima;
        valor = cima->dato;
        cima = cima->siguiente;

        delete auxiliar;
        cantidadElementos--;
        return true;
    }

    // Consultar la cima sin eliminarla
    bool consultarCima(int& valor) {
        if (cima == nullptr)
            return false;

        valor = cima->dato;
        return true;
    }

    bool estaVacia() {
        return cima == nullptr;
    }

    int cantidad() {
        return cantidadElementos;
    }

    // Mostrar los elementos
    void mostrar() {
        Nodo* actual = cima;

        while (actual != nullptr) {
            cout << actual->dato << endl;
            actual = actual->siguiente;
        }
    }

    // Liberar la memoria
    void vaciar() {
        while (cima != nullptr) {
            Nodo* auxiliar = cima;
            cima = cima->siguiente;
            delete auxiliar;
        }

        cantidadElementos = 0;
    }

    ~Pila() {
        vaciar();
    }

    // Evitar copias incorrectas de la pila
    Pila(const Pila&) = delete;
    Pila& operator=(const Pila&) = delete;
};

// Clase encargada del menú
class MenuPila {
private:
    Pila& pila;

public:
    MenuPila(Pila& unaPila) : pila(unaPila) {}

    void ejecutar() {
        int opcion, valor;

        do {
            cout << "\n--- MENU DE PILA ---\n";
            cout << "1. Insertar\n";
            cout << "2. Extraer\n";
            cout << "3. Consultar cima\n";
            cout << "4. Mostrar pila\n";
            cout << "5. Cantidad de elementos\n";
            cout << "6. Vaciar pila\n";
            cout << "0. Salir\n";
            cout << "Opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Numero: ";
                    cin >> valor;
                    pila.insertar(valor);
                    cout << "Elemento insertado.\n";
                    break;

                case 2:
                    if (pila.extraer(valor))
                        cout << "Extraido: " << valor << endl;
                    else
                        cout << "La pila esta vacia.\n";
                    break;

                case 3:
                    if (pila.consultarCima(valor))
                        cout << "Cima: " << valor << endl;
                    else
                        cout << "La pila esta vacia.\n";
                    break;

                case 4:
                    if (pila.estaVacia())
                        cout << "La pila esta vacia.\n";
                    else
                        pila.mostrar();
                    break;

                case 5:
                    cout << "Elementos: "
                         << pila.cantidad() << endl;
                    break;

                case 6:
                    pila.vaciar();
                    cout << "Pila vaciada.\n";
                    break;

                case 0:
                    cout << "Fin del programa.\n";
                    break;

                default:
                    cout << "Opcion no valida.\n";
            }

        } while (opcion != 0);
    }
};

int main() {
    Pila pila;
    MenuPila menu(pila);

    menu.ejecutar();

    return 0;
}
