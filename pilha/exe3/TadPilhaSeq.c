#include <stdio.h>
#include <stdlib.h>
#include "TadPilhaSeq.h"

struct Pilha_char
{
    char *Elem;
    int qdd, max;
};

Stack_char* Criate_Stack_char (int tam)
{
    Stack_char *Pi;
    Pi = (Stack_char*) malloc (sizeof(Stack_char));
    if(Pi != NULL)
    {
        Pi->Elem = (char*) malloc (tam*sizeof(char));
        Pi->qdd = 0;
        Pi->max = tam;
    }
    return Pi;
}

void Free_Stack_Char (Stack_char *Pi)
{
    free(Pi->Elem);
    free(Pi);
}


// 1)
int Push_Stack_Char (Stack_char *Pi, char c)
{
    if(Pi == NULL || Pi->Elem == NULL)
        return OUT_OF_MEMORY;
    else if(Pi->qdd == Pi->max)
        return INVALID_OPERATION;
    else
    {
        Pi->Elem[Pi->qdd] = c;
        Pi->qdd++;
        return SUCESS;
    }
}

// 2
int pop_Stack_Char (Stack_char *Pi)
{
    if(Pi == NULL && Pi->Elem == NULL)
        return OUT_OF_MEMORY;
    else if(Pi->qdd == 0)
        return ELEM_NOT_FOUND;
    else
    {
        Pi->qdd--;
        return SUCESS;
    }
}

//3
int Stack_Top_Char (Stack_char *Pi, char *c)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else if(Pi->Elem == NULL || Pi->qdd == 0)
        return ELEM_NOT_FOUND;
    else
    {
        (*c) = Pi->Elem[Pi->qdd-1];
        return SUCESS;
    }
}

// 4
int Size_Stack_Char (Stack_char *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Pi->qdd;
}

// 5)
int Full_Stack_Char (Stack_char *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else if(Pi->qdd == Pi->max)
        return SUCESS;
    else
        return ELEM_NOT_FOUND;
}

// 6)
int Empyt_Stack_Char (Stack_char *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else if(Pi->Elem == NULL || Pi->qdd == 0)
        return SUCESS;
    else
        return ELEM_NOT_FOUND;
}

// 7)
void Print_Stack_Char (Stack_char *Pi)
{
    if(Pi != NULL && Pi->Elem != NULL)
    {
        printf("Pilha de char: ");
        for(int i = 0; i < Pi->qdd; i++)
        {
            printf("%c",Pi->Elem[i]);
        }
        printf("\n");
    }
}