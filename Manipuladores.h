#ifndef MANIPULADORES_H_INCLUDED
#define MANIPULADORES_H_INCLUDED

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


#endif // MANIPULADORES_H_INCLUDED
