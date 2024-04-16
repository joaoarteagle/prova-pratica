#ifndef LISTATELEFONICA
#define LISTATELEFONICA
#include<contatoLista.h>

struct ListaTelefonicaListaEncadeada {
    struct Contato *cabeca;
};

void adicionar_contato(struct ListaTelefonicaListaEncadeada *lista, char *nome, char *telefone);
void remover_contato(struct ListaTelefonicaListaEncadeada *lista, char *nome);
void buscar_contato(struct ListaTelefonicaListaEncadeada *lista, char *nome);
#endif