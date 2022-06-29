/*
 * controller.c
 *
 *  Created on: 28 jun. 2022
 *      Author: Hugo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"
#include "computer.h"

int controller_loadFromText(LinkedList* pArrayListComputer)
{
	int isOk=0;
	FILE* pFile = NULL;

	if(pArrayListComputer!=NULL)
	{
		pFile = fopen("datos_SP.csv", "r");
		if(pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			if(parser_loadFromText(pFile, pArrayListComputer))
			{
				printf("Carga exitosa\n");
				isOk=1;
			}
		}
	}
	fclose(pFile);
	return isOk;
}

int controller_listComputer(LinkedList* pArrayListComputer)
{
	int isOk=0;
	int size;
	eComputer* auxComputer=NULL;
	if(pArrayListComputer != NULL)
	{
		size = ll_len(pArrayListComputer);
		printf("------------------------------------\n");
		printf("         LISTA DE COMPUTADORAS      \n");
		printf("ID   DESCRIPCION    PRECIO    TIPO  \n");

		for(int i=0; i<size; i++)
		{
			auxComputer = (eComputer*) ll_get(pArrayListComputer, i);
			computer_showComputer(auxComputer);
		}
		isOk=1;
	}
	return isOk;
}


int controller_saveAsText(char* path, LinkedList* pArrayListComputer)
{
	int isOk=0;
	FILE* pFile;
	int id;
	char descripcion[201];
	float precio;
	int idTipo;
	int size;

	eComputer* auxComputer;

	if(path!=NULL && pArrayListComputer!=NULL)
	{
		pFile = fopen("datos_SP.csv", "w");
		if(pFile==NULL)
		{
			printf("Error, no se pudo abrir el archivo\n");
		}

		fprintf(pFile, "id,descripcion,precio,idTipo");

		size=ll_len(pArrayListComputer);

		for(int i=0; i<size; i++)
		{
			auxComputer = ll_get(pArrayListComputer, i);
			if(computer_getId(auxComputer, &id) &&
					computer_getDescripcion(auxComputer, descripcion) &&
					computer_getPrecio(auxComputer, &precio) &&
					computer_getIdTipo(auxComputer, &idTipo))
			{
				fprintf(pFile, "%d,%s,%f,%d\n", id, descripcion, precio, idTipo);
				isOk=1;
			}
		}
		fclose(pFile);
	}
	return isOk;
}
