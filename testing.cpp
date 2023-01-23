#include <iostream>
#include "PESSOA.h"
#include <fstream>
using namespace std;
int main(){
    system("clear");
    ifstream arq("dados.bin",ios::binary);
    arq.seekg(0,arq.end);
    cout<<arq.tellg()<<endl;
    arq.seekg(0,arq.beg);
    cout<<arq.tellg()<<endl;
    cout<<sizeof(PESSOA)<<endl;
    cout<<sizeof(int)<<endl;
    cout<<"concluo que o tamanho de user é de >> "<<arq.tellg()/254<<endl;
    return 0;
}