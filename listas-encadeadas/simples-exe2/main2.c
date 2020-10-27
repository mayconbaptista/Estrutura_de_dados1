#include <stdio.h>
#include <stdlib.h>
#include "linked-list2.h"

void Scan_Al (struct Students *Al);
void Remove_endl (struct Students *Al);
void Print_Al (struct Students Al);
int Menu (void);

int main (void)
{
    int res, pos, mat, opc;

    List *Li;
    Li = List_Criate2();

    struct Students Al;
    printf("Lista não ordenada insere no inicio final e por posição\n");
    printf("Lista ordenada insere somente ordenadamente função 4\n");
    printf("Sua lista sera ordenada ou não? (s/n): ");
    char opc2;
    scanf("%c",&opc2);
    Sorted_s_n(Li, opc2);

    do
    {
        opc = Menu();

        switch (opc)
        {
            case 1:
                Scan_Al(&Al);
                res = List_Push_Front2(Li, Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido.\n");
                else if(res == INVALID_OPERATION)
                    printf("Lista esta ordenada use a função 4!.\n");
                else if(res == OUT_OF_MEMORY)
                    printf("Memoria insuficiente!.\n");
                else 
                    printf("Operação finalizada com sucesso.\n");
                break;

            case 2:
                Scan_Al(&Al);
                res = List_Push_Back2(Li, Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido.\n");
                else if(res == INVALID_OPERATION)
                    printf("Lista esta ordenada use a função 4!.\n");
                else if(res == OUT_OF_MEMORY)
                    printf("Memoria insuficiente!.\n");
                else 
                    printf("Operação finalizada com sucesso.\n");
                break;
                
            case 3:
                Scan_Al(&Al);
                printf("Entre com a posição: ");
                scanf("%d",&pos);
                res = List_Insert2(Li, pos, Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido.\n");
                else if(res == INVALID_OPERATION)
                    printf("Lista esta ordenada use a função 4!.\n");
                else if(res == OUT_OF_MEMORY)
                    printf("Memoria insuficiente.\n");
                else if(res == OUT_NOT_RANGE)
                    printf("Posição invalida!\n");
                else 
                    printf("Operação finalizada com sucesso!.\n");
                break;
                
            case 4:
                Scan_Al(&Al);
                res = List_Insert_Sorted2(Li, Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido.\n");
                else if(res == OUT_OF_MEMORY)
                    printf("Memoria insuficiente.\n");
                else if(res == INVALID_OPERATION)
                    printf("função somente para lista Ordenada!\n");
                else 
                    printf("Operação finalizada com sucesso!.\n");
                break;
                
            case 5:
                printf("Entre co a posição: ");
                scanf("%d",&pos);
                res = List_Find_Pos2(Li, pos, &Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == OUT_NOT_RANGE)
                    printf("Lista ainda esta vazia ou elemento não encontrado!\n");
                else{
                    printf("Operação finalizada com sucesso.\n");
                    Print_Al(Al);
                }
                break;

            case 6:
                printf("Entre com numero de matricula: ");
                scanf("%d",&mat);
                res = List_Find_mat2(Li, mat, &Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == ELEM_NOT_FOUND)
                    printf("Elemento não encontrado!\n");
                else{
                    printf("Operação finalizada com sucesso!\n");
                    Print_Al(Al);
                }
                break;

            case 7:
                printf("Entre numero de matricula: ");
                scanf("%d",&mat);
                res = List_Get_Pos2(Li, mat, &pos);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == ELEM_NOT_FOUND)
                    printf("Elemento não encontrado!\n");
                else
                {
                    printf("Operação finalizada com sucesso.\n");
                    printf("A matricula %d esta na posição %d.\n",mat,pos);
                }
                break;

            case 8:
                res = List_Front2(Li, &Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == ELEM_NOT_FOUND)
                    printf("Lista inda vazia!\n");
                else
                    Print_Al(Al);
                break;
                
            case 9:
                res = List_Back2(Li, &Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para Lista invalido!\n");
                else if(res == ELEM_NOT_FOUND)
                    printf("Lista vazia!\n");
                else
                    Print_Al(Al);
                break;

            case 10:
                res = List_pop_Front2(Li);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == OUT_NOT_RANGE)
                    printf("Lista ainda esta vazia!\n");
                else
                    printf("Operação finalizada com sucesso.\n");
                break;

            case 11:
                res = List_pop_Back2(Li);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == OUT_NOT_RANGE)
                    printf("Lista ainda esta vazia!\n");
                else
                    printf("Operação finalizada com sucesso\n");
                break;

            case 12:
                printf("Entre coma posição: ");
                scanf("%d",&pos);
                res = List_Erase_Pos2(Li, pos);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == OUT_NOT_RANGE)
                    printf("Posição invalida!\n");
                else 
                    printf("Operação finalizada com sucesso!\n");                
                break;

            case 13:
                printf("Entre com matricula: ");
                scanf("%d",&mat);
                res = List_Erase_Mat2(Li, mat);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == ELEM_NOT_FOUND)
                    printf("Matricula não encontrada!\n");
                else 
                    printf("Operação finalizada com sucesso\n");
                break;

            case 14:
                res = Empyt_List2(Li);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponterio para lista invalido!\n");
                else if(res == OUT_NOT_RANGE)
                    printf("False, lista não esta vazia!\n");
                else
                    printf("True, Lista esta vazia!\n");
                break;

            case 15:
                res = Full_List2(Li);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == OUT_NOT_RANGE)
                    printf("Falso, Ainda possui memoria disponivel\n");
                else
                    printf("True, não possui mais memoria disponivel\n");
                break;

            case 16:
                res = Size_List2(Li);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else
                    printf("Tamanho atual de %d\n.",res);
                break;

            case 17:
                res = Print_List2(Li);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == OUT_NOT_RANGE)
                    printf("Lista vazia!\n");
                break;

            default:
                if(opc != 0)
                    printf("Entre com um valor valido!\n");
                break;
        }
    }while(opc != 0);

    List_Free2(Li);
    return 0;
}

void Scan_Al (struct Students *Al)
{
    printf("Entre com matricula: ");
    scanf("%d",&Al->enrollment);

    printf("Entre com nome: ");
    setbuf(stdin, NULL);
    fgets(Al->name, 30, stdin);
    Remove_endl(Al);

    printf("Notas: ");
    scanf("%f",&Al->n1);
    scanf("%f",&Al->n2);
    scanf("%f",&Al->n3);
    return;
}

void Remove_endl (struct Students *Al)
{
    int i=0;
    while(Al->name[i] != '\n')
        i++;
    
    Al->name[i] = '\0';
    return;
}

void Print_Al (struct Students Al)
{
    printf("Matricula: %d\t",Al.enrollment);
    printf("Nome: %s\t",Al.name);
    printf("Notas: %.1f %.1f %.1f\n",Al.n1, Al.n2,Al.n3);
    return;
}

int Menu (void)
{
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Menu<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("                        Funções de incerção\n");
    printf("1-Insere no inicio.\n");
    printf("2-Insere no final.\n");
    printf("3-Insere indicado pela pos.\n");
    printf("4-Inrese ornedano pela matricula.\n");
    printf("                          Funçoes de busca\n");
    printf("5-Busca por posição.\n");
    printf("6-Busca por matricula.\n");
    printf("7-Busca a posição indicado pela matricula.\n");
    printf("8-Busca o primmeiro elemnto\n");
    printf("9-Busca o ultimo elemento.\n");
    printf("                         Funções de remoção\n");
    printf("10-Remoção no inicio.\n");
    printf("11-Remoção no final.\n");
    printf("12-Remove inindicado pela posição.\n");
    printf("13-Remove indicado pela matricula.\n");
    printf("                        Funçoes de tamanho\n");
    printf("14-Lista vazia.\n");
    printf("15-Lista Cheia.\n");
    printf("16-Tamanho da lista.\n");
    printf("                             Outras\n");
    printf("17-Imprime Lista.\n");
    printf("0- para sair.\n");
    printf("Entre com uma opção: ");
    int opc;
    scanf("%d",&opc);
    printf("------------------------\n");
    return opc;
}