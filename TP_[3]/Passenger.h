#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	unsigned int id;
	char name[50];
	char lastName[50];
	float price;
	char flyCode[9];
	char typePassenger[15];
	char statusFlight[12];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr, char* nameStr, char* lastNameStr, char* priceStr, char* flyCodeStr, char* typePassengerStr, char* statusFlightStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,unsigned int id);
int Passenger_getId(Passenger* this,unsigned int* id);

int Passenger_setName(Passenger* this,char* name);
int Passenger_getName(Passenger* this,char* name);

int Passenger_setLastName(Passenger* this,char* lastName);
int Passenger_getLastName(Passenger* this,char* lastName);

int Passenger_setPrice(Passenger* this,float price);
int Passenger_getPrice(Passenger* this,float* price);

int Passenger_setFlyCode(Passenger* this,char* flyCode);
int Passenger_getFlyCode(Passenger* this,char* flyCode);

int Passenger_setTypePassenger(Passenger* this,char* typePassenger);
int Passenger_getTypePassenger(Passenger* this,char* typePassenger);

int Passenger_setStatusFlight(Passenger* this,char* statusFlight);
int Passenger_getStatusFlight(Passenger* this,char* statusFlight);

#endif /* PASSENGER_H_ */
