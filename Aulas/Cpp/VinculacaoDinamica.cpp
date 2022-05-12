// Heranca multipla

// class nome_classe:<tipo_acesso> classe_base_1,<tipo_acesso> classe_base_2,...{}
//class F1: public P1, protected P2{}
// Unica diferenca entre struct e class em c++ -> é a declaração das herança enquanto na classe o default é private
//enquanto o struct é public.


// Modificador virtual

// O modificador virtual indica ao compilador que deve ser utilizada a definição da função() mais aproprieada, sem considerar o tipo do objeto a que se refere

#include <iostream>

using namespace std;

class B{
public:
// Se tirar o virtual vc percebera as diferencas ao rodar programa.
    virtual  void metodo(){
        cout <<"metodoB\n";
    }
};

class F:public B{
public:

    void metodo(){cout<<"metodoF\n";}
};

class N:public F{
public:
// Se colocar o virtual aqui, ele so será virtual para as classes filhas, não para a pai, e o jump feito
//Será direto para a variavel na func, pois ele tem um ponteiro de B
    void metodo(){cout<<"metodoN\n";}
};

//Observe que se mudar de B para N o virtual ( se for tirado de B e colocado em N irá funcionar, o msm se colocar em F) pq o virtual vale
// a partir do momento em q o metodo é definido como virtual, então como ali chama B não irá ocorrer e ira ser estatico
// ao substituir por N irá ser dinâmico e ai analisaremos .
void func(B *b){
    //Observação se mudar de ponteiro (B *b) para (F b) não existe a duvida ligada ao negc. E chamara apenas para F o metodo, a duvida
    // so existe se for um ponteiro,  e não uma copia
    b->metodo();
}

int main(){
    B b;
    b.metodo();
    
    F f;
    f.metodo();

    N n;
    n.metodo();

    //Observe o que acontece o que ao retirar e colocar virtual
    //Meio que por conta do virtual o compilador descobre qual a proxima linha de codigo em tempo de execução nessas funções abaixo
    //E chama a função a mais correta
    func(&b);
    func(&f);
    func(&n);
}