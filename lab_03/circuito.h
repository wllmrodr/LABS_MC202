typedef struct{

    int n_identificacao_c; 
    int n_participantes; 
    // vetor dinâmico de jogadas
    int *jogadas;
  

}Circuito;


int pior_circuito(int n_circuitos, int n_participantes, Circuito *circuitos); //pego vetor de circuitos e analiso o vetor de jogadas de cada um e vejo qual maior e pego o id


void soma_jogadas(int n_circuitos, int n_participantes, Circuito *circuitos, int *vetor_soma);

 // será que posso criar um novo vetor com a soma dos jogadores?