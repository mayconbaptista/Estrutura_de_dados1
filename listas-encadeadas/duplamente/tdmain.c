#include <stdio.h>
#include <stdlib.h>
#include "tdlinked-list.h"

void Scan_Al (struct Students *Al);
void Remove_endl (struct Students *Al);
void Print_Al (struct Students Al);
int Menu (void);

int main (void)
{
    int res, pos, mat, opc;

    List *Li;
    Li = TDList_criate();
    // iniciando lista

    struct Students Al;
    // iniciando dados alunos


    do
    {
        opc = Menu();

        switch (opc)
        {
            case 1:
                Scan_Al(&Al);
                res = TDList_Push_Front(Li, Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido.\n");
                else if(res == OUT_OF_MEMORY)
                    printf("Memoria insuficiente!.\n");
                else 
                    printf("Operação finalizada com sucesso.\n");
                break;

            case 2:
                Scan_Al(&Al);
                res = TDList_Push_Back(Li , Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido.\n");
                else if(res == OUT_OF_MEMORY)
                    printf("Memoria insuficiente!.\n");
                else 
                    printf("Operação finalizada com sucesso.\n");
                break;
                
            case 3:
                Scan_Al(&Al);
                printf("Entre com a posição: ");
                scanf("%d",&pos);
                res = TDList_Insert(Li, pos, Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido.\n");
                else if(res == OUT_OF_MEMORY)
                    printf("Memoria insuficiente.\n");
                else if(res == OUT_NOT_RANGE)
                    printf("Posição invalida!\n");
                else 
                    printf("Operação finalizada com sucesso!.\n");
                break;
                
            case 4:
                Scan_Al(&Al);
                res = TDList_Insert_Sorted(Li, Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido.\n");
                else if(res == OUT_OF_MEMORY)
                    printf("Memoria insuficiente.\n");
                else 
                    printf("Operação finalizada com sucesso!.\n");
                break;
                
            case 5:
                printf("Entre com a posição: ");
                scanf("%d",&pos);
                res = TDList_Find_Pos(Li, pos, &Al);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponterio para lista invalido.\n");
                else if(res == OUT_NOT_RANGE)
                    printf("Posição invalida!\n");
                else{
                    printf("Operação finalizada com sucesso!\n");
                    Print_Al(Al);
                }
                break;

            case 6:
                printf("Entre com numero de matricula: ");
                scanf("%d",&mat);
                res = TDList_Find_Mat(Li, mat, &Al);
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
                res = TDList_Get_Pos(Li, mat, &pos);
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
                res = TDList_Front (Li, &Al);
                if(res == INVALID_NULL_POINTER)
                {
                    printf("Ponteiro para lista invalido!\n");
                    return 0;
                }
                else if(res == ELEM_NOT_FOUND)
                    printf("Lista vazia!\n");
                else
                    Print_Al(Al);
                break;
            case 9:
                res = TDList_Back(Li, &Al);
                if(res == INVALID_NULL_POINTER)
                {
                    printf("Ponteiro para lista invalido!\n");
                    return 0;
                }
                else if(res == ELEM_NOT_FOUND)
                    printf("Lista vazia!\n");
                else
                    Print_Al(Al);
                break;

            case 10:
                res = TDList_Pop_Front(Li);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == OUT_NOT_RANGE)
                    printf("Lista ainda esta vazia!\n");
                else
                    printf("Operação finalizada com sucesso.\n");
                break;

            case 11:
                res = TDList_Pop_Back(Li);
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
                res = TDList_Erase_Pos(Li, pos);
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
                res = TDList_Erase_Mat(Li, mat);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == ELEM_NOT_FOUND)
                    printf("Matricula não encontrada!\n");
                else 
                    printf("Operação finalizada com sucesso\n");
                break;

            case 14:
                res = TDEmpyt_List (Li);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponterio para lista invalido!\n");
                else if(res == OUT_NOT_RANGE)
                    printf("False, lista não esta vazia!\n");
                else
                    printf("True, Lista esta vazia!\n");
                break;

            case 15:
                res = TDFull_List (Li);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == OUT_NOT_RANGE)
                    printf("Falso, Ainda possui memoria disponivel\n");
                else
                    printf("True, não possui mais memoria disponivel\n");
                break;

            case 16:
                res = TDSize_List(Li);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else
                    printf("Tamanho atual de %d\n",res);
                break;

            case 17:
                res = TDPrint_List(Li);
                if(res == INVALID_NULL_POINTER)
                    printf("Ponteiro para lista invalido!\n");
                else if(res == ELEM_NOT_FOUND)
                    printf("Lista ainda esta vazia!\n");
                break;
            
            case 18:
                res = Verifica(Li);
                if(res == SUCESS)
                    printf("Ponteiros corretos.\n");
                else
                    printf("perda de ponteiros!\n");
                break;

            default:
                if(opc != 0)
                    printf("Entre com um valor valido!\n");
                break;
        }
    }while(opc != 0);

    TDList_Free(Li);
    return 0;
}

void Scan_Al (struct Students *Al)
{
    printf("Entre com matricula: ");
    scanf("%d",&Al->matricula);

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
    printf("Matricula: %d\t",Al.matricula);
    printf("Nome: %s\t",Al.name);
    printf("NOtas: %.1f %.1f %.1f\n",Al.n1, Al.n2, Al.n3);
}

int Menu (void)
{
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Menu<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("                        Funções de incerção\n");
    printf("1-Inicio.\n");
    printf("2-Final.\n");
    printf("3-Indicado pela pos.\n");
    printf("4-Ordenado.\n");
    printf("                          Funçoes de busca\n");
    printf("5-Posição.\n");
    printf("6-Matricula.\n");
    printf("7-Posição pela matricula.\n");
    printf("8-Primeiro.\n");
    printf("9-Ultimo.\n");
    printf("                         Funções de remoção\n");
    printf("10-Primeiro.\n");
    printf("11-Ultimo.\n");
    printf("12-Por posição.\n");
    printf("13-Por matricula.\n");
    printf("                        Funçoes de tamanho\n");
    printf("14-vazia?.\n");
    printf("15-Cheia?.\n");
    printf("16-Tamanho.\n");
    printf("                             Outras\n");
    printf("17-Imprime.\n");
    printf("0- para sair.\n");
    printf("Entre com uma opção: ");
    int opc;
    scanf("%d",&opc);
    return opc;
}