#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fila_encadeada.h"

Fila* newFila()
{
	Fila *fila;
	
	fila = (Fila*)malloc(sizeof(Fila));
	if (fila != NULL)
	{
		fila->tamanho=0;
		fila->head = fila->tail = NULL;
	}
	return fila;
}

//aloca tInfo;
tInfo* newInfo(char *nome, char *fone, double valor)
{
	tInfo *info;
	info = (tInfo*)malloc(sizeof(tInfo));
	info->nome_solicitante = nome;
	info->telefone = fone;
	info->valor_conserto = valor;
	time_t t;
	time(&t);
	t = t+(60*60*24*14);
	info->data_entrega = ctime(&t);
	return info;
}

//destroi um tInfo
void destroiInfo(tInfo *info)
{
	free(info);
}

short filaVazia (Fila *fila)
{
	if (fila->tamanho==0)
		return 1;
	else 
		return 0;
}

//alocar info com newinfo() antes de pasar para este método
int adicionaFim (Fila *fila, tInfo *info)
{
	tElement *new;
	
	new = (tElement*)malloc(sizeof(tElement));
	if (new==NULL)
	{
		printf("Malloc Error\n");
		exit(1);
	}
    else if (filaVazia(fila))
    {
        new->info = info;
        fila->head = fila->tail = new;
		fila->head->next = fila->tail->next = NULL;
		fila->tamanho++;
        return EXIT_SUCCESS;
    }
    
	else 
	{
        new->info = info;
		fila->tail->next = new;
        fila->tail = new;
		fila->tail->next = NULL;
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
	tElement *atual, *anterior;
	if (filaVazia(fila))
		return;
	else
	{
		atual = fila->head;
		while (atual !=NULL)
		{
			anterior = atual;
			atual = atual->next;
			destroiInfo(anterior->info);
			free(anterior);
		}
		fila->head = fila->tail = NULL;
		fila->head->next = fila->tail->next = NULL;
		fila->tamanho = 0;
	}
}

void printInfo(tInfo *info, int posicao)
{
	printf("Nome do solicitante: %s\n",info->nome_solicitante);
	printf("Telefone: %s\n",info->telefone);

	info->data_entrega[strlen(info->data_entrega)-1] = '\0';
	printf("Data de Entrega: %s\n",info->data_entrega);
	printf("Valor do conserto %.2lf\n",info->valor_conserto);
	printf("Posição na fila: %d",posicao);
}


void printFila (Fila *fila)
{
	tElement *aux;
	aux = fila->head;
	int posicao=1;

	if (filaVazia(fila))
		printf("Fila Vazia!\n");
	
	else
	{
		printf("--------------------------------------\n");
		printf("Concertos na fila: \n");
		while (aux != NULL)
		{
			printInfo(aux->info, posicao++);
			if (aux->next)
				printf("\n");
			aux = aux->next;
		}
		printf("--------------------------------------\n");
	}
}

//Lê os dados do concerto e insere na fila
void insereConcerto(Fila *fila)
{
    char nome[30], *telefone;
    double valor;
    
	printf("Digite o valor do conserto: ");
    scanf("%lf",&valor);
	getchar();
    printf("Digite o nome do solicitante: ");
    fgets(nome,30,stdin);
    printf("Digite o telefone do solicitante: ");
    scanf("%s",telefone);
    
    tInfo *info = newInfo(nome,telefone,valor);
    adicionaFim(fila, info);
}
