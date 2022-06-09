#include <sstream>
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

char* conv(stringstream &o){
    string s = o.str();
    char* c = new char[s.size()];
    for(int i=0; s.size()>i;i++){
        c[i]=s[i];
    }
    return c;
}


int main(){
    char cadeia[]={'a','b'};
    stringstream o;
    o<<"testei";
    strcpy(cadeia,conv(o));
    cout <<cadeia;
}