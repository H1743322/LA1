#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logica.h"


int jogar(ESTADO *e, COORDENADA c) {

    //print_co(c);
    if (val_move(e, c) == 1 && val_vazio(e, c) == 1) {


        set_casa(e, e->last_coord, PRETA);
        set_casa(e, c, BRANCA);
        e->last_coord = c;
        update_player(e, c);

    } else {
        return 0;
    }
    return 1;
}

int val_vazio(ESTADO *e, COORDENADA c) {
    if (obter_estado_casa(e, c) == VAZIO || obter_estado_casa(e, c) == UM || obter_estado_casa(e, c) == DOIS)
        return 1;
    else
        return 0;
}

int val_move(ESTADO *e, COORDENADA c) {

    int lin = c.linha;
    int col = c.coluna;
    //int lin2 = e->last_coord.linha;
    //int col2 = e->last_coord.coluna;
    int lin2 = coor_branca(e).linha;
    int col2 = coor_branca(e).coluna;
    if (abs(col2 - col) <= 1 && abs(lin2 - lin) <= 1 && (col2 != col || lin2 != lin))
        return 1;
    else
        return 0;
}

void update_player(ESTADO *e, COORDENADA c) {

    if (obter_jogador_atual(e) == 1) {
        e->jogador_atual = 2;
        e->jogadas[e->num_jogadas].jogador1 = c;
        //printf("(%d,%d)",e->jogadas[e->num_jogadas].jogador1.coluna,e->jogadas[e->num_jogadas].jogador1.linha);


    } else {
        e->jogador_atual = 1;
        e->jogadas[e->num_jogadas].jogador2 = c;
        //printf("(%d,%d)",e->jogadas[e->num_jogadas].jogador2.coluna,e->jogadas[e->num_jogadas].jogador2.linha);
        e->num_jogadas++;
    }
}

int game_over(ESTADO *e) {

    if (obter_estado_casa(e, (COORDENADA) {0, 7}) == BRANCA || val_sem_jogada(e) == 2)

        return 1;
    if (obter_estado_casa(e, (COORDENADA) {7, 0}) == BRANCA || val_sem_jogada(e) == 1)
        return 2;
    else
        return 0;
}

int val_sem_jogada(ESTADO *e) {
    int lin2 = coor_branca(e).linha;
    int col2 = coor_branca(e).coluna;
    int a = 1, b = 1, c = 1, d = 1;


    if (col2 == 0)
        c = 0;
    if (col2 == 7)
        d = 0;
    if (lin2 == 0)
        a = 0;
    if (lin2 == 7)
        b = 0;


    for (int i = lin2 - a; i <= lin2 + b; i++) {
        for (int j = col2 - c; j <= col2 + d; j++) {
            COORDENADA lc = (COORDENADA) {j, i};
            if (obter_estado_casa(e, lc) == VAZIO || obter_estado_casa(e, lc) == UM || obter_estado_casa(e, lc) == DOIS)
                return 0;

        }
    }

    if (obter_jogador_atual(e) == 1)
        return 1;
    else
        return 2;

}


int pos(ESTADO *e, int numero) {
    int o, j, i;
    COORDENADA ola;
    COORDENADA inicial = {4, 3};

    int max =obter_numero_de_jogadas(e);
    if (numero>max)
        return 0;
    e->num_jogadas = 1;
    e->jogadas[0].jogador2 = inicial;
    e->jogador_atual = 1;


    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            set_casa(e, (COORDENADA) {j, i}, VAZIO);
        }
    }
    set_casa(e, (COORDENADA) {7, 0}, DOIS);
    set_casa(e, (COORDENADA) {0, 7}, UM);
    set_casa(e, (COORDENADA) {4, 3}, BRANCA);
    e->last_coord = coor_branca(e);

    for (o = 1; o <= numero; o++) {
        //print_co(e->jogadas[o].jogador1);
        ola = e->jogadas[o].jogador1;

        jogar(e, ola);
        //print_co(e->jogadas[o].jogador2);
        ola = e->jogadas[o].jogador2;
        jogar(e, ola);
    }
    return 1;

}


LISTA lista_jogadas(ESTADO *e, LISTA coordH) {

    COORDENADA *d;

    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {

            COORDENADA c = {j, i};
            if (val_move(e, c) == 1 && val_vazio(e, c) == 1) {
                d = malloc(sizeof(COORDENADA));
                d->linha = i;
                d->coluna = j;
                coordH = insere_cabeca(coordH, d);

            }
        }
    }
    return coordH;

}

COORDENADA euclides(LISTA Head, ESTADO *e) {
    /*2printf("\n==============================\n");
    printf(  "=          PERCURSO          =\n");
    printf(  "==============================\n\n");
    // percorre sem remover os elementos da lista
    for(LISTA T = Head;lista_esta_vazia(T)==0; T = proximo(T)) {
        COORDENADA *str = (COORDENADA*) devolve_cabeca(T);
        print_co(*str);
    }*/
    COORDENADA b;
    if (obter_jogador_atual(e) == 1) {
        b = (COORDENADA) {0, 7};
    } else {
        b = (COORDENADA) {7, 0};
    }
    float min = 10, dis;
    COORDENADA *best = NULL;
    for (LISTA O = Head; lista_esta_vazia(O) == 0; O = proximo(O)) {
        COORDENADA *a = (COORDENADA *) devolve_cabeca(O);
        dis = euclidiana(*a, b);
        if (dis < min) {
            min = dis;
            best = a;
        }

    }
    //print_co(*best);
    //printf("%f",min);

    return *best;

}

COORDENADA luck(LISTA Head) {
    int ola = 0;
    int Ncoo = 0;
    COORDENADA *best;
    LISTA J = Head;


    for (LISTA O = Head; lista_esta_vazia(O) == 0; O = proximo(O)) {
        Ncoo++;
    }

    int num = (rand() % (Ncoo - 0 + 0)) + 0;
    //printf("%d",num);
    for (; ola < num; J = proximo(J)) {
        ola++;
    }
    best = (COORDENADA *) devolve_cabeca(J);
    //print_co(*best);

    return *best;


}

void jog(LISTA Head, ESTADO *e) {
    Head = lista_jogadas(e, Head);
    COORDENADA best;
    best = luck(Head);
    jogar(e, best);


}

void jog2(LISTA Head, ESTADO *e) {
    Head = lista_jogadas(e, Head);
    COORDENADA best;
    best = euclides(Head, e);
    jogar(e, best);


}


