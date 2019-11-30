#ifndef GERENCIAMENTOMEMORIA_H_INCLUDED
#define GERENCIAMENTOMEMORIA_H_INCLUDED
#include <iostream>
#include <cstdint>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int n = 16384;   // Variavel para determinar o total de elementos
string binary[n];   // Variavel do tipo String para armazenar o endereço virtual no tipo binário
int Vet[n];     // Vetor para armazenar os endereços virtuais no tipo inteiro

int numeroPagina;	// Variavel para armazenar o numero da pagina
int Deslocamento;	// Variavel para armazenar o deslocamento

class GerenciamentoMemoria
{
    public:
        GerenciamentoMemoria(); //Construtor da classe
        void leitura(); //Funcao para fazer a leitura do endereço virtual no arquivo tipo .dat e armazenar no vetor
        void converte();    //Função para converter de decimal para binário
        void interpretadorEndereco();   //Obtendo numero de paginas e deslocamento da memoria virtual
        void inicializarTabela();   //Inicializando a tabela de paginas com 'I' de invalido
        void inicializarTabela_TLB(); //Inicializando a tabela de paginas da TLB com 'I' de invalido
        void checarTLB();
        char tabela[1024];  //Criando a tabela de paginas com 1024 paginas
        void checarTabelaPagina();  //Chegar se a pagina do endereço virtual está na tabela
        int acessoMemoria;  //Quantas vezes a memoria fisica foi acessada
        void impressao(); //Impressao do total de falhas, acertos, operacoes de ES, acessos a memoria e referencia
        int falha;  //Quantas vezes ocorreu falha ao acessar a tabela de paginas
        int acerto; //Quantas vezes ocorreu acerto ao acessar a memoria fisica
        int tlb_Acerto;
        int tlb_Falha;
        int operacaoES; //Quantas vezes ocorreu uma operacao de entrada e saida
        int referencia;
        int cont;
        int cont2;

    private:


};

#endif // GERENCIAMENTOMEMORIA_H_INCLUDED
