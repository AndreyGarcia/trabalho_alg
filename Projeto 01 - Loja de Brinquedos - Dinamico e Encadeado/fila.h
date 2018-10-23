#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "pilha.h"

/*  Aqui a pilha.h foi incluida pois ja tem
os recursos necessarios para implementa��o da fila.
    Nota-se que para a implementa��o da fila, um novo tipo de n� teve
de ser criado, onde o tipo de informa��o contida nele e uma pilha */

typedef struct no_fila{
    pilha p;
    struct no_fila *prox;
}no_fila;

typedef struct{
    no_fila *inicio,*fim;
}fila;

void cria_fila(fila *f);
int esta_vazia(fila *f);
int insere_fila(fila *f,pilha cx);
int remove_fila(fila *f, pilha *cx);
#endif // FILA_H_INCLUDED
