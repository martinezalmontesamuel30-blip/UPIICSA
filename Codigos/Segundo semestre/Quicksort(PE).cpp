int particionPE(const int claves[], int indices[], int izq, int 
der)
{
 int pivote = claves[indices[der]];
 int i = izq - 1;
 for(int j = izq; j < der; j++)
 {
 if(claves[indices[j]] <= pivote)
 {
 i++;
 int aux = indices[i];
 indices[i] = indices[j];
 indices[j] = aux;
 }
 }
 int aux = indices[i + 1];
 indices[i + 1] = indices[der];
 indices[der] = aux;
 return i + 1;
}
void quickPE(const int claves[], int indices[], int izq, int der)
{
 if(izq < der)
 {
 int p = particionPE(claves, indices, izq, der);
 quickPE(claves, indices, izq, p - 1);
 quickPE(claves, indices, p + 1, der);
 }
}
// POO: quick sort dentro de una clase
class OrdenadorQuick
{
private:
 int particion(const int claves[], int indices[], int izq, int 
der)
 {
 int pivote = claves[indices[der]];
 int i = izq - 1;
 for(int j = izq; j < der; j++)
 {
 if(claves[indices[j]] <= pivote)
 {
 i++;
 int aux = indices[i];
 indices[i] = indices[j];
 indices[j] = aux;
 }
 }
 int aux = indices[i + 1];
 indices[i + 1] = indices[der];
 indices[der] = aux;
 return i + 1;
 }
 void quick(const int claves[], int indices[], int izq, int 
der)
 {
 if(izq < der)
 {
 int p = particion(claves, indices, izq, der);
 quick(claves, indices, izq, p - 1);
 quick(claves, indices, p + 1, der);
 }
 }
public:
 void ordenar(const int claves[], int indices[], int n)
 {
 quick(claves, indices, 0, n - 1);
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
 OrdenadorQuick objeto;
 cout << "ORDENAMIENTO INDIRECTO - QUICK SORT" << endl;
 cout << "\nENTEROS:" << endl;
 iniciarIndices(indices, n);
 quickPE(clavesNumeros, indices, 0, n - 1);
 cout << "PE: "; mostrar(numeros, indices, n);
 iniciarIndices(indices, n);
 objeto.ordenar(clavesNumeros, indices, n);
 cout << "POO: "; mostrar(numeros, indices, n);
 cout << "\nCARACTERES:" << endl;
 iniciarIndices(indices, n);
 quickPE(clavesLetras, indices, 0, n - 1);
 cout << "PE: "; mostrar(letras, indices, n);
 iniciarIndices(indices, n);
 objeto.ordenar(clavesLetras, indices, n);
 cout << "POO: "; mostrar(letras, indices, n);
 cout << "\nALUMNOS ORDENADOS POR EDAD:" << endl;
 iniciarIndices(indices, n);
 quickPE(clavesAlumnos, indices, 0, n - 1);
 cout << "PE: "; mostrar(alumnos, indices, n);
 iniciarIndices(indices, n);
 objeto.ordenar(clavesAlumnos, indices, n);
 cout << "POO: "; mostrar(alumnos, indices, n);
 return 0;
}
