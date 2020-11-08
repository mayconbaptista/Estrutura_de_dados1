#ifndef PilhaEncWrapper_h
# define SUCESS 0
# define INVALID_NULL_POINTER -1
# define OUT_OF_MEMORY -2
# define OUT_NOT_RANGE -3
# define ELEM_NOT_FOUND -4
#include "Students.h"


typedef struct Lists Stak;

Stak* Criat_Stak2 (void);

void Free_Stak2 (Stak *Pi);

int Insert_Stak2 (Stak *Pi, struct Students Al);

int Erase_Stak2 (Stak *Pi);

int Stak_Back2 (Stak *Pi, struct Students *Al);

int Size_Stak2 (Stak *Pi);

void Print_Stak2 (Stak *Pi);

int Empyt_Stack (Stak *Pi);

#endif