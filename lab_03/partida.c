#include <stdio.h>
#include <stdlib.h>
#include "circuito.h"
#include "partida.h"

void recebe_entradas(int indice, Partida *partidas){
    
    int j;

    partidas[indice].n_identificacao_p = indice+1;

    scanf("%d %d %d ", &partidas[indice].n_participantes, &partidas[indice].n_circuitos, &partidas[indice].n_equipamentos);
    
    partidas[indice].soma_participantes = malloc(partidas[indice].n_participantes*sizeof(int));

    partidas[indice].valor_aluguel = (10.0*partidas[indice].n_circuitos) + (17.5*partidas[indice].n_equipamentos); 

    partidas[indice].circuitos = malloc(partidas[indice].n_circuitos*sizeof(Circuito)); // aloco memória pro vetor de circuitos

    for (j=0 ;j<partidas[indice].n_circuitos ;j++){ // aloco memória pro vetor de jogadas de cada circuito

        int i;

        partidas[indice].circuitos[j].jogadas = malloc((partidas[indice].n_participantes + 1)*sizeof(int));// dentro do for já aproveito e preencho as infos de cada circuito

        partidas[indice].circuitos[j].n_participantes = partidas[indice].n_participantes;

        for (i=0 ;i< partidas[indice].circuitos[j].n_participantes + 1;i++){

            scanf("%d ", &partidas[indice].circuitos[j].jogadas[i]);

        }

        partidas[indice].circuitos[j].n_identificacao_c = partidas[indice].circuitos[j].jogadas[0];


        } // na teoria eu já preenchi tudo aqui

    


    // falta reajustar essas funções: pior e soma

    partidas[indice].pior_circuito = pior_circuito(partidas[indice].n_circuitos, partidas[indice].n_participantes, partidas[indice].circuitos);

    soma_jogadas(partidas[indice].n_circuitos, partidas[indice].n_participantes, partidas[indice].circuitos, partidas[indice].soma_participantes);
    
    // ainda falta somar as jogadas de cada jogador

    // função que soma tudo e bota num vetor


    }



void relatorio_final(int indice, Partida *partidas){
    int i;
    
    printf("Partida %d\n", partidas[indice].n_identificacao_p);
    printf("Num. de Jogadores: %d - Num. de Circuitos: %d - Num. de Equipamentos: %d\n", partidas[indice].n_participantes, partidas[indice].n_circuitos, partidas[indice].n_equipamentos);
    printf("Valor do Aluguel: R$ %.2f\n", partidas[indice].valor_aluguel);
    for (i=0; i<partidas[indice].n_participantes; i++)
        printf("Jogador %d: %d\n", i+1, partidas[indice].soma_participantes[i]);   /////////////// acho que aqui ainda tem que ajustar 

    printf("Circuito mais dificil: %d\n", partidas[indice].pior_circuito);
    printf("##########\n");

    }


void libera_memoria(int indice, Partida *partidas){ // ainda falta arrumar esse trem
// tem q liberar memória da:
// circuitos
// jogadas
// soma de jogadas
    int i;

    free(partidas[indice].soma_participantes);

    for (i=0; i<partidas[indice].n_circuitos; i++){
            free(partidas[indice].circuitos[i].jogadas);

    }

    free(partidas[indice].circuitos);



    }