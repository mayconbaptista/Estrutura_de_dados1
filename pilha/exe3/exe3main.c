#include <stdlib.h>
#include <stdio.h>
#include "TadPilhaSeq.h"

int Menu (void);

int main (void)
{
    int opc, tam;
    char c;

    printf("Entre com o tamanho maximo da pilha de char: ");
    scanf("%d",&tam);

    Stack_char *Pi;
    Pi = Criate_Stack_char(tam);

    int res;
    do
    {
        opc = Menu();
        switch (opc)
        {
        case 1:
            printf("Entre com caracter: ");
            setbuf(stdin, NULL);
            c = getchar();
            res = Push_Stack_Char(Pi, c);
            if(res == SUCESS)
                printf("Operação finalizada com sucesso!\n");
            else
                printf("Erro! cod %d\n",res);
            break;

        case 2:
            res = pop_Stack_Char (Pi);
            if(res == SUCESS)
                printf("Operação finalizada com sucesso!\n");
            else
                printf("Erro! cod %d\n",res);
            break;

        case 3:
            res = Stack_Top_Char (Pi, &c);
            if(res == SUCESS){
                printf("Operação finalizada com sucesso!\n");
                printf("Caracter: %c\n",c);
            }
            else
                printf("Erro! cod = %d\n",res);
            break;
        case 4:
            res = Size_Stack_Char(Pi);
            if(res == INVALID_NULL_POINTER)
                printf("Erro! cod = %d\n",res);
            else
                printf("O tamanho atual da lista e %d elementos!\n",res);
            break;

        case 5:
            res = Full_Stack_Char (Pi);
            if(res == SUCESS)
                printf("True, não a mais espaço na mamoria!\n");
            else if(res == ELEM_NOT_FOUND)
                printf("False, anda a espaço no vetor!\n");
            else
                printf("Erro! cod = %d\n",res);
            break;

        case 6:
            res = Empyt_Stack_Char (Pi);
            if(res == SUCESS)
                printf("True, pilha vazia!\n");
            else if(res == ELEM_NOT_FOUND)
                printf("False, lista nao esta vazia!\n");
            else
                printf("Erro! cod = %d\n",res);
            break;
        case 7:
            Print_Stack_Char(Pi);
            break;
        case 0:
            Free_Stack_Char (Pi);
            break;
        default:
            printf("Entre com uma opcão valida!\n");
            break;
        }
    } while (opc != 0);

    printf("FIM!\n");
    return 0;   
}

int Menu (void)
{
    printf(">>>>>>>>>>>>>>>>>Menu<<<<<<<<<<<<<<<<<<<\n");
    printf("\t1- Insere\n");
    printf("\t2- Remove\n");
    printf("\t3- Consulta o ultimo elemento\n");
    printf("\t4- tamanho\n");
    printf("\t5- cheia?\n");
    printf("\t6- Vazia\n");
    printf("\t7- Imprime\n");
    printf("\t0-Sair\n");
    printf("Entre com uma opção: ");
    int opc;
    scanf("%d",&opc);
    printf("----------------\n");
    return opc;
}