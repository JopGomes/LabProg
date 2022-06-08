#include <iostream>
using namespace std;

enum valores{VAZIO,CIRCULO,XIS};
string valore[] = {" ", "O", "X"};



class JogoDaVelha
{
    valores tabuleiro[3][3];
    int i,j, state_i;

public:
    JogoDaVelha()
    {
        i=j=state_i=0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tabuleiro[i][j] = VAZIO;
            }
        }
    }
    valores getValores(int i,int j){
        return tabuleiro[i][j];
    }
    JogoDaVelha& operator[](int i){
        if(!state_i){this->i =i-1;}
        else{this->j=i-1;}
        state_i=(state_i+1)%2;
        return *this;
    }
    JogoDaVelha& operator=(const char* str){
        switch (str[0])
        {
        case 'X':
        case 'x':
            tabuleiro[i][j]= XIS;
            break;
        case 'O':
        case 'o':
            tabuleiro[i][j]= CIRCULO;
            break;
        default:
            tabuleiro[i][j]= VAZIO;
            break;
        }
        return *this;
    }
};


ostream &operator<<(ostream &os, JogoDaVelha k)
{
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(j==1 || j==2){
                    os<< "|"<<valore[k.getValores(i,j)];
                }
                else{
                    os<<valore[k.getValores(i,j)];
                }
            }
            if(i!=2){os<<"\n-----\n";}
            else os<<"\n";
        }
    return os;
}

int main()
{
    JogoDaVelha j;
    j[1][1]="X";
    cout << j;
}