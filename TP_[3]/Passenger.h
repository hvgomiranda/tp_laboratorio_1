/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[8];
	char typePassenger[21];
	char statusFlight[21];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nameStr, char* lastNameStr, char* priceStr, char* flycodeStr, char* typePassengerStr, char* statusFlightStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);

int Passenger_setName(Passenger* this, char* name);
int Passenger_getName(Passenger* this, char* name);

int Passenger_setLastName(Passenger* this, char* lastName);
int Passenger_getLastName(Passenger* this, char* lastName);

int Passenger_setPrice(Passenger* this, float price);
int Passenger_getPrice(Passenger* this, float* price);

int Passenger_setFlycode(Passenger* this, char* flycode);
int Passenger_getFlycode(Passenger* this, char* flycode);

int Passenger_setTypePassenger(Passenger* this, char* TypePassenger);
int Passenger_getTypePassenger(Passenger* this, char* TypePassenger);

int Passenger_setStatusFlight(Passenger* this, char* statusFlight);
int Passenger_getStatusFlight(Passenger* this, char* statusFlight);

void Passenger_printOne(Passenger* aPassenger);
//int isAName(char* name);

#endif /* PASSENGER_H_ */
