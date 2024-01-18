#ifndef NO_H
#define NO_H
#define MAX 60
#include <stdio.h>


typedef struct No_lista No;

struct No_lista{
    int isLast;
    char nome_livro[MAX];
    No* prox;
};

void insere(No **V,char nome_livro[MAX]);

void libera_lista(No* head);

No* cria_novo_no(char nome_livro[MAX]);

void push_front(No **V,char nome_livro[MAX]);

void push_back(No **V,char nome_livro[MAX]);

No* remove_livro(char nome_livro[MAX], No* head, int* npos);

void imprime(No* head);


#endif