#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"

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

    //TESTE DA PILHA
    printf("TESTE DA MAIN, PILHA\n");
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

    //TESTE DA FILA
    printf("TESTE DA MAIN, FILA\n");
    pilha p1,p2;
    cria_pilha(&p1);
    cria_pilha(&p2);
    strcpy(b1.nome,"ioio");
    b2.num_serial = 2;
    strcpy(b2.nome,"boneca");
    b3.num_serial = 3;
    strcpy(b3.nome,"robo");
    b4.num_serial = 4;
    strcpy(b4.nome,"carro");
    push(&p1,b1);
    push(&p1,b2);
    push(&p2,b3);
    push(&p2,b4);
    fila f;
    cria_fila(&f);
    insere_fila(&f,p1);
    insere_fila(&f,p2);
    remove_fila(&f,&p);
    top(&p,&b1);
    printf("%s\n",b1.nome);
    remove_fila(&f,&p);
    top(&p,&b1);
    printf("%s\n",b1.nome);
    return 0;
}
