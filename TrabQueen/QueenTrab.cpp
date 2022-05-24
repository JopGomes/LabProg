#include <stdio.h>
#include <iostream>
using namespace std;

enum Type
{
    Peao,
    Q,
};
enum Player
{
    W,
    B,
    V
};
enum Direction
{
    lf,
    rt,
};

enum Opponent
{
    comp,
    frnd,
};

class Peca
{
protected:
    char pec;

public:
    Peca() { pec = ' '; }
    Peca(Type P, Player T)
    {
        if (T == W && P == Peao)
        {
            pec = 'w';
        }
        if (T == B && P == Peao)
        {
            pec = 'b';
        }
        if (T == W && P == Q)
        {
            pec = 'W';
        }
        if (T == B && P == Q)
        {
            pec = 'B';
        }
    }
    char getChar() { return pec; }
    virtual Player getPlayer(){return V;};
};

class Vazio : public Peca
{
public:
    Vazio() : Peca() {}
    Player getPlayer() { return V; }
};
class Comum : public Peca
{
    Player Pl;

public:
    Comum(Player T) : Peca(Peao, T) { Pl = T; }
    Player getPlayer() { return Pl; }
};
class Queen : public Peca
{
    Player Pl;

public:
    Queen(Player T) : Peca(Q, T) { Pl = T; }
    Player getPlayer() { return Pl; }
};

class Tabuleiro
{
    Peca **tabuleiro;
    int count;

public:
    Tabuleiro()
    {
        count = 0;
        tabuleiro = new Peca *[8];
        for (int i = 0; 8 > i; i++)
        {
            tabuleiro[i] = new Peca[8];
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i < 3 && (i % 2 != j % 2))
                {
                    tabuleiro[i][j] = Comum(W);
                }
                else if (i >= 5 && (i % 2 == j % 2))
                {
                    tabuleiro[i][j] = Comum(B);
                }
                else
                {
                    tabuleiro[i][j] = Vazio();
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
                cout << tabuleiro[i][j].getChar() << " | ";
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
    bool isValid(int lin, int col, Player Player)
    {
        if (lin >= 8 || col >= 8 || lin < 0 || col < 0)
            return false;
        else if (tabuleiro[lin][col].getPlayer() == Player)
            return false;
        else if (tabuleiro[lin][col].getChar() != ' ' && (lin == 7 || col == 7 || lin == 0 || col == 0))
        {
            return false;
        }
        else
            return true;
    }
    void Jogada(int lin, int col, Direction T, Player Pl, Opponent Op)
    {
        if (tabuleiro[lin][col].getChar() == 'W' || tabuleiro[lin][col].getChar() == 'B')
        { // Dama
        }
        else
        {
            if (T == lf)
            { // para a esquerda
                if (Pl == W)
                { // se for as brancas
                    if (isValid(lin + 1, col - 1, Pl))
                    { // Talvez de pra criar uma função e deixar menos repetitivo
                        tabuleiro[lin][col] = Vazio();
                        if (lin == 6)
                        {
                            tabuleiro[lin + 1][col - 1] = Queen(W);
                        }
                        else if (tabuleiro[lin + 1][col - 1].getChar() != ' ')
                        {
                            tabuleiro[lin + 1][col - 1] = Vazio();
                            if (lin == 5)
                            {
                                tabuleiro[lin + 2][col - 2] = Queen(W);
                            }
                            else
                            {
                                tabuleiro[lin + 2][col - 2] = Comum(W);
                            }
                        }
                        else
                        {
                            tabuleiro[lin + 1][col - 1] = Comum(W);
                        }
                    }
                    else
                    {
                        cout << "Jogada Invalida";
                    }
                }
                else
                { // se for as negras
                    if (isValid(lin - 1, col - 1, Pl))
                    { // Talvez de pra criar uma função e deixar menos repetitivo
                        tabuleiro[lin][col] = Vazio();
                        if (lin == 1)
                        {
                            tabuleiro[lin - 1][col - 1] = Queen(B);
                        }
                        else if (tabuleiro[lin - 1][col - 1].getChar() != ' ')
                        {
                            tabuleiro[lin - 1][col - 1] = Vazio();
                            if (lin == 2)
                            {
                                tabuleiro[lin - 2][col - 2] = Queen(B);
                            }
                            else
                            {
                                tabuleiro[lin - 2][col - 2] = Comum(B);
                            }
                        }
                        else
                        {
                            tabuleiro[lin - 1][col - 1] = Comum(B);
                        }
                    }
                    else
                    {
                        cout << "Jogada Invalida";
                    }
                }
            }
            else
            { // para a direita
                if (Pl == W)
                { // se for as brancas
                    if (isValid(lin + 1, col + 1, Pl))
                    {
                       tabuleiro[lin][col] = Vazio();
                        if (lin == 6)
                        {
                            tabuleiro[lin + 1][col + 1] = Queen(W);
                        }
                        else if (tabuleiro[lin + 1][col - 1].getChar() != ' ')
                        {
                            tabuleiro[lin + 1][col  + 1] = Vazio();
                            if (lin == 5)
                            {
                                tabuleiro[lin + 2][col + 2] = Queen(W);
                            }
                            else
                            {
                                tabuleiro[lin + 2][col + 2] = Comum(W);
                            }
                        }
                        else
                        {
                            tabuleiro[lin + 1][col + 1] = Comum(W);
                        }
                    }
                    else
                    {
                        cout << "Jogada Invalida";
                    }
                }
                else
                { // se for as negras para direita
                    if (isValid(lin - 1, col + 1, Pl))
                    { // Talvez de pra criar uma função e deixar menos repetitivo
                        tabuleiro[lin][col] = Vazio();
                        if (lin == 1)
                        {
                            tabuleiro[lin - 1][col + 1] = Queen(B);
                        }
                        else if (tabuleiro[lin - 1][col + 1].getChar() != ' ')
                        {
                            tabuleiro[lin - 1][col + 1] = Vazio();
                            if (lin == 2)
                            {
                                tabuleiro[lin - 2][col + 2] = Queen(B);
                            }
                            else
                            {
                                tabuleiro[lin - 2][col + 2] = Comum(B);
                            }
                        }
                        else
                        {
                            tabuleiro[lin - 1][col + 1] = Comum(B);
                        }
                    }
                    else
                    {
                        cout << "Jogada Invalida";
                    }
                }
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
                if (tabuleiro[i][j].getChar()=='B' || tabuleiro[i][j].getChar()=='b')
                    countB++;
                if (tabuleiro[i][j].getChar()=='W' || tabuleiro[i][j].getChar()=='w')
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
    string info;
    Player Pl=W;
    Direction D;
    Opponent Op=frnd;
    int i;
    while(p.termino()){
        p.imprimir();
        cout << "\n";
        cout << "Escreva a linha e a coluna no formato a1 da peca:\n";
        cin >> info;
        cout << "Para qual lado \n[1] Esquerda \n[2]Direita\n";
        cin >> i;
        if(i==1)D=lf;
        else if(i==2)D=rt;
        else{continue;}
        p.Jogada(info[0]-'a',info[1]-'0',D,Pl,Op);
        if(Pl==W){Pl=B;}
        else Pl=W;
    }
}