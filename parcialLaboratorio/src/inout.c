/*
 * inout.c
 *
 *  Created on: 30 abr. 2022
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

int menu()
{
	int eleccion;
	system("cls");
	printf("1. Alta\n");
	printf("2. Modificar\n");
	printf("3. Baja\n");
	printf("4. Informar\n");
	printf("5. Listar\n");
	printf("6. Salir\n");
	printf("Elija una opcion: ");
	scanf("%d", &eleccion);

	while(!validarNumeroRangos(eleccion, 0, 6))
	{
		system("cls");
		printf("Eleccion erronea. Elija una opcion: ");
		scanf("%d", &eleccion);
	}

	return eleccion;
}

int subMenuModificar()
{
	int eleccion;
	system("cls");
	printf("1. Titulo\n");
	printf("2. Fecha de publicacion\n");
	printf("3. Importe\n");
	printf("4. Salir\n");
	printf("Que desea modificar? ");
	scanf("%d", &eleccion);
	while(!validarNumero(eleccion))
	{
		system("cls");
		printf("Eleccion erronea. Elija una opcion: ");
		scanf("%d", &eleccion);
	}

	return eleccion;
}

char subMenuListar()
{
	char eleccion;
	system("cls");
	printf("A. Todos los generos\n");
	printf("B. Todos los tipos de artistas musicales\n");
	printf("C. Todos los artistas\n");
	printf("D. Todos los albumes\n");
	printf("E. Albumes ordenados\n");
	printf("F. Todos los albumes cuya fecha de publicacion es anterior a 1/1/2000\n");
	printf("G. Todos los albumes que superan el promedio de los importes\n");
	printf("H. Todos los albumes de cada artista\n");
	printf("I. Todos los albumes de un anio determinado\n");
	printf("J. EL album o los albumes mas caros\n");
	printf("K. Listar todo\n");
	printf("L. Salir\n");
	printf("Elija una opcion: ");
	fflush(stdin);
	scanf("%c", &eleccion);
	eleccion = toupper(eleccion);
	while(!validarCaracter(eleccion))
	{
		system("cls");
		printf("Eleccion erronea. Elija una opcion: ");
		scanf("%c", &eleccion);
	}

	return eleccion;
}

char subMenuInformar()
{
	char eleccion;
	system("cls");
	printf("A. Total y promedio de los importes. Cuantos albumes superan el promedio.\n");
	printf("B. Cantidad de albumes cuya fecha de publicacion es anterior a 1/1/2000\n");
	printf("C. Salir\n");
	printf("Elija una opcion: ");
	fflush(stdin);
	scanf("%c", &eleccion);
	eleccion = toupper(eleccion);
	while(!validarCaracter(eleccion))
	{
		system("cls");
		printf("Eleccion erronea. Elija una opcion: ");
		scanf("%c", &eleccion);
	}

	return eleccion;
}

void mostrarTipoArtistas(eTipoArtista listaTiposArtistas[], int tam)
{
	int i;
	system("cls");
	printf("-----------------------------------\n");
	printf("         TIPOS DE ARTISTAS         \n");
	printf("-----------------------------------\n");
	printf("      CODIGO             TIPO      \n");
	printf("-----------------------------------\n");
	if(listaTiposArtistas!=NULL&&tam>0)
	{
		for(i=0;i<tam;i++)
		{
			printf("%d         %s\n", listaTiposArtistas[i].codigoTipoArtista, listaTiposArtistas[i].descripcionTipoArtista);
			printf("-----------------------------------\n");
		}
	}
}

void mostrarGeneros(eGenero listaGeneros[], int tam)
{
	if(listaGeneros!=NULL&&tam>0)
	{
		system("cls");
		printf("-----------------------------------\n");
		printf("              GENEROS              \n");
		printf("-----------------------------------\n");
		printf("      CODIGO             TIPO      \n");
		printf("-----------------------------------\n");
		for(int i=0;i<tam;i++)
		{
			printf("      %d         %s      \n", listaGeneros[i].codigoGenero, listaGeneros[i].descripcionGenero);
			printf("-----------------------------------\n");
		}
	}
}

void mostrarArtistas(eArtista listaArtistas[], int tam, eTipoArtista listaTipoArtista[], int tamTipoArtista, int* codigoTA)
{
	char descripcionTipoArtista[51];
	int i;
	system("cls");
	printf("-----------------------------------\n");
	printf("              ARTISTAS             \n");
	printf("-----------------------------------\n");
	printf("    CODIGO     NOMBRE     TIPO     \n");
	printf("-----------------------------------\n");
	if(listaArtistas!=NULL&&tam>0)
	{
		for(i=0;i<tam;i++)
		{
			cargaDescripcionTipoArtista(listaTipoArtista, tamTipoArtista, listaArtistas[i].codigoTipoArtista,descripcionTipoArtista);
			printf("%d      %s       %s\n", listaArtistas[i].codigoArtista, listaArtistas[i].nombre, descripcionTipoArtista);
			printf("-----------------------------------\n");
		}
	}
}

void mostrarAlbum(eAlbum album[], int tam, int indice, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG)
{
	char descripcionGenero[51];
	char nombreArtista[51];
	cargaNombreArtista(listaArtistas, tam, album[indice].codigoArtista, nombreArtista);
	cargaDescripcionGenero(listaGeneros, tam, album[indice].codigoGenero, descripcionGenero);

	if(album!=NULL&&tam>0)
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

void mostrarAlbumes(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGenero,
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
				mostrarAlbum(albumes, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, &codigoA, &codigoG);
				printf("---------------------------------------------------------\n");
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
