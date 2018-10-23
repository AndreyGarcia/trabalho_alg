#ifndef FILA_C_INCLUDED
#define FILA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*Aqui contem a implementação das funções da fila*/

void cria_fila(fila *f){
    f->inicio = NULL;
    f->fim = NULL;
    return;
}

int esta_vazia(fila *f){
    if(f->inicio == NULL){
        return 1;
    }
    return 0;
}

int insere_fila(fila *f,pilha cx){
    no_fila *novo_elemento = (no_fila*)malloc(sizeof(no_fila));
    if(novo_elemento == NULL){
        return 1;
    }
    novo_elemento->p = cx;
    novo_elemento->prox = NULL;
    if(esta_vazia(f)){
        f->inicio = novo_elemento;
        f->fim = novo_elemento;
    }
    else{
        f->fim->prox = novo_elemento;
        f->fim = novo_elemento;
    }
    return 0;
}

int remove_fila(fila *f, pilha *cx){
    if(esta_vazia(f)){
        return 1;
    }
    no_fila *aux = f->inicio;
    f->inicio = f->inicio->prox;
    if(f->fim == aux){
        f->fim = NULL;
    }
    *cx = aux->p;
    return 0;
}

#endif // FILA_C_INCLUDED
