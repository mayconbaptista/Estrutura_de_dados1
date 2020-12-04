#include <stdio.h>
#include <stdlib.h>
#include "FilaEncexe2.h"
#include "../../aluno.h"

struct Element
{
    struct Students Data;
    struct Element *next;
};
typedef struct Element Elem;

struct Fila
{
    struct Element *Bigin;
    struct Element *End;
    int Size;
};

Queue* Criate_Queue_Enc (void)
{
    Queue *Fi;
    Fi = (Queue*) malloc (sizeof(Queue));
    if(Fi != NULL)
    {
        Fi->Bigin = NULL;
        Fi->End = NULL;
        Fi->Size = 0;
    }
    return Fi;
}

void Free_Queue_Enc (Queue *Fi)
{
    if(Fi != NULL && Fi->Bigin != NULL)
    {
        Elem *aux;
        aux = Fi->Bigin;
        while(aux->next != NULL)
        {
            aux = Fi->Bigin;
            Fi->Bigin = Fi->Bigin->next;
            free(aux);
        }
        free(Fi->End);
        free(Fi);
    }
}

//1 insere
int Enqueue_Enc (Queue *Fi, struct Students Al)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    
    Elem *No;
    No = (Elem*) malloc (sizeof(Elem));
    if(No == NULL)
        return OUT_NOT_MEMORY;

    No->Data = Al;
    No->next = NULL;
    if(Fi->Size == 0)
    {
        Fi->Bigin = No;
        Fi->End = No;
    }
    else
    {
        Fi->End->next = No;
        Fi->End = No;
    }
    Fi->Size++;
    return SUCESS;
}

// 2
int Dequeue_Enc (Queue *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else if(Fi->Size == 0)
        return ELEM_NOT_FOUND;

    Elem *aux;
    aux = Fi->Bigin;
    if(Fi->Size == 1)
    {
        Fi->Bigin = NULL;
        Fi->End = NULL;
    }
    else
    {
        Fi->Bigin = Fi->Bigin->next;
    }
    Fi->Size--;
    free(aux);
    return SUCESS;
}

// 3
int First_Queue_Enc (Queue *Fi, struct Students *Al)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else if(Fi->Size == 0)
        return ELEM_NOT_FOUND;
    else
    {
        (*Al) = Fi->Bigin->Data;
        return SUCESS;
    }
    
}




// 5
int Size_Queue_Enc (Queue *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Fi->Size;
}

// 6
int Empyt_Queue_Enc (Queue *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else if(Fi->Size == 0)
        return SUCESS;
    else
        return OUT_NOT_RANGE;
}

// 7
int Full_Queue_Enc (Queue *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else
    {
        Elem *aux = (Elem*) malloc (sizeof(Elem));
        if(aux == NULL)
            return SUCESS;
        else
        {
            free(aux);
            return OUT_NOT_RANGE;
        }
    }
}


void Print_Queue_Enc (Queue *Fi)
{
    if(Fi != NULL && Fi->Bigin != NULL)
    {
        Elem *aux = Fi->Bigin;
        while(aux != NULL)
        {
            printf("Matricula: %d\t",aux->Data.matricula);
            printf("Nome: %s\t",aux->Data.name);
            printf("Notas: %.1f %.1f %.1f\n",aux->Data.n1, aux->Data.n2, aux->Data.n3);

            aux = aux->next;
        }
    }
}