#include <iostream>
#include <string>
using namespace std;

// PRACTICA 12: PARTIENDO DE LA PRACTICA 7, CREAR LISTAS
class Persona
{
private:
    string nombre, ap, am, genero;
    int edad;

public:
    void capturar()
    {
        cout << "Nombre: "; cin >> nombre;
        cout << "Apellido paterno: "; cin >> ap;
        cout << "Apellido materno: "; cin >> am;
        cout << "Genero: "; cin >> genero;
        cout << "Edad: "; cin >> edad;
    }

    void mostrar()
    {
        cout << nombre << " " << ap << " " << am
             << " - Genero: " << genero << " - Edad: " << edad << endl;
    }
};

class Auto
{
private:
    float precio;
    int anio;

public:
    void capturar()
    {
        cout << "Precio: "; cin >> precio;
        cout << "Anio: "; cin >> anio;
    }

    void mostrar()
    {
        cout << "Precio: " << precio << " - Anio: " << anio << endl;
    }
};

class ListaDatos
{
private:
    Persona personas[3];
    Auto autos[3];

public:
    void capturar()
    {
        for(int i = 0; i < 3; i++)
        {
            cout << "\nPERSONA " << i + 1 << endl;
            personas[i].capturar();
        }
        for(int i = 0; i < 3; i++)
        {
            cout << "\nAUTO " << i + 1 << endl;
            autos[i].capturar();
        }
    }

    void mostrar()
    {
        cout << "\nLISTA DE PERSONAS" << endl;
        for(int i = 0; i < 3; i++)
            personas[i].mostrar();

        cout << "\nLISTA DE AUTOS" << endl;
        for(int i = 0; i < 3; i++)
            autos[i].mostrar();
    }
};

int main()
{
    ListaDatos lista;
    cout << "PRACTICA 12 - ARREGLOS DE OBJETOS" << endl;
    lista.capturar();
    lista.mostrar();
    return 0;
}
