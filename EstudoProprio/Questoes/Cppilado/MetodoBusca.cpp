#include <stdio.h>

class MetodoBusca{
    int *vetor;
    int count;
    MetodoBusca(int max);
    bool inserir(int e);
    bool remover(int i);
    bool busca(int e);
};

MetodoBusca::MetodoBusca(int max){
    vetor=new int[max];
    count=0;
}
bool MetodoBusca::inserir(int e){
    vetor[count]=e;
    count++;
    return true;
}
bool MetodoBusca::remover(int i){
    
    return true;
}


int main(){

}