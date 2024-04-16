#ifndef TELEFONICA
#define TELEFONICA

#define MAX_CONTATOS 100

#include<contatoVetor.h>

struct ListaTelefonicaVetor {
    struct Contato contatos[MAX_CONTATOS];
    int tamanho;
};



void adicionar_contato(struct ListaTelefonicaVetor *lista, char *nome, char *telefone);
void remover_contato(struct ListaTelefonicaVetor *lista, char *nome);
void buscar_contato(struct ListaTelefonicaVetor *lista, char *nome);
#endif