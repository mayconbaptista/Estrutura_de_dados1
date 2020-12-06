#include <stdio.h>
#include <stdlib.h>

int Splice (List *dest,List *surce,int pos)
{
    if(dest == NULL || surce == NULL)
        return -1;

    Dlnove *aux;
    aux = dest->Bigin;
    cont;
    while(aux != NULL && const != pos)
    {
        aux = aux->next;
    }
    if(aux == NULL)
        return -1;
    else
    {
        aux->next = source->bigin;
        surce->prev = aux;
        aux->size += surce->size;

        surce->size = 0;
        surce->big = NULL;
        surce->end = NULL;
    }
    return 0;
}

/*
(cada item vale 2)
1) fez teste de posição e nulos
1
2) Testou se a inserção é no início
0
3) Testou se a posição é depois do último elemento
0
4) verificou que é no meio da lista e percorreu a lista procurando a posição
1
5) Atualizou o tamanho das listas
1
*/