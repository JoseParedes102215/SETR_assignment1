/**
@file main.c
@brief Ficheiro main para correr a aplicação de teste
 @author José Paredes Manuel Miranda
 @date 13 March 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

/**
@brief Função main
@details A função main corre um menu que permite a um utilizador interagir com o fifo.
*/
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
