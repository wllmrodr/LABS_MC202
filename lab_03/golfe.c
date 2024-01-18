#include <stdio.h>
#include <stdlib.h>
#include "circuito.h"
#include "partida.h"

int main(){
    
    int i;
    int num_partidas;
    Partida *partidas;

    scanf("%d", &num_partidas);

    partidas = malloc(num_partidas*sizeof(Partida)); // não esquecer de liberar memória

    for (i=0 ;i<num_partidas ;i++){
        //recebo as infos de cada partida
        recebe_entradas(i, partidas);

    }

    for (i=0 ;i<num_partidas ;i++){
        //recebo as infos de cada partida
        relatorio_final(i, partidas);

    }

    for(i=0 ;i<num_partidas ;i++){
        libera_memoria(i, partidas);

    }

    free(partidas);

    //libero a memória usada
   
    return 0;
}
