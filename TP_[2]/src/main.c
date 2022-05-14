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
    int subEleccion;
    int indexToRemove;
    int indexToModify;
    int id=1;
    int continuar = 1;
    Passenger aPassenger;
    Passenger list[LEN];
    initPassengers(list, LEN);

    setbuf(stdout, NULL);

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
        	indexToModify = findPassengerById(list, LEN);
        	modifyPassenger(list, LEN, indexToModify);
			break;

        case 3:
        	do{
				indexToRemove = findPassengerById(list, LEN);
				if(indexToRemove==-1)
				{
					system("cls");
					printf("No se ha encontrado el pasajero\n");
					system("pause");
				}
				else
				{
					removePassenger(list, LEN, indexToRemove);
					//agregar las validaciones y qué se hace con los retornos
				}


        	}while();



			break;

        case 4:
			do{
				subEleccion = subMenu();
				switch(subEleccion)
				{
				case 1:
				printf("informar 1\n");
				break;

				case 2:
				printf("informar 2\n");
				break;

				case 3:
				printf("informar 3\n");
				break;

				case 4:
				printf("informar 4\n");
				break;

				default:
				printf("Error, elija nuevamente\n");
				break;
				}
			}while(subEleccion!=4);
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
