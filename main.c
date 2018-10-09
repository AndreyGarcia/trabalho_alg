#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"

int main()
{
    int n,k,p;//n = qtd brinq, k = gap, p tam caixa
    brinquedo b_aux;
    printf("Entre com n,k,p e depois os brinquedos : ");
    scanf("%d %d %d",&n,&k,&p);
    lista esteira;
    cria_lista(&esteira);
    for(int i=0; i<n; i++){
        getchar();
        scanf("%d",&b_aux.num_serial);
        scanf("%s",b_aux.nome);
        insere_na_lista(&esteira,b_aux);
        //printf("brinquedo %d : %d %s\n",i+1,b_aux.num_serial,b_aux.nome);
    }
    //imprime_lista(esteira,n);
    pilha cx_aux;
    cria_pilha(&cx_aux);
    int i = 1;
    fila fila_esteira;
    cria_fila(&fila_esteira);
    //printf("\n%d\n",esteira.tam_lista);
    while(!vazia_lista(&esteira)){
            //printf("iteracao i = %d \n",i);
            //imprime_lista(esteira,esteira.tam_lista);
            b_aux.num_serial = -1; //incializa, se o ultimo brinquedo nao sair inicializado significa que tem uma caixa
            strcpy(b_aux.nome,"-1");     //para ser empilhada
            if(i <= esteira.tam_lista){
                remove_da_lista(&esteira,i,&b_aux);
                printf("brinquedo removido: %d %s\n",b_aux.num_serial,b_aux.nome);
                if(!esta_cheia(&cx_aux,p)){     //se a caixa nao esta cheia adiciono nela o brinquedo
                push(&cx_aux,b_aux);
                }
                else{                                   //se esta cheia eu insiro a caixa antiga na fila,
                    insere_fila(&fila_esteira,cx_aux);  //crio uma nova caixa e dou push
                    cria_pilha(&cx_aux);
                    push(&cx_aux,b_aux);
                }
                i = (i + k) - 1;
            }
            else{
                k--;
                i = 1;
            }
    }
    if(strcpy(b_aux.nome,"-1") !=0 ){
        insere_fila(&fila_esteira,cx_aux);
    }
    while(!remove_fila(&fila_esteira,&cx_aux)){
        top(&cx_aux,&b_aux);
        printf("brinquedo: %d %s\n",b_aux.num_serial,b_aux.nome);
    }


    return 0;
}

    /*printf("TESTE DA MAIN\n");
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
    printf("%s\n",b1.nome);*/
