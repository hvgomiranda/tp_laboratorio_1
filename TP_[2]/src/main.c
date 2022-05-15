/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Hugo Miranda Campos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include "header.h"

int main()
{
	setbuf(stdout, NULL);

    int subContinuar;
    int indexToRemove;
    int indexToModify;
    int id=1;
    int order;
    int continuar = 1;
    int passengersSize=0;
    Passenger aPassenger;
    Passenger list[LEN];
    initPassengers(list, LEN);

    do
    {
        switch(menu())
        {
        case 1:
			if(!newPassenger(&aPassenger))
			{
				aPassenger.id = id;
				if(!addPassenger(list, LEN, aPassenger.id, aPassenger.name, aPassenger.lastName, aPassenger.price, aPassenger.typePassenger, aPassenger.flycode))
				{
					id++;
					passengersSize++;
				}
			}
			else
			{
				system("cls");
				printf("Hubo un error al intentar agregar un nuevo pasajero\n\n");
				system("pause");
			}
			break;

        case 2:
        	if(passengersSize)
        	{
				indexToModify = findPassengerById(list, LEN);
				if(indexToModify==-1)
				{
					system("cls");
					printf("No se ha encontrado el pasajero\n");
					system("pause");
				}
				else
				{
					if(modifyPassenger(list, LEN, indexToModify))
					{
						system("cls");
						printf("No se ha modificado ningun pasajero\n");
						system("pause");
					}
					else
					{
						system("cls");
						printf("Modificacion exitosa\n");
						system("pause");
					}

				}
        	}
        	else
        	{
				system("cls");
				printf("No se ha ingresado ningun pasajero\n");
				system("pause");
        	}
			break;

        case 3:
        	if(passengersSize)
        	{
				indexToRemove = findPassengerById(list, LEN);
				if(indexToRemove==-1)
				{
					system("cls");
					printf("No se ha encontrado el pasajero\n");
					system("pause");
				}
				else
				{
					if(removePassenger(list, LEN, indexToRemove))
					{
						system("cls");
						printf("No se ha eliminado ningun pasajero\n");
						system("pause");
					}
					else
					{
						system("cls");
						printf("Eliminacion exitosa\n");
						system("pause");
						passengersSize--;
					}

				}
        	}
        	else
        	{
				system("cls");
				printf("No se ha ingresado ningun pasajero\n");
				system("pause");
        	}
			break;

        case 4:
        	if(passengersSize)
        	{
				do{
					switch(subMenu())
					{
					case 1:
					order = newOrder();
					sortPassengers(list, LEN, order);
					showPassengers(list, LEN);
					printf("\n\n");
					system("pause");
					break;

					case 2:
					averagePrice(list, LEN);
					break;

					case 3:
					printf("informar 3\n");
					break;

					case 4:
					system("cls");
					printf("Saliste del submenu\n\n");
					subContinuar = 0;
					system("pause");
					break;

					default:
					system("cls");
					printf("Error, elija nuevamente\n");
					system("pause");
					break;
					}
				}while(subContinuar);
        	}
        	else
        	{
				system("cls");
				printf("No se ha ingresado ningun pasajero\n");
				system("pause");
        	}
			break;

        case 5:
			continuar = 0;
			break;

        default:
			printf("Error, elija nuevamente\n");
			break;
        }
    }while(continuar);

	return EXIT_SUCCESS;
}
