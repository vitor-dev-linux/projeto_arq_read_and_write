#include <iostream>
//#include "PESSOA.h"
#include "Funcoes.h"
using namespace std;
class PESSOA;
int main(){
    int Q_pessoas=FN_arq_tam();
    PESSOA* pessoas=FN_arq();
    system("clear");
    for(int i=0;i<Q_pessoas;i++){
        cout<<"========================================="<<endl;
        cout<<"Dados USER ID>> "<<i<<":: "<<endl;
        cout<<"NOME:: "<<pessoas[i].get_nome()<<endl;
        cout<<"IDADE:: "<<pessoas[i].get_idade()<<endl;
        cout<<"EMAIL:: "<<pessoas[i].get_email()<<endl;
    }
    delete[]pessoas;
    return 0;
}