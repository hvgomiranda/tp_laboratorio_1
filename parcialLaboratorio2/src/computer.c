/*
 * computer.c
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


eComputer* computer_new()
{
	eComputer* newComputer = (eComputer*) malloc(sizeof(eComputer));

	return newComputer;
}

eComputer* computer_newParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr)
{
	eComputer* newComputer = computer_new();
	if(newComputer!=NULL)
	{
		computer_setId(newComputer, atoi(idStr));
		computer_setDescripcion(newComputer, descripcionStr);
		computer_setPrecio(newComputer, atof(precioStr));
		computer_setIdTipo(newComputer, atoi(idTipoStr));
	}

	return newComputer;
}

void computer_delete(eComputer* computer)
{
	if(computer!=NULL)
	{
		free(computer);
	}
}

int computer_setId(eComputer* this, int id)
{
	int isOk=0;
	if(this!=NULL && id>0)
	{
		this->id=id;
		isOk=1;
	}
	return isOk;
}

int computer_setDescripcion(eComputer* this, char* descripcion)
{
	int isOk=0;

	if(this!=NULL && descripcion!=NULL && strlen(descripcion)>=3 && strlen(descripcion)<200)
	{
		strcpy(this->descripcion, descripcion);
		isOk=1;
	}
	return isOk;
}

int computer_setPrecio(eComputer* this, float precio)
{
	int isOk=0;
	if(this!=NULL && precio>=0)
	{
		this->precio=precio;
		isOk=1;
	}
	return isOk;
}

int computer_setIdTipo(eComputer* this, int idTipo)
{
	int isOk=0;
	if(this!=NULL && idTipo>0)
	{
		this->idTipo = idTipo;
		isOk=1;
	}
	return isOk;
}

int computer_getId(eComputer* this, int* id)
{
	int isOk=0;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		isOk=1;
	}
	return isOk;
}

int computer_getDescripcion(eComputer* this, char* descripcion)
{
	int isOk=0;
	if(this!=NULL && descripcion!=NULL)
	{
		strcpy(descripcion, this->descripcion);
		isOk=1;
	}
	return isOk;
}

int computer_getPrecio(eComputer* this, float* precio)
{
	int isOk=0;
	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		isOk=1;
	}
	return isOk;
}

int computer_getIdTipo(eComputer* this, int* idTipo)
{
	idTipo=0;
	if(this!=NULL)
	{
		*idTipo = this->idTipo;
	}
	return *idTipo;
}

int computer_showComputer(eComputer* computer)
{
	int isOk=0;
	int id;
	char descripcion[201];
	float precio;
	int idTipo;

	if(computer!=NULL)
	{
		if(computer_getId(computer, &id) &&
				computer_getDescripcion(computer, descripcion) &&
				computer_getPrecio(computer, &precio) &&
				computer_getIdTipo(computer, &idTipo))
		{
			if(idTipo==1)
			{
				printf("%d  %-30s    %.2f        Desktop", id, descripcion, precio);
			}
			else
			{
				printf("%d  %-30s    %.2f        Laptop", id, descripcion, precio);
			}
			isOk=1;

		}
	}
	return isOk;
}

int computer_compareTipoId(void* computer1, void* computer2)
{
	int isOk=0;

	if(((eComputer*) computer1)->idTipo > ((eComputer*) computer2)->idTipo)
	{
		isOk=1;
	}
	if(((eComputer*) computer1)->idTipo < ((eComputer*) computer2)->idTipo)
	{
		isOk=-1;
	}

	return isOk;
}
