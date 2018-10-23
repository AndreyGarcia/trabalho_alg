#ifndef LISTA_C_INCLUDED
#define LISTA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/*Aqui foi incluida a string.h para o uso da função strcpy na
função remove da lista*/

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
    if(l->pos == MAX_TAM-1){
        return 1; // lista esta cheia
    }
    return 0;
}
/*O Indice -2 significa que nessa posicao existia um brinquedo, que agora foi subscrito*/
int remove_da_lista(lista *l, int *pos, brinquedo *toy){
    while(strcmp(l->vet[*pos].nome,"-2")== 0){
        *pos = *pos + 1;
    }
    *toy = l->vet[*pos];
    strcpy(l->vet[*pos].nome,"-2");
    l->vet[*pos].num_serial = -2;
    l->tam_lista--;
    return 0;
}

/*Esta função foi implementada apenas para teste do funcionamento da lista*/
void imprime_lista(lista l,int tam){
    int i = 0;
    while(tam > 0){
        printf("\nbrinquedo: %d %s\n",l.vet[i].num_serial,l.vet[i].nome);
        i++;
        tam--;
    }
}

#endif // LISTA_C_INCLUDED
