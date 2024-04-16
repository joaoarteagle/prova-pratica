#ifndef STACK
#define STACK
#define STACK_SIZE 100 // Tamanho da pilha
#include<produto.h>


// Estrutura para representar uma pilha
typedef struct Stack{
    Product items[STACK_SIZE];
    int top;
} Stack;


// Função para inicializar a pilha
void initStack(Stack* stack);

// Função para verificar se a pilha está vazia
int isStackEmpty(Stack* stack);

// Função para verificar se a pilha está cheia
int isStackFull(Stack* stack);

// Função para empilhar um produto na pilha
void push(Stack* stack, Product product);

// Função para desempilhar um produto da pilha
Product pop(Stack* stack);

#endif