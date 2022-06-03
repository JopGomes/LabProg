#include <iostream>
#include <vector>
#include <algorithm>
#define NJOG 2

using namespace std;


enum evalor{
    DOIS, TRES, QUATROS , CINCO, SEIS, SETE ,OITO, NOVE,
    DEZ,J,Q,K,AS
};

string valores[]= {" 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10"," J"," Q"," K","As"};

enum enaipe {OURO,COPAS,ESPADAS,PAUS};
string naipes[] ={"OUROS","COPAS","ESPADA","PAUS"};

struct Carta{
    evalor valor;
    enaipe naipe;
    Carta(evalor valor, enaipe naipe):valor(valor),naipe(naipe){}
    Carta operator++(int){
        Carta temp(*this);
        if(valor==AS){
            valor = DOIS;
            if(naipe == PAUS) {
                naipe= OURO;
            }
            else
                naipe=(enaipe)(naipe+1);
        }
        else
            valor=(evalor) (valor+1);
        return temp;
    }
    bool operator<(Carta c){return valor < c.valor;}
    bool operator==(evalor v){
        return valor==v;
    } 
};

ostream& operator << (ostream &os, const Carta &carta){
    os<< valores[carta.valor]<<" de "<<naipes[carta.naipe];
    return os;
}

Carta proximaCarta(){
    static Carta c(DOIS,OURO);
    return c++;
}


int main(){
    
    srand(time(NULL));
    Carta e(K,PAUS);
    vector<Carta> baralho(52, Carta(DOIS,OURO));
    vector<vector<Carta> > mao(NJOG);
    vector<Carta> mesa;
    generate_n(baralho.begin(),52,proximaCarta);
    random_shuffle(baralho.begin(),baralho.end());
    for(int k=0; k<2;k++){
        for(int i=0;i<NJOG;i++){
            Carta c= *(baralho.rbegin());
            baralho.pop_back();
            mao[i].push_back(c);
        }
    }
    for(int k =0;k<5;k++){
        if(k>2) baralho.pop_back();
        Carta c(*baralho.rbegin());
        mesa.push_back(c);
        baralho.pop_back();
    }
    cout<<endl;
    cout<<"MESA: ";
    for(auto it=mesa.begin();it!=mesa.end();it++)cout<< (*it)<<", ";
    for(int i=0; i<NJOG;i++){
        for(auto it=mesa.begin();it!=mesa.end();it++){
            mao[i].push_back(*it);
        }
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<NJOG;i++)sort(mao[i].begin(),mao[i].end());
    for(int i=0; i<NJOG;i++){
        cout<<"MAO "<<i<<": ";
        for(auto it=mao[i].begin();it!=mao[i].end();it++){
            cout << (*it)<<", ";
        }
        cout<<endl;
    }
    for(int i=0; i< NJOG;i++){
        cout <<"MAO"<<i<<": "<<endl;
        for(evalor val=DOIS; val< AS+1; val=(evalor) (val+1)){
            int co = count(mao[i].begin(),mao[i].end(),val);
            if(co>1)cout<<valores[val]<< ": "<<co<<endl;

        } 
    }

    return 0;
}

