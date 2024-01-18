#ifndef __PILHA_H__
#define __PILHA_H__

#include "no.h"
#include "peca.h"

typedef struct{
    
    No *topo;
    int tamanho_total;
    int tamanho_atual;

}Pilha;

Pilha * inicializa_pilha(int tam_pilha);

void empilha_pecas(Peca *peca_entrando, Pilha *pilha);

Peca *desempilha_pecas(Pilha *pilha);

int verifica_pilha(Pilha *pilha);



// pteciso criar função que vê se pode botar na pilha

// e função que vê se tem algo na pilha

#endif // __PILHA_H__