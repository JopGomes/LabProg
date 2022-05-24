#include <stdio.h>
#include <iostream>
using namespace std;

enum Tipo
{
    Peao,
    Q,
};
enum Jogador
{
    W,
    B,
    V
};

class Peca
{
protected:
    char pec;
public:
    Peca() { pec = ' '; }
    Peca(Tipo P, Jogador T){
        if(T==W && P==Peao){pec='w';}
        if(T==B && P==Peao){pec='b';}
        if(T==W && P==Q){pec='W';}
        if(T==B && P==Q){pec='B';}
    }
    char getChar() { return pec; }
    Jogador getJogador();
};

class Vazio: public Peca{
    public:
    Vazio():Peca(){}
    Jogador getJogador(){return V;}
};
class Comum:public Peca{
    Jogador Pl;
    public :
    Comum(Jogador T) : Peca(Peao, T){Pl=T;}
    Jogador getJogador(){return Pl;}
};
class Queen:public Peca{
    Jogador Pl;
    public :
    Queen(Jogador T) : Peca(Q, T){Pl=T;}
    Jogador getJogador(){return Pl;}
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
    bool isValid(int lin, int col, Jogador Player){
        if(tabuleiro[lin][col].getJogador()==V)return true;
        else if(tabuleiro[lin][col].getJogador==Player)return false;
        
    }
    void Jogada(){

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

int main(){
    Tabuleiro p;
    p.imprimir();
}