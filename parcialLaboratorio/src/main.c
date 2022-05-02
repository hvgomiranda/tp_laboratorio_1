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
#include "header.h"

int main(void)
{
	int eleccion;
	int proximoCodigo=0;
	eGenero listaGeneros[10];
	eArtista listaArtistas[6];
	eTipoArtista listaTipoArtista[2];
	eAlbum listaAlbumes[TAM];

	hardcodearTipoArtista(listaTipoArtista);
	hardcodearGenero(listaGeneros);
	hardcodearArtista(listaArtistas);
	inicializarEstructura(listaAlbumes, TAM); //hacer algo con el retorno

	setbuf(stdout, NULL);


	do
	{
		eleccion = menu();
		switch(eleccion)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		}
	}while(eleccion!=6);



	return EXIT_SUCCESS;
}


