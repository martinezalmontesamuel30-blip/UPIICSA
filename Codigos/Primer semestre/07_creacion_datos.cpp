#include <iostream>
#include <string>
using namespace std;

struct Automovil {
    double precio;
    int anio;
};

class Persona {
public:
    string nombre, apellidoPaterno, apellidoMaterno, genero;
    int edad;

    void mostrar() const {
        cout << "Nombre: " << nombre << " " << apellidoPaterno << " "
             << apellidoMaterno << "\nGenero: " << genero
             << "\nEdad: " << edad << "\n";
    }
};

int main() {
    Persona p;
    Automovil auto1;

    cout << "Nombre: "; cin >> p.nombre;
    cout << "Apellido paterno: "; cin >> p.apellidoPaterno;
    cout << "Apellido materno: "; cin >> p.apellidoMaterno;
    cout << "Genero: "; cin >> p.genero;
    cout << "Edad: "; cin >> p.edad;

    cout << "Precio del automovil: "; cin >> auto1.precio;
    cout << "Anio del automovil: "; cin >> auto1.anio;

    cout << "\nDatos de la persona:\n";
    p.mostrar();
    cout << "Automovil: $" << auto1.precio << ", anio " << auto1.anio << "\n";
    return 0;
}
