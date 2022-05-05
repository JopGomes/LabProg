#include <iostream>
#include <stdlib.h>
using namespace std;

class Elem
{
public:
    int chave;
    Elem *prox;
    ~Elem()
    {
        cout << "destrutor " << chave << endl;
    }
};

class ListaEncadeada
{
    Elem *inicio;

public:
    ListaEncadeada()
    {
        inicio = NULL;
    }
    ~ListaEncadeada()
    {
        while (inicio)
        {
            Elem *aux = inicio->prox;
            delete inicio;
            inicio = aux;
        }
    }
    void inserir(int valor)
    {
        Elem *atual = new (nothrow) Elem;
        if (atual == NULL)
        {
            cout << "ERRO";
            return;
        }

        atual->chave = valor;
        atual->prox = inicio;
        inicio = atual;
    }
    void remover(int valor)
    {
        Elem *atual = inicio, *ant = NULL;

        while (atual && atual->chave != valor)
        {
            ant = atual;
            atual = atual->prox;
        }

        if (atual)
        {
            if (atual == inicio)
                inicio = inicio->prox;
            else
                ant->prox = atual->prox;
            delete atual;
        }
    }
    void impressao()
    {
        Elem *atual = inicio;
        while (atual)
        {
            cout << atual->chave << " ";
            atual = atual->prox;
        }
        cout << endl;
    }
};
int main()
{
    ListaEncadeada l;

    l.inserir(10);
    l.inserir(7);
    l.inserir(5);

    l.impressao();

    l.remover(7);
    l.remover(9);

    l.impressao();
}