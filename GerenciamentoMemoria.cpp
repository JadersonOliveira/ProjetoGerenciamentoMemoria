#include "GerenciamentoMemoria.h"
#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#include <stdio.h>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

GerenciamentoMemoria::GerenciamentoMemoria()
{
    inicializarTabela();
    acessoMemoria = 0;  //Quantas vezes a memoria fisica foi acessada
    falha = 0;  //Quantas vezes ocorreu falha ao acessar a tabela de paginas
    acerto = 0; //Quantas vezes ocorreu acerto ao acessar a memoria fisica
    operacaoES = 0; //Quantas vezes ocorreu uma operacao de entrada e saida
    referencia = 0;
    tlb_Acerto = 0;
    tlb_Falha = 0;
    cont = 0;
    cont2 = 0;
}

void GerenciamentoMemoria::converte()
{
    for ( int i = 0; i < n; i++)
    {
        binary[i] =bitset<16>(Vet[i]).to_string();
    }

}

void GerenciamentoMemoria::inicializarTabela()
{
    for(int i = 0; i < 1024; i++)
    {
        tabela[i] = 'I';
    }

}

void GerenciamentoMemoria::leitura()
{
    int temp;
    ifstream file;

    file.open("C:\\Users\\User\\Documents\\sequencia01.dat", ios::binary);

    if(!file.is_open())
    {
        cout<<"error";
    }
    for(int i=0; i<n; i++)
    {
        file>>temp;
        Vet[i] = temp;
    }

    file.close();

}

void GerenciamentoMemoria::interpretadorEndereco()
{
    leitura();
    converte();



    char numeropagina[10];
    char deslocamento[6];

    string atual;

    for(int k = 0; k < n; k++)
    {
        referencia++;
        atual = binary[k];

        int l = 0;
        for(int i = 10; i <= 15; i++)
        {
            deslocamento[l] = atual[i];
            l++;
        }

        unsigned long deslocamento_string = bitset<6>(deslocamento).to_ulong(); //CONVERTI TIPO CHAR PARA INT
        //string binary_deslocamento = bitset<6>(deslocamento_string).to_string();
        Deslocamento = deslocamento_string;

        int j = 0;
        for(int i = 0; i <= 9; i++)
        {
            numeropagina[j] = atual[i];
            j++;
        }

        unsigned long numeropagina_string = bitset<10>(numeropagina).to_ulong(); //CONVERTI TIPO CHAR PARA INT
        //string binary_numeropagina = bitset<10>(numeropagina_string).to_string();
        numeroPagina = numeropagina_string;
       // cout<<numeroPagina<<endl;

        checarTabelaPagina();

    }

}

void GerenciamentoMemoria::checarTabelaPagina()
{
    acessoMemoria++;

    if(tabela[numeroPagina] == 'I'){
        falha++;
        tabela[numeroPagina] = 'V';
        operacaoES++;
    }else{
        acessoMemoria++;
        acerto++;
    }

}

void GerenciamentoMemoria::impressao()
{

    cout<<"------GERENCIAMENTO POR PAGINACAO------"<<endl;
    cout<<"Falhas: "<<falha<<endl;
    cout<<"Acertos: "<<acerto<<endl;
    cout<<"Operacoes de ES: "<<operacaoES<<endl;
    cout<<"Acessos de Memoria: "<<acessoMemoria<<endl;
    cout<<"Referencia: "<<referencia<<endl;

}
