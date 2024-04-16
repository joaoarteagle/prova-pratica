#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <telefonica.h>

//com vetor

void adicionar_contato(struct ListaTelefonicaVetor *lista, char *nome, char *telefone) {
    if (lista->tamanho < MAX_CONTATOS) {
        strcpy(lista->contatos[lista->tamanho].nome, nome);
        strcpy(lista->contatos[lista->tamanho].telefone, telefone);
        lista->tamanho++;
    } else {
        printf("Lista cheia. Não é possível adicionar mais contatos.\n");
    }
}

void remover_contato(struct ListaTelefonicaVetor *lista, char *nome) {
    int i, encontrado = 0;
    for (i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->contatos[i].nome, nome) == 0) {
            encontrado = 1;
            break;
        }
    }
    if (encontrado) {
        for (; i < lista->tamanho - 1; i++) {
            strcpy(lista->contatos[i].nome, lista->contatos[i + 1].nome);
            strcpy(lista->contatos[i].telefone, lista->contatos[i + 1].telefone);
        }
        lista->tamanho--;
        printf("Contato removido com sucesso.\n");
    } else {
        printf("Contato não encontrado.\n");
    }
}

void buscar_contato(struct ListaTelefonicaVetor *lista, char *nome) {
    int i, encontrado = 0;
    for (i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->contatos[i].nome, nome) == 0) {
            printf("Nome: %s, Telefone: %s\n", lista->contatos[i].nome, lista->contatos[i].telefone);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

int main() {
    struct ListaTelefonicaVetor lista;
    lista.tamanho = 0;

    adicionar_contato(&lista, "Joao", "123456789");
    adicionar_contato(&lista, "Maria", "987654321");

    buscar_contato(&lista, "Joao");
    buscar_contato(&lista, "Ana");

    remover_contato(&lista, "Maria");

    return 0;
}
