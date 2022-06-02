
//Podemos definir parametros default para o template e
//Passar como parametros nele tbm.


#include <stdio.h>

template<class T=char, int N=2>

class meuVetor{
    T vetor[N];
};

int main(){
    meuVetor <int,10> meuVetor1;
    meuVetor <float, 5> meuVetor2;
}