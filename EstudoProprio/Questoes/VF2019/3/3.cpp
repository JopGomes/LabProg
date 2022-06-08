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
        string bits;
        fstream arq;
        ostringstream Arq;
        Arq <<nomeArq<<".txt";
        arq.open(Arq.str(),ios::in);
        if(!arq.is_open()){return;}
        arq >> N;
        arq>> bits;
        vector<int> aux;
        for(int i=1;N*N>=i;i++){
            int aux2 = bits[i-1]-'0';
            aux.push_back(aux2);
            if(!(i%N) && i!=0){
                image.push_back(aux);
                aux.clear();
            }
        }
    }
    void imprime(){
        for(int i=0;N>i;i++){
            for(int j=0;N>j;j++){
                if(image[i][j]){
                    char aux=(char) 219;
                    cout <<aux;
                }
                else{ cout<< " ";}
            }
            cout<<"\n";
        }
    }
};

int main(){
    Image a;
    a.leitura("teste");
    a.imprime();
}