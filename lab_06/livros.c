#include <stdio.h>
#include "no.h"
#include <string.h>

int main(){

    char comando[MAX];
    char nome_livro[MAX];
    int pos = 1;
    No* lista_livros = NULL;
    int tam;

    while(scanf("%s", comando) != EOF){
        if (strcmp(comando, "adicionar") == 0){
            //ADICIONA O LIVRO
            fgets(nome_livro, MAX, stdin);

            //retiro o \n do final e coloco um 0 pra indicar o final
            tam = strlen(nome_livro);
            if (nome_livro[tam-1] == '\n')
                nome_livro[--tam] = 0;
            
            if(!pos) push_back(&lista_livros,nome_livro);
            else if(pos>0) push_front(&lista_livros,nome_livro);
            else insere(&lista_livros,nome_livro);
            pos = -1;
        }

        if (strcmp(comando, "remover") == 0){
            //REMOVE O LIVRO PROCURADO
            fgets(nome_livro, MAX, stdin);

            //retiro o \n do final e coloco um 0 pra indicar o final
            tam = strlen(nome_livro);
            if (nome_livro[tam-1] == '\n')
                nome_livro[--tam] = 0;
            
            lista_livros = remove_livro(nome_livro, lista_livros,&pos);
        }

        if (strcmp(comando, "inicio") == 0){
            //APONTA PRO INÍCIO DA LISTA
            pos = 1;
        }

        if (strcmp(comando, "final") == 0){
            //APONTA PRO FINAL DA LISTA
            pos = 0;
        }

        if (strcmp(comando, "imprimir") == 0){
            //IMPRIME LISTA
            imprime(lista_livros);
        }    
    }

    libera_lista(lista_livros);
    return 0;
}