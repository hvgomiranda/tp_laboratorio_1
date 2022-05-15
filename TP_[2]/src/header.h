/*
 * header.h
 *
 *  Created on: 13 may. 2022
 *      Author: Hugo
 */

#ifndef HEADER_H_
#define HEADER_H_
#define LEN 2000

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

/// @brief genera un menú
///
/// @return retorna la eleccion del usuario
int menu();

/// @brief genera un menú
///
/// @return retorna la eleccion del usuario
int subMenu();

/// @brief inicializa la lista de pasajeros, pone todos los isEmpty en 1
///
/// @param list Passenger*
/// @param len int
/// @return retorna -1 si hay un error, 0 si está OK
int initPassengers(Passenger* list, int len);

/// @brief busca en la lista de pasajeros un elemento que tenga isEmpty en 1
///
/// @param list Passenger*
/// @param len int
/// @return retorna el índice de la lista de pasajeros que está vacío
int findEmpty(Passenger* list, int len);

/// @brief busca el índice del pasajero con una id determinada
///
/// @param list Passenger*
/// @param len int
/// @return retorna -1 si hay un error, el índice del pasajero con la id si está OK
int findPassengerById(Passenger* list, int len);

/// @brief pide al usuario los datos para generar un nuevo pasajero
///
/// @param newPassenger Passenger*
/// @return retorna -1 si hay un error, 0 si está OK
int newPassenger(Passenger* newPassenger);

/// @brief obtiene los elementos del pasajero ingresado en newPassenger y los pasa a la lista de pasajeros
///
/// @param list Passenger*
/// @param len int
/// @param id int
/// @param name char[]
/// @param lastName char[]
/// @param price float
/// @param typePassenger int
/// @param flycode char[]
/// @return retorna -1 si hay un error, 0 si está OK
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);

/// @brief modifica un pasajero elegido por el usuario
///
/// @param list Passenger*
/// @param len int
/// @param index int
/// @return retorna -1 si hay un error, 0 si está OK
int modifyPassenger(Passenger* list, int len, int index);

/// @brief remueve un pasajero elegido por el usuario
///
/// @param list Passenger*
/// @param len int
/// @param index int
/// @return retorna -1 si hay un error, 0 si está OK
int removePassenger(Passenger* list, int len, int index);

/// @brief ordena los pasajeros por apellido y tipo de pasajero según el orden que quiera el usuario
///
/// @param list Passenger*
/// @param len int
/// @param order int
/// @return retorna -1 si hay un error, 0 si está OK
int sortPassengers(Passenger* list, int len, int order);

/// @brief pide al usuario el orden con el que quiere trabajar en sortPassengers
///
/// @return el orden
int newOrder();

/// @brief lista el total y el promedio del precio de los pasajes y cuántos pasajeros superan el precio promedio
///
/// @param list Passenger*
/// @param len int
/// @return retorna -1 si hay un error, 0 si está OK
int averagePrice(Passenger* list, int len);

/// @brief muestra un pasajero
///
/// @param list Passenger*
/// @param index int
/// @return
int showPassenger(Passenger* list, int index);

/// @brief muestra todos los pasajeros de la lista de pasajeros
///
/// @param list Passenger*
/// @param len int
/// @return retorna -1 si hay un error, 0 si está OK
int showPassengers(Passenger* list, int len);

/// @brief valida si lo ingresado es un string entre un tamaño y otro tamaño
///
/// @param string char[]
/// @param minSize int
/// @param maxSize int
/// @return retorna 1 si TRUE y 0 si FALSE
int validateString(char string[], int minSize, int maxSize);

/// @brief valida si lo ingresado es un float entre un número y otro número
///
/// @param number float
/// @param minSize int
/// @param maxSize int
/// @return retorna 1 si TRUE y 0 si FALSE
int validateFloat(float number, int minSize, int maxSize);

/// @brief valida si lo ingresado es un int entre un número y otro número
///
/// @param number int
/// @param minSize int
/// @param maxSize int
/// @return retorna 1 si TRUE y 0 si FALSE
int validateInt(int number, int minSize, int maxSize);

/// @brief valida si lo ingresado es un char entre dos opciones
///
/// @param character char
/// @param optionA char
/// @param optionB char
/// @return retorna 1 si TRUE y 0 si FALSE
int validateChar(char character, char optionA, char optionB);

#endif /* HEADER_H_ */
