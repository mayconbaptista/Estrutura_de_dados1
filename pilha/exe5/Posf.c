#include "../exe3/TadPilhaSeq.h"
#include "Posf.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* Posfix (char *Inf)
{
    int tam = strlen(Inf)-1;

    Stack_char *Pilha;
    Pilha = Criate_Stack_char(tam);
    char *posf;
    posf = (char*) malloc (tam*sizeof(char));
    if(Pilha == NULL || posf == NULL)
    {
        printf("Ponteiro para pilha invalido!\n");
        Free_Stack_Char(Pilha);
        free(Inf);
        free(posf);
        exit(1);
    }

    char temp;
    int i=0, j=0;
    while(i < strlen(Inf)-1)
    {
        switch(Inf[i])
        {
            case '(':
                Push_Stack_Char(Pilha, Inf[i]);
                break;

            case '+':
            case '-':
                Stack_Top_Char(Pilha, &temp);
                if(temp == '*' || temp == '/')
                {
                    pop_Stack_Char(Pilha);
                    Push_Stack_Char(Pilha, Inf[i]);
                    Push_Stack_Char(Pilha, temp);
                }
                else
                    Push_Stack_Char(Pilha, Inf[i]);
                break;
            
            case '*':
            case '/':
                Stack_Top_Char(Pilha, &temp);
                if(temp == '*' || temp == '/')
                {
                    pop_Stack_Char(Pilha);
                    posf[j++] = temp;
                    Push_Stack_Char(Pilha, Inf[i]);
                }
                else
                    Push_Stack_Char(Pilha, Inf[i]);
                break;

            case ')':
                Stack_Top_Char(Pilha, &temp);
                while(temp != '(')
                {
                    pop_Stack_Char(Pilha);
                    posf[j++]= temp;
                    Stack_Top_Char(Pilha, &temp);
                }
                pop_Stack_Char(Pilha);
                break;

            default:
                posf[j++] = Inf[i];
                break;
        }
        i++;
    }
    Free_Stack_Char(Pilha);
    free(Inf);
    return posf;
}
