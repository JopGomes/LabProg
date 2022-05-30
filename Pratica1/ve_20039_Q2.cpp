#include <stdio.h>
#include <iostream>

using namespace std;

#define SENT -2147483647; // usei o menor inteiro pra poder setar como null , mas podia ser NULL também com uma alteracao no metodo de imprimir, usei por conta de um warn.

class Buffer
{
protected:
    int *buffer;
    int inicio;
    int atual;
    int max;

public:
    Buffer(int tam)
    {
        inicio = 0;
        atual = 0;
        max = tam;
        buffer = new int[tam];
    }
    Buffer()
    {
        inicio = 0;
        atual = 0;
        max = 5;
        buffer = new int[max];
    }
    Buffer(const Buffer &p)
    {
        inicio = p.inicio;
        atual = p.atual;
        max = p.max;
        for (int i = 0; max > i; i++)
        {
            buffer[i] = p.buffer[i];
        }
    }
    ~Buffer()
    {
        delete[] buffer;
    }
    bool isCheio()
    {
        if ((atual == (max)) && inicio == 0)
        {
            cout << "Buffer cheio\n";
            return true;
        }
        else if ((inicio - 1) == (atual))
        {
            cout << "Buffer cheio\n";
            return true;
        }
        else
            return false;
    }
    bool isVazio()
    {
        if (inicio == atual)
        {
            cout << "Buffer Vazio\n";
            return true;
        }
        else
            return false;
    }
    void inserir(int value)
    {
        if (isCheio())
        {
            return;
        }
        else
        {
            if ((max) == atual)
            {
                atual = 0;
                buffer[atual] = value;
                atual++;
            }
            else
            {
                buffer[atual] = value;
                atual++;
            }
        }
    }
    void remover()
    {
        if (!isVazio())
        {
            if (inicio == (max - 1))
            {
                buffer[inicio] = SENT;
                inicio = 0;
            }
            else
            {
                buffer[inicio] = SENT;
                inicio++;
            }
        }
    }
    void imprimir()
    {
        bool isPrinted[max]{};
        for (int i = inicio; max > i; i++)
        {
            if (isPrinted[i])
            {
                break;
            }
            isPrinted[i] = true;
            if (buffer[i] != -2147483647) // se usar null basta colocar if(buffer[i])
                cout << buffer[i] << " ";
        }
        for (int i = 0; atual > i; i++)
        {
            if (isPrinted[i])
            {
                break;
            }
            isPrinted[i] = true;
            if (buffer[i] != -2147483647) // se usar null basta colocar if(buffer[i])
                cout << buffer[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Buffer bf;
    bf.isVazio();
    bf.inserir(0);
    bf.inserir(1);
    bf.inserir(2);
    bf.inserir(3);
    bf.inserir(4);
    bf.imprimir();
    bf.inserir(5);
    bf.imprimir();
    bf.remover();
    bf.imprimir();
    bf.inserir(5);
    bf.imprimir();
    bf.remover();
    bf.imprimir();
}