
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_FAILED -3
#define QUEUE_EMPTY -2
#define QUEUE_FULL -1
#define QUEUE_MAX_SIZE 5


typedef struct node{
    int value;
    struct node *next;
} node;

typedef struct{
    node *head;
    node *tail;
    int size;

} queue;

void MyFifoInit(queue *q, int maxsize){
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

int MyFifoSize(queue *q){
    return q->size;
}

int MyFifoInsert(queue *q, int value){

    // create a new node
    node * newnode =  malloc(sizeof(node));
    if (newnode == NULL) {
        fprintf(stderr, "O malloc falhou\n");
        return -3; //malloc failed
    }
    else{
        if(q->size == QUEUE_MAX_SIZE){
            fprintf(stderr, "O Fifo está cheio\n");
            return -1;
        }
        q->size += 1;
        newnode->value = value;
        newnode->next = NULL;
        // if there is a tail, connect that tail to this new tail
        if(q->tail != NULL){
            q->tail->next = newnode;
        }
        q->tail = newnode;
        // make sure the head makes sense
        if (q->head == NULL){
            q->head = newnode;
        }
        return 1;
    }
    
}


int MyFifoRemove(queue *q){
    // check to see if the queue is empty
    if(q->head == NULL) {
        fprintf(stderr, "O Fifo está vazio\n");
        return -2; // FIFO EMPTY
    }
    node *tmp = q->head;
    //take it off
    q->head = q->head->next;
    if (q->head == NULL){
        q->tail = NULL;
    }
    q->size = q->size - 1;
    free(tmp);
    return 1;
}


void printMyFifo(queue *q){
    node *tmp = q->head;
    for (int i = 0; i < q->size; i++)
    {
        
        printf("%d\n",tmp->value);
        tmp = tmp->next;

    }
 
}

int MyFifoPeep(queue *q){
    return q->head->value; // return the oldest element
}


int main(){
    queue q1;
    int size = 10;
    MyFifoInit(&q1, size);

    MyFifoInsert(&q1, 56);
    MyFifoInsert(&q1, 57);
    MyFifoInsert(&q1, 58);
    MyFifoInsert(&q1, 59);
    MyFifoInsert(&q1, 60);
    printMyFifo(&q1);
    printf("\n");
    printf("size = %d \n",MyFifoSize(&q1));
    printf("\n");
    printf("oldest element = %d \n",MyFifoPeep(&q1));
    printf("\n");
    //MyFifoInsert(&q1, 12);
    MyFifoRemove(&q1);
    MyFifoRemove(&q1);
    MyFifoRemove(&q1);
    MyFifoRemove(&q1);
    //MyFifoRemove(&q1);
    //MyFifoRemove(&q1);
    //printf("\n%d\n",MyFifoSize(&q1));
    printMyFifo(&q1);
    printf("\n");
    printf("size = %d \n",MyFifoSize(&q1));
    printf("\n");
    printf("oldest element = %d \n",MyFifoPeep(&q1));
    printf("\n");
    //printMyFifo(&q1);
    return 0;
}