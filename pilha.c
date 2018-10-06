#ifndef PILHA_C_INCLUDED
#define PILHA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void cria_pilha(pilha *p){
    p->num_elementos = 0;
    p->topo = NULL;
}

int esta_cheia(pilha *p,int tam_max){
    if(p->num_elementos == tam_max){
        return 1;
    }
    return 0;
}

int push(pilha *p,brinquedo toy){
    no* novo_elem = (no*)malloc(sizeof(no));
    if(novo_elem == NULL){
        return 1;
    }
    novo_elem->b = toy;
    novo_elem->prox = p->topo;
    p->topo =  novo_elem;
    p->num_elementos ++;
    return 0;
}

int top(pilha *p,brinquedo *toy){
    if(p->topo == NULL){
        return 1;
    }
    *toy = p->topo->b;
    return 0;
}


#endif // PILHA_C_INCLUDED
