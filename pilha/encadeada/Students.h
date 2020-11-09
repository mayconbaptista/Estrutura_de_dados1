#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

# define SUCESS 0
# define INVALID_NULL_POINTER -1
# define OUT_OF_MEMORY -2
# define OUT_NOT_RANGE -3
# define ELEM_NOT_FOUND -4

struct Students
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

#endif // ALUNO_H_INCLUDED