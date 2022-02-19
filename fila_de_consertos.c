#include "fila_encadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Fila *fila;

//Lê os dados do concerto e insere na fila
void insereConcerto()
{
    char *nome, *telefone;
    double valor;

    printf("Digite o nome do solicitante: ");
    fgets(nome,30,stdin);
    printf("Digite o telefone do solicitante: ");
    fgets(telefone,15,stdin);
    printf("Digite o valor do conserto: ");
    scanf("%lf",&valor);

    nome[strlen(nome)-1] = '\0';
    telefone[strlen(telefone)-1] = '\0';
    tInfo *info = newInfo(nome,telefone,valor);
    adicionaFim(fila, info);
    return;
}

int main(int argc, char const *argv[])
{
    newFila(fila);
    while (1)
    {
        int op;
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
                insereConcerto(fila);
            break;

            case 2:
                retiraInicio(fila);
            break;

            case 3:
                limpaFila(fila);
            break;

            case 4:
                printFila(fila);
            break;
        }
    }
    return 0;
}

