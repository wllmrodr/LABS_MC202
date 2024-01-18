#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"
#define TAMANHO 10

int main(){

    int n_comandos, i;
    char comando[TAMANHO];
    Memoria *bat_memoria;

    bat_memoria = malloc(sizeof(Memoria));

    // inicilialização dos vetores
    bat_memoria->vetor_valores = malloc(8*sizeof(int));
    bat_memoria->vetor_auxiliar = calloc(8,sizeof(int));

    bat_memoria->cardinalidade = 8;

    scanf("%d", &n_comandos);

    // recebe os comandos e executa a função desejada

    for(i=0;i<n_comandos;i++){
        scanf("%s", comando);

        if (strcmp(comando, "bat-alloc") == 0) {
            bat_alloc(bat_memoria);


        }

        else if (strcmp(comando, "bat-print") == 0) {
            bat_print(bat_memoria);
            

        }

        else if (strcmp(comando, "bat-free") == 0) {
            bat_free(bat_memoria);
            

        }

        else if (strcmp(comando, "bat-uso") == 0) { // bat-uso
            bat_uso(bat_memoria);
            

        }

    }

    // depois do for eu preciso liberar a memória antes de acabar o programa

    free(bat_memoria->vetor_valores);
    free(bat_memoria->vetor_auxiliar);
    free(bat_memoria);


    return 0;
}