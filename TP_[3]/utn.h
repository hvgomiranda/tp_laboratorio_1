/*
 * utn.h
 *
 *  Created on: 10 jun. 2022
 *      Author: Hugo
 */

int utn_getInteger(int* integer, char* message, int min, int max);
int utn_getFloat(float* floatNumber, char* message, int min, int max);
int utn_getString(char* string, char* message, int min, int max);
int utn_validateChar(char string[]);
