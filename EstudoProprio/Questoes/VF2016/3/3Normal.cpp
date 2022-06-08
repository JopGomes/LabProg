#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct Pessoa{
    string nome;
    int idade;
    Pessoa():nome(""),idade(0){}
};

bool carregar(vector<Pessoa>& v, string nomeDoArquivo){
    ostringstream nomeArq;
    nomeArq <<nomeDoArquivo<<".txt";
    ifstream Arq(nomeArq.str());
    string nome;
    int idade;
    if(!Arq.is_open()){return false;}
    while(!Arq.eof()){
            Pessoa newPessoa;
            Arq>> nome >> idade;
            newPessoa.nome=nome;
            newPessoa.idade=idade;
            v.push_back(newPessoa);
    }
    return true;
}

bool gravar(vector<Pessoa>& v, string nomeDoArquivo){
    ostringstream nomeArq;
    nomeArq <<nomeDoArquivo<<".txt";
    ofstream Arq(nomeArq.str());
    string nome;
    int idade;
    if(!Arq.is_open()){return false;}
    for(int i=0;v.size()>i;i++){
            Arq<<v[i].nome <<" "<< v[i].idade<<endl;
    }
    return true;
}

int main(){
    vector<Pessoa> v;
    if(carregar(v,"teste")){cout<<"Carregar";}
    if(gravar(v,"output")){cout<<"Gravar";}
    return 0;
}