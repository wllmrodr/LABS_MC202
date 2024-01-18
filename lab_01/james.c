#include<stdio.h>
#define MAX 10000

void printer(int n_salada_de_fruta_p, int n_salada_de_fruta_m, int n_salada_de_fruta_g, int maior, int n_salada_maior_sequencia){

    printf("James vendeu %d saladas de 5 reais, %d de 7 reais e %d de 10 reais\n", n_salada_de_fruta_p, n_salada_de_fruta_m, n_salada_de_fruta_g);
    printf("James vendeu %d saladas de %d reais consecutivamente\n", maior, n_salada_maior_sequencia);
    
}


int main (){

    int n_salada_de_fruta;
    int n_salada_de_fruta_p = 0;
    int n_salada_de_fruta_m = 0;
    int n_salada_de_fruta_g = 0;
    int preco, i;
    int lista_vendas[MAX];
    int contador = 1;
    int maior = 1;
    int salada_de_maior_sequencia;

    scanf("%d",&n_salada_de_fruta);

    // laço que coloca os preços das saladas de fruta na lista de vendas do james e conta quanto cada uma de cada tamanho foi vendido
    for (i=0; i<n_salada_de_fruta; i++){
        
        scanf("%d", &preco);

        if (preco == 5){
            n_salada_de_fruta_p++;

        }

        else if (preco == 7){
            n_salada_de_fruta_m++;

        }

        else {
            n_salada_de_fruta_g++;

        }

        lista_vendas[i] = preco;

    }

    // laço que conta a maior sequência de salada de fruta vendida e salva o tamanho
    for (i=0; i<n_salada_de_fruta; i++){
        
        if (lista_vendas[i] == lista_vendas[i+1]){
            contador++;

        }

        else { // erro ta aqui
            if (contador > maior){
                maior = contador;
                salada_de_maior_sequencia = lista_vendas[i];

            }

            contador = 1;
        }

        if (i== n_salada_de_fruta-1){
            break;
        }
        
    } 


    printer(n_salada_de_fruta_p, n_salada_de_fruta_m, n_salada_de_fruta_g, maior, salada_de_maior_sequencia);

    return 0;
}