/**
@file fifo.c
@brief Ficheiro fifo.c para as definições das funções
 @author José Paredes Manuel Miranda
 @date 12 March 2023
*/

#include <stdlib.h>
#include "fifo.h"

#include <stdio.h>


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
    //printf("| tail = %d; head = %d\n",fifo->tail,fifo->head); efeitos de teste
}

int MyFIFORemove(struct FIFO *fifo){
    if(isFifoEmpty(fifo) == 1){
        printf("Erro a remover um elemento \n");
        //printf("| tail = %d; head = %d\n",fifo->tail,fifo->head); efeitos de teste
        return -1;
    }
    int value =fifo->buffer[fifo->head];
    fifo->buffer[fifo->head] = -99;
    fifo->cnt--;
    fifo->head++;
    printf("Removido um elemento com sucesso \n");
    return value;
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
