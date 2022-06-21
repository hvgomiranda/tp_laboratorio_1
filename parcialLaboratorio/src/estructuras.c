/*
 * estructuras.c
 *
 *  Created on: 30 abr. 2022
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

//HARDCODEO---------------------------------------------------------------------------------------------------
void hardcodearTipoArtista(eTipoArtista listaTipoArtista[], int tam, int* codigoTA)
{
	char descripcion[2][51] = {"solista", "banda"};

	for(int i=0;i<tam;i++)
	{
		(*codigoTA)++;
		listaTipoArtista[i].codigoTipoArtista = *codigoTA;
		strcpy(listaTipoArtista[i].descripcionTipoArtista, descripcion[i]);
	}
}

void hardcodearGenero(eGenero listaGeneros[], int tam, int* codigoG)
{
	char descripcionGenero[6][51] = {"clasico", "rock", "pop", "urbano", "bossa", "jazz"};

	for(int i=0;i<tam;i++)
	{
		(*codigoG)++;
		listaGeneros[i].codigoGenero = *codigoG;
		strcpy(listaGeneros[i].descripcionGenero, descripcionGenero[i]);
	}
}

void hardcodearArtista(eArtista listaArtistas[], int tam, int* codigoA)
{
	char nombre[10][51] = {"Pescado Rabioso", "Juana Molina", "Franz Liszt", "Mac Miller", "Madonna",
			"Frank Ocean", "Gorillaz", "Philip Glass", "Chico Buarque", "David Bowie"};
	int codigoTipoArtista[] = {102,101,101,101,101,101,102,101,101,101};
	for(int i=0;i<tam;i++)
	{
		(*codigoA)++;
		listaArtistas[i].codigoArtista = *codigoA;
		strcpy(listaArtistas[i].nombre, nombre[i]);
		listaArtistas[i].codigoTipoArtista = codigoTipoArtista[i];
	}
}

void hardcodearTipoAlbum(eTipoAlbum listaTiposAlbumes[], int tam, int* codigoTAlb)
{
	char descripcionTipoAlbum[3][51] = {"Vinilo", "Cinta", "CD"};
	for(int i=0; i<tam; i++)
	{
		(*codigoTAlb)++;
		listaTiposAlbumes[i].id = *codigoTAlb;
		strcpy(listaTiposAlbumes[i].descripcionTipoAlbum, descripcionTipoAlbum[i]);
	}
}

void hardcodearAlbumes(eAlbum listaAlbumes[])
{
	eAlbum carga[] = {
						{1,"Desatormentandonos", 500, 1, {1,9,1972}, 10001, 1002, 3},
						{2,"Pescado 2", 500, 1, {1,2,1973}, 10001, 1002, 3},
						{3,"Artaud", 750, 1, {1,10,1973}, 10001, 1002, 1},
						{4,"Halo", 1250.50, 1, {5,4,2017}, 10002, 1002, 3},
						{5,"Rapsodias Hungaras", 1400, 1, {14,1,2020}, 10003, 1001, 2},
						{6,"Swimming", 900, 1, {3,8,2018}, 10004, 1004, 1},
						{7,"Blonde", 850, 1, {20,8,2016}, 10006, 1004, 3},
						{8,"Chico Buarque", 500, 1, {19,6,1966}, 10009, 1005, 1},
						{9,"Glass: Piano Works", 1000, 1, {1,5,1968}, 10008, 1001, 2},
						{10,"Plastic Beach", 850, 1, {3,4,2010}, 10007, 1004, 3}
					};

	if(listaAlbumes!=NULL)
	{
		for(int i=0;i<10;i++)
		{
			listaAlbumes[i] = carga[i];
		}
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
//INICIALIZACION--------------------------------------------------------------------------------------------------
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
//INICIALIZACION---------------------------------------------------------------------------------------------------

//BUSQUEDAS---------------------------------------------------------------------------------------------------------
int buscarAlbumPorCodigo(eAlbum album[], int tam, int codigo)
{
	int retorno = 0;
	if(album!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(album[i].codigoAlbum == codigo)
			{
				retorno=1;
				break;
			}
		}
	}

	if(retorno==0)
	{
		system("cls");
		printf("Codigo no encontrado\n");
		system("pause");
	}
	return retorno;
}

int buscarIndiceAlbumPorCodigo(eAlbum album[], int tam, int codigo)
{
	int indice=0;
	if(album!=NULL)
	{
		for(int i=0; i<tam;i++)
		{
			if(album[i].codigoAlbum == codigo && album[i].estado == OCUPADO)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
//BUSQUEDAS---------------------------------------------------------------------------------------------------------

//ABM----------------------------------------------------------------------------------------------------------------
int altaEstructura(eAlbum albumes[], int tam, int* codigo, eGenero listaGeneros[], int tamGeneros, eArtista listaArtistas[],
		int tamArtistas, eTipoArtista listaTipoArtista[], int tamTipoArtista, int* codigoG, int* codigoA, int* codigoTA,
		eTipoAlbum listaTipoAlbum[], int tamTipoAlbumes, int* codigoTAlb)
{
	int indice;
	eAlbum auxAlbum;
	int retorno = 0;

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

			system("cls");
			printf("-----------------------------------\n");
			printf("                ALTA               \n");
			printf("-----------------------------------\n");

			(*codigo)++;
			auxAlbum.codigoAlbum = *codigo;

			do{
				printf("\nIngrese el titulo del album: ");
				fflush(stdin);
				scanf("%[^\n]", &auxAlbum.titulo);
			}while(!validarCadena(auxAlbum.titulo, 51));

			do{
				printf("\nIngrese el importe del album: ");
				fflush(stdin);
				scanf("%f", &auxAlbum.importe);
			}while(!validarNumeroRangos(auxAlbum.importe, 0, 999999));

			do{
				mostrarGeneros(listaGeneros, tamGeneros);
				printf("\nElija el genero al que pertenece el album: ");
				fflush(stdin);
				scanf("%d", &auxAlbum.codigoGenero);
			}while(!validarNumeroRangos(auxAlbum.codigoGenero, 1000, 1006));

			do{
				system("cls");
				mostrarArtistas(listaArtistas, tamArtistas, listaTipoArtista, tamTipoArtista, codigoTA);
				printf("\nElija el artista del album: ");
				fflush(stdin);
				scanf("%d", &auxAlbum.codigoArtista);
			}while(!validarNumeroRangos(auxAlbum.codigoArtista, 10000, 10010));

			do{
				system("cls");
				mostrarTipoAlbumes(listaTipoAlbum, tamTipoAlbumes, codigoTAlb);
				printf("\nElija el tipo de album: ");
				fflush(stdin);
				scanf("%d", &auxAlbum.codigoTipoAlbum);
			}while(!validarNumeroRangos(auxAlbum.codigoTipoAlbum, 1, 3));

			auxAlbum.fecha = cargarFecha();

			auxAlbum.estado = OCUPADO;

			retorno = 1;
		}

		albumes[indice] = auxAlbum;
	}

	return retorno;
}

int bajaEstructura(eAlbum albumes[], int tam, int*codigo, eGenero listaGeneros[], int tamGeneros, eArtista listaArtistas[],
		int tamArtistas, eTipoArtista listaTipoArtista[], int tamTipoArtista, int *codigoG, int *codigoA,
		eTipoAlbum listaTipoAlbum[], int tamTipoAlbumes, int* codigoTAlb)
{
	int retorno = 0;
	char confirmacion;
	int indice;
	int codigoBaja;
	eAlbum auxAlbum;

	if(albumes!=NULL &&  tam>0)
	{
		retorno = 1;
		system("cls");
		do{
			mostrarAlbumes(albumes, tam, listaGeneros, tamGeneros, listaArtistas, tamArtistas, codigoG, codigoA, listaTipoAlbum, codigoTAlb);
			printf("\n\nElija el codigo del album a eliminar: ");
			fflush(stdin);
			scanf("%d", &codigoBaja);
		}while(!buscarAlbumPorCodigo(albumes, tam, codigoBaja));

		indice = buscarIndiceAlbumPorCodigo(albumes, tam, codigoBaja);

		auxAlbum.estado = LIBRE;

		do{
			system("cls");
			printf("\nDesea dar de baja el album con codigo %d. Es correcto? (s/n)", codigoBaja);
			fflush(stdin);
			scanf("%c", &confirmacion);
		}while(!validarCaracterOpciones(confirmacion, 's', 'n'));

		if(confirmacion == 's')
		{
			albumes[indice].estado = auxAlbum.estado;
		}
		else
		{
			retorno = 0;
			system("cls");
			printf("Baja cancelada\n");
			system("pause");
		}
	}

	return retorno;
}

int modificarEstructura(eAlbum albumes[], int tam, eGenero listaGeneros[], int tamGeneros, eArtista listaArtistas[],
		int tamArtistas, eTipoArtista listaTipoArtista[], int tamTipoArtista, int *codigoG, int *codigoA,
		eTipoAlbum listaTipoAlbum[], int tamTipoAlbumes, int* codigoTAlb)
{
	eAlbum auxAlbum;
	int retorno = 0;
	int codigoModificar;
	int indice;
	int eleccion;
	char confirmacion;

	if(albumes!=NULL&&tam>0)
	{
		system("cls");
		do{
			mostrarAlbumes(albumes, tam, listaGeneros, tamGeneros, listaArtistas, tamArtistas, codigoG, codigoA, listaTipoAlbum, codigoTAlb);
			printf("\n\nElija el codigo del album a modificar: ");
			scanf("%d", &codigoModificar);
		}while(!buscarAlbumPorCodigo(albumes, tam, codigoModificar));

		indice = buscarIndiceAlbumPorCodigo(albumes, tam, codigoModificar);

		do{
			eleccion = subMenuModificar();

			switch(eleccion)
			{
			case 1:

				do
				{
					system("cls");
					printf("Cual es el nuevo titulo del album? ");
					fflush(stdin);
					scanf("%[^\n]", auxAlbum.titulo);
				}while(!validarCadena(auxAlbum.titulo, 51));
				do{
					system("cls");
					printf("El nuevo titulo es %s. Es correcto? (s/n)", auxAlbum.titulo);
					fflush(stdin);
					scanf("%c", &confirmacion);
				}while(!validarCaracterOpciones(confirmacion, 's', 'n'));
				if(confirmacion == 's')
				{
					strcpy(albumes[indice].titulo, auxAlbum.titulo);
					retorno=1;
				}
				else
				{
					system("cls");
					printf("modificacion cancelada\n");
					system("pause");
				}
				break;

			case 2:

				system("cls");
				printf("Cual es la nueva fecha de publicacion del album?\n");
				auxAlbum.fecha = cargarFecha();

				do{
					system("cls");
					printf("La nueva fecha es %d/%d/%d. Es correcto? (s/n)", auxAlbum.fecha.dia,
							auxAlbum.fecha.mes, auxAlbum.fecha.anio);
					fflush(stdin);
					scanf("%c", &confirmacion);
				}while(!validarCaracterOpciones(confirmacion, 's', 'n'));
				if(confirmacion == 's')
				{
					albumes[indice].fecha = auxAlbum.fecha;
					retorno=1;
				}
				else
				{
					system("cls");
					printf("modificacion cancelada\n");
					system("pause");
				}
				break;

			case 3:
				do
				{
					system("cls");
					printf("Cual es el nuevo importe del album?\n");
					printf("Ingrese el importe: ");
					scanf("%f", &auxAlbum.importe);
				}while(!validarNumeroRangos(auxAlbum.importe, 0, 999999));
				do{
					system("cls");
					printf("El nuevo importe es %.2f. Es correcto? (s/n)", auxAlbum.importe);
					fflush(stdin);
					scanf("%c", &confirmacion);
				}while(!validarCaracterOpciones(confirmacion, 's', 'n'));
				if(confirmacion == 's')
				{
					albumes[indice].importe = auxAlbum.importe;
					retorno=1;
				}
				else
				{
					system("cls");
					printf("modificacion cancelada\n");
					system("pause");
				}
				break;

			case 4:
				do
				{
					system("cls");
					mostrarTipoAlbumes(listaTipoAlbum, tamTipoAlbumes, codigoTAlb);
					printf("Cual es el nuevo tipo de album?\n");
					printf("Ingrese el id del tipo: ");
					fflush(stdin);
					scanf("%d", &auxAlbum.codigoTipoAlbum);
				}while(!validarNumeroRangos(auxAlbum.codigoTipoAlbum, 0, 3));


				do{
					system("cls");
					printf("El nuevo tipo de album es %s. Es correcto? (s/n)", listaTipoAlbum[(auxAlbum.codigoTipoAlbum)-1].descripcionTipoAlbum);
					fflush(stdin);
					scanf("%c", &confirmacion);
				}while(!validarCaracterOpciones(confirmacion, 's', 'n'));
				if(confirmacion == 's')
				{
					albumes[indice].codigoTipoAlbum = auxAlbum.codigoTipoAlbum;
					retorno=1;
				}
				else
				{
					system("cls");
					printf("modificacion cancelada\n");
					system("pause");
				}
				break;

			case 5:
				system("cls");
				printf("Ha salido del sub menu de modificacion.\n");
				system("pause");
				break;

			default:
				system("cls");
				printf("Opcion invalida. Elija nuevamente.\n");
				system("pause");
				break;
			}
		}while(eleccion!=4);
	}

	return retorno;
}
//ABM----------------------------------------------------------------------------------------------------------------

//CARGA DE DESCRIPCIONES---------------------------------------------------------------------------------------------
int cargaDescripcionTipoArtista(eTipoArtista listaTipoArtista[], int tam, int codigoTipoArtista, char descripcionTipoArtista[])
{
	int i;
	int retorno=0;

	if(listaTipoArtista!=NULL && tam>0 && descripcionTipoArtista!=NULL)
	{
		for(i=0; i<tam; i++)
		{
			if(listaTipoArtista[i].codigoTipoArtista==codigoTipoArtista)
			{
				strcpy(descripcionTipoArtista, listaTipoArtista[i].descripcionTipoArtista);
				retorno=1;
				break;
			}
		}
	}

	return retorno;
}

int cargaDescripcionTipoAlbum(eTipoAlbum listaTipoAlbum[], int tam, int codigoTipoAlbum, char descripcionTipoAlbum[])
{
	int i;
	int retorno=0;

	if(listaTipoAlbum!=NULL && tam>0 && descripcionTipoAlbum!=NULL)
	{
		for(i=0; i<tam; i++)
		{
			if(listaTipoAlbum[i].id==codigoTipoAlbum)
			{
				strcpy(descripcionTipoAlbum, listaTipoAlbum[i].descripcionTipoAlbum);
				retorno=1;
				break;
			}
		}
	}

	return retorno;
}

int cargaNombreArtista(eArtista listaArtistas[], int tam, int codigoArtista, char nombreArtista[])
{
	int i;
	int retorno=0;

	if(listaArtistas!=NULL && tam>0 &&  nombreArtista!=NULL)
	{
		for(i=0; i<tam; i++)
		{
			if(listaArtistas[i].codigoArtista==codigoArtista)
			{
				strcpy(nombreArtista, listaArtistas[i].nombre);
				retorno=1;
				break;
			}
		}
	}

	return retorno;
}

int cargaDescripcionGenero(eGenero listaGeneros[], int tam, int codigoGenero, char descripcionGenero[])
{
	int i;
	int retorno;

	if(listaGeneros!=NULL && tam>0)
	{
		for(i=0; i<tam; i++)
		{
			if(listaGeneros[i].codigoGenero==codigoGenero)
			{
				strcpy(descripcionGenero, listaGeneros[i].descripcionGenero);
				retorno=1;
				break;
			}
		}
	}

	return retorno;
}

//CARGA DE DESCRIPCIONES----------------------------------------------------------------------------------------------

eFecha cargarFecha()
{
	int dia;
	int mes;
	int anio;

	do{
	system("cls");
	printf("Ingrese el dia: ");
	fflush(stdin);
	scanf("%d", &dia);
	}while(!validarNumeroRangos(dia, 0, 31));

	do{
	printf("Ingrese el mes: ");
	fflush(stdin);
	scanf("%d", &mes);
	}while(!validarNumeroRangos(mes, 0, 12));

	do{
	printf("Ingrese el anio: ");
	fflush(stdin);
	scanf("%d", &anio);
	}while(!validarNumeroRangos(anio, 1919, 2022));

	eFecha fecha = {dia, mes, anio};

	return fecha;
}
