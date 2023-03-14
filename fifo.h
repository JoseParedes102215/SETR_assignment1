/**
@file fifo.h
@brief Biblioteca fifo.h para manipulação de um fifo
 @author José Paredes Manuel Miranda
 @date 13 March 2023
*/

#include <stdlib.h>

#ifndef FIFO_H
#define FIFO_H

#define MAX_SIZE 5 /**< Tamanho do fifo */

/**
@brief estrutura do fifo
*/
struct FIFO{
    int buffer[MAX_SIZE];   /**< Array para armazenar os elementos */
    int head;               /**< Variavel para guardar o primeiro elemento */
    int tail;               /**< Variavel para guardar o ultimo elemento */
    int cnt;                /**< Numero de elementos no buffer */
};

/**
@brief Inicialização da fila
@param fifo ponteiro para fifo a ser inicializado
*/
void MyFIFOInit(struct FIFO *fifo);

/**
@brief Verifica se o fifo está cheio
@param fifo Ponteiro para o fifo
@return 0 se o fifo estiver cheio
*/
int isFifoFull(struct FIFO *fifo);

/**
@brief Verifica se o fifo está vazio
@param fifo Ponteiro para o fifo
@return 0 se o fifo estiver vazio
*/
int isFifoEmpty(struct FIFO *fifo);

/**
@brief Imprime o conteúdo do fifo
@param fifo Ponteiro para o fifo
*/
void PrintFifo(struct FIFO *fifo);

/**
@brief Remove o valor mais antigo da fila
@param fifo Ponteiro para o fifo
@return Valor removido em caso de sucesso, -1 se o fifo estiver vazio
*/
int MyFIFORemove(struct FIFO *fifo);

/**
@brief Insere um valor na fila
@param fifo Ponteiro para o fifo
@param value Inteiro a ser inserido no fifo
@return 1 em caso de sucesso, -1 se o fifo estiver vazio
*/
int MyFIFOInsert(struct FIFO *fifo,int value);

/**
@brief Retorna o numero de elementos a serem removidos do fifo
@param fifo Ponteiro para o fifo
@return Numero de elementos a serem removidos do fifo
*/
int fifoSize(struct FIFO *fifo);

#endif