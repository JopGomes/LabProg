#include <iostream>
#include <cmath>

using namespace std;

class Complex{
    float real,img;
public:
    Complex(float real, float img):img(img),real(real){}
    bool operator! (){
        return ( real==0 && img ==0);
    }
    friend bool operator-(Complex c);
    Complex& operator++ (){
        real+=1;
        return *this;
    }
    Complex operator++ (int){
        Complex temp(*this);
        real++;
        return temp;
    }
    Complex operator+(Complex rhs){
        return Complex(real+rhs.real,img+rhs.img);
    }
    float modulo(){
        return sqrt(real*real+img*img);
    }
    bool operator==(Complex rhs){
        return (real==rhs.real && img==rhs.img);
    }
    bool operator<(Complex rhs){
        return modulo()<rhs.modulo();
    }
    bool operator>(Complex rhs){
        return rhs.modulo()>modulo();
    }
    Complex operator=(Complex rhs){
        real=rhs.real;
        img = rhs.img;
        return *this;
    }
    float& operator[](int pivot){
        if(pivot==1)return img;
        else if(pivot==0)return real;
        else throw "Wrong Input";
    }
    operator float(){
        return real;
    }
};

bool operator-(Complex c){
    cout << c.real <<" "<< c.img<<"i"<<endl;
    return !c;
}



int main(){
    Complex c1(0,0),c2(1,3);
    cout<< !c1<<endl;
    cout <<!c2<<endl;
    cout<<"After the operato - which came from a friend function\n";
    cout<<-c1<<endl;
    cout <<-c2<<endl;
    cout<<"After the operator++\n";
    c1++;
    cout << -c1<< endl;
    cout<<"After the ++operator\n";
    cout << -(++c1)<<endl;
    cout <<-c1<<endl;

    cout << (float) c1<<"\n";
}