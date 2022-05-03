#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class Jogador
{
private:
    string nome;
    int forca, velocidade, estilo, pontos;

public:
    Jogador(string name, int f, int v, int e, int pontos)
    {
        forca = f;
        velocidade = v;
        estilo = e;
        nome = name;
    }
    Jogador()
    {
        forca = 0;
        velocidade = 0;
        estilo = 0;
        nome = "";
    }
    int getPontos()
    {
        return pontos;
    }
};

class Goleiro : public Jogador
{
public:
    Goleiro(string name, int f, int v, int e, int CL, int Jogos) : Jogador(name, f, v, e, f * 2 + e * 3 - (Jogos - CL)) {}
};
class Apanhador : public Jogador
{
public:
    Apanhador(string name, int f, int v, int e, int pomos) : Jogador(name, f, v, e, f + e * 3 + v * 2 + 10 * pomos) {}
};
class Artilheiro : public Jogador
{
public:
    Artilheiro(string name, int f, int v, int e, int TC) : Jogador(name, f, v, e, f + v * 3 + e * 2 + 20 * TC) {}
};

class Batedor : public Jogador
{
public:
    Batedor(string name, int f, int v, int e, int BA)
    {
        int pontos = 3 * f + v + e;
        while (BA > 0)
        {
            pontos *= 2;
            BA /= 2;
        }
        Jogador(name, f, v, e, pontos);
    }
};

class QuadribolTime
{
private:
    string nomeT;
    Jogador *equipe;
    int Art, Bat, Apa, Gol,count;

public:
    QuadribolTime(string nome)
    {
        nomeT = nome;
        equipe = new Jogador[7];
        Art = Bat = Apa = Gol = 0;
        count=0;
    }
    void adicionarJogador(Goleiro a)
    {
        if (count >= 7)
        {
            Gol++;
            count++;
            equipe[count] = a;
        }
    }
    void adicionarJogador(Artilheiro a)
    {
        if (count >= 7)
        {
            Art++;
            count++;
            equipe[count] = a;
        }
    }
    void adicionarJogador(Apanhador a)
    {
        if (count >= 7)
        {
            Apa++;
            count++;
            equipe[count] = a;
        }
    }
    void adicionarJogador(Batedor a)
    {
        if (count >= 7)
        {
            Bat++;
            count++;
            equipe[count] = a;
        }
    }
    void alterarJogador(int n,Jogador a){
        equipe[n]= a;
    }
    int pegarHabilidadeTotal(){
        int total=0;
        if(Bat>2 || Gol >1 || Art >3 || Apa>1 || count !=6 ){return -1;}
        for(int i=0;count>i; i++){
            total+=equipe[i].getPontos();
        }
        return total;
    }
    string getNome(){
        return nomeT;
    }
    ~QuadribolTime(){
        delete[] equipe;
    }
};

class Partida{
    private:
    string res;
    public:
    Partida(){
        res="";
    }
    bool realizar(QuadribolTime t1,QuadribolTime t2, string res){
        if(t1.pegarHabilidadeTotal()!=-1 && t2.pegarHabilidadeTotal()!=-1){
            if(t1.pegarHabilidadeTotal()> t2.pegarHabilidadeTotal()){
                res=t1.getNome();
                return true;
            }
            if(t2.pegarHabilidadeTotal()> t1.pegarHabilidadeTotal()){
                res=t2.getNome();
                return true;
            }
            if(t1.pegarHabilidadeTotal()== t2.pegarHabilidadeTotal()){
                res="Empate";
                return true;
            }
        
        }
        else{return false;}
    }
};

int main()
{
    
}