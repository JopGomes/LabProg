#include <iostream>

int main()
{
    try
    {
        int *x = new int[10000000000000000000000]; // excessão é se tiver muito grande
    }
    catch(...){
        std:: cout << "Errou\n";
    }
    std::cout<<"Oi";
}