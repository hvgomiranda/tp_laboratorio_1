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
    printf("5. Salir\n\n");
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
    printf("3. Listado de los pasajeros por codigo de vuelo y estados de vuelos ‘ACTIVO’,\n");
    printf("4. Salir\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int validateString(char string[], int minSize, int maxSize)
{
	return strlen(string)>minSize && strlen(string)<maxSize;
}

int validateFloat(float number, int minSize, int maxSize)
{
	return number>minSize&&number<maxSize;
}

int validateInt(int number, int minSize, int maxSize)
{
	return number>minSize&&number<maxSize;
}

int validateChar(char character, char optionA, char optionB)
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
