#ifndef LISTAENCCIR_H
#define LISTAENCCIR_H

#define SUCESS 0
#define INVALID_NULL_POINTER -1
#define ELEM_NOT_FOUND -2
#define OUT_NOT_MEMORY -3
#define OUT_NOT_RANGE -4

struct Students
{
    char name[30];
    int matricula;
    float n1, n2, n3;
};

typedef struct Lista List;

// Cria Ponteiro para lista
List* Criate_Lista_Circular (void);

// Libera a lista;
void Free_List_Circular (List *Li);

// Inserção

// insere no inicio
int Push_Front_List_Circular (List *Li, struct Students Al);

// insere no final
int Push_Back_List_Circular (List *Li, struct Students Al);

// insere na pos indicada
int Insert_List_Circular_Ordered_Pos (List *Li, struct Students Al, int pos);

// orrenado pela matricula
int Insert_List_Circular_Ordered_Mat (List *Li, struct Students Al);

// funçoes de remoção

// Remove o ultimo
int List_Circular_Pop_Front (List *Li);

// remove o primeiro
int List_Circular_Pop_Back (List *Li);

// remove insicado pela posição
int List_Circular_Erase_Pos (List *Li, int pos);

// indicado pela matricula
int List_Circular_Erase_mat (List *Li, int mat);

// consulta

// pela posição
int List_Circular_Find_pos (List *Li,int pos, struct Students *Al);

// retolna o ultimo
int List_Back_Circular (List *Li, struct Students *Al);

// consulta posição pela matricula
int List_Circular_Get_Pos_ (List *Li, int *pos, int mat);

// consulta indicado pela matricula
int List_Circular_Find_Mat (List *Li, int mat, struct Students *Al);

// tamanho

// tamanho da lista
int Size_List_Circular (List *Li);

// vazia?
int Empyt_List_Circular (List *Li);

// cheia?
int List_Circular_Full (List *Li);

// imprime
int Print_List_Circular (List *Li);

#endif