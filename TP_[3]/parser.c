#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Parser.h"
#include "utn.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int isOk = 0;

	char id[100];
	char name[100];
	char lastName[100];
	char price[100];
	char flycode[100];
	char typePassenger[100];
	char statusFlight[100];
	char false[1000];
	Passenger* aPassenger = NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		isOk = 1;
		//falsa lectura
		fscanf(pFile, "%[^\n]\n", false);
		do
		{

			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName, price, flycode, typePassenger, statusFlight) == 7)
			{
				aPassenger = Passenger_newParametros(id, name, lastName, price, flycode, typePassenger, statusFlight);
				ll_add(pArrayListPassenger, aPassenger);
			}
			else
			{
				printf("Hubo un error al leer el archivo.\n");
			}

		}while(!feof(pFile));
	}

    return isOk;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int isOk=0;
	int success;
	Passenger* aPassenger = NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		success=0;
		do
		{
			aPassenger = Passenger_new();
			if(aPassenger!=NULL)
			{
				success = fread(aPassenger, sizeof(Passenger), 1, pFile);
				if(success)
				{
					ll_add(pArrayListPassenger, aPassenger);
				}
				else
				{
					Passenger_delete(aPassenger);
					break;
				}
				isOk=1;
			}
		}while(!feof(pFile));

	}
	return isOk;
}

int parser_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int isOk = 0;
	int size;
	char id[100];
	char name[100];
	char lastName[100];
	char price[100];
	char flycode[100];
	char typePassenger[100];
	char statusFlight[100];
	Passenger* aPassenger = NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		size = ll_len(pArrayListPassenger);

		fprintf(pFile, "id,name,lastName,price,flycode,typePassenger,statusFlight\n");

		for(int i=0; i<size; i++)
		{
			aPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

			if(Passenger_getId(aPassenger, id) &&
				Passenger_getName(aPassenger, name) &&
				Passenger_getLastName(aPassenger, lastName) &&
				Passenger_getPrice(aPassenger, price) &&
				Passenger_getFlycode(aPassenger, flycode) &&
				Passenger_getStatusFlight(aPassenger, statusFlight) &&
				Passenger_getTypePassenger(aPassenger, typePassenger))
			{
				fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s", *id, name, lastName, *price, flycode, statusFlight, typePassenger);
			}
		}
		isOk=1;
	}
	return isOk;
}

int parser_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int isOk=0;
	int size;
	Passenger* aPassenger;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		size = ll_len(pArrayListPassenger);

		for(int i=0; i<size; i++)
		{
			aPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

			if(aPassenger != NULL)
			{
				fwrite(aPassenger, sizeof(Passenger), 1, pFile);
			}
		}
		isOk=1;
	}
	return isOk;
}
