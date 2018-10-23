#ifndef FILA_C_INCLUDED
#define FILA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/* Função implementada para ajudar na impressão final do topo da pilha
    Recebe uma fila como argumento*/

void imprimetopofila(fila *f){
    for(int i=0; i< f->fim; i++){
        printf("caixa %d: %d %s, quantidade %d\n",i,f->vet[i].vet[f->vet[i].topo].num_serial,f->vet[i].vet[f->vet[i].topo].nome,f->vet[i].num_elementos);
    }
    printf("\n");
}
/* Aqui estao as outras funções implementadas como o requerido*/
void cria_fila(fila *f) {
    f->ini = 0;
    f->fim = 0;
    f->qtd = 0;
    return;
}

int estaCheia(fila *f) {
    return f->qtd == MAX_TAM;
}

int estaVazia(fila *f) {
    if (f->qtd == 0){
        return 1;
    }
    return 0;
}

int insere_fila(fila *f, pilha cx) {
    if (estaCheia(f)){
        return 1;
    }
    else{
    f->vet[f->fim] = cx;
    }
    f->qtd++;
    f->fim++;
    return 0;
}

int remove_fila(fila *f, pilha *cx) {
    if (estaVazia(f)){
        return 1;
    }
    *cx = f->vet[cx->topo];
    f->qtd--;
    f->ini++;
    return 0;
}

#endif // FILA_C_INCLUDED
