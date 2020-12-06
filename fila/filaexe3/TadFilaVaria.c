#include <stdio.h>
#include <stdlib.h>
#include "../../aluno.h"
#include "TadFilaVaria.h"
#include "math.h"

struct Fila
{
    struct Students *Data;
    int front;
    int rear;
    int Size;
    int MAX;
    int tam_inicial;
};


// cria
Queue* Criate_Queue_Variant (int tam)
{
    Queue *Fi = (Queue*) malloc (sizeof(Queue));
    if(Fi != NULL)
    {
        Fi->Data = (struct Students*) malloc (tam*sizeof(struct Students));
        if(Fi->Data != NULL)
        {
            Fi->front =0;
            Fi->rear = 0;
            Fi->tam_inicial= tam;
            Fi->MAX = tam;
            Fi->Size = 0;
        }
        else
        {
            free(Fi);
            Fi = NULL;
        }
    }
    return Fi;
}

// aqui
Queue* Realloc_Queue_Variant (Queue *Fi)
{
    if(Fi != NULL && Fi->Data != NULL)
    {
        Fi->MAX += Fi->tam_inicial;
        Fi->Data = (struct Students*) realloc (Fi->Data, Fi->MAX*sizeof(struct Students));
    }
    return Fi;
}

//
void Free_Queue_Variant (Queue *Fi)
{
    if(Fi != NULL)
    {
        free(Fi->Data);
        free(Fi);
    }
}

// 1 push
int Enqueue_Variant (Queue *Fi, struct Students Al)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else if(Fi->Size == Fi->MAX)
    {
        Realloc_Queue_Variant (Fi);
        Fi->Data[Fi->rear] = Al;
        Fi->rear = (Fi->rear +1 ) % Fi->MAX;
        Fi->Size++;
        return SUCESS;
    }
    else
    {
        Fi->Data[Fi->rear] = Al;
        Fi->rear = (Fi->rear +1 ) % Fi->MAX;
        Fi->Size++;
        return SUCESS;
    }
}

// 2 pop
int Dequeue_Variant (Queue *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else if(Fi->Size == 0)
        return OUT_NOT_RANGE;
    else
    {
        Fi->front++;
        Fi->Size--;
        return SUCESS;
    }
}

// 3 top
int First_Queue_Variant (Queue *Fi, struct Students *Al)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else if(Fi->Size == 0)
        return OUT_NOT_RANGE;
    else
    {
        (*Al) = Fi->Data[0];
        return SUCESS;
    }
}

// 4 size
int Size_Queue_Variant (Queue *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Fi->Size;
}

int Empty_Queue_Variant (Queue *Fi)
{
    if(Fi != NULL)
        return INVALID_NULL_POINTER;
    else if(Fi->Size == 0)
        return SUCESS;
    else
        return OUT_NOT_RANGE;
}

int Queue_Variant_Full (Queue *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else if(Fi->Size == Fi->MAX)
        return SUCESS;
    else
        return OUT_NOT_RANGE;
}

int Compact_Queue_Variant (Queue *Fi)
{
    if(Fi == NULL || Fi->Data == NULL)
        return INVALID_NULL_POINTER;
    else
    {
        int tam = ceil(Fi->Size / Fi->tam_inicial)* Fi->tam_inicial;
        Fi->Data = (struct Students*) realloc (Fi->Data, tam*sizeof(struct Students));
        if(Fi->Data == NULL)
            return OUT_NOT_RANGE;
        else
        {
            Fi->MAX = tam;
        }
    }
    return SUCESS;
}

void Print_Queue_Variant (Queue *Fi)
{
    if(Fi != NULL && Fi->Data != NULL)
    {
        printf("--------------------------------------------\n");
        for(int i=0; i < Fi->Size; i++)
        {
            printf("Matricula: %d\t",Fi->Data[i].matricula);
            printf("Nome: %s\t",Fi->Data[i].name);
            printf("Notas: %.1f %.1f %.1f\n",Fi->Data[i].n1,Fi->Data[i].n2,Fi->Data[i].n3);
        }
    }
}