#define SUCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define ELEM_NOT_FOUND -3
#define OUT_NOT_RANGE -4

struct Students{
    int matricula;
    char name[30];
    float n1, n2, n3;
};
typedef struct TDList List;

//
int Verifica (List *Li);

// cria lista duplamentes encadeada
List* TDList_criate (void);

//
void TDList_Free (List *Li);

// incerção
// 1
int TDList_Push_Front (List *Li, struct Students Al);

// 2
int TDList_Push_Back (List *Li, struct Students Al);

// 3
int TDList_Insert (List *Li, int pos, struct Students Al);

// 4
int TDList_Insert_Sorted (List *Li, struct Students Al);

// busca
// 5
int TDList_Find_Pos (List *Li, int pos, struct Students *Al);

// 6
int TDList_Find_Mat (List *Li, int mat, struct Students *Al);

// 7
int TDList_Get_Pos (List *Li, int mat, int *pos);

// 8
int TDList_Front (List *Li, struct Students *Al);

// 9
int TDList_Back (List *Li, struct Students *Al);

// remoção
// 10
int TDList_Pop_Front (List *Li);

// 11
int TDList_Pop_Back (List *Li);

// 12
int TDList_Erase_Mat (List *Li, int mat);

// 13
int TDList_Erase_Pos (List *Li, int pos);

// tamanho
// 14
int TDEmpyt_List(List *Li);

// 15
int TDFull_List (List *Li);

// 16
int TDSize_List (List *Li);

// 17
int TDPrint_List (List *Li);
