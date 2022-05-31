#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
int total;
class Candidate{
    string name;
    string party;
    int votes;
    int num;
public:
    Candidate(int num,string name, string party):name(name),party(party),votes(0),num(num){}
    void addVote(){votes++; total++; }
    int getVote(){return votes;}
    int getNum(){return num;}
    string getName(){return name;}
    string getPartido(){return party;}
    static int getTotal(){return total;}

};

bool sortVotes(Candidate a, Candidate b){
    if(a.getVote()>b.getVote())return true;
    else return false;

}
int main(){
    vector<Candidate> candidates;
    fstream candi;
    int num;
    string nam,part;

    candi.open("candidatos.txt",ios::in);
    if(!candi.is_open()){return 1;}
    while(!candi.eof()){
        candi >> num >> nam >> part;
        if(candi.eof())continue;
        candidates.push_back(Candidate(num,nam,part));
    }

    candi.close();
    for(int i =0; i<4 ; i++){
        ostringstream nomeUrna;
        nomeUrna << "urna"<<i+1<<".txt";
        ifstream urnaArq(nomeUrna.str());
        if(!urnaArq.is_open()){return 2;}
        while(!urnaArq.eof()){
            urnaArq>> num;
            if(urnaArq.eof())continue;
            candidates[num-1].addVote();
        }
        urnaArq.close();
    }

    sort(candidates.begin(),candidates.end(),sortVotes);

    ofstream Output("output.txt");
    for(int i = 0;candidates.size()>i;i++){
        Output<< candidates[i].getName()<<"-"<<candidates[i].getVote()<<"-"<< (candidates[i].getVote()+0.0)/candidates[i].getTotal() *100  << "% "  << "\n";
        cout<<candidates[i].getName()<<" "<< candidates[i].getPartido()<<" "<<candidates[i].getVote()<<"-"<< (candidates[i].getVote()+0.0)/candidates[i].getTotal() *100  << "% " << setw(10) << "\n";
    }

    Output.close();
    return 0;
}