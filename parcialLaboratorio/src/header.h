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
#define TAMTIPOALBUMES 3

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
	int codigoTipoAlbum;
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

typedef struct
{
	int id;
	char descripcionTipoAlbum[51];
}eTipoAlbum;

//ESTRUCTURAS---------------------------------------------------------------------------------------------------------

//PROTOTIPOS---------------------------------------------------------------------------------------------------------
//ESTRUCTURAS--------------------------------------------------------------------------------------------------------
void hardcodearTipoArtista(eTipoArtista listaTipoArtista[], int tam, int *codigoTA);
void hardcodearGenero(eGenero listaGeneros[], int tam, int *codigoG);
void hardcodearArtista(eArtista listaArtistas[], int tam, int *codigoA);
void hardcodearAlbumes(eAlbum listaAlbumes[]);
void hardcodearTipoAlbum(eTipoAlbum listaTiposAlbumes[], int tam, int* codigoTAlb);
int inicializarEstructura(eAlbum listaAlbumes[], int tam);
int buscarEspacioVacioEstructura(eAlbum albumes[], int tam);
int altaEstructura(eAlbum albumes[], int tam, int* codigo, eGenero listaGeneros[], int tamGeneros, eArtista listaArtistas[],
		int tamArtistas, eTipoArtista listaTipoArtista[], int tamTipoArtista, int* codigoG, int* codigoA, int* codigoTA,
		eTipoAlbum listaTipoAlbum[], int tamTipoAlbumes, int* codigoTAlb);
int bajaEstructura(eAlbum albumes[], int tam, int*codigo, eGenero listaGeneros[], int tamGeneros, eArtista listaArtistas[],
		int tamArtistas, eTipoArtista listaTipoArtista[], int tamTipoArtista, int *codigoG, int *codigoA,
		eTipoAlbum listaTipoAlbum[], int tamTipoAlbumes, int* codigoTAlb);
int modificarEstructura(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGeneros, eArtista listaArtistas[],
		int tamArtistas, eTipoArtista listaTipoArtista[], int tamTipoArtista, int *codigoG, int *codigoA,
		eTipoAlbum listaTipoAlbum[], int tamTipoAlbumes, int* codigoTAlb);
int cargaDescripcionTipoArtista(eTipoArtista listaTipoArtista[], int tam, int codigoTipoArtista, char descripcionTipoArtista[]);
int cargaNombreArtista(eArtista listaArtistas[], int tam, int codigoArtista, char nombreArtista[]);
int cargaDescripcionGenero(eGenero listaGeneros[], int tam, int codigoGenero, char descripcionGenero[]);
int cargaDescripcionTipoAlbum(eTipoAlbum listaTipoAlbum[], int tam, int codigoTipoAlbum, char descripcionTipoAlbum[]);
eFecha cargarFecha();
//ESTRUCTURAS--------------------------------------------------------------------------------------------------------

//INOUT--------------------------------------------------------------------------------------------------------------
int menu();
int subMenuModificar();
char subMenuListar();
char subMenuInformar();
void mostrarTipoArtistas(eTipoArtista listaTiposArtistas[], int tam);
void mostrarGeneros(eGenero listaGeneros[], int tam);
void mostrarArtistas(eArtista listaArtistas[], int tam, eTipoArtista listaTipoArtista[], int tamTipoArtista, int* codigoTA);
void mostrarTipoAlbumes(eTipoAlbum listaTipoAlbum[], int tam, int* codigoTAlb);
void mostrarAlbum(eAlbum album[], int tam, int indice, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb);
void mostrarAlbumes(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int* codigoA, int* codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb);
//INOUT--------------------------------------------------------------------------------------------------------------

//INFORMES-----------------------------------------------------------------------------------------------------------
void importePromedio(eAlbum albumes[], int tam);
void albumesViejitos(eAlbum albumes[], int tam);
void mostrarAlbumesViejitos(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int* codigoA, int* codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb);
void mostrarAlbumViejito(eAlbum album[], int tam, int indice, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb);
void mostrarAlbumesCaros(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int* codigoA, int* codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb);
void mostrarAlbumCaro(eAlbum album[], int tam, int indice, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb);
void mostrarAlbumesPorArtistas(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb);
void mostrarAlbumesPorAnio(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb);
void albumMasCaro(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb);
void mostrarAlbumesNoVinilo(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb);
void mostrarAlbumesViniloPorArtista(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb,
		eTipoArtista listaTipoArtista[], int tamTipoArtista, int *codigoTA);
void mostrarAlbumesOrdenados(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb);
//INFORMES-----------------------------------------------------------------------------------------------------------

//VALIDACIONES-------------------------------------------------------------------------------------------------------
int validarNumero(int numero);
int validarNumeroRangos(int numero, int rangoMin, int rangoMax);
int validarCaracterOpciones(char caracter, char opcionA, char opcionB);
int validarCaracter(char caracter);
int validarCadena(char cadena[], int tam);
//VALIDACIONES-------------------------------------------------------------------------------------------------------
//PROTOTIPOS---------------------------------------------------------------------------------------------------------

#endif /* HEADER_H_ */
