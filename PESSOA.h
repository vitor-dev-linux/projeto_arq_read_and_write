#include <iostream>
#include <cstring>
using namespace std;
class PESSOA{
    private:
        char nome[100]={};
        int idade=0;
        char email[150]={};
    public:
        PESSOA(){}
        PESSOA(string nome, int idade, string email){
            strcpy(this->nome,nome.c_str());
            this->idade=idade;
            strcpy(this->email,email.c_str());
        }
        string get_nome(){
            return this->nome;
        }
        int get_idade(){
            return this->idade;
        }
        string get_email(){
            return this->email;
        }
};