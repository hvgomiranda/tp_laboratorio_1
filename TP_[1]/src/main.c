/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Miranda Campos, Hugo
 Version     :
 Copyright   : UTN
 Description : Primer trabajo práctico de laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

int main(void) {

	int eleccion;
	int subEleccion;
	float precioDebitoAerolineas, precioDebitoLatam, precioCreditoAerolineas, precioCreditoLatam, precioBitcoinAerolineas, precioBitcoinLatam, precioUnitarioAerolineas, precioUnitarioLatam, diferencia;
	int kilometros=0;
	float precioAerolineas=0;
	float precioLatam=0;
	int costosCalculados = 0;
	char decisionCargaForzada, decisionSalida;

	setbuf(stdout, NULL);

	do
	{
		eleccion = menu(kilometros, precioAerolineas, precioLatam);
		switch(eleccion)
		{
		case 1:
			system("cls");
			printf("Ingrese los kilometros: ");
			scanf("%d", &kilometros);
			break;

		case 2:
			subEleccion = subMenu(precioAerolineas, precioLatam);
			switch(subEleccion)
			{
			case 1:
				system("cls");
				printf("Ingrese el precio de Aerolineas: ");
				scanf("%f", &precioAerolineas);
				break;

			case 2:
				system("cls");
				printf("Ingrese el precio de LATAM: ");
				scanf("%f", &precioLatam);
				break;

			case 3:
				break;

			default:
				printf("Error\n");
				system("pause");
			}
			break;

		case 3:
			if(precioAerolineas&&precioLatam&&kilometros)
			{
				precioDebitoAerolineas = precioDebito(precioAerolineas);
				precioDebitoLatam = precioDebito(precioLatam);
				precioCreditoAerolineas = precioCredito(precioAerolineas);
				precioCreditoLatam = precioCredito(precioLatam);
				precioBitcoinAerolineas = precioBitcoin(precioAerolineas);
				precioBitcoinLatam = precioBitcoin(precioLatam);
				precioUnitarioAerolineas = precioUnitario(precioAerolineas, kilometros);
				precioUnitarioLatam = precioUnitario(precioLatam, kilometros);
				diferencia =  diferenciaDePrecios(precioAerolineas, precioLatam);
				costosCalculados=1;
				system("cls");
				printf("Precios calculados!\n");
				sleep(2);
			}
			else
			{
				system("cls");
				printf("Falta ingresar algun dato para poder calcular los costos\n");
				system("pause");
			}
			break;

		case 4:
			if(precioAerolineas&&precioLatam&&kilometros&&costosCalculados)
			{
				system("cls");

				printf("Aerolineas\n");
				printf("Precio con tarjeta de debito: %f\n", precioDebitoAerolineas);
				printf("Precio con tarjeta de credito: %f\n", precioCreditoAerolineas);
				printf("Precio pagando con bitcoin: %f\n", precioBitcoinAerolineas);
				printf("Precio por kilometro (precio unitario): %f\n\n", precioUnitarioAerolineas);

				printf("LATAM\n");
				printf("Precio con tarjeta de debito: %f\n", precioDebitoLatam);
				printf("Precio con tarjeta de credito: %f\n", precioCreditoLatam);
				printf("Precio pagando con bitcoin: %f\n", precioBitcoinLatam);
				printf("Precio por kilometro (precio unitario): %f\n\n", precioUnitarioLatam);

				printf("La diferencia de precios es de %f\n\n", diferenciaDePrecios);

				system("pause");
			}
			else
			{
				printf("Error ");
			}
			break;

		case 5:
			system("cls");
			printf("Estas seguro de querer hacer una carga forzada (s/n)? Sobrescribira los datos ingresados manualmente ");
			fflush(stdin);
			scanf("%c", &decisionCargaForzada);
			decisionCargaForzada = tolower(decisionCargaForzada);
			while(decisionCargaForzada!='s'&&decisionCargaForzada!='n')
			{
				system("cls");
				printf("Error. Ingrese nuevamente 's' si desea hacer una carga forzada, 'n' si desea cancelar: ");
				fflush(stdin);
				scanf("%c", &decisionCargaForzada);
				decisionCargaForzada = tolower(decisionCargaForzada);
			}
			if(decisionCargaForzada=='s')
			{
				kilometros=7090;
				precioAerolineas=162965;
				precioLatam=159339;
				precioDebitoAerolineas = precioDebito(precioAerolineas);
				precioDebitoLatam = precioDebito(precioLatam);
				precioCreditoAerolineas = precioCredito(precioAerolineas);
				precioCreditoLatam = precioCredito(precioLatam);
				precioBitcoinAerolineas = precioBitcoin(precioAerolineas);
				precioBitcoinLatam = precioBitcoin(precioLatam);
				precioUnitarioAerolineas = precioUnitario(precioAerolineas, kilometros);
				precioUnitarioLatam = precioUnitario(precioLatam, kilometros);
				diferencia =  diferenciaDePrecios(precioAerolineas, precioLatam);
				costosCalculados=1;
			}
			else
			{
				system("cls");
				printf("Carga forzada cancelada");
			}
			break;

		case 6:
			system("cls");
			printf("Estas seguro de salir del programa (s/n)? ");
			fflush(stdin);
			scanf("%c", decisionSalida);
			decisionSalida = tolower(decisionSalida);
			while(decisionSalida!='s'&&decisionSalida!='n')
			{
				printf("Error. Ingrese nuevamente 's' si desea salir, 'n' si desea cancelar: ");
				fflush(stdin);
				scanf("%c", decisionSalida);
				decisionSalida = tolower(decisionSalida);
			}
			if(decisionSalida=='s')
			{
				eleccion = 6;
			}
			else
			{
				system("cls");
				printf("Salida cancelada");
				eleccion = 1;
			}
			break;

		default:
			printf("Eleccion erronea. Vuelva a elegir.");
			break;
		}
	}while(eleccion!=6);

	return EXIT_SUCCESS;
}
