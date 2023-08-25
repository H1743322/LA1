#include <stdlib.h>
#include <math.h>
#include "dados.h"
#define BUF_SIZE 1024

ESTADO *inicializar_estado() {
    int i, j;
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    COORDENADA inicial = {4, 3};
    e->jogador_atual = 1;
    e->num_jogadas = 1;
    e->jogadas[0].jogador2 = inicial;
    e->bot=0;

    e->num_comando = 1;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            set_casa(e, (COORDENADA) {j, i}, VAZIO);
        }
    }
    set_casa(e, (COORDENADA) {7, 0}, DOIS);
    set_casa(e, (COORDENADA) {0, 7}, UM);
    set_casa(e, (COORDENADA) {4, 3}, BRANCA);
    e->last_coord = coor_branca(e);
    //e->last_coord=inicial;


    return e;
}

int obter_numero_de_jogadas(ESTADO *e) {

    int n;
    n = e->num_jogadas;
    return n;
}

CASA obter_estado_casa(ESTADO *e, COORDENADA c) {
    CASA estado;
    estado = e->tab[c.coluna][c.linha];
    return estado;
}

int obter_jogador_atual(ESTADO *e) {
    int jogador;
    jogador = e->jogador_atual;
    return jogador;
}

int obter_num_comando(ESTADO *e) {
    int num;
    num = e->num_comando;
    return num;
}

void set_casa(ESTADO *e, COORDENADA c, CASA V) {
    int col, lin;
    col = c.coluna;
    lin = c.linha;
    e->tab[col][lin] = V;
}

COORDENADA coor_branca(ESTADO *e) {
    int i, j;
    COORDENADA error={-1,-1};

    for (i = 0; i < 8; i++) {

        for (j = 0; j < 8; j++) {
            COORDENADA c = {j, i};
            if (obter_estado_casa(e, c) == BRANCA)
                return c;
        }
    }
    return error;
}

int update_com(ESTADO *e) {
    int a;
    a = e->num_comando++;
    return a;
}
float euclidiana(COORDENADA a,COORDENADA b)
{
    float d=sqrtf(pow(a.linha - b.linha, 2) + pow(a.coluna - b.coluna, 2));
    //printf("%f ",d);
    return d;

}


