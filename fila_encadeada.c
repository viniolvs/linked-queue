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
	else
	{
		printf("\nFalha na alocação!\n");
	}
	
	return fila;
}

//aloca tInfo;
void newInfo(tInfo *info )//(char *nome, char *fone, double valor)
{
	info = (tInfo*)malloc(sizeof(tInfo));
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
    else 
    {
		new->info = info;
		new->info->nome_solicitante = info->nome_solicitante;
		new->info->data_entrega = info->data_entrega;
		new->info->telefone = info->telefone;
		new->info->valor_conserto = info->valor_conserto;
		
        if (filaVazia(fila))
		{
			fila->head = fila->tail = new;
			fila->head->next = fila->tail->next = NULL;
    	}
		else 
		{
			fila->tail->next = new;
			fila->tail = new;
			fila->tail->next = NULL;
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
	tElement *atual, *anterior;
	if (filaVazia(fila))
		return;
	else
	{
		fila->tamanho = 0;
		atual = fila->head;
		while (atual !=NULL)
		{
			anterior = atual;
			free(anterior->info->nome_solicitante);
			free(anterior->info->telefone);
			atual = atual->next;
		}
	}
}

void printInfo(tInfo *info, int posicao)
{
	printf("Nome do solicitante: %s\n",info->nome_solicitante);
	printf("Telefone: %s\n",info->telefone);
	printf("Data de Entrega: %s\n",info->data_entrega);
	printf("Valor do conserto %.2lf\n",info->valor_conserto);
	printf("Posição na fila: %d\n",posicao);
}


void printFila (Fila *fila)
{
	tElement *aux;
	aux = fila->head;
	int posicao=1;

	if (filaVazia(fila))
		printf("\nFila Vazia!\n");
	
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
void insereConcerto(Fila *fila, tInfo *info)
{
    char *nome, *telefone;
    double valor;
    
	nome = (char*)malloc(30*sizeof(char));
	telefone = (char*)malloc(15*sizeof(char));

	printf("\nDigite o valor do conserto: ");
    scanf("%lf",&valor);
	getchar();
    printf("Digite o nome do solicitante: ");
    fgets(nome,30,stdin);
    printf("Digite o telefone do solicitante: ");
    scanf("%s",telefone);
	
	nome[strcspn(nome,"\n")] = 0;
    
	info->nome_solicitante = nome;
	info->telefone = telefone;
	info->valor_conserto = valor;
	time_t t;
	time(&t);
	t = t+(60*60*24*14);
	info->data_entrega = ctime(&t);
	info->data_entrega[strcspn(info->data_entrega,"\n")] = 0;

    adicionaFim(fila, info);
}
