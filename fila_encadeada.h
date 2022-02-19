typedef struct tInfo
{
	char *nome_solicitante;
	char *telefone;
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

Fila* newFila();

tInfo* newInfo(char *nome, char *fone, double valor);

void destroiInfo(tInfo *info);

short filaVazia (Fila *L);

int adicionaFim (Fila *L, tInfo *data);

tInfo* retiraInicio (Fila *L);

void limpaFila(Fila *L);

void printInfo(tInfo *info,int posicao);

void printFila (Fila *L);

void insereConcerto(Fila *fila);
