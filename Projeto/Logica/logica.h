/**
@file logica.h
Definição da logica e das funções que o manipulam.
*/
#include "dados.h"

#ifndef LOGICA_H
#define LOGICA_H

/**
\brief Joga a cordenada no tabuleiro.
@param e Apontador para o estado
@param c A coordenada
@returns O valor 1 ou 0 dependendo se a cordenada foi aceite
*/
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Da update no player.
Esta funcao muda o player apos a execucao da jogada
@param e Apontador para o estado
@param c Apontador para a coordenada
*/
void update_player(ESTADO *e, COORDENADA c);

/**
\brief Verifica se as casas proximas estao vazias.
@param e Apontador para o estado
@param c A coordenada
@returns O valor 1 ou 0 dependendo se estao vazias ou nao
*/
int val_vazio(ESTADO *e, COORDENADA c);

/**
\brief Verifica se a jogada e permitida.
Esta funcao ve se a coordenada esta na vizinhanca da coordenada branca.
@param e Apontador para o estado.
@param c A coordenada.
@returns O valor 1 ou 0 dependendo se foi correta.
*/
int val_move(ESTADO *e, COORDENADA c);

/**
\brief Verifica se e possivel jogar.
Esta funcao ve se existe uma jogada possivel permitida na vizinhanca da peca branca.
@param e Apontador para o estado.
@returns O valor 1 ou 0 dependendo se e possivel.
*/
int val_sem_jogada(ESTADO *e);

/**
\brief Verifica se o jogo acabou.
@param e Apontador para o estado
@returns O valor 1 ou 0 dependendo da verificacao
*/
int game_over(ESTADO *e);

/**
\brief Retrocede o jogo.
Esta funcao volta a reescrever o jogo ate ao numero da jogada metida
@param e Apontador para o estado
@param numero Numero maximo da jogada retrocedida
@returns O valor 1 ou 0 dependendo da verificacao
*/
int pos(ESTADO *e, int numero);

/**
\brief Armazena na LISTA as possiveis jogadas no momento.
@param e Apontador para o estado
@param coordH Apontador para a struct list
@returns LISTA com as coordenadas das possiveis jogadas
*/
LISTA lista_jogadas(ESTADO *e, LISTA coordH);
/**
\brief Calcula a coordenada com a menor distancia a base.
@param Head Apontador para a struct list
@param e Apontador para o estado
@returns A coordenada com menor distancia
*/
COORDENADA euclides(LISTA Head, ESTADO *e);
/**
\brief Sorteio de uma coordenada da list.
@param Head Apontador para a struct list
@returns A coordenada sorteada
*/
COORDENADA luck(LISTA Head);
/**
\brief Sorteio de uma coordenada da list.
@param Head Apontador para a struct list
@param e Apontador para o estado
@returns e Apontador para o estado
*/
void jog(LISTA Head, ESTADO *e);
/**
\brief Executa a coordenada com menor distancia a base
@param Head Apontador para a struct list
@param e Apontador para o estado
@returns e Apontador para o estado
*/
void jog2(LISTA Head, ESTADO *e);

#endif