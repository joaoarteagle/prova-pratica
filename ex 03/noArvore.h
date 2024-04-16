#ifndef NOARVORE
#define NOARVORE

// Definição da estrutura do nó da árvore
struct NoArvore {
    char palavra[50];
    struct NoArvore *esquerda;
    struct NoArvore *direita;
};

// Função para criar um novo nó da árvore
struct NoArvore* criar_no(char *palavra);
// Função para adicionar uma palavra à árvore
void adicionar_palavra(struct NoArvore** raiz, char *palavra) ;
// Função para buscar uma palavra na árvore
int buscar_palavra(struct NoArvore* raiz, char *palavra);
// Função para liberar a memória ocupada pela árvore
void liberar_arvore(struct NoArvore* raiz);
#endif