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
	int dia;
	int mes;
	int anio;
}eFecha;

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
	char descripcionTipoArtista[51];
}eTipoArtista;

//ESTRUCTURAS---------------------------------------------------------------------------------------------------------

//PROTOTIPOS---------------------------------------------------------------------------------------------------------
void hardcodearTipoArtista(eTipoArtista listaTipoArtista[], int tam, int *codigoTA);
void hardcodearGenero(eGenero listaGeneros[], int tam, int *codigoG);
void hardcodearArtista(eArtista listaArtistas[], int tam, int *codigoA);
void hardcodearAlbumes(eAlbum listaAlbumes[]);
int inicializarEstructura(eAlbum listaAlbumes[], int tam);
int buscarEspacioVacioEstructura(eAlbum albumes[], int tam);
int altaEstructura(eAlbum albumes[], int tam, int* codigo, eGenero listaGeneros[], int tamGeneros,
		eArtista listaArtistas[],int tamArtistas, eTipoArtista listaTipoArtista[], int tamTipoArtista, int*codigoG, int*codigoA, int*codigoTA);
int bajaEstructura(eAlbum albumes[], int tam, int*codigo, eGenero listaGeneros[], int tamGeneros,
		eArtista listaArtistas[],int tamArtistas, eTipoArtista listaTipoArtista[], int tamTipoArtista, int*codigoG, int*codigoA);
int modificarEstructura(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGeneros, eArtista listaArtistas[],
		int tamArtistas, eTipoArtista listaTipoArtista[], int tamTipoArtista, int*codigoG, int*codigoA);
int cargaDescripcionTipoArtista(eTipoArtista listaTipoArtista[], int tam, int codigoTipoArtista, char descripcionTipoArtista[]);
int cargaNombreArtista(eArtista listaArtistas[], int tam, int codigoArtista, char nombreArtista[]);
int cargaDescripcionGenero(eGenero listaGeneros[], int tam, int codigoGenero, char descripcionGenero[]);

int menu();
int subMenuModificar();
char subMenuListar();
void mostrarTipoArtistas(eTipoArtista listaTiposArtistas[], int tam);
void mostrarGeneros(eGenero listaGeneros[], int tam);
void mostrarArtistas(eArtista listaArtistas[], int tam, eTipoArtista listaTipoArtista[], int tamTipoArtista, int* codigoTA);
void mostrarAlbum(eAlbum album[], int tam, int indice, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoG, int *codigoA);
void mostrarAlbumes(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int* codigoA, int* codigoG);
eFecha cargarFecha();

int validarNumero(int numero);
int validarNumeroRangos(int numero, int rangoMin, int rangoMax);
int validarCaracterOpciones(char caracter, char opcionA, char opcionB);
int validarCaracter(char caracter);
int validarCadena(char cadena[], int tam);


//PROTOTIPOS---------------------------------------------------------------------------------------------------------

#endif /* HEADER_H_ */
