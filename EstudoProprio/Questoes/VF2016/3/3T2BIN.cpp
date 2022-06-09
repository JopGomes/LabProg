#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string.h>
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
    int tamanho;
   if(!Arq) {
      cout << "Cannot open file!" << endl;
      return false;
   }
   int i=1;
    while(Arq.good()){
            Pessoa temp;
            int idade;
            char *c;
            Arq.read((char *) &tamanho, sizeof(int));
            c= new char[tamanho+1];
            Arq.read(c,tamanho);
            Arq.read((char*) &tamanho,sizeof(int));
            if(Arq.eof()){continue;}
            temp.nome=c;
            temp.idade=tamanho;
            v.push_back(temp);
            i++;
    }
    Arq.close();
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
    int tamanho;
    for(int i=0;v.size()>i;i++){
        tamanho = strlen(v[i].nome.c_str())+1;
        Arq.write((char*) &tamanho,sizeof(int));
        Arq.write(v[i].nome.c_str(),tamanho);
        Arq.write((char*) &v[i].idade,sizeof(int));
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
    if(gravar(v,"outputTesteD")){cout<<"Gravou"<<endl;}
    if(carregar(v,"outputTesteD")){cout<<"Carregou"<<endl;}
    for(int i=0; v.size()>i;i++){
        cout<<v[i].nome<<" "<<v[i].idade<<"\n";
    }
    return 0;
}