#ifndef __FILA_H__
#define __FILA_H__
#include "peca.h"
#define MAX 10000

typedef struct{ // preciso arrumar isso
    
    Peca *pecas[MAX]; 
    int fim;
    int tamanho;


    // colocar n aqui

}Fila;

Fila * inicializa_esteira(int tam_fila);

void enfileira_pecas(Fila *esteira, Peca *peca_entrando);

Peca * desinfileira_pecas(Fila *esteira);

int verifica_fila(Fila *esteira);

#endif // __FILA_H__
