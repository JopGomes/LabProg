#include <iostream>

using namespace std;


class Contador{
    static int cnt;
    public:
    Contador(){
        cnt++;
    }
    Contador(const Contador &p){
        cnt++;
    }
    ~Contador(){
        cnt--;
    }
    static int lerContagem(){return cnt;}
};

int Contador::cnt=0;

int main(){
    Contador c1,c2;
    cout << c1.lerContagem()<<endl;
    Contador *c = new Contador;
    cout << c->lerContagem()<<endl;
    delete c;

    {
        Contador c3;
        cout << Contador::lerContagem()<<endl;
    }
    Contador c4=c2;
    cout << c4.lerContagem()<<endl;
}