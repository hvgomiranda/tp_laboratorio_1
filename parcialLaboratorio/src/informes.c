/*
 * informes.c
 *
 *  Created on: 3 may. 2022
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

void importePromedio(eAlbum albumes[], int tam)
{
	float importes=0;
	int cantidad=0;
	float promedio;
	int importesMasAltos=0;
	if(albumes!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(albumes[i].estado==1)
			{
				importes+=albumes[i].importe;
				cantidad++;
			}
		}
		promedio = importes/cantidad;
	}

	if(albumes!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(albumes[i].estado==1&&(albumes[i].importe>promedio))
			{
				importesMasAltos++;
			}
		}

	}

	system("cls");
	printf("El total es %.2f\n", importes);
	printf("El promedio es %.2f\n", promedio);
	printf("Hay %d albumes que superan el promedio\n", importesMasAltos);
	system("pause");

}

void albumesViejitos(eAlbum albumes[], int tam)
{
	int cantidad=0;

	if(albumes!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(albumes[i].estado==1&&(albumes[i].fecha.anio<2000)) cantidad++;
		}
	}

	system("cls");
	printf("El total de albumes producidos antes del 2000 son %d\n", cantidad);
	system("pause");

}

void mostrarAlbumesViejitos(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int* codigoA, int* codigoG)
{
	int sinAlbumes = 1;
	if(albumes!=NULL&&tam>0)
	{
		printf("                         ALBUMES                         \n");
		printf("---------------------------------------------------------\n");
		printf("CODIGO    TITULO     IMPORTE   FECHA    ARTISTA    GENERO\n");
		printf("---------------------------------------------------------\n");
		for(int i=0;i<tam;i++)
		{
			if(albumes[i].estado==OCUPADO)
			{
				sinAlbumes = 0;
				mostrarAlbumViejito(albumes, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, &codigoA, &codigoG);
			}
		}
	}
	if(sinAlbumes)
	{
		system("cls");
		printf("No hay albumes para mostrar");
		system("pause");
	}
}

void mostrarAlbumViejito(eAlbum album[], int tam, int indice, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG)
{
	char descripcionGenero[51];
	char nombreArtista[51];
	cargaNombreArtista(listaArtistas, tam, album[indice].codigoArtista, nombreArtista);
	cargaDescripcionGenero(listaGeneros, tam, album[indice].codigoGenero, descripcionGenero);

	if(album!=NULL&&tam>0&&(album[indice].fecha.anio<2000))
	{
		printf("%d %s %.2f %d/%d/%d %s %s\n",
				album[indice].codigoAlbum,
				album[indice].titulo,
				album[indice].importe,
				album[indice].fecha.dia,
				album[indice].fecha.mes,
				album[indice].fecha.anio,
				nombreArtista,
				descripcionGenero);
	}
}

void mostrarAlbumesCaros(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int* codigoA, int* codigoG)
{
	int sinAlbumes = 1;
	if(albumes!=NULL&&tam>0)
	{
		printf("                         ALBUMES                         \n");
		printf("---------------------------------------------------------\n");
		printf("CODIGO    TITULO     IMPORTE   FECHA    ARTISTA    GENERO\n");
		printf("---------------------------------------------------------\n");
		for(int i=0;i<tam;i++)
		{
			if(albumes[i].estado==OCUPADO)
			{
				sinAlbumes = 0;
				mostrarAlbumCaro(albumes, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, &codigoA, &codigoG);
			}
		}
	}
	if(sinAlbumes)
	{
		system("cls");
		printf("No hay albumes para mostrar");
		system("pause");
	}
}

void mostrarAlbumCaro(eAlbum album[], int tam, int indice, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG)
{
	char descripcionGenero[51];
	char nombreArtista[51];
	cargaNombreArtista(listaArtistas, tam, album[indice].codigoArtista, nombreArtista);
	cargaDescripcionGenero(listaGeneros, tam, album[indice].codigoGenero, descripcionGenero);

	float importes=0;
	int cantidad=0;
	float promedio;
	if(album!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(album[i].estado==1)
			{
				importes+=album[i].importe;
				cantidad++;
			}
		}
		promedio = importes/cantidad;
	}

	if(album!=NULL&&tam>0&&(album[indice].importe>promedio))
	{
		printf("%d %s %.2f %d/%d/%d %s %s\n",
				album[indice].codigoAlbum,
				album[indice].titulo,
				album[indice].importe,
				album[indice].fecha.dia,
				album[indice].fecha.mes,
				album[indice].fecha.anio,
				nombreArtista,
				descripcionGenero);
	}
}

void albumMasCaro(eAlbum album[], int tam)
{
	char albumesMasCaros[][51];
	int albumMasCaro;
	if(album!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(albumMasCaro=0||albumMasCaro>album[i].importe)
			{
				strcpy(albumesMasCaros[i],album[i].titulo);
				printf("El album mas caro es %s", albumesMasCaros[i]);
			}
		}
	}
}
