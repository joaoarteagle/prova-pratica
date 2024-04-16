#ifndef HASH
#define HASH
#define HASH_SIZE 100 // Tamanho da tabela hash

#include<node.h>

// Estrutura para representar a tabela hash
typedef struct {
    Node* array[HASH_SIZE]; // Vetor de ponteiros para nós
} HashTable;


// Função de hash utilizando o método de multiplicação
unsigned int hash(char* name);

// Função para inicializar a tabela hash
void initHashTable(HashTable* hashTable);

// Função para inserir um produto na tabela hash
void insertProduct(HashTable* hashTable, Product product);

#endif