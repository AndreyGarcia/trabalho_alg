#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/*  Aqui est�o definidos os tipos para o brinquedo, o no e para a lista
nota-se que temos uma varivel para guardar o tamanho da lista nessa
implementa��o.
    Tamb�m est�o definidos os cabe�alhos das fun��es do arquivo lista.c*/

typedef struct{
    int num_serial;
    char nome[50];
}brinquedo;

typedef struct no{
    brinquedo b;
    struct no *prox;
}no;

typedef struct{
    no *inicio;
    no *fim;
    int tam_lista;
}lista;

void cria_lista(lista *l);
int insere_na_lista(lista *l,brinquedo toy);
int vazia_lista(lista *l);
int remove_da_lista(lista *l, int pos, brinquedo *toy);
void imprime_lista(lista l,int tam);

#endif // LISTA_H_INCLUDED
