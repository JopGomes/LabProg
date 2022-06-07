#include <iostream>
using namespace std;

enum valores{VAZIO,CIRCULO,XIS};
string valore[] = {" ", "O", "X"};

// valores& operator=(string j){
//     if(j==" ")
//     if(j=="O")
//     if(j=="X")
// }

class JogoDaVelha
{
    valores tabuleiro[3][3];

public:
    JogoDaVelha()
    {
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
    valores* operator[](int i)
    {
       return tabuleiro[i];
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
    j[1][1]=CIRCULO;
    cout << j;
}