#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

class Matriz{
    int **matriz;
    int tam;

    public:
    Matriz(int n){
        tam=n;
        matriz = new int*[n];
        for(int i=0; n>i;i++){
            matriz[i]=new int[n];
        }
        for(int i=0; tam>i;i++){
            for(int j=0;tam>j;j++){
                matriz[i][j]=0;
            }
        }
    }
    Matriz(const Matriz& p){
        tam=p.tam;
        matriz = new int*[p.tam];
        for(int i=0; p.tam>i;i++){
            matriz[i]=new int[p.tam];
        }
        for(int i=0; tam>i;i++){
            for(int j=0;tam>j;j++){
                matriz[i][j]=p.matriz[i][j];
            }
        }
    }
    ~Matriz(){
        for(int i=0; tam>i;i++){
            delete matriz[i];
        }
        delete[] matriz;
    }
    void imprimir(){
        for(int i=0; tam>i;i++){
            cout<<endl;
            for(int j=0;tam>j;j++){
                cout<<setw(5)<< matriz[i][j]<<" ";
            }
        }
        cout<< endl;
    }
    void setMatriz(int i,int j,int valor){
        matriz[i-1][j-1]=valor;
    }
    int** getMatriz(){
        return matriz;
    }
    int getTam(){return tam;}
    Matriz& operator+=(Matriz rhs){
        if(tam!= rhs.getTam()){return *this;}
        for(int i=0; tam>i;i++){
            for(int j=0;tam>j;j++){
                matriz[i][j]+=rhs.getMatriz()[i][j];
            }
        }
        return *this;        
    }
    Matriz operator+(Matriz rhs){
        if(tam!= rhs.getTam()){return *this;}
        Matriz aux(tam);
        for(int i=0; tam>i;i++){
            for(int j=0;tam>j;j++){
                aux.getMatriz()[i][j]=matriz[i][j]+rhs.getMatriz()[i][j];
            }
        }
        return aux;        
    }
    Matriz operator*(Matriz rhs){
        if(tam!= rhs.getTam()){return *this;}
        Matriz aux(tam);
        for(int i=0;tam>i;i++){
            for(int j=0;tam>j;j++){
                for(int k=0;tam>k;k++){
                    aux.getMatriz()[i][j]+=matriz[i][k]*rhs.getMatriz()[k][j];
                }
            }
        }
        return aux;
    }   
    // Matriz operator*=(Matriz rhs){
    //     if(tam!= rhs.getTam()){return *this;}
    //     Matriz aux(tam);
    //     for(int i=0;tam>i;i++){
    //         for(int j=0;tam>j;j++){
    //             for(int k=0;tam>k;k++){
    //                 aux.getMatriz()[i][j]+=matriz[i][k]*rhs.getMatriz()[k][j];
    //             }
    //         }
    //     }
    //     *this = aux;
    //     return *this;
    // }   
};


int main(){
    Matriz m1(5);
    m1.imprimir();
    m1.setMatriz(1,1,2);
    m1.setMatriz(5,1,2);
    m1.imprimir();
    Matriz m2(5);
    m2.setMatriz(1,1,11);
    m2.setMatriz(5,1,11);
    m1+=m2;
    m1.imprimir();
    Matriz m3(5);
    m3=(m1*m2);
    m3.imprimir();
}