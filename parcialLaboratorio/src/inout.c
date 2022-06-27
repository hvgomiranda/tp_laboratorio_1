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
	fflush(stdin);
	scanf("%d", &eleccion);

	while(!validarNumeroRangos(eleccion, 0, 6))
	{
		system("cls");
		printf("1. Alta\n");
		printf("2. Modificar\n");
		printf("3. Baja\n");
		printf("4. Informar\n");
		printf("5. Listar\n");
		printf("6. Salir\n");
		printf("Elija una opcion: ");
		fflush(stdin);
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
	printf("4. Tipo de album\n");
	printf("5. Salir\n");
	printf("Que desea modificar? ");
	fflush(stdin);
	scanf("%d", &eleccion);

	while(!validarNumero(eleccion))
	{
		system("cls");
		printf("1. Titulo\n");
		printf("2. Fecha de publicacion\n");
		printf("3. Importe\n");
		printf("4. Tipo de album\n");
		printf("5. Salir\n");
		printf("Que desea modificar? ");
		fflush(stdin);
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
	printf("E. Todos los tipos de albumes\n");
	printf("F. Albumes ordenados\n");
	printf("G. Todos los albumes cuya fecha de publicacion es anterior a 1/1/2000\n");
	printf("H. Todos los albumes que superan el promedio de los importes\n");
	printf("I. Todos los albumes de cada artista\n");
	printf("J. Todos los albumes de un anio determinado\n");
	printf("K. EL album o los albumes mas caros\n");
	printf("L. Albumes que no son de vinilo\n");
	printf("M. Albumes de vinilo de un artista determinado\n");
	printf("N. Listar todo\n");
	printf("O. Listar de todos los álbumes de un tipo de álbum determinado y de un género determinado.\n");
	printf("P. Informar la cantidad de solistas de un año determinado\n");
	printf("Q. Salir\n");
	printf("Elija una opcion: ");
	fflush(stdin);
	eleccion = getchar();
	eleccion = toupper(eleccion);

	while(!validarCaracter(eleccion))
	{
		system("cls");
		printf("A. Todos los generos\n");
		printf("B. Todos los tipos de artistas musicales\n");
		printf("C. Todos los artistas\n");
		printf("D. Todos los albumes\n");
		printf("E. Todos los tipos de albumes\n");
		printf("F. Albumes ordenados\n");
		printf("G. Todos los albumes cuya fecha de publicacion es anterior a 1/1/2000\n");
		printf("H. Todos los albumes que superan el promedio de los importes\n");
		printf("I. Todos los albumes de cada artista\n");
		printf("J. Todos los albumes de un anio determinado\n");
		printf("K. EL album o los albumes mas caros\n");
		printf("L. Albumes que no son de vinilo\n");
		printf("M. Albumes de vinilo de un artista determinado\n");
		printf("N. Listar todo\n");
		printf("O. Informar la cantidad de solistas de un año determinado\n");
		printf("P. Listar de todos los álbumes de un tipo de álbum determinado y de un género determinado.\n");
		printf("Q. Salir\n");
		printf("Elija una opcion: ");
		fflush(stdin);
		eleccion = getchar();
		eleccion = toupper(eleccion);
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
	eleccion = getchar();
	eleccion = toupper(eleccion);

	while(!validarCaracter(eleccion))
	{
		system("cls");
		printf("A. Total y promedio de los importes. Cuantos albumes superan el promedio.\n");
		printf("B. Cantidad de albumes cuya fecha de publicacion es anterior a 1/1/2000\n");
		printf("C. Salir\n");
		printf("Elija una opcion: ");
		fflush(stdin);
		eleccion = getchar();
		eleccion = toupper(eleccion);
	}

	return eleccion;
}

void mostrarTipoArtistas(eTipoArtista listaTiposArtistas[], int tam)
{
	int i;
	system("cls");
	printf("-----------------------------------\n");
	printf("|         TIPOS DE ARTISTAS       |\n");
	printf("-----------------------------------\n");
	printf("|      CODIGO             TIPO    |\n");
	printf("-----------------------------------\n");
	if(listaTiposArtistas!=NULL&&tam>0)
	{
		for(i=0;i<tam;i++)
		{
			printf("|      %3d             %8s    |\n", listaTiposArtistas[i].codigoTipoArtista, listaTiposArtistas[i].descripcionTipoArtista);
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
			printf("      %4d            %8s      \n", listaGeneros[i].codigoGenero, listaGeneros[i].descripcionGenero);
			printf("-----------------------------------\n");
		}
	}
}

void mostrarArtistas(eArtista listaArtistas[], int tam, eTipoArtista listaTipoArtista[], int tamTipoArtista, int* codigoTA)
{
	char descripcionTipoArtista[51];
	int i;
	system("cls");
	printf("----------------------------------------\n");
	printf("|                ARTISTAS              |\n");
	printf("----------------------------------------\n");
	printf("|    CODIGO       NOMBRE       TIPO    |\n");
	printf("----------------------------------------\n");
	if(listaArtistas!=NULL&&tam>0)
	{
		for(i=0;i<tam;i++)
		{
			cargaDescripcionTipoArtista(listaTipoArtista, tamTipoArtista, listaArtistas[i].codigoTipoArtista,descripcionTipoArtista);
			printf("|  %5d      %-20s       %8s|\n", listaArtistas[i].codigoArtista, listaArtistas[i].nombre, descripcionTipoArtista);
			printf("-----------------------------------\n");
		}
	}
}

void mostrarTipoAlbumes(eTipoAlbum listaTipoAlbum[], int tam, int* codigoTAlb)
{
	system("cls");
	printf("-----------------------------------\n");
	printf("           TIPO DE ALBUMES         \n");
	printf("-----------------------------------\n");
	printf("        ID         DESCRIPCION     \n");
	printf("-----------------------------------\n");
	if(listaTipoAlbum!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			printf("      %d        %s\n", listaTipoAlbum[i].id, listaTipoAlbum[i].descripcionTipoAlbum);
			printf("-----------------------------------\n");
		}
	}
}

void mostrarAlbum(eAlbum album[], int tam, int indice, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	char descripcionGenero[51];
	char nombreArtista[51];
	char descripcionTipoAlbum[51];
	cargaNombreArtista(listaArtistas, tam, album[indice].codigoArtista, nombreArtista);
	cargaDescripcionGenero(listaGeneros, tam, album[indice].codigoGenero, descripcionGenero);
	cargaDescripcionTipoAlbum(listaTipoAlbum, tam, album[indice].codigoTipoAlbum, descripcionTipoAlbum);

	if(album!=NULL&&tam>0)
	{
		printf("| %3d      %-20s %7.2f   %.2d/%.2d/%.4d     %-20s %-10s %-6s |\n",
				album[indice].codigoAlbum,
				album[indice].titulo,
				album[indice].importe,
				album[indice].fecha.dia,
				album[indice].fecha.mes,
				album[indice].fecha.anio,
				nombreArtista,
				descripcionGenero,
				descripcionTipoAlbum);
	}
}

void mostrarAlbumes(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int* codigoA, int* codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	int sinAlbumes = 1;
	if(albumes!=NULL&&tam>0)
	{
		system("cls");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("|                                        ALBUMES                                                |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("| CODIGO          TITULO         IMPORTE    FECHA          ARTISTA            GENERO    TIPO    |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<tam;i++)
		{
			if(albumes[i].estado==OCUPADO)
			{
				sinAlbumes = 0;
				mostrarAlbum(albumes, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, codigoA, codigoG, listaTipoAlbum, codigoTAlb);
				printf("-------------------------------------------------------------------------------------------------\n");
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
