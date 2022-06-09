#include <iostream>
#include <cmath>
using namespace std;

class polinomio
{
public:
    float a,b, x;
    int n;
    polinomio(float x, float a = 0,float b = 0, int n = 0) : x(x), a(a),b(b), n(n) {}
    polinomio operator+(float b)
    {
        return polinomio(x, a, b);
    }
    float operator^(int ldo)
    {
        return a*pow(x,ldo)+b;
    };
};

polinomio operator+(int leo, polinomio ldo)
{
    return polinomio(ldo.x,leo);
};

int main()
{
    float a, b, x, y;
    int n;
    cin >> a >> x >> n >> b;
    polinomio pol(x);
    y = a + pol + b ^ n;
    cout << y;
}