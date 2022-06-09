#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

// template <typename T> class Pilha {
//     int tamanho, topo;
//     T* ptrPilha;
//   public:
//     Pilha(int tamanho=10) : tamanho(tamanho), topo(0) {
//         ptrPilha = new T[tamanho];
//     }
//     bool inserir(const T& valor);
// };

// template <typename T> bool Pilha<T>::inserir(const T& valor){
//     if(topo<tamanho){
//         ptrPilha[topo++]=valor;
//         return true;
//     } else return false;
// }
#define N 3
template <int Q> class Nonacci {
  
  public:
    long long operator<<(int v){
        int dp[v]={0};
        for(int i=0;i<Q;i++)
            dp[i]=1;
        for(int i=Q;i<v;i++){
            for(int j=1;j<=Q;j++){
                dp[i]+=dp[i-j];
            }
        }
        return dp[v-1];
    }
};
int main(){
    ofstream file("data.txt");
    auto buffer_file = file.rdbuf();
    
    auto buffer = cout.rdbuf();
    cout.rdbuf(buffer_file);

    int v=7;
    Nonacci<N> X;
    std::ostream out(buffer);
    cout << (X << v) << endl;

    cout.rdbuf(buffer);
    cout << (X << v+1) << endl;
    return 0;
}