#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

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
}lista;

void cria_lista(lista *l);
int insere_na_lista(lista *l,brinquedo toy);
int vazia_lista(lista *l);
int remove_da_lista(lista *l, int pos, brinquedo toy);

#endif // LISTA_H_INCLUDED
