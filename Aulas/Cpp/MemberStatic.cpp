// O static representa que ele é compartilhado com todas as classes;
//Pode ser acessado pelo operador escopo
// We call that variable by class variable
//If the method is static we can acess only static atributs
//Don't has acess to 'this'

#include <iostream>

using namespace std;

class B{
public:
    virtual void metodo()=0;
};

class F:public B{
public:
    void metodo(){cout<<"metodoF\n";}

};

class N:public F{
public:
    void metodo()const{cout<<"metodoN\n";}// We mark as const because we don't want to change any atribut of my object
    static int s;
};

class X{
private:
    static string nomeX;
public:
    static void imprimeNome()  {cout<<nomeX<<endl;}
};

void func(B *b){
    b->metodo();
}

int N::s=100;

//Inicializando o nome fora de uma classe
string X::nomeX="X";
int main(){
    cout << N::s<<endl;
    N::s++;
    N n1;
    cout << n1.s<<endl;
    //Pay attention in this, because we didn't create a object in class X, but we inicializated one, so we can acess the 
    //static atributes
    X::imprimeNome();
}