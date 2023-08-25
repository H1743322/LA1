#include <assert.h>
#include "teste.h"


int compare_coord(COORDENADA a, COORDENADA b) {
    if (a.coluna == b.coluna && a.linha == b.linha)
        return 1;
    else
        return 0;
}

void test_jogar() {
    ESTADO *e = inicializar_estado();
    //test COORD last
    COORDENADA last = {4, 3};
    assert(compare_coord(e->last_coord, last) == 1);
    // test JOG d4
    COORDENADA c = {3, 4};
    jogar(e, c);
    //test CASA d4
    assert(obter_estado_casa(e, c) == BRANCA);
    //test update coord
    assert(e->last_coord.coluna == c.coluna && e->last_coord.linha == c.linha);
    //test CASA last
    assert(obter_estado_casa(e, last) == PRETA);
    //test JOGADOR
    assert(e->jogador_atual == 2);
    //test NUM JOGADAS
    assert(e->num_jogadas == 1);
    //test JOGADAS
    assert(compare_coord(e->jogadas[e->num_jogadas].jogador1, c));

}

void test_jogar_impo() {
    ESTADO *e = inicializar_estado();
    //test JOGAR d3
    COORDENADA c = {3, 5};


    if (jogar(e, c) == 0) {
        assert(obter_estado_casa(e, c) == VAZIO);
        COORDENADA last = {4, 3};
        assert(obter_estado_casa(e, last) == BRANCA);
        assert(e->jogador_atual == 1);
        assert(e->num_jogadas == 1);
        assert(compare_coord(e->jogadas[e->num_jogadas].jogador1, c) == 0);
    }
}

void test_updateP() {
    ESTADO *e = inicializar_estado();
    assert(e->jogador_atual == 1);
    assert(e->num_jogadas == 1);
    COORDENADA c = {3, 4};
    update_player(e, c);
    assert(compare_coord(e->jogadas[1].jogador1, c) == 1);
    assert(e->jogador_atual == 2);
    COORDENADA c1 = {3, 5};
    update_player(e, c1);
    assert(compare_coord(e->jogadas[1].jogador2, c1) == 1);
    assert(e->jogador_atual == 1);
    assert(e->num_jogadas == 2);


}

void test_gameOver_none() {
    ESTADO *e = inicializar_estado();
    assert(game_over(e) == 0);

}

void test_gameOver_1() {
    ESTADO *e = inicializar_estado();
    COORDENADA c = {0, 7};
    set_casa(e, c, BRANCA);
    assert(game_over(e) == 1);


}

void test_gameOver_2() {
    ESTADO *e = inicializar_estado();
    COORDENADA c = {7, 0};
    set_casa(e, c, BRANCA);
    assert(game_over(e) == 2);


}

void test_pos() {
    ESTADO *e = inicializar_estado();
    jogar(e, (COORDENADA) {4, 4});
    jogar(e, (COORDENADA) {4, 5});
    jogar(e, (COORDENADA) {4, 6});
    jogar(e, (COORDENADA) {4, 7});
    pos(e, 1);
    assert(obter_estado_casa(e, (COORDENADA) {4, 4}) == PRETA);
    assert(obter_estado_casa(e, (COORDENADA) {4, 5}) == BRANCA);
    assert(obter_estado_casa(e, (COORDENADA) {4, 6}) == VAZIO);
    assert(obter_estado_casa(e, (COORDENADA) {4, 7}) == VAZIO);
    assert(e->jogador_atual == 1);
    assert(e->num_jogadas == 2);


}


int tests() {
    test_jogar();
    test_jogar_impo();
    test_updateP();
    test_gameOver_none();
    test_gameOver_1();
    test_gameOver_2();
    test_pos();


    return 1;
}


