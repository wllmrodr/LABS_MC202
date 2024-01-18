#include <stdio.h>

typedef struct No_Arvore No_Arv;
// Definição da estrutura do nó da árvore
struct No_Arvore {
    
    char dado;
    No_Arv* dir;
    No_Arv* esq;

};



No_Arv * constroi_arvore(char expressao[]);

No_Arv * cria_novo_no(char dado);

No_Arv * simplifica_arvore(No_Arv * raiz);

No_Arv * clona_arvores(No_Arv * raiz);

void printa_em_ordem(No_Arv * raiz);

void apaga_arvores(No_Arv * raiz);

int verifica_operador_logico(No_Arv * no);

int verifica_operador_relacional(No_Arv * no);

int verifica_operador_comparador(No_Arv * no);