#include "ListaEncCir.h"
#include <stdio.h>
#include <stdlib.h>

void Scan_Al (struct Students *Al);
void Remove_endl (struct Students *Al);
void Print_Al (struct Students Al);
int Menu (void);
void retornos (int codigo);

int main (void)
{
    int res, pos, mat, opc;

    List *Li;
    Li = Criate_Lista_Circular();
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
                res = Push_Front_List_Circular(Li, Al);
                break;

            case 2:
                Scan_Al(&Al);
                res = Push_Back_List_Circular(Li, Al);
                break;
                
            case 3:
                Scan_Al(&Al);
                printf("Entre com a posição: ");
                scanf("%d",&pos);
                res = Insert_List_Circular_Ordered_Pos(Li, Al, pos);
                break;
                
            case 4:
                Scan_Al(&Al);
                res = Insert_List_Circular_Ordered_Mat (Li, Al);
                break;
                
            case 5:
                printf("Entre com a posição: ");
                scanf("%d",&pos);
                res = List_Circular_Find_pos (Li, pos, &Al);
                if(res == SUCESS)
                    Print_Al(Al);
                break;

            case 6:
                printf("Entre com numero de matricula: ");
                scanf("%d",&mat);
                res = List_Circular_Find_Mat(Li, mat, &Al);
                if(res == SUCESS)
                    Print_Al(Al);
                break;

            case 7:
                printf("Entre numero de matricula: ");
                scanf("%d",&mat);
                res = List_Circular_Get_Pos_ (Li, &pos, mat);
                if(res == SUCESS)
                    printf("A matricula %d esta na possição %d\n",mat,pos);
                break;

            case 8:
                res = List_Back_Circular (Li, &Al);
                if(res == SUCESS)
                    Print_Al(Al);
                break;

            case 9:
                res = List_Circular_Pop_Front(Li);
                break;

            case 10:
                res = List_Circular_Pop_Back(Li);
                break;

            case 11:
                printf("Entre coma posição: ");
                scanf("%d",&pos);
                res = List_Circular_Erase_Pos(Li,pos);             
                break;

            case 12:
                printf("Entre com matricula: ");
                scanf("%d",&mat);
                res = List_Circular_Erase_mat(Li, mat);
                break;

            case 13:
                res = Empyt_List_Circular(Li);
                if(res == SUCESS)
                    printf("True, Lista inda vazia!\n");
                break;

            case 14:
                res = List_Circular_Full(Li);
                if(res == OUT_NOT_RANGE)
                    printf("False, lista não esta cheia!\n");
                break;

            case 15:
                res = Size_List_Circular(Li);
                if(res != INVALID_NULL_POINTER)
                    printf("Tamanho atual da lista e de %d.\n",res);
                break;

            case 16:
                res = Print_List_Circular(Li);
                break;
            
            case 0:
                Free_List_Circular (Li);
                continue;
                break;

            default:
                printf("Entre com um valor valido!\n");
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
    printf("4-Ordenado pela matricula.\n");
    printf("                          Funçoes de busca\n");
    printf("5-indicado pela posição.\n");
    printf("6-indicado pela matricula.\n");
    printf("7-Posição indicado pela matricula.\n");
    printf("8-Ultimo.\n");
    printf("                         Funções de remoção\n");
    printf("9-inicio.\n");
    printf("10-final.\n");
    printf("11-indicado Por posição.\n");
    printf("12-indicado Por matricula.\n");
    printf("                        Funçoes de tamanho\n");
    printf("13-vazia?.\n");
    printf("14-Cheia?.\n");
    printf("15-Tamanho.\n");
    printf("                             Outras\n");
    printf("16-Imprime.\n");
    printf("0- para sair.\n");
    printf("Entre com uma opção: ");
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