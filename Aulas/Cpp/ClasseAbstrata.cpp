//Classe projetada somente como base
//Contain only virtual methods

class X{
    virtual void f()=0;
};

// Abstrat class can't be stanched, so you need to fill this method in a child class
//But you can use this with pointer or by adress(referencia)

#include <iostream>

using namespace std;

class B{
public:
    virtual void metodo()=0;// Example of implemetation
};

class F:public B{
public:
    void metodo(){cout<<"metodoF\n";}
};

class N:public F{
public:
    void metodo(){cout<<"metodoN\n";}
};

void func(B *b){
    b->metodo();
}

int main(){
    
    F f;
    f.metodo();

    N n;
    n.metodo();

    func(&f);
    func(&n);
}