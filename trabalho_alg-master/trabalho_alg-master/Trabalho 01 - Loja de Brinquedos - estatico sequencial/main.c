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
                remove_da_lista(&esteira,i,b_aux);
                if(!cheia_pilha(&cx_aux)){     //se a caixa nao esta cheia adiciono nela o brinquedo
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
    if(strcmp(b_aux.nome,"-1") != 0){
        insere_fila(&fila_esteira,cx_aux);
    }
    while(!remove_fila(&fila_esteira,&cx_aux)){
        top(&cx_aux,&b_aux);
        printf("brinquedo: %d %s\n",b_aux.num_serial,b_aux.nome);
    }


    return 0;
}

/*
Especificações:

1<= n <= 1000; Tipo inteiro;
1<= k <= n; Tipo inteiro;
1<= p <= 1000; Tipo inteiro;

*/
