#include <iostream>

using namespace std;

class MinhaClasse
{
public:
    int *ponteiro, a;
    MinhaClasse()
    {
        ponteiro = (int *)malloc(10 * sizeof(int));
        a = 5;
    }
    MinhaClasse(const MinhaClasse &mc){
        a = mc.a;
        ponteiro = (int*) malloc(10*sizeof(int));
        for(int i=0;i<10;i++){
            ponteiro[i]=mc.ponteiro[i];
        }
    }
    ~MinhaClasse()
    {
        free(ponteiro);
    }
};


int main()
{
    MinhaClasse c1;
    MinhaClasse c2(c1);
    cout << c1.ponteiro[1]<<" "<< c1.a;
    return 0;
}