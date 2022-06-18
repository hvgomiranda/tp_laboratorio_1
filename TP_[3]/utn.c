#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Parser.h"
#include "utn.h"

int utn_getInteger(int* integer, char* message, int min, int max)
{
	int isOk = 0;
	int* auxInteger = (int*) malloc(sizeof(int));

	if(integer!=NULL && auxInteger!=NULL && message!=NULL)
	{
		isOk = 1;
		printf("%s", message);
		scanf("%d", auxInteger);
		while(*auxInteger<min || *auxInteger>max)
		{
			printf("Error.\n %s (minimo %d y maximo %d)", message, min, max);
			scanf("%d", auxInteger);
		}
		printf("HOLA %d\n", *auxInteger);
		*integer = *auxInteger;
	}

	free(auxInteger);
	return isOk;
}

int utn_getFloat(float* floatNumber, char* message, int min, int max)
{
	int isOk = 0;
	float* auxFloat = (float*) malloc(sizeof(float));

	if(floatNumber!=NULL && auxFloat!=NULL && message!=NULL)
	{
		isOk = 1;

		printf("%s: ", message);
		scanf("%f", auxFloat);
		while(*auxFloat<min || *auxFloat>max)
		{
			printf("Error.\n %s (minimo %d y maximo %d)", message, min, max);
			scanf("%f", auxFloat);
		}
		*floatNumber = *auxFloat;
	}

	free(auxFloat);
	return isOk;
}

int utn_getString(char* string, char* message, int min, int max)
{
	int isOk = 0;
	char* auxString = (char*) malloc(sizeof(char)*100);

	if(string!=NULL && auxString!=NULL && message!=NULL)
	{
		isOk = 1;
		printf("%s", message);
		fflush(stdin);
		gets(auxString);
		while(strlen(auxString)<min || strlen(auxString)>max)
		{
			printf("Error.\n %s (caracteres minimo %d y maximo %d)", message, min, max);
			fflush(stdin);
			gets(auxString);
		}
		strcpy(string, auxString);
	}

	free(auxString);
	return isOk;
}

int utn_validateChar(char string[])
{
    int isOk = 1;
    int* i = (int*) malloc(sizeof(int));

    if(i != NULL)
    {
        while(string[*i] != '\0')
        {
            if((string[*i] != ' ') && (string[*i] < 'a' || string[*i] > 'z') && (string[*i] < 'A' || string[*i] > 'Z'))
            {
                isOk = 0;
                break;
            }
            (*i)++;
        }
    }
    free(i);

    return isOk;
}

int ask(char* message)
{
    char input;

    if(message != NULL)
    {
        printf("%s s/n: ", message);
        fflush(stdin);
        input = getchar();
        input = tolower(input);
        while (input != 'n' && input != 's')
        {
            printf("%s s/n: ", message);
            fflush(stdin);
            input = getchar();
            input = tolower(input);
        }
    }
    return input == 's';
}
