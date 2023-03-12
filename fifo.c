#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // antes 10

// Estrutura do FIFO

struct FIFO{
    int buffer[MAX_SIZE];
    int head; // posição do primeiro elemento
    int tail; // posição do próximo elemento a ser inserido
    int cnt;    // numero de elementos no buffer
};

// inicializa o FIFO
void MyFIFOInit(struct FIFO *fifo){
		fifo->head=0;
		fifo->tail=0;
        fifo->cnt=0;
}

int isFifoFull(struct FIFO *fifo){
     return fifo->cnt==MAX_SIZE;
}

int isFifoEmpty(struct FIFO *fifo){
    return fifo->cnt==0;
}

void PrintFifo(struct FIFO *fifo){
    for (int i = 0; i < MAX_SIZE; i++){
        printf("%d ",fifo->buffer[i]);
    }
    printf("| tail = %d; head = %d\n",fifo->tail,fifo->head);
}

int MyFIFORemove(struct FIFO *fifo){
    if(isFifoEmpty(fifo) == 1){
        printf("erro a remover um elemento \n");
        printf("| tail = %d; head = %d\n",fifo->tail,fifo->head);
        return -1;
    }
    fifo->buffer[fifo->head] = -99;
    fifo->cnt--;
    fifo->head++;
    printf("Removido um elemento com sucesso \n");
    return 0;
}

int MyFIFOInsert(struct FIFO *fifo,int value){
    if(isFifoFull(fifo) == 1){
        printf("fifo cheio %d \n",value);
        return -1;
    }
    if (fifo->cnt<5 && fifo->tail==5){
        fifo->tail=0;
    }
    fifo->buffer[fifo->tail] = value;
    fifo->cnt++;

    fifo->tail= fifo->tail + 1;

    printf("Adicionou o elemento %d com sucesso \n",value);
    return 0;
}

int fifoSize(struct FIFO *fifo){
    printf("SIZE=%d\n",fifo->cnt);
    return fifo->cnt;

}
int main(){

struct FIFO fifo1;
MyFIFOInit(&fifo1);
for (int i = 0; i < MAX_SIZE;i++){
        MyFIFOInsert(&fifo1,2*i);
    }

    PrintFifo(&fifo1);
    printf("fifo full ? R: %d\n",isFifoFull(&fifo1));

    MyFIFORemove(&fifo1);
    PrintFifo(&fifo1);

    fifoSize(&fifo1);
    
    MyFIFORemove(&fifo1);
    PrintFifo(&fifo1);
    printf("fifo full ? R: %d\n",isFifoFull(&fifo1));

    MyFIFOInsert(&fifo1,69);
    PrintFifo(&fifo1);
    printf("fifo full ? R: %d\n",isFifoFull(&fifo1));
    
    MyFIFOInsert(&fifo1,69);
    PrintFifo(&fifo1);
    printf("fifo full ? R: %d\n",isFifoFull(&fifo1));
    
    fifoSize(&fifo1);

    MyFIFOInsert(&fifo1,69);
    PrintFifo(&fifo1);
    printf("fifo full ? R: %d\n",isFifoFull(&fifo1));
        
    MyFIFORemove(&fifo1);
    PrintFifo(&fifo1);
    printf("fifo full ? R: %d\n",isFifoFull(&fifo1));

return 0;
    
}
