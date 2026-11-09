#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;
};

int main() {
    Persona personas[3];
    Persona *p = personas;

    for (int i = 0; i < 3; i++) {
        cout << "Nombre de la persona " << i + 1 << ": ";
        cin >> (p + i)->nombre;
        cout << "Edad: ";
        cin >> (p + i)->edad;
    }

    cout << "\nDatos almacenados mediante el apuntador:\n";
    for (int i = 0; i < 3; i++) {
        cout << (p + i)->nombre << " - " << (p + i)->edad << " anios\n";
    }
    return 0;
}
