#ifndef list_h
#define MAX 100
#define SUCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_NOT_RANGE -2
#include "../encadeada/Students.h"
// onde ele achar a variavel max ele troca poelo valor 100;


//define uma struct do tipo students ja que e uma lista de struct;

typedef struct Listas List;
// define um struct lista que sera minha lista;

List* Criate_List ();
// função cria lista para criar uma lista de struct;

void Release_List (List *Lst);
// libera lista libeira a memoria alocada;


int Query_List_pos (List *Lst, int pos,struct Students *Std);
// consulta lista


int Query_List_mat (List *Lst,int mat,struct Students *Std);
//

int Insert_List_Final (List *Lst, struct Students Std);
//

int Inserts_List_Start (List *Lst,struct Students Std);
//

int Inserts_List_Ordered (List *Lst,struct Students Std);
//

int Remove_List (List *Lst, int mat);
//

int Remove_List_Final (List *Lst);
//

int Remove_List_Start (List *Lst);
//

int Size_List (List *Lst);
//

int Size_Full (List *Lst);
//

int Size_Empty (List *Lst);
//

int Print_List (List *Lst);
//

int Remove_List_Optimized (List *Lst, int mat);
//

// funçoes estras pra menu:
void Print_Strudets_Pos (struct Students *Std);

// função extra para pilha
int List_back (List *Lst, struct Students *Al);
#endif


