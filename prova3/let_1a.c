#include <stdio.h>
#include <stdlib.h>


int List_erave_even (List *Li)
{
    if(Li == NULL && Li->size == 0)
        return -1;

    int pos=1, res;
    Dlnode *aux;
    aux = Li->Bigin;
    while(aux != NULL)
    {
        if((aux->data % 2) == 0)
        {
            if(List_erase (Li , pos) == -1);
                return -1;
        }
    }
    return 0;
}