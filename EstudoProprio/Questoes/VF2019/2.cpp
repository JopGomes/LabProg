#include <iostream>
#include <vector>
#define N 3
using namespace std;

template<unsigned int k>

class Nonacci{
    vector<int> numbers;
public:
    Nonacci(){
        numbers.push_back(0);
        for(int i=0 ; k>i;i++){
            numbers.push_back(1);
        }
    }
    int operator<<(unsigned int v){
        int aux;
        int size=numbers.size();
        while(v-size+1){
            v--;
            aux=0;
            for(int i=k;i>0;i--){
                aux+=numbers[numbers.size()-i];
            }
            numbers.push_back(aux);
        }
        return aux;
    }
};

int main(){
    int v=6;
    Nonacci<N> X;
    cout<<(X<<v)<<endl;
}