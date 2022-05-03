/*
 * validaciones.c
 *
 *  Created on: 30 abr. 2022
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

int validarNumero(int numero)
{
	int retorno;
	retorno = 0;
	if(!isdigit(numero))
	{
		retorno = 1;
	}
	else
	{
		system("cls");
		printf("Error, intente nuevamente.\n");
		system("pause");
	}
	return retorno;
}

int validarNumeroRangos(int numero, int rangoMin, int rangoMax)
{
	int retorno;
	retorno = 0;
	if(!isdigit(numero)&&numero>rangoMin&&numero<=rangoMax)
	{
		retorno = 1;
	}
	else
	{
		system("cls");
		printf("Error, intente nuevamente.\n");
		system("pause");
	}
	return retorno;
}

int validarCaracterOpciones(char caracter, char opcionA, char opcionB)
{
	int retorno=0;
	if(caracter == opcionA || caracter == opcionB)
	{
		retorno=1;
	}
	else
	{
		system("cls");
		printf("Error, intente nuevamente.\n");
		system("pause");
	}
	return retorno;
}

int validarCaracter(char caracter)
{
	int retorno=0;
	if(isalpha(caracter))
	{
		retorno=1;
	}
	else
	{
		system("cls");
		printf("Error, intente nuevamente.\n");
		system("pause");
	}
	return retorno;
}

int validarCadena(char cadena[], int tam)
{
	int retorno;
	retorno = 0;
	if(cadena!=NULL && strlen(cadena)>0 && strlen(cadena)<=tam)
	{
		retorno = 1;
	}
	else
	{
		system("cls");
		printf("Incorreto, intente nuevamente.\n");
		system("pause");
	}
	return retorno;
}
