#ifndef TADFILAVARIA_H
#define TADFILAVARIA_H
#include "../../aluno.h"

typedef struct Fila Queue;

void Print_Queue_Variant (Queue *Fi);

int Queue_Variant_Full (Queue *Fi);

int Dequeue_Variant (Queue *Fi);

int Empty_Queue_Variant (Queue *Fi);

int Size_Queue_Variant (Queue *Fi);

int Queue_Variant_Back (Queue *Fi, struct Students *Al);

int First_Queue_Variant (Queue *Fi, struct Students *Al);

int Enqueue_Variant (Queue *Fi, struct Students Al);

void Free_Queue_Variant (Queue *Fi);

Queue* Criate_Queue_Variant (int tam);

int Compact_Queue_Variant (Queue *Fi);

Queue* Realloc_Queue_Variant (Queue *Fi);


#endif