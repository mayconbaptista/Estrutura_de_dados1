#include <stdio.h>
#include <stdlib.h>
#include "Posf.h"

int main (void)
{
    int n;
    char *inf;
    printf("Entre com o tamanho da expressão: ");
    scanf("%d",&n);
    inf = (char*) malloc ((n+1)*sizeof(char));
    if(inf == NULL)
    {
        printf("Ponteiro para vetor invalido!\n");
        exit(1);
    }

    printf("Entre com a expressão: ");
    setbuf(stdin, NULL);
    fgets(inf, 30, stdin);

    inf = Posfix(inf);
    printf("resposta: %s\n",inf);
    return 0;
}
