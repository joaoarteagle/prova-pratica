#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <noArvore.h>


// Função para criar um novo nó da árvore
struct NoArvore* criar_no(char *palavra) {
    struct NoArvore* novo_no = (struct NoArvore*)malloc(sizeof(struct NoArvore));
    strcpy(novo_no->palavra, palavra);
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

// Função para adicionar uma palavra à árvore
void adicionar_palavra(struct NoArvore** raiz, char *palavra) {
    if (*raiz == NULL) {
        *raiz = criar_no(palavra);
    } else {
        if (strcasecmp((*raiz)->palavra, palavra) > 0) {
            adicionar_palavra(&((*raiz)->esquerda), palavra);
        } else {
            adicionar_palavra(&((*raiz)->direita), palavra);
        }
    }
}

// Função para buscar uma palavra na árvore
int buscar_palavra(struct NoArvore* raiz, char *palavra) {
    if (raiz == NULL) {
        return 0;
    } else {
        if (strcasecmp(raiz->palavra, palavra) == 0) {
            return 1;
        } else if (strcasecmp(raiz->palavra, palavra) > 0) {
            return buscar_palavra(raiz->esquerda, palavra);
        } else {
            return buscar_palavra(raiz->direita, palavra);
        }
    }
}

// Função para liberar a memória ocupada pela árvore
void liberar_arvore(struct NoArvore* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    FILE *arquivo;
    char palavra[50];
    struct NoArvore* raiz = NULL;

   
    arquivo = fopen("palavras_chave.txt", "r"); // Abre o arquivo de 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }


    // Ler as palavras do arquivo
    while (fscanf(arquivo, "%s", palavra) != EOF){

        adicionar_palavra(&raiz, palavra); //  adicioná à árvore
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Pedir ao usuário para inserir uma palavra para busca
    printf("Digite uma palavra para buscar no dicionario: ");
    scanf("%s", palavra);

    // Verificar se a palavra está no dicionário
    if (buscar_palavra(raiz, palavra)) {
        printf("A palavra '%s' esta presente no dicionario.\n", palavra);
    } else {
        printf("A palavra '%s' nao foi encontrada no dicionario.\n", palavra);
    }

    // Liberar a memória ocupada pela árvore
    liberar_arvore(raiz);

    return 0;
}
