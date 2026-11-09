#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <cstddef>
#include <new>

class ListaEnlazada {
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
        explicit Nodo(int valor) : dato(valor), siguiente(nullptr) {}
    };

    Nodo* cabeza = nullptr;
    std::size_t total = 0;

public:
    ListaEnlazada() = default;

    ListaEnlazada(const ListaEnlazada&) = delete;
    ListaEnlazada& operator=(const ListaEnlazada&) = delete;

    ~ListaEnlazada() { vaciar(); }

    bool estaVacia() const { return cabeza == nullptr; }
    std::size_t cantidad() const { return total; }

    // Inserta al final de la lista
    void insertarAlFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            cabeza = nuevo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        ++total;
    }

    // Inserta al inicio de la lista
    void insertarAlInicio(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        ++total;
    }

    // Elimina la primera ocurrencia del valor dado
    bool eliminar(int valor) {
        if (estaVacia()) return false;

        if (cabeza->dato == valor) {
            Nodo* eliminado = cabeza;
            cabeza = cabeza->siguiente;
            delete eliminado;
            --total;
            return true;
        }

        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato != valor) {
            actual = actual->siguiente;
        }

        if (actual->siguiente == nullptr) return false;

        Nodo* eliminado = actual->siguiente;
        actual->siguiente = eliminado->siguiente;
        delete eliminado;
        --total;
        return true;
    }

    bool buscar(int valor) const {
        for (const Nodo* actual = cabeza; actual; actual = actual->siguiente) {
            if (actual->dato == valor) return true;
        }
        return false;
    }

    void recorrer(const std::function<void(int)>& visitar) const {
        for (const Nodo* actual = cabeza; actual; actual = actual->siguiente) {
            visitar(actual->dato);
        }
    }

    void vaciar() {
        while (cabeza != nullptr) {
            Nodo* eliminado = cabeza;
            cabeza = cabeza->siguiente;
            delete eliminado;
        }
        total = 0;
    }
};

class MenuLista {
private:
    ListaEnlazada& lista;

    bool leerEntero(const std::string& mensaje, int& numero) {
        std::string linea;
        while (true) {
            std::cout << mensaje;
            if (!std::getline(std::cin, linea)) return false;
            std::istringstream entrada(linea);
            char sobrante;
            if ((entrada >> numero) && !(entrada >> sobrante)) return true;
            std::cout << "Dato invalido.\n";
        }
    }

    void mostrar() const {
        if (lista.estaVacia()) {
            std::cout << "Lista vacia.\n";
            return;
        }
        std::cout << "Cabecera -> ";
        lista.recorrer([](int valor) { std::cout << "[" << valor << "] -> "; });
        std::cout << "nullptr\n";
    }

public:
    explicit MenuLista(ListaEnlazada& unaLista) : lista(unaLista) {}

    void ejecutar() {
        while (true) {
            std::cout << "\nLista Enlazada Simple\n"
                      << "1. Insertar al inicio\n"
                      << "2. Insertar al final\n"
                      << "3. Eliminar elemento\n"
                      << "4. Buscar elemento\n"
                      << "5. Mostrar lista\n"
                      << "6. Cantidad de elementos\n"
                      << "7. Vaciar lista\n"
                      << "0. Salir\n";
            int opcion;
            if (!leerEntero("Opcion: ", opcion)) return;
            int valor;
            switch (opcion) {
                case 1:
                    if (!leerEntero("Numero: ", valor)) return;
                    try {
                        lista.insertarAlInicio(valor);
                        std::cout << "Insertado al inicio: " << valor << "\n";
                        mostrar();
                    } catch (const std::bad_alloc&) {
                        std::cout << "Sin memoria.\n";
                    }
                    break;
                case 2:
                    if (!leerEntero("Numero: ", valor)) return;
                    try {
                        lista.insertarAlFinal(valor);
                        std::cout << "Insertado al final: " << valor << "\n";
                        mostrar();
                    } catch (const std::bad_alloc&) {
                        std::cout << "Sin memoria.\n";
                    }
                    break;
                case 3:
                    if (!leerEntero("Numero a eliminar: ", valor)) return;
                    if (lista.eliminar(valor)) {
                        std::cout << "Eliminado: " << valor << "\n";
                        mostrar();
                    } else {
                        std::cout << "Elemento no encontrado o lista vacia.\n";
                    }
                    break;
                case 4:
                    if (!leerEntero("Numero a buscar: ", valor)) return;
                    if (lista.buscar(valor))
                        std::cout << "El elemento " << valor << " SI se encuentra en la lista.\n";
                    else
                        std::cout << "El elemento " << valor << " NO esta en la lista.\n";
                    break;
                case 5:
                    mostrar();
                    break;
                case 6:
                    std::cout << "Cantidad de elementos: " << lista.cantidad() << "\n";
                    break;
                case 7:
                    lista.vaciar();
                    std::cout << "Lista vaciada.\n";
                    break;
                case 0:
                    return;
                default:
                    std::cout << "Opcion invalida.\n";
            }
        }
    }
};

int main() {
    ListaEnlazada lista;
    MenuLista menu(lista);
    menu.ejecutar();
    return 0;
}
