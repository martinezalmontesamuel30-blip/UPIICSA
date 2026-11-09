#include <iostream>
#include <string>

using namespace std;

struct Alumno {
    string nombre;
    int edad;
};

void iniciarIndices(int indices[], int n) {
    for (int i = 0; i < n; ++i) indices[i] = i;
}

void mostrar(const int datos[], const int indices[], int n) {
    for (int i = 0; i < n; ++i) cout << datos[indices[i]] << " ";
    cout << endl;
}

void mostrar(const char datos[], const int indices[], int n) {
    for (int i = 0; i < n; ++i) cout << datos[indices[i]] << " ";
    cout << endl;
}

void mostrar(const Alumno datos[], const int indices[], int n) {
    for (int i = 0; i < n; ++i)
        cout << datos[indices[i]].nombre << "(" << datos[indices[i]].edad << ") ";
    cout << endl;
}

void fusionar(const int claves[], int indices[], int auxiliar[],
              int inicio, int medio, int fin) {
    int i = inicio;
    int j = medio + 1;
    int k = inicio;

    while (i <= medio && j <= fin) {
        if (claves[indices[i]] <= claves[indices[j]])
            auxiliar[k++] = indices[i++];
        else
            auxiliar[k++] = indices[j++];
    }
    while (i <= medio) auxiliar[k++] = indices[i++];
    while (j <= fin) auxiliar[k++] = indices[j++];
    for (int posicion = inicio; posicion <= fin; ++posicion)
        indices[posicion] = auxiliar[posicion];
}

void mergeSortPE(const int claves[], int indices[], int auxiliar[],
                 int inicio, int fin) {
    if (inicio >= fin) return;
    const int medio = inicio + (fin - inicio) / 2;
    mergeSortPE(claves, indices, auxiliar, inicio, medio);
    mergeSortPE(claves, indices, auxiliar, medio + 1, fin);
    fusionar(claves, indices, auxiliar, inicio, medio, fin);
}

void ordenarPE(const int claves[], int indices[], int n) {
    if (n < 2) return;
    int* auxiliar = new int[n];
    mergeSortPE(claves, indices, auxiliar, 0, n - 1);
    delete[] auxiliar;
}

class OrdenadorMerge {
private:
    void mergeSort(const int claves[], int indices[], int auxiliar[],
                   int inicio, int fin) {
        if (inicio >= fin) return;
        const int medio = inicio + (fin - inicio) / 2;
        mergeSort(claves, indices, auxiliar, inicio, medio);
        mergeSort(claves, indices, auxiliar, medio + 1, fin);
        fusionar(claves, indices, auxiliar, inicio, medio, fin);
    }

public:
    void ordenar(const int claves[], int indices[], int n) {
        if (n < 2) return;
        int* auxiliar = new int[n];
        mergeSort(claves, indices, auxiliar, 0, n - 1);
        delete[] auxiliar;
    }
};

int main() {
    const int n = 5;
    int numeros[n] = {24, 8, 31, 12, 5};
    char letras[n] = {'Z', 'B', 'M', 'A', 'C'};
    Alumno alumnos[n] = {
        {"Ana", 20}, {"Luis", 18}, {"Mara", 22}, {"Jose", 19}, {"Eva", 17}
    };
    int clavesNumeros[n], clavesLetras[n], clavesAlumnos[n];
    int indices[n];

    for (int i = 0; i < n; ++i) {
        clavesNumeros[i] = numeros[i];
        clavesLetras[i] = letras[i];
        clavesAlumnos[i] = alumnos[i].edad;
    }

    OrdenadorMerge objeto;
    cout << "ORDENAMIENTO INDIRECTO - MERGE SORT" << endl;

    cout << "\nENTEROS:" << endl;
    iniciarIndices(indices, n);
    ordenarPE(clavesNumeros, indices, n);
    cout << "PE: ";
    mostrar(numeros, indices, n);
    iniciarIndices(indices, n);
    objeto.ordenar(clavesNumeros, indices, n);
    cout << "POO: ";
    mostrar(numeros, indices, n);

    cout << "\nCARACTERES:" << endl;
    iniciarIndices(indices, n);
    ordenarPE(clavesLetras, indices, n);
    cout << "PE: ";
    mostrar(letras, indices, n);
    iniciarIndices(indices, n);
    objeto.ordenar(clavesLetras, indices, n);
    cout << "POO: ";
    mostrar(letras, indices, n);

    cout << "\nALUMNOS ORDENADOS POR EDAD:" << endl;
    iniciarIndices(indices, n);
    ordenarPE(clavesAlumnos, indices, n);
    cout << "PE: ";
    mostrar(alumnos, indices, n);
    iniciarIndices(indices, n);
    objeto.ordenar(clavesAlumnos, indices, n);
    cout << "POO: ";
    mostrar(alumnos, indices, n);

    return 0;
}
