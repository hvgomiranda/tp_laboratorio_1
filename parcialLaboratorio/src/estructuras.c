/*
 * estructuras.c
 *
 *  Created on: 30 abr. 2022
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

//HARDCODEO---------------------------------------------------------------------------------------------------
void hardcodearTipoArtista(eTipoArtista listaTipoArtista[], int tam)
{
	int i;
	int codigo=0;
	char descripcion[tam][51] = {"solista", "banda"};

	for(i=0;i<tam;i++)
	{
		codigo++;
		listaTipoArtista[i].codigoTipoArtista = codigo;
		strcpy(listaTipoArtista[i].descripcionTipoArtista, descripcion[i]);
	}
}

void hardcodearGenero(eGenero listaGeneros[], int tam)
{
	int i;
	int codigo=0;
	char descripcion[tam][51] = {"clasico", "rock", "pop", "metal", "bossa", "jazz"};

	for(i=0;i<tam;i++)
	{
		codigo++;
		listaGeneros[i].codigoGenero = codigo;
		strcpy(listaGeneros[i].descripcionGenero, descripcion[i]);
	}
}

void hardcodearArtista(eArtista listaArtistas[], int tam)
{
	int i;
	int codigo=0;
	char nombre[tam][51] = {"Pescado Rabioso", "Juana Molina", "Franz Liszt", "Mac Miller", "Madonna",
			"Frank Ocean", "Gorillaz", "Philip Glass", "Chico Buarque", "David Bowie"};
	int codigoTipoArtista[] = {2,1,1,1,1,1,2,1,1,1};
	for(i=0;i<tam;i++)
	{
		codigo++;
		listaArtistas[i].codigoArtista = codigo;
		strcpy(listaArtistas[i].nombre, nombre[i]);
		listaArtistas[i].codigoTipoArtista = codigoTipoArtista[i];
	}
}
//HARDCODEO---------------------------------------------------------------------------------------------------

//INICIALIZACION----------------------------------------------------------------------------------------------
int inicializarEstructura(eAlbum listaAlbumes[], int tam)
{
	int retorno=0;
	int i;
	if(listaAlbumes!=NULL&&tam>0)
	{
		for(i=0;i<tam;i++)
		{
			listaAlbumes[i].estado = LIBRE;
		}
		retorno = 1;
	}
	return retorno;
}
//INICIALIZACION----------------------------------------------------------------------------------------------

int buscarEspacioVacioEstructura(eAlbum albumes[], int tam)
{
	int indice;
	int i;

	indice = -1;
	if(albumes != NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(albumes[i].estado == LIBRE)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int altaEstructura(eAlbum albumes[], int tam, int* codigo, eGenero listaGeneros[], int tamGeneros, eArtista listaArtistas[],int tamArtistas, eTipoArtista listaTipoArtista[], int tamTipoArtista)
{
	int indice;
	int i;
	eAlbum auxAlbum;

	indice = buscarEspacioVacioEstructura(albumes, tam);
	if(albumes!=NULL&&tam>0)
	{
		if(indice==-1)
		{
			system("cls");
			printf("Todos los espacios están ocupados. Elimina un album o reinicia el programa\n");
		}
		else
		{
			for(i=0; i<tam; i++)
			{
				system("cls");
				printf("-----------------------------------\n");
				printf("                ALTA               \n");
				printf("-----------------------------------\n");

				(*codigo)++;
				auxAlbum.codigoAlbum = *codigo;

				do{
					system("cls");
					printf("Ingrese el titulo del album: ");
					fflush(stdin);
					scanf("%[^\n]", &auxAlbum.titulo);
				}while(validarCadena(auxAlbum.titulo, 51));

				do{
					system("cls");
					printf("Ingrese el importe del album: ");
					fflush(stdin);
					scanf("%f", &auxAlbum.importe);
				}while(validarNumeroRangos(auxAlbum.importe, 0, 999999));

				do{
					system("cls");
					mostrarGeneros(listaGeneros, tamGeneros);
					printf("Elija el genero al que pertenece el album: ");
					scanf("%d", &auxAlbum.codigoGenero);
				}while(validarNumeroRangos(auxAlbum.codigoGenero, 0, 6));

				do{
					system("cls");
					mostrarArtistas(listaArtistas, tamArtistas, listaTipoArtista, tamTipoArtista);
					printf("Elija el artista del album: ");
					scanf("%d", &auxAlbum.codigoArtista);
				}while(validarNumeroRangos(auxAlbum.codigoArtista, 0, 10));

				auxAlbum.fecha = cargarFecha();

				auxAlbum.estado = OCUPADO;





			}
		}
	}

}

//CARGA DE DESCRIPCIONES----------------------------------------------------------------------------------------------
char cargaDescripcionTipoArtista(eTipoArtista listaTipoArtista[], int tam, int codigoTipoArtista)
{
	char descripcionTipoArtista[51];
	int i;

	if(listaTipoArtista!=NULL && tam>0)
	{
		for(i=0; i<tam; i++)
		{
			if(codigoTipoArtista==listaTipoArtista[i].codigoTipoArtista)
			{
				descripcionTipoArtista = listaTipoArtista[i].descripcionTipoArtista;
			}
		}
	}

	return descripcionTipoArtista;
}
//CARGA DE DESCRIPCIONES----------------------------------------------------------------------------------------------
