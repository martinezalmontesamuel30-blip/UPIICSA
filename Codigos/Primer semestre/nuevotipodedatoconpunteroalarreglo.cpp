#include <iostream>
#include <string>
using namespace std;

// PRACTICA 13: ACCEDER INDIRECTAMENTE A LAS LISTAS DE LA PRACTICA 12
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

class ListaIndirecta
{
private:
    Persona personas[3];
    Auto autos[3];
    Persona *pPersonas;
    Auto *pAutos;

public:
    ListaIndirecta()
    {
        pPersonas = personas;
        pAutos = autos;
    }

    void capturar()
    {
        for(int i = 0; i < 3; i++)
        {
            cout << "\nPERSONA " << i + 1 << endl;
            (pPersonas + i)->capturar();
        }
        for(int i = 0; i < 3; i++)
        {
            cout << "\nAUTO " << i + 1 << endl;
            (pAutos + i)->capturar();
        }
    }

    void mostrar()
    {
        cout << "\nLISTA DE PERSONAS MEDIANTE PUNTERO" << endl;
        for(int i = 0; i < 3; i++)
            (pPersonas + i)->mostrar();

        cout << "\nLISTA DE AUTOS MEDIANTE PUNTERO" << endl;
        for(int i = 0; i < 3; i++)
            (pAutos + i)->mostrar();
    }
};

int main()
{
    ListaIndirecta lista;
    cout << "PRACTICA 13 - ACCESO INDIRECTO CON PUNTEROS" << endl;
    lista.capturar();
    lista.mostrar();
    return 0;
}
