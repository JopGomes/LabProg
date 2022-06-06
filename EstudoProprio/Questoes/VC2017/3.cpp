#include <iostream>
#include <iomanip>


// nao entendi mt bem a questao deixei pra lá
class ThreeD{
    int ponto[3];
    public:
    ThreeD(int x,int y, int z){
        ponto[0]=x;
        ponto[1]=y;
        ponto[2]=z;
    }
    ThreeD(){
        ponto[0]=0;
        ponto[1]=0;
        ponto[2]=0;
    }
};

class TwoD:public ThreeD{
    public:
    TwoD(int x,int y):ThreeD(x,y,0){}
    TwoD():ThreeD(){}
};

class Cubo{
    vector<int> pontos;

};

int main(){

}