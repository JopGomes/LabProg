#include <iostream>
#include <string>
using namespace std;

template <typename T>
void imprimirVetor(const T *vetor, int quantidade){
    for(int i=0;i <quantidade;i++){
        cout <<vetor[i]<<" ";
    }
    cout <<endl;
}

int main(){
    int a[]={1,2,3,4,5};
    string s[]={"Um","Dois","Tres","Quatro"};
    imprimirVetor(a,5);
    imprimirVetor(s,4);
    return 0;
}