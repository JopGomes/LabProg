#include <iostream>
#include "mapa.h"

using namespace std;

int main(){
    Mapa mapa1;
    mapa1.inserir(50,"casa");
    mapa1.inserir(30,"aaa");

    cout<<mapa1.mapaChave("casa")<<endl;
    cout<<mapa1.mapaValor(30)<<endl;
}