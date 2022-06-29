/*
 * computer.h
 *
 *  Created on: 28 jun. 2022
 *      Author: Hugo
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_

typedef struct
{
	int id;
	char descripcion[201];
	float precio;
	int idTipo;
}eComputer;

eComputer* computer_new();
eComputer* computer_newParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr);
void computer_delete(eComputer* computer);
int computer_setId(eComputer* this, int id);
int computer_setDescripcion(eComputer* this, char* descripcion);
int computer_setPrecio(eComputer* this, float precio);
int computer_setIdTipo(eComputer* this, int idTipo);
int computer_getId(eComputer* this, int* id);
int computer_getDescripcion(eComputer* this, char* descripcion);
int computer_getPrecio(eComputer* this, float* precio);
int computer_getIdTipo(eComputer* this, int* idTipo);
int computer_showComputer(eComputer* computer);
int computer_compareTipoId(void* computer1, void* computer2);
int pedirString(char cadena[], char mensaje[], int limite);


#endif /* COMPUTER_H_ */
