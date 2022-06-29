#include "parser.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int isOk=0,
		errorFlag=0;

	char id[6],
		 name[50],
		 lastName[50],
		 price[14],
		 flyCode[9],
		 typePassenger[15],
		 statusFlight[12];

	Passenger* newPassenger=NULL;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName, price, flyCode, typePassenger, statusFlight);
	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName, price, flyCode, typePassenger, statusFlight);
		newPassenger = Passenger_newParametros(id, name, lastName, price, flyCode, typePassenger, statusFlight);
		if(newPassenger!=NULL)
			ll_add(pArrayListPassenger,newPassenger);
		else
			errorFlag=1;
	}
	if(errorFlag==1)
		isOk=-1;

	Passenger_delete(newPassenger);

    return isOk;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int isOk=0,
		errorFlag=0;
	char aux[59];

	Passenger* newPassenger=NULL;

	fread(aux, sizeof(aux), 1, pFile);
	while(!feof(pFile))
	{
		newPassenger = Passenger_new();
		if(newPassenger!=NULL)
		{
			if(fread(newPassenger, sizeof(Passenger),1,pFile))
					ll_add(pArrayListPassenger,newPassenger);
		}
		else
			errorFlag=1;
	}

	if(errorFlag==1)
		isOk=-1;

	Passenger_delete(newPassenger);

    return isOk;
}
