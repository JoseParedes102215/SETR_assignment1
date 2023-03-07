#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Estrutura do FIFO
/*
typedef struct {
    int buffer[MAX_SIZE];
    int head; // posição do primeiro elemento
    int tail; // posição do próximo elemento a ser inserido
} FIFO;
*/

struct FIFO{
    int buffer[MAX_SIZE];
    int head; // posição do primeiro elemento
    int tail; // posição do próximo elemento a ser inserido
};

// inicializa o FIFO
void MyFIFOInit(struct FIFO *fifo){
		fifo->head=0;
		fifo->tail=0;
}

int main(){

    struct FIFO fifo1;
		MyFIFOInit(&fifo1);

    fifo1.buffer[0] = 11;
    printf("O primeiro elemento e %d",fifo1.buffer[0]);
    printf("\no head é %d",fifo1.head);
    return 0;
}
