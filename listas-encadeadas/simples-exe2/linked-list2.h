#define SUCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_NOT_RANGE -3
#define ELEM_NOT_FOUND -4
#define INVALID_OPERATION -5


struct Students{
    int enrollment;
    char name [30];
    float n1, n2, n3;
};

typedef struct Lists List;

// cria lista
List* List_Criate2 (void);

// libera os nos da lista
void List_Free2 (List *Li);

//-1) insere no inicio
int List_Push_Front2 (List *Li, struct Students Al);

//-2) insere no final
int List_Push_Back2 (List *Li, struct Students Al);

//-3) insere na posição sezejada
int List_Insert2 (List *Li, int pos, struct Students Al);

//-4) insere ordenado
int List_Insert_Sorted2 (List *Li, struct Students Al);

//                  funçoes de busca:
// busca por posição
int List_Find_Pos2 (List *Li, int pos, struct Students *Al);

// busca por numero de matricula
int List_Find_mat2 (List *Li, int mat, struct Students *Al);
 
// busca a posiçãp pela matricula
int List_Get_Pos2 (List *Li, int mat, int *pos);

// busca o primeiro
int List_Front2(List *Li, struct Students *Al);

// busca o ultimo elemento
int List_Back2 (List *Li, struct Students *Al);

//                  funcoes de remoção
// remove inicio
int List_pop_Front2 (List *Li);

// remove final
int List_pop_Back2 (List *Li);

// remove na posição indicada
int List_Erase_Pos2 (List *Li, int pos);

// remove pelo numero de matricula
int List_Erase_Mat2 (List *Li, int mat);

//                  funçoes de tamanho
// lista vazia
int Empyt_List2 (List *Li);

// lista cheia
int Full_List2 (List *Li);

// tamanho lista
int Size_List2 (List *Li);

//                          extras
// imprime lista
int Print_List2 (List *Li);

// verifica se a lista criada sera ordenada ou não
int Sorted_s_n (List *Li, char opc);
