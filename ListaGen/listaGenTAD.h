

struct reg_lista{
	struct listagen *cabeca;
	struct listagen *cauda;
};
union info_lista{
	char info[8];
	struct reg_lista lista;
};
struct listagen{
	char terminal;
	union info_lista no;
};
typedef struct listagen ListaGen;

char Nula(ListaGen *L){
	return L == NULL;
}
//criar caixinha de Atomo
//lembra que char *info == char info[], por isso o strcpy ficou como esta
ListaGen *CriaT(char *info){ 
	ListaGen *L = (ListaGen*)malloc(sizeof(ListaGen));
	L->terminal = 1;
	strcpy(L->no.info, info);
	return L;
}
char Atomo(ListaGen *L){
	return !Nula(L) && L->terminal;
}
//criar Lista
ListaGen *Cons(ListaGen *H, ListaGen *T){
	if(Atomo(T)){
		//printf("Cons: segundo argumento nao pode ser um atomo!");
		return NULL;
	}
	else{
		ListaGen *L = (ListaGen*)malloc(sizeof(ListaGen));
		L->terminal = 0;
		L->no.lista.cabeca = H;
		L->no.lista.cauda = T;
		return L;
	}
}
//retornar cabe�a da Lista
ListaGen *Head(ListaGen *L){
	if(Nula(L) || Atomo(L)){
		//printf("Head: argumento deve ser lista nao vazia!");
		return NULL;
	}
	else
		return L->no.lista.cabeca;
}
ListaGen *Tail(ListaGen *L){
	if(Nula(L) || Atomo(L)){
		//printf("Tail: argumento deve ser lista nao vazia!");
		return NULL;
	}
	else
		return L->no.lista.cauda;
}
void Exibir(ListaGen *L){
    if(Atomo(L)){
        printf("%s",L->no.info);
    }
    else{
        printf("[");
        while (!Nula(L))
        {
            Exibir(Head(L));
            L = Tail(L);
            if(!Nula(L))
                printf(",");
        }
        printf("]");
    }
}
void ExibeAtomo_R(ListaGen *L){
	if(!Nula(L)){
		if(Atomo(L))
			printf("%s",L->no.info);
		else{
			ExibeAtomo_R(Head(L));
			ExibeAtomo_R(Tail(L));
		}
		
	}
}
