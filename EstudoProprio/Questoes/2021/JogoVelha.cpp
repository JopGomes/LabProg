#include <stdio.h>
#include <iostream>
using namespace std;

bool Check(char **matriz, int lin, int col, int max)
{
    char win = matriz[lin][col];
    int countH = 1;
    int countV = 1;
    int countDM = 1;
    int countDme = 1;
    for (int i = 0; i < max; i++)
    {
        if (matriz[i][i] == win)
        {
            countDM++;
        }
        if (countDM == max)
            return true;
        for (int j = 0; j < max; j++)
        {
            if (countH == max)
                return true;
            if (matriz[i][j] == win)
            {
                countH++;
            }
            else
            {
                countH = 1;
            }
            if (countV == max)
                return true;
            if (matriz[i][j] == win)
            {
                countV++;
            }
            else
            {
                countV = 1;
            }
        }
    }
    for (int i = max - 1; 0 <= i; i--)
    {
        if (matriz[i][i] == win)
        {
            countDme++;
        }
        if (countDme == max)
        {
            return true;
        };
    }

    return false;
}

class Tabuleiro
{
private:
    int n;
    char **matriz;
    int count;

public:
    Tabuleiro(int tam)
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
                matriz[i][j] = ' ';
            }
        }
    }
    void jogar(int l, int c)
    {
        int lin = l - 1, col = c - 1;
        if (lin >= n || col >= n)
        {
            cout << "Jogada Invalida\n";
            return;
        }
        else
        {
            if (count + 1 == n * n)
            {
                cout << "Ultima Jogada Valida\n";
            }
            if (matriz[lin][col] != ' ')
            {
                cout << "Jogada Invalida\n";
                return;
            }
            else
            {
                if (count % 2 == 0)
                {
                    matriz[lin][col] = 'O';
                    count++;
                }
                else
                {
                    matriz[lin][col] = 'X';
                    count++;
                }
            }
            if (Check(matriz, lin, col, n))
            {
                if (count % 2 == 0)
                {
                    cout << "Vitoria do Jogador O\n";
                }
                if (count % 2)
                {
                    cout << "Vitoria do Jogador X\n";
                }
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

int main()
{
    Tabuleiro a(3);
    a.jogar(1, 1);
    a.jogar(6, 2);
    a.jogar(2, 6);
    a.jogar(1, 1);
    a.jogar(1, 2);
    a.jogar(2, 1);
    a.jogar(1, 3);
    a.jogar(3, 1);
    a.jogar(2, 2);
    a.jogar(2, 3);
    a.jogar(3, 2);
    a.jogar(3, 3);
    a.imprimir();
    cout << "Outro jogo\n";
}