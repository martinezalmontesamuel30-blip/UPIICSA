#include <iostream>
#include <string>
using namespace std;

// PRACTICA 7 BIS: TAMANIOS EN POO
class Auto
{
private:
    float precio;
    int anio;
};

class Persona
{
private:
    string nombre, ap, am, genero;
    int edad;
};

class MostrarTamanios
{
public:
    void mostrar()
    {
        cout << "PRACTICA 7 BIS - TAMANIOS DE DATOS" << endl;
        cout << "char: " << sizeof(char) << " bytes" << endl;
        cout << "bool: " << sizeof(bool) << " bytes" << endl;
        cout << "short: " << sizeof(short) << " bytes" << endl;
        cout << "int: " << sizeof(int) << " bytes" << endl;
        cout << "long: " << sizeof(long) << " bytes" << endl;
        cout << "float: " << sizeof(float) << " bytes" << endl;
        cout << "double: " << sizeof(double) << " bytes" << endl;
        cout << "\nTIPOS CREADOS CON CLASES" << endl;
        cout << "Auto: " << sizeof(Auto) << " bytes" << endl;
        cout << "Persona: " << sizeof(Persona) << " bytes" << endl;
        cout << "Nota: el tamanio puede cambiar segun el compilador." << endl;
    }
};

int main()
{
    MostrarTamanios datos;
    datos.mostrar();
    return 0;
}
