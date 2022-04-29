#include <iostream>
using std::cin;
using std::cout;

int main(){
    int *ptr, tamanho;
    cin >> tamanho;
    ptr = new(std::nothrow) int[tamanho];
    if(ptr==NULL){
        cout << "Erro";
    }
    else{
        cout << "Deu bom";
    }
}