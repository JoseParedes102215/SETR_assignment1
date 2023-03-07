#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // antes 10

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

<<<<<<< HEAD
int isFifoFull(*FIFO fifo){
    return ((fifo>tail - 1 ) ==  MAX_SIZE);
}

int isFifoEmpty(){
    return (fifo->tail == fifo->head);
}


void MyFIFOInsert(*FIFO fifo,int value){
    if(isFifoFull(fifo) == 1){
        return -1;
    }
    fifo.buffer[tail] = value;
    fifo.tail +=  1;
    return 0;
}



// inicializa o FIFO
void MyFIFOInit(struct FIFO *fifo){
		fifo->head=0;
		fifo->tail=0;
}


int main(){
/*
struct FIFO fifo1;
MyFIFOInit(&fifo1);
    for (int i = 0; i < MAX_SIZE + 1 ;i++)
    {
        if(MyFIFOInsert(fifo1,2*i) == 0);

    }
   
    fifo1.buffer[0] = 11;
    printf("O primeiro elemento e %d",fifo1.buffer[0]);
    printf("\no head é %d",fifo1.head);
    return 0;

*/
    
}
