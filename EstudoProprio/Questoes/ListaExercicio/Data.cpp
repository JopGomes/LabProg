#include <stdio.h>
#include <iostream>
using namespace std;

int Dias(int mes, int ano)
{
    if(mes>12){
        mes = mes%12;
    }
    int dia = 0;
    switch (mes)
    {
    case 1:
        dia = 31;
        break;
    case 2 : if (ano % 400)
        {
            dia=28;
            break;
        }
        else{
            dia=29;
            break;
        }
    case 3:
        dia= 31;
        break;
    case 4:
        dia= 30;break;
    case 5:
        dia =31; break;
    case 6:
        dia=30;break;
    case 7:
        dia= 31;break;
    case 8:
        dia=30;break;
    case 9:
        dia=31;break;
    case 10:
        dia= 30;break;
    case 11:
        dia= 31;break;
    case 12:
        dia=30;break;
    default:
        dia=-1;break;
    }
    return dia;
}

void normalizar(int *dia, int *mes, int *ano)
{
    if (*mes > 12)
    {
        int countAno = *mes/12;
        *mes = *mes%12;
        *ano += countAno;
    }
    if(*mes < 1) *mes =1;
    if (1 > *ano){*ano = 1;}
    int diaMax = Dias(*mes, *ano);
    if (*dia > diaMax)
    {
        int countMes = *dia / diaMax;
        *dia = *dia % diaMax;
        *mes += countMes;
    }
    if(*dia < 1) *dia =1;
    if (*mes > 12)
    {
        int countAno = *mes/12;
        *mes = *mes%12;
        *ano += countAno;
    }
}

class Data
{
    int dia, mes, ano;

public:
    Data(int d, int m, int a)
    {
        normalizar(&d,&m,&a);
        dia = d;
        mes = m;
        ano = a;
    }
    Data(){
        dia=1;
        mes=1;
        ano=1;
    }
    void reiniciar(int d, int m, int a)
    {
        normalizar(&d,&m,&a);
        dia = d;
        mes = m;
        ano = a;
    }
    void adiantar(int d, int m, int a)
    {
        dia += d;
        mes += m;
        ano += a;
        normalizar(&dia,&mes,&ano);
    }
    int getDia(){
        return dia;
    }
    int getMes(){
        return mes;
    }
    int getAno(){
        return ano;
    }
    void ler(){
        cout << "Dia "<<  getDia() << " do mes " << getMes()<< " de "<<getAno() <<"\n"<<endl;
    }

};

int main()
{
    Data a(30,10,2001), b(31,10,2001), c(31,12,2002), d(-1,-1,-1),e(30,2,2000);
    a.ler();
    b.ler();
    c.ler();
    d.ler();
    e.ler();
}