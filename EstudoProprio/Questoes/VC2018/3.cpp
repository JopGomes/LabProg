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
    }
    int seq(int val)
    {
        int size = fibs.size();
        auto it = find(fibs.begin(), fibs.end(), val);
        if (it != fibs.end())
        {
            return distance(it, fibs.begin()) + 1;
        }
        else if (*it == val)
        {
            return size;
        }
        else
        {
            int newComponent;
            while (newComponent != val)
            {
                auto it= fibs.rbegin();
                newComponent = (*it) + (*it--);
                fibs.push_back(newComponent);
            }
            return (size);
        }
    }
};

int main()
{
    Fib a1;
    cout << a1.seq(3);
}