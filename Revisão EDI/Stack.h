#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

/*
    TAD of Stack 
    a method of data acess
    where utilize the LIFO concept

*/

struct stack{
    int info;
    struct stack *next;

}; typedef struct stack Stack;

//Init the stack
void init(Stack **S){
    *S = NULL;
}
//Returns if the stack is empty or not
char isEmpty(Stack *S){
    return S == NULL;
}

//Return the top element from stack
int Top(Stack *S){

    if(!isEmpty(S))        
        return S->info;
    return -1;
}
//insert one element with the LIFO concept into the stack
void Push(Stack **S, int x){
    Stack *new = (Stack*)malloc(sizeof(Stack));
    new->info = x;
    new->prox = *S;
    *S = new;
}
//function for the remove one element with the LIFO concept into the stack
void pop(Stack **S, int *x){
    Stack *aux;
    if(!isEmpty(*S)){
        aux = *S;
        *x = (*S)->info;
        *S = (*S)->prox;
        free(aux);
    }
    else
        *x = -1;
}