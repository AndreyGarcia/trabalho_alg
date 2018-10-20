#ifndef LISTA_C_INCLUDED
#define LISTA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void cria_lista(lista *l){

    l->pos = -1;
    l->tam_lista = 0;
}

int insere_na_lista(lista *l,brinquedo toy){

   l->pos++;
   l->vet[l->pos] = toy;
   l->tam_lista++;
    return 0;
}

int vazia_lista(lista *l){
    if(l->tam_lista == 0){
        return 1; // lista esta vazia;
    }
    return 0;
}

int cheia_lista(lista *l){
    if(l->pos == max-1){
        return 1; // lista esta cheia
    }
    return 0;
}

int remove_da_lista(lista *l, int pos, brinquedo toy){
    l->vet[pos].num_serial = -1;
    l->tam_lista--;
    return 0;
}

/*Esta função foi implementada apenas para teste do funcionamento da lista*/
void imprime_lista(lista l,int tam){
    int i = 0;
    while(tam > 0){
        printf("brinquedo: %d %s\n",l.vet[i].num_serial,l.vet[i].nome);
        i++;
        tam--;
    }
}

#endif // LISTA_C_INCLUDED
