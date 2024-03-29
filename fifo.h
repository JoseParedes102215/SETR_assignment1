/**

@file fifo.h
@brief Biblioteca fifo.h para manipulação de um fifo


 @author José Paredes Manuel Miranda
 @date 12 March 2023


*/


 
#ifndef FIFO_H
#define FIFO_H

#include <stdlib.h>
#include <stdio.h>

#define MALLOC_FAILED -3
#define QUEUE_EMPTY -2
#define QUEUE_FULL -1
#define QUEUE_MAX_SIZE 5

/**

@brief Nodo do fifo
@details O Nodo representa a informação de um elemento do fifo
*/
typedef struct node{
int value; /**< Valor inteiro armazenado no nodo */
int priority; /**< Valor da prioridade do elemento */
struct node *next; /**< Ponteiro para o próximo nodo */
} node;

/**
@brief Fila
@details A Fila é a estrutura a partir do qual acedemos à lista ligada.
*/
typedef struct{
node *head; /**< Ponteiro para o primeiro nodo da fila */
node *tail; /**< Ponteiro para o último nodo */
int size; /**< Tamanho atual do fifo */

} queue;

/**

@brief Inicialização da fila
@param q Ponteiro para a fila
@param maxsize Tamanho máximo do fifo
*/
void MyFifoInit(queue *q, int maxsize);
/**

@brief Retorna o tamanho da fila
@param q Ponteiro para a fila
@return Tamanho atual da fila
*/
int MyFifoSize(queue *q);
/**

@brief Insere um valor na fila
@param q Ponteiro para a fila
@param value Valor a ser inserido
@param priority Indicaçao da prioridade do elemento a adicionar
@return 0 em caso de sucesso, QUEUE_FULL se a fila estiver cheia, MALLOC_FAILED se houver falha na alocação de memória
*/
int MyFifoInsert(queue *q, int value,int priority);
/**

@brief Remove o valor mais antigo da fila
@param q Ponteiro para a fila
@return 0 em caso de sucesso, QUEUE_EMPTY se a fila estiver vazia
*/
int MyFifoRemove(queue *q);
/**

@brief Imprime todos os valores da fila
@param q Ponteiro para a fila
*/
void printMyFifo(queue *q);
/**

@brief Retorna o valor mais antigo da fila sem removê-lo
@param q Ponteiro para a fila
@return Valor mais antigo em caso de sucesso, QUEUE_EMPTY se a fila estiver vazia
*/
int MyFifoPeep(queue *q);

/**
@brief Retorna o indice do elemento com maior prioridade
@param q Ponteiro para a fila
@return indice do elemento com maior prioridade
*/
int MyFifoCheckPriority(queue *q);
#endif // FIFO_H