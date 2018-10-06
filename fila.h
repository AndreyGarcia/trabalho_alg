#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "pilha.h"
/*aqui a pilha.h foi incluida pois ja tem
os recursos necessarios para implementação da fila*/

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
