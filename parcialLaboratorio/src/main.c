/*
 ============================================================================
 Name        : parcialLaboratorio.c
 Author      : Miranda Campos Hugo
 Version     :
 Copyright   : UTN
 Description : Primer parcial de laboratorio I, año 2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

int main(void)
{
	char decision;
	int proximoCodigo=10;
	int codigoTA = 100;
	int codigoG = 1000;
	int codigoA = 10000;
	eGenero listaGeneros[6];
	eArtista listaArtistas[10];
	eTipoArtista listaTipoArtista[2];
	eAlbum listaAlbumes[TAM];

	setbuf(stdout, NULL);

	hardcodearTipoArtista(listaTipoArtista, TAMTIPOARTISTAS, &codigoTA);
	hardcodearGenero(listaGeneros, TAMGENERO, &codigoG);
	hardcodearArtista(listaArtistas, TAMARTISTAS, &codigoA);
	inicializarEstructura(listaAlbumes, TAM); //hacer algo con el retorno
	hardcodearAlbumes(listaAlbumes);

	do
	{
		switch(menu())
		{
		case 1:
			if(altaEstructura(listaAlbumes, TAM, &proximoCodigo, listaGeneros, TAMGENERO, listaArtistas,
					TAMARTISTAS, listaTipoArtista, TAMTIPOARTISTAS, &codigoG, &codigoA, &codigoTA))
			{
				system("cls");
				printf("Alta exitosa\n");
				system("pause");
			}
			else
			{
				system("cls");
				printf("Error al dar de alta el album\n");
				system("pause");
			}
			break;
		case 2:
			if(modificarEstructura(listaAlbumes, TAM, listaGeneros, TAMGENERO, listaArtistas,
					TAMARTISTAS, listaTipoArtista, TAMTIPOARTISTAS, &codigoG, &codigoA))
			{
				system("cls");
				printf("Modificacion exitosa\n");
				system("pause");
			}
			else
			{
				system("cls");
				printf("Error al modificar el album\n");
				system("pause");
			}
			break;
		case 3:
			if(bajaEstructura(listaAlbumes, TAM, &proximoCodigo, listaGeneros, TAMGENERO, listaArtistas,
					TAMARTISTAS, listaTipoArtista, TAMTIPOARTISTAS, &codigoG, &codigoA))

			{
				system("cls");
				printf("Baja exitosa\n");
				system("pause");
			}
			else
			{
				system("cls");
				printf("Error al dar de baja el album\n");
				system("pause");
			}
			break;

		case 4:
			do
			{
				switch(subMenuInformar())
				{
				case 'A':
					importePromedio(listaAlbumes, TAM);
					break;
				case 'B':
					albumesViejitos(listaAlbumes, TAM);
					break;
				case 'C':
					system("cls");
					printf("Saliste del menu de informes.\n");
					system("pause");
					break;
				default:
					system("cls");
					printf("Error, elija nuevamente.\n");
					system("pause");
					break;
				}
			}while(subMenuInformar()!='C');
			break;
		case 5:
			do
			{
				switch(subMenuListar())
				{
				case 'A':
					mostrarGeneros(listaGeneros, TAMGENERO);
					break;
				case 'B':
					mostrarTipoArtistas(listaTipoArtista, TAMTIPOARTISTAS);
					break;
				case 'C':
					mostrarArtistas(listaArtistas, TAMARTISTAS, listaTipoArtista, TAMTIPOARTISTAS, &codigoTA);
					break;
				case 'D':
					mostrarAlbumes(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG);
					system("pause");
					break;
				case 'E':

					break;
				case 'F':
					mostrarAlbumesViejitos(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG);
					system("pause");
					break;
				case 'G':
					albumMasCaro(listaAlbumes, TAM);
					system("pause");
					break;
				case 'H':

					break;
				case 'I':

					break;
				case 'J':
					break;
				case 'K':

					break;
				case 'L':
					system("cls");
					printf("Saliste del menu de listas.\n");
					system("pause");
					break;
				default:
					system("cls");
					printf("Error, elija nuevamente.\n");
					system("pause");
					break;
				}
			}while(subMenuListar()!='L');
			break;
		case 6:
			do{
				printf("Esta seguro que quiere salir? (S/N)\n");
				fflush(stdin);
				scanf("%c", &decision);
				decision = toupper(decision);
			}while(!validarCaracterOpciones(decision, 'S', 'N'));
			if(decision=='N')
			{
				system("cls");
				printf("Salida cancelada.\n");
				system("pause");
			}
			break;
		default:
			system("cls");
			printf("Opcion invalida\n");
			system("pause");
			break;
		}
	}while(decision!='S');

	return EXIT_SUCCESS;
}


