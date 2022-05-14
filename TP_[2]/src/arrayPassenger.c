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
	char auxString[51];
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
			gets(auxString);
		}while(!validateString(auxString, 2, 51));
		printf("%s\n", auxString);
		strcpy(aPassenger->name,auxString);

		do{
			printf("Ingrese el apellido del pasajero: ");
			fflush(stdin);
			gets(auxString);
		}while(!validateString(auxString, 1, 51));
		strcpy(aPassenger->lastName,auxString);

		do{
			printf("Ingrese el precio del vuelo: ");
			scanf("%f", &auxFloat);
		}while(!validateFloat(auxFloat, 0, 9999999));
		aPassenger->price = auxFloat;

		do{
			printf("Ingrese el codigo del vuelo: ");
			fflush(stdin);
			gets(auxString);
		}while(!validateString(auxString, 0, 10));
		strcpy(aPassenger->flycode,auxString);

		do{
			printf("Ingrese el tipo de pasajero: ");
			scanf("%d", &auxInteger);
		}while(!validateFloat(auxInteger, 0, 5));
		aPassenger->typePassenger = auxInteger;

		aPassenger->isEmpty = 0;
	}

	return ok;
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
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
    	(list+index)->isEmpty = 0;
		printf("---------------------------------------\n");
		printf("----------------PASAJERO---------------\n");
		printf("---------------------------------------\n");
		printf("ID NOMBRE APELLIDO  PRECIO  TIPO  VUELO\n");
		showPassenger(list, index);
    }

    return ok;
}

int findPassengerById(Passenger* list, int len)
{
	int idFound;
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
				scanf("%d", &idFound);
			}while(!validateInt(idFound, 0, len+1));

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
	char auxString[1000];
	float auxFloat;
	int auxInteger;

	if(list!=NULL&&len>0)
	{
		ok=1;
		do
		{
			printf("ID NOMBRE APELLIDO  PRECIO  TIPO  VUELO\n");
			printf("---------------------------------------\n");
			showPassenger(list, index);
			printf("---------------------------------------\n");
			printf("1. Modificar nombre\n");
			printf("2. Modificar apellido\n");
			printf("3. Modificar precio del vuelo\n");
			printf("4. Modificar el codigo de vuelo\n");
			printf("5. Modificar el tipo de pasajero\n");
			printf("6. Salir\n");
			printf("Ingrese opcion: ");
			scanf("%d", &option);

			switch (option)
			{
			case 1:
				do{
					printf("Ingrese el nombre del pasajero: ");
					fflush(stdin);
					gets(auxString);
					ok=0;
				}while(!validateString(auxString, 2, 51));
				printf("%s\n", auxString);
				strcpy(list->name,auxString);
				break;

			case 2:
				do{
					printf("Ingrese el apellido del pasajero: ");
					fflush(stdin);
					gets(auxString);
					ok=0;
				}while(!validateString(auxString, 1, 51));
				strcpy(list->lastName,auxString);
				break;

			case 3:
				do{
					printf("Ingrese el precio del vuelo: ");
					scanf("%f", &auxFloat);
					ok=0;
				}while(!validateFloat(auxFloat, 0, 9999999));
				list->price = auxFloat;
				break;

			case 4:
				do{
					printf("Ingrese el codigo del vuelo: ");
					fflush(stdin);
					gets(auxString);
					ok=0;
				}while(!validateString(auxString, 0, 10));
				strcpy(list->flycode,auxString);
				break;

			case 5:
				do{
					printf("Ingrese el tipo de pasajero: ");
					scanf("%d", &auxInteger);
					ok=0;
				}while(!validateFloat(auxInteger, 0, 5));
				list->typePassenger = auxInteger;
				break;

			case 6:
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
		printf("va a eliminar el pasajero: \n");
		showPassenger(list, index);

		do{
			printf("\nEsta seguro? (s/n)");
			fflush(stdin);
			input = getchar();
			input = tolower(input);
		}while(!validateChar(input, 's', 'n'));

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

int averagePrice(Passenger* list, int len)
{
	int ok=-1;
	int total;
	float totalPrecios;
	float promedioPrecios;
	int totalPreciosArribaDelPromedio;


	if(list!=NULL && len>0)
	{
		ok=0;
		for (int i=0; i<len; i++)
		{
			if(!list[i].isEmpty)
			{
				total++;
				totalPrecios += list[i].price;
			}
		}

		promedioPrecios = (float) total / totalPrecios;

		for (int i=0; i<len; i++)
		{
			if(!list[i].isEmpty && list[i].price > promedioPrecios)
			{
				totalPreciosArribaDelPromedio++;
			}
		}
		system("cls");
		printf("El total de precios es de %f.2\n", totalPrecios);
		printf("El promedio de precios es de %f.2\n", promedioPrecios);
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
		printf("%d %s %s %.2f %d %s\n",(list+index)->id,
									   (list+index)->name,
									   (list+index)->lastName,
									   (list+index)->price,
									   (list+index)->typePassenger,
									   (list+index)->flycode);
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
		printf("---------------------------------------\n");
		printf("----------------PASAJERO---------------\n");
		printf("---------------------------------------\n");
		printf("ID NOMBRE APELLIDO  PRECIO  TIPO  VUELO\n");
		for(int i=0;i<len;i++)
		{
			showPassenger(list, i);
			printf("---------------------------------------\n");
		}

	}
	return ok;
}

int newOrder()
{
	int order;
	system("cls");
	printf("Desea ordenar ascendente o descendentemente? (1 para asc/0 para desc");
	scanf("%d", &order);
	while(order!=0 && order!=1)
	{
		system("cls");
		printf("Error. Elija nuevamente (1 para asc/0 para desc) ");
        scanf("%d", &order);
	}
	return order;
}
