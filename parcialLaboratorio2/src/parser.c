/*
 * parser.c
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

int parser_loadFromText(FILE* pFile, LinkedList* pArrayListComputer)
{
	int isOk=0;
	int size;
	char id[201];
	char descripcion[201];
	char precio[201];
	char idTipo[201];

	eComputer* auxComputer;

	if(pFile!=NULL && pArrayListComputer!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, descripcion, precio, idTipo);
		do
		{
			size = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, descripcion, precio, idTipo);
			auxComputer = computer_newParametros(id, descripcion, precio, idTipo);

			if(auxComputer!=NULL)
			{
				ll_add(pArrayListComputer, auxComputer);
				isOk=1;
			}
		}while(!feof(pFile));
	}
	return isOk;
}
