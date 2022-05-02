/*
 * validaciones.c
 *
 *  Created on: 30 abr. 2022
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

int validarNumero(int numero)
{
	int retorno;
	retorno = 0;
	if(isdigit(numero))
	{
		retorno = 1;
	}
	else
	{
		system("cls");
		printf("Error, intente nuevamente.\n");
	}
	return retorno;
}

int validarNumeroRangos(int numero, int rangoMin, int rangoMax)
{
	int retorno;
	retorno = 0;
	if(numero>rangoMin&&numero<=rangoMax)
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

int validarFloat(float flotante)
{

}

int validarCaracter(char caracter)
{

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
