#include <stdio.h>
#include <stdlib.h>

int Verifica (char *S)
{
    Stack *Pi;
    Pi = Stak_Criate();

    int i=0, res;
    char let;
    do
    {
        switch (S[i])
        {
            case '(':
                Stack_push(Pi, S[i]);
                break;

            case ')':
                if(Stack_Empty(Pi) == 0)
                {
                    Stack_free(Pi);
                    return -1;
                }
                else
                    Stack_top(Pi,&let);
                if(let == '(')
                    Satck_pop(Pi);
                else
                    Stack_push(Pi, S[i]);
                break;

            case '[':
                Stak_push(Pi,S[i]);
                break;

            case ']':
                if(Stack_empyt(Pi) == 0)
                {
                    Stack_free(Pi);
                    return -1;
                }
                else
                    Stack_top(Pi, &let);
                if(let == '[')
                    Stak_pop(Pi);
                else
                    Stak_push(Pi, S[i]);
                break;
        }
        i++;
    }while(S[i] != '\0');
    
    if(stak_mpyt(Pi) == SUCESS)
    {
        Stack_free(Pi);
        return 0;
    }
    else
    {
        Stack_free(Pi);
        return 1;
    }
}