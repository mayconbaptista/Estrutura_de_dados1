#ifndef FilaWrapperEnc_h
#define FilaWrapperEnc_h
#include "../../aluno.h"

typedef struct Fila Queue;

Queue* Criate_Queue_Wrapper (void);

void Free_Queue_Wrapper (Queue *Fi);

int Enqueue_Wrapper (Queue *Fi, struct Students Al);

int Dequeue_Wrapper (Queue *Fi);

int First_Queue_Wrapper (Queue *Fi, struct Students *Al);

int Size_Queue_Wrapper (Queue *Fi);

int Full_Queue_Wrapper (Queue *Fi);

int Empyt_Queue_Wrapper (Queue *Fi);

void Print_Queue_Wrapper (Queue *Fi);

#endif