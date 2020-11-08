#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstint.h"

struct Pilha_int
{
    float *num;
    int max;
    int size;
};

Stack_int* criat_stack_int (int tam)
{
    Stack_int *Pi;
    Pi = (Stack_int*) malloc (sizeof(Stack_int));
    if(Pi != NULL)
    {
        Pi->num = (float*) malloc (tam* sizeof(float));
        Pi->max = tam;
        Pi->size = 0;
    }
    return Pi;
}

void free_stack_Int (Stack_int *Pi)
{
    free(Pi->num);
    free(Pi);
}

// 1 insere
int push_stack_int (Stack_int *Pi, float val)
{
    if(Pi == NULL || Pi->num == NULL)
        return INVALID_NULL_POINTER;
    else if(Pi->size == Pi->max)
        return OUT_OF_MEMORY;

    Pi->num[Pi->size] = val;
    Pi->size++;
    return SUCESS;    
}

// 2 remove
int pop_stack_int (Stack_int *Pi)
{
    if(Pi == NULL || Pi->num == NULL)
        return INVALID_NULL_POINTER;
    else if(Pi->size == 0)
        return INVALID_OPERATION;
    else
    {
        Pi->size--;
        return SUCESS;
    }
}

// 3
int stack_top_int (Stack_int *Pi, float *val)
{
    if(Pi == NULL || Pi->num == NULL)
        return INVALID_OPERATION;
    else if(Pi->size == 0)
        return ELEM_NOT_FOUND;
    else
    {
        (*val) = Pi->num[Pi->size-1];
        return SUCESS;
    }
}

// 4
int size_stack_int (Stack_int *Pi)
{
    if(Pi == NULL || Pi->num == NULL)
        return INVALID_NULL_POINTER;
    else
        return Pi->size;
}

// 5
int empyt_stack_int (Stack_int *Pi)
{
    if(Pi == NULL || Pi->num == NULL)
        return INVALID_NULL_POINTER;
    else if(Pi->size == 0)
        return SUCESS;
    else
        return ELEM_NOT_FOUND; // false
}

// 6
int full_stack_int (Stack_int *Pi)
{
    if(Pi == NULL || Pi->num == NULL)
        return INVALID_NULL_POINTER;
    else if(Pi->size == Pi->max)
        return SUCESS;
    else
        return ELEM_NOT_FOUND;
}

// 7
void print_stack_int (Stack_int *Pi)
{
    if(Pi != NULL && Pi->num != NULL)
    {
        printf("Pilha de inteiros: ");
        for(int i = 0; i < Pi->size; i++)
        {
            printf("%.1f ",Pi->num[i]);
        }
        printf("\n");
    }
}
