typedef struct tInfo
{
	char nome_solicitante[30];
	char telefone[45];
    char *data_entrega;
    double valor_conserto;
}tInfo;

typedef struct tElement
{
	tInfo *info;
	struct tElement *next;
}tElement;

typedef struct Fila
{
	tElement *head;
    tElement *tail;
	int tamanho;
}Fila;

void newFila(Fila *fila);

void newInfo(tInfo *info);

short filaVazia (Fila *fila);

int adicionaFim (Fila *fila, tInfo info);

tInfo* retiraInicio (Fila *fila);

void limpaFila(Fila *fila);

void printInfo(tInfo *info,int posicao);

void printFila (Fila fila);

void insereConcerto(Fila *fila);
