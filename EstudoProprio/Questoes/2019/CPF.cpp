#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

string verificador(string a){
    int sum=0;
    string verificadores;
    int size=a.size();
    int b;
    for(int i=0;i < size; i++){
        b=(int) a[9-i];
        sum=sum+(b)*(i+2);
    }
    if(sum%11==1 || sum%11==0){
        verificadores.append(to_string(0));
    }
    else{
        verificadores.append(to_string(11- sum%11)) ;
    }
    sum=0;
    for(int i=0;i < size; i++){
        sum=sum+((a[9-i]-48))*(i+3);
    }
    sum+= 2*stoi(verificadores);
    if(sum%11==1 || sum%11==0){
        verificadores.append(to_string(0));
    }
    else{
        verificadores.append(to_string(11- sum%11)) ;
    }
    return verificadores;
}

class CPF{
    private:
    string cpf;
    public:
    CPF(string nums){
       cpf=nums; 
    }
    string setCPF(string nums){
        string verificadores;
        verificadores=verificador(nums);
        cpf= cpf + verificadores[0]+verificadores[1];
        return verificadores;
    }
    bool checagem(string nums){
        string verificadores;
        string teste=nums.substr(9,2);
        verificadores=setCPF(nums.substr(0,9));
        if(teste==verificadores){
            return true;
        }
        else{
            return false;
        }
    }
    void imprimir(){
        for(int i=0; 3>i;i++){
            cout << cpf[i];
        }
        cout <<".";
        for(int i=3; 6>i;i++){
            cout << cpf[i];
        }
        cout <<".";
        for(int i=6; 9>i;i++){
            cout << cpf[i];
        }
        cout <<"-";
        for(int i=9; 11>i;i++){
            cout << cpf[i];
        }
        cout <<"\n";

    }
};

int main(){
    CPF a("031048795");
    a.imprimir();
    a.setCPF("529982247");
    a.imprimir();
}