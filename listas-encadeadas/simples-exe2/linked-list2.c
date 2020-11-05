#include <stdio.h>
#include <stdlib.h>
#include "linked-list2.h"
#define SORTED 1
#define NOT_SORTED 0


struct list_node{
    struct Students date;
    struct list_node *next;
};
typedef struct list_node List_Node;

struct Lists{
    struct list_node *Head;
    int size;
    int sorted;
};


int Sorted_s_n (List *Li, char opc)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if( opc == 's')
        Li->sorted = SORTED;
    else if(opc == 'n')
        Li->sorted = NOT_SORTED;
    return SUCESS;
}

// funções de criação e destruição da lista;
List* List_Criate2 (void)
{
    List *Li;
    Li = (List*) malloc (sizeof(List));
    if(Li != NULL){
        Li->Head = NULL;
        Li->size = 0;
        Li->sorted = NOT_SORTED;
    }
    return Li;
}

void List_Free2 (List *Li)
{
    if(Li != NULL){
        List_Node *aux;
        aux = Li->Head;
        while(Li->Head != NULL){
            aux = Li->Head;
            Li->Head = Li->Head->next;
            free(aux);
        }
        free(Li);
    }
    return;
}

// funçoes de incerção;
// 1)
int List_Push_Front2 (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->sorted == SORTED)
        return INVALID_OPERATION;

    
    List_Node *Node;
    Node = (List_Node*) malloc (sizeof(List_Node));
    if(Node == NULL)
        return OUT_OF_MEMORY;
    
    Node->date = Al;
    Node->next = NULL;

    Node->next = Li->Head;
    Li->Head = Node;
    Li->size++;
    return SUCESS;
}// ok


// 2)
int List_Push_Back2 (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->sorted == SORTED)
        return INVALID_OPERATION;
    
    List_Node *Node;
    Node = (List_Node*) malloc (sizeof(List_Node));
    if(Node == NULL)
        return OUT_OF_MEMORY;

    Node->date = Al;
    Node->next = NULL;

    if(Li->Head == NULL)
    {
        Li->Head = Node;
        Li->size++;
        return SUCESS;
    }

    List_Node *aux;
    aux = Li->Head;
    while(aux->next != NULL)
        aux = aux->next;
    
    aux->next = Node;
    Li->size++;
    return SUCESS;
}// ok

// 3)
int List_Insert2 (List *Li, int pos, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->sorted == SORTED)
        return INVALID_OPERATION;

    List_Node *Node;
    Node = (List_Node*) malloc (sizeof(List_Node));
    if(Node == NULL)
        return OUT_OF_MEMORY;
    
    Node->date = Al;
    Node->next = NULL;

    if(pos == 1)// se for a primeira possição
    {
        Node->next = Li->Head;
        Li->Head = Node;
        Li->size++;
        return SUCESS;
    }

    List_Node *prev, *pres;
    pres = Li->Head;
    int cont=1;
    while(pres != NULL && cont != pos)
    {
        prev = pres;
        pres = pres->next;
        cont++;
    }
    if(cont == pos)
    {
        prev->next = Node;
        Node->next = pres;
        Li->size++;
        return SUCESS;
    }else 
        return OUT_NOT_RANGE;
}// ??

// 4)
int List_Insert_Sorted2 (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->sorted == NOT_SORTED)
        return INVALID_OPERATION;

    List_Node *node;
    node = (List_Node*) malloc (sizeof(List_Node));
    if(node == NULL)
        return OUT_OF_MEMORY;

    node->date = Al;
    node->next = NULL;
    if(Li->Head == NULL || Li->Head->date.enrollment > Al.enrollment)
    {
        node->next = Li->Head;
        Li->Head = node;
        Li->size++;
        return SUCESS;
    }

    List_Node *prev, *pres;
    pres = Li->Head;
    while(pres != NULL && pres->date.enrollment < Al.enrollment)
    {
        prev = pres;
        pres = pres->next;
    }

    prev->next = node;
    node->next = pres;
    Li->size++;
    return SUCESS;
}// ok.

//Funçoes relacionadas a busca
// 5)
int List_Find_Pos2 (List *Li, int pos, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;  

    List_Node *aux;
    aux = Li->Head;
    int cont=1;
    while(aux != NULL && cont != pos)
    {
        aux = aux->next;
        cont++;
    }
    if(cont == pos && aux != NULL)
    {
        (*Al) = aux->date;
        return SUCESS;
    }
    else 
        return OUT_NOT_RANGE;
}// ok


// 6)
int List_Find_mat2 (List *Li, int mat, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    
    List_Node *aux;
    aux = Li->Head;
    while(aux != NULL && aux->date.enrollment != mat)
        aux = aux->next;

    if(aux != NULL)
    {
        (*Al) = aux->date;
        return SUCESS;
    }
    else
        return ELEM_NOT_FOUND;
}// ok


// 7)
int List_Get_Pos2 (List *Li, int mat, int *pos)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;

    List_Node *aux;
    aux = Li->Head;
    int cont=1;
    while(aux != NULL && aux->date.enrollment != mat)
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
}// ok

// 8) 
int List_Front2 (List *Li, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->size == 0)
        return ELEM_NOT_FOUND;
    else
    {
        (*Al) = Li->Head->date;
        return SUCESS;
    }
}// ?

// 9)
int List_Back2 (List *Li, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->size == 0)
        return ELEM_NOT_FOUND;
    else
    {
        List_Node *aux;
        aux = Li->Head;
        while(aux->next != NULL)
            aux = aux->next;
        (*Al)= aux->date;
        return SUCESS;
    }
}//? 


// Funçoes relacionadas e remoção;
// 10)
int List_pop_Front2 (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return OUT_NOT_RANGE;

    List_Node *aux;
    aux = Li->Head;
    Li->Head = aux->next;
    Li->size--;
    free(aux);
    return SUCESS;
}// ok

// 11)
int List_pop_Back2 (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return OUT_NOT_RANGE;

    List_Node *prev, *pres;
    pres = Li->Head;
    while(pres->next != NULL)
    {
        prev = pres;
        pres = pres->next;
    }
    if(Li->Head->next == NULL)
    {
        Li->Head = NULL;
    }
    else
    {
        prev->next = NULL;
    }
    free(pres);
    Li->size--;
    return SUCESS;
}// ok


// 12)
int List_Erase_Pos2 (List *Li, int pos)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(pos > Li->size || pos < 1)
        return OUT_NOT_RANGE;

    List_Node *prev, *pres;
    pres = Li->Head;
    int cont=1;
    while(pres != NULL && cont != pos)
    {
        prev = pres;
        pres = pres->next;
        cont++;
    }
    if(pos == 1) // primeira
    {
        Li->Head = Li->Head->next;
    }
    else
    {
        prev->next = pres->next;
    }
    free(pres);
    Li->size--;
    return SUCESS;
}//  ok


// 13)
int List_Erase_Mat2 (List *Li, int mat)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->size == 0)
        return ELEM_NOT_FOUND;

    List_Node *prev, *pres;
    pres = Li->Head;
    if(Li->Head->date.enrollment == mat) // se for o primeiro
    {
        Li->Head = Li->Head->next;
        free(pres);
        Li->size--;
        return SUCESS;
    }

    while(pres->next != NULL)
    {
        prev = pres;
        pres = pres->next;

        if(pres->date.enrollment == mat)
        {
            prev->next = pres->next;
            free(pres);
            Li->size--;
            return SUCESS;
        }
    }
    return ELEM_NOT_FOUND;
} // ok

// Funçoes relacionadas ao tamanho
// 14) lista vazia
int Empyt_List2 (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->size == 0)
        return SUCESS; // true
    else
        return OUT_NOT_RANGE; // false;
}

// 15) lista cheia
int Full_List2 (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->size == 0)
        return OUT_NOT_RANGE; // falso;
    
    List_Node *Node;
    Node = (List_Node*) malloc (sizeof(List_Node));
    if(Node == NULL) // se nao tem mais memoria ela esta cheia.
        return SUCESS;
    else{
        free(Node);
        return OUT_NOT_RANGE; // falso;
    }
}

// 16) tamanho lista
int Size_List2 (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else 
        return Li->size;
}

// funçoes de impreção e verifica se esta ordenada
// 17)
int Print_List2 (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li == NULL)
        return OUT_NOT_RANGE;
    else
    {
        List_Node *aux;
        aux = Li->Head;
        while(aux != NULL)
        {
            printf("Matricula: %d\t",aux->date.enrollment);
            printf("Nome: %s\t",aux->date.name);
            printf("Notas: %.1f %.1f %.1f\n",aux->date.n1, aux->date.n2, aux->date.n3);
            aux = aux->next;
        }
    }
    return SUCESS;
}
