#include<stdio.h>
#include<stdlib.h>


struct priorityqueue{
    int info, priority;
    struct priorityqueue *next;
};
typedef struct priorityqueue PriorQueue;

void init(PriorQueue **QP){
    *QP = NULL;
}
void Enqueue(PriorQueue **QP, int x, int p){
    PriorQueue *new = (PriorQueue*)malloc(sizeof(PriorQueue));
    new->next = NULL;
    
}