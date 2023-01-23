#include <iostream>
#include <fstream>
#include "PESSOA.h"
using namespace std;
//----------------
PESSOA* FN_dinamico(PESSOA*,int&);
PESSOA* FN_arq();
PESSOA* FN_write();
PESSOA* FN_read();
int FN_arq_tam();

//----------------
int FN_arq_tam(){
    ifstream arq("dados.bin",ios::binary);
    if(!arq){
        return 0;
    }
    else{
        arq.seekg(0,arq.end);
        int tam=arq.tellg()/254;//254 é a soma da mémoria dos atributos do objeto PESSOA sendo 254=nome[100]+email[150]+int-->tam4;
        arq.seekg(0,arq.beg);
        arq.close();
        arq.clear();
        return tam;
    }
}
PESSOA* FN_dinamico(PESSOA*antigo,int&tam){
    PESSOA* novo=new PESSOA[tam+1];
    for(int i=0;i<tam;i++){
        novo[i]=PESSOA(antigo[i].get_nome(),antigo[i].get_idade(),antigo[i].get_email());
    }
    delete[]antigo;
    tam++;
    return novo;
}
PESSOA* FN_arq(){;
    ifstream arq("dados.bin",ios::binary);
    if(!arq){
        arq.close();
        arq.clear();
        return FN_write();
    }
    else{
        arq.close();
        arq.clear();
        return FN_read();
    }
}
PESSOA* FN_write(){
    ofstream arq("dados.bin",ios::binary);
    int tam=1,indice=0;
    PESSOA* pessoas=new PESSOA[tam];
    string nome="",email="";
    int idade=0;
    cout<<"Olá adm, não foi encontrado nenhum arquivo dados.bin válido, então vamos cadastrar os primieros os usuários."<<endl;
    system("sleep 5 && clear");
    cout<<"Insira um nome para novo usuário ou NOT para parar de inserir usuários: ";
    getline(cin>>ws,nome);
    while(nome!="NOT"){
        if(indice==0){
            cout<<"Insira idade: ";
            cin>>idade;
            cout<<"Insira email: ";
            getline(cin>>ws,email);
            pessoas[indice]=PESSOA(nome,idade,email);
            indice++;
            char nome_aux[100];
            strcpy(nome_aux,nome.c_str());
            char email_aux[150];
            strcpy(email_aux,email.c_str());
            arq.write((const char*)nome_aux,100*sizeof(char));
            arq.write((const char*)&idade,sizeof(int));
            arq.write((const char*)email_aux,150*sizeof(char));
            nome="";idade=0;email="";
            system("clear");
            cout<<"Insira um nome para novo usuário ou NOT para parar de inserir usuários: ";
            getline(cin>>ws,nome);
        }
        else{
            cout<<"Insira idade: ";
            cin>>idade;
            cout<<"Insira email: ";
            getline(cin>>ws,email);
            pessoas=FN_dinamico(pessoas,tam);
            indice=tam-1;
            pessoas[indice]=PESSOA(nome,idade,email);
            char nome_aux[100];
            strcpy(nome_aux,nome.c_str());
            char email_aux[150];
            strcpy(email_aux,email.c_str());
            arq.write((const char*)nome_aux,100*sizeof(char));
            arq.write((const char*)&idade,sizeof(int));
            arq.write((const char*)email_aux,150*sizeof(char));
            nome="";idade=0;email="";
            system("clear");
            cout<<"Insira um nome para novo usuário ou NOT para parar de inserir usuários: ";
            getline(cin>>ws,nome);
        }
    }
    //arq.write((const char*)pessoas,tam*sizeof(PESSOA));
    arq.close();
    arq.clear();
    return pessoas;
}
PESSOA* FN_read(){
    ifstream arq("dados.bin",ios::binary);
    int tam=1,indice=0;
    PESSOA* pessoas=new PESSOA[tam];
    while(!arq.eof()){
        char Nome[100],Email[150];
        int idade;
        arq.read((char*)Nome,100*sizeof(char));
        arq.read((char*)&idade,1*sizeof(int));
        arq.read((char*)Email,150*sizeof(char));
        string nome=Nome;
        string email=Email;
        if(indice==0){
            pessoas[indice]=PESSOA(nome,idade,email);
            nome="";idade=0;email="";
            indice++;
        }
        else{
            pessoas=FN_dinamico(pessoas,tam);
            indice=tam-1;
            pessoas[indice]=PESSOA(nome,idade,email);
            nome="";idade=0;email="";
        }
    }
    return pessoas;
}