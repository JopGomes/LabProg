// falta criar a funcionalidade de Dama voltando 
// falta as condições de contorno para valores CHAR
// falta criar as classses de peça e vazio
// falta criar uma IA para jogar as peças

#include <stdio.h>
#include <iostream>
using namespace std;

enum Movimento
{
    esquerda,
    direita,
};

class Tabuleiro
{
private:
    char **tabuleiro;
    int count;

public:
    Tabuleiro()
    {
        count = 0;
        tabuleiro = new char *[8];
        for (int i = 0; 8 > i; i++)
        {
            tabuleiro[i] = new char[8];
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i < 3 && (i % 2 != j % 2))
                {
                    tabuleiro[i][j] = 'W';
                }
                else if (i >= 5 && (i % 2 == j % 2))
                {
                    tabuleiro[i][j] = 'B';
                }
                else
                {
                    tabuleiro[i][j] = ' ';
                }
            }
        }
    }
    void imprimir()
    {
        cout << "\n";
        for (int i = 0; 8 > i; i++)
        {
            for (int j = 0; 8 > j; j++)
            {
                cout << tabuleiro[i][j] << " | ";
            }
            cout << "\n";
            for (int k = 0; 30 > k; k++)
            {
                cout << "-";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void Jogada(int i, int j, Movimento lado)
    {
        if (lado == esquerda)
        {
            if (count % 2 == 0)
            {
                if (tabuleiro[i][j] == 'W' || tabuleiro[i][j] == 'Q')
                {
                }
                else
                {
                    cout << "Jogada Invalida";
                    return;
                }
                if (tabuleiro[i + 1][j - 1] == 'W')
                {
                    cout << "Jogada Invalida";
                    return;
                }
                else if (tabuleiro[i + 1][j - 1] == 'B' && (j - 1) > 0 && (i + 1) < 7)
                {
                    count++;
                    tabuleiro[i][j] = ' ';
                    tabuleiro[i + 1][j - 1] = ' ';
                    tabuleiro[i + 2][j - 2] = 'W';
                }
                else
                {
                    count++;
                    tabuleiro[i][j] = ' ';
                    tabuleiro[i + 1][j - 1] = 'W';
                }
            }
            else
            {
                if (tabuleiro[i][j] == 'B' || tabuleiro[i][j] == 'K')
                {
                }
                else
                {
                    cout << "Jogada Invalida";
                    return;
                }
                if (tabuleiro[i - 1][j - 1] == 'B')
                {
                    cout << "Jogada Invalida";
                    return;
                }
                else if (tabuleiro[i - 1][j - 1] == 'W' && (j - 1) > 0 && (i - 1) > 0)
                {
                    count++;
                    tabuleiro[i][j] = ' ';
                    tabuleiro[i - 1][j - 1] = ' ';
                    tabuleiro[i - 2][j - 2] = 'B';
                }
                else
                {
                    count++;
                    tabuleiro[i][j] = ' ';
                    tabuleiro[i - 1][j - 1] = 'B';
                };
            }
        }
        if (lado == direita)
        {
            if (count % 2 == 0)
            {
                if (tabuleiro[i][j] == 'W' || tabuleiro[i][j] == 'Q')
                {
                }
                else
                {
                    cout << "Jogada Invalida";
                    return;
                }
                if (tabuleiro[i + 1][j + 1] == 'W')
                {
                    cout << "Jogada Invalida";
                    return;
                }
                else if (tabuleiro[i + 1][j + 1] == 'B' && (j - 1) > 0 && (i + 1) < 7)
                {
                    count++;
                    tabuleiro[i][j] = ' ';
                    tabuleiro[i + 1][j + 1] = ' ';
                    tabuleiro[i + 2][j + 2] = 'W';
                }
                else
                {
                    count++;
                    tabuleiro[i][j] = ' ';
                    tabuleiro[i + 1][j + 1] = 'W';
                }
            }
            else
            {
                if (tabuleiro[i][j] == 'B' || tabuleiro[i][j] == 'K')
                {
                }
                else
                {
                    cout << "Jogada Invalida";
                    return;
                }
                if (tabuleiro[i - 1][j + 1] == 'B')
                {
                    cout << "Jogada Invalida";
                    return;
                }
                else if (tabuleiro[i - 1][j + 1] == 'W' && (j + 1) < 8 && (i + 1) < 7)
                {
                    count++;
                    tabuleiro[i][j] = ' ';
                    tabuleiro[i - 1][j + 1] = ' ';
                    tabuleiro[i - 2][j + 2] = 'B';
                }
                else
                {
                    count++;
                    tabuleiro[i][j] = ' ';
                    tabuleiro[i - 1][j + 1] = 'B';
                };
            }
        }
    }
    bool termino()
    {
        int countB = 0;
        int countW = 0;
        for (int i = 0; 8 > i; i++)
        {
            for (int j = 0; 8 > j; j++)
            {
                if (tabuleiro[i][j] == 'B' || tabuleiro[i][j] == 'Q')
                    countB++;
                if (tabuleiro[i][j] == 'W' || tabuleiro[i][j] == 'K')
                    countW++;
            }
        }
        if (countB == 0)
        {
            cout << "White";
            return false;
        }
        if (countW == 0)
        {
            cout << "Black";
            return false;
        }
        return true;
    }
    ~Tabuleiro()
    {
        for (int i = 0; 8 > i; i++)
        {
            delete[] tabuleiro[i];
        }
        delete[] tabuleiro;
    }
};

int main()
{
    Tabuleiro p;

    while (p.termino())
    {
        p.imprimir();

        int a, b, lado;
        cout << "Peca na linha:";
        cin >> a;
        cout << "\nPeca na coluna:";
        cin >> b;
        // colocar um if pra ver se é normal ou queen;
        cout << " Para qual lado que vai\n [1] Esquerda \n [2]Direita\n";
        cin >> lado;
        if (lado == 1)
        {
            p.Jogada(a - 1, b - 1, esquerda);
        }
        if (lado == 2)
        {
            p.Jogada(a - 1, b - 1, direita);
        }
    }
}