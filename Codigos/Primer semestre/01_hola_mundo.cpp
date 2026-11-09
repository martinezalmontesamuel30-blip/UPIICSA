#include <iostream>
using namespace std;

class Saludo {
public:
    void mostrar() {
        cout << "Hola mundo desde C++ con POO\n";
    }
};

int main() {
    Saludo mensaje;
    mensaje.mostrar();
    return 0;
}
