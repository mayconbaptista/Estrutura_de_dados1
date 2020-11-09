#include <stdlib.h>
#include <stdio.h>
#include "bibliFilaEst.h"
#include "PilhaEstWrapper.h"

struct Pilha
{
    struct Listas *Li;
};

Stack* Criat_Stack_est (void)
{
    Stack *Pi;
    Pi = (Stack*) malloc (sizeof(Stack));
    if(Pi != NULL)
    {
        Pi->Li = Criate_List();
            if(Pi->Li == NULL)
                free(Pi);
    }
    return Pi;
}

void Free_Stack_est (Stack *Pi)
{
    Release_List(Pi->Li);
    free(Pi);
}

// 1)
int Push_Stack_est (Stack *Pi, struct Students Al)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Insert_List_Final(Pi->Li, Al);
}

// 2)
int Pop_Stack_est (Stack *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Remove_List_Final(Pi->Li);
}

// 3
int Top_Stack_est (Stack *Pi, struct Students *Al)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return List_back(Pi->Li, Al);
}

// 4
int Size_Stack_est (Stack *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Size_List(Pi->Li);
}

// 5
int Empyt_Stack_est (Stack *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Size_Empty(Pi->Li);
}

// 6
int Full_Stack_est (Stack *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Size_Full(Pi->Li);
}

// 7
int Print_Stack_est (Stack *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Print_List(Pi->Li);
}

