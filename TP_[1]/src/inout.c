#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include "header.h"

int menu(float kilometros, float precioAerolineas, float precioLatam)
{
	int eleccion;

	system("cls");

	if(!kilometros)
	{
		printf("1. Ingresar kilometros\n");
	}
	else
	{
		printf("1. Reingresar kilometros (km ingresados: ");
		imprimirDecimales(kilometros);
		printf(")\n");
	}

	if(!precioAerolineas&&!precioLatam)
	{
		printf("2. Ingresar el precio de los vuelos\n");
	}
	else if(!precioAerolineas)
	{
		printf("2. Ingresar el precio del vuelo de Aerolineas (LATAM: ");
		imprimirDecimales(precioLatam);
		printf(")\n");
	}
	else if(!precioLatam)
	{
		printf("2. Ingresar el precio del vuelo de LATAM (Aerolineas: ");
		imprimirDecimales(precioAerolineas);
		printf(")\n");
	}
	else
	{
		printf("2. Reingresar el precio de los vuelos (Aerolineas: ");
		imprimirDecimales(precioAerolineas);
		printf(" / LATAM: ");
		imprimirDecimales(precioLatam);
		printf(")\n");
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
		printf("1. Reingrese el precio de Aerolineas (precio ingresado: $");
		imprimirDecimales(precioAerolineas);
		printf(")\n");
	}

	if(!precioLatam)
	{
		printf("2. Ingresar precio de LATAM\n");
	}
	else
	{
		printf("2. Reingrese el precio del vuelo de LATAM (precio ingresado: $");
		imprimirDecimales(precioLatam);
		printf(")\n");
	}
	printf("3. Salir\n\n");

	printf("Ingrese la opcion elegida: ");
	scanf("%d", &eleccion);

	return eleccion;
}

void imprimirResultados(float kilometros, float precioAerolineas, float precioDebitoAerolineas, float precioCreditoAerolineas,
		float precioBitcoinAerolineas, float precioUnitarioAerolineas, float precioLatam, float precioDebitoLatam,
		float precioCreditoLatam, float precioBitcoinLatam, float precioUnitarioLatam, float diferencia)
{
	system("cls");

	printf("Kilometros: ");
	imprimirDecimales(kilometros);
	printf("\n\n");

	printf("Precio Aerolineas: $");
	imprimirDecimales(precioAerolineas);
	printf("\n");

	printf("Precio con tarjeta de debito: $");
	imprimirDecimales(precioDebitoAerolineas);
	printf("\n");

	printf("Precio con tarjeta de credito: $");
	imprimirDecimales(precioCreditoAerolineas);
	printf("\n");

	printf("Precio pagando con bitcoin: %f\n", precioBitcoinAerolineas);

	printf("Precio por kilometro (precio unitario): $");
	imprimirDecimales(precioUnitarioAerolineas);
	printf("\n\n");


	printf("Precio LATAM: $");
	imprimirDecimales(precioLatam);
	printf("\n");

	printf("Precio con tarjeta de debito: $");
	imprimirDecimales(precioDebitoLatam);
	printf("\n");

	printf("Precio con tarjeta de credito: $");
	imprimirDecimales(precioCreditoLatam);
	printf("\n");

	printf("Precio pagando con bitcoin: %f\n", precioBitcoinLatam);

	printf("Precio por kilometro (precio unitario): $");
	imprimirDecimales(precioUnitarioLatam);
	printf("\n\n");

	printf("La diferencia de precios es de $");
	imprimirDecimales(diferencia);
	printf("\n\n");

	system("pause");
}

void imprimirDecimales(float numero)
{
	if(numero==(int)numero)
	{
		printf("%.0f",numero);
	}
	else
	{
		printf("%.2f", numero);
	}
}

float validacionNumeroPositivo(char mensaje[])
{
	float numero;
	system("cls");
	printf("%s ", mensaje);
	scanf("%f", &numero);

	while(numero<=0)
	{
		system("cls");
		printf("El numero no puede ser menor o igual que cero\n");
		printf("%s ", mensaje);
		scanf("%f", &numero);
	}

	return numero;
}
