
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
LISTA criar_lista() {
    LISTA l = malloc(sizeof(Nodo));
    l->valor = NULL;
    l->next = NULL;
    return l;
}


/*void print_list(LISTA l) {
    while (l != NULL) {
        printf("[%s]\n ", l->valor);
        l = l->next;
    }
}*/

int lista_esta_vazia(LISTA l) {
    if (l == NULL)
        return 1;
    else
        return 0;
}

LISTA remove_cabeca(LISTA l) {
    LISTA temp;
    temp = l->next;
    free(l);
    return temp;

}

LISTA proximo(LISTA l) {
    return l->next;

}

LISTA insere_cabeca(LISTA l, void *valor) {
    LISTA new = criar_lista();
    new->valor = valor;
    new->next = l;
    return new;

}
void *devolve_cabeca(LISTA l)
{
    return l->valor;

}