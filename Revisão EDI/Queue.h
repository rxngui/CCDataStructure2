#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

struct queue{
    int info;
    struct queue *next;
};typedef struct queue Queue;

//Initialize the queue 
void Init(Queue **Q){
    *Q = NULL;
}

char QisEmpty(Queue *Q){
    return *Q == NULL;
}
//Enqueue new element into the final of Queue with the concept FIFO
void Enqueue(Queue **Q, int x){
    Queue *new = (Queue*)malloc(sizeof(Queue)), *aux;
    new->next = NULL;
    new->info = x;
    if(QisEmpty(*Q))
        *Q = new;
    else{
        aux = *Q;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = new;
    }
}

//Dequeue the first element of queue for the element "x" with reference
void Dequeue(Queue **Q, int *x){
    Queue *aux;
    if(QisEmpty(*Q)){
        aux = *Q;
        *x = (*Q)->info;
        *Q = (*Q)->next;
        free(aux);
    }
    else
        *x = -1;
}

