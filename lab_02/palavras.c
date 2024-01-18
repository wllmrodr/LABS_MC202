#include <stdio.h>
#include <string.h>
#define MAX 300

void preenche_matriz_char(char matriz[][MAX], int linha, int coluna){ 
    
    int i,j;

    for (i=0; i<linha; i++)
        for (j=0; j<coluna; j++)
            scanf("%c ", &matriz[i][j]);

}

// falta criar função pra preencher a matriz de palavras
void preenche_matriz_palavras(char matriz[][21], int num_palavras){
    
    int i;

    for (i=0; i<num_palavras; i++)
            scanf("%s", matriz[i]);




}
//falta cria função que enche vetor de ocorrência de zeros
void preenche_vetor_ocorrencia(int num_palavras, int ocorrencia_palavras[MAX]){
    
    int i;
    // preenche vetor de ocorrência com zeros
    // se ocorre, outra função substitui a posição por 1
    // a palavras não ocorre até que seja encontrada

    for (i=0; i<num_palavras; i++){
        ocorrencia_palavras[i] = 0;

        }

}


void procura_horizontal_normal(int num_linhas, int num_colunas, char matriz_letras[MAX][MAX], char matriz_palavras[MAX][21], int vetor_ocorrencia[MAX], int p){
    
    int i,j, achou;

    for (i=0; i<num_linhas; i++){
            for (j=0; j<num_colunas; j++){

                // acha a primeira letra no meio da matriz
                if (matriz_letras[i][j] == matriz_palavras[p][0]){
                    
                    int pos = 0;
                    int j_aux = j;
                    achou = 1;

                    while (j_aux <= num_colunas && matriz_palavras[p][pos] != '\0'){ // esse while vai comparar 2 a 2 enquanto as caracteres forem iguais, somando j e pos
                        
                        if (matriz_letras[i][j_aux] != matriz_palavras[p][pos]){
                            achou = 0;
                            break; // encerra o loop
                        }

                        pos++;
                        j_aux++;

                    }

                    // se depois de fazer o loop, a última posição+1 for /0, a palavra ocorre na matriz de caracteres 
                    if (achou && matriz_palavras[p][pos+1] == '\0'){
                        vetor_ocorrencia[p] = 1; //sinal que ocorre
                        return;
                    }


                }
            }
        }


}

void procura_horizontal_invertida(int num_linhas, int num_colunas, char matriz_letras[MAX][MAX], char matriz_palavras[MAX][21], int vetor_ocorrencia[MAX], int p){
    
    int i,j, achou;

    for (i=num_linhas - 1; i>=0; i--){
            for (j=num_colunas - 1; j>=0; j--){

                // acha a primeira letra no meio da matriz
                if (matriz_letras[i][j] == matriz_palavras[p][0]){
                    
                    int pos = 0;
                    int j_aux = j;
                    achou = 1;

                    while (j_aux >= 0 && matriz_palavras[p][pos] != '\0'){ // esse while vai comparar 2 a 2 enquanto as caracteres forem iguais, somando j e pos
                        
                        if (matriz_letras[i][j_aux] != matriz_palavras[p][pos]){
                            achou = 0;
                            break;
                        }

                        pos++;
                        j_aux--;

                    }

                    // se depois de fazer o loop, a última posição+1 for /0, a palavra ocorre na matriz de caracteres 
                    if (achou && matriz_palavras[p][pos+1] == '\0'){
                        vetor_ocorrencia[p] = 1; //sinal que ocorre 
                        return;
                    }

                

                }
            }
        }


}


void procura_vertical_normal(int num_linhas, int num_colunas, char matriz_letras[MAX][MAX], char matriz_palavras[MAX][21], int vetor_ocorrencia[MAX], int p){

    int i,j, achou;

    for (i=0; i<num_colunas; i++){
                for (j=0; j<num_linhas; j++){

                    // acha a primeira letra no meio da matriz
                    if (matriz_letras[j][i] == matriz_palavras[p][0]){
                        

                        int pos = 0;
                        int j_aux = j;
                        achou = 1;

                        while (j_aux <= num_linhas && matriz_palavras[p][pos] != '\0'){ // esse while vai comparar 2 a 2 enquanto as caracteres forem iguais, somando j e pos
                            
                            if (matriz_letras[j_aux][i] != matriz_palavras[p][pos]){
                                achou = 0;
                                break;
                            }

                            pos++;
                            j_aux++;
                            
                        }

                        // se depois de fazer o loop, a última posição+1 for /0, a palavra ocorre na matriz de caracteres 
                        if (achou && matriz_palavras[p][pos+1] == '\0'){
                            vetor_ocorrencia[p] = 1; //sinal que ocorre 
                            return;
                        }


                    }
                }
            }


}

void procura_vertical_invertida(int num_linhas, int num_colunas, char matriz_letras[MAX][MAX], char matriz_palavras[MAX][21], int vetor_ocorrencia[MAX], int p){

    int i,j, achou;

    for (i=num_colunas - 1; i>=0; i--){
            for (j=num_linhas - 1; j>=0; j--){

                // acha a primeira letra no meio da matriz
                if (matriz_letras[j][i] == matriz_palavras[p][0]){
                    
                    int pos = 0;
                    int j_aux = j;
                    achou = 1;

                    while (j_aux >= 0 && matriz_palavras[p][pos] != '\0'){ // esse while vai comparar 2 a 2 enquanto as caracteres forem iguais, somando j e pos
                        
                        if (matriz_letras[j_aux][i] != matriz_palavras[p][pos]){
                            achou = 0;
                            break;
                        }

                        pos++;
                        j_aux--;

                    }

                    // se depois de fazer o loop, a última posição+1 for /0, a palavra ocorre na matriz de caracteres 
                    if (achou && matriz_palavras[p][pos+1] == '\0'){
                        vetor_ocorrencia[p] = 1; //sinal que ocorre 
                        return;
                    }
;

                }
            }
        }
}

void caca_palavras(char matriz_letras[][MAX], char matriz_palavras[MAX][21], int vetor_ocorrencia[MAX], int num_palavras, int num_linhas, int num_colunas){

    int p;
    for (p=0; p<num_palavras; p++){
        //procura na horizontal normal
        procura_horizontal_normal(num_linhas, num_colunas, matriz_letras, matriz_palavras, vetor_ocorrencia, p);
        if (!vetor_ocorrencia[p])
            // procura na horizontal invertida
            procura_horizontal_invertida(num_linhas, num_colunas, matriz_letras, matriz_palavras, vetor_ocorrencia, p);
        if (!vetor_ocorrencia[p])
            // procura na vertical normal
            procura_vertical_normal(num_linhas, num_colunas, matriz_letras, matriz_palavras, vetor_ocorrencia, p);
        if (!vetor_ocorrencia[p])
            // procura na vertical invertida
            procura_vertical_invertida(num_linhas, num_colunas, matriz_letras, matriz_palavras, vetor_ocorrencia, p);
       
    }

}

void printa_resultado(char matriz_palavras[MAX][21], int vetor_ocorrencia[MAX], int num_palavras){
    
    int i; 

    for (i=0; i<num_palavras; i++){
        
    
        if (vetor_ocorrencia[i] == 0){
            printf("A palavra %s não está no texto!\n", matriz_palavras[i]);

        }

        else if (vetor_ocorrencia[i] == 1){
            printf("A palavra %s está no texto!\n", matriz_palavras[i]);

        }

    }

}




int main(){
//primeiro cria a matriz e as variáveis
//depois preenche
//depois verifica
//depois printa
int i;
int l, c, p;

char matriz_char[MAX][MAX];
char matriz_palavras[MAX][21];
int ocorrencia_palavras[MAX];

scanf("%d %d %d ", &l, &c, &p);

preenche_matriz_char(matriz_char, l, c);
preenche_matriz_palavras(matriz_palavras, p);
preenche_vetor_ocorrencia(p, ocorrencia_palavras);

for (i=0;i<p; i++){
    caca_palavras(matriz_char, matriz_palavras, ocorrencia_palavras, p, l, c);
}

printa_resultado(matriz_palavras, ocorrencia_palavras, p);

return 0;
}