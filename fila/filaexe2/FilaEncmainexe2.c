#include <stdio.h>
#include "FilaEncexe2.h"
#include "../../aluno.h"

void consulta (struct Students Al);
void dados_aluno (struct Students *Al);
int Menu (void);


int main (void)
{
    int res, opc, mat;

    Queue *Fi;
    Fi = Criate_Queue_Enc ();

    struct Students Al;

    do{
        opc = Menu();
        switch (opc)
        {
        case 1:
            dados_aluno(&Al);
            res = Enqueue_Enc(Fi, Al);
            if(res == SUCESS)
                printf("Operação finalizada com sucesso!\n");
            else
                printf("erro Cod %d\n",res);
            break;

        case 2:
            res = Dequeue_Enc (Fi);
            if(res == SUCESS)
                printf("Operação finalizada com sucesso!\n");
            else
                printf("erro Cod %d\n",res);
            break;

        
        case 3:
            res = First_Queue_Enc(Fi, &Al);
            if(res == SUCESS)
            {
                printf("Operação finalizada com sucesso!\n");
                consulta(Al);
            }
            else
                printf("erro Cod %d\n",res);
            break;

        case 4:
            // leitura dos dados do aluno
            res = Size_Queue_Enc (Fi);
            if(res == INVALID_NULL_POINTER)
                printf("ponteiro para fila invalido!\n");
            else
                printf("Tamanho atual da fila de %d\n",res);
            break;

        case 5:
            // leitura dos dados do aluno
            res = Empyt_Queue_Enc (Fi);
            if(res == SUCESS)
                printf("True, lista vazia!\n");
            else if(res == OUT_NOT_RANGE)
                printf("False, não esta vazia!\n");
            else
                printf("Erro Cod %d\n",res);
            break;

        case 6:
            res = Full_Queue_Enc (Fi);
            if(res == SUCESS)
                printf("True, não ha mais memoria!\n");
            else if(res == OUT_NOT_RANGE)
                printf("False, ainda a mamoria.\n");
            else
                printf("Erro! Cod %d\n",res);
            break;

        case 7:
            Print_Queue_Enc(Fi);
            break;

        case 0:
            Free_Queue_Enc(Fi);
            break;
        
        default:
            printf("Entre com opção valida!\n");
            break;
        }

    }while(opc != 0);

    printf("Fim!\n");
    return 0;
}

void dados_aluno (struct Students *Al)
{
    printf("Entre com matricula: ");
    scanf("%d",&Al->matricula);

    printf("Entre com nome: ");
    setbuf(stdin, NULL);
    fgets(Al->name, 30, stdin);


    for(int i=0; i < 30; i++)
    {
        if(Al->name[i] == '\n')
        {
            Al->name[i] = '\0';
            break;
        }
    }

    printf("Entre com as notas: ");
    scanf("%f",&Al->n1);
    scanf("%f",&Al->n2);
    scanf("%f",&Al->n3);
}

int Menu (void)
{
    printf(">>>>>>>>>>>>>>>>>>>>menu<<<<<<<<<<<<<<<<<<\n");
    printf("\t1- Insere\n");
    printf("\t2- Remove\n");
    printf("\t3- consulta primeiro\n");
    printf("\t4- tamanho\n");
    printf("\t5- vazia?\n");
    printf("\t6-Cheia.\n");
    printf("\t7- vizualiza.\n");
    printf("\t0- Liberar/sair\n");
    printf("Opção: ");
    int opc;
    scanf("%d",&opc);
    return opc;
}

void consulta (struct Students Al)
{
    printf("Matricula : %d\t",Al.matricula);
    printf("Nome: %s\t",Al.name);
    printf("Notas: %.1f %.1f %.1f\n",Al.n1, Al.n2, Al.n3);
}