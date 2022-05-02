#include <iostream>
#include <stdlib.h>
using namespace std;
// super heroi tem bonus de 10%
//  tem bonus no tempo de cadeia de a cada 5 anos + 5%

class SuperPoder
{
private:
    string nome;
    int categoria;

public:
    SuperPoder(string pNome, int pCategoria)
    {
        nome = pNome;
        categoria = pCategoria;
    }
    string getNome() { return nome; }
    int getCategoria() { return categoria; }
    void setNome(string pNome) { nome = pNome; }
    void setCategoria(int pCategoria) { categoria = pCategoria; }
};

class Personagem
{
private:
    string nome;
    string nomeVidaReal;
    SuperPoder **poderes;
    int nPoderes;

public:
    Personagem(string pNome, string pNomeVidaReal)
    {
        nome = pNome;
        nomeVidaReal = pNomeVidaReal;
        poderes = new SuperPoder *[4];
        nPoderes = 0;
    }
    Personagem(const Personagem &p)
    {
        nome = p.nome;
        nomeVidaReal = nomeVidaReal;
        poderes = new SuperPoder *[4];
        nPoderes = p.nPoderes;
        for (int i = 0; i < nPoderes; i++)
            poderes[i] = p.poderes[i];
    }
    string getNome() { return nome; }
    bool adicionaSuperPoder(SuperPoder &sp);
    double getPoderTotal();
    string getNomeVidaReal() { return nomeVidaReal; }
    void setNome(string pNome) { nome = pNome; }
    void setNomeVidaReal(string pNomeVidaReal) { nomeVidaReal = pNomeVidaReal; }
    ~Personagem() { delete[] poderes; }
    Personagem(const Personagem &p) : nome(p.nome), nomeVidaReal(p.nomeVidaReal), nPoderes(p.nPoderes)
    {
        for (int i = 0; i < p.nPoderes; i++)
        {
            poderes[i] = p.poderes[i];
        }
    };
};

bool Personagem::adicionaSuperPoder(SuperPoder &sp)
{
    if (nPoderes == 4)
        return false;
    poderes[nPoderes++] = &sp;
    return true;
};

double Personagem::getPoderTotal()
{
    double total;
    for (int i = 0; i < nPoderes; i++)
    {
        total += poderes[i]->getCategoria();
    }
    return total;
}

class Heroi : public Personagem
{
public:
    Heroi(string nome, string nomeVidaReal) : Personagem(nome, nomeVidaReal) {}
    double getPoderTotal()
    {
        return Personagem::getPoderTotal() * 1.1;
    }
};

class Vilao : public Personagem
{
private:
    double tempoCadeia;

public:
    Vilao(string nome, string nomeVidaReal, double tempoCadeia) : tempoCadeia(tempoCadeia), Personagem(nome, nomeVidaReal) {}
    double getTempo() { return tempoCadeia; }
    void setTempo(double tempoC) { tempoCadeia = tempoC; }
    double getPoderTotal()
    {

        return Personagem::getPoderTotal() * (1 + 0.1 * tempoCadeia);
    }
};

class Confronto
{
    int poderHeroi;
    string nomeHeroi;
    int poderVilao;
    string nomeVilao;

public:
    Confronto(double poderHeroi, string nomeHeroi, double poderVilao, string nomeVilao) : poderHeroi(poderHeroi),
                                                                                          nomeHeroi(nomeHeroi),
                                                                                          poderVilao(poderVilao),
                                                                                          nomeVilao(nomeVilao)
    {
    }
    void getResultado()
    {
        if (poderHeroi > poderVilao)
            cout << nomeHeroi;
        else if (poderHeroi < poderVilao)
            cout << nomeVilao;
        else
            cout << "Empate";
    }
};

int main()
{
    SuperPoder sp1("voo", 10), sp2("velocidade", 50);
    Heroi h1("Jop", "Joseph");
    Vilao v1("JOP2", "Joseph2", 3);
    v1.adicionaSuperPoder(sp1);
    h1.adicionaSuperPoder(sp2);
    cout << h1.getNome() << ": " << h1.getPoderTotal() << " " << v1.getNome() << ": " << v1.getPoderTotal() << "\n";
    Confronto c1(h1.getPoderTotal(), h1.getNome(), v1.getPoderTotal(), v1.getNome());

    c1.getResultado();
}