#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    int numero[50];
    int Topo;
} Pilha;

void FazPilhaVazia(Pilha *pilha){
    pilha->Topo = -1;
}

int PilhaVazia(Pilha *pilha){
    return (pilha->Topo == -1);
}

int Empilha(int x, Pilha *pilha){
    if (pilha->Topo == (50-1))
        return 0;
    else{
        pilha->Topo = pilha->Topo + 1;
        pilha->numero[pilha->Topo] = x;
        return 1;
    }
}

int Desempilha(Pilha *pilha, int *x){
    if (PilhaVazia(pilha))
        return 0;
    else{
        *x = pilha->numero[pilha->Topo];
        pilha->Topo = pilha->Topo - 1;
        return 1;
    }
}

void ImprimePilha(Pilha *pilha){
    int x;
    Pilha pilhaAux;
    FazPilhaVazia(&pilhaAux);

    while (!PilhaVazia(pilha)){
        Desempilha(pilha, &x);
        printf("%d", x);
        Empilha(x, &pilhaAux);
    }
    printf("\n");

    while (!PilhaVazia(&pilhaAux)){
        Desempilha(&pilhaAux, &x);
        Empilha(x, pilha);
    }
}

void converBin (long long int x, Pilha *pilha){
    while (x>1){
        Empilha(x%2, pilha);
        x = x/2;
    }
    Empilha(x, pilha);
}

void converDec(char* num, Pilha *pilha){
    int i, j, k = 0, a = strlen(num);
    long long int dec = 0;
    for (i=0;i<a;i++){
        Empilha(num[i] - '0', pilha);
    }
    while(a){
        Desempilha(pilha, &j);
        dec = dec + (j*pow(2,k));
        k++;
        a--;
    }
    printf("%I64d\n", dec);
}

int main()
{
    int continuar = 1;
    printf("\n********** Conversor Decimal/Binario **********\n\n");
    do
    {
        long long int dec;
        char bit;
        Pilha bin;
        FazPilhaVazia(&bin);

        printf("Escolha uma opcao:\n\n");
        printf("1. Decimal para Binario\n");
        printf("2. Binario para Decimal\n");
        printf("3. Sair\n\n");
        scanf("%d", &continuar);
        system("cls");

        switch(continuar)
        {
            case 1:
                printf("\nNumero (decimal): ");
                scanf("%I64d", &dec);
                printf("\n\n");
                converBin(dec, &bin);
                printf("Numero (binario): ");
                ImprimePilha(&bin);
                printf("\n\n");
                break;

            case 2:
                printf("\nNumero (binario): ");
                scanf("%s", &bit);
                printf("\n\n");
                printf("Numero (decimal): ");
                converDec(&bit, &bin);
                printf("\n\n");
                break;

            case 3:
                printf("\n\n Bye, bye!");
                break;

            default:
                printf("\n********** Conversor Decimal/Binario **********\n\n");
                printf("*** Digite uma opcao valida! ***\n\n");
        }
    } while(continuar!=3);

    return 0;
}
