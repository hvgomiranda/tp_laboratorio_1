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
#include <Windows.h>
#include "header.h"

int main(void) {

	int eleccion, subEleccion;
	float precioDebitoAerolineas, precioDebitoLatam, precioCreditoAerolineas, precioCreditoLatam, precioBitcoinAerolineas, precioBitcoinLatam, precioUnitarioAerolineas, precioUnitarioLatam, diferencia;
	float kilometros=0;
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
			kilometros = validacionNumeroPositivo("Ingrese la cantidad de kilometros:");
			break;

		case 2:
			subEleccion = subMenu(precioAerolineas, precioLatam);
			switch(subEleccion)
			{
			case 1:
				precioAerolineas = validacionNumeroPositivo("Ingrese el precio de Aerolineas:");
				break;

			case 2:
				precioLatam = validacionNumeroPositivo("Ingrese el precio de LATAM:");
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
				printf("Precios calculados\n");
				system("pause");
			}
			else
			{
				system("cls");
				printf("Falta ingresar algun dato para poder calcular los costos\n\n");
				system("pause");
			}
			break;

		case 4:
			if(precioAerolineas&&precioLatam&&kilometros&&costosCalculados)
			{
				imprimirResultados(kilometros, precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas,
						precioBitcoinAerolineas, precioUnitarioAerolineas, precioLatam, precioDebitoLatam,
						precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam, diferencia);
			}
			else
			{
				system("cls");
				printf("Falta ingresar algun dato para poder mostrar los resultados\n\n");
				system("pause");
			}
			break;

		case 5:
			system("cls");
			printf("Si cargo manualmente algun dato, la carga forzada lo sobrescribira.\n\nEstas seguro de querer hacer esta accion (s/n)? ");
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
				imprimirResultados(kilometros, precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas,
										precioBitcoinAerolineas, precioUnitarioAerolineas, precioLatam, precioDebitoLatam,
										precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam, diferencia);
			}
			else
			{
				system("cls");
				printf("Carga forzada cancelada");
				system("pause");
			}
			break;

		case 6:
			system("cls");
			printf("Estas seguro de salir del programa (s/n)? ");
			fflush(stdin);
			scanf("%c", &decisionSalida);
			decisionSalida = tolower(decisionSalida);
			while(decisionSalida!='s'&&decisionSalida!='n')
			{
				system("cls");
				printf("Error. Ingrese nuevamente 's' si desea salir, 'n' si desea cancelar: ");
				fflush(stdin);
				scanf("%c", &decisionSalida);
				decisionSalida = tolower(decisionSalida);
			}
			if(decisionSalida=='s')
			{
				system("cls");
				printf("Gracias por usar este programa\n");
				Sleep(1500);
			}
			else
			{
				system("cls");
				printf("Salida cancelada\n");
				system("pause");
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
