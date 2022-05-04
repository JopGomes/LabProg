#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct stateS{
    double tempoMedio;
    double desistentes;
} state;// so criei pra resposta final la dele

class ClientePreferencial
{
private:
    string nome;
    int tempoC, tempoS;

public:
    ClientePreferencial(string name, int tempoChegada, int tempoServico, int tipo = 0) : nome(name), tempoC(tempoChegada), tempoS(tempoServico) {}
    ClientePreferencial()
    {
        nome = "";
        tempoC = -1;
        tempoS = 0;
    }
    int getTempoChegada()
    {
        return tempoC;
    }
    int getTempoServico()
    {
        return tempoS;
    }
};

class ClienteComum : public ClientePreferencial
{
private:
    int tempoE;

public:
    ClienteComum(string name, int tempoChegada, int tempoServico, int tempoEspera) : ClientePreferencial(name, tempoChegada, tempoServico), tempoE(tempoEspera) {}
    ClienteComum() : ClientePreferencial(), tempoE(0) {}
    int getTempoEspera()
    {
        return tempoE;
    }
};

class Banco
{
private:
    int tamMaximo, count;
    ClienteComum *caixaC;
    ClientePreferencial *caixaE;

public:
    Banco(int tamMax)
    {
        tamMaximo = tamMax;
        count = 0;
        caixaC = new ClienteComum[tamMax];
        caixaE = new ClientePreferencial[tamMax];
    }
    void adicionarCliente(ClienteComum c1)
    {
        if (tamMaximo <= count)
        {
            cout << "Limite alcancado"
                 << "\n";
        }
        else
        {
            count++;
            int i = 0;
            while (caixaC[i].getTempoChegada() >= c1.getTempoChegada())
            {
                i++;
            }
            ClienteComum temp(c1);
            ClienteComum temp2(caixaC[i]);
            for (i; tamMaximo > i; i++)
            {
                temp2 = caixaC[i];
                caixaC[i] = temp;
                temp = temp2;
            }
        }
    }
    void adicionarCliente(ClientePreferencial c1)
    {
        if (tamMaximo <= count)
        {
            cout << "Limite alcancado"
                 << "\n";
        }
        else
        {
            count++;
            int i = 0;
            while (caixaE[i].getTempoChegada() >= c1.getTempoChegada())
            {
                i++;
            }
            ClientePreferencial temp(c1);
            ClientePreferencial temp2(caixaC[i]);
            for (i; tamMaximo > i; i++)
            {
                temp2 = caixaE[i];
                caixaE[i] = temp;
                temp = temp2;
            }
        }
    }
    state simular()
    {
        //Tem jeito melhor de fazer mas varei o q era pra fazer nesse metodo quanto a printar e to adequando
        int des = 0, atendidosC = 0,atendidosE = 0, tempoPassadoC = 0, tempoPassadoE = 0,tempMax{};
        bool tempoA[1000]{}, tempoD[1000]{};
        state st;
        for (int i = 0; tamMaximo > i && caixaC[i].getTempoChegada() != -1; i++)
        {
            if (tempoPassadoC-caixaC[i].getTempoChegada() >= caixaC[i].getTempoEspera())
            {
                tempoD[tempoPassadoC]=true;
                des++;
                continue;
            }
            else
            {
               for(int k=tempoPassadoC; tempoPassadoC+caixaC[i].getTempoServico()>k;k++) tempoA[k]=true;
                tempoPassadoC += caixaC[i].getTempoServico();
                atendidosC++;
            }
        }
        if(tempoPassadoC>tempMax)tempMax=tempoPassadoC;
        for (int i = 0; tamMaximo > i && caixaE[i].getTempoChegada() != -1; i++)
        {
            for(int k=tempoPassadoE; tempoPassadoE+caixaE[i].getTempoServico()>k;k++) {tempoA[k]=true;}
            tempoPassadoE += caixaE[i].getTempoServico();
            atendidosE++;
        }
        if(tempoPassadoE>tempMax)tempMax=tempoPassadoE;
        for(int i=0;tempMax+2>i;i++){
            cout<<"tempo = ";
            if(tempoA[i] && tempoD[i]){
                cout << i <<" Desistentes: Sim" <<" Sendo atendidos:Sim";
            }
            if(tempoA[i] && !tempoD[i]){
                cout << i <<" Desistentes: Nao" <<" Sendo atendidos:Sim";
            }
            if(!tempoA[i] && tempoD[i]){
                cout << i <<" Desistentes: Sim" <<" Sendo atendidos:Nao";
            }
            if(!tempoA[i] && !tempoD[i]){
                cout << i <<" Desistentes: Nao" <<" Sendo atendidos:Nao";
            }
            cout <<"\n";
        }
        double info[2]{},medE{},medC{};
        info[0]=des;
        if(atendidosE+atendidosC){
            if(atendidosE)medE= tempoPassadoE/atendidosE;
            if(atendidosC)medC= tempoPassadoC/atendidosC;
            if(medE && medC) info[1]=(medE+medC)/2;
            else if(medE)info[1]=medE;
            else info[1]=medC;
        }
        else{
            cout << "Insira Clientes\n";
        }
        st.tempoMedio=info[1];
        st.desistentes=info[0];
        return st;
    }
    ~Banco()
    {
        delete[] caixaC;
        delete[] caixaE;
    }
};


int main()
{
    Banco b(10);
    ClienteComum cc1("Joao", 1, 3, 5);
    ClienteComum cc2("Maria", 2, 9, 6);
    ClienteComum cc3("Maria", 3, 4, 1);
    ClientePreferencial cp1("Ana", 1, 3);
    ClientePreferencial cp2("Jorge", 3, 5);
    b.adicionarCliente(cc2);
    b.adicionarCliente(cc1);
    b.adicionarCliente(cp2);
    b.adicionarCliente(cp1);
    state st= b.simular();
    cout << st.tempoMedio <<" "<< st.desistentes<< endl;
}