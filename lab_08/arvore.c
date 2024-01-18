#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#define MAX 120

int verifica_operador_logico(No_Arv * no){ // posso colocar hierarquia aqui
   
    if(no->dado == '&' || no->dado == '|')
        return 1;

    else
        return 0;
}

int verifica_operador_relacional(No_Arv * no){ // posso colocar hierarquia aqui

    if(no->dado == '>' || no->dado == '<' || no->dado == '}' || no->dado == '{')
        return 1;

    else
        return 0;
}

int verifica_operador_comparador(No_Arv * no){ // posso colocar hierarquia aqui
   
    if(no->dado == '=' || no->dado == '!')
        return 1;

    else
        return 0;
}



int eh_operador(char digito){

    if(digito == '>' || digito == '<' || digito == '}' || digito == '{' || digito == '=' || digito == '!' || digito== '&' || digito == '|')
        return 1;

    else
        return 0;

}

int eh_operando(char digito){

    if(digito == '>' || digito == '<' || digito == '}' || digito == '{' || digito == '=' || digito == '!' || digito== '&' || digito == '|')
        return 0;

    else
        return 1;

}



int casting(char numero_char){

    int numero_int = numero_char - '0';

    return numero_int;


}




void libera_simplificacao(No_Arv * raiz) {
    apaga_arvores(raiz->dir);
    apaga_arvores(raiz->esq);
    raiz->dir = raiz->esq = NULL;
}


void regras_simplificacao(No_Arv * raiz){

//--------------------------------------------------------------------------------------------------------//
// REGRAS LÓGICAS

    if (verifica_operador_logico(raiz) == 1){
        //● T | (qualquer expressão) deve resultar em T
        if (raiz->dado == '|')
            if (raiz->dir->dado == 'T' || raiz->esq->dado == 'T' ){
                raiz->dado = 'T';
                libera_simplificacao(raiz);
            }
                

        //● F & (qualquer expressão) deve resultar em F
        if (raiz->dado == '&')
            if (raiz->dir->dado == 'F' || raiz->esq->dado == 'F' ){
                raiz->dado = 'F';
                libera_simplificacao(raiz);
            }
                
    }
    //--------------------------------------------------------------------------------------------------------//

    // REGRAS DE COMPARAÇÃO

    if (verifica_operador_comparador(raiz) == 1){
        //● Se x é uma variável ou uma constante (lógica ou inteira), x = x deve resultar em T
        if (raiz->dado == '='){

            if (eh_operando(raiz->dir->dado) == 1 && eh_operando(raiz->esq->dado) == 1){
                if(raiz->dir->dado == raiz->esq->dado){
                    raiz->dado = 'T';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;
                }
            }     
        }
        //● Se x é uma variável ou uma constante (lógica ou inteira), x ! x deve resultar em F
        if (raiz->dado == '!'){

            if (eh_operando(raiz->dir->dado) == 1 && eh_operando(raiz->esq->dado) == 1){
                if(raiz->dir->dado == raiz->esq->dado){
                    raiz->dado = 'F';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;
                }
                
            }
        
        }
    }
    //--------------------------------------------------------------------------------------------------------//


    // REGRAS RELACIONAIS (OLHAR MAIS CASOS)

    if (verifica_operador_relacional(raiz) == 1){
        
        if(raiz->dado == '{'){

            if (eh_operando(raiz->dir->dado) == 1 && eh_operando(raiz->esq->dado) == 1){
                //● (qualquer variável) { 9 deve resultar em T
                if(raiz->dir->dado == '9'){
                    raiz->dado = 'T';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;
                 }

                //● Se x é uma variável ou uma constante inteira x { x deve resultar em T
                else if (casting(raiz->dir->dado) >= casting(raiz->esq->dado)){
                    raiz->dado = 'T';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;

                }

                else{
                    raiz->dado = 'F';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;
                }

            }
        }
           
                

        
        if(raiz->dado == '}'){
            if (eh_operando(raiz->dir->dado) == 1 && eh_operando(raiz->esq->dado) == 1){
                //● (qualquer variável) } 0 deve resultar em T
                if(raiz->dir->dado == '0'){
                    raiz->dado = 'T';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;
                }

                //● Se x é uma variável ou uma constante inteira x } x deve resultar em T
                else if (casting(raiz->esq->dado) >= casting(raiz->dir->dado)){
                    raiz->dado = 'T';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;

                }

                else{
                    raiz->dado = 'F';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;
                }

            }

        }

                

        
        if(raiz->dado == '>'){
            if (eh_operando(raiz->dir->dado) == 1 && eh_operando(raiz->esq->dado) == 1){
                //● (qualquer variável) > 9 deve resultar em F
                if(raiz->dir->dado == '9'){
                    raiz->dado = 'F';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;
                }

                else if (casting(raiz->esq->dado) > casting(raiz->dir->dado)){
                    raiz->dado = 'T';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;

                }

                //● Se x é uma variável ou uma constante inteira x > x deve resultar em F
                else if (raiz->dir->dado == raiz->esq->dado){
                    raiz->dado = 'F';
                    free(raiz->dir); 
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;
                }

                else{
                    raiz->dado = 'F';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;
                }

            }



        }
   

        
        if(raiz->dado == '<'){

            if (eh_operando(raiz->dir->dado) == 1 && eh_operando(raiz->esq->dado) == 1){
                //● (qualquer variável) < 0 deve resultar em F
                if(raiz->dir->dado == '0'){
                    raiz->dado = 'F';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;
                 }

                else if (casting(raiz->dir->dado) > casting(raiz->esq->dado)){
                    raiz->dado = 'T';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;

                }
                //● Se x é uma variável ou uma constante inteira x < x deve resultar em F
                else if (raiz->dir->dado == raiz->esq->dado){
                    raiz->dado = 'F';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;

                }

                else{
                    raiz->dado = 'F';
                    free(raiz->dir);
                    free(raiz->esq);
                    raiz->dir = raiz->esq = NULL;
                }

            }

        }
    //--------------------------------------------------------------------------------------------------------
    }

}


//constroi árvore
No_Arv * constroi_arvore(char expressao[]){
    
    int tam = strlen(expressao);
    No_Arv * pilha[MAX];
    int topo = -1;

    for (int i = 0; i < tam; i++) {
        No_Arv * no_atual = cria_novo_no(expressao[i]);

        if (eh_operando(expressao[i]) == 1) {
            // Se o caractere for um dígito, é um operando, e o nó é empilhado
            pilha[++topo] = no_atual;
        } else if (eh_operador(expressao[i]) == 1) {
            // Se o caractere for um operador, cria-se um nó operador e conecta os operandos da pilha
            no_atual->dir = pilha[topo--];
            no_atual->esq = pilha[topo--];
            pilha[++topo] = no_atual;
        } else {
            // Se o caractere não for dígito nem operador, trata-se de espaço em branco ou outro caractere
            // Pode ser tratado de acordo com a lógica da sua aplicação
            free(no_atual); // Libera a memória alocada para o nó
        }
    }

    // O nó no topo da pilha será a raiz da árvore
    return pilha[topo];

}

No_Arv * cria_novo_no(char dado) {
    No_Arv * novo_no = malloc(sizeof(No_Arv));
    if (novo_no) {
    
        novo_no->dado = dado;
        novo_no->dir = NULL;
        novo_no->esq = NULL;
        

    }
    return novo_no;
}



//simplifica árvore
No_Arv * simplifica_arvore(No_Arv * raiz){ //SIMPLIFICO ESQUERDA, SIMPLIFCO DIREITA, DEPOIS VEJ SE POSSO SIMPLIFICAR O NÓ EM QUESTÃO

    if (raiz != NULL){

    raiz->esq = simplifica_arvore(raiz->esq);
    raiz->dir = simplifica_arvore(raiz->dir);
    regras_simplificacao(raiz);

    // preciso de uma funçaõ que apaga os nós filhos quando é possivel simplificar

    }


    return raiz;


}




// Função para clonar uma árvore binária
No_Arv * clona_arvores(No_Arv * raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    // Cria um novo nó com os mesmos dados do nó atual
    No_Arv * novo_no = cria_novo_no(raiz->dado);

    // Clona recursivamente os subárvores esquerdo e direito
    novo_no->esq = clona_arvores(raiz->esq);
    novo_no->dir = clona_arvores(raiz->dir);

    return novo_no;

    // NA MAIN

    // Clonar a árvore
    //struct TreeNode* clonedTree = cloneTree(originalTree);

    // Imprimir a árvore clonada em ordem
    // printf("Árvore clonada em ordem: ");
    //inorderTraversal(clonedTree);


}



// Função para imprimir a árvore em ordem
void printa_em_ordem(No_Arv * raiz) { // ainda preciso muda pra colocar os parêntesee afins
    if (raiz != NULL) { // PRA PRINTAR EXPRESSÕES NÃO SIMPLIFICADAS COMPLETAMENTE

        if (eh_operador(raiz->dado) == 1)
            printf("(");

        printa_em_ordem(raiz->esq);
        printf("%c ", raiz->dado);
        printa_em_ordem(raiz->dir);

        if (eh_operador(raiz->dado) == 1)
            printf(")");

        if (raiz->dir == NULL && raiz->esq == NULL) // PRA PRINTAR EXPRESSÕES SIMPLIFICADAS COMPLETAMENTE
            printf("%d ", raiz->dado);
    }


}

// Função para apagar uma árvore binária
void apaga_arvores(No_Arv * raiz) {
    if (raiz == NULL) {
        return;
    }
    // Apaga recursivamente os subárvores esquerdo e direito
    apaga_arvores(raiz->esq);
    apaga_arvores(raiz->dir);

    // Libera a memória alocada para o nó atual
    free(raiz);
}
