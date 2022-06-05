// falta dama
// falta IA decente
// falta SFML
// static count numero de peças
// ver se tem jogada valida
// anda frente ou pra tras
// tratar caso de comer para tras
#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
//#include "gameTile.h"

using namespace sf;
using namespace std;


vector<CircleShape> whites(12);

#include <stdio.h>
#include <iostream>


#define WHITE 'w'
#define BLACK 'b'
#define QUEEN_WHITE 'W'
#define QUEEN_BLACK 'B'
#define VAZIO ' '

string arqWhitePeao =  "images/white_checker.png";
string arqBlackPeao =  "images/black_checker.png";
string arqWhiteQueen = "images/white_checker_King.png";
string arqBlackQueen = "images/black_checker_King.png";


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
    static int qntWhite;
    static int qntBlack;
    Player Pl;
    Type Ty;
    string arquivo;

public:
    Peca()
    {
        pec = VAZIO;
        Pl = V;
    }
    Peca(Type P, Player T)
    {   
        if (T == W && P == Peao)
        {
            pec = WHITE;
            arquivo = arqWhitePeao;
        }
        if (T == B && P == Peao)
        {
            pec = BLACK;
            arquivo = arqBlackPeao;
        }
        if (T == W && P == Q)
        {
            pec = QUEEN_WHITE;
            arquivo = arqWhiteQueen;
        }
        if (T == B && P == Q)
        {
            pec = QUEEN_BLACK;
            arquivo = arqBlackQueen;
        }

        Pl = T;
        Ty = P;

        if (T == B)
            qntBlack++;
        else
            qntWhite++;
    }
    Peca(const Peca &p)
    {
        if (p.pec == B)
            qntBlack++;
        else
            qntWhite++;
        pec = p.pec;
        Pl =p.Pl;
    }
    char getChar() { return pec; }
    Type getType(){return Ty;}
    Player getPlayer(){return Pl;}
    static void setQnt(Player Play) {
        if (Play == B)
            qntBlack--;
        else if(Play== W)
            qntWhite--;
    }
    static int getQntWhite() { return qntWhite; }
    static int getQntBlack() { return qntBlack; }
    string getTipo() {return arquivo;}
};

int Peca::qntBlack = 0;
int Peca::qntWhite = 0;

class Vazio : public Peca
{
public:
    Vazio() : Peca() {}
};

class Comum : public Peca
{
public:
    Comum(Player T) : Peca(Peao, T)
    {
        Pl = T;
        if (T == B)
            qntBlack++;
        else
            qntWhite++;
    }
    Comum(const Comum &p)
    {
        if (p.pec == B)
            qntBlack++;
        else
            qntWhite++;
        pec = p.pec;
        Pl =p.Pl;
    }
    ~Comum(){
        if( Pl == B) qntBlack--;
        else qntWhite--;
    }
};

class Queen : public Peca
{
public:
    Queen(Player T) : Peca(Q, T)
    {
        Pl = T;
        if (T == B)
            qntBlack++;
        else
            qntWhite++;
    }
    Queen(const Queen &p)
    {
        if (p.pec == B)
            qntBlack++;
        else
            qntWhite++;
        pec = p.pec;
        Pl =p.Pl;
    }
    ~Queen(){
        if( Pl == B) qntBlack--;
        else qntWhite--;
    }
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
    void setVazio(int lin , int col){
        tabuleiro[lin][col].setQnt(tabuleiro[lin][col].getPlayer());
        tabuleiro[lin][col]=Vazio();
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
    bool isValid(int lin, int col, int Tlin, int Tcol, Player Player)
    {    
        if (lin >= 8 || col >= 8 || lin < 0 || col < 0 || Tlin >= 8 || Tcol >= 8 || Tlin < 0 || Tcol < 0) return false;

        if(Player != tabuleiro[lin][col].getPlayer()) return false; //posicao inicial invalida

        if(tabuleiro[Tlin][Tcol].getPlayer() != V ) return false; //se ja existe uma peça na posicao de destino

        if(tabuleiro[lin][col].getChar() == WHITE|| tabuleiro[lin][col].getChar() == BLACK){ //Comportamento do peao
            if(Player == W){
                if(Tlin - lin == 1 && abs(Tcol-col) == 1) return true; //andar apenas uma casa
                else if(Tlin - lin == 2 && abs(Tcol -col) == 2){ //tentar comer
                    if(Tcol > col) col += 1;
                    else col -= 1;

                    if(tabuleiro[lin+1][col].getPlayer() != B ) return false; //se não for uma peça inimiga
                }
                else return false;   
            }
            else{
                if(Tlin - lin == -1 && abs(Tcol-col) == 1) return true; //andar apenas uma casa
                else if(Tlin - lin == -2 && abs(Tcol -col) == 2){ //tentar comer
                    if(Tcol > col) col += 1;
                    else col -= 1;

                    if(tabuleiro[lin-1][col].getPlayer() != W ) return false; //se não for uma peça inimiga
                }
                else return false;    
            }  
        }
        else{//É uma dama
            int addLin = (Tlin - lin) / abs(Tlin - lin);//direcões
            int addCol = (Tcol - col) / abs(Tcol - col);
            int auxLin=lin;
            int auxCol=col;
            int bloqueio = 0;
            while(lin != Tlin || col != Tcol){
                lin += addLin;
                col += addCol;
                if(tabuleiro[lin][col].getPlayer() != V) bloqueio += 1;
            }    
            if(bloqueio > 1) {
                return false;
            }
            else{
                if(bloqueio == 1){
                    if(tabuleiro[Tlin][Tcol].getPlayer() != V || !(((tabuleiro[Tlin-addLin][Tcol-addCol].getPlayer() != Player ))&&((tabuleiro[Tlin-addLin][Tcol-addCol].getPlayer() != V )))){
                        return false;
                    }
                }
                return true;
            }
        }
        return true;
    }
    
    bool Jogada(int lin, int col, int Tlin, int Tcol, Player Pl, Opponent Op)
    {   
        if (!isValid(lin, col, Tlin, Tcol, Pl))
        {
            cout << "Jogada Invalida\n";
            return false;
        }


        if (tabuleiro[lin][col].getChar() == QUEEN_WHITE || tabuleiro[lin][col].getChar() == QUEEN_BLACK)
        { // Dama
                int addLin = (Tlin - lin) / abs(Tlin - lin);//direcões
                int addCol = (Tcol - col) / abs(Tcol - col);
                int auxLin=lin , auxCol=col;
                setVazio(auxLin,auxCol);
                setVazio(Tlin-addLin,Tcol-addCol);
                // tabuleiro[auxLin][auxCol] = Vazio();
                // tabuleiro[Tlin-addLin][Tcol-addCol] = Vazio();
                tabuleiro[Tlin][Tcol] = Queen(Pl);
            return true;    
        }
        else
        { // Normal
            setVazio(lin,col);
            // tabuleiro[lin][col] = Vazio();
            if (abs(Tlin-lin) == 2 && abs(Tcol - col) == 2)
            { // Capturar peca
                // tabuleiro[lin][col] = Vazio();
                if (Tcol > col)
                    col += 1;
                else
                    col -= 1;
                if(Pl == W) lin += 1;
                else lin-=1;

                setVazio(lin,col);

                if (Tlin == 7 || Tlin == 0) tabuleiro[Tlin][Tcol] = Queen(Pl);
                else tabuleiro[Tlin][Tcol] = Comum(Pl);

                return true;
            }
            else
            {   
                if(Tlin == 0 || Tlin == 7) tabuleiro[Tlin][Tcol] = Queen(Pl);
                else tabuleiro[Tlin][Tcol] = Comum(Pl);
                return true;
            }
        }
    }

    void ComputerPlay(Player Pl)
    { // falta implementar o computador jogar
        /*Player Comp;
        if(Pl==W){Comp=B;}
        else Comp=W;
        if(Comp==W){addLin=1;}
        else addLin=-1;
        for (int i = 0; 8 > i; i++)
        {
            for (int j = 0; 8 > j; j++)
            {
                if (tabuleiro[i][j].getPlayer()==Comp){
                    if(tabuleiro[i][j].getType()==Peao){//Peao
                        if(tabuleiro[i+addLin][j+addLin].getPlayer!=V){//Capturar peca
                            if(isValid(i,j,i+addLin,j+addLin,Comp)){
                                return false;
                            }
                        }
                        if()
                    }
                    else{//Dama}
                    
                    }
                }
            }
        }
        return;*/
    }

    int getQuantidadeB() { return tabuleiro[0][0].getQntBlack(); }
    int getQuantidadeW() { return tabuleiro[0][0].getQntWhite(); }

    bool termino()
    {
        int countB = getQuantidadeB();
        int countW = getQuantidadeW();

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

    Peca& getElement(int i, int j){
        return tabuleiro[i][j];
    }
    
    string getText(int i,int j){
        return (tabuleiro[i][j].getTipo());
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
    Opponent Op = frnd;
    Player Pl = W;

    RenderWindow window(VideoMode(500,500), "Damas");

    Texture backGroundTexture,texturaTeste;
   
    if(!backGroundTexture.loadFromFile("images/checker_board.jpg")){
        cout<<"Erro ao carregar o tabuleiro"<<endl;
        return 2;
    }
    backGroundTexture.setSmooth(true);

    Sprite background;
    background.setTexture(backGroundTexture);

    CircleShape teste(20);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(event.type == Event::MouseButtonPressed){
                if(event.mouseButton.button == Mouse::Left)
                    if((Mouse::getPosition(window).x >= 50)&&(Mouse::getPosition(window).x <= 450)&&(Mouse::getPosition(window).y >= 50)&&(Mouse::getPosition(window).y <= 450)){
                        int x = (Mouse::getPosition(window).x - 50)/52;
                        int y = (Mouse::getPosition(window).y - 50)/50;
                        int destX,destY;
                        cout<< "x: " << x << " y: "<< y<<endl; 


                        while(Mouse::isButtonPressed(Mouse::Left)){}
                        while(1){
                            if(Mouse::isButtonPressed(Mouse::Left)){
                                destX = (Mouse::getPosition(window).x - 50)/52;
                                destY = (Mouse::getPosition(window).y - 50)/50;
                                break;
                            }
                        }
                        cout<<"destX: "<< destX<<" destY"<<destY<<endl;
                        if(p.Jogada(y,x,destY,destX,Pl,Op)){
                            if(Pl == W) Pl = B;
                            else Pl = W;
                            break;
                        }
                    }
            }  
            
        }

        
        window.clear();
        window.draw(background);
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if((p.getElement(i,j)).getPlayer() != V){
                    if (!texturaTeste.loadFromFile(p.getText(i,j))){   
                        cout<<"Erro ao renderizar pecas do tabuleiro"<<endl;
                        return 1;
                    }
                    texturaTeste.setSmooth(true);
                    teste.setTexture(&texturaTeste);
                    teste.setPosition(Vector2f(50+52*j,50+50*i));
                    window.draw(teste);
                }
            }
        }  
        window.display();
    }


    return 0;
}