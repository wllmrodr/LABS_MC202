#include <stdio.h>
#include "fila.h"
#include <stdlib.h>


Fila * inicializa_esteira(int tam_fila){  //   erro ta aqui 
    
    Fila *esteira = malloc(sizeof(Fila));

    esteira->tamanho = tam_fila;

    for(int i=0;i<esteira->tamanho;i++){
        esteira->pecas[i] = NULL;
    }

    esteira->fim = 0;

    return esteira;

    // tenho que alocar a esteira
}

void enfileira_pecas(Fila *esteira, Peca *peca_entrando){ // n = tamanho da fila do scanf

    if (esteira->fim == esteira->tamanho){ 
        return; 

    } else {
        esteira->pecas[esteira->fim] = peca_entrando; // preciso adaptar
        esteira->fim++;

    }
}

Peca * desinfileira_pecas(Fila *esteira){ // ta ineficiente, usar vetor circular ??
    Peca *peca_saindo;
    if (esteira->fim == 0){ // fila ta vazia
        return NULL;

    } else {
        peca_saindo = esteira->pecas[0];

        for(int i=0;i<esteira->fim;i++)
            esteira->pecas[i] = esteira->pecas[i+1]; // preciso adaptar

        esteira->fim--;

        

    }
    return peca_saindo;
}

int verifica_fila(Fila *esteira){

    if (esteira->fim == 0)
        return 0;

    else
        return 1;

    
}
