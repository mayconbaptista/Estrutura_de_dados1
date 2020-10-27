#include <stdio.h>
#include <stdlib.h>
#include "tdlinked-list.h"

struct LIST_NODE
{
    struct Students Data;
    struct LIST_NODE *prev;
    struct LIST_NODE *next;
    int Size;
};
typedef struct LIST_NODE DLnode;

struct TDList
{
    struct LIST_NODE *Bigin;
    struct LIST_NODE *End;
    int Size;
};

int Verifica (List *Li)
{
    if(Li != NULL && Li->Bigin != NULL)
    {
        DLnode *aux;
        aux = Li->Bigin;
        int cont=1;
        while(aux->next != NULL)
        {
            aux = aux->next;
            cont++;
        }
        if(aux == Li->End && cont == Li->Size)
        {
            while(aux->prev != NULL)
            {
                aux = aux->prev;
            }
            if(aux == Li->Bigin)
                return SUCESS;
        }

    }
    return ELEM_NOT_FOUND;
}

List* TDList_criate (void)
{    
    List *Li;
    Li = (List*) malloc (sizeof(List));
    if(Li != NULL)
    {
        Li->Bigin = NULL;
        Li->End = NULL;
        Li->Size = 0;
    }
    return Li;
}

void TDList_Free (List *Li)
{
    if(Li != NULL && Li->Bigin != NULL)
    {
        while(Li->Bigin->next != NULL)
        {
            Li->Bigin = Li->Bigin->next;
            free(Li->Bigin->prev);
        }
        free(Li->End);
    }
}

// funçoes de incerção
// 1)
int TDList_Push_Front (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;

    DLnode *node;
    node = (DLnode*) malloc (sizeof(DLnode));
    if(node == NULL)
        return OUT_OF_MEMORY;
    
    node->Data = Al;
    node->prev = NULL;
    node->next = NULL;
    if(Li->Bigin == NULL)
    {
        Li->Bigin = node;
        Li->End = node;
    }
    else
    {
        Li->Bigin->prev = node;
        node->next = Li->Bigin;
        Li->Bigin = node;
    }
    Li->Size++;
    return SUCESS;
    
}// ok

// 2)
int TDList_Push_Back (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    
    DLnode *node;
    node = (DLnode*) malloc (sizeof(DLnode));
    if(node == NULL)
        return OUT_OF_MEMORY;
    
    node->Data = Al;
    node->prev = NULL;
    node->next = NULL;
    if(Li->End == NULL)
    {
        Li->Bigin = node;
        Li->End = node;
    }
    else
    {
        Li->End->next= node;
        node->prev = Li->End;
        Li->End = node;
    }
    Li->Size++;
    return SUCESS;
}// ?


// 3)
int TDList_Insert (List *Li, int pos, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(pos < 1 || Li->Size+1 < pos)
        return OUT_NOT_RANGE;
    
    DLnode *Node;
    Node = (DLnode*) malloc (sizeof(DLnode));
    if(Node == NULL)
        return OUT_OF_MEMORY;

    Node->Data = Al;
    Node->prev = NULL;
    Node->next = NULL;

    DLnode *prev, *pres;
    pres = Li->Bigin;
    int cont=1;
    while(pres != NULL && cont != pos)
    {
        prev = pres;
        pres = pres->next;
        cont++;
    }
    if(Li->Size == 0)
    {
        Li->Bigin = Node;
        Li->End = Node;
    }
    else if(pos == 1)
    {
        Li->Bigin->prev = Node;
        Node->next = Li->Bigin;
        Li->Bigin = Node;
    }
    else if(pos == Li->Size+1)
    {
        Li->End->next = Node;
        Node->prev = Li->End;
        Li->End = Node;
    }
    else
    {
        prev->next = Node;
        Node->prev = prev;
        Node->next = pres;
        pres->prev = Node;
    }
    Li->Size++;
    return SUCESS;
}// ?

// 4)
int TDList_Insert_Sorted (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    
    DLnode *Node;
    Node = (DLnode*) malloc(sizeof(DLnode));
    if(Node == NULL)
        return OUT_OF_MEMORY;
    
    Node->Data = Al;
    Node->prev = NULL;
    Node->next = NULL;
    if(Li->Bigin == NULL)
    {
        Li->Bigin = Node;
        Li->End = Node;
    }
    else if(Li->Bigin->Data.matricula > Al.matricula)
    {
        Node->next = Li->Bigin;
        Li->Bigin->prev = Node;
        Li->Bigin = Node;
    }
    else
    {
        DLnode *prev, *pres;
        pres = Li->Bigin;
        while(pres != NULL && pres->Data.matricula < Al.matricula)
        {
            prev = pres;
            pres = pres->next;
        }
        if(pres == NULL)// insere no final
        {
            Node->prev = Li->End;
            Li->End->next = Node;
            Li->End = Node;
        }
        else
        {
            prev->next = Node;
            Node->prev = prev;
            Node->next = pres;
            pres->prev = Node;
        }
    }
    Li->Size++;
    return SUCESS;
}// ?

// Funçoes de remoção

int TDList_Pop_Front (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Bigin == NULL)
        return OUT_NOT_RANGE;
    
    DLnode *aux;
    aux = Li->Bigin;
    if(Li->Size == 1)
    {
        Li->Bigin = NULL;
        Li->End = NULL;
    }
    else
    {
        Li->Bigin = aux->next;
        Li->Bigin->prev = NULL;
    }
    Li->Size--;
    free(aux);
    return SUCESS;
}// ??

//
int TDList_Pop_Back (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Size == 0)
        return OUT_NOT_RANGE;
    
    DLnode *aux;
    aux = Li->End;
    if(Li->Size == 1)
    {
        Li->Bigin = NULL;
        Li->End = NULL;
    }
    else
    {
        Li->End = Li->End->prev;
        Li->End->next = NULL;
    }
    Li->Size--;
    free(aux);
    return SUCESS;
}

//
int TDList_Erase_Mat (List *Li, int mat)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Size == 0)
        return ELEM_NOT_FOUND;

    DLnode *aux;
    aux = Li->Bigin;
    while(aux != NULL && aux->Data.matricula != mat)
    {
        aux = aux->next;
    }
    if(aux == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    else if((Li->Bigin->Data.matricula == mat) && (Li->Size == 1))// primeiro e ultimo
    {
        Li->Bigin = NULL;
        Li->End = NULL;
    }
    else if((Li->Bigin->Data.matricula == mat) && (Li->Size > 1))
    {
        Li->Bigin = Li->Bigin->next;
        Li->Bigin->prev = NULL;
    }
    else if(Li->End->Data.matricula == mat)
    {
        Li->End = Li->End->prev;
        Li->End->next = NULL;
    }
    else
    {
        DLnode *prev;
        prev = aux->prev;
        prev->next = aux->next;
    }
    free(aux);
    Li->Size--;
    return SUCESS;
}//?

//
int TDList_Erase_Pos (List *Li, int pos)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Size == 0 || Li->Size < pos || pos < 1)
        return OUT_NOT_RANGE;
    
    DLnode *aux;
    aux = Li->Bigin;
    int cont=1;
    while(aux != NULL && cont != pos)
    {
        aux = aux->next;
        cont++;
    }
    if((pos == 1) && (Li->Size == 1))// primeira e ultima
    {
        Li->Bigin = NULL;
        Li->End = NULL;
    }
    else if((pos == 1) && (Li->Size > 1))// primeira
    {
        Li->Bigin = Li->Bigin->next;
        Li->Bigin->prev = NULL;
    }
    else if(pos == Li->Size) // ultima
    {
        Li->End = Li->End->prev;
        Li->End->next = NULL;
    }
    else
    {
        DLnode *prev, *pres;
        prev = aux->prev;
        pres = aux->next;
        
        prev->next = pres;
        pres->prev = prev;
    }

    Li->Size--;
    free(aux);
    return SUCESS;
}//?



// funçoes de consulta
// 5)
int TDList_Find_Pos (List *Li, int pos, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    
    DLnode *aux;
    aux = Li->Bigin;
    int cont=1;
    while(aux != NULL && cont != pos)
    {
        aux = aux->next;
        cont++;
    }
    if(aux != NULL && cont == pos)
    {
        (*Al) = aux->Data;
        return SUCESS;
    }
    else
        return OUT_NOT_RANGE;
}

// 6)
int TDList_Find_Mat (List *Li, int mat, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    
    DLnode *aux;
    aux = Li->Bigin;
    while(aux != NULL && aux->Data.matricula != mat)
        aux = aux->next;
    
    if(aux != NULL && aux->Data.matricula == mat)
    {
        (*Al) = aux->Data;
        return SUCESS;
    }
    else 
        return ELEM_NOT_FOUND;
}

// 7)
int TDList_Get_Pos (List *Li, int mat, int *pos)
{
    if(Li == NULL)
        return SUCESS;
    
    DLnode *aux;
    aux = Li->Bigin;
    int cont=1;
    while(aux != NULL && aux->Data.matricula != mat)
    {
        aux = aux->next;
        cont++;
    }
    if(aux != NULL)
    {
        (*pos) = cont;
        return SUCESS;
    }
    else 
        return ELEM_NOT_FOUND;
}

// 8)
int TDList_Front (List *Li, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Size == 0)
        return ELEM_NOT_FOUND;
    else
    {
        (*Al) = Li->Bigin->Data;
        return SUCESS;
    }
}

// 9)
int TDList_Back (List *Li, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Size == 0)
        return ELEM_NOT_FOUND;
    else
    {
        (*Al) = Li->End->Data;
        return SUCESS;
    }
}

// funçoes relacionadas ao tamanho
// lista vazia
int TDEmpyt_List (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Size != 0)
        return OUT_NOT_RANGE;
    else 
        return SUCESS;
}

//
int TDFull_List (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Size == 0)
        return OUT_NOT_RANGE;
    
    DLnode *test;
    test = (DLnode*) malloc (sizeof(DLnode));
    if(test == NULL)// mamoria indisponivel;
        return SUCESS;
    else
    {
        free(test);
        return OUT_NOT_RANGE;
    }   
}

//
int TDSize_List (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else 
        return Li->Size;
}

//
int TDPrint_List (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Bigin == NULL)
        return ELEM_NOT_FOUND;
    else
    {
        DLnode *aux;
        aux= Li->Bigin;
        int pos=1;
        while(aux != NULL)
        {
            printf("pos: %d\t",pos);
            printf("Matricula: %d\t",aux->Data.matricula);
            printf("Nome: %s\t",aux->Data.name);
            printf("Notas: %.1f %.1f %.1f\n",aux->Data.n1, aux->Data.n2, aux->Data.n3);
            pos++;
            aux = aux->next;
        }
        return SUCESS;
    }
}