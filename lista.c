#ifndef LISTA_C_INCLUDED
#define LISTA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void cria_lista(lista *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->tam_lista = 0;
}

int insere_na_lista(lista *l,brinquedo toy){
    no *novo_elemento = (no*)malloc(sizeof(no));
    if(novo_elemento == NULL){
        return 1;
    }
    novo_elemento->b = toy;
    /*se a fila estiver vazia, o inicio tera que ser atualizado*/
    if(l->inicio == NULL){
        l->inicio = novo_elemento;
        l->fim = novo_elemento;
    }
    else{
        l->fim->prox = novo_elemento;
        l->fim = novo_elemento;
    }
    /*com isso a lista fica circular*/
    l->fim->prox = l->inicio;
    l->tam_lista ++;
    return 0;
}

int vazia_lista(lista *l){
    return (l->tam_lista == 0);
}

int remove_da_lista(lista *l, int pos, brinquedo *toy){
    if(vazia_lista(l)){
        return 1;
    }
    no *aux = l->inicio;
    no *anterior;
    while(pos-1 > 0){
        anterior = aux;
        aux = aux->prox;
        pos--;
    }
    *toy = aux->b;
    /*ver se e o começo da lista*/
    if(l->inicio == aux){
        l->inicio = l->inicio->prox;
        l->fim->prox = l->inicio;
    }
    else{
        anterior->prox = aux->prox;
        if(l->fim == aux){
            l->fim = anterior;
            l->fim->prox = l->inicio;
        }
    }
    free(aux);
    l->tam_lista --;
    return 0;
}

void imprime_lista(lista l,int tam){
    while(tam > 0){
        printf("brinquedo: %d %s\n",l.inicio->b.num_serial,l.inicio->b.nome);
        l.inicio = l.inicio->prox;
        tam--;
    }
}

#endif // LISTA_C_INCLUDED
