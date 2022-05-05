#include <iostream>

using namespace std;

class Elemento{
    int chave;
    string valor;
    Elemento* prox;
    public:
    Elemento(int chave, string valor):chave(chave),valor(valor),prox(nullptr){};
    int getChave(){
        return chave;
    }
    Elemento* getProx(){
        return prox;
    }
    void setProx(Elemento* elem){
        prox = elem;
    }
    string getValor(){
        return valor;
    }
};

class Mapa{
    Elemento* inicio;
    public:
    Mapa():inicio(nullptr){};
    void imprimir(){
        Elemento* aux = inicio;
        while(aux!=nullptr){
            cout<<"String: "<<aux->getValor()<<"/ Chave: "<<aux->getChave()<<endl;
            aux = aux->getProx();
        }
    }
    string mapaValor(int alvo){
        if(!buscarChave(alvo)){
            cout<<"Mapa Inexistente";
            return " ";
        }
        Elemento* aux = inicio;
        while(aux!=nullptr){
            if(aux->getChave()==alvo){
                return aux->getValor();
            }
            aux = aux->getProx();
        }
    }
    int mapaChave(string alvo){
        if(!buscarValor(alvo)){
            cout<<"Mapa Inexistente"<<endl;
            return 0;
        }
        Elemento* aux = inicio;
        while(aux!=nullptr){
            if(aux->getValor()==alvo){
                return aux->getChave();
            }
            aux = aux->getProx();
        }
    }
    bool buscarChave(int alvo){
        Elemento* aux = inicio;
        while(aux!=nullptr){
            if(aux->getChave()==alvo){
                return 1;
            }
            aux = aux->getProx();
        }
        return 0;        
    }
    bool buscarValor(string alvo){
        Elemento* aux = inicio;
        while(aux!=nullptr){
            if(aux->getValor()==alvo){
                return 1;
            }
            aux = aux->getProx();
        }
        return 0;        
    }

    void inserir(int chave, string valor){
        if(buscarChave(chave)||buscarValor(valor)){
            cout<<"Ja existente"<<endl;
            return;
        }
        Elemento* aux = inicio;
        if(aux == nullptr){
            inicio = new Elemento(chave,valor);
            return;
        }
        while(aux->getProx()!=nullptr){
            aux = aux->getProx();
        }
        aux->setProx(new Elemento(chave,valor));
    }    
};