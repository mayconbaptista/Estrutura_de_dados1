#include "../encadeada/Students.h"

typedef struct Listas Stack;

Stack* Criat_Stak (void);

void Free_Stak (Stack *Pi);

// 1)
int Push_Stak (Stack *Pi, struct Students Al);

// 2)
int Pop_Stack (Stack *Pi);

// 3)
int Top_Stack (Stack *Pi, struct Students *Al);

// 4)
int Size_Stak (Stack *Pi);

// 5)
int Empyt_stack (Stack *Pi);

// 6
int Full_Stack (Stack *Pi);

// 7)
int Print_Stack (Stack *Pi);

