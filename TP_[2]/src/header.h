/*
 * header.h
 *
 *  Created on: 13 may. 2022
 *      Author: Hugo
 */

#ifndef HEADER_H_
#define HEADER_H_
#define LEN 10

//ESTRUCTURAS--------------------------------------------------------
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger;
    int isEmpty;
}Passenger;
//ESTRUCTURAS--------------------------------------------------------


int menu();
int subMenu();


int initPassengers(Passenger* list, int len);
int findEmpty(Passenger* list, int len);

int findPassengerById(Passenger* list, int len);

int newPassenger(Passenger* newPassenger);
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);
int modifyPassenger(Passenger* list, int len, int index);
int removePassenger(Passenger* list, int len, int index);

int sortPassengers(Passenger* list, int len, int order);

int showPassenger(Passenger* list, int index);
int showPassengers(Passenger* list, int len);


int validateString(char string[], int minSize, int maxSize);
int validateFloat(float number, int minSize, int maxSize);
int validateInt(int number, int minSize, int maxSize);


#endif /* HEADER_H_ */
