#include<stdio.h>
#include<stdlib.h>//para o malloc
#include<string.h>
#include<conio.h>
#include "stackGenList.h"
/*  --- Exercicios_-_Listas_Generalizadas --- */

/* Exercicio 1*/
void Destruir(ListaGen **L){
	if(!Nula(*L)){
		if(Atomo(*L))
			free(*L);
		else{
			Destruir(&(*L)->no.lista.cabeca);
			Destruir(&(*L)->no.lista.cauda);
			free(*L);
			*L = NULL;
		}
	}
}

/* Exercicio 2*/
    //duplicar do Chico
ListaGen *dup(ListaGen *L){
	if(Nula(L))
		return NULL;
	if(Atomo(L))
		return CriaT(L->no.info);
	return Cons(dup(Head(L)),dup(Tail(L)));
}

/* Exercicio 3*/
char Comparar(ListaGen *L, ListaGen *L2){
	if(!Nula(L) && !Nula(L2)){
		if(L->terminal == L2->terminal){
			if(!L->terminal)
				return Comparar(Head(L),Head(L2)) && Comparar(Tail(L),Tail(L2));		

			return strcmp(L->no.info,L2->no.info)==0;
		}
		return 0;
	}
	else if(Nula(L) && Nula(L2))
		return 1;
	return 0;
}
/* Exercicio 3:- Version Vinicius */
char igual(ListaGen *L, ListaGen *H){
    if(Nula(L) && Nula(H))
        return 0;
    else if(!Nula(L) && !Nula(H)){
        if(!Atomo(H) && !Atomo(L))
            return igual(Head(L),Head(H)) && igual(Tail(L),Tail(H));
        if((Atomo(H) && !Atomo(L)) || (Atomo(L) && !Atomo(H)))
            return 0;
        if(Atomo(H) && Atomo(L) && stricmp(H->no.info,L->no.info)==0)
            return 1;
    }
    return 0;

}

/* Exercicio 4.a) */
void len(ListaGen *L, int *comp){
	if(!Nula(L)){
        if (!Atomo(L))
            *comp += 1;
        len(Tail(L),*&comp);
    }
    
}
/* Exercicio 4.b) */
void deph(ListaGen *L, int nivel, int *maior){
	if(!Nula(L)){

		if(Atomo(L))
			printf("%s",L->no.info);
		else{
            if(nivel > *maior)
                *maior = nivel;
			deph(Head(L), nivel+1, &*maior);
			deph(Tail(L), nivel, &*maior);
		}
		
	}
}


/*  Exercicio 5   */
//Sempre antes do append duplicar as listar que estão sendo passadas
ListaGen* Append(ListaGen *L, ListaGen *M){
    ListaGen *aux;
    aux = L;
    // !Nula(Tail(L)) pode ser substituida na condição do WHILE
    while (!Nula(Tail(aux)))
        aux = Tail(aux);
    aux->no.lista.cauda = M;
    return L;
}

/*  Exercicio 6   */
void Replace(char *O, char *N, ListaGen *L){
    if(!Nula(L)){
        if(Atomo(L) && stricmp(L->no.info,O) == 0)
            strcpy(L->no.info,N);
        else{
           Replace(O,N,Head(L));
           Replace(O,N,Tail(L)); 
        }        
    }   
}



/*  Exercicio 7   */
ListaGen *TopLevel(ListaGen *L){
    ListaGen *aux1 = NULL, *aux2;
    
    while (!Nula(L)){
        if(Atomo(Head(L))){       
            if(Nula(aux1)){
                aux1 = Cons(Head(L),NULL);
                aux2 = aux1;
            }
            else{
                aux1->no.lista.cauda = Cons(Head(L),NULL);
                aux1 = Tail(aux1);
            }
        }
        L = Tail(L);    
    }
    return aux2;
}

/*  Exercicio 8  */
ListaGen* Nth(ListaGen *L, int n){
    while (!Nula(L) && n){
        if(Atomo(Head(L)))
            n--;
        if(n)
            L = Tail(L);    
    }
    return Head(L);
}
/* Exercicio 9:-) */
void Plain(ListaGen *L, ListaGen **L2)
{
    ListaGen  *aux;
    if(!Nula(L))
    {
        if(Atomo(L))
        {
            if(Nula(*L2))
                *L2 = Cons(CriaT(L->no.info),NULL);
            else
            {
                aux = *L2;
                while(!Nula(Tail(aux)))
                    aux = Tail(aux);
                aux->no.lista.cauda = Cons(CriaT(L->no.info),NULL);
            }
        }   
        else
        {
            Plain(Head(L),&*L2);
            Plain(Tail(L),&*L2);
        }
    }
}
/*
//N = [a,[b,[c],b],e]
//Após a func exlcuiChave(N, "b");
//N = [a,[,[c],],e]
void excluiChave(ListaGen **L, char chave[])
{
	if(!Nula(L))
	{
        if(!Atomo(L) && Atomo(Head(L)))
        {
            if(stricmp(chave,L->no.info) == 0)
            {
                free(Head(L));
                L->no.lista.cabeca = NULL;
            }
        }
        if(!Atomo(L)) 
        {
            excluiChave(&(Head(*L))),chave);
            excluiChave(&(Tail(*L))),chave);
        }
    }
}*/

int main(void){

    ListaGen *L, *M,*_L,*_M ,*aux, *N, *Plain_N = NULL,*Nesimo = NULL, *TopLvl = NULL;
    int maior_nivel = 0, comp = 0, res = 0;
    char chave[8];
    //L = [[a,b],c]
    L = Cons(Cons(CriaT("a"),Cons(CriaT("b"),NULL)),Cons(CriaT("c"),NULL));
	_L = dup(L);
    printf("Lista {L}: ");
    Exibir(L);printf("\n\n");
	getch();
    
    //M = [[a,b]]
    M = Cons(Cons(CriaT("a"),Cons(CriaT("b"),NULL)),NULL);
    _M = dup(M);
    printf("Lista {M}: ");
    Exibir(M);printf("\n\n");
    getch();
    //N = [a,[b,[c],b],e]
    N = Cons(CriaT("a"),Cons(Cons(CriaT("b"),Cons(Cons(CriaT("c"),NULL),Cons(CriaT("b"),NULL))),Cons(CriaT("e"),NULL)));
    printf("Lista {N}: ");
    Exibir(N);printf("\n\n");
    getch();


    
    /*strcpy(chave,"b");
    excluiChave(&N,chave);
    printf("\nLista [N] apos excluir todos os \"b\": ");
    Exibir(N); printf("\n\n");
    getch();*/

    /*
    //Retorna o n-ésimo elemento existente no top-level de L
    Nesimo = Nth(N,1);
    if(Atomo(Nesimo))
        printf("\nN-esimo item: %s",Nesimo->no.info);
    else
        printf("\ne nulo");
    

    

    
    //Concatenação de ListaGen
    aux = Append(_L,_M);
    printf("Juncao de {L} && {M}: ");
    Exibir(aux);printf("\n\n");
    getch();
    aux = Append(_L,dup(N));
    printf("Juncao de {L} && {M} && {N}: ");
    Exibir(aux);printf("\n\n");
    getch();
    


    //Modifica todas as palavras "a" para "eu"
    //[[a,b],c,[a,b],a,[b,[c],d],e]
    printf("Replace \"a\" \"Eu\": ");
    Replace("a","Eu",aux);
    Exibir(aux);printf("\n\n");
    getch();
    


    
    
    //retorna uma lista contendo  apenas  os
    //elementos  que  se encontram no top-level
    //de uma lista L
    printf(" Top Level de Aux:\n ");
    TopLvl = TopLevel(aux);
    Exibir(TopLvl);printf("\n\n");
    getch();

	//Tranforma uma lista L em uma lista de profundidade 1
    Plain(N,&Plain_N);
    printf("\nPlain da Lista [N]: ");
    Exibir(Plain_N);
    getch();
    printf("\n\n");


    
    //Deph ListaGen - Profundidade
    printf("Profundidade da ListaGen [aux]:\n");
    deph(aux,1,&maior_nivel);
    printf("Profundidade: %d\n",maior_nivel);

    //Len Lista Gen - Comprimento
    printf("Comprimento da ListaGen [aux]: ");
    len(aux,&comp);
    printf("\nComprimento: %d\n",comp);
    */


    return 1;
}
