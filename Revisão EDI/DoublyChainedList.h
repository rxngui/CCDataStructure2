#include<stdio.h>
#include<stdlib.h>


struct box
{
    int info;
    struct box *next, *prev;
};
typedef struct box Box;

struct descriptor{
    Box *start, *end;
};
typedef struct descriptor Descriptor;

void initDL(Descriptor *DL){
    (*DL).start = (*DL).end = NULL;
}
char isEmptyDL(Descriptor DL){
	return DL.inicio == NULL;
}

Box *newBox(int x){
    Box *nBox = (Box*)malloc(sizeof(Box));
    nBox->info = x;
    nBox->next = nBox->prev = NULL;
    return nBox; 
}
void insertStart(Descriptor *DL, int x){
    Box *new = newBox(x);
    if(isEmptyDL(*DL))
        (*DL).start = (*DL).end = new;
    else
    {
        new->next = (*DL).start;
        (*DL).start->prev = new;
        (*DL).start = new;
    }
}

void insertEnd(Descriptor *DL, int x){
    Box *new = newBox(x);

    if(isEmptyDL(*DL))
        (*DL).start = (*DL).end = new;
    else
    {
        new->prev = (*DL).end;
        (*DL).end->next = new;
        (*DL).end = new;
    }
}

Box *searchDL(Descriptor DL, int x){
    while(DL.start != NULL && x != DL.start->info)
        DL.start = DL.start->next;
    return DL.start;
}

void exclude(Descriptor *DL, int x){
    Box *pos = searchDL(*DL, x);

    if(pos != NULL){
        if(pos == (*DL).start){
            (*DL).start = (*DL).start->next;
            isEmptyDL(*DL) ? initDL(&*DL) : (*DL).start->prev = NULL;
        }
        else if(pos == (*DL).end){
            (*DL).end = (*DL).end->prev;
            (*DL).end->next = NULL;
        }
        else{
            pos->prev->next = pos->next;
            pos->next->prev = pos->prev;
        }
        free(pos);
    }
    else
        printf("\nThe element is not found!\n");

}

void showDL(Descriptor DL){
    printf("|Start ");
    while(!isEmptyDL(DL)){
        printf("<-[%d]->", DL.start->info);
        DL.start = DL.start->next;
    }
    printf(" End|\n");
}