#include <stdio.h>
#include "arv_bb.h"
#include <ctype.h>
#include <string.h>
#define MAX 200


int eh_operacao(char linha[MAX]){

    return (strchr(linha, '=') || strchr(linha, '+') || strchr(linha, '/') || strchr(linha, '*') || strchr(linha, '%'));

}

int verifica_linha(char linha[MAX]){

    // SE TIVER PARENTESES, DESCARTA
    if (strchr(linha, '(') != NULL)
        return 0;

    //SE O PRIMEIRO CARACTERE NÃO FOR UMA LETRA, DESCARTA
    char fst[200];
    int n_itens = sscanf(linha, "%s", fst);
    if (n_itens > 0 && !isalpha(fst[0])) // tem uma maneira mais prática? ARRUMAR ISSO DAQUI
        return 0;

    return 1;
}





int main(){

    
    int i_linhas = 1;
    int contador_erro = 0;
    char linha[MAX];

    No_Arv_BB *raiz_declaracoes = NULL;

    
    while(fgets(linha, sizeof(linha), stdin) != NULL){


       if (verifica_linha(linha) == 1) { //verifica se eu devo colocar na árvore ou na lista;
           //tiro o ";" do final
            char *semicomma = strchr(linha, ';');
            if (semicomma)
                *semicomma = '\0';

            if (eh_operacao(linha) == 1){ // SE FOR OPERAÇÃO, EU FAÇO TODAS A VERIFICAÇÕES
                if(verifica_operacao(linha, raiz_declaracoes, i_linhas) == 1){
                    contador_erro++;
                }
            }

            else{ // SE FOR DECLARAÇÃO EU COLOCO NA ÁRVORE DE BUSCA
                char fst[200];
                int n_itens = sscanf(linha, "%s", fst);
                if (n_itens > 0 && (strcmp(fst,"char") == 0 || strcmp(fst,"int") == 0 || strcmp(fst,"double") == 0)){
                    No_Arv_BB *novo_no = cria_novo_no(linha, i_linhas);
                    raiz_declaracoes = insere_novo_no(raiz_declaracoes, novo_no);

                }
                
            }
            
    
        }

        i_linhas++;
    }

    if (contador_erro == 0){
        printf("Não há erros de tipo.\n");
    }

    //percorro árvore de declaracoes pra printar
    printa_arvore(raiz_declaracoes);
    libera_arvore(raiz_declaracoes);

    return 0;
}