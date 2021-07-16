#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/*
Nome: Silas Rodrigues Gouveia Júnior
RA: 0040481712041

a)	Inserção  de Listas  Simplesmente   < 1,5 >
b)	Remoção de Lista Duplamente         < 2,0 >
c)	Exibir os Resultados da Lista       < 1,5 >
*/



typedef struct no {
char nome[10];
int codigo;
struct no*next;
} no;

struct no *auxiliar, *corrente, *inicio;

void enterdata()
{
    printf("Digite o nome:\n");
    scanf("%s", &corrente->nome);
    fflush(stdin);
    printf("Digite o codigo: \n");
    scanf("%i", &corrente->codigo);
    fflush(stdin);
}


int inserir(no**lista){
    system("cls");

    if(inicio==NULL)
    {
        corrente= (no*) malloc(sizeof(no));
        corrente->next=NULL;
        auxiliar= corrente;
        inicio=corrente;
        enterdata();

    } else {
    auxiliar=inicio;
    corrente=inicio;

    while(corrente->next!= NULL)
    {
     corrente=corrente->next;
     auxiliar=auxiliar->next;
    }
     corrente=(no*)malloc(sizeof(no));
     auxiliar->next=corrente;
     corrente->next=NULL;
     auxiliar= corrente;
     enterdata();
    }

}

int exibir (no**lista)
{
    if(inicio==NULL)
    {
        printf("Lista vazia\n");
        system("pause");
    }

    else
    {
    auxiliar = inicio;

    while (auxiliar != NULL)
    {
        printf("nome %s\n", auxiliar->nome);
        printf("codigo %i\n", auxiliar->codigo);
        auxiliar = auxiliar->next;
        system("pause");
    }
    }
}


int remover(no**lista)
{
    int achou = 0;

    if (inicio == NULL)
    {
        printf("Lista se encontra vazia\n");
        system("pause");
    }
    else
    {
        auxiliar = inicio;

        int xcodigo;


        printf("Digite o numero a ser removido:\n");
        scanf("%i", &xcodigo);
        fflush(stdin);

        if(auxiliar->next == NULL && auxiliar->codigo!= xcodigo)
        {
            printf("Existe apenas um numero na memoria\n");

        }
        else{
            if (auxiliar->codigo == xcodigo)
            {
                inicio = inicio->next;
                free(auxiliar);
                printf("o primeiro foi removido\n");
                system("pause");
                achou = 1;
            }
            else
            {
                corrente = auxiliar->next;
                while (corrente != NULL)
                {
                    if (corrente->codigo == xcodigo)
                    {
                        auxiliar->next = corrente->next;
                        printf("O elemento do meio foi removido\n");
                        system("pause");
                        achou = 1;
                        break;
                    }
                    else
                    {
                        auxiliar = auxiliar->next;
                        corrente = corrente->next;
                    }
                }
            }
            if (achou == 0 && corrente->codigo == xcodigo)
            {
                auxiliar->next = NULL;
                free(corrente);
                achou = 1;
                printf("O ultimo elemento foi removido\n");
                system("pause");

            }
        }
    }

    if (achou ==0)
    {
        printf("Numero nao encontrado");
        system("pause");

    }
}

int main()
{
    auxiliar = NULL;
    inicio = NULL;
    corrente = NULL;
    int op;
do{
    system("cls");
    printf("\n[1]-Inserir registro na lista.");
    printf("\n[2]-Exibir registro da lista.");
    printf("\n[3]-Remover registro da lista.");
    printf("\n[4]-Sair do sistema.\n");
    printf("\n\n");
    printf("Informe a opcao:\n");
    scanf("%d",&op);
    fflush(stdin);

    switch(op)
    {
    case 1:
        inserir(&inicio);
        break;
   case 2:
        exibir(&inicio);
        break;
    case 3:
        remover(&inicio);
        break;
    case 4:
        break;
        default:
        system("cls");
        printf("Opcao invalida, tente novamente.. \n");
        system("pause");
        break;
    }

  }while(op!=4);

}
