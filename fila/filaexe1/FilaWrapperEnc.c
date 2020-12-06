#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "FilaWrapperEnc.h"


struct Fila
{
    struct Lists *Lst;
    int Size;
};

Queue* Criate_Queue_Wrapper (void)
{
    Queue *Fi = (Queue*) malloc (sizeof(Queue));
    if(Fi != NULL)
    {
        Fi->Lst = List_Criate();
        if(Fi->Lst == NULL)
        {
            free(Fi);
            Fi = NULL;
        }
    }
    return Fi;
}

void Free_Queue_Wrapper (Queue *Fi)
{
    if(Fi != NULL)
    {
        List_Free(Fi->Lst);
        free(Fi);
    }
}

int Enqueue_Wrapper (Queue *Fi, struct Students Al)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else
        return List_Push_Back(Fi->Lst, Al);
}

int Dequeue_Wrapper (Queue *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else
        return List_pop_Front (Fi->Lst);
}

int First_Queue_Wrapper (Queue *Fi, struct Students *Al)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else
        return List_Front(Fi->Lst, Al);
}

int Size_Queue_Wrapper (Queue *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Size_List (Fi->Lst);
}

int Full_Queue_Wrapper (Queue *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Full_List (Fi->Lst);
}

int Empyt_Queue_Wrapper (Queue *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Empty_List (Fi->Lst);
}

void Print_Queue_Wrapper (Queue *Fi)
{
    Print_List (Fi->Lst);
}