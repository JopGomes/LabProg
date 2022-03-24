#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
    float a, b;

public:
    Complex(float c = 0, float d = 0)
    {
        a = c;
        b = d;
    }
    void setReal(float c){a=c;}
    void setImg(float d){b=d;}
    float getReal(){return a;}
    float getImg(){return b;}
    float Mod()
    {
        return sqrt(a * a + b * b);
    }
    Complex Conj()
    {
        return Complex(a, -b);
    }
    void Imprimir()
    {
        cout << a << "+"
             << "(" << b << ")"
             << "i \n";
    }
    Complex Sum(Complex c)// Retorna uma copia que apos o chamamento ira ser destruido
    {
        return Complex(a + c.a, b + c.b);// Retorna um  novo complexo
    }
    Complex& acum(Complex c)//Com o & retorna por referencia o parametro de saída para poder alterar ele
    {
        a+= c.a;
        b+= c.b;
        return *this; // retorna o proprio complexo
    }
    Complex Sub(Complex c) 
    {
        return Complex(a - c.a, b - c.b);
    }
    Complex Mult(Complex c)
    {
        return Complex(a * c.a - b * c.b, a * c.b + b * c.a);
    }
    Complex Div(Complex c)
    {
        return Complex(Mult(c.Conj()).a / c.Mod(), Mult(c.Conj()).b / c.Mod());
    }
};

int main()
{
    int n,real1,img1,real2,img2;
    cin  >> n;
    while (n--)
    {
        cin >> real1 >> img1 >> real2 >> img2;
        Complex a(real1,img1),b(real2,img2);
        cout << "b\n";
        b.Imprimir();
        cout << "a\n";
        a.Imprimir();
        Complex c = a.Div(b);
        cout << "Div\n";
        c.Imprimir();
        Complex d = a.Mult(b);
        cout << "Mult\n";
        d.Imprimir();
        d = a.Conj();
        cout << "Conj\n";
        d.Imprimir();
    }
}