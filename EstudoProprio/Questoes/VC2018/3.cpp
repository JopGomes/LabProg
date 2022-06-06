#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Fib(){
    vector<int> fibs;
    int pos;
public:
    Fib(){
        pos=1;
        fibs.push_back(0);
        fibs.push_back(1);
    }
    int seq(int val){
        auto it= find(fibs.begin(),fibs.end(),val);
        if(it!=fibs.end()){return (it - fibs.begin())++;}
        else if(*it==val){return val.size();}
        else{
           int newComponent;
           
        }
    }
}



int main(){

}