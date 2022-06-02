#include <iostream>

using namespace std;

struct AcessoInvalido{
    int indice,count,lin;
    string erro;
    AcessoInvalido(int lin, string erro, int indice, int count):lin(lin),erro(erro),indice(indice),count(count){}
};

template <typename T>

class Conjunto{
    int size,count;
    T* elems;
public:
    Conjunto(int size)
    try
        :size(size),count(0),elems(new T[size]){}   
    catch(...){
        cout<<"Erro na criacao";
    }
    ~Conjunto(){
        try{delete []elems;}
        catch(...){}
    }
    Conjunto& operator +=(const T& item){//adiciona elemento
        if(size==count){
            return *this;
        }
        else{
            for(int i=0;i<count;i++){
                if(item==elems[i]){
                    return *this;
                }
            }
            elems[count++]=item;
            return *this;
        }
    }
    Conjunto& operator+=(const Conjunto& elems){//unir conjuntos
        for(int i=0; elems.count>i;i++){
            *this += elems.elems[i];
        }
        return *this;
    }
    Conjunto& operator-=(const T& item){//remove elemento
        int i;
        if(count==0){return *this;}
        for(i=0;count>i;i++){
            if(elems[i]==item){
                count--;
                break;
            }
        }
        for(int j=i;count>j;j++){
            swap(elems[j],elems[j+1]);
        }
        return *this;
    }
    Conjunto& operator-=(const Conjunto& elems){//tira um conjunto do outro
        for(int i=0;elems.count>i;i++){
            *this-=elems.elems[i];
        }
        return *this;
    }
    Conjunto& operator*=(const Conjunto& e){//interseção
        T valor;
        int i,j;
        for(i=count-1;i>=0;i--){
            valor = elems[i];
            for(j=0;j<count;j++){
                if(valor==e.elems[j]){
                    break;
                }
            }
            if(j==e.count-1){
                *this-=valor;
            }
        }
        return *this;
    }
    operator int (){//numero de elementos
        return count;
    }
    T operator[](int i){//acesso a elemento i
        if( i<count){
            return elems[i];
        }
        else throw AcessoInvalido(80,"return elems[i]",i,count);
    }
    void operator!(){//imprimir
        if(count==0){cout<<"Vazio\n";return;}
        for(int i=0;i<count;i++){
            cout<<elems[i]<<" ";
        }
        cout<<"\n";
    }
};


int main(){
    Conjunto <int> c1(10);
    Conjunto <int> c2(10);
    (c1+=1)+=3;
    c2+=2;
    // (c1+=c2);
    (c2+=4)+=1;
    !c1;
    !c2;
    c1*=c2;
    !c1;
    try{
        cout<<c1[100];
    }
    catch(AcessoInvalido a){
        cout<< a.erro<< " \n"<< a.indice<<">"<<a.count<<endl;
    }
    cout <<(int) c1<< " "<<c1;
    Conjunto <string> c3(10);
}