//Header Files
#include <stdio.h>
#include <stdlib.h>

//Pre-Processador
#define TElem int

//Structs
typedef struct No
{
    TElem Elem;
    struct No *Prox;
}No;

typedef struct Fila
{
    No *Inicio;
    No *Fim;
    int N;
}Fila;

//Procedimentos Essenciais a Filas
void Constroi(Fila *F)
{
    F->Inicio=NULL;
    F->Fim=NULL;
    F->N=0;
}

void Destroi(Fila *F)
{
    //mesma destruicao de listas encadeadas
    //Do pdf Listas Lineares pag.41:
    No *p,*pprox,*aux;
    pprox=F->Inicio;
    while(pprox!=NULL)
    {
	aux=pprox;
        pprox=pprox->Prox;
	p=aux;	
	free(p);
    }
}

//Outras Funcoes e Procedimentos
TElem Proximo(Fila *F)
{
    return (F->Inicio->Elem);	
}

void Enfileira(Fila *F,TElem x)
{
    No *novoNo;
    novoNo=(No *) malloc(sizeof(No));
    novoNo->Elem=x;
    novoNo->Prox=NULL;
    F->N = F->N + 1;

    if(F->Inicio == NULL)
    {
	F->Inicio=novoNo;
	F->Fim=novoNo;
    }
    else
    {
	F->Fim->Prox=novoNo;
	F->Fim=novoNo;
    }

}

TElem Desenfileira(Fila *F)
{
    if(F->Inicio!=NULL)
    {
	No *NoARemover=F->Inicio;
	TElem x=F->Inicio->Elem;
	if(F->Inicio==F->Fim)
        {
	    F->Inicio=NULL;
	    F->Fim=NULL;
	}
	else
	    F->Inicio=F->Inicio->Prox;
	free(NoARemover);
	F->N--;
	return x;
    }
    //else
     printf("UNDERFLOW\n");
}

int Tamanho(Fila *F)
{
    return (F->N);
}

//Novas funcoes

//Main
int main()
{
    Fila F;
    Constroi(&F);
    printf("Construida\n");
    Enfileira(&F,10);
    Enfileira(&F,100);
    Enfileira(&F,1000);
    printf("%d\n", Proximo(&F));
    printf("%d\n", Tamanho(&F));
    printf("%d\n", Desenfileira(&F));
    printf("%d\n", Proximo(&F));
    printf("%d\n", Tamanho(&F));
    Destroi(&F);
    return 0;
}
//FIM

	
