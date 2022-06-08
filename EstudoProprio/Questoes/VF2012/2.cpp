#include <iostream>

using namespace std;

template <unsigned K>
struct Fatorial{
    static const unsigned result = (Fatorial<K-1>::result)*K;
};
template<> struct Fatorial<0>{
    static const unsigned result = 1;
};
template<> struct Fatorial<1>{
    static const unsigned result = 1;
};

template <unsigned int n >
struct sf{
    static const unsigned result = (Fatorial<n>::result)*(sf<n-1>::result);
};
template<> struct sf<0>{
    static const unsigned result = 1;
};
template<> struct sf<1>{
    static const unsigned result = 1;
};

int main(){
    cout << sf<5>::result<<endl;
}