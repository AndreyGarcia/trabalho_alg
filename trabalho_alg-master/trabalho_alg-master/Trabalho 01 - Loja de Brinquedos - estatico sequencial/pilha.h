#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <stdio.h>
#include "lista.h"

#define tam_max

/*aqui foi incluida a lista.h pois nela ja estao contidas
as estruturas de no e brinquedo além da definição de max*/

typedef struct{
    brinquedo vet[2];
    int topo;
    int num_elementos;
} pilha;


void cria_pilha(pilha *P);
int push(pilha *p, brinquedo toy);
int top(pilha *p, brinquedo *toy);
int cheia_pilha(pilha *p);

#endif // PILHA_H_INCLUDED
