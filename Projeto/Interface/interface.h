/**
@file interface.h
Definição da interface e das funções que o manipulam
*/

#include "dados.h"

#ifndef INTERFACE_H
#define INTERFACE_H

/**
\brief Mostra o tabuleiro.
Esta funcao mostra o tabuleiro e as respetivas CASAS .
@param e Apontador para o estado
@param file Apontador para o file
*/
void mostrar_tabuleiro(ESTADO *e, FILE *file);

/**
\brief Le os comandos do utilizador.
Esta funco interpreta o que o jogar escreveu na janela e compara se e uma funcao defenida no programa se for ele executa a funcao.
@param e Apontador para o estado
@returns O valor 1 ou 0 dependendo se foi correta
*/
int interpretador(ESTADO *e);

/**
\brief Escreve o prompt do jogo.
@param e Apontador para o estado
@param file Apontador para o file
*/
void prompt(ESTADO *e, FILE *file);

/**
\brief Intrudus o banner do jogo RASTOS
*/
void banner();

/**
\brief Mostra o valor da linha e da coluna de uma coordenada
@param c Coordenada
*/
void print_co(COORDENADA c);

/**
\brief Produz o menu
@returns Um inteiro 1 ou 0
*/
int menu();

/**
\brief Grava a jogada atual
@param e Apontador para o estado
@param filename Nome do arquivo
@returns Um inteiro 1 ou 0
*/
int gravar(ESTADO *e, char filename[100]);

/**
\brief Le o file que foi gravado
Esta funcao le linha a linha do ficheiro e mete na sctruct os valores escritos
@param e Apontador para o estado
@param filename Nome do arquivo
@returns Um inteiro 1 ou 0
*/
int ler(ESTADO *e, char filename[100]);

/**
\brief Escreve uma mensagem a dizer quem ganhou
@param e Apontador para o estado
*/
void val_game_over(ESTADO *e);

/**
\brief Imprime as coordenadas das jogadas anteriors
@param e Apontador para o estado
@param file Apontador para o file
*/
int movs(ESTADO *e, FILE *file);

#endif