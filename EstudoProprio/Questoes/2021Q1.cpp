#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Falta verificar se o metodo que estou recebendo o parametro deque esta correto
//Falta construtor por copia
//Falta a classe derivada e saber como se cria uma

using namespace std;

typedef struct sLista
{
    int valor;
    struct sLista *prox;
} TLista;

class Deque()
{
plubic:
    double tam;
    TLista deque;
    Deque(tam)
    { // Construtor
        while (tam--)
        {
            TLista *novoElemento = (TLista *)malloc(sizeof(TLista));
            novoElemento->valor = null;
            novoElemento->prox = *deque;
            *deque = novoElemento;
        }
    }
    Deque(TLista Deque )
private:
    Deque remove(enum)
    {
        TLista *aux = &deque, *anterior = NULL;
        for (int i = 0; num > i; i++)
        {
            anterior = aux;
            aux = aux->prox;
        }
        while (aux)
        {
            aux.valor = aux->prox.valor;
            aux = aux->prox;
        }
    }
    Deque insere(enum, valor)
    {
        TLista *aux = deque, *anterior = NULL;
        while (num--)
        {
            anterior = aux;
            aux = aux->prox;
        }

        while (aux)
        {
            aux.valor = aux->prox.valor;
            aux = aux->prox;
        }
    }
    Deque imprime()
    {
        TLista *aux = deque;
        while (aux)
        {
            cout << aux.valor <<" ";
            aux = aux->prox;
        }
        cout << "\n";
    }
    ~Deque()
    {
        TLista *aux = deque, *anterior = NULL;
        while (aux)
        {
            {
                if (anterior)
                    anterior->prox = aux->prox;
                else
                    *pInicio = aux->prox;
                free(aux);
            }
        }
    }
};

class Fila:: public Deque {
    Deque remove(enum)
    {
        TLista *aux = &deque, *anterior = NULL;
        for (int i = 0; num > i; i++)
        {
            anterior = aux;
            aux = aux->prox;
        }
        while (aux)
        {
            aux.valor = aux->prox.valor;
            aux = aux->prox;
        }
    }
    Deque insere(enum, valor)
    {
        TLista *aux = deque, *anterior = NULL;
        while (num--)
        {
            anterior = aux;
            aux = aux->prox;
        }

        while (aux)
        {
            aux.valor = aux->prox.valor;
            aux = aux->prox;
        }
    }
}


int main()
{
}