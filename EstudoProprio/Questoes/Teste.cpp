#include<iostream>
#include<vector>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;



class Candidato{
private:
    const string nome;
    int numero;
    string partido;
    int votos;
public:
    Candidato(string nome):nome(nome){
        partido = "NHA";
        numero = -1;
        votos = 0;
    }
    Candidato(string nome, int num, string partido):nome(nome),numero(num),partido(partido),votos(0){}
    string getNome() const{
        return nome;
    }
    int getVotos(){
        return votos;
    }
    void incrementaVotos(){
        votos++;
    }

    bool operator<(const Candidato& c){
        if(votos < c.votos)return true;
        else return false;
    }

    friend ostream& operator<<(ostream& os,const Candidato& c);
};

ostream& operator<<(ostream& os,const Candidato& c){
        os << c.nome << " votos: "<< c.votos<<endl;
        return os;
    } 

bool ordena(Candidato &c1,Candidato &c2){
    if(c1.getVotos() > c2.getVotos()) return true;
    else return false;
}

int main(){
    vector<Candidato> listaCandidatos;
    ifstream arqCandidatos("dados_eleicao/candidatos.txt");
    int num;
    string nome, partido;
    if(!arqCandidatos.is_open()){
        cout<<"erro na abertura"<<endl;
        return 1;
    }
    while(1){
        arqCandidatos >> num >> nome >> partido;
        if(arqCandidatos.eof()) break;
        Candidato temp(nome,num,partido);
        listaCandidatos.push_back(temp);
    }
    
    string nomeUrnaBase = "dados_eleicao/urna", final = ".txt";

    for(int i = 0 ; i < 4 ; i++){
        string nomeFinal = nomeUrnaBase + to_string(i+1) + final;
        ifstream arqUrnas(nomeFinal);
        int numCand;
        while(1){
            arqUrnas >> numCand;
            if(arqUrnas.eof()) break;
            listaCandidatos[numCand].incrementaVotos();
        }
    }

    sort(listaCandidatos.begin(),listaCandidatos.end());

    for(int i = 0 ; i < listaCandidatos.size() ; i++){
        cout<<listaCandidatos[i].getNome()<<" votos: "<<listaCandidatos[i].getVotos() <<endl;
    }
    return 0 ;
}