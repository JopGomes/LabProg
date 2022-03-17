// // -------Introducao
// #include <iostream>
// #include <string>
// using namespace std;
// int main (){
// 		string s;
// 		cout<< "Por favor insitra um nome\n";
// 		cin >> s;
// 		cout << "oi, " << s << "\n";

// }

// ---------Classs
#include <iostream>

using namespace std;
class Complexo
{
public:
    double real, imag;
    Complexo soma(Complexo c)
    { // Soma
        return Complexo(real + c.real, imag + c.imag);
    }
    Complexo(double r, double i)
    { // Construtor
        real = r;
        imag = i;
    }
    Complexo()
    { // Polimorfismo do construtor, é acessado no c4 pois ele não tem parametros
        real = imag = 0;
    }
    ~Complexo()
    { // Destrutor observe o ~ em complexo antes
        cout << "Destrutor" << real<<endl;
    }
};

//podemos definir constructor fora da classe
// Complexo::Complexo(){

// }
}
int main()
{
    Complexo c1(1, -3), c2(-3, 10), c4;
    // c1+c2
    Complexo c3 = c1.soma(c2);
    cout << c3.real << "+" << c3.imag << "i"<<endl;
    return 0;
}