#ifndef exe2_h
# define SUCESS 0
# define INVALID_NULL_POINTER -1
# define OUT_OF_MEMORY -2
# define OUT_NOT_RANGE -3
# define ELEM_NOT_FOUND -4
#include "Students.h"

typedef struct Lists List;

// libera lista;
void List_Free (List *Li);

// cria lista;
List* List_Criate (void);

// insere lista inicio;
int List_Push_Front (List *Li, struct Students Al);

// insere lista final ordenado pela matricula;
int List_Push_Back (List *Li, struct Students Al);

// insere ordenado pela posição
int List_Insert (List *Li, int pos, struct Students Al);

// insere 
int List_Insert_Sorted (List *Li, struct Students Al);

//imprime lista
void List_Print (List *Li);

// busca por posição;
int List_Find_Pos (List *Li, int pos, struct Students *Al);

// busca por numero de matricula;
int List_Find_Mat (List *Li, int mat, struct Students *Al);

// Retorn o primeiro
int List_Front (List *Li, struct Students *Al);

// retorna o ultimo
int List_Back (List *Li, struct Students *Al);

// consulta lista por posição;
int List_Find_Pos (List *Li, int pos, struct Students *Al);

// remove inicio
int List_pop_Front (List *Li);

// remove final
int List_pop_Back (List *Li);

// remove elemento por numero de matricula;
int List_Erase_Mat (List *Li,int mat);

// remove pela posição indicada
int List_Erase_Pos (List *Li, int pos);

// consulta a posição pela matricula
int List_get_Pos (List *Li, int mat, int *pos);

//  lista vazia
int Empty_List (List *Li);

// lista cheia
int Full_List (List *Li);

// tamanho da lista
int Size_List (List *Li);

// imprime
int Print_List (List *Li);

#endif