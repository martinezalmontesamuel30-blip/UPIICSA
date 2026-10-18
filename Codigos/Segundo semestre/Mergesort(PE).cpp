void burbujaPE(const int claves[], int indices[], int n)
{
 for(int i = 0; i < n - 1; i++)
 {
 for(int j = 0; j < n - 1 - i; j++)
 {
 if(claves[indices[j]] > claves[indices[j + 1]])
 {
 int aux = indices[j];
 indices[j] = indices[j + 1];
 indices[j + 1] = aux;
 }
 }
 }
}
// POO: el mismo ordenamiento, pero dentro de una clase
class OrdenadorBurbuja
{
public:
 void ordenar(const int claves[], int indices[], int n)
 {
 for(int i = 0; i < n - 1; i++)
 {
 for(int j = 0; j < n - 1 - i; j++)
 {
 if(claves[indices[j]] > claves[indices[j + 1]])
 {
 int aux = indices[j];
 indices[j] = indices[j + 1];
 indices[j + 1] = aux;
 }
 }
 }
 }
};
int main()
{
 const int n = 5;
 int numeros[n] = {24, 8, 31, 12, 5};
 char letras[n] = {'Z', 'B', 'M', 'A', 'C'};
 Alumno alumnos[n] = {{"Ana", 20}, {"Luis", 18}, {"Mara", 22}, 
{"Jose", 19}, {"Eva", 17}};
 int clavesNumeros[n], clavesLetras[n], clavesAlumnos[n];
 int indices[n];
 for(int i = 0; i < n; i++)
 {
 clavesNumeros[i] = numeros[i];
 clavesLetras[i] = letras[i];
 clavesAlumnos[i] = alumnos[i].edad;
 }
 OrdenadorBurbuja objeto;
 cout << "ORDENAMIENTO INDIRECTO - BURBUJA" << endl;
 cout << "\nENTEROS:" << endl;
 iniciarIndices(indices, n);
 burbujaPE(clavesNumeros, indices, n);
 cout << "PE: "; mostrar(numeros, indices, n);
 iniciarIndices(indices, n);
 objeto.ordenar(clavesNumeros, indices, n);
 cout << "POO: "; mostrar(numeros, indices, n);
 cout << "\nCARACTERES:" << endl;
 iniciarIndices(indices, n);
 burbujaPE(clavesLetras, indices, n);
 cout << "PE: "; mostrar(letras, indices, n);
 iniciarIndices(indices, n);
 objeto.ordenar(clavesLetras, indices, n);
 cout << "POO: "; mostrar(letras, indices, n);
 cout << "\nALUMNOS ORDENADOS POR EDAD:" << endl;
 iniciarIndices(indices, n);
 burbujaPE(clavesAlumnos, indices, n);
 cout << "PE: "; mostrar(alumnos, indices, n);
 iniciarIndices(indices, n);
 objeto.ordenar(clavesAlumnos, indices, n);
 cout << "POO: "; mostrar(alumnos, indices, n);
 return 0;
}
