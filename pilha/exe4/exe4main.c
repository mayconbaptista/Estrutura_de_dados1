#include <stdio.h>
#include <stdlib.h>
#include "../exe3/TadPilhaSeq.h"

char Verifica (Stack_char *Pi, char *S);
void imprime (char *S);

int main (void)
{
    int n;
    char *S;
    printf("Entre com quantidades dos parenteses: ");
    scanf("%d",&n);
    n++; // para contar '\0'
    S = (char*) malloc (n*sizeof(char));
    if(S == NULL)
    {
        printf("Ponteiro para lista Invalido\n");
        exit(1);
    }

    printf("Entre com os caracteres: ");
    setbuf(stdin, NULL);
    fgets(S, 30, stdin);
    Stack_char *Pi;    
    Pi = Criate_Stack_char(n);
    if(Pi == NULL)
    {
        printf("Erro Ponteiro para pilha invalido!");
        exit(1);
    }
    else
    {
        if(Verifica(Pi, S) == 's')
            printf("Sim a sequencia esta bem formada!\n");
        else
            printf("Não, ela esta mal formada!\n");
    }
    Free_Stack_Char(Pi);
    free(S);
    return 0;
}


void imprime (char *S)
{
    printf("Vetor original!\n");
    for(int i = 0; S[i] != '\0'; i++)
    {
        printf("%c",S[i]);
    }
    printf("\n");
}

char Verifica (Stack_char *Pi, char *S)
{
    int i=0, res;
    char let;
    do
    {
        switch (S[i])
        {
            case '(':
                Push_Stack_Char(Pi, S[i]);
                break;

            case ')':
                if(Empyt_Stack_Char(Pi) == SUCESS)
                    return 'n';
                else
                    Stack_Top_Char(Pi,&let);
                if(let == '(')
                    pop_Stack_Char(Pi);
                else
                    Push_Stack_Char(Pi, S[i]);
                break;

            case '[':
                Push_Stack_Char(Pi,S[i]);
                break;

            case ']':
                if(Empyt_Stack_Char(Pi) == SUCESS)
                    return 'n';
                else
                    Stack_Top_Char(Pi, &let);
                if(let == '[')
                    pop_Stack_Char(Pi);
                else
                    Push_Stack_Char(Pi, S[i]);
                break;
        }
        i++;
    }while(S[i] != '\0');
    
    if(Empyt_Stack_Char(Pi) == SUCESS)
        return 's';
    else
        return 'n';
}