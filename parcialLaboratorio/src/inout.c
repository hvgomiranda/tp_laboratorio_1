/*
 * inout.c
 *
 *  Created on: 30 abr. 2022
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

int menu()
{
	int eleccion;
	system("cls");
	printf("1. Alta\n");
	printf("2. Modificar\n");
	printf("3. Baja\n");
	printf("4. Informar\n");
	printf("5. Listas\n");
	printf("6. Salir\n");
	printf("Elija una opcion: ");
	scanf("%d", &eleccion);
	while(!validarNumero(eleccion))
	{
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
	printf("I. Todos los albumes de un año determinado\n");
	printf("J. EL album o los albumes mas caros\n");
	printf("K. Listar todo\n");
	printf("L. Salir\n");
	scanf("%c", &eleccion);
	while(!validarCaracter(eleccion))
	{
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
			printf("%-6d %-10s", listaTiposArtistas[i].codigoTipoArtista, listaTiposArtistas[i].descripcionTipoArtista);
			printf("-----------------------------------\n");
		}
	}
}

void mostrarGeneros(eGenero listaGeneros[], int tam)
{
	int i;
	system("cls");
	printf("-----------------------------------\n");
	printf("              GENEROS              \n");
	printf("-----------------------------------\n");
	printf("      CODIGO             TIPO      \n");
	printf("-----------------------------------\n");
	if(listaGeneros!=NULL&&tam>0)
	{
		for(i=0;i<tam;i++)
		{
			printf("%-6d %-10s", listaGeneros[i].codigoGenero, listaGeneros[i].descripcionGenero);
			printf("-----------------------------------\n");
		}
	}
}

void mostrarArtistas(eArtista listaArtistas[], int tam, eTipoArtista listaTipoArtista[], int tamTipoArtista)
{
	char descripcionTipoArtista;
	int i;
	system("cls");
	printf("-----------------------------------\n");
	printf("              GENEROS              \n");
	printf("-----------------------------------\n");
	printf("    CODIGO     NOMBRE     TIPO     \n");
	printf("-----------------------------------\n");
	if(listaArtistas!=NULL&&tam>0)
	{
		for(i=0;i<tam;i++)
		{
			descripcionTipoArtista = cargaDescripcionTipoArtista(listaTipoArtista, tamTipoArtista, listaArtistas[i].codigoTipoArtista);
			printf("%-6d %-10s %-10s", listaArtistas[i].codigoArtista, listaArtistas[i].nombre, descripcionTipoArtista);
			printf("-----------------------------------\n");
		}
	}
}

void mostrarAlbum()
{

}

void mostrarAlbumes()
{

}

eFecha cargarFecha()
{
	int dia;
	int mes;
	int anio;
	eFecha fecha;

	do{
	system("cls");
	printf("Ingrese el dia: ");
	scanf("%d", &dia);
	}while(validarNumeroRangos(dia, 0, 31));

	do{
	system("cls");
	printf("Ingrese el mes: ");
	scanf("%d", &mes);
	}while(validarNumeroRangos(mes, 0, 12));

	do{
	system("cls");
	printf("Ingrese el anio: ");
	scanf("%d", &anio);
	}while(validarNumeroRangos(anio, 1919, 2022));

	fecha = {dia, mes, anio};

	return fecha;

}
