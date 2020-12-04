#include "TadFilaVaria.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../aluno.h"

void retornos (int codigo);
int Menu (void);
void Print_Al (struct Students Al);
void Scan_Al (struct Students *Al);

int main (void)
{
    int res, opc;

    struct Students Al;

    printf("Qual sera o tamanho inicial da fila?: ");
    int tam;
    scanf("%d",&tam);

    Queue *Fi;
    Fi = Criate_Queue_Variant (tam);

    do{
        opc = Menu();

        switch (opc)
        {
        case 1:
            Scan_Al(&Al);
            res = Enqueue_Variant (Fi, Al);
            break;

        case 2:
            res = Dequeue_Variant (Fi);
            break;

        case 3:
            res = First_Queue_Variant (Fi,&Al);
            if(res == SUCESS)
                Print_Al(Al);
            break;

        case 4:
            res = Size_Queue_Variant(Fi);
            if(res != INVALID_NULL_POINTER)
            {
                printf("O tamanho atual é %d\n",res);
                continue;
            }
            break;

        case 5:
            res = Empty_Queue_Variant(Fi);
            if(res == SUCESS)
                printf("True, lista vazia!\n");
            else if(res == OUT_NOT_RANGE)
                printf("False, não esta vazia!\n");
            else
                continue;
            break;

        case 6:
            res = Queue_Variant_Full(Fi);
            if(res == SUCESS)
                printf("True, Cheia!\n");
            else if(res == OUT_NOT_RANGE)
                printf("False, ainda!\n");
            else
                continue;
            break;

        case 7:
            res = Compact_Queue_Variant (Fi);
            break;

        case 8:
            Print_Queue_Variant(Fi);
            break;

        case 0:
            Free_Queue_Variant(Fi);
            break;
        
        default:
            printf("Entre com uma opção valida!\n");
            break;
        }

        retornos(res);

    }while(opc != 0);

    return 0;
}


void Scan_Al (struct Students *Al)
{
    printf("Entre com matricula: ");
    scanf("%d",&Al->matricula);

    printf("Entre com nome: ");
    setbuf(stdin, NULL);
    fgets(Al->name, 30, stdin);
    
    int i=0;
    while(Al->name[i] != '\n')
        i++;
    
    Al->name[i] = '\0';

    printf("Notas: ");
    scanf("%f",&Al->n1);
    scanf("%f",&Al->n2);
    scanf("%f",&Al->n3);
    return;
}

void Print_Al (struct Students Al)
{
    printf("Matricula: %d\t",Al.matricula);
    printf("Nome: %s\t",Al.name);
    printf("NOtas: %.1f %.1f %.1f\n",Al.n1, Al.n2, Al.n3);
}

int Menu (void)
{
    printf(">>>>>>>>>>>>>>>>>>Menu<<<<<<<<<<<<<<<<<<<\n");
    printf("\t1-Isere.\n");
    printf("\t2-Remove.\n");
    printf("\t3-Busca o primeiro.\n");
    printf("\t4-Tamanho.\n");
    printf("\t5-Vazia?.\n");
    printf("\t6-Cheia?\n");
    printf("\t7-compacta.\n");
    printf("\t8-Imprime.\n");
    printf("\t0-sair.\n");
    printf("Opção: ");
    int opc;
    scanf("%d",&opc);
    return opc;
}

void retornos (int codigo)
{
    switch (codigo)
    {
    case 0:
        printf("Operação finalizada com sucesso!\n");
        break;
    case -1:
        printf("Erro! Ponteiro para lista invalido!\n");
        break;
    case -2:
        printf("Erro! Elemento não encontrado\n");
        break;
    case -3:
        printf("Erro! Falta de mamoria\n");
        break;
    case -4:
        printf("Erro! Fora do alcanse\n");
        break;
    }
}
