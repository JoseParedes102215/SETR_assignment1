/**

@file main.c
@brief Ficheiro main para correr a aplicação de teste


 @author José Paredes Manuel Miranda
 @date 12 March 2023


*/


#include "fifo.h"


/**

@brief Função main
@details A função main corre um menu que permite a um utilizador interagir com o fifo.
*/

int main(){
    queue q1;
    int tecla,num,pr,out = 0;
    MyFifoInit(&q1,QUEUE_MAX_SIZE);
    while(1){
        if(out == 1)
            break;
        printf("\nMenu FIFO - Escolha uma das seguintes opçoes \n"
        "0 -> Adicionar novo inteiro\n"
        "1 -> Remover o elemento com maior prioridade\n"
        "2 -> Retorna o elemento mais antigo do fifo e nao o elimina\n"
        "3 -> Retorna o numero de elementos do fifo\n"
        "4 -> Printa todos os elementos do fifo \n"
        "5 -> Sair do Menu\n");
        while (scanf("%d", &tecla) != 1) {
            printf("Entrada inválida. Digite um número inteiro.\n");
            while (getchar() != '\n'); //limpa o buffer de entrada 
            }
        
            
        switch (tecla)
        {
        case 0:
            printf("Digite um número inteiro para adicionar ao fifo: ");
            while (scanf("%d", &num) != 1) {
            printf("Entrada inválida. Digite um número inteiro.\n");
            while (getchar() != '\n'); //limpa o buffer de entrada
            }
            printf("Digite um número inteiro para a prioridade do elemento do fifo: ");
            while (scanf("%d", &pr) != 1) {
            printf("Entrada inválida. Digite um número inteiro.\n");
            while (getchar() != '\n'); //limpa o buffer de entrada
            }
        

            MyFifoInsert(&q1,num,pr);
            break;
        case 1:
            printf("O elemento mais prioritario foi eliminado\n");
            MyFifoRemove(&q1);
            break;
        case 2:
            if(MyFifoPeep(&q1) == -1);
            else{
                printf("O elemento mais antigo e: %d\n",MyFifoPeep(&q1));
                }
            break;
        case 3:
            printf("tamanho do fifo: %d\n",MyFifoSize(&q1));
            break;
        case 4:
            printf("\n");
            printMyFifo(&q1);
            break;
        case 5:
            out = 1;
            break;
        default:
            printf("Insere um novo comando");
            break;
        }
    }
    return 0;
}
