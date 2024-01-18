#include <stdio.h>
#include "arvore.h"
#define MAX 120

void processa_expressoes(char expressao [MAX]){

    
    // recebo a função pós-ordem

    // transformo em árvore
    No_Arv * raiz_arv = constroi_arvore(expressao);
    
    // clono árvore
    No_Arv * raiz_arv_clonada = clona_arvores(raiz_arv);

    // simplifico árvore clonada até o limite (com função simplifica_filhos)
    simplifica_arvore(raiz_arv_clonada);

    //printo as duas árvorem em ordem
    printa_em_ordem(raiz_arv);
    printa_em_ordem(raiz_arv_clonada);

    //apago as duas árvores
    apaga_arvores(raiz_arv);
    apaga_arvores(raiz_arv_clonada);

    // recebo nova árvore


}




int main(){


    int n;
    char expressao_posordem[MAX];

    scanf("%d",&n);

    for(int i=0;i<n;i++){

        scanf("%s",expressao_posordem);

        processa_expressoes(expressao_posordem);

    }


    return 0;
}