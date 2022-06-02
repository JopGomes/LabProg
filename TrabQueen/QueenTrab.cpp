// falta dama
// falta IA decente
// falta SFML
// static count numero de peças
// ver se tem jogada valida
// anda frente ou pra tras
// tratar caso de comer para tras

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
    static int qntWhite;
    static int qntBlack;
    Player Pl;

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

        Pl = T;

        if (T == B)
            qntBlack++;
        else
            qntWhite++;
    }
    Peca(const Peca &p)
    {
        cout << "construindo ";
        if (p.pec == B)
            qntBlack++;
        else
            qntWhite++;
        pec = p.pec;
        Pl =p.Pl;
    }

    char getChar() { return pec; }
    Player getPlayer(){return Pl;}
    static int getQntWhite() { return qntWhite; }
    static int getQntBlack() { return qntBlack; }
    // ~Peca()
    // {
    //     if (Pl == W)
    //         qntWhite--;
    //     else if(Pl == B)
    //         qntBlack--;
    // }
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
    Comum(const Comum &c)
    {
        pec = c.pec;
    }
    ~Comum()
    {
        if (Pl == W)
            qntWhite--;
        else
            qntBlack--;
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
    ~Queen()
    {
        if (Pl == W)
            qntWhite--;
        else
            qntBlack--;
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
        /*
        if (lin >= 8 || col >= 8 || lin < 0 || col < 0 || Tlin >= 8 || Tcol >= 8 || Tlin < 0 || Tcol < 0)
            return false;
        if (Tlin == lin || Tcol == col)
        {
            return false;
        }
        if (tabuleiro[lin][col].getChar() == VAZIO || tabuleiro[lin][col].getChar())
        {
            return false;
        }
        if (Player == W)
        {
            if (tabuleiro[lin][col].getChar() == BLACK || tabuleiro[lin][col].getChar() == QUEEN_BLACK)
                return false;
        }
        if (Player == B)
        {
            if (tabuleiro[lin][col].getChar() == WHITE || tabuleiro[lin][col].getChar() == QUEEN_WHITE)
                return false;
        }
        if ((tabuleiro[lin][col].getChar() == WHITE || tabuleiro[lin][col].getChar() == BLACK))
        {
            if (abs(Tlin - lin) > 1 || abs(Tcol - col) > 1)
            {
                return false;
            }
            else if (tabuleiro[lin][col].getChar() == WHITE)
            {
                if (lin >= Tlin)
                    return false;
            }
            else if (tabuleiro[lin][col].getChar() == BLACK)
            {
                if (Tlin >= lin)
                    return false;
            }
        }
        else if ((tabuleiro[lin][col].getChar() == QUEEN_WHITE || tabuleiro[lin][col].getChar() == QUEEN_BLACK))
        { // acho q da pra tirar
            if (abs(Tlin - lin) != abs(Tcol - col))
            {
                return false;
            }
            else
            { // CONDIÇÕES DA DAMA PRECISA REFAZER os FOR
                int addLin = (Tlin - lin) / abs(Tlin - lin);
                int addCol = (Tcol - col) / abs(Tcol - col);
                for (int i = min(lin, Tlin); max(Tlin, lin) >= i && i >= 0; i += addLin)
                {
                    for (int j = min(col, Tcol); max(Tcol, col) >= j && i >= 0; j += addCol)
                    {
                        // Caso de ter duas comidas
                        if (tabuleiro[i][j].getChar() != VAZIO && tabuleiro[i + addLin][j + addCol].getChar() != VAZIO)
                            return false;
                        // Caso ter peca branca no meio
                        if (tabuleiro[i][j].getChar() == tabuleiro[lin][col].getChar())
                            return false;
                    }
                }
            }
        }
        if (tabuleiro[Tlin][Tcol].getChar() != VAZIO)
        {
            if (Tlin > lin && Tcol > col && (Tlin == 7 || Tcol == 7))
            {
                return false;
            }
            if (Tlin > lin && Tcol < col && (Tlin == 7 || Tcol == 0))
            {
                return false;
            }
            if (Tlin < lin && Tcol > col && (Tlin == 0 || Tcol == 7))
            {
                return false;
            }
            if (Tlin < lin && Tcol < col && (Tlin == 0 || Tcol == 0))
            {
                return false;
            }
        }


        */
        
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
            int auxLin=lin;
            int auxCol=col;
            while(lin != Tlin || col != Tcol){
                tabuleiro[lin][col]=Queen(Pl);
                if(!isValid(lin, col, lin+addLin , col+ addCol,Pl)){
                    if(tabuleiro[lin+addLin][col+addCol].getPlayer() != Pl){//se tiver peca no meio do caminho
                        if(lin+addLin == Tlin ) {tabuleiro[lin][col]=Vazio();
                            cout << "Jogada Invalida\n";return false;}// se for pra fora do range
                        if(isValid(lin, col, lin+2*addLin , col+ 2*addCol,Pl)){
                            tabuleiro[auxLin][auxCol]=Vazio();
                            tabuleiro[lin+addLin][col+addCol]=Vazio();
                            tabuleiro[lin][col]=Vazio();
                            tabuleiro[lin+2*addLin][col+2*addCol]=Queen(Pl);
                            return true;
                        }
                        else{tabuleiro[lin][col]=Vazio();
                            cout << "Jogada Invalida\n";return false;}
                    }
                    else {tabuleiro[lin][col]=Vazio();
                        cout<< "Jogada invalida"<<endl;
                        return false;
                    }
                }
                tabuleiro[lin][col]=Vazio();
                lin += addLin;
                col += addCol;
            }
            tabuleiro[auxLin][auxCol]=Vazio();//se n tiver nada no range
            tabuleiro[Tlin][Tcol]=Queen(Pl);
            return true;
        }
        else
        { // Normal
            tabuleiro[lin][col] = Vazio();
            if (abs(Tlin-lin) == 2 && abs(Tcol - col) == 2)
            { // Capturar peca
                tabuleiro[lin][col] = Vazio();
                if (Pl == W)
                {// Brancas
                    if (Tcol > col)
                        col += 1;
                    else
                        col -= 1;

                    tabuleiro[lin+1][col] = Vazio();

                    if (Tlin == 7)
                        tabuleiro[Tlin][Tcol] = Queen(Pl);
                    else
                        tabuleiro[Tlin][Tcol] = Comum(Pl);

                    return true;
                }
                else
                {// Negras
                    if (Tcol > col)
                        col += 1;
                    else
                        col -= 1;

                    tabuleiro[lin-1][col] = Vazio();
                    if (Tlin == 0)
                        tabuleiro[Tlin][col] = Queen(Pl);
                    else
                        tabuleiro[Tlin][Tcol] = Comum(Pl);

                    return true;
                }
            }
            else
            {
                tabuleiro[Tlin][Tcol] = Comum(Pl);
                return true;
            }
        }
    }

    void ComputerPlay(Player Pl)
    { // falta implementar o computador jogar
        return;
    }

    int getQuantidadeB() { return tabuleiro[0][0].getQntBlack(); }
    int getQuantidadeW() { return tabuleiro[0][0].getQntWhite(); }

    bool termino()
    {
        int countB = getQuantidadeB();
        int countW = getQuantidadeW();
        /*for (int i = 0; 8 > i; i++)
        {
            for (int j = 0; 8 > j; j++)
            {
                if (tabuleiro[i][j].getChar()==QUEEN_BLACK || tabuleiro[i][j].getChar()==BLACK){
                    countB++;
                    if(i==0 && tabuleiro[i][j].getChar()==BLACK){
                        tabuleiro[i][j] = Queen(B);
                    }
                }
                if (tabuleiro[i][j].getChar()==QUEEN_WHITE || tabuleiro[i][j].getChar()==WHITE){
                    countW++;
                    if(i==7 && tabuleiro[i][j].getChar()==WHITE){
                        tabuleiro[i][j] = Queen(W);
                    }
                }
            }
        }*/
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
    string info, Target;
    Player Pl = W;
    Opponent Op = frnd;
    int i = 3;
    bool jogadaValida = true;
    while (i != 1 && i != 2)
    {
        cout << "Deseja Jogar contra:\n[1]Computador\n[2]Humano\n";
        cin >> i;
    }
    if (i == 1)
    {
        Op = comp;
    }
    else
    {
        Op = frnd;
    }
    if (Op == comp && jogadaValida && Pl == B)
    {
        // p.ComputerPlay(Pl);
    }
    while (p.termino())
    {
        p.imprimir();
        cout << "o numero de pecas " << p.getQuantidadeB() << endl;
        cout << "\n";
        cout << "Escreva a linha e a coluna no formato a1, que e o canto superior esquerdo\nDa peca escolhida:\n";
        cin >> info;
        if (info[0] - 'a' > 8 || info[1] - '1' > 8 || info[0] - 'a' < 0 || info[1] - '1' < 0)
        {
            cout << "Digite um valor valido\n";
            continue;
        }
        cout << "Do destino:\n";
        cin >> Target;
        if (Target[0] - 'a' > 8 || Target[1] - '1' > 8 || Target[0] - 'a' < 0 || Target[1] - '1' < 0)
        {
            cout << "Digite um valor valido\n";
            continue;
        }
        jogadaValida=  p.Jogada(info[1]-'1',info[0]-'a',Target[1]-'1',Target[0]-'a',Pl,Op);
        if (!jogadaValida)
        {
            continue;
        }
        if (Op == frnd)
        {
            if (Pl == W)
            {
                Pl = B;
            }
            else
                Pl = W;
        }
        if (Op == comp)
        {
            // p.ComputerPlay(Pl);
        }
    }
}