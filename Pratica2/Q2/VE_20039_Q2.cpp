#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

template<typename K>
class vetorOrdenado{
    vector<K> vetor;
    int capacidade;
public:
    vetorOrdenado(int N=5):capacidade(N){
        vector<K> aux{};
        aux.resize(capacidade);
        vetor=aux;
    }
    void operator<<(string arq){
        ostringstream nomeArq;
        nomeArq << arq<<".txt";
        ifstream Arq(nomeArq.str());
        if(!Arq.is_open()){cout<<"Erro na leitura";return;}
        string valores;
        int count=0;
        while(Arq.good()){
            if(count==capacidade)break;
            K aux;
            Arq >> aux;
            if(Arq.eof())break;
            Arq.seekg(1*sizeof(char),ios_base::cur);
            if(Arq.eof())break;
            vetor[count]=aux;
            count++;
        }
        Arq.close();
        sort(vetor.begin(),vetor.end());
    }
    int operator+(K val){
        auto it =find(vetor.begin(),vetor.end(),val);
        if(it!=vetor.end()){
            return distance(vetor.begin(),it)+1;
        }
        else return -1;
    }
    int operator-(K val){
        
        auto it =lower_bound(vetor.begin(),vetor.end(),val);
        return distance(vetor.begin(),it);
    }
    template<typename T>
    friend ostream& operator << (ostream &os, const vetorOrdenado<T> &obj);
};

template<>
class vetorOrdenado<string>{
    vector<string> vetor;
    int capacidade;
public:
    vetorOrdenado(int N=5):capacidade(N){
        vector<string> aux{};
        aux.resize(capacidade);
        vetor=aux;
    }
    void operator<<(string arq){
        ostringstream nomeArq;
        nomeArq << arq<<".txt";
        ifstream Arq(nomeArq.str());
        if(!Arq.is_open()){cout<<"Erro na leitura";return;}
        string valores;
        int count=0;
        while(Arq.good()){
            if(count==capacidade)break;
            string aux1;
            Arq >> aux1;
            string aux2;
            for(int i=0;aux1.size()>i;i++){
                if(count==capacidade)break;
                if(aux1[i]==','){
                    vetor[count]=aux2;
                    aux2="";
                    count++;
                    continue;
                }
                aux2.push_back(aux1[i]);
            }
        }
        Arq.close();
        sort(vetor.begin(),vetor.end());
    }
    int operator+(string val){
        auto it =find(vetor.begin(),vetor.end(),val);
        if(it!=vetor.end()){
            return distance(vetor.begin(),it)+1;
        }
        else return -1;
    }
    int operator-(string val){
        
        auto it =lower_bound(vetor.begin(),vetor.end(),val);
        return distance(vetor.begin(),it);
    }
    template<typename T>
    friend ostream& operator << (ostream &os, const vetorOrdenado<T> &obj);
};

template<typename K>
ostream& operator << (ostream &os, const vetorOrdenado<K> &obj)
{//letra e, ta esq então tem q ser fora
    for(int i=0; obj.vetor.size()>i;i++){
        os << obj.vetor[i]<<" ";
    }
    os << endl;
    return os;
}


int main(){
    vetorOrdenado<float> i(5);
    i<<"teste";
    cout << i+9.0<<endl;
    cout << i-9<<endl;
    cout << i;
    vetorOrdenado<char> c(5);
    c<<"testeS";
    cout << c+'r'<<endl;
    cout << c-'s'<<endl;
    cout << c;
    vetorOrdenado<string> s(5);
    s<<"testeS";
    cout << s+"r"<<endl;
    cout << s-"si"<<endl;
    cout << s;
}