/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Hugo Miranda Campos
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Parser.h"
#include "utn.h"



//CONSTRUCTORES Y DESTRUCTOR-----------------------------------------------------------------------------
//CONSTRUCTOR SIN PARAMETROS-----------------------------------------------------------------------------
Passenger* Passenger_new()
{
	Passenger* aPassenger;
	aPassenger = (Passenger*) malloc(sizeof(Passenger));

	return aPassenger;
}
//-------------------------------------------------------------------------------------------------------
//CONSTRUCTOR CON PARAMETROS-----------------------------------------------------------------------------
Passenger* Passenger_newParametros(char* idStr, char* nameStr, char* lastNameStr, char* priceStr, char* flycodeStr, char* typePassengerStr, char* statusFlightStr)
{
	Passenger* aPassenger = NULL;
	aPassenger = Passenger_new();

	if(!Passenger_setId(aPassenger, atoi(idStr)))
	{
		Passenger_delete(aPassenger);
		printf("Hubo un error al cargar el id\n");
	}
	else if(!Passenger_setName(aPassenger, nameStr))
	{
		Passenger_delete(aPassenger);
		printf("Hubo un error al cargar el nombre\n");
	}
	else if(!Passenger_setLastName(aPassenger, lastNameStr))
	{
		Passenger_delete(aPassenger);
		printf("Hubo un error al cargar el apellido\n");
	}
	else if(!Passenger_setPrice(aPassenger, atof(priceStr)))
	{
		Passenger_delete(aPassenger);
		printf("Hubo un error al cargar el precio\n");
	}
	else if(!Passenger_setFlycode(aPassenger, flycodeStr))
	{
		Passenger_delete(aPassenger);
		printf("Hubo un error al cargar el codigo de vuelo\n");
	}
	else if(!Passenger_setTypePassenger(aPassenger, typePassengerStr))
	{
		Passenger_delete(aPassenger);
		printf("Hubo un error al cargar el tipo de pasajero\n");
	}
	else if(!Passenger_setStatusFlight(aPassenger, statusFlightStr))
	{
		Passenger_delete(aPassenger);
		printf("Hubo un error al cargar el estado de vuelo\n");
	}

	return aPassenger;
}
//-------------------------------------------------------------------------------------------------------
//DESTRUCTOR---------------------------------------------------------------------------------------------
void Passenger_delete(Passenger* this)
{
	free(this);
}
//-------------------------------------------------------------------------------------------------------

//SETTERS------------------------------------------------------------------------------------------------
//ID-----------------------------------------------------------------------------------------------------
int Passenger_setId(Passenger* this, int id)
{
	int isOk = 0;

	if(this!=NULL && id>0)
	{
		isOk = 1;
		this->id = id;
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//NAME---------------------------------------------------------------------------------------------------
int Passenger_setName(Passenger* this, char* name)
{
	int isOk = 0;

	if(this!=NULL)
	{
		isOk = 1;
		strcpy(this->name, name);
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//LAST NAME----------------------------------------------------------------------------------------------
int Passenger_setLastName(Passenger* this, char* lastName)
{
	int isOk = 0;

	if(this!=NULL)
	{
		isOk = 1;
		strcpy(this->lastName, lastName);
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//PRICE--------------------------------------------------------------------------------------------------
int Passenger_setPrice(Passenger* this, float price)
{
	int isOk = 0;

	if(this!=NULL && price>0 && price<99999)
	{
		isOk = 1;
		this->price = price;
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//FLYCODE------------------------------------------------------------------------------------------------
int Passenger_setFlycode(Passenger* this, char* flycode)
{
	int isOk = 0;

	if(this!=NULL)
	{
		isOk = 1;
		strcpy(this->flycode, flycode);
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//TYPE PASSENGER-----------------------------------------------------------------------------------------
int Passenger_setTypePassenger(Passenger* this, char* typePassenger)
{
	int isOk = 0;

	if(this!=NULL)
	{
		isOk = 1;
		strcpy(this->typePassenger, typePassenger);
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//STATUS FLIGHT------------------------------------------------------------------------------------------
int Passenger_setStatusFlight(Passenger* this, char* statusFlight)
{
	int isOk = 0;

	if(this!=NULL)
	{
		isOk = 1;
		strcpy(this->statusFlight, statusFlight);
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------

//GETTERS------------------------------------------------------------------------------------------------
//ID-----------------------------------------------------------------------------------------------------
int Passenger_getId(Passenger* this, int* id)
{
	int isOk = 0;

	if(this!=NULL && id!=NULL)
	{
		isOk = 1;
		*id = this->id;
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//NAME---------------------------------------------------------------------------------------------------
int Passenger_getName(Passenger* this, char* name)
{
	int isOk = 0;

	if(this!=NULL && name!=NULL)
	{
		isOk = 1;
		strcpy(name, this->name);
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//LAST NAME----------------------------------------------------------------------------------------------
int Passenger_getLastName(Passenger* this, char* lastName)
{
	int isOk = 0;

	if(this!=NULL && lastName!=NULL)
	{
		isOk = 1;
		strcpy(lastName, this->lastName);
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//PRICE--------------------------------------------------------------------------------------------------
int Passenger_getPrice(Passenger* this, float* price)
{
	int isOk = 0;

	if(this!=NULL && price!=NULL)
	{
		isOk = 1;
		*price = this->price;
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//FLYCODE------------------------------------------------------------------------------------------------
int Passenger_getFlycode(Passenger* this, char* flycode)
{
	int isOk = 0;

	if(this!=NULL && flycode!=NULL)
	{
		isOk = 1;
		strcpy(flycode, this->flycode);
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//TYPE PASSENGER-----------------------------------------------------------------------------------------
int Passenger_getTypePassenger(Passenger* this, char* typePassenger)
{
	int isOk = 0;

	if(this!=NULL && typePassenger!=NULL)
	{
		isOk = 1;
		strcpy(typePassenger, this->typePassenger);
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//STATUS FLIGHT------------------------------------------------------------------------------------------
int Passenger_getStatusFlight(Passenger* this, char* statusFlight)
{
	int isOk = 0;

	if(this!=NULL && statusFlight!=NULL)
	{
		isOk = 1;
		strcpy(statusFlight, this->statusFlight);
	}

	return isOk;
}
//-------------------------------------------------------------------------------------------------------
//PRINT--------------------------------------------------------------------------------------------------
void Passenger_printOne(Passenger* aPassenger)
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[8];
	char typePassenger[21];
	char statusFlight[21];

	Passenger_getId(aPassenger, &id);
	Passenger_getName(aPassenger, name);
	Passenger_getLastName(aPassenger, lastName);
	Passenger_getPrice(aPassenger, &price);
	Passenger_getFlycode(aPassenger, flycode);
	Passenger_getTypePassenger(aPassenger, typePassenger);
	Passenger_getStatusFlight(aPassenger, statusFlight);

	printf("%4d %10s %10s %5f %10s %10s %10s\n", id,
											   name,
											   lastName,
											   price,
											   flycode,
											   typePassenger,
											   statusFlight);
}
//-------------------------------------------------------------------------------------------------------
//FUNCION ADICIONAL--------------------------------------------------------------------------------------
/*int isAName(char* name)
{
	int isOk = 1;

    for(int i=0; i < strlen(name); i++)
    {
        if(!(isalpha(name[i]) || isblank(name[i])))
        {
            isOk = 0;
            break;
        }
    }

    return isOk;
}*/
//-------------------------------------------------------------------------------------------------------
