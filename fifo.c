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


// inicializa o FIFO
void MyFIFOInit(struct FIFO *fifo){
		fifo->head=0;
		fifo->tail=0;
}



int isFifoFull(struct FIFO *fifo){
    return ((fifo->tail) ==  MAX_SIZE);
     
}

int isFifoEmpty(struct FIFO *fifo){
    return (fifo->tail == fifo->head);
}


int MyFIFOInsert(struct FIFO *fifo, int value){
    if(isFifoFull(fifo) == 1){
        return -1;
    }
    fifo->buffer[fifo->tail] = value;
    fifo->tail =   fifo->tail + 1;
    return 0;
}

void PrintFifo(struct FIFO *fifo){
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d\n",fifo->buffer[i]);
    }
    
}

int main(){

struct FIFO fifo1;
MyFIFOInit(&fifo1);
for (int i = 0; i < MAX_SIZE + 1 ;i++)
    {
        if(MyFIFOInsert(&fifo1,2*i) == 0){
            printf("Adicionou o elemento com sucesso \n");
        }

        else{
            printf("fifo cheio \n");
        }
    }

    PrintFifo(&fifo1);

   /*
    fifo1.buffer[0] = 11;
    printf("O primeiro elemento e %d",fifo1.buffer[0]);
    printf("\no head é %d",fifo1.head);
    
*/
return 0;
    
}
