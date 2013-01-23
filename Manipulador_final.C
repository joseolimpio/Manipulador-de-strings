#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum { FALSE, TRUE } bool;

typedef struct tNo {

                    char caractere;
                    struct tNo * prox;

                    } tNo;

typedef struct {
                tNo* inicio;
                tNo* fim;
                int tam;
               } Lista;


// ***********************************************
// ******************** Initlista ****************
// ***********************************************
bool initString ( Lista* S)
{
    bool r = TRUE;
    S->inicio=NULL;
    S->fim = NULL;
    S->tam = 0;
    return r;
}

// ***********************************************
// ******            empty check            ******
// ***********************************************
bool testavazio(Lista S)
{
    return((S.inicio == NULL)&&(S.fim == NULL));
}

// ***********************************************
// ******             imprimir              ******
// ***********************************************
void imprimeLista (Lista S) {

int pos =0;
char c;

    printf("========================\n");
        if ( S.inicio == NULL)
            printf("Lista Vazia\n");
        else {
            tNo* posAtual = S.inicio;
                do {
                    c = posAtual->caractere;
                    if(( c >= 48)&&(c <= 125))
                            {
                                printf("%c",c);
                            }else
                                {
                                    printf("%c",32);
                                }
                    posAtual = posAtual->prox;
                    pos++;
                    } while (posAtual != NULL);
                }
    printf("\n");
    printf("========================\n");
}
// ***********************************************
// ******              inserir              ******
// ***********************************************
bool inserirItem(Lista* S, char caractere)
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
                            novoNo->prox = S->fim;
                            S->inicio = novoNo;
                            if(S->inicio == NULL)
                                {
                                    printf("Ocorreu um erro na inserção do primeiro termo.");
                                }
                        }
                }
            else
                {
                    S->fim->prox = novoNo;
                    S->fim = novoNo;
                }
    S->tam++;
    return r;
}
// ***********************************************
// ******        copia strings              ******
// ***********************************************
bool copiaString(Lista*Original, Lista* Copia)
{
    bool OK,r = TRUE;
    int pos =0;
    char elemento;
        tNo* posOriginal = Original->inicio;

            if ( Original->inicio == NULL)
                {
                    printf("Lista Vazia\n");
                    r = FALSE;
                    return r;
                }
            else
                {
                do{
                    elemento = posOriginal->caractere;
                    OK = inserirItem(Copia,elemento);
                        if(OK == TRUE)
                            {
                                posOriginal = posOriginal->prox;
                            }
                        else
                            {
                                printf("erro na copia da lista.\n");
                            }
                } while (posOriginal != NULL);
                }
    return r;
}
// ***********************************************
// ******           Verificar 2 strings     ******
// ***********************************************
bool verificarStrings(Lista* S1, Lista * S2)
{
    bool OK,r = TRUE;
    int pos,flag =0;
    char elemento,elemento1;
    tNo* posPrimaria = S1->inicio;
    tNo* posSecundaria = S2->inicio;

   if (( S1->inicio == NULL)||(S2->inicio == NULL))
    {
        printf("Lista Vazia\n");
        r = FALSE;
        return r;
    }

   else {


        do {


          elemento = posPrimaria->caractere;
          elemento1 = posSecundaria->caractere;
          if(elemento == elemento1)
                    {

                    }
                 else
                    {
                        flag++;
                    }
          posPrimaria =  posPrimaria->prox;
          posSecundaria= posSecundaria->prox;

          } while (posPrimaria != NULL);
      }
   if(flag > 0)
   {
       r = FALSE;
       return r;
   }
   return r;
}
// ***********************************************
// ******              Inverter as letras   ******
// ***********************************************
void inverteFrase(Lista S)
{
char frase[40];
char c;
int pos,i = 0;

        if ( S.inicio == NULL)
            printf("Lista Vazia\n");
        else {
            tNo* posAtual = S.inicio;
                do{
                    frase[i] = posAtual->caractere;
                    posAtual = posAtual->prox;
                    i++;
                    pos++;
                }while(posAtual != NULL);

        pos=S.tam;
        initString(&S);
                do{
                    c = frase[pos];
                    if(c == 91)
                        {
                            inserirItem(&S,' ');
                        }else
                        {
                            inserirItem(&S,c);
                        }
                pos--;
                }while((pos >= 0 )||( c >= 48)&&(c <= 125));

                }
    printf("\n");
  imprimeLista(S);
}
// ***********************************************
// ******        intercalar strings         ******
// ***********************************************
void intercalarFrases(Lista S,Lista S1)
{
char frase[40];
char frase1[40];
char aux[80];
char c;
int h,l,q;
int pos,i = 0;
int pos1,j = 0;
Lista S3;

        initString(&S3);
            if ((S.inicio == NULL)||(S1.inicio == NULL))
                printf("Lista Vazia\n");
            else {

                tNo* posAtual = S.inicio;
                    do{
                        frase[i] = posAtual->caractere;
                        posAtual = posAtual->prox;
                        i++;
                        pos++;
                    }while(posAtual != NULL);
        pos1,i = 0;
        posAtual =S1.inicio;
                    do
                    {
                    frase1[i] = posAtual->caractere;
                    posAtual = posAtual->prox;
                    i++;
                    pos1++;
                    }while(posAtual != NULL);

        pos = S.tam;
        pos1 = S1.tam;
        h=pos+pos1;
        l = 0; //aparentemente se eu colocar l,q,i = 0 buga, talvez seja o compilador Code::Blocks,a testar no linux.
        q = 0;
        i = 0;
                    do{ //Bug, ou erro de lógica, espaços em excesso.
                            do{
                                c = frase[l];
                                inserirItem(&S3,c);
                                l++;
                            }while((frase[l]!= ' ')&&(frase[l]!= '.')&&(l <= pos));
                    l++;
                    inserirItem(&S3,' ');
                            do{
                                c = frase1[q];
                                inserirItem(&S3,c);
                                q++;
                            }while((frase1[q]!= ' ')&&(frase1[q]!= '.')&&(q <= pos1));
                    inserirItem(&S3,' ');
                    q++;
                    i++;

                                if(l>=pos)
                                    {
                                            do{
                                                c = frase1[q];
                                                inserirItem(&S3,c);
                                                q++;
                                            }while((frase1[q]!= ' ')&&(frase1[q]!= '.')&& (q <= pos1));

                                    inserirItem(&S3,' ');
                                    q++;
                                    }else
                                    {
                                            do{
                                                c = frase[l];
                                                inserirItem(&S3,c);
                                                l++;
                                            }while((frase[l]!= ' ')&&(frase[l]!= '.')&&(l <= pos));
                                    l++;
                                    inserirItem(&S3,' ');
                                    }
                        inserirItem(&S3,' ');
                        l++;
                        }while((l<=h)&&( c >= 48)&&(c <= 125));
                }
        printf("\n\n");
    	imprimeLista(S3);
}
// ***********************************************
// ***********************************************
// ***********************************************
void inverterLetraPalavras(Lista S)
{
char frase[100];
char c;
int pos,i = 0;
int cont = 0;
int j = 0;
Lista S1;

   if ( S.inicio == NULL)
      printf("Lista Vazia\n");
   else {

      tNo* posAtual = S.inicio;


        do{
          frase[i] = posAtual->caractere;
          posAtual = posAtual->prox;

           i++;
           pos++;
        }while(posAtual != NULL);
        }

        pos,i =0;
        pos = S.tam;
        initString(&S);
            do{
                c=frase[i];
                        if((c == ' ')||(c== '.'))
                                {
                                    j = i-1;

                                    do{
                                        if(frase[j]== 91)
                                        {
                                        inserirItem(&S,' ');
                                        j--;
                                        }else
                                        {
                                        inserirItem(&S,frase[j]);
                                        j--;
                                        }
                                    }while(( frase[j] >= 48)&&(frase[j] <= 125));

                                            if(c == 91) //não sei por que mas sempre aparece um [...
                                            {
                                            inserirItem(&S,' ');
                                            i++;
                                            }else
                                            {
                                            inserirItem(&S,c);
                                            i++;
                                            }

                                }else
                                {
                                    i++;
                                }

            }while(i<=pos);

    printf("\n");
    imprimeLista(S);
    printf("\n");
}
// ***********************************************
// ***********************************************
// ***********************************************
void inverterPalavras(Lista S)
{
char frase[100];
char frase1[100];
char c;
char c1;
int pos,i = 0;
int cont = 0;
int j = 0;
bool OK;
Lista S1;
                if ( S.inicio == NULL)
                    printf("Lista Vazia\n");
                else{
                    tNo* posAtual = S.inicio;
                            do{
                            frase[i] = posAtual->caractere;
                            posAtual = posAtual->prox;
                            i++;
                            pos++;
                            }while(posAtual != NULL);
                    }

                  tNo* posAtual = S.inicio;
                    do{
                        frase[i] = posAtual->caractere;
                        posAtual = posAtual->prox;
                        i++;
                        pos++;
                    }while(posAtual != NULL);
                pos=S.tam;
                initString(&S);
                do // inverte a frase
                {
                    c = frase[pos];
                    if(frase[pos] == 91)
                    {
                        inserirItem(&S,' ');
                    }else
                    {
                    inserirItem(&S,frase[pos]);
                    }
                    pos--;
                }while((pos >= 0 )||( c >= 48)&&(c <= 125));

            pos,i =0;
            pos = S.tam;
            initString(&S); //inverter as letras da frase já invertida.
                    do{
                        c=frase[i];
                        if((c == ' ')||(c== '.'))
                            {
                                j = i-1;
                                do{
                                    if(frase[j]== 91)
                                        {
                                            inserirItem(&S,' ');
                                            j--;
                                        }else
                                        {
                                            inserirItem(&S,frase[j]);
                                            j--;
                                        }
                                }while(( frase[j] >= 48)&&(frase[j] <= 125));
                        if(c == 91)
                            {
                                inserirItem(&S,' ');
                                i++;
                            }else
                            {
                                inserirItem(&S,c);
                                i++;
                            }
                        }else
                            {
                                i++;
                            }

                    }while(i<=pos);

            printf("\n\n");
            inverteFrase(S);
            printf("\n");

}
// ***********************************************
// ******              Menu                 ******
// ***********************************************
int menu()
{
    int opcao,i,j,tam,contpalavra,sair;
    char c;
    char caracter;
    Lista SVazia,S1,S,S2,S3,S4;
    bool OK,OK1,OK2;


    system("cls");
    printf("|-----------------------------------------------|\n");
    printf("                    |>Testes<|                   \n");
    printf("|-----------------------------------------------|\n");
    printf("\n\n");
    printf("1. Criar uma String vazia.\n");
    printf("2. Criar uma string S1 e copia-la para a string S.\n");
    printf("3. Verificar se S1 e S2 sao identicas.\n");
    printf("4. Contar o numero de palavras na string S.\n");
    printf("5. Inverter as letras de uma string.\n");
    printf("6. Concatenar duas strings.\n");
    printf("7. Intercalar 2 strings.\n");
    printf("8. Inverter as palavras.\n");
    printf("9. Inverter as letras das palavras.\n");
    printf("10. Sair.\n");
    printf("\n\n");
    printf("|-----------------------------------------------|\n");
    printf("Opcao:");
    scanf("%d", &opcao);

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
                                printf("Deseja Retornar ao menu ou sair?  1 - voltar / 2 - sair\n");
                                scanf("%d", &sair);
                                return sair;
                    }

                        if(opcao == 2)
                            {
                            i,contpalavra = 0;
                            c = '\0';
                            system("cls");
                            OK = initString(&S1);
                            OK1 = initString(&S);
                            printf("\n\n");
                            printf("Criar uma String[S1] e copiar para outra String[S]...\n");
                            printf("Obs: Como comentado na sala a forma de insercao deve ser concluida com um '.' .\n\n");
                                if((OK == TRUE)&&(OK1 == TRUE))
                                    {
                                        printf("Lista S1 e S criadas com sucesso. \n");
                                    }
                            printf("\n\n");
                            printf("insira a String[S1]:\n");
                            scanf("%c",&c);
                            if((OK == TRUE)&&(OK1 == TRUE))
                                {
                                    OK = testavazio(S1);
                                    OK1 = testavazio(S);
                                        if((OK == TRUE)&&(OK1 == TRUE))
                                            {
                                                for(i=0; i<=200 ;i++)
                                                    {
                                                        if(caracter!='.')
                                                            {
                                                                scanf("%c",&c);
                                                                caracter = c;
                                                                    if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }
                                                        OK = inserirItem(&S1,caracter);
                                                            if(OK == TRUE)
                                                                {
                                                                //printf("inserção[%i] realizada com sucesso.\n",i);
                                                                }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                            }else
                                                            {
                                                        contpalavra++;
                                                        break;
                                                            }

                                                    }
                                            }
                                }else
                                    {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S1.\n");
                                    }
                        printf("\n\n");
                        printf("\n\n");
                        OK = copiaString(&S1,&S);
                        if(OK == TRUE)
                        {
                            printf("\n\n");
                            printf("String Original [S1]");
                            printf("\n\n");
                            imprimeLista(S1);
                            printf("\n\n");
                            printf("String Copia [S]");
                            printf("\n\n");
                            imprimeLista(S);
                        }else
                            {
                                printf("erro na criacao da copia da lista.\n");
                            }
                        OK = verificarStrings(&S1,&S);
                            if (OK == TRUE)
                                {
                                    printf("\n\n");
                                    printf("As Strings sao identicas.\n");
                                    printf("\n\n");
                                }else
                                {
                                printf("\n\n");
                                printf("As Strings nao sao identicas.\n");
                                printf("\n\n");
                                }
                        printf("\n\n");
                        printf("Deseja Retornar ao menu ou sair?  1 - voltar / 2 - sair\n");
                        scanf("%d", &sair);
                        return sair;
        }


    if(opcao == 3) // bug, se acessada depois de voltar ao menu a strin S1 é automaticamente preenchida (vazia) não faço ideia por que.
        {
            i,contpalavra = 0;
            c = '\0';
            system("cls");
            OK = initString(&S1);
            OK1 = initString(&S2);
            printf("\n\n");
            printf("Verificar se duas Strings são identicas...\n");
            printf("Obs: Como comentado na sala a forma de insercao deve ser concluida com um '.' .\n\n");
                    if((OK == TRUE)&&(OK1 == TRUE))
                        {
                            printf("Lista S1 e S2 criadas com sucesso. \n");
                        }
            printf("\n\n");
            printf("insira a String[S1]:\n");
            scanf("%c",&c);
                    if(OK == TRUE)
                        {
                            OK = testavazio(S1);
                            if(OK == TRUE)
                                {
                                      for(i=0; i<=200 ;i++)
                                        {
                                                   if(caracter!='.')
                                                        {
                                                            scanf("%c",&c);
                                                            caracter = c;
                                                            if(caracter == ' ')
                                                                {
                                                                    contpalavra++;
                                                                }

                                                    OK = inserirItem(&S1,caracter);
                                                            if(OK == TRUE)
                                                                {
                                                                    //printf("inserção[%i] realizada com sucesso.\n",i);
                                                                }else
                                                                    {
                                                                        printf("inserção[%i] falhou.\n",i);
                                                                    }
                                                        }else
                                                            {
                                                                contpalavra++;
                                                                break;
                                                            }

                                        }
                                }else
                                    {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S2.\n");
                                    }
            printf("\n\n");
            printf("\n\n");
            contpalavra = 0;
            caracter = '\0';
            printf("insira a String[S2]:\n");
            scanf("%c",&c);
                if(OK == TRUE)
                    {
                        OK = testavazio(S2);
                            if(OK == TRUE)
                                {
                                      for(i=0; i<=200 ;i++)
                                        {
                                                   if(caracter!='.')
                                                        {
                                                            scanf("%c",&c);
                                                            caracter = c;
                                                            if(caracter == ' ')
                                                                {
                                                                    contpalavra++;
                                                                }

                                                            OK = inserirItem(&S2,caracter);
                                                                if(OK == TRUE)
                                                                    {
                                                                        //printf("inserção[%i] realizada com sucesso.\n",i);
                                                                    }else
                                                                    {
                                                                        printf("inserção[%i] falhou.\n",i);
                                                                    }
                                                        }else
                                                            {
                                                                contpalavra++;
                                                                break;
                                                            }

                                            }
                                }else
                                    {
                                        system("cls");
                                        printf("Ocorreu um erro na criação da lista S1.\n");
                                    }


                    printf("\n\n");
                    printf("\n\n");
                    printf("\n\n");
                        }else
                        {
                            printf("erro na criacao da copia da lista.\n");
                        }
         OK = verificarStrings(&S1,&S2);
            if (OK == TRUE)
                {
                    printf("\n\n");
                    printf("As Strings sao identicas.\n");
                    printf("\n\n");
                }else
                {
                    printf("\n\n");
                    printf("As Strings nao sao identicas.\n");
                    printf("\n\n");
                }
                }
            printf("\n\n");
            printf("Deseja Retornar ao menu ou sair?  1 - voltar / 2 - sair\n");
            scanf("%d", &sair);
            return sair;
        }


        if(opcao == 4)
            {
                int i,contpalavra = 0;
                c = '\0';
                caracter='\0';
                system("cls");
                OK = initString(&S3);
                printf("\n\n");
                printf("Criar uma String[S3] e contar quantas palavras...\n");
                printf("Obs: Como comentado na sala a forma de insercao deve ser concluida com um '.' .\n\n");
                    if(OK == TRUE)
                        {
                            printf("Lista S3 criadas com sucesso. \n");
                        }
                printf("\n\n");
                printf("insira a String:\n");
                scanf("%c",&c);
                    if(OK == TRUE)
                        {
                            OK = testavazio(S3);
                                if(OK == TRUE)
                                    {
                                        for(i=0; i<=200 ;i++)
                                            {
                                                   if(caracter!='.')
                                                        {
                                                            scanf("%c",&c);
                                                            caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }
                                                    OK = inserirItem(&S3,caracter);
                                                            if(OK == TRUE)
                                                                {
                                                                    //printf("inserção[%i] realizada com sucesso.\n",i);
                                                                }else
                                                                    {
                                                                        printf("inserção[%i] falhou.\n",i);
                                                                    }
                                                        }else
                                                    {
                                                        contpalavra++;
                                                        break;
                                                    }

                                            }
                                    }
                        }else
                                {
                                system("cls");
                                printf("Ocorreu um erro na criação da lista S3.\n");
                                }
                printf("\n\n");
                printf("palavras[%i]",contpalavra);
                printf("\n\n");
                printf("\n\n");
                printf("Deseja Retornar ao menu ou sair?  1 - voltar / 2 - sair\n");
                scanf("%d", &sair);
                return sair;
        }

        if(opcao == 5)
            {
                int i,contpalavra = 0;
                c = '\0';
                caracter='\0';
                system("cls");
                OK = initString(&S4);
                printf("\n\n");
                printf("Criar uma String[S4] inverter as letras de uma frase...\n");
                printf("Obs: Como comentado na sala a forma de insercao deve ser concluida com um '.' .\n\n");
                if(OK == TRUE)
                    {
                        printf("Lista S4 criadas com sucesso. \n");
                    }
                printf("\n\n");
                printf("insira a String:\n");
                scanf("%c",&c);
                if(OK == TRUE)
                    {
                        OK = testavazio(S4);
                            if(OK == TRUE)
                                {
                                    for(i=0; i<=200 ;i++)
                                        {
                                             if(caracter!='.')
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }
                                                    OK = inserirItem(&S4,caracter);
                                                            if(OK == TRUE)
                                                                {
                                                                    //printf("inserção[%i] realizada com sucesso.\n",i);
                                                                }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                }else
                                                {
                                                contpalavra++;
                                                break;
                                                }
                                        }
                                }
                                }else
                                    {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S4.\n");
                                    }
            inverteFrase(S4);
            printf("\n\n");
            printf("Deseja Retornar ao menu ou sair?  1 - voltar / 2 - sair\n");
            scanf("%d", &sair);
            return sair;
      }
        if(opcao == 6)// de novo bug, se acessada depois de voltar ao menu a strin S1 é automaticamente preenchida (vazia) não faço ideia por que.
        {
            i = 0;
            c = '\0';
            system("cls");
            OK = initString(&S1);
            OK1 = initString(&S2);
            OK2 = initString(&S3);
            printf("\n\n");
            printf("Criar S1, S2 e concatena-las em S3...\n");
            printf("Obs: Como comentado na sala a forma de insercao deve ser concluida com um '.' .\n\n");
                if((OK == TRUE)&&(OK1 == TRUE)&&(OK2 == TRUE))
                    {
                        printf("Lista S1,S2 e S3 criadas com sucesso. \n");
                    }
            printf("\n\n");
            printf("insira a String[S1]:\n");
            scanf("%c",&c);
                if(OK == TRUE)
                    {
                        OK = testavazio(S1);
                            if(OK == TRUE)
                                    {
                                      for(i=0; i<=200 ;i++)
                                        {

                                            if(caracter!='.')
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }

                                                    OK = inserirItem(&S1,caracter);
                                                            if(OK == TRUE)
                                                            {
                                                            //printf("inserção[%i] realizada com sucesso.\n",i);
                                                            }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                }else
                                                {
                                                contpalavra++;
                                                break;
                                                }

                                        }
                                }else
                                {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S2.\n");
                                }
            printf("\n\n");
            printf("\n\n");
            contpalavra = 0;
            caracter = '\0';
            printf("insira a String[S2]:\n");
            scanf("%c",&c);
                if(OK1 == TRUE)
                    {
                        OK = testavazio(S2);
                            if(OK == TRUE)
                                {
                                      for(i=0; i<=200 ;i++)
                                        {
                                            if(caracter!= 46)
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }

                                                    OK = inserirItem(&S2,caracter);
                                                            if(OK == TRUE)
                                                            {
                                                            //printf("inserção[%i] realizada com sucesso.\n",i);
                                                            }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                }else
                                                {
                                                contpalavra++;
                                                break;
                                                }

                                        }
                                }else
                                {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S1.\n");
                                }


                    printf("\n\n");
                    printf("\n\n");
                    }else
                    {
                    printf("erro na criacao da copia da lista.\n");
                    }

        //como a cópia não apaga a string, se eu copiar as duas para a mesma string ocorre uma concatenação.
         OK = copiaString(&S1,&S3);
         OK1 = copiaString(&S2,&S3);


         if ((OK == TRUE)&&(OK1== TRUE))
         {
            printf("\n\n");
            imprimeLista(S3);
            printf("\n\n");
         }else
         {
          printf("\n\n");
          printf("Ocorreu um erro.\n");
          printf("\n\n");
         }
        }
            printf("\n\n");
            printf("Deseja Retornar ao menu ou sair?  1 - voltar / 2 - sair\n");
            scanf("%d", &sair);
            return sair;
        }


    if(opcao == 7)
        {
            i = 0;
            c = '\0';
            system("cls");
            OK = initString(&S1);
            OK1 = initString(&S2);
            printf("\n\n");
            printf("Criar S1, S2 intercala-las ...\n");
            printf("Obs: Como comentado na sala a forma de insercao deve ser concluida com um '.' .\n\n");
                if((OK == TRUE)&&(OK1 == TRUE))
                    {
                        printf("Lista S1 e S2 criadas com sucesso. \n");
                    }
            printf("\n\n");
            printf("insira a String[S1]:\n");
            scanf("%c",&c);
            if(OK == TRUE)
                {
                    OK = testavazio(S1);
                      if(OK == TRUE)
                            {
                                      for(i=0; i<=200 ;i++)
                                        {

                                            if(caracter!='.')
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }

                                                    OK = inserirItem(&S1,caracter);
                                                            if(OK == TRUE)
                                                            {
                                                                //printf("inserção[%i] realizada com sucesso.\n",i);
                                                            }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                }else
                                                {
                                                contpalavra++;
                                                break;
                                                }
                                        }
                                }else
                                {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S2.\n");
                                }
            printf("\n\n");
            printf("\n\n");
            contpalavra = 0;
            caracter = '\0';
            printf("insira a String[S2]:\n");
            scanf("%c",&c);
            if(OK1 == TRUE)
                {
                    OK = testavazio(S2);
                      if(OK == TRUE)
                            {
                                      for(i=0; i<=200 ;i++)
                                        {
                                            if(caracter!= 46)
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }

                                                    OK = inserirItem(&S2,caracter);
                                                            if(OK == TRUE)
                                                            {
                                                            //printf("inserção[%i] realizada com sucesso.\n",i);
                                                            }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                }else
                                                {
                                                contpalavra++;
                                                break;
                                                }

                                        }
                                }else
                                {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S1.\n");
                                }


                    printf("\n\n");
                    printf("\n\n");
                    }else
                    {
                    printf("erro na criacao da copia da lista.\n");
                    }
            printf("\n\n");
            intercalarFrases(S1,S2);
            printf("\n\n");
            printf("Deseja Retornar ao menu ou sair?  1 - voltar / 2 - sair\n");
            scanf("%d", &sair);
            return sair;
        }

        }

    if(opcao == 8)
        {
            int i,contpalavra = 0;
            c = '\0';
            caracter='\0';
            system("cls");
            OK = initString(&S1);
            printf("\n\n");
            printf("Inverter as palavras...\n");
            printf("Obs: Como comentado na sala a forma de insercao deve ser concluida com um '.' .\n\n");
                if(OK == TRUE)
                    {
                        printf("Lista criadas com sucesso. \n");
                    }
            printf("\n\n");
            printf("insira a String:\n");
            scanf("%c",&c);
                if(OK == TRUE)
                    {
                        OK = testavazio(S1);

                            if(OK == TRUE)
                                {
                                    for(i=0; i<=200 ;i++)
                                        {
                                            if(caracter!='.')
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }

                                                    OK = inserirItem(&S1,caracter);
                                                            if(OK == TRUE)
                                                            {
                                                                //printf("inserção[%i] realizada com sucesso.\n",i);
                                                            }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                }else
                                                {
                                                    contpalavra++;
                                                    break;
                                                }

                                        }
                                }
                                }else
                                {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S4.\n");
                                }
            inverterPalavras(S1);
            printf("\n\n");
            printf("Deseja Retornar ao menu ou sair?  1 - voltar / 2 - sair\n");
            scanf("%d", &sair);
            return sair;
      }


        if(opcao == 9)
        {
            int i,contpalavra = 0;
            c = '\0';
            caracter='\0';
            system("cls");
            OK = initString(&S1);
            printf("\n\n");
            printf("Inverter as letras das palavras...\n");
            printf("Obs: Como comentado na sala a forma de insercao deve ser concluida com um '.' .\n\n");
                if(OK == TRUE)
                    {
                        printf("Lista criadas com sucesso. \n");
                    }
            printf("\n\n");
            printf("insira a String:\n");
            scanf("%c",&c);
            if(OK == TRUE)
                {
                    OK = testavazio(S1);
                        if(OK == TRUE)
                            {
                                    for(i=0; i<=200 ;i++)
                                        {
                                            if(caracter!='.')
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }

                                                    OK = inserirItem(&S1,caracter);
                                                            if(OK == TRUE)
                                                            {
                                                                //printf("inserção[%i] realizada com sucesso.\n",i);
                                                            }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                }else
                                                {
                                                    contpalavra++;
                                                    break;
                                                }

                                        }
                            }
                                }else
                                {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S4.\n");
                                }
            inverterLetraPalavras(S1);
            printf("\n\n");
            printf("Deseja Retornar ao menu ou sair?  1 - voltar / 2 - sair\n");
            scanf("%d", &sair);
            return sair;
      }
    if( opcao == 10)
        {
        sair = 2;
        return sair;
        }

}
// ***********************************************
// ***********************************************
// ***********************************************
int main()
{

    int sair = 0;
    do
    {
        sair = menu();
    }while(sair != 2);




}

