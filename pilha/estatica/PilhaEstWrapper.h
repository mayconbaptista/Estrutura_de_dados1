#ifndef PILHAESTWRAPPER_H
#define PILHAESTWRAPPER_H
#include "../encadeada/Students.h"

typedef struct Pilha Stack;

Stack* Criat_Stack_est (void);

void Free_Stack_est (Stack *Pi);

// 1)
int Push_Stack_est (Stack *Pi, struct Students Al);

// 2)
int Pop_Stack_est (Stack *Pi);

// 3)
int Top_Stack_est (Stack *Pi, struct Students *Al);

// 4)
int Size_Stack_est (Stack *Pi);

// 5)
int Empyt_Stack_est (Stack *Pi);

// 6
int Full_Stack_est (Stack *Pi);

// 7)
int Print_Stack_est (Stack *Pi);

#endif