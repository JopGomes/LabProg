#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Deque
{
public:
    int *deque;
    int max;
    int atual;
    Deque(int tam)
    {
        deque = new int [tam]{};
        max = tam;
        atual=0;
    }
    Deque(const Deque &p)
    {
        max = p.max;
        atual=p.atual;
        deque = new int[max];
        for (int i = 0; i < max; i++)
        {
            deque[i] = p.deque[i];
        }
    }
    int getTam()
    {
        return max;
    }
    void inserir(int enum0, int valor)
    {
        int temp2{};
        int temp = deque[enum0];
        deque[enum0] = valor;
        for (int i = enum0 + 1; i < getTam(); i++)
        {
            temp2 = deque[i];
            deque[i] = temp;
            temp = temp2;
        }
        atual=atual+1;
    }
    void excluir(int enum0)
    {
        int temp{},temp2{};
        for (int i = getTam(); enum0 <= i; i--)
        {
            temp2 = deque[i];
            deque[i] = temp;
            temp = temp2;
        }
        atual=atual-1;
    }
    void imprimir(){
        for(int i = 0; i<atual;i++){
            cout << deque[i]<<" ";
        }
        cout << "\n";
    }
    ~Deque()
    {
        delete[] deque;
    }
};

class Fila: public Deque{
    public:
    Fila(int tam): Deque(tam){}
    void excluir(){
        Deque::excluir(getTam());
    }
    void inserir(int valor){
        Deque::inserir(0,valor);
    }
};

int main()
{
    Deque a(3);
    Fila b(4);
    b.inserir(1);
    b.inserir(2);
    b.inserir(3);
    b.imprimir();
    Fila d(b);
    d.imprimir();
    b.excluir();
    b.imprimir();
    a.inserir(0, 1);
    a.inserir(0, 2);
    a.inserir(2, 2);
    Deque c(a);
    c.imprimir();
    a.imprimir();
    a.excluir(1);
    a.imprimir();
}