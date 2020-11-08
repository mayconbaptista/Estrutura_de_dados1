#ifndef PilhaEstint_h

#define SUCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define ELEM_NOT_FOUND -3
#define INVALID_OPERATION -4

typedef struct Pilha_int Stack_int;

Stack_int* criat_stack_int (int tam);

void free_stack_Int (Stack_int *Pi);

int push_stack_int (Stack_int *Pi, float val);

int pop_stack_int (Stack_int *Pi);

int stack_top_int (Stack_int *Pi, float *val);

int size_stack_int (Stack_int *Pi);

int empyt_stack_int (Stack_int *Pi);

int full_stack_int (Stack_int *Pi);

void print_stack_int (Stack_int *Pi);

#endif