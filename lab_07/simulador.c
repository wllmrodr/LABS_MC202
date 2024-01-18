#include <stdio.h>
#include <stdlib.h>
#include "peca.h"
#include "trabalhador.h"
#include "fila.h"
#include "pilha.h"


void simulador(Trabalhador *embalador, Trabalhador *classificador, Pilha *pilha, Fila *esteira, int n_pecas){ // simulo segundo por segundo até todas as peças passarem pelo processo e calculo tempo de atraso
    
    int pecas_entregues = 0;
    int pecas_lidas = 0;
    int minuto_atual = 0;
    int atraso = 0; 
    int tipo_peca; 
    char tam_peca[8];
 

    printf("##### Simulação\n");

    while (pecas_entregues < n_pecas) { // qual a ondição do True?

        int entrou_pilha = 0;
        int saiu_pilha = 0;
        int entrou_fila = 0;
        int saiu_fila = 0;


        minuto_atual++;

        // ETAPA DA EMBALAGEM
        
        
        if (embalador->peca_de_trabalho != NULL){
            embalador->peca_de_trabalho->t_embalagem--;
        }


        if (embalador->peca_de_trabalho != NULL && embalador->peca_de_trabalho->t_embalagem <= 0){
            // cuspo (libero)
            free(embalador->peca_de_trabalho);
            embalador->peca_de_trabalho = NULL;
            pecas_entregues++;
            //printf("%d\n", pecas_entregues);
            saiu_pilha = 1;
            
        }


        if (embalador->peca_de_trabalho == NULL){
            //  (desempilho)
            //preciso de uma função pra checar se há coisa na pilha pra desempilhar (criar função)
            
            if (verifica_pilha(pilha) == 1){

                Peca *peca_desempilhada = desempilha_pecas(pilha);
                embalador->peca_de_trabalho = peca_desempilhada;
                
                
            }

        }

        // ETAPA DA CLASSIFICAÇÃO
        // façou outro else if?
        if (classificador->peca_de_trabalho != NULL){
            classificador->peca_de_trabalho->t_classificacao--;
        }

        if (classificador->peca_de_trabalho != NULL && classificador->peca_de_trabalho->t_classificacao <= 0){
            
            // tenho q verificar se posso colocar na pilha (criar função)
            if (pilha->tamanho_atual < pilha->tamanho_total){

                empilha_pecas(classificador->peca_de_trabalho, pilha); 
                classificador->peca_de_trabalho = NULL;
                entrou_pilha = 1;
                saiu_fila = 1;

            }
        }


        if (classificador->peca_de_trabalho == NULL){

            //verifico se tem peça na fila pra pegar (criar função)
            if (verifica_fila(esteira) == 1) {
            //se sim: pego e atualizo tempo
                Peca *peca_desinfileirada = desinfileira_pecas(esteira);
                classificador->peca_de_trabalho = peca_desinfileirada;
                
 
            }

        }
                
            //vejo se ainda tem coisa pra ler;
        if (pecas_lidas < n_pecas){

            //verifico se posso botar na fila (criar função)

            if (esteira->fim < esteira->tamanho) {
            //se sim: leio nova peça e enfileiro
                scanf("%s %d", tam_peca, &tipo_peca);
                Peca *nova_peca = filtro(tam_peca, tipo_peca);
                pecas_lidas++;
                enfileira_pecas(esteira, nova_peca);
                entrou_fila = 1;
            }


                else {
                //se não: atraso
                    atraso++;
                }

        }  // eu só paro quando a última peça passar por todo o processo
            

    printf("Min. %d: Classificação (+%d,-%d) | Embalagem (+%d,-%d).\n", minuto_atual, entrou_fila, saiu_fila, entrou_pilha, saiu_pilha); // preciso criar variáveis pra controlar a saída e entrada da pilha e fila
    // ainda falta colocar os prints do relatório
    



    }

   
    printf("Tempo atraso: %d.\n", atraso);
    
    



} 




int main(){

    int tam_fila, tam_pilha;
    
    Trabalhador *embalador = malloc(sizeof(Trabalhador));
    embalador->peca_de_trabalho = NULL;
    Trabalhador *classificador = malloc(sizeof(Trabalhador));
    classificador->peca_de_trabalho = NULL;
    Pilha *pilha = NULL;
    Fila *esteira = NULL;

    int n_pecas;
    
    // recebe o tamanho e n
    scanf("%d %d",&tam_fila, &tam_pilha);
    scanf("%d",&n_pecas);

    // inicializa os trem
    esteira = inicializa_esteira(tam_fila);
    pilha = inicializa_pilha(tam_pilha);
    
  

    // simulador
    simulador(embalador, classificador, pilha, esteira, n_pecas);

    free(embalador);
    free(classificador);
    free(pilha);
    free(esteira);

    return 0;
}
