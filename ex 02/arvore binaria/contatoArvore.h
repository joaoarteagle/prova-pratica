#ifndef CONTATO
#define CONTATO

struct Contato {
    char nome[50];
    char telefone[20];
    struct Contato *esquerda;
    struct Contato *direita;
};

#endif