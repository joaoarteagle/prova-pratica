#ifndef PRODUTO
#define PRODUTO

#include<stdio.h>
#include<stdlib.h>

#define MAX_NAME_LENGTH 50 // Comprimento máximo do nome do produto

// Estrutura para representar um produto
typedef struct Product {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Product;

// Função para buscar um produto na tabela hash
Product* findProduct(HashTable* hashTable, char* name);

#endif;