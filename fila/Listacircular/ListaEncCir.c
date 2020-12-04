#include "ListaEncCir.h"
#include <stdio.h>
#include <stdlib.h>

struct Element
{
    struct Students Data;
    struct Element *Next;
};
typedef struct Element Elem;

struct Lista
{
    struct Element *End;
    int Size;
};



List* Criate_Lista_Circular (void)
{
    List *Li = (List*) malloc (sizeof(List));
    if(Li != NULL)
    {
        Li->End = NULL;
        Li->Size = 0;
    }
    return Li;
}

void Free_List_Circular (List *Li)
{
    if(Li != NULL && Li->End != NULL)
    {
        Elem *aux, *no;
        no = Li->End;
        while(no->Next != Li->End)
        {
            aux = no;
            no = no->Next;
            free(aux);
        }
        free(no);
        free(Li);
    }
}

// Funçoes de incerção
int Push_Front_List_Circular (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    
    Elem *No = (Elem*) malloc (sizeof(Elem));
    if(No == NULL)
        return OUT_NOT_MEMORY;
    
    No->Data = Al;
    if(Li->End == NULL)
    {
        Li->End = No;
        No->Next = No;
    }
    else
    {
        No->Next = Li->End->Next;
        Li->End->Next = No;
    }
    Li->Size++;
    return SUCESS;
}

// insere final
int Push_Back_List_Circular (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else
    {
        Elem *No = (Elem*) malloc (sizeof(Elem));
        if(No == NULL)
            return OUT_NOT_MEMORY;
        else
        {
            No->Data = Al;
            if(Li->End == NULL)
            {
                No->Next = No;
                Li->End = No;
            }
            else
            {
                No->Next  = Li->End->Next;
                Li->End->Next = No;
                Li->End = No;
            }
        }
    }
    Li->Size++;
    return SUCESS;
}

// indicado por pos
int Insert_List_Circular_Ordered_Pos (List *Li, struct Students Al, int pos)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(pos > (Li->Size +1) || pos < 1)
        return OUT_NOT_RANGE;
    else
    {
        if(pos == 1)
        {
            return Push_Front_List_Circular(Li, Al);
        }
        else if(pos == (Li->Size+1) && Li->End != NULL)
        {
            return Push_Back_List_Circular(Li, Al);
        }
        else
        {
            Elem *No = (Elem*) malloc (sizeof(Elem));
            No->Data = Al;
            if(No == NULL)
                return OUT_NOT_MEMORY;
            else
            {
                Elem *ant, *aux = Li->End->Next;
                int cont=1;
                while(cont != pos)
                {
                    ant = aux;
                    aux = aux->Next;
                    cont++;
                }
                ant->Next = No;
                No->Next = aux;
            }
        }
        Li->Size++;
        return SUCESS;
    }
}

// insere ordenado por matricula 
int Insert_List_Circular_Ordered_Mat (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else
    {
        Elem *aux= Li->End->Next;
        int cont=1;
        while(cont != (Li->Size + 1) && aux->Data.matricula < Al.matricula)
        {
            aux = aux->Next;
            cont++;
        }
        return Insert_List_Circular_Ordered_Pos(Li, Al, cont);
    }
}
// Funçoes de remoção
int List_Circular_Pop_Front (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->End == NULL)
        return ELEM_NOT_FOUND;
    else if(Li->Size == 1)
    {
        free(Li->End);
        Li->End = NULL;
    }
    else
    {
        Elem *aux = Li->End->Next;
        Li->End->Next = aux->Next;
        free(aux);
    }
    Li->Size--;
    return SUCESS;
}

// remove final;
int List_Circular_Pop_Back (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->End == NULL)
        return ELEM_NOT_FOUND;
    else if(Li->Size == 1)
    {
        free(Li->End);
        Li->End = NULL;
    }
    else
    {
        Elem *aux = Li->End->Next;
        while(aux->Next != Li->End)
        {
            aux = aux->Next;
        }
        aux->Next = Li->End->Next;
        free(Li->End);
        Li->End = aux;
    }
    Li->Size--;
    return SUCESS;
}

int List_Circular_Erase_Pos (List *Li, int pos)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(pos > Li->Size || pos < 1)
        return ELEM_NOT_FOUND;
    else if(pos == 1)
        return List_Circular_Pop_Front(Li);
    else if(pos == Li->Size)
        return List_Circular_Pop_Back(Li);
    else
    {
        Elem *prev, *aux = Li->End->Next;
        int cont=0;
        while(cont != pos && aux->Next != Li->End)
        {
            prev = aux;
            aux = aux->Next;
            cont++;
        }
        prev->Next = aux->Next;
        free(aux);
        Li->Size--;
        return SUCESS; 
    }
}

int List_Circular_Erase_mat (List *Li, int mat)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->End == NULL)
        return ELEM_NOT_FOUND;
    else
    {
        Elem *prev, *aux = Li->End->Next;
        if(aux->Data.matricula == mat)
            return List_Circular_Pop_Front(Li);
        else if(Li->End->Data.matricula == mat)
            return List_Circular_Pop_Back(Li);
        else
        {
            while(aux->Data.matricula != mat && aux != Li->End)
            {
                prev = aux;
                aux = aux->Next;
            }
            if(aux->Data.matricula == mat)
            {
                prev->Next = aux->Next;
                free(aux);
                Li->Size--;
                return SUCESS;
            }
            else
                return ELEM_NOT_FOUND;
        }
    }
}


// funçes de consulta;

int List_Circular_Find_pos (List *Li,int pos, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->End == NULL && Li->Size == 0)
        return OUT_NOT_RANGE;
    else if(pos > Li->Size || pos < 1)
        return OUT_NOT_RANGE;
    else
    {
        Elem *aux = Li->End->Next;
        int cont=1;
        while(cont != pos)
        {
            aux = aux->Next;
            cont++;
        }
        (*Al) = aux->Data;
        return SUCESS;
    }
}

int List_Back_Circular (List *Li, struct Students *Al)
{
    if(Li== NULL)
        return INVALID_NULL_POINTER;
    else if(Li->End == NULL)
        return OUT_NOT_RANGE;
    else
    {
        (*Al) = Li->End->Data;
        return SUCESS;
    }
}

int List_Circular_Get_Pos_ (List *Li, int *pos, int mat)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->End == NULL)
        return OUT_NOT_RANGE;
    else
    {
        Elem *aux = Li->End->Next;
        int cont=1;
        while(aux != Li->End && aux->Data.matricula != mat)
        {
            aux = aux->Next;
            cont++;
        }
        if(aux->Data.matricula == mat)
        {
            (*pos) = cont;
            return SUCESS;
        }
        else
            return ELEM_NOT_FOUND;
    }
}

// consulta dados por matricula ]
int List_Circular_Find_Mat (List *Li, int mat, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->End == NULL)
        return ELEM_NOT_FOUND;
    else
    {
        Elem *aux = Li->End->Next;
        while(aux->Data.matricula != mat && aux != Li->End)
        {
            aux = aux->Next;
        }
        if(aux->Data.matricula == mat)
        {
            (*Al) = aux->Data;
            return SUCESS;
        }
        else
            return ELEM_NOT_FOUND;
    }
} 

// funçoes de tamanho
int Size_List_Circular (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else
        return Li->Size;
}

int Empyt_List_Circular (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Size == 0 && Li->End == NULL)
        return SUCESS;
    else 
        OUT_NOT_RANGE;
}

int List_Circular_Full (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Size == 0)
        return OUT_NOT_RANGE;
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

// impressão
int Print_List_Circular (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->End == NULL && Li->Size == 0)
        return ELEM_NOT_FOUND;
    else
    {
        Elem *aux = Li->End->Next;
        int cont=1;
        while(cont <= Li->Size)
        {
            printf("Matricula: %d\t",aux->Data.matricula);
            printf("Nome: %s\t",aux->Data.name);
            printf("Notas: %.1f %.1f %.1f\n", aux->Data.n1, aux->Data.n2, aux->Data.n3);
            aux = aux->Next;
            cont++;
        }
    }
    return SUCESS;
}