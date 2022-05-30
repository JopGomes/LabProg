// falta dama
// falta IA decente
// falta SFML

#include <stdio.h>
#include <iostream>
using namespace std;

#define WHITE 'w'
#define BLACK 'b'
#define QUEEN_WHITE 'W'
#define QUEEN_BLACK 'B'
#define VAZIO ' '

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
    Peca() { pec = VAZIO; }
    Peca(Type P, Player T)
    {
        if (T == W && P == Peao)
        {
            pec = WHITE;
        }
        if (T == B && P == Peao)
        {
            pec = BLACK;
        }
        if (T == W && P == Q)
        {
            pec = QUEEN_WHITE;
        }
        if (T == B && P == Q)
        {
            pec = QUEEN_BLACK;
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
                if (i < 3 && (i % 2 == j % 2))
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
    bool isValid(int lin, int col,int Tlin, int Tcol, Player Player)
    {
        if (lin >= 8 || col >= 8 || lin < 0 || col < 0 || Tlin >= 8 || Tcol >= 8 || Tlin < 0 || Tcol < 0)
            return false;
        else if (tabuleiro[Tlin][Tcol].getPlayer() == Player)
            return false;
        else if (tabuleiro[Tlin][Tcol].getChar() != VAZIO && (lin == 7 || col == 7 || lin == 0 || col == 0))
        {
            return false;
        }
        else if(tabuleiro[lin][col].getChar()== VAZIO){return false;}
        else if((tabuleiro[lin][col].getChar()==WHITE || tabuleiro[lin][col].getChar()==BLACK) && (abs(Tlin-lin)>1 || abs(Tcol-col)>1)){return false;}
        else if((tabuleiro[lin][col].getChar()==QUEEN_WHITE || tabuleiro[lin][col].getChar()==QUEEN_BLACK)){
            if(abs(Tlin-lin)!=abs(Tcol-col)){return false;}
            else{
                for(int i=lin;Tlin>=i;i+=(Tlin-lin)/abs(Tlin-lin)){
                    for(int j=col;Tcol>=j;j+=(Tcol-col)/abs(Tcol-col)){
                        if(tabuleiro[i][j].getChar()==tabuleiro[lin][col].getChar())return false;
                    }
                }

            }
        }
        return true;
    }
    bool Jogada(int lin, int col, int Tlin, int Tcol, Player Pl, Opponent Op)
    { 
        if(!isValid(lin,col,Tlin,Tcol,Pl)){cout<< "Jogada Invalida\n";return false;}
        tabuleiro[lin][col]=Vazio();
        if (tabuleiro[lin][col].getChar() == QUEEN_WHITE || tabuleiro[lin][col].getChar() == QUEEN_BLACK)
        { // Dama
            return false;
        }
        else
        {// Normal
            if(tabuleiro[Tlin][Tcol].getChar() != VAZIO){//Capturar peca
                if(Tlin > lin && Tcol > col && tabuleiro[Tlin+1][Tcol+1].getChar()==VAZIO){tabuleiro[Tlin+1][Tcol+1]=Comum(Pl);
                tabuleiro[Tlin][Tcol]=Vazio();return true;}
                if(Tlin > lin && Tcol < col && tabuleiro[Tlin+1][Tcol-1].getChar()==VAZIO){tabuleiro[Tlin+1][Tcol-1]=Comum(Pl);
                tabuleiro[Tlin][Tcol]=Vazio();return true;}
                if(Tlin < lin && Tcol > col && tabuleiro[Tlin-1][Tcol+1].getChar()==VAZIO){tabuleiro[Tlin-1][Tcol+1]=Comum(Pl);
                tabuleiro[Tlin][Tcol]=Vazio();return true;}
                if(Tlin < lin && Tcol < col && tabuleiro[Tlin-1][Tcol-1].getChar()==VAZIO){tabuleiro[Tlin-1][Tcol-1]=Comum(Pl);
                tabuleiro[Tlin][Tcol]=Vazio();return true;}
                return false;
            }
            else{
                tabuleiro[Tlin][Tcol]=Comum(Pl);
                return true;
            }
        }
    } 
    void ComputerPlay(Player Pl){//falta implementar o computador jogar
        return;}
    bool termino()
    {
        int countB = 0;
        int countW = 0;
        for (int i = 0; 8 > i; i++)
        {
            for (int j = 0; 8 > j; j++)
            {
                if (tabuleiro[i][j].getChar()==QUEEN_BLACK || tabuleiro[i][j].getChar()==BLACK){
                    countB++;
                    if(i==0 && tabuleiro[i][j].getChar()==BLACK){
                        tabuleiro[i][j]= Queen(B);
                    }
                }
                if (tabuleiro[i][j].getChar()==QUEEN_WHITE || tabuleiro[i][j].getChar()==WHITE){
                    countW++;
                    if(i==7 && tabuleiro[i][j].getChar()==WHITE){
                        tabuleiro[i][j]= Queen(W);
                    }
                }
            }
        }
        if (countB == 0)
        {
            cout << "White WIN";
            return false;
        }
        if (countW == 0)
        {
            cout << "Black WIN";
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
    string info,Target;
    Player Pl=W;
    Opponent Op=frnd;
    int i=3;
    bool jogadaValida;
    while(i != 1 && i!=2){
        cout << "Deseja Jogar contra:\n[1]Computador\n[2]Humano\n";
        cin>> i;
    }
    if(i==1){Op=comp;}
    else{Op=frnd;}
    if(Op==comp && jogadaValida && Pl==B){
           p. ComputerPlay(Pl);
    }
    while(p.termino()){
        p.imprimir();
        cout << "\n";
        cout << "Escreva a linha e a coluna no formato a1, que e o canto superior esquerdo\nDa peca escolhida:\n";
        cin >> info;
        if(info[0]-'a'>8 || info[1]-'1'>8 || info[0]-'a'<0 || info[1]-'1'<0){cout<<"Digite um valor valido\n";continue;}
        cout << "Do destino:\n";
        cin >> Target;
        if(Target[0]-'a'>8 || Target[1]-'1'>8 || Target[0]-'a'<0 || Target[1]-'1'<0){cout<<"Digite um valor valido\n";continue;}
        jogadaValida=  p.Jogada(info[1]-'1',info[0]-'a',Target[1]-'1',Target[0]-'a',Pl,Op);
        if(!jogadaValida){continue;}
        if(Op==frnd  ){
            if(Pl==W){Pl=B;}
            else Pl=W;
        }
        if(Op==comp ){
            p.ComputerPlay(Pl);
        }
    }
}