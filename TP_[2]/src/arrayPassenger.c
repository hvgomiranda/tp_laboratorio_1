/*
 * ArrayPassenger.c
 *
 *  Created on: 13 may. 2022
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include "header.h"

int initPassengers(Passenger* list, int len)
{
    int ok = -1;

    if(list!=NULL && len>0)
    {
        ok = 0;
        for(int i=0;i<len;i++)
        {
        	(list+i)->isEmpty = 1;
        }
    }

    return ok;
}

int newPassenger(Passenger* aPassenger)
{
	int ok = -1;
	char auxName[51];
	char auxLastName[51];
	char auxPrice[51];
	char auxFlycode[51];
	char auxType[51];
	char auxStatus[51];
	int auxInteger;
	float auxFloat;

	if(aPassenger != NULL)
	{
		ok = 0;

		system("cls");
		printf("---------------------------------------\n");
		printf("------------ALTA DE PASAJERO-----------\n");
		printf("---------------------------------------\n");

		do{
			printf("Ingrese el nombre del pasajero: ");
			fflush(stdin);
			scanf("%[^\n]", auxName);
		}while(!validateString(auxName));
		strcpy(aPassenger->name,auxName);

		do{
			printf("Ingrese el apellido del pasajero: ");
			fflush(stdin);
			scanf("%[^\n]", auxLastName);
		}while(!validateString(auxLastName));
		strcpy(aPassenger->lastName,auxLastName);

		do
		{
			printf("Ingrese el precio: ");
			fflush(stdin);
			scanf("%[^\n]", auxPrice);
			auxFloat = validateFloat(auxPrice, 0, 99999999);
			ok=0;
		}while(!auxFloat);
		aPassenger->price = auxFloat;

		do{
			printf("Ingrese el codigo del vuelo: ");
			fflush(stdin);
			scanf("%[^\n]", auxFlycode);
		}while(!validateAlphanum(auxFlycode));
		strcpy(aPassenger->flycode,auxFlycode);

		do{
			printf("Ingrese el tipo de pasajero: ");
			fflush(stdin);
			scanf("%[^\n]", auxType);
			auxInteger = validateInt(auxType, 0, 4);
		}while(!auxInteger);
		aPassenger->typePassenger = auxInteger;

		do{
			printf("Ingrese el estado de vuelo: ");
			fflush(stdin);
			scanf("%[^\n]", auxStatus);
			auxInteger = validateInt(auxStatus, 0, 4);
		}while(!auxInteger);
		aPassenger->flightStatus = auxInteger;

		aPassenger->isEmpty = 0;
	}

	return ok;
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int flightStatus)
{
    int ok = -1;
    int index;
    if(list!=NULL && len>0 && name!=NULL && lastName!=NULL && flycode!=NULL)
    {
    	ok = 0;
    	index = findEmpty(list, len);

    	(list+index)->id = id;
    	strcpy((list+index)->name,name);
    	strcpy((list+index)->lastName,lastName);
    	(list+index)->price = price;
    	(list+index)->typePassenger = typePassenger;
    	strcpy((list+index)->flycode, flycode);
    	(list+index)->flightStatus = flightStatus;
    	(list+index)->isEmpty = 0;
    	system("cls");
		printf("---------------------------------------\n");
		printf("----------------PASAJERO---------------\n");
		printf("---------------------------------------\n");
		printf("ID NOMBRE APELLIDO  PRECIO  TIPO  VUELO ESTADO\n");
		showPassenger(list, index);
		printf("\n\nAlta exitosa\n\n");
		system("pause");
    }

    return ok;
}

int findPassengerById(Passenger* list, int len)
{
	int idFound;
	char auxChar[51];
	int continuar = 1;
	int index=-1;
	if(list!=NULL&&len>0)
	{
		idFound = 0;

		do
		{
			showPassengers(list, len);
			do{
				printf("Elija un id: ");
				fflush(stdin);
				scanf("%[^\n]", auxChar);
				idFound = validateInt(auxChar, 0, len+1);
			}while(!idFound);

			for(int i=0;i<len;i++)
			{
				if((list+i)->id == idFound)
				{
					index = i;
					continuar = 0;
					break;
				}
			}
		}while(continuar);
	}

	return index;
}

int modifyPassenger(Passenger* list, int len, int index)
{
	int ok = -1;
	int option = 0;
	int continuar = 1;
	float auxFloat;
	int auxInteger;
	char auxName[51];
	char auxLastName[51];
	char auxPrice[51];
	char auxFlycode[51];
	char auxType[51];
	char auxStatus[51];

	if(list!=NULL&&len>0)
	{
		ok=1;
		do
		{
			system("cls");
			printf("ID NOMBRE APELLIDO  PRECIO  TIPO  VUELO\n");
			printf("---------------------------------------\n");
			showPassenger(list, index);
			printf("---------------------------------------\n");
			printf("1. Modificar nombre\n");
			printf("2. Modificar apellido\n");
			printf("3. Modificar precio del vuelo\n");
			printf("4. Modificar el codigo de vuelo\n");
			printf("5. Modificar el tipo de pasajero\n");
			printf("6. Modificar el estado de vuelo\n");
			printf("7. Salir\n");
			printf("Ingrese opcion: ");
			scanf("%d", &option);

			switch (option)
			{
			case 1:
				printf("Ingrese el nombre del pasajero: ");
				fflush(stdin);
				scanf("%[^\n]", auxName);
				while(!validateString(auxName))
				{
					printf("Error. Reingrese el nombre del pasajero: ");
					fflush(stdin);
					scanf("%[^\n]", auxName);
				}
				strcpy(list[index].name,auxName);
				break;

			case 2:
				printf("Ingrese el apellido del pasajero: ");
				fflush(stdin);
				scanf("%[^\n]", auxLastName);
				while(!validateString(auxLastName))
				{
					printf("Error. Reingrese el apellido del pasajero: ");
					fflush(stdin);
					scanf("%[^\n]", auxLastName);
				}
				strcpy(list[index].lastName,auxLastName);
				break;

			case 3:
				printf("Ingrese el precio: ");
				fflush(stdin);
				scanf("%[^\n]", auxPrice);
				auxFloat = validateFloat(auxPrice, 0, 99999999);
				while(!auxFloat)
				{
					printf("Error. Reingrese el precio: ");
					fflush(stdin);
					scanf("%[^\n]", auxPrice);
					auxFloat = validateFloat(auxPrice, 0, 99999999);
					ok=0;
				}
				list[index].price = auxFloat;
				break;

			case 4:
				printf("Ingrese el codigo del vuelo: ");
				fflush(stdin);
				scanf("%[^\n]", auxFlycode);
				while(!validateAlphanum(auxFlycode))
				{
					printf("Error. Reingrese el codigo del vuelo: ");
					fflush(stdin);
					scanf("%[^\n]", auxFlycode);
				}
				strcpy(list[index].flycode,auxFlycode);
				break;

			case 5:
				printf("Ingrese el tipo de pasajero: ");
				fflush(stdin);
				scanf("%[^\n]", auxType);
				auxInteger = validateInt(auxType, 0, 4);
				while(!auxInteger)
				{
					printf("Error. Reingrese el tipo de pasajero: ");
					fflush(stdin);
					scanf("%[^\n]", auxType);
					auxInteger = validateInt(auxType, 0, 4);
					ok=0;
				}
				list[index].typePassenger = auxInteger;
				break;

			case 6:
				printf("Ingrese el estado del vuelo: ");
				fflush(stdin);
				scanf("%[^\n]", auxStatus);
				auxInteger = validateInt(auxStatus, 0, 4);
				while(!auxInteger)
				{
					printf("Error. Reingrese el estado del vuelo: ");
					scanf("%[^\n]", auxStatus);
					auxInteger = validateInt(auxStatus, 0, 4);
					ok=0;
				}
				list[index].flightStatus = auxInteger;
				break;

			case 7:
				continuar = 0;
				break;

			default:
				printf("Ingrese una opcion valida\n");
				break;
			}
		}while(continuar);
	}

	return ok;
}

int removePassenger(Passenger* list, int len, int index)
{
	int ok = -1;
	char input;

	if(list!=NULL && len>0 && index>0)
	{
		system("cls");
		printf("va a eliminar el pasajero: \n\n");
		showPassenger(list, index);

		do{
			printf("\nEsta seguro? (s/n) ");
			fflush(stdin);
			input = getchar();
			input = tolower(input);
		}while(!validateCharOptions(input, 's', 'n'));

		if(input=='s')
		{
			(list+index)->isEmpty = 1;
			ok = 0;
		}
		else
		{
			ok = 1;
		}
	}

	return ok;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int ok = -1;
	Passenger auxPassenger;
	if (list != NULL && len > 0 && order >= 0 && order <= 1) {
		ok = 0;
		switch (order)
		{
		case 1:
			for (int i=0; i<len-1; i++)
			{
				for (int j=i+1; j<len; j++)
				{
					if (strcmp(list[i].lastName, list[j].lastName) > 0
					|| (strcmp(list[i].lastName, list[j].lastName) == 0
						&& list[i].typePassenger > list[j].typePassenger))
					{
						auxPassenger = list[j];
						list[j] = list[i];
						list[i] = auxPassenger;
					}
				}
			}
			break;
		case 0:
			for (int i=0; i<len-1; i++)
			{
				for (int j=i+1; j<len; j++)
				{
					if (strcmp(list[i].lastName, list[j].lastName) < 0
					|| (strcmp(list[i].lastName, list[j].lastName) == 0
						&& list[i].typePassenger < list[j].typePassenger))
					{
						auxPassenger = list[j];
						list[j] = list[i];
						list[i] = auxPassenger;
					}
				}
			}
			break;
		}
	}
	return ok;
}

int sortPassengersByCode(Passenger list[], int len, int order)
{
	int retorno=-1;

	Passenger aux;

	if(list!=NULL && len>0)
	{
		retorno=0;
		printf("\n-------------------Lista de pasajeros-------------------\n\n");
		if(order==0)
		{
			for (int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmpi(list[i].flycode,list[j].flycode)<0
					|| (strcmpi(list[i].flycode,list[j].flycode)==0 && list[i].flightStatus>list[j].flightStatus))
					{
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
				}
			}
		}
		else
		{
			for (int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmpi(list[i].flycode,list[j].flycode)>0
					|| (strcmpi(list[i].flycode,list[j].flycode)==0 && list[i].flightStatus>list[j].flightStatus))
					{
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
				}
			}
		}

	}

	return retorno;
}

int averagePrice(Passenger* list, int len)
{
	int ok=-1;
	int total=0;
	float totalPrecios=0;
	float promedioPrecios;
	int totalPreciosArribaDelPromedio=0;


	if(list!=NULL && len>0)
	{
		ok=0;
		for (int i=0; i<len; i++)
		{
			if(!list[i].isEmpty)
			{
				total++;
				totalPrecios += (list+i)->price;
			}
		}

		promedioPrecios =  totalPrecios/total;

		for (int i=0; i<len; i++)
		{
			if((list+i)->isEmpty == 0 && ((list+i)->price > promedioPrecios))
			{
				totalPreciosArribaDelPromedio++;
			}
		}
		system("cls");
		printf("El total de precios es de %.2f\n", totalPrecios);
		printf("El promedio de precios es de %.2f\n", promedioPrecios);
		printf("Hay %d vuelos que costaron mas que el promedio\n", totalPreciosArribaDelPromedio);
		system("pause");
	}
	return ok;
}

int findEmpty(Passenger* list, int len)
{
	int index = -1;

	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if((list+i)->isEmpty == 1)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int showPassenger(Passenger* list, int index)
{
	int ok = -1;
	if(list != NULL)
	{
		ok = 0;
		printf("%d   %3s   %3s   $%5.2f  %1d   %5s  %2d\n",
										list[index].id,
										list[index].name,
										list[index].lastName,
										list[index].price,
										list[index].typePassenger,
										list[index].flycode,
										list[index].flightStatus);
	}
	return ok;
}

int showPassengers(Passenger* list, int len)
{
	int ok = -1;
	if(list != NULL && len>0)
	{
		ok = 0;
		system("cls");
		printf("--------------------------------------------\n");
		printf("-------------------PASAJERO-----------------\n");
		printf("--------------------------------------------\n");
		printf("ID  NOMBRE  APELLIDO   PRECIO    TIPO  VUELO\n");
		for(int i=0;i<len;i++)
		{
			if(!list[i].isEmpty)
			{
				showPassenger(list, i);
				printf("---------------------------------------\n");
			}
		}

	}
	return ok;
}

int newOrder()
{
	int order;
	system("cls");
	printf("Desea ordenar ascendente o descendentemente? (1 para asc/0 para desc) ");
	scanf("%d", &order);
	while(order!=0 && order!=1)
	{
		system("cls");
		printf("Error. Elija nuevamente (1 para asc/0 para desc) ");
        scanf("%d", &order);
	}
	return order;
}
