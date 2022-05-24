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
enum Direction{
    lf,
    rt,
};

enum Opponent{
    comp,
    frnd,
};

class Peca
{
protected:
    char pec;
public:
    Peca() { pec = ' '; }
    Peca(Type P, Player T){
        if(T==W && P==Peao){pec='w';}
        if(T==B && P==Peao){pec='b';}
        if(T==W && P==Q){pec='W';}
        if(T==B && P==Q){pec='B';}
    }
    char getChar() { return pec; }
    Player getPlayer();
};

class Vazio: public Peca{
    public:
    Vazio():Peca(){}
    Player getPlayer(){return V;}
};
class Comum:public Peca{
    Player Pl;
    public :
    Comum(Player T) : Peca(Peao, T){Pl=T;}
    Player getPlayer(){return Pl;}
};
class Queen:public Peca{
    Player Pl;
    public :
    Queen(Player T) : Peca(Q, T){Pl=T;}
    Player getPlayer(){return Pl;}
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
    bool isValid(int lin, int col, Player Player){
        if(lin>=8 || col >=8 || lin<0 || col <0) return false; 
        else if(tabuleiro[lin][col].getPlayer()==Player)return false;
        else return true;
    }
    void JogadaComp();
    void Jogada(int lin, int col, Direction T, Player Pl,Opponent Op ){
        if(T==lf){
            if(Pl==W){}
            else{}
        }
        else{
            if(Pl==W){}
            else{}
        }
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