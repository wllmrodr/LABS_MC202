#ifndef __PECA_H__
#define __PECA_H__

typedef struct{

    int tipo;
    char tamanho;
    int t_embalagem;
    int t_classificacao;

}Peca;

Peca * filtro(char tamanho[], int tipo);

#endif // __PECA_H__