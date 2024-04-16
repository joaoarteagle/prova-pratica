#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <produto.h>
#include <node.h>
#include <hashTable.h>
#include <stack.h>





//=================================================================
unsigned int hash(char* name) {
    unsigned int hash_value = 0;
    unsigned int a = 37; // Fator de multiplicação

    for (int i = 0; name[i] != '\0'; i++) {
        hash_value = (hash_value * a + name[i]) % HASH_SIZE;
    }

    return hash_value;
}
//=================================================================


//=================================================================
void initHashTable(HashTable* hashTable) {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable->array[i] = NULL;
    }
}
//=================================================================


void insertProduct(HashTable* hashTable, Product product) {
    unsigned int index = hash(product.name);

    // Criar um novo nó para o produto
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->product = product;
    newNode->next = NULL;

    // Se não houver colisão, apenas insira na posição index
    if (hashTable->array[index] == NULL) {
        hashTable->array[index] = newNode;
    } else {
        // Se houver colisão, insira no início da lista encadeada
        newNode->next = hashTable->array[index];
        hashTable->array[index] = newNode;
    }
}


//=================================================================
Product* findProduct(HashTable* hashTable, char* name) {
    unsigned int index = hash(name);
    Node* currentNode = hashTable->array[index];

    // Percorre a lista encadeada para encontrar o produto
    while (currentNode != NULL) {
        if (strcmp(currentNode->product.name, name) == 0) {
            return &(currentNode->product);
        }
        currentNode = currentNode->next;
    }

    return NULL; // Produto não encontrado
}

//=================================================================
void initStack(Stack* stack) {
    stack->top = -1;
}
//=================================================================
int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}
//=================================================================

int isStackFull(Stack* stack) {
    return stack->top == STACK_SIZE - 1;
}
//=================================================================

void push(Stack* stack, Product product) {
    if (!isStackFull(stack)) {
        stack->items[++stack->top] = product;
    } else {
        printf("Erro: Pilha cheia!\n");
    }
}
//=================================================================
Product pop(Stack* stack) {
    if (!isStackEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Erro: Pilha vazia!\n");
        Product emptyProduct = {"", 0.0, 0};
        return emptyProduct;
    }
}
//=================================================================


int main() {
    HashTable hashTable;
    Stack recentChanges;
    initHashTable(&hashTable);
    initStack(&recentChanges);

    // Exemplo de adição de produtos
    Product product1 = {"Biscoito", 1.5, 50};
    Product product2 = {"Refrigerante", 3.0, 100};
    Product product3 = {"Chocolate", 2.0, 30};

    insertProduct(&hashTable, product1);
    insertProduct(&hashTable, product2);
    insertProduct(&hashTable, product3);

    // Adicionando alterações recentes à pilha
    push(&recentChanges, product1);
    push(&recentChanges, product2);
    push(&recentChanges, product3);

    // Exemplo de busca de produto
    char searchName[MAX_NAME_LENGTH] = "Refrigerante";
    Product* foundProduct = findProduct(&hashTable, searchName);
    if (foundProduct != NULL) {
        printf("Produto encontrado: %s, Preço: %.2f, Quantidade em estoque: %d\n",
               foundProduct->name, foundProduct->price, foundProduct->quantity);
    } else {
        printf("Produto não encontrado.\n");
    }

    // Removendo um produto da pilha (simulando uma remoção)
    Product removedProduct = pop(&recentChanges);
    printf("Último produto removido da pilha: %s\n", removedProduct.name);

    return 0;
}
