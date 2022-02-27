#ifndef TINFO_T
#define TINFO_T 1
//tipo Info, armazena as informações contidas em cada elemento da fila
typedef struct tInfo
{
	char nome_solicitante[31];
	char telefone[15];
	char modelo[21];
    char *data_entrega;
    double valor_conserto;
}tInfo;
#endif

#ifndef TELEMENT_T
#define TELEMENT_T 1
//tipo elemento, representa os nós da fila encadeada
typedef struct tElement
{
	tInfo *info;
	struct tElement *next;
}tElement;
#endif

#ifndef FILA_T
#define FILA_T 1
//Tipo fila
typedef struct Fila
{
	tElement *head;
    tElement *tail;
	int tamanho;
}Fila;
#endif

//inicializa uma fila
void newFila(Fila *fila);

//verifica se uma fila está vazia
short filaVazia (Fila *fila);

//adiciona um novo  elemento no fim de uma fila
int adicionaFim (Fila *fila, tInfo info);

//retira e retorna o primeiro elemento da fila
tInfo* retiraInicio (Fila *fila);

//remove todos os elementos de uma fila
void limpaFila(Fila *fila);

//escreve no terminal os dados do tipo tInfo
void printInfo(tInfo *info,int posicao);

//escreve todos os elementos da fila
void printFila (Fila fila);

//pede ao usuário os dados de um novo concerto e insere-o no fim da fila
void insereConcerto(Fila *fila);
