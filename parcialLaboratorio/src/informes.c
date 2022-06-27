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
	float promedio=0;
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
		eArtista listaArtistas[], int tamArtista, int* codigoA, int* codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	int sinAlbumes = 1;
	if(albumes!=NULL&&tam>0)
	{
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("|                            ALBUM/ES LANZADOS DESPUES DEL 2000                                 |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("| CODIGO          TITULO         IMPORTE    FECHA          ARTISTA            GENERO    TIPO    |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<tam;i++)
		{
			if(albumes[i].estado==OCUPADO)
			{
				sinAlbumes = 0;
				mostrarAlbumViejito(albumes, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, codigoA, codigoG, listaTipoAlbum, codigoTAlb);
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
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	char descripcionGenero[51];
	char nombreArtista[51];
	char descripcionTipoAlbum[51];
	cargaNombreArtista(listaArtistas, tam, album[indice].codigoArtista, nombreArtista);
	cargaDescripcionGenero(listaGeneros, tam, album[indice].codigoGenero, descripcionGenero);
	cargaDescripcionTipoAlbum(listaTipoAlbum, tam, album[indice].codigoTipoAlbum, descripcionTipoAlbum);

	if(album!=NULL&&tam>0&&(album[indice].fecha.anio<2000))
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

void mostrarAlbumesCaros(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int* codigoA, int* codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	int sinAlbumes = 1;
	if(albumes!=NULL&&tam>0)
	{
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("|                             ALBUM/ES MAS CAROS QUE LA MEDIA                                   |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("| CODIGO          TITULO         IMPORTE    FECHA          ARTISTA            GENERO    TIPO    |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<tam;i++)
		{
			if(albumes[i].estado==OCUPADO)
			{
				sinAlbumes = 0;
				mostrarAlbumCaro(albumes, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, codigoA, codigoG, listaTipoAlbum, codigoTAlb);
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
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	char descripcionGenero[51];
	char nombreArtista[51];
	char descripcionTipoAlbum[51];
	cargaNombreArtista(listaArtistas, tam, album[indice].codigoArtista, nombreArtista);
	cargaDescripcionGenero(listaGeneros, tam, album[indice].codigoGenero, descripcionGenero);
	cargaDescripcionTipoAlbum(listaTipoAlbum, tam, album[indice].codigoTipoAlbum, descripcionTipoAlbum);

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

void mostrarAlbumesPorArtistas(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	if(album!=NULL&&tam>0)
	{
		system("cls");
		for(int i=0;i<tamArtista;i++)
		{
			printf("\n%s\n", listaArtistas[i].nombre);
			for(int j=0;j<tam;j++)
			{
				if(album[j].estado==1 && listaArtistas[i].codigoArtista == album[j].codigoArtista)
				{
					mostrarAlbum(album, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, codigoA, codigoG, listaTipoAlbum, codigoTAlb);
				}
			}
		}
		system("pause");
	}
}

void mostrarAlbumesPorAnio(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	int anio;
	int acierto=0;

	if(album!=NULL&&tam>0)
	{
		system("cls");
		do{
		printf("Ingrese el anio: ");
		fflush(stdin);
		scanf("%d", &anio);
		}while(!validarNumeroRangos(anio, 1919, 2022));

		for(int i=0; i<tam; i++)
		{
			if(album[i].fecha.anio == anio)
			{
				acierto=1;
				system("cls");
				printf("Anio %d\n", anio);
				mostrarAlbum(album, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, codigoA, codigoG, listaTipoAlbum, codigoTAlb);
				printf("\n");
				system("pause");
			}
		}
		if(!acierto)
		{
			system("cls");
			printf("No hay albumes de ese anio\n");
			system("pause");
		}

	}
}

void albumMasCaro(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{

	float albumMasCaro=0;

	if(album!=NULL&&tam>0)
	{

		for(int i=0;i<tam;i++)
		{
			if(album[i].estado)
			{
				if(i==0)
				{
					albumMasCaro = album[i].importe;
				}
				else if(albumMasCaro<album[i].importe)
				{
					albumMasCaro = album[i].importe;
				}
			}
		}

		system("cls");
		for(int i=0;i<tam;i++)
		{
			if(album[i].estado && album[i].importe == albumMasCaro)
			{
				printf("-------------------------------------------------------------------------------------------------\n");
				printf("|                                     ALBUM/ES MAS CAROS                                        |\n");
				printf("-------------------------------------------------------------------------------------------------\n");
				printf("| CODIGO          TITULO         IMPORTE    FECHA          ARTISTA            GENERO    TIPO    |\n");
				printf("-------------------------------------------------------------------------------------------------\n");
				mostrarAlbum(album, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, codigoA, codigoG, listaTipoAlbum, codigoTAlb);

			}
		}
	}
}

void mostrarAlbumesNoVinilo(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	int acierto=0;
	if(album!=NULL && tam>0)
	{
		system("cls");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("|                              ALBUMES QUE NO SON DE VINILO                                     |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("| CODIGO          TITULO         IMPORTE    FECHA          ARTISTA            GENERO    TIPO    |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<tam;i++)
		{
			if(album[i].estado && album[i].codigoTipoAlbum!=1)
			{
				acierto=1;
				mostrarAlbum(album, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, codigoA, codigoG, listaTipoAlbum, codigoTAlb);
				printf("-------------------------------------------------------------------------------------------------\n");
			}
		}
		if(!acierto)
		{
			system("cls");
			printf("Todos los discos son de vinilo\n");
		}
		system("pause");
	}
}

void mostrarAlbumesViniloPorArtista(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb,
		eTipoArtista listaTipoArtista[], int tamTipoArtista, int *codigoTA)
{
	int codigoArtista;
	int acierto=0;

	if(album!=NULL && tam>0)
	{
		mostrarArtistas(listaArtistas, tamArtista, listaTipoArtista, tamTipoArtista, codigoTA);

		printf("Ingrese el codigo del artista que buscara: ");
		fflush(stdin);
		scanf("%d", &codigoArtista);

		system("cls");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("|                             ALBUMES DE VINILO POR ARTISTA                                     |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("| CODIGO          TITULO         IMPORTE    FECHA          ARTISTA            GENERO    TIPO    |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<tam;i++)
		{
			if(album[i].estado && album[i].codigoTipoAlbum==1 && album[i].codigoArtista == codigoArtista)
			{
				acierto=1;
				mostrarAlbum(album, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, codigoA, codigoG, listaTipoAlbum, codigoTAlb);
				printf("-------------------------------------------------------------------------------------------------\n");
			}
		}
		if(!acierto)
		{
			system("cls");
			printf("No hay vinilos del autor buscado\n");
		}
		system("pause");
	}
}

void mostrarAlbumesOrdenados(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	eAlbum auxAlbum;

	if(album!=NULL && tam>0)
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam; j++)
			{
				if((album[j].importe>album[i].importe) || (album[j].importe==album[i].importe && strcmp(album[j].titulo, album[i].titulo)<0))
				{
					auxAlbum = album[i];
					album[i] = album[j];
					album[j] = auxAlbum;
				}
			}
		}
		mostrarAlbumes(album, tam, listaGeneros, tamGenero, listaArtistas, tamArtista, codigoA, codigoG, listaTipoAlbum, codigoTAlb);
		system("pause");
	}
}

void mostrarAlbumPorTipoGenero(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	int tipoAlbum;
	int genero;
	int acierto=0;

	if(album!=NULL&&tam>0)
	{
		system("cls");
		mostrarTipoAlbumes(listaTipoAlbum, 3, codigoTAlb);
		printf("\nIngrese el id del tipo de artista: ");
		fflush(stdin);
		scanf("%d", &tipoAlbum);

		system("cls");
		mostrarGeneros(listaGeneros, tamGenero);
		printf("\nIngrese el id del genero: ");
		fflush(stdin);
		scanf("%d", &genero);

		system("cls");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("|                           ALBUMES POR GENERO Y TIPO DE ALBUM                                  |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("| CODIGO          TITULO         IMPORTE    FECHA          ARTISTA            GENERO    TIPO    |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<tam;i++)
		{
			if(album[i].estado && album[i].codigoTipoAlbum==tipoAlbum && album[i].codigoGenero==genero)
			{
				acierto=1;
				mostrarAlbum(album, tam, i, listaGeneros, tamGenero, listaArtistas, tamArtista, codigoA, codigoG, listaTipoAlbum, codigoTAlb);
				printf("-------------------------------------------------------------------------------------------------\n");
			}
		}
		if(!acierto)
		{
			system("cls");
			printf("No hay albumes que concuerden con la busqueda\n");
		}
		system("pause");
	}
}

void informarCantidadSolistas(eAlbum album[], int tam, eGenero listaGeneros[], int tamGenero,
		eArtista listaArtistas[], int tamArtista, int *codigoA, int *codigoG, eTipoAlbum listaTipoAlbum[], int *codigoTAlb)
{
	int anio;
	int contador=0;

	if(album!=NULL&&tam>0)
	{
		do{
		printf("Ingrese el anio a buscar: ");
		fflush(stdin);
		scanf("%d", &anio);
		}while(!validarNumeroRangos(anio, 1919, 2022));
		for(int i=0;i<tam;i++)
		{
			if(album[i].estado && album[i].fecha.anio==anio)
			{
				for(int j=0; j<tamArtista;j++)
				{
					if(album[i].codigoArtista == listaArtistas[j].codigoArtista && listaArtistas[j].codigoTipoArtista == 101)
					{
						contador++;
					}
				}
			}
		}
	}
	if(contador!=0)
	{
		system("cls");
		printf("La cantidad es de %d\n", contador);
		system("pause");
	}
	else
	{
		system("cls");
		printf("no hay concordancias\n");
		system("pause");
	}
}
