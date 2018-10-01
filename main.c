#include <stdio.h>
#include <stdlib.h>


typedef struct Node *Apontador;

struct Node {
    int bin;
    Apontador prox;
};

struct TipoPilha {
    Apontador Topo;
};

typedef struct TipoPilha Pilha;

void inicia(Pilha *a){
    a->Topo = (Apontador)malloc(sizeof(Apontador));
    a->Topo->prox = NULL;
}

int PilhaVazia(Pilha *a){
    return (a->Topo->prox == NULL);
}

void empilha(int valor, Pilha *a){
    Apontador num;
    num = (Apontador)malloc(sizeof(Apontador));
    a->Topo->bin = valor;
    num->prox = a->Topo;
    a->Topo = num;
}

int desempilha(Pilha *a, int *x){
    if(PilhaVazia(a))
        return 0;
    else{
        Apontador p;
        p = a->Topo;
        a->Topo = a->Topo->prox;
        *x = a->Topo->bin;
        free(p);
        return 1;
    }
}

void imprimePilha(Pilha *a){
    int x;
    Pilha PilhaAux;
    inicia(& PilhaAux);
    while(!PilhaVazia(a)){
        desempilha(a, &x);
        printf("%d", x);
        empilha(x, &PilhaAux);
    }
    while(!PilhaVazia(&PilhaAux)){
        desempilha(&PilhaAux, &x);
        empilha(x, a);
    }
}

void converBin (int num, Pilha *a){
    while (num>1){
        empilha(num%2, a);
        num = num/2;
    }
    empilha(num, a);
}

int main()
{
    while(1){
    int dec;
    Pilha a;
    inicia(&a);
    printf("Numero a ser convertido: ");
    scanf("%d", &dec);
    printf("\n");
    converBin(dec, &a);
    imprimePilha(&a);
    printf("\n");
    }
    return 0;
}
