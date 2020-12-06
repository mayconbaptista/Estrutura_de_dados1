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