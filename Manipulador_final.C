/*
* Programa de Teste.
* By - José Olimpio M. Negrão
* Gmail - joseolimpionegrao@gmail.com
* Trabalho - "Manipulador de Strings."
* Orientado por : Profº Apolinário.
* UFBA - 01/2013
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Manipuladores.h"




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

