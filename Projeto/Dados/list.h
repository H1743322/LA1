/**
@file list.h
Definição da lista generica e das funções que o manipulam
*/
#ifndef PROJETO_LIST_H
#define PROJETO_LIST_H
/**
\brief Tipo de dados generico
*/
typedef struct list *LISTA;
typedef struct list {
    void *valor;
    LISTA next;
} Nodo;
/**
\brief Cria uma lista
Esta função cria espaco para uma LISTA
@returns o endereco do espaco  criado
*/
LISTA criar_lista();
/**
\brief Junta nodo a cabeca da lista
@param L Lista
@param valor Endereco de um valor
@returns o endereco do espaco  criado
*/
LISTA insere_cabeca(LISTA L, void *valor);
/**
\brief Devolve a cabeca da lista
@param L Lista
@returns Endereco do valor da cabeca
*/
void *devolve_cabeca(LISTA L);
/**
\brief Avanca para o proximo nodo
@param L Lista
@returns o endereco da prox lista
*/
LISTA proximo(LISTA L);
/**
\brief Remove cabeca da lista
@param L Lista
@returns o endereco do proximo nodo da lista
*/
LISTA remove_cabeca(LISTA L);
/**
\brief Verifica se esta no final da lista ou seja se e NULL
@param L Lista
@returns 1 ou 0 dependendo se a lista chegou ao final
*/
int lista_esta_vazia(LISTA L);
#endif //PROJETO_LIST_H
