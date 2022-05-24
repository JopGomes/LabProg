#include <stdio.h>
#include <iostream>
using namespace std;

int mdc(int a,int b){
    return b? mdc(b,a%b): a;
}

class NumeroRacional{
    int up,dw;
    public:
    NumeroRacional(int a,int b){
        if(b==0)throw "Invalid";
        else{

            int div=mdc(a,b);
            up=a/div;
            dw=b/div;
            if(dw <0){
                dw*=-1;
                up*=-1;
            }
        }
    }
    void frac(){
        cout << up <<"/"<<dw<<"\n";
    }
    NumeroRacional operator+(NumeroRacional rhs){
        return NumeroRacional(up*rhs.dw+rhs.up*dw,dw*rhs.dw);
    }
    NumeroRacional operator-(NumeroRacional rhs){
        return NumeroRacional(up*rhs.dw-rhs.up*dw,dw*rhs.dw);
    }
    NumeroRacional operator/(NumeroRacional rhs){
        return NumeroRacional(up*rhs.dw,dw*rhs.up);
    }
    NumeroRacional operator*(NumeroRacional rhs){
        return NumeroRacional(up*rhs.up,dw*rhs.dw);
    }
    void operator=(NumeroRacional rhs){
        up=rhs.up;
        dw=rhs.dw;
    }
    NumeroRacional operator ++(){
        NumeroRacional temp(up,dw);
        up+=dw;
        return temp;
    }
    operator++(int){
        up+=dw;
        return *this;
    }
    operator float(){
        double c= (up+0.0)/dw +0.0;
        return c;
    }
};

int main(){
    NumeroRacional a(2,4),b(1,-2);
    a.frac();
    b.frac();
    (a+b).frac();
    (a-b).frac();
    cout << (float) a<< "\n" << a;
}