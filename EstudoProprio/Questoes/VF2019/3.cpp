#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Image{
    vector<vector<int> > image;
    int N;
public:
    void leitura(string nomeArq ){
        string num;
        fstream arq;
        ostringstream Arq;
        Arq <<nomeArq<<".txt";
        arq.open(Arq,ios::in);
        if(!arq.is_open()){return 1;}
        arq >> N;
        while(!arq.eof()){
            arq >> num ;
            if(arq.eof())continue;
            candidates.push_back(Candidate(num,nam,part));
        }
    }
};

int main(){

}