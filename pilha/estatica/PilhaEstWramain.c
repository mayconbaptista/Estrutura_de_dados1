#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstWrapper.h"

void Print_Al (struct Students Al);
void Scan_Al (struct Students *Al);
int Menu (void);

int main (void)
{
    int opc, res;

    struct Students Al;

    Stack *Pi;
    Pi = Criat_Stak();

    do
    {
        opc = Menu();
        switch (opc)
        {
        case 1:
            Scan_Al(&Al);
            res = Push_Stak(Pi, Al);
            if(res == 0)
                printf("Operação finalizada com sucesso!\n");
            else
                printf("Erro! cod = %d\n",res);
            break;

        case 2:
            res = Pop_Stack(Pi);
            if(res == 0)
                printf("Operação finalizada com sucesso!\n");
            else
                printf("Erro! cod = %d\n",res);
            break;
        case 3:
            res = Top_Stack(Pi, &Al);
            if(res == 0){
                printf("Operação finalizada com sucesso!\n");
                Print_Al(Al);
            }
            else
                printf("Erro! cod = %d\n",res);
            break;
        case 4:
            res = Size_Stak(Pi);
            if(res == -1)
                printf("Erro! cod = %d\n",res);
            else
                printf("O tamanho atual da lista e %d elementos!\n",res);
            break;
        case 5:
            res = Full_Stack(Pi);
            if(res == -2)
                printf("True, pilha estatica cheia\n!\n");
            else if(res == 0)
                printf("False, ainda possui espaço!\n");
            else
                printf("Erro! cod = %d\n",res);
            break;
        case 6:
            res = Empyt_stack(Pi);
            if(res == 0)
                printf("True, pilha vazia!\n");
            else if(res == -2)
                printf("False, pilha nao esta vazia!\n");
            else
                printf("Erro! cod = %d\n",res);
            break;
        case 7:
            Print_Stack(Pi);
            break;
        case 0:
            Free_Stak(Pi);
            break;
        default:
            printf("Entre com uma opcão valida!\n");
            break;
        }
    } while (opc != 0);

    printf("FIM!\n");
    return 0;   
}

void Scan_Al (struct Students *Al)
{
    printf("Entre com matricula: ");
    scanf("%d",&Al->matricula);

    printf("Entre com nome: ");
    setbuf(stdin, NULL);
    fgets(Al->nome, 30, stdin);

    // remove o '\n'
    int i=0;
    while (Al->nome[i] != '\n')
        i++;
    Al->nome[i]='\0';

    printf("Entre com notas: ");
    scanf("%f",&Al->n1);
    scanf("%f",&Al->n2);
    scanf("%f",&Al->n3);
}


int Menu (void)
{
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>Menu<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("1-Insere Na pilha.\n");
    printf("2-Remove elemento da pilha.\n");
    printf("3-conta ultimo elemento da pilha.\n");
    printf("4- tamanho pilha.\n");
    printf("5- Pilha Cheia?.\n");
    printf("6- Pilha vazia?.\n");
    printf("7-Emprime pilha.\n");
    printf("entre com opção: ");
    int opc;
    scanf("%d",&opc);
    printf("-----------------------------------\n");
    return opc;
}

void Print_Al (struct Students Al)
{
    printf("Matricula: %d\t",Al.matricula);
    printf("Nome: %s\t",Al.nome);
    printf("Notas: %.1f %.1f %.1f\n",Al.n1, Al.n2, Al.n3);
}