#include "fila_encadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Fila fila;

int main()
{
    newFila(&fila);
    int op = 0;
    while (1)
    {
        if(op!=4)
            system("clear");
        printf ("\n==========MENU===========\n");
        printf ("[0] Sair\n");
        printf ("[1] Nova solicitação de conserto\n");
        printf ("[2] Remover solicitação de conserto\n");
        printf ("[3] Limpar fila de consertos\n");
        printf ("[4] Exibir fila de consertos\n");

        printf("Digite o número da operação desejada: ");
        scanf("%d",&op);

        switch (op)
        {
            case 0:
                exit(0);
            break;
                
            case 1:
                insereConcerto(&fila);
            break;

            case 2:
                retiraInicio(&fila);
            break;

            case 3:
                limpaFila(&fila);
            break;

            case 4:
                printFila(fila);
            break;
        }
    }
    return 0;
}

