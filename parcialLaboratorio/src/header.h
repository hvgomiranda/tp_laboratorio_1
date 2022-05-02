/*
 * header.h
 *
 *  Created on: 30 abr. 2022
 *      Author: Hugo
 */

#ifndef HEADER_H_
#define HEADER_H_
#define TAM 50
#define LIBRE 0
#define OCUPADO 1
#define TAMARTISTAS 10
#define TAMTIPOARTISTAS 2
#define TAMGENERO 6

//ESTRUCTURAS---------------------------------------------------------------------------------------------------------
typedef struct
{
	int codigoArtista;
	char nombre[51];
	//foraneo
	int codigoTipoArtista;
}eArtista;

typedef struct
{
	int codigoAlbum;
	char titulo[51];
	float importe;
	int estado;
	//estructura externa
	eFecha fecha;
	//foraneo
	int codigoArtista;
	int codigoGenero;
}eAlbum;

typedef struct
{
	int codigoGenero;
	char descripcionGenero[51];
}eGenero;

typedef struct
{
	int codigoTipoArtista;
	char descripcionTipoArtista;
}eTipoArtista;

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;
//ESTRUCTURAS---------------------------------------------------------------------------------------------------------

//PROTOTIPOS---------------------------------------------------------------------------------------------------------
void hardcodearTipoArtista(eTipoArtista listaTipoArtista[], int tam);
void hardcodearGenero(eGenero listaGeneros[], int tam);
void hardcodearArtista(eArtista listaArtistas[], int tam);

//PROTOTIPOS---------------------------------------------------------------------------------------------------------
#endif /* HEADER_H_ */
