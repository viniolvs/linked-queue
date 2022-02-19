CC=gcc
CFLAGS=-Wall -g -std=c1x
TARGET=nomedoprograma
OBJS=fila_de_concertos.c fila_encadeada.c

nomedoprograma:$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -rf *.o
