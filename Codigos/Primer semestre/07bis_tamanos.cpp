#include <iostream>
#include <string>
using namespace std;

struct Automovil {
    double precio;
    int anio;
};

class Persona {
public:
    string nombre;
    int edad;
};

int main() {
    cout << "Tamanos de tipos basicos:\n";
    cout << "char: " << sizeof(char) << " bytes\n";
    cout << "int: " << sizeof(int) << " bytes\n";
    cout << "float: " << sizeof(float) << " bytes\n";
    cout << "double: " << sizeof(double) << " bytes\n";
    cout << "bool: " << sizeof(bool) << " bytes\n";

    cout << "\nTamanos de tipos creados:\n";
    cout << "Automovil: " << sizeof(Automovil) << " bytes\n";
    cout << "Persona: " << sizeof(Persona) << " bytes\n";
    cout << "Nota: sizeof(string) mide el objeto string, no el texto dinamico.\n";
    return 0;
}
