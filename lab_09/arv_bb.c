#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv_bb.h"
#define MAX 200

No_Arv_BB * cria_novo_no(char linha_lida[], int indice_linha){

    No_Arv_BB * novo_no = malloc(sizeof(No_Arv_BB));

    if (novo_no){
        novo_no->i_linha = indice_linha;
        //novo_no->linha = linha_lida;
        strcpy(novo_no->linha,linha_lida);
        novo_no->dir = NULL;
        novo_no->esq = NULL;

        //separa o tipo e no nome da variável
        sscanf(linha_lida, "%s %s", novo_no->tipo, novo_no->nome);

    }
    return novo_no;
}


No_Arv_BB * insere_novo_no(No_Arv_BB *raiz, No_Arv_BB *novo){ // INSERE NOVO NÓ NA ÁRVORE BINÁRIA

    if (raiz == NULL)
        return novo;
    
    else{

        if(strcmp(novo->nome, raiz->nome) < 0){//LINHA DO NOVO É MENOR QUE A DA RAIZ
        // insere na esquerda
            raiz->esq = insere_novo_no(raiz->esq, novo);
        } 

        else if(strcmp(novo->nome, raiz->nome) > 0) { //LINHA DO NOVO É MAIOR QUE A DA RAIZ
        // insere na direita
            raiz->dir = insere_novo_no(raiz->dir, novo);
        }

        return raiz;
    
    }
}



int procura_declaracoes_arv_bb(No_Arv_BB * raiz_declaracoes, char * token){ // ISSO PARECE OK concordo

    int achou = 0;
    while(raiz_declaracoes != NULL){

        if (strcmp(token, raiz_declaracoes->nome) == 0){
            achou = 1;
            return achou;
        }

        else if(strcmp(token, raiz_declaracoes->nome) < 0){
            raiz_declaracoes = raiz_declaracoes->esq; 
            
            }//LINHA DO NOVO É MENOR QUE A DA RAIZ

       else if(strcmp(token, raiz_declaracoes->nome) > 0) {
            raiz_declaracoes = raiz_declaracoes->dir; 
        }

    }

    return 0;
}


/////////////////////////////////////// VERIFICA SE O TIPO JÁ FOI DECLARADO///////////////////////////

char * verifica_tipo_declaracoes_arv_bb(No_Arv_BB * raiz_declaracoes, char * token){ // PENSAR MAIS SOBRE
    
    while(raiz_declaracoes != NULL){

        if (strcmp(token, raiz_declaracoes->nome) == 0){
            return raiz_declaracoes->tipo;
        }
        else if(strcmp(token, raiz_declaracoes->nome) < 0){
            raiz_declaracoes = raiz_declaracoes->esq;       
        }

        else if(strcmp(token, raiz_declaracoes->nome) > 0) {
            raiz_declaracoes = raiz_declaracoes->dir; 
        }
    }
    return NULL;
}



void libera_arvore(No_Arv_BB * raiz_declaracoes){

    if (raiz_declaracoes == NULL)
        return;

    libera_arvore(raiz_declaracoes->dir);
    libera_arvore(raiz_declaracoes->esq);

    free(raiz_declaracoes);


    // NO MAIN: free(raiz);



}


int verifica_declaracoes(char linha[], No_Arv_BB * raiz_declaracoes, int i_linha){ //OK
    // PERCORRO TODAS AS PALAVRAS DA LINHA DE OPERAÇÃO, TORNANDO CADA UMA A CHAVE PRA PROCURAR NA ÁRVORE
    char linha_aux[MAX];
    strcpy(linha_aux, linha);
    char *token;
    token = strtok(linha_aux, " ");

    while(token){ // 
        
        if (*token != '=' && *token != '+' && *token != '-' && *token != '*' && *token != '/' && *token != '%'){

            if(procura_declaracoes_arv_bb(raiz_declaracoes, token) == 0){
                printf("Linha %d: o símbolo %s não foi definido.\n", i_linha, token); //PARO AQUI
                return 1; //achou erro
            }   
        }

        token = strtok(NULL, " ");

    }

    return 0; //n achou erro

}

int verifica_operandos(char linha[], No_Arv_BB * raiz_declaracoes, int i_linha){
    // VERFICO A PARTIR DA SEGUNDA PALAVRA SE OS TIPOS SÃO IGUAIS 

    char linha_aux[MAX];
    strcpy(linha_aux, linha);
    char *tipo1, *tipo2, *nome1, *nome2;
    char *token;
    token = strtok(linha_aux, " ");
    char *op;

    //a = b + c
    //0 1 2 3 4

    for(int i = 0 ;i<5; i++){ // COM O FOR LIMITADO ATÉ 3 EU CONSIGO FAZER ISSO MEC
      
        if (token == NULL)
            break;
        if (i == 2){
            tipo1 = verifica_tipo_declaracoes_arv_bb(raiz_declaracoes, token); 
            nome1 = token;
        }
        if(i == 3){
            op = token;
        }
        if (i == 4){
            tipo2 = verifica_tipo_declaracoes_arv_bb(raiz_declaracoes, token); 
            nome2 = token;
        }
  
        token = strtok(NULL, " "); // faz continuar de onde parou
    }

    if (strcmp(tipo1,tipo2) != 0){

        printf("Linha %d: tipos incompatíveis: %s (%s) %c %s (%s).\n", i_linha, nome1, tipo1, *op, nome2, tipo2);
        return 1;
    }

    return 0;
}


int verifica_resultado(char linha[], No_Arv_BB * raiz_declaracoes, int i_linha){
    // VERIFICO A PRIMEIRA PALAVRA SE 
    char linha_aux[MAX];
    strcpy(linha_aux, linha);
    char *tipo_resultado, *tipo_operando, *nome_resultado;
    char *token;
    token = strtok(linha_aux, " ");
    
    //a = b + c
    //0 1 2 3 4

    for(int i = 0 ;i<5; i++){ // COM O FOR LIMITADO ATÉ 3 EU CONSIGO FAZER ISSO MEC

        if (token == NULL)
            break;
        if (i == 0){
            nome_resultado = token;
            tipo_resultado = verifica_tipo_declaracoes_arv_bb(raiz_declaracoes, token); 
            
        }
        if (i == 2){
            
            tipo_operando = verifica_tipo_declaracoes_arv_bb(raiz_declaracoes, token); 
            
        }
        token = strtok(NULL, " "); // faz continuar de onde parou
    }

    if (strcmp(tipo_resultado,tipo_operando) != 0){
        printf("Linha %d: tipos incompatíveis: o símbolo %s espera %s, obteve %s.\n", i_linha, nome_resultado, tipo_resultado, tipo_operando);
        return 1;
    }

    return 0;
}


int verifica_operacao(char linha[], No_Arv_BB * raiz_declaracoes, int i_linha){
    int erro = 0;

    if(verifica_declaracoes(linha, raiz_declaracoes, i_linha) == 1){
        erro = 1;
        return erro;
    }
        

    if(verifica_operandos(linha, raiz_declaracoes, i_linha) == 1){
        erro = 1;
        return erro;
    }

        
    if(verifica_resultado(linha, raiz_declaracoes, i_linha) == 1){
        erro = 1;
        return erro;
    }
    return erro;
    

}


// Função para percorrer a árvore da menor para a maior chave
void printa_arvore(No_Arv_BB * raiz_declaracoes){
    if (raiz_declaracoes != NULL) {
        // Primeiro, percorre a subárvore esquerda
        printa_arvore(raiz_declaracoes->esq);

        // Em seguida, imprime a chave do nó atual
        printf("%s %s\n", raiz_declaracoes->nome, raiz_declaracoes->tipo);

        // Por fim, percorre a subárvore direita
        printa_arvore(raiz_declaracoes->dir);
    }
}