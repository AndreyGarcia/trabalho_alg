#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "lista.h"

/*aqui foi incluida a lista.h pois nela ja estao contidas
as estruturas de no e brinquedo al�m da defini��o de max*/

typedef struct{
    brinquedo *vet;//o uso do ponteiro est� explicado no arquivo.c e no relatorio
    int tam_caixa;
    int topo;
    int num_elementos;
}pilha;

void cria_pilha(pilha *p,int tam);
int push(pilha *p, brinquedo toy);
int top(pilha *p, brinquedo *toy);
int isfull_pilha(pilha *p);

#endif // PILHA_H_INCLUDED
