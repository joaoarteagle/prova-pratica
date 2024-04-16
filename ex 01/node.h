#ifndef NO
#define NO

#include<produto.h>

// Estrutura para representar um nó na lista encadeada
typedef struct Node {
    Product product;
    struct Node* next;
} Node;


#endif;