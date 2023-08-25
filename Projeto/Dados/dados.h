/**
@file dados.h
Definição do estado e das funções que o manipulam
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifndef DADOS_H
#define DADOS_H
#define BUF_SIZE 1024
/**
\brief Tipo de dados para os erros
*/
typedef enum {
    OK,
    COORDENADA_INVALIDA,
    JOGADA_INVALIDA,
    ERRO_LER_TAB,
    ERRO_ABRIR_FICHEIRO
} ERROS;

/**
\brief Tipo de dados para a casa
*/
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;
/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
/**
\brief Tipo de dados para a jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];
/**
\brief Tipo de dados para o estado
*/
typedef struct {
    /** O tabuleiro */
    CASA tab[8][8];
    /** As jogadas */
    JOGADAS jogadas;
    /** A coordenada da última jogada */
    COORDENADA last_coord;
    /** O nº de comando, usado no prompt */
    int num_comando;
    /** O número das jogadas, usado no prompt */
    int num_jogadas;
    /** O jogador atual */
    int jogador_atual;
    /** Switch para o bot */
    int bot;
} ESTADO;



/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
*/
ESTADO *inicializar_estado();

/**
\brief Devolve o numero de jogadas
Esta funcao devolve o numero de jogadas contadas num parametro da sturct.
@param e Apontador para o estado
@returns O numero de jogads
*/
int obter_numero_de_jogadas(ESTADO *e);

/**
\brief Devolve o valor de uma casa
Esta função ve o estado da cordenada c no tabuleiro e devolve o estado da mesma.
@param e Apontador para o estado
@param c A coordenada
@returns O valor da casa
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);

/**
\brief Devolve o jogador atual
Esta função devolve o jogador atual que esta na struct estado .
@param e Apontador para o estado
@returns O jogador atual
*/
int obter_jogador_atual(ESTADO *e);

/**
\brief Devolve o numero de comandos efetuados
Esta função devolve o numero de comandos que esta na struct estado.
@param e Apontador para o estado
@returns O numero de comandos
*/
int obter_num_comando(ESTADO *e);

/**
\brief Muda o valor de uma casa
Esta função vai ao tabuleiro do jogo e na coordenada c troca peca da casa para a peca V.
@param e Apontador para o estado
@param c A coordenada
@param V O novo valor para a casa
*/
void set_casa(ESTADO *e, COORDENADA c, CASA V);

/**
\brief Encontra a ccoordenada onde esta a peca branca
Esta função pecorre o tabuleiro e ve onde esta a coordenada com a CASA BRANCO
@param e Apontador para o estado
@returns A coordenada da posicao branca
*/
COORDENADA coor_branca(ESTADO *e);

/**
\brief Acrescenta 1 ao numero de comandos
Esta função acrescenta 1 ao numero dos comandos na struct estado.
@param e Apontador para o estado
@returns O numero de comandos
*/
int update_com(ESTADO *e);
/**
\brief Faz o calculo da distacncia euclidiana de duas coordenadas
@param a Coordenada
@param b Coordenada
@returns Distancia entre as coordenadas
*/
float euclidiana(COORDENADA a,COORDENADA b);




#endif

