typedef struct{

    int n_identificacao_p; // enumero sequencialmente com um for 
    int n_participantes;
    int n_circuitos;
    int n_equipamentos;
    int pior_circuito;
    float valor_aluguel;
    
    Circuito *circuitos; // sera q ta certo isso?
    int *soma_participantes;


}Partida;



void recebe_entradas(int indice, Partida *partidas);

void relatorio_final(int indice, Partida *partidas);

void libera_memoria(int indice, Partida *partidas);