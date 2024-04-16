#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <listaTelefonica.h>


void adicionar_contato(struct ListaTelefonicaListaEncadeada *lista, char *nome, char *telefone) {
    struct Contato *novo_contato = (struct Contato *)malloc(sizeof(struct Contato));
    strcpy(novo_contato->nome, nome);
    strcpy(novo_contato->telefone, telefone);
    novo_contato->prox = NULL;

    if (lista->cabeca == NULL || strcmp(lista->cabeca->nome, nome) > 0) {
        novo_contato->prox = lista->cabeca;
        lista->cabeca = novo_contato;
    } else {
        struct Contato *atual = lista->cabeca;
        while (atual->prox != NULL && strcmp(atual->prox->nome, nome) < 0) {
            atual = atual->prox;
        }
        novo_contato->prox = atual->prox;
        atual->prox = novo_contato;
    }
}

void remover_contato(struct ListaTelefonicaListaEncadeada *lista, char *nome) {
    struct Contato *atual = lista->cabeca;
    struct Contato *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->prox = atual->prox;
        } else {
            lista->cabeca = atual->prox;
        }
        free(atual);
        printf("Contato removido com sucesso.\n");
    } else {
        printf("Contato não encontrado.\n");
    }
}

void buscar_contato(struct ListaTelefonicaListaEncadeada *lista, char *nome) {
    struct Contato *atual = lista->cabeca;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        atual = atual->prox;
    }
    if (atual != NULL) {
        printf("Nome: %s, Telefone: %s\n", atual->nome, atual->telefone);
    } else {
        printf("Contato não encontrado.\n");
    }
}

int main() {
    struct ListaTelefonicaListaEncadeada lista;
    lista.cabeca = NULL;

    adicionar_contato(&lista, "Joao", "123456789");
    adicionar_contato(&lista, "Maria", "987654321");

    buscar_contato(&lista, "Joao");
    buscar_contato(&lista, "Ana");

    remover_contato(&lista, "Maria");

    return 0;
}
