#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));

	return passenger;
}

Passenger* Passenger_newParametros(char* idStr, char* nameStr, char* lastNameStr, char* priceStr, char* flyCodeStr, char* typePassengerStr, char* statusFlightStr)
{
	Passenger* aPassenger = Passenger_new();

	Passenger_setId(aPassenger, atoi(idStr));
	Passenger_setName(aPassenger, nameStr);
	Passenger_setLastName(aPassenger, lastNameStr);
	Passenger_setPrice(aPassenger, atof(priceStr));
	Passenger_setFlyCode(aPassenger, flyCodeStr);
	Passenger_setTypePassenger(aPassenger, typePassengerStr);
	Passenger_setStatusFlight(aPassenger, statusFlightStr);

	return aPassenger;
}

void Passenger_delete(Passenger* this)
{
	free(this);
}

int Passenger_setId(Passenger* this,unsigned int id)
{
	int retorno=-1;
	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,unsigned int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int Passenger_setName(Passenger* this,char* name)
{
	int retorno=-1;
	if(this!=NULL && name!=NULL)
	{
		strcpy(this->name, name);
		retorno=0;
	}
	return retorno;
}

int Passenger_getName(Passenger* this,char* name)
{
	int retorno=-1;
	if(this!=NULL && name!=NULL)
	{
		strcpy(name, this->name);
		retorno=0;
	}
	return retorno;
}

int Passenger_setLastName(Passenger* this,char* lastName)
{
	int retorno=-1;
	if(this!=NULL && lastName!=NULL)
	{
		strcpy(this->lastName, lastName);
		retorno=0;
	}
	return retorno;
}

int Passenger_getLastName(Passenger* this,char* lastName)
{
	int retorno=-1;
	if(this!=NULL && lastName!=NULL)
	{
		strcpy(lastName, this->lastName);
		retorno=0;
	}
	return retorno;
}

int Passenger_setPrice(Passenger* this,float price)
{
	int retorno=-1;
	if(this!=NULL && price>0)
	{
		this->price=price;
		retorno=0;
	}
	return retorno;
}

int Passenger_getPrice(Passenger* this,float* price)
{
	int retorno=-1;
	if(this!=NULL && price!=NULL)
	{
		*price=this->price;
		retorno=0;
	}
	return retorno;
}

int Passenger_setFlyCode(Passenger* this,char* flyCode)
{
	int retorno=-1;
	if(this!=NULL && flyCode!=NULL)
	{
		strcpy(this->flyCode,flyCode);
		retorno=0;
	}
	return retorno;
}

int Passenger_getFlyCode(Passenger* this,char* flyCode)
{
	int retorno=-1;
	if(this!=NULL && flyCode!=NULL)
	{
		strcpy(flyCode,this->flyCode);
		retorno=0;
	}
	return retorno;
}

int Passenger_setTypePassenger(Passenger* this,char* typePassenger)
{
	int retorno=-1;
	if(this!=NULL && typePassenger!=NULL)
	{
		strcpy(this->typePassenger,typePassenger);
		retorno=0;
	}
	return retorno;
}

int Passenger_getTypePassenger(Passenger* this,char* typePassenger)
{
	int retorno=-1;
	if(this!=NULL && typePassenger!=NULL)
	{
		strcpy(typePassenger,this->typePassenger);
		retorno=0;
	}
	return retorno;
}

int Passenger_setStatusFlight(Passenger* this,char* statusFlight)
{
	int retorno=-1;
	if(this!=NULL && statusFlight!=NULL)
	{
		strcpy(this->statusFlight,statusFlight);
		retorno=0;
	}
	return retorno;
}

int Passenger_getStatusFlight(Passenger* this,char* statusFlight)
{
	int retorno=-1;
	if(this!=NULL && statusFlight!=NULL)
	{
		strcpy(statusFlight,this->statusFlight);
		retorno=0;
	}
	return retorno;
}
