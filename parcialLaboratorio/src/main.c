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
	char subDecision;
	char subDecisionListar;
	int proximoCodigo=10;
	int codigoTA = 100;
	int codigoG = 1000;
	int codigoA = 10000;
	int codigoTAlb = 0;
	eGenero listaGeneros[6];
	eArtista listaArtistas[10];
	eTipoArtista listaTipoArtista[2];
	eAlbum listaAlbumes[TAM];
	eTipoAlbum listaTiposAlbumes[3];

	setbuf(stdout, NULL);

	hardcodearTipoArtista(listaTipoArtista, TAMTIPOARTISTAS, &codigoTA);
	hardcodearGenero(listaGeneros, TAMGENERO, &codigoG);
	hardcodearArtista(listaArtistas, TAMARTISTAS, &codigoA);
	hardcodearTipoAlbum(listaTiposAlbumes, TAMTIPOALBUMES, &codigoTAlb);
	inicializarEstructura(listaAlbumes, TAM);
	hardcodearAlbumes(listaAlbumes);

	do
	{

		switch(menu())
		{
		case 1:
			if(altaEstructura(listaAlbumes, TAM, &proximoCodigo, listaGeneros, TAMGENERO, listaArtistas,
					TAMARTISTAS, listaTipoArtista, TAMTIPOARTISTAS, &codigoG, &codigoA, &codigoTA, listaTiposAlbumes, TAMTIPOALBUMES, &codigoTAlb))
			{
				system("cls");
				printf("Alta exitosa\n");
				system("pause");
			}
			else
			{
				system("cls");
				printf("No se ha dado de alta ningun album\n");
				system("pause");
			}
			break;
		case 2:
			if(modificarEstructura(listaAlbumes, TAM, listaGeneros, TAMGENERO, listaArtistas,
					TAMARTISTAS, listaTipoArtista, TAMTIPOARTISTAS, &codigoG, &codigoA, listaTiposAlbumes, TAMTIPOALBUMES, &codigoTAlb))
			{
				system("cls");
				printf("Modificacion exitosa\n");
				system("pause");
			}
			else
			{
				system("cls");
				printf("No se ha modificado ningun album\n");
				system("pause");
			}
			break;
		case 3:
			if(bajaEstructura(listaAlbumes, TAM, &proximoCodigo, listaGeneros, TAMGENERO, listaArtistas,
					TAMARTISTAS, listaTipoArtista, TAMTIPOARTISTAS, &codigoG, &codigoA, listaTiposAlbumes, TAMTIPOALBUMES, &codigoTAlb))
			{
				system("cls");
				printf("Baja exitosa\n");
				system("pause");
			}
			else
			{
				system("cls");
				printf("No se ha dado de baja ningun album\n");
				system("pause");
			}
			break;

		case 4:
			do
			{
				subDecision = subMenuInformar();
				switch(subDecision)
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
			}while(subDecision!='C');
			break;

		case 5:
			do
			{
				subDecisionListar = subMenuListar();
				switch(subDecisionListar)
				{
				case 'A':
					mostrarGeneros(listaGeneros, TAMGENERO);
					system("pause");
					break;
				case 'B':
					mostrarTipoArtistas(listaTipoArtista, TAMTIPOARTISTAS);
					system("pause");
					break;
				case 'C':
					mostrarArtistas(listaArtistas, TAMARTISTAS, listaTipoArtista, TAMTIPOARTISTAS, &codigoTA);
					system("pause");
					break;
				case 'D':
					mostrarAlbumes(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb);
					system("pause");
					break;
				case 'E':
					mostrarTipoAlbumes(listaTiposAlbumes, TAMTIPOALBUMES, &codigoTAlb);
					system("pause");
					break;

				case 'F':
					mostrarAlbumesOrdenados(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb);
					break;
				case 'G':
					mostrarAlbumesViejitos(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb);
					system("pause");
					break;
				case 'H':
					mostrarAlbumesCaros(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb);
					system("pause");
					break;
				case 'I':
					mostrarAlbumesPorArtistas(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb);
					break;
				case 'J':
					mostrarAlbumesPorAnio(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb);
					break;
				case 'K':
					albumMasCaro(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb);
					system("pause");
					break;
				case 'L':
					mostrarAlbumesNoVinilo(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb);
					break;

				case 'M':
					mostrarAlbumesViniloPorArtista(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb,
							listaTipoArtista, TAMTIPOARTISTAS, &codigoTA);
					break;

				case 'N':
					mostrarAlbumes(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb);
					system("pause");
					break;
				case 'O':
					mostrarAlbumPorTipoGenero(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb);
					break;

				case 'P':
					informarCantidadSolistas(listaAlbumes, TAM, listaGeneros, TAMGENERO,
							listaArtistas, TAMARTISTAS, &codigoA, &codigoG, listaTiposAlbumes, &codigoTAlb);
					break;

				case 'Q':
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
			}while(subDecisionListar!='Q');
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
			else
			{
				system("cls");
				printf("APROBAME DAVID\n");
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
