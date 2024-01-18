#include "no.h"
#include <stdlib.h>
#include <string.h>


void libera_lista(No* head){
    
    if(head != NULL){
        libera_lista(head->prox);
        free(head);

    }
}

No* cria_novo_no(char nome_livro[MAX]){
    No* novo_no = (No*)malloc(sizeof(No));
    strcpy(novo_no->nome_livro, nome_livro);
    novo_no->prox = NULL;    
    novo_no->isLast = 1;
    return novo_no;
}

void clearLast(No** V){
    No* aux = *V;

    while(aux!=NULL){
        aux->isLast = 0;
        aux = aux->prox;
    }
}

void push_front(No **V,char nome_livro[MAX]){
    clearLast(V);
    No *novo_no= cria_novo_no(nome_livro);
    novo_no->prox=(*V);
    (*V) = novo_no;
}

void insere(No **V,char nome_livro[MAX]){
    No *novo_no = cria_novo_no(nome_livro), *aux = *V;

    while(aux!=NULL && !aux->isLast) aux = aux->prox;
    clearLast(V);
    
    novo_no->prox=aux->prox;
    aux->prox=novo_no;
}

void push_back(No **V,char nome_livro[MAX]){   
    clearLast(V); 
    No *novo_no= cria_novo_no(nome_livro);
    No *ult=*V;
    novo_no->prox=NULL;
    if(*V==NULL){
        *V=novo_no;
        return;
    }

    while(ult->prox!=NULL)
        ult=ult->prox;
    ult->prox=novo_no;
}

No* remove_livro(char nome_livro[MAX], No* head,int* npos){
    No* aux = NULL;
    No* remover = NULL;
    
    if(head!=NULL){
        if(strcmp(head->nome_livro, nome_livro) == 0){
            remover = head;
            head = remover->prox;
            if(remover->isLast) (*npos) = 1;
        }
        else{
            aux = head;
            while(aux->prox!=NULL && strcmp(aux->prox->nome_livro, nome_livro) != 0) aux = aux->prox;
            if(aux->prox!=NULL){
                remover = aux->prox;
                aux->prox = remover->prox;
                if(remover->isLast) aux->isLast = 1;
            }
        }
    }

    free(remover);

    return head;
}

void imprime(No* head){
    No* atual = head;

    while(atual != NULL){   
        if(atual->prox == NULL){ //VÊ SE É ÚLTIMO DA LISTA, PRA N SAIR COM VÍRGULA
            printf("%s", atual->nome_livro);
        }
        else{
            printf("%s, ", atual->nome_livro);
        }
        atual = atual->prox;
    }
    printf("\n");
}