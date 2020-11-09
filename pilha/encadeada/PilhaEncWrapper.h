#ifndef PilhaEncWrapper_h
#define PilhaEncWrapper_h
#include "Students.h"

# define SUCESS 0
# define INVALID_NULL_POINTER -1
# define OUT_OF_MEMORY -2
# define OUT_NOT_RANGE -3
# define ELEM_NOT_FOUND -4



typedef struct Pilha Stack;

Stack* Criat_Stack_enc (void);

void Free_Stack_enc (Stack *Pi);

int Push_Stack_enc (Stack *Pi, struct Students Al);

int Pop_Stack_enc (Stack *Pi);

int Stack_Top_enc (Stack *Pi, struct Students *Al);

int Size_Stack_enc (Stack *Pi);

void Print_Stack_enc (Stack *Pi);

int Empyt_Stack_enc (Stack *Pi);

#endif