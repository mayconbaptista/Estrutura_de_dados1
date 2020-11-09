#include <stdlib.h>
#include <stdio.h>
#include "auxlista.h"
#include "PilhaEncWrapper.h"

struct Pilha
{
    struct Lists *Li;
};

Stack* Criat_Stack_enc (void)
{
    Stack* Pi;
    Pi = (Stack*) malloc (sizeof(Stack));
    if(Pi != NULL)
    {
        Pi->Li = List_Criate();
        if(Pi->Li == NULL)
            free(Pi);
    }
    return Pi;
}

void Free_Stack_enc (Stack *Pi)
{
    List_Free(Pi->Li);
    free(Pi);
};


int Push_Stack_enc (Stack *Pi, struct Students Al)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return List_Push_Back(Pi->Li, Al);
}

int Pop_Stack_enc (Stack *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return List_pop_Back(Pi->Li);
}

int Stack_Top_enc (Stack *Pi, struct Students *Al)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return List_Back(Pi->Li, Al);
}

int Size_Stack_enc (Stack *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Size_List(Pi->Li);
}

void Print_Stack_enc (Stack *Pi)
{
    if(Pi != NULL)
        Print_List(Pi->Li);
}

int Empyt_Stack_enc (Stack *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Empty_List(Pi->Li);
}