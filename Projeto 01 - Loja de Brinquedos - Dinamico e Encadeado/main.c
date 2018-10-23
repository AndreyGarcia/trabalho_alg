#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"

int main(int argc, char *argv[])
{
    /*Nesta primeira parte do codigo serao inicializadas as variaveis
    n = quantidade de brinquedos, k = gap, p = tamanho da caixa/pilha
    atraves do que foi recebido em argv*/

    int n,k,p;
    int count_argv = 1;
    n = atoi(argv[count_argv]);
    count_argv++;
    k = atoi(argv[count_argv]);
    count_argv++;
    p = atoi(argv[count_argv]);
    count_argv++;

    /*Nesta segunda parte estão sendo declaradas as variaveis para a esteira
    e uma do tipo brinquedo para servir de auxilio para coloca-los na lista
    aqui foi/e será utilizada a função atoi que converte um caractere ascii para int*/

    brinquedo b_aux;
    lista esteira;
    cria_lista(&esteira);
    for(int i=0; i<n; i++){
        b_aux.num_serial = atoi(argv[count_argv]);
        count_argv++;
        strcpy(b_aux.nome,argv[count_argv]);
        count_argv++;
        insere_na_lista(&esteira,b_aux);
    }

    /*Aqui, com os brinquedos ja na lista serão declaradas uma pilha/caixa auxiliar
    e uma fila que representa a segunda esteira(fila de caixas)*/

    pilha cx_aux;
    cria_pilha(&cx_aux);
    int i = 1;
    fila fila_esteira;
    cria_fila(&fila_esteira);

    /*Neste loop while será feita a remoção dos brinquedos respeitando os gaps e a ordem, nesse caso
    a variavel b_aux e incializada com o nome do brinquedo como -1, pois se isso não for alterado significa
    que temos uma caixa vazia no ultimo brinquedo*/

    while(!vazia_lista(&esteira)){
            b_aux.num_serial = -1; //incializa, se o ultimo brinquedo nao sair inicializado significa que tem uma caixa
            strcpy(b_aux.nome,"-1");     //para ser empilhada
            if(i <= esteira.tam_lista){
                remove_da_lista(&esteira,i,&b_aux);
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

    /*Aqui temos o caso de a ultima caixa nao estar vazia, se ela estiver, não sera empilhada,
    se tiver algo, ela sera inserida na fila*/
    if(strcmp(b_aux.nome,"-1") !=0 ){
        insere_fila(&fila_esteira,cx_aux);
    }
    while(!remove_fila(&fila_esteira,&cx_aux)){
        top(&cx_aux,&b_aux);
        printf("brinquedo: %d %s",b_aux.num_serial,b_aux.nome);
        printf(", quantidade : %d\n",cx_aux.num_elementos);
    }


    return 0;
}
