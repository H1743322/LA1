#include "dados.h"
#include "logica.h"
/**
@file teste.h
Funções que testao o programa e o seu funcionamento
*/
#ifndef PROJETO_TESTE_H
#define PROJETO_TESTE_H

/**
\brief Executa todos os testes.
@returns 1 ou 0
*/
int tests();

/**
\brief Compara duas coordenadas.
@param a Coordenada 1
@param b Coordenada 2
@returns 1 ou 0
*/
int compare_coord(COORDENADA a, COORDENADA b);
/**
\brief Testa a fucncao jogar
*/
void test_jogar();
/**
\brief Testa a fucncao jogar de uma coordenada impossivel
*/
void test_jogar_impo();
/**
\brief Testa a fucncao update player
*/
void test_updateP();
/**
\brief Testa o fim do jogo quando ainda nao acabou
*/
void test_gameOver_none();
/**
\brief Testa o fim do jogo qd o player 1 ganha
*/
void test_gameOver_1();
/**
\brief Testa o fim do jogo qd o player 2 ganha
*/
void test_gameOver_2();
/**
\brief Testa a funcao pos
*/
void test_pos();


#endif //PROJETO_TESTE_H
