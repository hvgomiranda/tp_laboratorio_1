#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include "header.h"


int menu(int kilometros, float precioAerolineas, float precioLatam)
{
	int eleccion;

	system("cls");

	if(!kilometros)
	{
		printf("1. Ingresar kilometros\n");
	}
	else
	{
		printf("1. Reingresar kilometros (km ingresados: %d)\n", kilometros);
	}

	if(!precioAerolineas&&!precioLatam)
	{
		printf("2. Ingresar el precio de los vuelos\n");
	}
	else if(!precioAerolineas)
	{
		printf("2. Ingresar el precio del vuelo de Aerolineas (LATAM: %.2f)\n", precioLatam);
	}
	else if(!precioLatam)
	{
		printf("2. Ingresar el precio del vuelo de LATAM (Aerolineas: %.2f)\n", precioAerolineas);
	}
	else
	{
		printf("2. Reingresar el precio de los vuelos (Aerolineas: %.2f / LATAM: %.2f)\n", precioAerolineas, precioLatam);
	}

	printf("3. Calcular todos los costos\n");
	printf("4. Informar resultados\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n\n");

	printf("Ingrese la opcion elegida: ");
	scanf("%d", &eleccion);

	return eleccion;
}

int subMenu(float precioAerolineas, float precioLatam)
{
	int eleccion;

	system("cls");
	if(!precioAerolineas)
	{
		printf("1. Ingresar precio de Aerolineas\n");
	}
	else
	{
		printf("1. Reingrese el precio de Aerolineas (precio ingresado: %.2f)\n", precioAerolineas);
	}

	if(!precioLatam)
	{
		printf("2. Ingresar precio de LATAM\n");
	}
	else
	{
		printf("2. Reingrese el precio de LATAM (precio ingresado: %.2f)\n", precioLatam);
	}
	printf("3. Salir\n\n");

	printf("Ingrese la opcion elegida: ");
	scanf("%d", &eleccion);

	return eleccion;
}

float precioDebito(float precio)
{
	precio = precio*0.9;
	return precio;
}

float precioCredito(float precio)
{
	precio = precio*1.25;
	return precio;
}

float precioBitcoin(float precio)
{
	precio = precio/4606954.55;
	return precio;
}

float precioUnitario(float precio, int kilometros)
{
	precio = precio/kilometros;
	return precio;
}

float diferenciaDePrecios(float precioAerolineas, float precioLatam)
{
	float diferencia;

	diferencia = precioAerolineas - precioLatam;
	if(diferencia<0)
	{
		diferencia=diferencia*-1;
	}
	return diferencia;
}
