#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"

int main()
{
    printf("TESTE DA MAIN\n");
    lista l;
    cria_lista(&l);
    brinquedo b1,b2,b3,b4;
    b1.num_serial = 1;
    strcpy(b1.nome,"ioio");
    b2.num_serial = 2;
    strcpy(b2.nome,"boneca");
    b3.num_serial = 3;
    strcpy(b3.nome,"robo");
    b4.num_serial = 4;
    strcpy(b4.nome,"carro");

    insere_na_lista(&l,b1);
    printf("%s\n",l.fim->prox->b.nome);
    insere_na_lista(&l,b2);
    printf("%s\n",l.fim->prox->b.nome);
    insere_na_lista(&l,b3);
    printf("%s\n",l.fim->prox->b.nome);
    insere_na_lista(&l,b4);
    printf("%s\n",l.fim->prox->b.nome);
    remove_da_lista(&l,1,b1);
    printf("\n%s\n",l.fim->prox->b.nome);
    remove_da_lista(&l,3,b1);
    printf("\n%s\n",l.fim->prox->b.nome);

    printf("TESTE DA MAIN, PILHA\n");
    //TESTE DA PILHA
     b1.num_serial = 1;
    strcpy(b1.nome,"ioio");
    b2.num_serial = 2;
    strcpy(b2.nome,"boneca");
    b3.num_serial = 3;
    strcpy(b3.nome,"robo");
    b4.num_serial = 4;
    strcpy(b4.nome,"carro");
    pilha p;
    cria_pilha(&p);
    push(&p,b1);
    top(&p,&b1);
    printf("%s\n",b1.nome);
    push(&p,b2);
    top(&p,&b2);
    printf("%s\n",b2.nome);

    return 0;
}
