#include <iostream>
#include <cmath>
using namespace std;

class PoligoRegular
{
private:
    int lados;
    double comprimento;

public:
    PoligoRegular(int a, int b)
    { // Construtor
        lados = a;
        comprimento = b;
    }
    PoligoRegular()
    { // Construtor
        lados = 1;
        comprimento = 0;
    }
    int angulo()
    { // Metodos dos angulos
        return 180 * (lados - 1);
    }
    int perimetro()
    { // Metodo do perimetro
        return lados * comprimento;
    }
    int get_comprimento() {
        return comprimento;
    }
    int get_lado(){
        return lados;
    }
    int set_lado(int pLado){
        return lados = pLado;
    }
    double set_comprimento(double pComp){
        return comprimento=pComp;
    }
};

class Triangulo:public PoligoRegular{
    public :
        Triangulo(int comprimento) : PoligoRegular(3, comprimento){};
        Triangulo() : PoligoRegular{3, 0}{};
        double area()
        {
            int comprimento = get_comprimento();
            return comprimento*comprimento*sqrt(3)/4;
        }
};

class Quadrado:public PoligoRegular{
    public :
        Quadrado(int comprimento) : PoligoRegular(4, comprimento){};
        Quadrado() : PoligoRegular{4, 0}{};
        int area()
        {
            int comprimento = get_comprimento();
            return comprimento*comprimento;
        }
};

int main()
{
    PoligoRegular a(6, 5),d;
    Triangulo b(4);
    Quadrado c(5);
    cout << a.angulo() << " " << a.perimetro()<<" " << b.area() <<" " << c.area()<<"\n";
    cout << b.angulo() <<" " << c.angulo() << " angulos \n";
    cout << b.perimetro() << " " << c.perimetro() <<" perimetros \n";
    cout << d.angulo();
}