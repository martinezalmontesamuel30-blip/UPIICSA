#include <iostream>
#include <string>
using namespace std;
// Nuevo tipo de dato creado por nosotros
struct Alumno
{
 string nombre;
 int edad;
};
// Los indices se ordenan, los datos originales NO se modifican.
void iniciarIndices(int indices[], int n)
{
 for(int i = 0; i < n; i++)
 indices[i] = i;
}
void mostrar(const int datos[], const int indices[], int n)
{
 for(int i = 0; i < n; i++)
 cout << datos[indices[i]] << " ";
 cout << endl;
}
void mostrar(const char datos[], const int indices[], int n)
{
 for(int i = 0; i < n; i++)
 cout << datos[indices[i]] << " ";
 cout << endl;
}
void mostrar(const Alumno datos[], const int indices[], int n)
{
 for(int i = 0; i < n; i++)
 cout << datos[indices[i]].nombre << "(" << 
datos[indices[i]].edad << ") ";
 cout << endl;
}
