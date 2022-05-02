#include <stdio.h>
#include <iostream>
using namespace std;

// Implementar uma classe Matriz 2x2 que inclua um
// construtor por default, funções de acesso para acessar os
// atributos da matriz, uma função inversa(), que devolve o
// inverso da matriz, uma função det() que devolve o
// determinante da matriz e uma função visualizar.

class Matriz{
    private:
    double a,b,c,d;
    public:
    Matriz(double aa,double bb ,double cc, double dd){
        a=aa,b=bb,c=cc,d=dd;
    }
    double getA00(){
        return a;
    }
    double getA01(){
        return b;
    }
    double getA10(){
        return c;
    }
    double getA11(){
        return d;
    }
    double det(){
        return getA00()*getA11() - getA10()*getA01();
    }
    Matriz inversa(){
        double ai=getA11()/det();
        double bi=-getA01()/det();
        double ci=-getA10()/det();
        double di=getA00()/det();
        return Matriz(ai,bi,ci,di);
    }
    void imprimir(){
        cout << getA00() <<" " <<getA01()<<" " << "\n" << getA10() <<" "<< getA11() << endl;
    }
};

int main(){
    Matriz a(2,0, 1,1);
    cout << a.det()<<"\n";
    a.imprimir();
    a.inversa().imprimir();
}