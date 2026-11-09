#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <stack>
#include <queue>
#include <list>
#include <numeric>
using namespace std;

class Lista {
    private:
    static constexpr int CAP=100;
    int datos[CAP]{};
    int n=0;
    public:
    int cantidad() const {
        return n;
}

void insertar(int valor,int posicion) {
    if(n==CAP) throw runtime_error("Estructura llena");
    if(posicion<0 || posicion>n) throw runtime_error("Posicion no valida");
    for(int i=n;i>posicion;--i) datos[i]=datos[i-1];
    datos[posicion]=valor; ++n;
}

int extraer(int posicion) {
    if(posicion<0 || posicion>=n) throw runtime_error("Vacia o posicion no valida");
    int valor=datos[posicion];
    for(int i=posicion;i<n-1;++i) datos[i]=datos[i+1];
    --n; return valor;
}

void mostrar() const {
    for(int i=0;i<n;++i) cout<<datos[i]<<" ";
    cout<<"\n";
}
};

int main(){
    Lista e;
    int opcion;
    while(true) {
        cout<<"1. Insertar  2. Extraer  3. Mostrar  4. Cantidad  0. Salir: ";
        if(!(cin>>opcion) || opcion==0) break;
        try {
            if(opcion==1) {
                int valor;
                cout<<"Valor: "; if(!(cin>>valor)) break;
                int posicion; cout<<"Posicion (desde 0): "; if(!(cin>>posicion)) break;
                e.insertar(valor, posicion);
            } else if(opcion==2) {
                int posicion; cout<<"Posicion: "; if(!(cin>>posicion)) break;
                int valor=e.extraer(posicion);
                cout<<"Extraido: "<<valor<<"\n";
            } else if(opcion==3) { e.mostrar(); }
            else if(opcion==4) cout<<"Cantidad: "<<e.cantidad()<<"\n";
            else cout<<"Opcion no valida\n";
        } catch(const exception& ex) { cout<<ex.what()<<"\n"; }
    }
}
