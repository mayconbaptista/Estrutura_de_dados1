#include <stdlib.h>
#include <stdio.h>
#include "bibliFilaEst.h"
#include "PilhaEstWrapper.h"

Stack* Criat_Stak (void)
{
    Stack *Pi;
    Pi = Criate_List();
    return Pi;
}

void Free_Stak (Stack *Pi)
{
    Release_List(Pi);
}

// 1)
int Push_Stak (Stack *Pi, struct Students Al)
{
    if(Pi == NULL)
        return -1;
    else
        return Insert_List_Final(Pi, Al);
}

// 2)
int Pop_Stack (Stack *Pi)
{
    if(Pi == NULL)
        return -1;
    else
        return Remove_List_Final(Pi);
}

// 3
int Top_Stack (Stack *Pi, struct Students *Al)
{
    if(Pi == NULL)
        return -1;
    else
        return List_back(Pi, Al);
}

// 4
int Size_Stak (Stack *Pi)
{
    if(Pi == NULL)
        return -1;
    else
        return Size_List(Pi);
}

// 5
int Empyt_stack (Stack *Pi)
{
    if(Pi == NULL)
        return -1;
    else
        return Size_Empty(Pi);
}

// 6
int Full_Stack (Stack *Pi)
{
    if(Pi == NULL)
        return -1;
    else
        return Size_Full(Pi);
}

// 7
int Print_Stack (Stack *Pi)
{
    return Print_List(Pi);
}

