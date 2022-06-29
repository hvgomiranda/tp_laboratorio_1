#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include "header.h"

int menu()
{
    int opcion;
    system("cls");
    printf("1. Alta\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informar\n");
    printf("5. Alta forzada\n");
    printf("6. Salir\n\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

int subMenu()
{
    int opcion;
    system("cls");
    printf("1. Listado de los pasajeros ordenados alfabeticamente por apellido y tipo de pasajero.\n");
    printf("2. Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n");
    printf("3. Listado de los pasajeros por codigo de vuelo y estados de vuelos 'ACTIVO'\n");
    printf("4. Salir\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int validateString(char string[])
{
	int result=1;

	for(int i=0;i<strlen(string);i++)
	{
		if((!isalpha(string[i])) || strlen(string)<=2)
		{
			result=0;
			break;
		}
	}
	return result;
}

int validateInt(char number[], int minSize, int maxSize)
{
	int result=0;
	int size = strlen(number);

	for(int i=0;i<size;i++)
	{
		if(!isdigit(number[i]))
		{
			break;
		}
		else
		{
			result=1;
		}
	}

	if(result)
	{
		result = atoi(number);
		if(!(result>minSize && result<maxSize))
		{
			result = 0;
		}
	}

	return result;
}

int validateCharOptions(char character, char optionA, char optionB)
{
	int ok=0;
	if(character == optionA || character == optionB)
	{
		ok=1;
	}
	else
	{
		system("cls");
		printf("Error, intente nuevamente.\n\n");
		system("pause");
	}
	return ok;
}

int validateFloat(char number[], int minSize, int maxSize)
{
	int result=0;
	int size = strlen(number);

	for(int i=0;i<size;i++)
	{
		if(!isdigit(number[i]))
		{
			break;
		}
		else
		{
			result=1;
		}
	}

	if(result)
	{
		result = atof(number);
		if(!(result>minSize && result<maxSize))
		{
			result = 0;
		}
	}

	return result;
}

int validateAlphanum(char string[])
{
	int result=0;
	int size = strlen(string);
	for(int i=0;i<size;i++)
	{
		if((isdigit(string[i]) || isalpha(string[i])) && (size>2))
		{
			result=1;
		}
		else
		{
			result=0;
			break;
		}
	}
	return result;
}
