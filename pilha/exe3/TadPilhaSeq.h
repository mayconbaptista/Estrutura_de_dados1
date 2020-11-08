#define SUCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define ELEM_NOT_FOUND -3
#define INVALID_OPERATION -4

typedef struct Pilha_char Stack_char;

Stack_char* Criate_Stack_char (int tam);

void Free_Stack_Char (Stack_char *Pi);

int Push_Stack_Char (Stack_char *Pi, char c);

int pop_Stack_Char (Stack_char *Pi);

int Stack_Top_Char (Stack_char *Pi, char *c);

int Size_Stack_Char (Stack_char *Pi);

int Full_Stack_Char (Stack_char *Pi);

int Empyt_Stack_Char (Stack_char *Pi);

void Print_Stack_Char (Stack_char *Pi);
