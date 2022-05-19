#include <stdio.h>
#include <iostream>
using namespace std;
;

class Empregado{
    const string nome;
    double salario;
    int ramal;
    static int cnt;
    static bool print;
public:
    Empregado(string nome, double salario, int ramal):nome(nome),salario(salario),ramal(ramal){cnt++;printCount(false);}
    Empregado(const Empregado &p):nome(p.nome),salario(salario),ramal(ramal){cnt++;printCount(false);}
    ~Empregado(){cnt--;printCount(true);}
    double getSal() const{return salario;}
    int getRamal() const{return ramal;}
    string getNome() const{return nome;}
    void setSal(double s){salario=s;}
    void setRamal(int r){ramal= r;}
    void setPrint(bool p){print=p;}
    static int getCount (){return cnt;}
    void printCount(bool a){
        int numbEmp=getCount();
        if(numbEmp>50 && !a && print){cout <<"\nQuantidade maxima atingida\n";}
        else if(numbEmp<10 && a && print){cout<<"\nQuantidade minima nao atingida\n";}
    }
};


bool Empregado::print=true;
int Empregado::cnt=0;
int main(){
 Empregado e("Jose",10000,6675);
 const Empregado e2=e;
 cout <<e2.getNome();
 Empregado *lista[55];
 for(int i=0;55>i;i++){
     lista[i]=new Empregado(e);
 }
 for(int i=0; i<55;i++){
     delete lista[i];
 }
 e.setPrint(false);
return 0;
}