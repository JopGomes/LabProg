#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

enum Tipo
{
    artilheiro,
    batedor,
    apanhador,
    goleiro,
    outros
};
class Jogador
{
private:
    string nome;
    int forca, velocidade, estilo, pontos;
    Tipo tipo;

public:
    Jogador(string name, int f, int v, int e, Tipo t = outros)
    {
        forca = f;
        velocidade = v;
        estilo = e;
        nome = name;
        tipo = t;
        pontos = 0;
    }
    Jogador(const Jogador &a)
    {
        forca = a.forca;
        velocidade = a.velocidade;
        estilo = a.estilo;
        nome = a.nome;
        tipo = a.tipo;
        pontos = a.pontos;
    }
    Jogador()
    {
        forca = 0;
        velocidade = 0;
        estilo = 0;
        nome = " ";
        tipo = outros;
        pontos = 0;
    }
    void setPontos(int value) { pontos = value; }
    int getForca() { return forca; }
    int getEstilo() { return estilo; }
    int getVelocidade() { return velocidade; }
    string getNome() { return nome; }
    int getPontos() { return pontos; }
    Tipo getTipo() { return tipo; }
};

class Goleiro : public Jogador
{
public:
    Goleiro(string name, int f, int v, int e, int CL, int Jogos) : Jogador(name, f, v, e, goleiro)
    {
        setPontos(f * 2 + e * 3 - (Jogos - CL));
    }
};
class Apanhador : public Jogador
{
public:
    Apanhador(string name, int f, int v, int e, int pomos) : Jogador(name, f, v, e, apanhador)
    {
        setPontos(f + e * 3 + v * 2 + 10 * pomos);
    }
};
class Artilheiro : public Jogador
{
public:
    Artilheiro(string name, int f, int v, int e, int TC) : Jogador(name, f, v, e, artilheiro)
    {
        setPontos(f + v * 3 + e * 2 + 20 * TC);
    }
};

class Batedor : public Jogador
{
public:
    Batedor(string name, int f, int v, int e, int BA) : Jogador(name, f, v, e, batedor)
    {

        setPontos(3 * f + v + e + (BA % 100) * 2);
    }
};

class QuadribolTime
{
private:
    string nomeT;
    Jogador *equipe;
    int count;

public:
    QuadribolTime(string nome) : nomeT(nome), count(0), equipe(new Jogador[7]) {}
    ~QuadribolTime()
    {
        delete[] equipe;
    }
    void adicionarJogador(Jogador a)
    {
        if (count < 7)
        {

            equipe[count] = a;
            count++;
        }
        else
        {
            cout << "Tamanho maximo alcancado\n";
        }
    }
    void alterarJogador(int indice, Jogador player)
    {
        if (indice >= 7)
        {
            cout << "Nao existe jogador com esse indice!" << endl;
        }
        else
        {
            Tipo tipoP = player.getTipo();
            int contArt = 0;
            int contBat = 0;
            int contAp = 0;
            int contGol = 0;
            for (int i = 0; i < count; i++)
            {
                Tipo tipo = equipe[i].getTipo();
                // cout << equipe[i].getVelocidade() <<"\n";
                if (tipo == artilheiro)
                {
                    contArt++;
                };
                if (tipo == batedor)
                {
                    contBat++;
                };
                if (tipo == apanhador)
                {
                    contAp++;
                };
                if (tipo == goleiro)
                {
                    contGol++;
                };
            }
            if (contArt < 3 && tipoP == artilheiro)
            {

                equipe[indice-1] = player;
                cout << "Jogador: " << player.getNome() << " adicionado no Time:  " << nomeT << " por alteracao" << endl;
            }
            else if (contBat < 2 && tipoP == batedor)
            {
                equipe[indice-1] = player;
                cout << "Jogador: " << equipe[indice].getNome() << " adicionado no Time:  " << nomeT << " por alteracao" << endl;
            }
            else if (contAp < 1 && tipoP == apanhador)
            {
                equipe[indice-1] = player;
                cout << "Jogador: " << player.getNome() << " adicionado no Time:  " << nomeT << " por alteracao" << endl;
            }
            else if (contGol < 1 && tipoP == goleiro)
            {
                equipe[indice-1] = player;
                cout << "Jogador: " << player.getNome() << " adicionado no Time:  " << nomeT << " por alteracao" << endl;
            }
            else
            {
                cout << "Nao eh possivel realizar a troca!" << endl;
            }
        }
    }
    int pegarHabilidadeTotal()
    {

        int total = 0;
        int Art{}, Bat{}, Apa{}, Gol{};
        for (int i = 0; count > i; i++)
        {
            total += equipe[i].getPontos();
            if (equipe[i].getTipo() == goleiro)
                Gol++;
            if (equipe[i].getTipo() == artilheiro)
                Art++;
            if (equipe[i].getTipo() == apanhador)
                Apa++;
            if (equipe[i].getTipo() == batedor)
                Bat++;
        }
        if (Bat != 2 || Gol != 1 || Art !=3 || Apa != 1 || count != 7)
        {
            return -1;
        }
        else
            return total;
    }
    string getNome()
    {
        return nomeT;
    }
};

class Partida
{
private:
    string result;

public:
    Partida()
    {
        result = "";
    }
    bool realizar(QuadribolTime &t1, QuadribolTime &t2, string &res)
    {
        int hab1 = t1.pegarHabilidadeTotal();
        int hab2 = t2.pegarHabilidadeTotal();
        if (hab1 != -1 && hab2 != -1)
        {
            if (hab1 > hab2)
            {
                res = t1.getNome();
                return true;
            }
            if (hab2 > hab1)
            {
                res = t2.getNome();
                return true;
            }
            if (hab1 == hab2)
            {
                res = "Empate";
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Goleiro go1("R", 5, 3, 4, 10, 20);
    Apanhador ap1("H", 3, 2, 6, 10);
    Batedor ba1("J", 3, 6, 4, 8), ba2("R", 3, 6, 3, 7);
    Artilheiro ar1("D", 5, 7, 3, 8), ar2("G", 10, 7, 3, 2), ar3("K", 2, 7, 4, 4);

    Goleiro go2("R", 5, 3, 4, 10, 50);
    Apanhador ap2("H", 5, 1, 5, 20);
    Batedor ba4("J", 3, 6, 4, 8), ba5("R", 3, 6, 3, 7);
    Artilheiro ar4("D", 5, 7, 3, 8), ar5("G", 10, 7, 3, 2), ar6("K", 2, 7, 4, 0);
    QuadribolTime q1("Grifinoria"), q2("Sonserina");
    q1.adicionarJogador(go1);
    q1.adicionarJogador(ap1);
    q1.adicionarJogador(ba1);
    q1.adicionarJogador(ap2);
    q1.adicionarJogador(ar1);
    q1.adicionarJogador(ar2);
    q1.adicionarJogador(ar3);

    q2.adicionarJogador(go2);
    q2.adicionarJogador(ap2);
    q2.adicionarJogador(ba4);
    q2.adicionarJogador(ba5);
    q2.adicionarJogador(ar4);
    q2.adicionarJogador(ar5);
    q2.adicionarJogador(ar6);

    Partida p;
    string res;
    bool b;
    b = p.realizar(q1, q2, res);
    if (b)
    {
        cout << q1.getNome() <<" X " <<q2.getNome() << " .>" << res << endl;
    }
    else
        cout << "Jogo Invalido\n";
    q1.alterarJogador(4, ba2);
    b = p.realizar(q1, q2, res);
    if (b)
    {
        cout << q1.getNome() <<" X " << q2.getNome() << " .>" << res << endl;
    }
    else
        cout << "Jogo Invalido\n";
}