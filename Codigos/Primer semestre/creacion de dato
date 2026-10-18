#include <iostream>
#include <string>
using namespace std;

// PRACTICA 7: NUEVOS TIPOS DE DATO EN POO
class Auto
{
private:
    float precio;
    int anio;

public:
    void capturar()
    {
        cout << "Precio del auto: ";
        cin >> precio;
        cout << "Anio del auto: ";
        cin >> anio;
    }

    void mostrar()
    {
        cout << "Precio: " << precio << endl;
        cout << "Anio: " << anio << endl;
    }
};

class Persona
{
private:
    string nombre, ap, am, genero;
    int edad;

public:
    void capturar()
    {
        cout << "Nombre (sin espacios): ";
        cin >> nombre;
        cout << "Apellido paterno: ";
        cin >> ap;
        cout << "Apellido materno: ";
        cin >> am;
        cout << "Genero: ";
        cin >> genero;
        cout << "Edad: ";
        cin >> edad;
    }

    void mostrar()
    {
        cout << "Nombre: " << nombre << " " << ap << " " << am << endl;
        cout << "Genero: " << genero << endl;
        cout << "Edad: " << edad << endl;
    }
};

int main()
{
    Auto auto1;
    Persona persona1;

    cout << "PRACTICA 7 - CLASE AUTO" << endl;
    auto1.capturar();
    cout << "\nDATOS DEL AUTO" << endl;
    auto1.mostrar();

    cout << "\nPRACTICA 7 - CLASE PERSONA" << endl;
    persona1.capturar();
    cout << "\nDATOS DE LA PERSONA" << endl;
    persona1.mostrar();
    return 0;
}
