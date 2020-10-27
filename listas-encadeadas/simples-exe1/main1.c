#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "linked-list1.h"

int Menu (void);
// menu com as opções.
void Print_Al (struct Students Al);
// printa as consultas.
int Scan_Al (struct Students *Al);
// ler os dados para incerção.



int main (void)
{
    int res; // obter o retorno das funções.
    int opc; // para o meu laço e switch.
    int pos, mat; // variaveis auxiliares.

    List *Li;
    Li = List_Criate();
    // iniciando minha lista;
    struct Students Al;

    while (opc != 0)
    {
        opc = Menu();
        switch (opc)
        {
        case 1:
            // insere no inicio.
            Scan_Al(&Al);
            res = List_Push_Front(Li, Al);
            if(res == INVALID_NULL_POINTER)
                printf("Ponteiro para lista invalido!\n");
            else if(res == OUT_OF_MEMORY)
                printf("Memoria insuficiente!\n");
            else
                printf("Operação Finalizada com sucesso.\n");
           break;

        case 2:
            //Insere no final
            Scan_Al(&Al);
            res = List_Push_Back(Li, Al);
            if(res == INVALID_NULL_POINTER)
                printf("Ponteiro para lista invalido!\n");
            else if(res == OUT_OF_MEMORY)
                printf("Memoria insuficiente!\n");
            else
                printf("Operação Finalizada com sucesso.\n");
           break;

        case 3:
            // insere ordenada por mat 
            Scan_Al(&Al);
            res = List_Insert_Sorted(Li, Al);
            if(res == INVALID_NULL_POINTER){
                printf("Ponteiro para lista invalido!\n");
                return 0;
            }
            else if(res == OUT_OF_MEMORY)
                printf("Memoria insuficiente!\n");
            else if(res == OUT_NOT_RANGE)
                printf("Lista ainda esta vazia use outra opção.\n");
            else
                printf("Operação Finalizada com sucesso.\n");
            break;

        case 4:
            // insere ornada por pos.
            printf("Entre com pos: ");
            scanf("%d",&pos);
            Scan_Al(&Al);
            res = List_Insert(Li, pos, Al);
            if(res == INVALID_NULL_POINTER){
                printf("Ponteiro para lista Invalido!\n");
                return 0;
            }
            else if(res == OUT_OF_MEMORY)
                printf("Memoria insuficiente!\n");
            else if(res == OUT_NOT_RANGE)
                printf("Posição invalida!\n");
            else 
                printf("Operação finalizada com sucesso.\n");
            break;

        case 5:
            // busca por posição;
            printf("Entre com posição para consulta: ");
            scanf("%d",&pos);
            res = List_Find_Pos(Li, pos, &Al);
            if(res == INVALID_NULL_POINTER)
                printf("Ponteiro para lista Invalido!\n");
            else if(res == OUT_NOT_RANGE)
                printf("Posição invalida!\n");
            else{ 
                printf("Operação finalizada com sucesso.\n");
                Print_Al(Al);
            }
           break;

        case 6:
            // busca por numero de matricula.
            printf("Entre com numero de matricula: ");
            scanf("%d",&mat);
            res = List_Find_Mat(Li, mat, &Al);
            if(res == INVALID_NULL_POINTER)
                printf("Ponteiro para lista invalido.\n");
            else if(res == ELEM_NOT_FOUND)
                printf("Elemento não encontrado!.\n");
            else{
                printf("Operação finalizada com sucesso.\n");
                Print_Al(Al);
            }
           break;

        case 7:
            // consulta pos pela mat
            printf("Entre com numero de matricula: ");
            scanf("%d",&mat);
            res = List_get_Pos (Li, mat, &pos);
            if(res == INVALID_NULL_POINTER){
                printf("Ponteiro para lista invalido.\n");
                return 0;
            }
            else if(res == ELEM_NOT_FOUND)
                printf("Elemento não encontrado!.\n");
            else{
                printf("Operação finalizada com sucesso.\n");
                printf("A pos da matrucula %d e %d\n",mat, pos);
            }
            break;

        case 8:
            res = List_Front (Li, &Al);
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
            res = List_Back (Li, &Al);
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
            // remove inicio
            res = List_pop_Front(Li);
            if(res == INVALID_NULL_POINTER){
                printf("Ponteiro para lista invalido!\n");
                return 0;
            }
            else if(res == ELEM_NOT_FOUND)
                printf("Nenhum elemento encontrado!\n");
            else
                printf("Operação finalizada com sucesso.\n");
            break;

        case 11:
            // remove final
            res = List_pop_Back(Li);
            if(res == INVALID_NULL_POINTER)
                printf("Ponteiro para lista invalido.\n");
            else if(res == ELEM_NOT_FOUND)
                printf("Elemento não encontrado!.\n");
            else{
                printf("Operação finalizada com sucesso.\n");
            }
            break;

        case 12:
            // remove pela pos
            printf("Entre com a posição: ");
            scanf("%d",&pos);
            res = List_Erase_Pos(Li, pos);
            if(res == INVALID_NULL_POINTER)
                printf("Ponteiro para lista invalido!\n");
            else if(res == OUT_NOT_RANGE)
                printf("Posição não encontrada!\n");
            else 
                printf("Operação realizada com sucesso!\n");
            break;

        case 13:
            // remove por numero de matricula
            printf("Entre com numero de matricula: ");
            scanf("%d",&mat);
            res = List_Erase_Mat(Li, mat);
            if(res == INVALID_NULL_POINTER)
                printf("Ponteiro para lista invalido!\n");
            else if(res == ELEM_NOT_FOUND)
                printf("Elemento não encontrado!\n");
            else
                printf("Operação finalizada com sucesso.\n");
            break;

        case 14:
            // lista vazia.
            res = Empty_List (Li);
            if(res == INVALID_NULL_POINTER)
                printf("Ponteiro para lista invalido!\n");
            else if(res == OUT_NOT_RANGE)
                printf("Não, lista não esta vazia.\n");
            else
                printf("Sim, lista esta vazia.\n");
            break;

        case 15:
            // lista cheia
            res = Full_List (Li);
            if(res == INVALID_NULL_POINTER)
                printf("Ponteiro para lista invalido!\n");
            else if(res == OUT_NOT_RANGE)
                printf("Falso Lista não esta Cheia!\n");
            else if(res == SUCESS)
                printf("Sim lista esta cheia.\n");
            break;
        
        case 16:
            // tamanho da lista.
            res = Size_List(Li);
            if(res == INVALID_NULL_POINTER)
                printf("Ponteiro para lista invalido!\n");
            else
                printf("O tamanho atual da lista e de %d.\n",res);
            break;
        case 17:
            // imprime lista.
            res = Print_List(Li);
            if(res == INVALID_NULL_POINTER){
                printf("Ponteiro para lista invalido!\n");
                return 0;
            }
            else if(res == OUT_NOT_RANGE)
                printf("Lista ainda esta vazia!\n");
           break;

        default:
            if(opc != 0)
                printf("Entre com uma opção valida!.\n");
            break;
        }
    }
    List_Free(Li);
    return 0;  
}

void Print_Al (struct Students Al)
{
    printf("Matricula: %d\t",Al.matricula);
    printf("Nome: %s\t",Al.nome);
    printf("Notas: %.1f %.1f %.1f\n",Al.n1, Al.n2, Al.n3);
}

int Scan_Al (struct Students *Al)
{
    printf("Entre com matricula: ");
    scanf("%d",&Al->matricula);
    setbuf(stdin, NULL);
    printf("Entre com nome: ");
    fgets(Al->nome, 30, stdin);
    printf("Entre com as Notas\nNota 1: ");
    scanf("%f",&Al->n1);
    printf("Nota 2: ");
    scanf("%f",&Al->n2);
    printf("Nota 3: ");
    scanf("%f",&Al->n3);
    return SUCESS;
}

int Menu (void)
{
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Menu<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("                    Funçoes relacionadas a incerção:\n");
    printf("1-insere no inicio.\n");
    printf("2-insere no final.\n");
    printf("3-insere ordenado por matricula.\n");
    printf("4-insere ordenado por posição.\n");

    printf("                     Funções relacionadas a busca:\n");
    printf("5-busca por posição.\n");
    printf("6-busca por numero de matricula.\n");
    printf("7-busca posição pela matricula.\n");
    printf("8-retorna o primeiro elemento.\n");
    printf("9-retorna o ultimo elemento.\n");

    printf("                     Funções relacionadas a remoção.\n");
    printf("10-remove inicio.\n");
    printf("11-remove final.\n");
    printf("12-remove indicado pela posição.\n");
    printf("13-remove indicado por matricula.\n");

    printf("                     Funçoes relacionadas ao tamanho:\n");
    printf("14-lista vazia.\n");
    printf("15-lista cheia.\n");
    printf("16-tamanho da lista.\n");

    printf("                               Outras.\n");
    printf("17-Libera lista.\n");
    printf("0 Para sair...");

    printf("\nEntre com uma opção: ");
    int opc;
    scanf("%d",&opc);
    printf("-------------------------\n");
    return opc;
}