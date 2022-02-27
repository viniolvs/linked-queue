//ATV 01 ESTRUTURA DE DADOS
//Vinicius de Oliveira Silva

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fila_encadeada.h"

void newFila(Fila *fila)
{	
	fila->head = NULL;
	fila->tail = NULL;
	fila->tamanho=0;
}

short filaVazia (Fila *fila)
{
	if (fila->tamanho==0)
		return 1;
	else 
		return 0;
}

int adicionaFim (Fila *fila, tInfo info)
{
	tElement *new;
	tElement *aux;
	
	new = (tElement*)malloc(sizeof(tElement));
	if (new==NULL)
	{
		printf("Malloc Error\n");
		return EXIT_FAILURE;
	}
    else 
    {
		new->info = (tInfo*)malloc(sizeof(tInfo));
		*new->info = info;
        if (filaVazia(fila))
		{
			fila->head = new;
			fila->tail = new;
    	}
		else 
		{
			aux = fila->tail;
			fila->tail = new;
			aux->next = new;
		}
		fila->tamanho++;
		return EXIT_SUCCESS;
	}
}

tInfo* retiraInicio (Fila *fila)
{	
    tInfo *retorno;
	if (filaVazia(fila))
		return NULL;

    else if (fila->tamanho == 1)
    {
        retorno = fila->head->info;
        free(fila->head);
        fila->head = NULL; 
		fila->tail = NULL;
		fila->tamanho--;
    }
	else
	{
        tElement *out;
		out = fila->head;
        fila->head = fila->head->next;
		fila->tamanho--;
        retorno = out->info;
		free(out);
		return retorno;
	}
}
		
void limpaFila(Fila *fila)
{
	if (filaVazia(fila))
		return;
	else
	{	
		while (fila->tamanho > 0)
		{
			retiraInicio(fila);
		}
	}
}

void printInfo(tInfo *info, int posicao)
{
	printf("Posição na fila: %5.d\n",posicao);
	printf("Nome do solicitante: %s\n",info->nome_solicitante);
	printf("Modelo do computador: %s\n",info->modelo);
	printf("Telefone: %s\n",info->telefone);
	printf("Data de Entrega: %s\n",info->data_entrega);
	printf("Valor do conserto %.2lf\n",info->valor_conserto);
}

void printFila (Fila fila)
{
	if (filaVazia(&fila))
		printf("\nFila Vazia!\n");
	
	else
	{
		tElement *aux;
		aux = fila.head;
		int posicao=1;
		printf("\n       CONCERTOS NA FILA: \n");
		printf("--------------------------------------\n");
		while (posicao < fila.tamanho+1)
		{
			printInfo(aux->info, posicao++);
			if (aux->next){
				printf("\n");
				aux = aux->next;
			}
		}
		printf("--------------------------------------\n");
	}
}

void insereConcerto(Fila *fila)
{
	system("clear");
	tInfo info;
	printf("\nDigite o valor do conserto: ");
    scanf("%lf",&info.valor_conserto);
	getchar();
    printf("Digite o nome do solicitante: ");
    fgets(info.nome_solicitante,30,stdin);
	printf("Digite o modelo do computador: ");
	fgets(info.modelo,20,stdin);
    printf("Digite o telefone do solicitante: ");
    scanf("%s",info.telefone);
	
	
	time_t t;
	time(&t);
	t = t+(60*60*24*14);
	info.data_entrega = ctime(&t);
	//remove a quebra de linha do final da string
	info.data_entrega[strcspn(info.data_entrega,"\n")] = 0;
	info.nome_solicitante[strcspn(info.nome_solicitante,"\n")] = 0;
	info.modelo[strcspn(info.modelo,"\n")] = 0;	
    adicionaFim(fila, info);
	
	printf("\nA data estimada de entrega do computador é:\n%s\n",info.data_entrega);
}
