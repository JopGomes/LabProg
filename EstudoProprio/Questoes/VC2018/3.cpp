#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Fib
{
    vector<int> fibs;
    int pos;

public:
    Fib()
    {
        pos = 1;
        fibs.push_back(0);
        fibs.push_back(1);
        fibs.push_back(1);
    }
    int seq(int pos)
    {
        int size = fibs.size();
        if (pos>=size)
        {
           int newComponent;
            while (pos-size+1)
            {
                newComponent = fibs[fibs.size()-1] + fibs[fibs.size()-2];
                fibs.push_back(newComponent);
                pos--;
            }
            return newComponent;
        }
        else 
        {
            return fibs[pos];
        }
    }
    int getPos(int numFib){
        int pos=0;
        while(seq(pos) != numFib){
            pos++;
        }
        return pos;
    }
};

int main()
{
    Fib a1;
    cout << a1.seq(0)<<endl;
    cout << a1.seq(1)<<endl;
    cout << a1.seq(2)<<endl;
    cout << a1.seq(3)<<endl;
    cout << a1.getPos(3)<<endl;
}