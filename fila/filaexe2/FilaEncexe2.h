#ifndef FilaEncexe2_h
#define FilaEncExe2_h
#include "../../aluno.h"

typedef struct Fila Queue;


Queue* Criate_Queue_Enc (void);

void Free_Queue_Enc (Queue *Fi);

int Enqueue_Enc (Queue *Fi, struct Students Al);

int Dequeue_Enc (Queue *Fi);

int First_Queue_Enc (Queue *Fi, struct Students *Al);

int Queue_Back_Enc (Queue *Fi, struct Students *Al);

int Size_Queue_Enc (Queue *Fi);

int Empyt_Queue_Enc (Queue *Fi);

int Full_Queue_Enc (Queue *Fi);

void Print_Queue_Enc (Queue *Fi);

#endif