#include <stdio.h>
#include "peca.h"
#include <string.h>
#include <stdlib.h>

Peca * filtro(char tamanho[], int tipo){


    Peca *peca = malloc(sizeof(Peca));


    if (strcmp("pequena", tamanho) == 0){
        peca->tamanho = 'P';
        if (tipo == 1){
            peca->t_classificacao = 1;
            peca->t_embalagem = 1;

        }

        else if (tipo == 2) {
            peca->t_classificacao = 1;
            peca->t_embalagem = 2;

        }
    }

    if (strcmp("media", tamanho) == 0){
        peca->tamanho = 'M';
        if (tipo == 1){
            peca->t_classificacao = 2;
            peca->t_embalagem = 2;
        }

        else if (tipo == 2) {
            peca->t_classificacao = 2;
            peca->t_embalagem = 3;
        }
    }

    if (strcmp("grande", tamanho) == 0){
        peca->tamanho = 'G';
        if (tipo == 1){
            peca->t_classificacao = 3;
            peca->t_embalagem = 2;
        }

        else if (tipo == 2) {
            peca->t_classificacao = 3;
            peca->t_embalagem = 3;
        }
    }

    return peca;

}