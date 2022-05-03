#include <stdio.h>
#include <iostream>

using namespace std;

class Retangulo{
    private:
    double base,altura;
    public:
    Retangulo(double b,double a){
        base=b;
        altura=a;
    }
    int getBase(){
        return base;
    }
    int getAltura(){
        return altura;
    }
    double perimetro(){
        return 2*base+2*altura;
    }
    double area(){
        return base*altura;
    }
};

class Quadrado: public Retangulo{
    public:
    Quadrado(int tam):Retangulo(tam){}
};

class TrapezioIsosceles: public Quadrado{
    public:
    TrapezioIsosceles()
};

int main(){

}