#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include "listaGenTAD.h"
/*
    TAD of Stack Lista Gen
    a method of data acess
    where utilize the LIFO concept

*/

struct stack{
    ListaGen *info;
    struct stack *next;

}; typedef struct stack Stack;

//Init the stack
void Init(Stack **S){
    *S = NULL;
}
//Returns if the stack is empty or not
char isEmpty(Stack *S){
    return S == NULL;
}

//Return the top element from stack
ListaGen *Top(Stack *S){

    if(!isEmpty(S))        
        return S->info;
    return NULL;
}
//insert one element with the LIFO concept into the stack
void Push(Stack **S, ListaGen *x){
    Stack *new = (Stack*)malloc(sizeof(Stack));
    new->info = x;
    new->next = *S;
    *S = new;
}
//function for the remove one element with the LIFO concept into the stack
void Pop(Stack **S, ListaGen **x){
    Stack *aux;
    if(!isEmpty(*S)){
        aux = *S;
        *x = (*S)->info;
        *S = (*S)->next;
        free(aux);
    }
    else
        *x = NULL;
}