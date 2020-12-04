#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"


struct Element{
    struct Students data;
    struct Element *next;
};
typedef struct Element Elem;

struct Lists {
    struct Element *Head;
};

// criação e liberação ++++++++++++++++++++++++++++++++++++++++++++++++++++
// cria lista
List* List_Criate (void)
{
    List *Li;
    Li = (List*) malloc (sizeof(List));

    if(Li != NULL)
        Li->Head = NULL;
    return Li;
}//ok


// 16 libera lista
void List_Free (List *Li)
{
    if(Li != NULL){
        Elem *pre, *aux;
        aux = Li->Head;
        while(aux != NULL){
            pre = aux;
            aux = aux->next;
            free(pre);
        }
        free(Li);
    }
}//ok


// funçoes de incerção +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 1 insere no inicio da lista
int List_Push_Front (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER; 
    
    Elem *Node;
    Node = (Elem*) malloc (sizeof(Elem));
    if(Node == NULL)
        return OUT_NOT_MEMORY;
    Node->data = Al;
    Node->next = NULL;

    Node->next = Li->Head;
    Li->Head = Node;
    return SUCESS;
}//ok

// 2 insere lista final
int List_Push_Back (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    
    Elem *Node;
    Node = (Elem*) malloc (sizeof(Elem));

    if(Node == NULL)
        return OUT_NOT_MEMORY;

    Node->data = Al;
    Node->next = NULL;

    if(Li->Head == NULL){ // lista vazia ele vira o primeiro
        Li->Head = Node;
        return SUCESS;
    }

    Elem *aux;
    aux = Li->Head;
    while(aux->next != NULL)
        aux = aux->next;

    aux->next = Node;
    return SUCESS;
}//ok

// 3) insere ordenado por posição
int List_Insert (List *Li, int pos, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;


    Elem *Node;
    Node = (Elem*) malloc (sizeof(Elem));
    if(Node == NULL)
        return OUT_NOT_MEMORY;
    
    Node->data = Al;
    Node->next = NULL;

    if(pos == 1){
        Node->next = Li->Head;
        Li->Head = Node;
        return SUCESS;
    }

    Elem *prev, *aux;
    aux = Li->Head;
    int cont=1;
    while(aux != NULL){
        prev = aux;
        aux = aux->next;
        cont++;
        if(cont == pos){
            prev->next = Node;
            Node->next = aux;
            return SUCESS;
        }
    }
    return OUT_NOT_RANGE;
}// ok

// 4 iserir em uma lista orndenado por numero de mat
int List_Insert_Sorted (List *Li, struct Students Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    
    Elem *Node;
    Node = (Elem*) malloc (sizeof(Elem));
    if(Node == NULL)
        return OUT_NOT_MEMORY;

    Node->data = Al;
    Node->next = NULL;

    if(Li->Head == NULL || Li->Head->data.matricula > Al.matricula)
    {
        Node->next = Li->Head;
        Li->Head = Node;
        return SUCESS;
    }
    else
    {
        Elem *prev, *pres;
        prev = Li->Head;
        pres = Li->Head;
        while(pres != NULL && pres->data.matricula < Al.matricula)
        {
            prev = pres;
            pres = pres->next;
        }
        Node->next = pres;
        prev->next = Node;
        return SUCESS;
    }
}// ok


// funçoes de consulta ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 5 busca por posiçao
int List_Find_Pos (List *Li, int pos, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return OUT_NOT_RANGE;

    Elem *aux;
    aux = Li->Head;
    int cont=1;
    while(aux != NULL){
        if(pos == cont){
            (*Al) = aux->data;
            return SUCESS;
        }
        aux = aux->next;
        cont++;
    }
    return OUT_NOT_RANGE;
}// ok

// 6 busca por numero de matricula
int List_Find_Mat (List *Li, int mat, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return ELEM_NOT_FOUND;
    
    Elem *aux;
    aux= Li->Head;
    while(aux != NULL){
        if(aux->data.matricula == mat){
            (*Al) = aux->data;
            return SUCESS;
        }
        aux = aux->next;
    }
    return ELEM_NOT_FOUND;
}

// 7 consulta a possição pela matricula
int List_get_Pos (List *Li, int mat, int *pos)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if (Li->Head == NULL)
        return ELEM_NOT_FOUND;

    Elem *aux;
    aux = Li->Head;
    int cont=0;
    while(aux != NULL){
        cont++;
        if(aux->data.matricula == mat){
            (*pos) = cont;
            return SUCESS;
        }else 
            aux = aux->next;
    }
    return ELEM_NOT_FOUND;
}// ok

// 8) retorna o primeiro elemento
int List_Front (List *Li, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return ELEM_NOT_FOUND;
    else
        (*Al) = Li->Head->data;
    return SUCESS;
}// ?


// 9)
int List_Back (List *Li, struct Students *Al)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return ELEM_NOT_FOUND;
    else
    {
        Elem *aux;
        aux = Li->Head;
        while(aux->next != NULL)
            aux = aux->next;
        
        (*Al) = aux->data;
        return SUCESS;
    }
}

// funçoes de remover ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 10 remove inicio
int List_pop_Front (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return ELEM_NOT_FOUND;
    
    Elem *aux;
    aux= Li->Head;
    if(aux->next != NULL){
        Li->Head = aux->next;
        free(aux);
    }
    else{
        free(aux);
        Li->Head = NULL; // cuidado;
    }
    return SUCESS;
}// ok

// 11 remove final
int List_pop_Back (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return ELEM_NOT_FOUND;

    if(Li->Head->next == NULL){ // primeiro e ultimo;
        free(Li->Head);
        Li->Head = NULL;
        return SUCESS;
    }

    Elem *prev, *pres;
    pres = Li->Head;
    while(pres->next != NULL){
        prev = pres;
        pres = pres->next;
    }

    prev->next = NULL;
    free(pres);
    return SUCESS;
}// ok


// 12 remove elemento indicado pela posição;
int List_Erase_Pos (List *Li, int pos)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if (Li->Head == NULL)
        return OUT_NOT_RANGE;
    
    Elem *prev, *pres;
    pres = Li->Head;
    int cont=1;
    while(pres != NULL && cont != pos)
    {
        prev = pres;
        pres = pres->next;
        cont++;
    }
    if(pres == NULL)
    {
        return OUT_NOT_RANGE;
    }
    else if(pos == 1)
    {
        Li->Head = pres->next;

    }
    else
    {
        prev->next = pres->next;
    }
    free(pres);
    return SUCESS;
}// ?

// 13 remove elemento por numero de matricula;
int List_Erase_Mat (List *Li,int mat)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return ELEM_NOT_FOUND;
    
    Elem *previus, *present;
    present = Li->Head;
    if(present->data.matricula == mat){ // verifica se e o primeiro;
        Li->Head = present->next;
        free(present);
        return SUCESS;
    }

    while(present->next != NULL){
        previus = present;
        present = present->next;
        if(present->data.matricula == mat){
            previus->next = present->next;
            free(present);
            return SUCESS;
        }
    }
    return ELEM_NOT_FOUND;
}// ok

// funçoes ralacionadas ao tamanho +++++++++++++++++++++++++++++++++++++++++++++
// 14 lista vazia
int Empty_List (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return SUCESS;
    else 
        return OUT_NOT_RANGE;
}// ok

// lista cheia
int Full_List (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return OUT_NOT_RANGE; // false

    Elem *Node;
    Node = (Elem*) malloc (sizeof(Elem));
    if(Node == NULL) // não a mais memoria disponivel;
        return SUCESS; 
    else
        return OUT_NOT_RANGE;  
}// ok

// 16 tamanho da lista
int Size_List (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else
    {
        int size=0;
        Elem *aux;
        aux = Li->Head;
        while(aux != NULL){
            aux = aux->next;
            size++;
        }
        return size;
    }
}// ok

// imprime +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 17 imprime
int Print_List (List *Li)
{
    if(Li == NULL)
        return INVALID_NULL_POINTER;
    else if(Li->Head == NULL)
        return OUT_NOT_RANGE;
    
    else
    {
        Elem *aux;
        aux = Li->Head;
        while(aux != NULL)
        {
            printf("Matricula: %d\t",aux->data.matricula);
            printf("Nome: %s\t",aux->data.name);
            printf("Notas: %.1f %.1f %.1f\n", aux->data.n1, aux->data.n2, aux->data.n3);
            aux = aux->next;
        }
        return SUCESS;
    }
}
