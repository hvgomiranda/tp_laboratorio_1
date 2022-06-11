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
		//falsa lectura
		isOk = 1;
		fscanf(pFile, "%[^\n]\n", false);
		while(!feof(pFile))
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
		}
	}

    return isOk;//qué devuelve
}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	//programar a lo último
    return 1;
}
