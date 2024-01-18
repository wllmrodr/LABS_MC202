#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha * inicializa_pilha(int tam_pilha){
   
    Pilha *pilha = malloc(sizeof(Pilha));
   
    pilha->tamanho_total = tam_pilha;
    pilha->tamanho_atual = 0;

    pilha->topo = NULL;

    return pilha;
    // preciso alocar devolvendo o ponteiro
}

void empilha_pecas(Peca *peca_entrando, Pilha *pilha){

    No *no = malloc(sizeof(No));

    if (no) {

        no->peca = peca_entrando;
        no->proximo = pilha->topo;
        pilha->topo = no;
        pilha->tamanho_atual++;

    }

    
}

Peca *desempilha_pecas(Pilha *pilha){

    No *no = pilha->topo;

    if (no == NULL) // pilha ta vazia
        return NULL;

    pilha->topo = no->proximo;
    no->proximo = NULL;
    Peca *peca_saindo = no->peca;
    free(no);
    pilha->tamanho_atual--;

    return peca_saindo;
}

int verifica_pilha(Pilha *pilha){

    No *no = pilha->topo;

    if (no == NULL) //ta vazia
        return 0;

    else 
        return 1;

}