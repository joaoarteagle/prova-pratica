#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arvore.h>




struct Contato *criar_contato(char *nome, char *telefone) {
    struct Contato *novo_contato = (struct Contato *)malloc(sizeof(struct Contato));
    strcpy(novo_contato->nome, nome);
    strcpy(novo_contato->telefone, telefone);
    novo_contato->esquerda = NULL;
    novo_contato->direita = NULL;
    return novo_contato;
}

struct Contato *adicionar_contato_recursivamente(struct Contato *raiz, char *nome, char *telefone) {
    if (raiz == NULL) {
        return criar_contato(nome, telefone);
    }
    if (strcmp(nome, raiz->nome) < 0) {
        raiz->esquerda = adicionar_contato_recursivamente(raiz->esquerda, nome, telefone);
    } else if (strcmp(nome, raiz->nome) > 0) {
        raiz->direita = adicionar_contato_recursivamente(raiz->direita, nome, telefone);
    }
    return raiz;
}

void adicionar_contato(struct ArvoreBinariaBusca *arvore, char *nome, char *telefone) {
    arvore->raiz = adicionar_contato_recursivamente(arvore->raiz, nome, telefone);
}

struct Contato *buscar_contato_recursivamente(struct Contato *raiz, char *nome) {
    if (raiz == NULL || strcmp(nome, raiz->nome) == 0) {
        return raiz;
    }
    if (strcmp(nome, raiz->nome) < 0) {
        return buscar_contato_recursivamente(raiz->esquerda, nome);
    }
    return buscar_contato_recursivamente(raiz->direita, nome);
}

void buscar_contato(struct ArvoreBinariaBusca *arvore, char *nome) {
    struct Contato *contato = buscar_contato_recursivamente(arvore->raiz, nome);
    if (contato != NULL) {
        printf("Nome: %s, Telefone: %s\n", contato->nome, contato->telefone);
    } else {
        printf("Contato não encontrado.\n");
    }
}

int main() {
    struct ArvoreBinariaBusca arvore;
    arvore.raiz = NULL;

    adicionar_contato(&arvore, "Joao", "123456789");
    adicionar_contato(&arvore, "Maria", "987654321");

    buscar_contato(&arvore, "Joao");
    buscar_contato(&arvore, "Ana");

    return 0;
}
