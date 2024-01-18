#include <stdio.h>
#include "circuito.h"

int pior_circuito(int n_circuitos, int n_participantes, Circuito *circuitos){ //pego vetor de circuitos e analiso o vetor de jogadas de cada um e vejo qual maior e pego o id
    
    int i,j;
    int maior = 0;
    int pior = 0;

    for (j=0 ;j<n_circuitos ;j++){
        int soma = 0;
        for (i=0 ;i<n_participantes ;i++){
            soma += circuitos[j].jogadas[i+1];
        }
        

        if (soma > maior){
            maior = soma;
            pior = circuitos[j].jogadas[0];
        }
    }

    return pior;


}


void soma_jogadas(int n_circuitos, int n_participantes, Circuito *circuitos, int *vetor_soma ){
    
    int i,j;
    
    for (i=0 ;i<n_participantes ;i++){
        int soma_participante = 0;
        for (j=0 ;j<n_circuitos ;j++){ // sepa q tenho q arrumar

            soma_participante += circuitos[j].jogadas[i+1];

            }

        vetor_soma[i] = soma_participante;



    }



}