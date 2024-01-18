#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

int procura_espaco(int n_inteiros, Memoria *bat_memoria){
    int achou = -1;
    int i;

    for (i=0; i<bat_memoria->cardinalidade; i++){ // verifico se tem espaço pelo vetor auxiliar

        if (bat_memoria->vetor_auxiliar[i] == 0){

            int contador = 0; // eu tenho q voltar o valor dele pra um em algum momento?

            for (int j=i; j<n_inteiros+i+1 && j<bat_memoria->cardinalidade; j++){
              
        
                if (bat_memoria->vetor_auxiliar[j] != 0) /////////
                    break;

                contador++;

            }

            if (contador == n_inteiros+1){
                achou = i;
                break;
            }

            contador = 0; // volto o valor do contador pra 1
        }
        
        else{
            i += bat_memoria->vetor_valores[i];


        }
    }


    return achou;


}



int verifica_vetor(Memoria *bat_memoria){
    int vetor_vago = 1;
    int quarto = bat_memoria->cardinalidade/4;

    for(int i=quarto;i<bat_memoria->cardinalidade;i++){ // iteração pra verificar se 3 quartos do vetor estao vagos depois de liberar espaço, caso ache uma ocorrencia, o vetor não esta vago
        if (bat_memoria->vetor_auxiliar[i] == 1){
            vetor_vago = 0;
            break;
        }
            
    }

    return vetor_vago;
    
}


void copia_vetores1(Memoria *bat_memoria){

    int nova_cardinalidade = 2*bat_memoria->cardinalidade; 

    int *novo_vetor_valores = malloc(nova_cardinalidade*sizeof(int));
    int *novo_vetor_auxiliar = calloc(nova_cardinalidade,sizeof(int)); 

    for(int i=0;i<bat_memoria->cardinalidade;i++){ // copio os elementos de um vetor pro outro
        novo_vetor_valores[i] = bat_memoria->vetor_valores[i];
        novo_vetor_auxiliar[i] = bat_memoria->vetor_auxiliar[i];    // ser a que ao inveś da nova_cardinalidade eu tenho q colocar a antiga?

        }

    free(bat_memoria->vetor_valores); // libero os vetores antigos
    free(bat_memoria->vetor_auxiliar); 

    bat_memoria->vetor_valores = novo_vetor_valores; // atualizo os novos vetores
    bat_memoria->vetor_auxiliar = novo_vetor_auxiliar;
    bat_memoria->cardinalidade = nova_cardinalidade;




}


void copia_vetores3(Memoria *bat_memoria){

    int nova_cardinalidade = (bat_memoria->cardinalidade)/2;

    int *novo_vetor_valores = malloc(nova_cardinalidade*sizeof(int));
    int *novo_vetor_auxiliar = calloc(nova_cardinalidade,sizeof(int));

    for(int i=0;i<nova_cardinalidade;i++){ // copio os elementos de um vetor pro outro
        novo_vetor_valores[i] = bat_memoria->vetor_valores[i];
        novo_vetor_auxiliar[i] = bat_memoria->vetor_auxiliar[i];    

        }

        free(bat_memoria->vetor_valores); // libero os vetores antigos
        free(bat_memoria->vetor_auxiliar);

        bat_memoria->vetor_valores = novo_vetor_valores; // atualizo os novos vetores
        bat_memoria->vetor_auxiliar = novo_vetor_auxiliar;
        bat_memoria->cardinalidade = nova_cardinalidade;

}



void bat_alloc(Memoria *bat_memoria){
    // guarda uma lista de N inteiros na primeira posição disponível e printa o endereço da primeira posição alocada
    // bat-alloc N LISTA 
    int n_inteiros, i;
    int pos_interesse;
    

    scanf("%d ", &n_inteiros);

    // PARTE QUE PROCURA O ESPAÇO PRA ALOCAR
    // com o n eu aloco um vetor e coloco ele dentro do meu vetor de interesse

    pos_interesse = procura_espaco(n_inteiros, bat_memoria);

    if (pos_interesse != -1){ // percorreu a lista e achou espaço pra alocar e aloco na posição de interesse
        
        bat_memoria->vetor_valores[pos_interesse] = n_inteiros;
        bat_memoria->vetor_auxiliar[pos_interesse] = 1;


        for(i=pos_interesse+1;i<pos_interesse+n_inteiros+1;i++){   
            if (i >= bat_memoria->cardinalidade){
                break;
            }
            scanf("%d ", &bat_memoria->vetor_valores[i]); //ta certo com o espaço?
            bat_memoria->vetor_auxiliar[i] = 1;  // preenche o vetor auxiliar com 1 onde foi adicionado os n inteiros


        }

        printf("%d\n", pos_interesse);
    }

    // PARTE QUE DOBRA O VETOR

    else { //percorreu a lista inteira e não achou espaço, logo devo dobrar o tamanho e alocar no começo da segunda metade do vetor
       
        copia_vetores1(bat_memoria);
        
        pos_interesse = procura_espaco(n_inteiros, bat_memoria);
       
        bat_memoria->vetor_valores[pos_interesse] = n_inteiros;
        bat_memoria->vetor_auxiliar[pos_interesse] = 1;

        for(i=pos_interesse+1;i<pos_interesse+n_inteiros+1;i++){  
            if(i >= bat_memoria->cardinalidade){
                break;
            }
            scanf("%d ", &bat_memoria->vetor_valores[i]);
            bat_memoria->vetor_auxiliar[i] = 1;

        }

        printf("%d\n", pos_interesse);

    }

    
}



void bat_free(Memoria *bat_memoria){
    // libera espaço na memória com o endereço dado
    // bat-free ENDEREÇO
    int endereco;
    int vetor_vago;


    scanf("%d", &endereco);

    // PARTE QUE LIBERA ESPAÇO DA MEMÓRIA
    // libero o espaço do endereço e as proximas 4 posições

    for(int i = endereco;i<(bat_memoria->vetor_valores[endereco]+endereco+1);i++){

        bat_memoria->vetor_auxiliar[i] = 0;

    }

    // PARTE QUE VERIFICA SE O SÓ PRIMEIRO QUARTO DO VETOR ESTÁ OCUPADA

    vetor_vago = verifica_vetor(bat_memoria);

    // PARTE QUE CORTA O VETOR PELA METADE
    
    if(vetor_vago == 1){ // vetor vago, logo tenho que diminuir pela metade e copiar os valores 
        

        if (bat_memoria->cardinalidade > 8){ // assegura que não diminui um vetor de 8 posiões 
            copia_vetores3(bat_memoria);
        }
    }


}


void bat_print(Memoria *bat_memoria){
    // printa os inteiros desde o endereço inicial até o final 
    // bat-print ENDEREÇO
    int endereco_inicial;
    scanf("%d", &endereco_inicial);

    for(int i = endereco_inicial+1; i<endereco_inicial + bat_memoria->vetor_valores[endereco_inicial] + 1; i++){
        if (bat_memoria->vetor_auxiliar[i] == 1){
            printf("%d ", bat_memoria->vetor_valores[i]); // se tiver espaço vazio no meio, qq eu faço?
        }                                                 // posso utilizar o vetor auxiliar, se for 0, eu n printo
    }
    printf("\n");

}


void bat_uso(Memoria *bat_memoria){
    // printa o número de espaços alocados e quantos estão sendo utilizados
    // bat-uso
    int cardinalidade_util = 0;

    // iteração que conta tamanho do vetor utilizado

    for(int i=0;i<bat_memoria->cardinalidade;i++){
        if (bat_memoria->vetor_auxiliar[i] == 1){
            cardinalidade_util++;
        }
    }
    
    printf("%d de %d\n", cardinalidade_util, bat_memoria->cardinalidade);

}
