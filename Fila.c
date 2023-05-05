#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

//função criar fila
Fila *criarFila()
{
    Fila *fila;
    fila =(Fila *) calloc(1, sizeof(Fila));

    fila->tamanho = 0;
    fila->inicio = fila->fim = NULL;
    return fila;
}
int filaVazia(Fila *fila)
{
    return (fila->inicio == NULL);
}
//função enfileirar 
void InserirElementoNaFila(Fila *fila, Item valor)
{

    Lista *listaNovo;
    listaNovo =(Lista*) malloc(sizeof(Lista));
    listaNovo->item = valor;
    listaNovo->proximo = NULL;
    if(fila->tamanho < 0)
       fila =  criarFila();
    if(!filaVazia(fila))
    {

        fila->fim->proximo = listaNovo;
        fila->fim = listaNovo;
    }
    else
    {
        fila->tamanho = 1;
        fila->fim = listaNovo;
        fila->inicio = fila->fim;
    }
    fila->tamanho++;


}
//função de desenfileirar 
Item desenfileirar(Fila *fila)
{

    Lista *novaLista;
    Item item = fila->inicio->item;
    novaLista = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    fila->tamanho--;
    free(novaLista);
    return(item);
}




