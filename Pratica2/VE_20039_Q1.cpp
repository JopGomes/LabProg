#include <vector>
#include <set>
#include <strings.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define vida 6;

class JogoDaForca{
    static const int chance;
    int count;
    vector<string> palavras;
    set<char> letras{};
    vector<string> resposta{};
    string answ;
public:
    JogoDaForca(vector<string> palavras):palavras(palavras),count(0),answ(""){
        set<char> auxLetras;
        vector<string> auxResposta;
        letras=auxLetras;
        resposta=auxResposta;
    }
    void iniciar(){
        count=0;
        srand(time(0));
        letras.clear();
        random_shuffle(palavras.begin(),palavras.end());
        auto it = palavras.begin();
        answ = *it;
        resposta.resize(answ.size());
        fill(resposta.begin(),resposta.end(),"_");
        palavras.erase(it);
   }
   void mostrar(){
       for(int i=0; resposta.size()>i;i++){
           cout <<resposta[i];
       }
       cout<<"\n";
       cout<< "Number of lifes:" << chance-count <<endl;
       cout<<"\n";
   }
   void jogar(char c){
       if(letras.count(c)){cout <<"Alredy tested"<<endl;return;}
       int aux=0;
       letras.insert(c);
       for(int i=0;answ.length()>i;i++){
           if(answ[i]==c){
               aux++;
               resposta[i]=c;
           }
       }
       if(!aux)count++;
   }
    bool testeFimdeJogo(){
        if(count>=chance){
            cout<< "You lose, correct word:"<<endl;
            cout << answ<<endl;
            return true;
        }
        else{
            
            int aux=0;
            for(int i=0;answ.length()>i;i++){
                if(answ[i]==resposta[i][0]){
                    aux++;
                }
            }
            if(palavras.size()==0 && aux==answ.length()){

                cout<< "You win"<<endl;
                return true;
            }
            if(aux==answ.length()){
                mostrar();
                cout<< "Correct word"<<endl;
                iniciar();
            }
        }
    return false;
    }
};

const int JogoDaForca::chance=vida;

int main(){
    vector<string> palavras;
    char aux;
    palavras.push_back("esse");
    palavras.push_back("teste");
    palavras.push_back("foi");
    palavras.push_back("testado");
    palavras.push_back("mais");
    palavras.push_back("outra");
    palavras.push_back("vez");
    JogoDaForca p(palavras);
    p.iniciar();
    cout<<"The game started"<<endl;
    while(!p.testeFimdeJogo()){
        cin >> aux;
        p.jogar(aux);
        p.mostrar();
    }
}