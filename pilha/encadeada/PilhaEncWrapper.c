#include <stdlib.h>
#include <stdio.h>
#include "auxlista.h"
#include "PilhaEncWrapper.h"
#include "Students.h"

Stak* Criat_Stak2 (void)
{
    Stak* Pi;
    Pi = List_Criate();
    return Pi;
}

void Free_Stak2 (Stak *Pi)
{
    List_Free(Pi);
};


int Insert_Stak2 (Stak *Pi, struct Students Al)
{
    int res;
    res = List_Push_Back(Pi, Al);
    if(res == INVALID_NULL_POINTER)
        return INVALID_NULL_POINTER;
    else if(res == OUT_OF_MEMORY)
        return OUT_OF_MEMORY;
    else
        SUCESS;
}

int Erase_Stak2 (Stak *Pi)
{
    int res;
    res = List_pop_Back(Pi);
    if(res == INVALID_NULL_POINTER)
        return INVALID_NULL_POINTER;
    else if(res == ELEM_NOT_FOUND)
        return ELEM_NOT_FOUND;
    else 
        return SUCESS;
}

int Stak_Back2 (Stak *Pi, struct Students *Al)
{
    int res;
    res = List_Back(Pi, Al);
    if(res == INVALID_NULL_POINTER)
        return INVALID_NULL_POINTER;
    else if(res == ELEM_NOT_FOUND)
        return ELEM_NOT_FOUND;
    else
        return SUCESS;
}

int Size_Stak2 (Stak *Pi)
{
    return Size_List(Pi);
}

void Print_Stak2 (Stak *Pi)
{
    if(Pi != NULL)
        Print_List(Pi);
}

int Empyt_Stack (Stak *Pi)
{
    if(Pi == NULL)
        return INVALID_NULL_POINTER;
    else
        return Empty_List(Pi);
}