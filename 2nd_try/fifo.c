/**

@file fifo.c
@brief Ficheiro fifo.c para as definições das funções


 @author José Paredes Manuel Miranda
 @date 12 March 2023


*/


#include "fifo.h"

void MyFifoInit(queue *q, int maxsize){
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

int MyFifoSize(queue *q){
    return q->size;
}

int MyFifoInsert(queue *q, int value){

    //cria um novo nodo
    node * newnode =  malloc(sizeof(node));
    if (newnode == NULL) {
        fprintf(stderr, "O malloc falhou\n");
        return -3; //malloc falhou
    }
    else{
        if(q->size == QUEUE_MAX_SIZE){
            fprintf(stderr, "O Fifo está cheio\n");
            return -1;
        }
        q->size += 1;
        newnode->value = value;
        newnode->next = NULL;
        // Se já existir um tail , conectar essa tail à nova
        if(q->tail != NULL){
            q->tail->next = newnode;
        }
        q->tail = newnode;
        //Assegurar que o head faz sentido
        if (q->head == NULL){
            q->head = newnode;
        }
        return 1;
    }
    
}


int MyFifoRemove(queue *q){
    // Verificar se o fifo está vazio
    if(q->head == NULL) {
        fprintf(stderr, "O Fifo está vazio\n");
        return -2; /** fifo vazio*/
    }
    node *tmp = q->head;
    //Retira o elemento do fifo
    q->head = q->head->next;
    if (q->head == NULL){
        q->tail = NULL;
    }
    q->size = q->size - 1;
    free(tmp);
    return 1;
}


void printMyFifo(queue *q){
    node *tmp2 = q->head;
    for (int i = 0; i < q->size; i++)
    {
        
        printf("%d\n",tmp2->value);
        tmp2 = tmp2->next;

    }
 
}

int MyFifoPeep(queue *q){
    return q->head->value; //retorna o elemento mais antigo
}


