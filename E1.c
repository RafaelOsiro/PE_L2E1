/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 1. Leia o nome completo de 2 pessoas e apresente o primeiro nome somente em letras maiúsculas e
 na linha seguinte, com uma tabulação, o segundo nome em letras minúsculas, solicitando outros nomes caso o
  usuário deseje. Somente devem ser usadas funções do padrão ANSI da linguagem C.
*/

//!LIBRARIES _______________________________________________________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________
void messageTitle();
void messageMenu();
void messageNameInput(int index);
void messageConfirmExit();
void messageExit();


//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________
void errorMessageInput(int quantityOfError);
void errorExit();

//! VALIDATION INPUT __________________________________________________________________________________________

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________
int functionOptionInput();



int main()
{
    int option, quantityOfError = 0;
    char name[2][50];
    bool validation = false;

    do
    {
        messageTitle();
        messageMenu();
        option = functionOptionInput();

        switch (option)
        {
        case 1: //TODO: ENTRADA DE DADOS
            system("cls");
            quantityOfError = 0;
            /* code */
            break;
        
        case 2:
            system("cls");
            quantityOfError = 0;
            
            do
            {
                messageConfirmExit();
                option = functionOptionInput();

                if (option == 1)
                {
                    validation = true;
                }
                else if(option == 2)
                {
                    validation = false;
                }
                else
                {
                    quantityOfError++;
                    errorMessageInput(quantityOfError);

                    if (quantityOfError == 3)
                    {
                        errorExit();
                        exit(EXIT_FAILURE);
                    }    
                }

            } while (option != 1 || option != 2);

            system("cls");
            quantityOfError = 0;
            
            break;

        default:    //TODO: ERRO DO SISTEMA
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
            break;
        }
    
    } while (validation == false);
    
    messageExit();
    exit(EXIT_SUCCESS);
}

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________

//  MESSAGE TITLE OF THE SYSTEM
void messageTitle()
{
    printf("SISTEMA PARA FORMATAR OS NOMES\n\n\n");
}

//  MESSAGE MENU
void messageMenu()
{
    printf("---------------------------------\n");
    printf("[1] ENTRADA DE NOMES E FORMATA\200\307O\n");
    printf("[2] SAIR DO PROGRAMA\n");
    printf("---------------------------------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE ASK NAME INPUT
void messageNameInput(int index)
{
    printf("DIGITE O NOME DO USU\265RIO %d:", index);
}

//  MESSAGE ASK CONFIRM EXIT OF THE SYSTEM
void messageConfirmExit()
{
    printf("DESEJA CONFIRMAR A SA\326DA DO SISTEMA?\n\n");
    printf("-------\n");
    printf("[1] SIM\n");
    printf("[2] N\3070\n");
    printf("-------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE TO EXIT SYSTEM
void messageExit()
{
    printf("O SISTEMA IR\265 FINALIZAR\n");
}


//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________

//  ERROR MESSAGE INPUT
void errorMessageInput(int quantityOfError)
{
    printf("ERRO %d de 3!\n", quantityOfError);
    printf("DIGITE UMA OP\200\307O V\265LIDA\n\n\n");
}

//  ERROR EXIT SYSTEM
void errorExit()
{
    printf("QUANTIDADE DE ERROS ATINGIDO!\n");
    printf("O SISTEMA IR\265 FINALIZAR!\n\n\n");
}

//! VALIDATION INPUT __________________________________________________________________________________________



//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________

//  FUNCTION OPTION INPUT
int functionOptionInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}


