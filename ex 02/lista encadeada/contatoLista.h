#ifndef CONTATO
#define CONTATO


struct Contato {
    char nome[50];
    char telefone[20];
    struct Contato *prox;
};
#endif