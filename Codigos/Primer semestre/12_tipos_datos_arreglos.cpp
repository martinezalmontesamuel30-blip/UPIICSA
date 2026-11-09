#include <iostream>
#include <string>
using namespace std;

struct Automovil {
    string marca;
    double precio;
    int anio;
};

class Persona {
public:
    string nombre;
    int edad;
};

int main() {
    Persona personas[2];
    Automovil autos[2];

    cout << "Datos de 2 personas:\n";
    for (int i = 0; i < 2; i++) {
        cout << "Nombre: "; cin >> personas[i].nombre;
        cout << "Edad: "; cin >> personas[i].edad;
    }

    cout << "\nDatos de 2 automoviles:\n";
    for (int i = 0; i < 2; i++) {
        cout << "Marca: "; cin >> autos[i].marca;
        cout << "Precio: "; cin >> autos[i].precio;
        cout << "Anio: "; cin >> autos[i].anio;
    }

    cout << "\nPersonas:\n";
    for (int i = 0; i < 2; i++)
        cout << personas[i].nombre << ", " << personas[i].edad << " anios\n";

    cout << "\nAutomoviles:\n";
    for (int i = 0; i < 2; i++)
        cout << autos[i].marca << ", $" << autos[i].precio
             << ", " << autos[i].anio << "\n";

    return 0;
}
