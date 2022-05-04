#include <stdio.h>
#include <iostream>
using namespace std;

class MetodoBusca
{
    public:
    int *vetor;
    int count;
    int max;
    MetodoBusca(int max);
    bool inserir(int e);
    bool remover(int i);
    bool busca(int e);
    ~MetodoBusca(){
        delete[] vetor;
    }
};

MetodoBusca::MetodoBusca(int maxi)
{
    vetor = new int[maxi];
    max=maxi;
    count = 0;
}
bool MetodoBusca::inserir(int e)
{
    int i=0;
    while (e > vetor[i] && count >= i && max > i)
    {
        i++;
    }
    if (count <= max)
    {
        vetor[i] = e;
        count++;
        return true;
    }
    else
    {
        return false;
    }
}

bool MetodoBusca::busca(int e)
{
    
}

bool MetodoBusca::remover(int e)
{
    int temp, temp2;
    for (int i = 0; count >= i; i++)
    {
        if (vetor[i] == e)
        {
            for (int j = i; count >= j; j++)
            {
                temp = vetor[j + 1];
                vetor[j] = temp;
            }
            count--;
            return true;
        }
    }
    return false;
}

class BuscaLinear : public MetodoBusca
{
    public:

    BuscaLinear(int max) : MetodoBusca(max){}
    busca(int e)
    {
        for (int i = 0; count >= i; i++)
        {
            if (vetor[i] == e)
            {
                return true;
            }
        }
        return false;
    }
};

class BuscaBinaria : public MetodoBusca
{
    public:
    
    BuscaBinaria(int max) : MetodoBusca(max){}
    busca(int e)
    {
        int r=count;
        int l=0;
        int pivot= l + (r-l)/2;
        while(pivot!=r){
            if(e>vetor[pivot]){
                l=pivot;
            }
            else if(e<vetor[pivot]){
                r=pivot;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

bool buscar(MetodoBusca &mb,int *vet, int n, int k){
    for(int i=0;i<n;i++){
        mb.inserir(vet[i]);
    }
    return mb.busca(k);
}
int main()
{
    srand(time(NULL));
    int n=100,k,m=50;
    int v[100];
    BuscaBinaria mb1(n);
    BuscaLinear mb2(n);
    for(int i=0; i<n;i++){
        k=rand()%m;
        v[i]=k;
    }
    k=rand()%m;
    cout <<"BuscaBinaria:"<<(buscar(mb1,v,n,k)?"Sim":"Nao")<<"\n";
    cout <<"BuscaLinear:"<<(buscar(mb2,v,n,k)?"Sim":"Nao")<<"\n";
}