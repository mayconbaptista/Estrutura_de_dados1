#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../exe3/TadPilhaSeq.h" // pilha estatica de char
#include "PilhaEstint.h" // pilha estatica de int
#include "../exe5/Posf.h"

int Result (char *Posf);

int main (void)
{
    printf("Entre com o tamanho da expressão: ");
    int tam;
    scanf("%d",&tam);

    char *infix;
    infix = (char*) malloc (tam*sizeof(char));
    
    printf("Entre com a expressão: ");
    setbuf(stdin, NULL);
    fgets(infix, 30, stdin);

    infix = Posfix(infix);
    Result(infix);
    return 0;
}

int Result (char *Posf)
{
    float temp=0, temp2=0;
    int tam = strlen(Posf);

    Stack_int *Pilha;
    Pilha = criat_stack_int(tam);
    if(Pilha == NULL)
        return INVALID_NULL_POINTER;
    printf("posfix : %s.\n",Posf);
    
    for(int i=0; i < strlen(Posf); i++)
    {
        switch (Posf[i])
        {
        case '+':
            stack_top_int(Pilha, &temp);
            pop_stack_int(Pilha);

            stack_top_int(Pilha, &temp2);
            pop_stack_int(Pilha);

            temp2  = temp2 + temp;
            push_stack_int(Pilha, temp2);
            break;

        case '-':
            stack_top_int(Pilha, &temp);
            pop_stack_int(Pilha);

            stack_top_int(Pilha, &temp2);
            pop_stack_int(Pilha);

            temp2  = temp2 + temp;
            push_stack_int(Pilha, temp2);
            break;

        case '/':
            stack_top_int(Pilha, &temp);
            pop_stack_int(Pilha);

            stack_top_int(Pilha, &temp2);
            pop_stack_int(Pilha);

            temp2  = temp2 / temp;
            push_stack_int(Pilha, temp2);
            break;

        case '*':
            stack_top_int(Pilha, &temp);
            pop_stack_int(Pilha);

            stack_top_int(Pilha, &temp2);
            pop_stack_int(Pilha);

            temp2  = temp2 * temp;
            push_stack_int(Pilha, temp2);
            break;

        default:
            temp = (int)Posf[i] - 48;
            push_stack_int(Pilha, temp);
            break;
        }
    }
    stack_top_int(Pilha, &temp);
    printf("Resultado: %.1f\n",temp);
    free_stack_Int(Pilha);
    free(Posf);
    return 0;
}