#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum { FALSE, TRUE } bool;

typedef struct tNo {    char caractere;
                        struct tNo * prox;
                    } tNo;

typedef struct {
                tNo* inicio;
                tNo* fim;
               } Fila;


// ***********************************************
// ******************** Initlista ****************
// ***********************************************
bool initString ( Fila* S)
{
    bool r = TRUE;
    S->inicio=NULL;
    S->fim = NULL;
    return r;
}

// ***********************************************
// ******            empty check            ******
// ***********************************************
bool testavazio(Fila S)
{
    return((S.inicio == NULL)&&(S.fim == NULL));
}
// ***********************************************
// ******                                   ******
// ***********************************************





// ***********************************************
// ******             imprimir              ******
// ***********************************************
void imprimeLista (Fila S) {

int pos =0;

                 printf("========================\n");

   if ( S.inicio == NULL)
      printf("Lista Vazia\n");
   else {

      printf("Inicio = %p\n", S.inicio);
      printf("Final = %p\n", S.fim);
      tNo* posAtual = S.inicio;

      do {
          printf("posicao[%i] - dado[%c] -> ponteiro[%p]\n", pos, posAtual->caractere , posAtual);
          posAtual = posAtual->prox;
          pos++;
          } while (posAtual != NULL);
      }
	printf("========================\n");
}
// ***********************************************
// ******                                   ******
// ***********************************************


bool inserirItem(Fila* S, char caractere)
{
    bool OK;
    bool r = TRUE;
    tNo* novoNo;

    novoNo = (tNo*) malloc(sizeof(tNo));
        if(novoNo == NULL)
            {
                r = FALSE;
                return r;
            }
     novoNo->caractere = caractere;
     novoNo->prox = NULL;

    OK = testavazio(*S);

    if (OK == TRUE)
        {
            if(S->inicio == NULL)
                {
                    novoNo->caractere = caractere;
                    novoNo->prox = NULL;

                    if (S->fim == NULL) S->fim = novoNo;

                    novoNo->prox = S->inicio;
                    S->inicio = novoNo;

                    if(S->inicio == NULL)
                        {
                          printf("Ocorreu um erro na inserção do primeiro termo.");
                        }

                }
                else
                {
                    S->fim->prox = novoNo;
                    S->fim = novoNo;
                }

        }
    return r;
}

// ***********************************************
// ******                                   ******
// ***********************************************


// ***********************************************
// ******                                   ******
// ***********************************************


// ***********************************************
// ******              Menu                 ******
// ***********************************************
int menu()
{
    int opcao;
    system("cls");
    printf("|-----------------------------------------------|\n");
    printf("                    |>Testes<|                   \n");
    printf("|-----------------------------------------------|\n");
    printf("\n\n");
    printf("1. Criar uma String vazia.\n");
    printf("2. Criar uma string S1 e copia-la para a string S.\n");
    printf("3. Verificar se S1 e S2 não idênticas.\n");
    printf("4. Contar o número de palavras na string S.\n");
    printf("5. Inverter uma as letras.\n");
    printf("6. Concatenar duas strings.\n");
    printf("7. Intercalar strings.\n");
    printf("8. Inverter as palavras.\n");
    printf("9. Inverter as letras das palavras.\n");
    printf("10. Sair.\n");
    printf("\n\n");
    printf("|-----------------------------------------------|\n");
    printf("|-----------------------------------------------|\n");
    scanf("%d", &opcao);
    return opcao;
}

// ***********************************************
// ***********************************************
// ***********************************************

int main()
{
    int opcao,i,j;
    char frase[50];
    char caracter;
    Fila SVazia,S1,S;
    opcao = 0;
    bool OK,OK1;
    opcao = menu();
    system("cls");

        if(opcao == 1)
        {
            system("cls");
            printf("\n\n");
            printf("Criando uma string vazia...\n\n");
            OK = initString(&SVazia);
                if(OK == TRUE)
                    {
                        OK = testavazio(SVazia);
                            if(OK == TRUE)
                                {
                                printf("\n");
                                printf("String vazia criada com sucesso.\n");
                                printf("\n");
                                }
                    }else
                    {
                        system("cls");
                        printf("Ocorreu um erro na criação da lista vazia.\n");
                    }
            printf("\n\n");
        }

        if(opcao == 2)
        {   i,j = 0;
            system("cls");
            OK = initString(&S1);
            OK1 = initString(&S);
            printf("\n\n");
            printf("Criar uma String[S1] e copiar para outra String[S]...\n\n");
            if((OK == TRUE)&&(OK1 == TRUE))
                {
                    printf("Lista S1 e S criadas com sucesso. \n");
                }
                printf("\n\n");
            printf("insira a String[S1]\n");
            scanf("%s",&frase);

            if((OK == TRUE)&&(OK1 == TRUE))
                {
                    OK = testavazio(S1);
                    OK1 = testavazio(S);
                        if((OK == TRUE)&&(OK1 == TRUE))
                            {

                                  //  while(frase[i]!= '.')
                                    for(i=0; i<= 200 ;i++)
                                        {
                                            caracter = frase[i];
                                            if(caracter!='.')
                                                {
                                                    inserirItem(&S1,caracter);
                                                    printf("inserção[%i] realizada com sucesso.\n",i);
                                                }else
                                                {
                                                i= 200;
                                                }

                                        }
                            }
                                }else
                                    {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S1.\n");
                                    }
                    printf("\n\n");
                    imprimeLista(S1);
        }

}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum { FALSE, TRUE } bool;

typedef struct tNo { char caractere;
                 struct tNo * prox;
               } tNo;

typedef struct {
                tNo* inicio;
                tNo* fim;
               } Fila;


// ***********************************************
// ******************** Initlista ****************
// ***********************************************
bool initString ( Fila* S)
{
    bool r = TRUE;
    S->inicio=NULL;
    S->fim = NULL;
    return r;
}

// ***********************************************
// ******            empty check            ******
// ***********************************************
bool testavazio(Fila S)
{
    return((S.inicio == NULL)&&(S.fim == NULL));
}
// ***********************************************
// ******                                   ******
// ***********************************************
bool inserirItem(Fila* S, char caractere)
{
    bool OK;
    bool r = TRUE;
    tNo* novoNo;

    novoNo = (tNo*) malloc(sizeof(tNo));
        if(novoNo == NULL)
            {
                r = FALSE;
                return r;
            }
     novoNo->caractere = caractere;
     novoNo->prox = NULL;

    OK = testavazio(*S);
    if (!OK)
        {
            S->fim->prox = novoNo;
            S->fim = novoNo;
        }
    return r;
}
// ***********************************************
// ******                                   ******
// ***********************************************



// ***********************************************
// ******                                   ******
// ***********************************************




// ***********************************************
// ******                                   ******
// ***********************************************


// ***********************************************
// ******                                   ******
// ***********************************************


// ***********************************************
// ******                                   ******
// ***********************************************


// ***********************************************
// ***********************************************
// ***********************************************

int main()
{




}
