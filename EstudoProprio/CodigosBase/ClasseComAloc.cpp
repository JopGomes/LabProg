#include <iostream>
using namespace std;

class Deque
{
public:
    int *deque;
    int max;
    int atual;
    Deque(int tam)
    {
        deque = new int [tam]{};
        max = tam;
        atual=0;
    }
    Deque(const Deque &p)
    {
        max = p.max;
        atual=p.atual;
        deque = new int[max];
        for (int i = 0; i < max; i++)
        {
            deque[i] = p.deque[i];
        }
    }
    void imprimir(){
        for(int i = 0; i<atual;i++){
            cout << deque[i]<<" ";
        }
        cout << "\n";
    }
    ~Deque()
    {
        delete[] deque;
    }
};