#include <stdio.h>

typedef struct{

    int *vetor_valores; // vetor de memoria
    int *vetor_auxiliar; // vetor auxiliar, 1 se a posição tem algum valor e 0 se a posição tem lixo
    int cardinalidade; // tamanho do vetor

}Memoria;

int verifica_vetor(Memoria *bat_memoria);

int procura_espaco(int n_inteiros, Memoria *bat_memoria);

int procura_posicao(int n_inteiros, Memoria *bat_memoria);

void copia_vetores1(Memoria *bat_memoria);

void copia_vetores2(int endereco, Memoria *bat_memoria);

void copia_vetores3(Memoria *bat_memoria);

void bat_alloc(Memoria *bat_memoria);

void bat_free(Memoria *bat_memoria);

void bat_print(Memoria *bat_memoria);

void bat_uso(Memoria *bat_memoria);