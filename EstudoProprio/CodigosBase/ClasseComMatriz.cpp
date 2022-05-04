#include <stdio.h>
#include <iostream>
using namespace std;

class Tabuleiro
{
private:
    int n;
    char **matriz;
    int count;

public:
    Tabuleiro(int tam)// de tamanho tam
    {
        n = tam;
        count = 0;
        matriz = new char *[n];
        for (int i = 0; i < n; i++)
        {
            matriz[i] = new char[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matriz[i][j] = ' ';// para deixar tudo com espaço vazio
            }
        }
    }
    Tabuleiro(const Tabuleiro &p)
    {
        n = p.n;
        count=p.count;
        matriz = new char[n];
        for (int i = 0; i < n; i++)
        {
            matriz[i] = new char[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matriz[i][j] = p.matriz[i][j];// para deixar tudo com espaço vazio
            }
        }
    }
    void imprimir()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "|" << matriz[i][j];
            }
            cout << "\n";
            if (i < n)
            {
                for (int k = 0; k < 2 * n; k++)
                    cout << "-";
            }
            cout << "\n";
        }
    }
    ~Tabuleiro()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
};

int main(){
    
}