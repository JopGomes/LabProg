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
};

bool carregar(vector<Pessoa>& v, string nomeDoArquivo){
    ostringstream nomeArq;
    nomeArq <<nomeDoArquivo<<".txt";
    ifstream Arq(nomeArq.str(),ios::in | ios::binary);
    string nome;
    int idade;
   if(!Arq) {
      cout << "Cannot open file!" << endl;
      return false;
   }
   int i=1;
    while(!Arq.eof()){
            Pessoa newPessoa;
            if(Arq.eof()){continue;}
            Arq.read((char *) &v[i], sizeof(Pessoa));
            i++;
            v.push_back(newPessoa);
    }
    Arq.close();
    if(!Arq.good()) {
      cout << "Error occurred at reading time!" << endl;
         return false;
    }
    return true;
}

bool gravar(vector<Pessoa>& v, string nomeDoArquivo){
    ostringstream nomeArq;
    nomeArq <<nomeDoArquivo<<".txt";
    ofstream Arq(nomeArq.str(), ios::out | ios::binary);
    string nome;
    int idade;
    if(!Arq) {
      cout << "Cannot open file!" << endl;
      return false;
   }
    for(int i=0;v.size()>i;i++){
        Arq.write((char*) &v[i],sizeof(Pessoa));
    }
    Arq.close();
    if(!Arq.good()) {
      cout << "Error occurred at writing time!" << endl;
      return false;
   }
    return true;
}

int main(){
    vector<Pessoa> v;
    Pessoa teste;
    teste.nome="Jop";
    teste.idade=10;
    v.push_back(teste);
    if(gravar(v,"output")){cout<<"Gravou";}
    if(carregar(v,"output")){cout<<"Carregou";}
    return 0;
}