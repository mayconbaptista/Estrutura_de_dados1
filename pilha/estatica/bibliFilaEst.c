// @utor maycon douglas 11921BSI209

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliFilaEst.h"

struct Listas {
    int amount;
    struct Students DICE[MAX];
};
// bom aqui como e uma lista de alunos nos definimos 
// uma estruct lista que tem quantdade e strdestas que tera
// matrivula nome e notas dos alunos;




List* Criate_List ()
{
    List *Lst=NULL;
    Lst= (List*)malloc(sizeof(struct Listas));

    if(Lst!=NULL)
        Lst->amount=0;

    return Lst;
}


// libeira lista;
void Release_List (List *Lst)
{
    free(Lst);
}

// insere no final da minha lista;
int Insert_List_Final (List *Lst,struct Students Std)
{
    if(Lst == NULL)
        return INVALID_NULL_POINTER; // -1 cod interno para erro!!
    else if(Lst->amount == MAX)
        return OUT_NOT_RANGE; // -1 cod interno para Erro!!
    
    Lst->DICE[Lst->amount]= Std;
    Lst->amount++;

    return SUCESS;
}

// insere no começo da lista;
int Inserts_List_Start (List *Lst,struct Students Std)
{
    if(Lst->amount == MAX)
        return INVALID_NULL_POINTER;
    if(Lst == NULL)
        return OUT_NOT_RANGE;

    for(int pos=Lst->amount; pos>=0; pos--){
        Lst->DICE[pos+1]=Lst->DICE[pos];
    }

    Lst->DICE[0]= Std;
    Lst->amount++;
    return SUCESS;
}

// consulta os dados na pos
int Query_List_pos (List *Lst, int pos,struct Students *Std)
{
    if(pos < 0 || pos > MAX || pos > Lst->amount)
        return OUT_NOT_RANGE;
    *Std= Lst->DICE[pos-1];
    return SUCESS;
}

// função extra para o exercicio de pilha
int List_back (List *Lst, struct Students *Al)
{
    if(Lst == NULL)
        return INVALID_NULL_POINTER;
    else if(Lst->amount == 0)
        return OUT_NOT_RANGE;
    else
    {
        (*Al) = Lst->DICE[Lst->amount-1];
        return SUCESS;
    }
}

// consultda os dados buscando por numero de matricula.
int Query_List_mat (List *Lst,int mat,struct Students *Std)
{
    if(Lst == NULL)
        return INVALID_NULL_POINTER;
    
    int i=0;
    while(i<Lst->amount && Lst->DICE[i].matricula != mat)
        i++;
    
    if(i == Lst->amount)
        return OUT_NOT_RANGE;
    *Std= Lst->DICE[i];
    return SUCESS;
}

// Insere um elemento ordenadamente;
int Inserts_List_Ordered (List *Lst,struct Students Std)
{
    if(Lst == NULL)
        return INVALID_NULL_POINTER;
    else if(Lst->amount == MAX)
        return OUT_NOT_RANGE;
    
    int k, i=0;
    while(i<Lst->amount && Lst->DICE[i].matricula < Std.matricula)
        i++;
    
    for(k=Lst->amount-1; k>=i; k--)
        Lst->DICE[k+1]= Lst->DICE[k];
    
    Lst->DICE[i]= Std;
    Lst->amount++;

    return SUCESS;
}

// remove um elemento da lista pelo numero de matricula;
int Remove_List (List *Lst, int mat)
{
    if(Lst == NULL)
        return INVALID_NULL_POINTER;
    int i;
    for(i=0; i<Lst->amount; i++){
        if(Lst->DICE[i].matricula == mat)
            break;
    }

    if(i== Lst->amount)
        return OUT_NOT_RANGE; // não encontrado;
    else
        for(; i<Lst->amount; i++){
            Lst->DICE[i]=Lst->DICE[i+1];
        }
    Lst->amount--;
    return SUCESS; // deu certo.
}


// remove o ultimo elemento da lista;
int Remove_List_Final (List *Lst)
{
    if(Lst == NULL)
        return -1;
    else if(Lst->amount == 0)
        return 0;
    Lst->amount--;

    return SUCESS;
}

// remove o primeiro elemento da lista
int Remove_List_Start (List *Lst)
{
    if(Lst == NULL)
        return INVALID_NULL_POINTER;
    else if(Lst->amount == 0)
        return OUT_NOT_RANGE;

    for(int k=0; k<Lst->amount; k++)
        Lst->DICE[k]= Lst->DICE[k+1];
    
    Lst->amount--;
    return SUCESS;
}

// tamanho lista.
int Size_List (List *Lst)
{
    if(Lst == NULL)
        return INVALID_NULL_POINTER;
    else
        return Lst->amount;
}


// função verifica se a lista esta cheia;
int Size_Full (List *Lst)
{
    if(Lst == NULL)
        return INVALID_NULL_POINTER;
    else if(Lst->amount == MAX)
        return SUCESS; // 1= True;
    else   
        return OUT_NOT_RANGE; // 0= False;
}

// Função verifica se a lista esta vazia;
int Size_Empty (List *Lst)
{
    if(Lst == NULL)
        return INVALID_NULL_POINTER;
    else if(Lst->amount == 0)
        return SUCESS; // 1= True;
    else 
        return OUT_NOT_RANGE; // 0= False;
}


// imprime a minha lista;
int Print_List (List *Lst)
{
    if(Lst == NULL)
        return INVALID_NULL_POINTER;
    else if(Lst->amount == 0)
    {
        printf("Lista ainta esta vazia!!\n");
        return OUT_NOT_RANGE;
    }
    else{
        for(int i=0; i<Lst->amount; i++){
            printf("Matricula: %d\t",Lst->DICE[i].matricula);
            printf("Nome: %s\t",Lst->DICE[i].nome);
            printf("Notas: %.1f %.1f %.1f\n",Lst->DICE[i].n1, Lst->DICE[i].n2, Lst->DICE[i].n3);
        }
    }
    printf("====================================================\n");
    return SUCESS;
}


// Remove lista otimizada;
int Remove_List_Optimized (List *Lst, int mat)
{
    if(Lst == NULL)
        return -1;
    else if(Lst->amount == 0)
        return -1;
    int i=0;
    while(i<Lst->amount && Lst->DICE[i].matricula != mat)
        i++;
    if(i == Lst->amount)
        return 0;
    Lst->amount--;
    Lst->DICE[i] = Lst->DICE[Lst->amount];
    return 1;
}

// funçoes extras;

void Print_Strudets_Pos (struct Students *Std)
{
    printf("Matricula : %d\t",Std->matricula);
    printf("Nome: %s\t",Std->nome);
    printf("Notas: %.1f\t%.1f\t%.1f\n",Std->n1,Std->n2,Std->n3);
    printf("====================================================\n");
}
