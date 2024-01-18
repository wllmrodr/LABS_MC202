#ifndef ARV_BB_H
#define ARV_BB_H
#define MAX 200

typedef struct No_Arvore No_Arv_BB;

struct No_Arvore{

    char linha[MAX];
    char tipo[7];
    char nome[20];
    int i_linha;
    No_Arv_BB *dir;
    No_Arv_BB *esq;

};


No_Arv_BB * cria_novo_no(char linha_lida[], int indice_Linha);

No_Arv_BB * insere_novo_no(No_Arv_BB *raiz, No_Arv_BB *novo);

int procura_declaracoes_arv_bb(No_Arv_BB * raiz_declaracoes, char * token);

char * verifica_tipo_declaracoes_arv_bb(No_Arv_BB * raiz_declaracoes, char * token);

void libera_arvore(No_Arv_BB * raiz_declaracoes);

int verifica_declaracoes(char linha[], No_Arv_BB * raiz_declaracoes, int i_linha);

int verifica_operandos(char linha[], No_Arv_BB * raiz_declaracoes, int i_linha);

int verifica_resultado(char linha[], No_Arv_BB * raiz_declaracoes, int i_linha);

int verifica_operacao(char linha[], No_Arv_BB * raiz_declaracoes, int i_linha);

void printa_arvore(No_Arv_BB * raiz_declaracoes);

#endif
