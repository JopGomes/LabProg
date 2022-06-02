#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>

class Pilha{
    int tamanho,topo;
    T *ptrPilha;
    public:
    Pilha(int tamanho=10):tamanho(tamanho),topo(0){ptrPilha= new T[tamanho];}
    ~Pilha(){delete ptrPilha; }
    bool inserir(const T& valor);
    void print(){
        for(int i=0; topo>i;i++){cout<<ptrPilha[i]<<" ";}
        cout<<"\n";
    }
};
template <typename T>
bool Pilha<T>:: inserir(const T& valor){
    if(topo<tamanho){
        ptrPilha[topo++]=valor;
        return true;
    }
    else return false;
}

int main(){
    Pilha<int> p(12);
    p.inserir(2);
    p.inserir(4);
    p.print();
    return 0;
}