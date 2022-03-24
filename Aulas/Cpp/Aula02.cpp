// Exemplo de LOO em c++ basico

#include <cstdlib>
#include <iostream>

using namespace std;

class hello{ // Declarando a classe
    public: // Metodos e atributos publicos
        void primeiro();
    private: // Metodos e atributos privados
    protected: // Serão vistos posteriormente
};
void hello::primeiro(){
    cout << "Ola mundo";
}
int main(){
    hello p; // inicializando um objeto p
    p.primeiro(); // chamando o metodo primeiro
}