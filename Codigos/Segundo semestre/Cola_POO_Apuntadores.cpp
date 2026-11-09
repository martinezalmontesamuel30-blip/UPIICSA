#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <cstddef>
#include <new>

class Cola {
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
        explicit Nodo(int valor) : dato(valor), siguiente(nullptr) {}
    };

    Nodo* frente = nullptr;
    Nodo* final = nullptr;
    std::size_t total = 0;

public:
    Cola() = default;

    Cola(const Cola&) = delete;
    Cola& operator=(const Cola&) = delete;

    ~Cola() { vaciar(); }

    bool estaVacia() const { return frente == nullptr; }
    std::size_t cantidad() const { return total; }

    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            frente = nuevo;
        } else {
            final->siguiente = nuevo;
        }
        final = nuevo;
        ++total;
    }

    bool extraer(int& valor) {
        if (estaVacia()) return false;
        Nodo* eliminado = frente;
        valor = eliminado->dato;
        frente = frente->siguiente;
        if (frente == nullptr) final = nullptr;
        delete eliminado;
        --total;
        return true;
    }

    bool consultarFrente(int& valor) const {
        if (estaVacia()) return false;
        valor = frente->dato;
        return true;
    }

    void recorrer(const std::function<void(int)>& visitar) const {
        for (const Nodo* actual = frente; actual; actual = actual->siguiente) {
            visitar(actual->dato);
        }
    }

    void vaciar() {
        while (frente != nullptr) {
            Nodo* eliminado = frente;
            frente = frente->siguiente;
            delete eliminado;
        }
        final = nullptr;
        total = 0;
    }
};

class MenuCola {
private:
    Cola& cola;

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
        if (cola.estaVacia()) {
            std::cout << "Cola vacia.\n";
            return;
        }
        std::cout << "Frente: ";
        cola.recorrer([](int valor) { std::cout << "[" << valor << "] "; });
        std::cout << ": Final\n";
    }

public:
    explicit MenuCola(Cola& unaCola) : cola(unaCola) {}

    void ejecutar() {
        while (true) {
            std::cout << "\nCola con apuntadores\n"
                      << "1. Insertar\n"
                      << "2. Extraer\n"
                      << "3. Ver frente\n"
                      << "4. Mostrar\n"
                      << "5. Cantidad\n"
                      << "6. Vaciar\n"
                      << "0. Salir\n";
            int opcion;
            if (!leerEntero("Opcion: ", opcion)) return;
            int valor;
            switch (opcion) {
                case 1:
                    if (!leerEntero("Numero: ", valor)) return;
                    try {
                        cola.insertar(valor);
                        std::cout << "Insertado: " << valor << "\n";
                        mostrar();
                    } catch (const std::bad_alloc&) {
                        std::cout << "Sin memoria.\n";
                    }
                    break;
                case 2:
                    if (cola.extraer(valor)) {
                        std::cout << "Extraido: " << valor << "\n";
                        mostrar();
                    } else {
                        std::cout << "Cola vacia.\n";
                    }
                    break;
                case 3:
                    if (cola.consultarFrente(valor))
                        std::cout << "Primero: " << valor << "\n";
                    else
                        std::cout << "Cola vacia.\n";
                    break;
                case 4:
                    mostrar();
                    break;
                case 5:
                    std::cout << "Cantidad: " << cola.cantidad() << "\n";
                    break;
                case 6:
                    cola.vaciar();
                    std::cout << "Cola vacia.\n";
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
    Cola cola;
    MenuCola menu(cola);
    menu.ejecutar();
    return 0;
}
