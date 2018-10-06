#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "lista.h"

/*aqui foi incluida a lista.h pois nela ja estao contidas
as estruturas de no e brinquedo*/

typedef struct{
    no* topo;
    int num_elementos;
}pilha;

void cria_pilha(pilha *p);
int esta_cheia(pilha *p,int tam_max);
int push(pilha *p,brinquedo toy);
int top(pilha *p,brinquedo *toy);


#endif // PILHA_H_INCLUDED
