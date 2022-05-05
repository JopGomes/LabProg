#include <iostream>

using namespace std;

class Elemento
{
    int chave;
    Elemento *prox;

public:
    Elemento(int chave) : chave(chave), prox(NULL){};
    int getChave()
    {
        return chave;
    }
    Elemento *getProx()
    {
        return prox;
    }
    void setProx(Elemento *elem)
    {
        prox = elem;
    }
};

class ListaEncadeada
{
protected:
    Elemento *inicio;

public:
    ListaEncadeada() : inicio(NULL){};
    void imprimir()
    {
        Elemento *aux = inicio;
        while (aux != nullptr)
        {
            cout << " " << aux->getChave();
            aux = aux->getProx();
        }
        cout << "\n";
    }
    ListaEncadeada(const ListaEncadeada &p)
    {
        inicio = p.inicio;
        Elemento *aux = p.inicio->getProx();
        Elemento *aux2 = inicio;
        while (aux)
        {
            aux2->setProx(aux);
            aux = aux->getProx();
        }
    }
    ~ListaEncadeada()
    {
        while (inicio)
        {
            Elemento *aux = inicio->getProx();
            delete inicio;
            inicio = aux;
        }
    }
    Elemento *getInicio()
    {
        return inicio;
    }
    void inserir(int chave)
    {
        Elemento *aux = inicio;
        if (aux == NULL)
        {
            inicio = new Elemento(chave);
            return;
        }
        while (aux->getProx() != NULL)
        {
            aux = aux->getProx();
        }
        aux->setProx(new Elemento(chave));
    }
};

class Fim : public ListaEncadeada
{
public:
    Fim() : ListaEncadeada() {}
    void remover()
    {
        Elemento *aux = inicio, *ant;
        if (aux == NULL)
        {
            return;
        }
        while (aux->getProx() != NULL)
        {
            ant = aux;
            aux = aux->getProx();
        }
        ant->setProx(NULL);
        delete aux;
    }
};

class Inicio : public ListaEncadeada
{
public:
    Inicio() : ListaEncadeada() {}
    void remover()
    {
        Elemento *aux = inicio, *ant;
        if (aux == NULL)
        {
            return;
        }
        inicio = inicio->getProx();
        delete aux;
    }
};

int main()
{
    Fim ld;
    cout << "Fim\n";
    ld.inserir(50);
    ld.inserir(40);
    ld.inserir(30);
    ld.inserir(20);
    ld.imprimir();
    ld.remover();
    ld.imprimir();
    ld.remover();
    ld.imprimir();
    ld.inserir(60);
    ld.imprimir();
    cout << "Inicio\n";
    Inicio ld2;
    ld2.inserir(50);
    ld2.inserir(40);
    ld2.inserir(30);
    ld2.inserir(20);
    ld2.imprimir();
    ld2.remover();
    ld2.imprimir();
    ld2.remover();
    ld2.imprimir();
    ld2.inserir(60);
    ld2.imprimir();
}