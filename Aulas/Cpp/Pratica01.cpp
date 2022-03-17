// Implementar uma classe Ponto;
//  Atributos 3-d(x,y,z) privativos;
//  Metodo para calculo de distância ( entre dois pontos)
#include <iostream>
#include<math.h>
using namespace std;
class Ponto
{
private:
    double x, y, z;

public:
    // Formula de Constructor usando parametros privados
    Ponto(int x1, int y1, int z1) { x = x1, y = y1, z = z1; }
    float distancia(Ponto pont1)
    { // Função para calcular distancia
        
        return sqrt((pont1.x - x) * (pont1.x - x) + (pont1.y - y) * (pont1.y - y) + (pont1.z - z) * (pont1.z - z));
    }
};

int main()
{
    Ponto origem(0, 0, 0), ponto1(1, 1, 2), ponto2(1, 1, 1);
    // Distancia entre pontos
    float dist1 = origem.distancia(ponto1);
    float dist2 = origem.distancia(ponto2);
    float dist3 = ponto1.distancia(ponto2);
    cout << dist1 <<" "<< dist2<< " "<< dist3<< endl;
    return 0;
}