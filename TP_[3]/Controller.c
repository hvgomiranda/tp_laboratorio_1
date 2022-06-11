#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Parser.h"
#include "utn.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int isOk = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		isOk = 1;

		FILE* pFile = fopen(path, "r");

		parser_PassengerFromText(pFile, pArrayListPassenger);

		fclose(pFile);
	}


    return isOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

int controller_addPassenger(LinkedList* pArrayListPassenger, int nextId)
{
	Passenger* aPassenger = Passenger_new();

	int* id = (int*) malloc(sizeof(int));
	int isOk = 0;
	char* name = (char*) malloc(sizeof(char)*51);
	char* lastName = (char*) malloc(sizeof(char)*51);
	float* price = (float*) malloc(sizeof(float));
	char* flycode = (char*) malloc(sizeof(char)*8);
	char* typePassenger = (char*) malloc(sizeof(char)*21);
	char* statusFlight = (char*) malloc(sizeof(char)*21);

	if(pArrayListPassenger!=NULL && name!=NULL && lastName!=NULL && price!=NULL && flycode!=NULL && typePassenger!=NULL && statusFlight!=NULL)
	{
		isOk = 1;

		if(!Passenger_setId(aPassenger, nextId))
		{
			printf("Hubo un error al cargar el ID\n");
			isOk = 0;
		}
		else if(!utn_getString(name, "Ingrese el nombre del pasajero: ", 2, 50))
		{
			printf("Hubo un problema al obtener el nombre\n");
			isOk = 0;
		}
		else if(!utn_getString(lastName, "Ingrese el apellido del pasajero: ", 2, 50))
		{
			printf("Hubo un problema al obtener el apellido\n");
			isOk = 0;
		}
		else if(!utn_getFloat(price, "Ingrese el precio del vuelo: ", 0, 1000000))
		{
			printf("Hubo un problema al obtener el precio\n");
			isOk = 0;
		}
		else if(!utn_getString(flycode, "Ingrese el codigo de vuelo: ", 6, 8))
		{
			printf("Hubo un problema al obtener el codigo de vuelo\n");
			isOk = 0;
		}
		else if(!utn_getString(typePassenger, "Ingrese el tipo de pasajero: ", 2, 20))
		{
			printf("Hubo un problema al obtener el tipo de pasajero\n");
			isOk = 0;
		}
		else if(!utn_getString(statusFlight, "Ingrese el estado de vuelo: ", 2, 20))
		{
			printf("Hubo un problema al obtener el estado de vuelo\n");
			isOk = 0;
		}
		if(isOk == 1)
		{
			if(Passenger_setName(aPassenger, name)&&
			   Passenger_setLastName(aPassenger, lastName)&&
			   Passenger_setPrice(aPassenger, *price)&&
			   Passenger_setFlycode(aPassenger, flycode)&&
			   Passenger_setTypePassenger(aPassenger, typePassenger)&&
			   Passenger_setStatusFlight(aPassenger, statusFlight))
			{
				ll_add(pArrayListPassenger, aPassenger);
				printf("El empleado se ha agregado: \n");
				Passenger_printOne(aPassenger);
				id++;
			}
		}
	}

	free(name);
	free(lastName);
	free(price);
	free(flycode);
	free(typePassenger);
	free(statusFlight);

    return isOk;
}


int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int isOk = 0;
	int* id = (int*) malloc(sizeof(int));
	int* index = (int*) malloc(sizeof(int));
	char* name = (char*) malloc(sizeof(char)*51);
	char* lastName = (char*) malloc(sizeof(char)*51);
	float* price = (float*) malloc(sizeof(float));
	char* flycode = (char*) malloc(sizeof(char)*8);
	char* typePassenger = (char*) malloc(sizeof(char)*21);
	char* statusFlight = (char*) malloc(sizeof(char)*21);
	int* option = (int*) malloc(sizeof(int));
	int* go = (int*) malloc(sizeof(int));
	*go = 0;
	Passenger* aPassenger = Passenger_new();

	if(pArrayListPassenger!=NULL && name!=NULL && lastName!=NULL && price!=NULL && flycode!=NULL && typePassenger!=NULL && statusFlight!=NULL)
	{
		isOk = 1;
		controller_listPassenger(pArrayListPassenger);
		utn_getInteger(id, "Ingrese el id: ", 1, 999999);
		*index = controller_findPassengerById(pArrayListPassenger, *id);

		while(*index==0)
		{
			utn_getInteger(id, "Ingrese el id: ", 1, 999999);
			*index = controller_findPassengerById(pArrayListPassenger, *id);
		}

		if(*index > 0)
		{
			aPassenger = ll_get(pArrayListPassenger, *index);
			if(aPassenger==NULL)
			{
				isOk = 0;
			}
			else
			{
				*go = 1;
			}

			while(isOk && go)
			{
				system("cls");
				Passenger_printOne(aPassenger);
				printf("\n");
				printf("Editar pasajero\n\n");
				printf("1. Modificar nombre\n");
				printf("2. Modificar apellido\n");
				printf("3. Modificar precio\n");
				printf("4. Modificar codigo de vuelo\n");
				printf("5. Modificar tipo de pasajero\n");
				printf("6. Modificar estado de vuelo\n");
				printf("7. Salir\n\n");
				printf("Ingrese la opcion: ");
				scanf("%d", option);

				switch(*option)
				{
				case 1:
					utn_getString(name, "Ingresa el nombre: ", 2, 51);
					if(Passenger_setName(aPassenger, name))
					{
						system("cls");
						printf("Modificacion realizada\n");
						system("pause");
					}
					break;

				case 2:
					utn_getString(lastName, "Ingresa el apellido: ", 2, 51);
					if(Passenger_setLastName(aPassenger, lastName))
					{
						system("cls");
						printf("Modificacion realizada\n");
						system("pause");
					}
					break;

				case 3:
					if(utn_getFloat(price, "Ingresa el precio: ", 0, 99999999))
					{
						if(Passenger_setPrice(aPassenger, *price))
						{
							system("cls");
							printf("Modificacion realizada\n");
							system("pause");
						}
					}
					break;

				case 4:
					utn_getString(flycode, "Ingresa el el codigo de vuelo: ", 6, 8);
					if(Passenger_setFlycode(aPassenger, flycode))
					{
						system("cls");
						printf("Modificacion realizada\n");
						system("pause");
					}
					break;

				case 5:
					utn_getString(typePassenger, "Ingresa el el tipo de pasajero: ", 2, 21);
					if(Passenger_setTypePassenger(aPassenger, typePassenger))
					{
						system("cls");
						printf("Modificacion realizada\n");
						system("pause");
					}
					break;

				case 6:
					utn_getString(statusFlight, "Ingresa el el estado de vuelo: ", 2, 21);
					if(Passenger_setStatusFlight(aPassenger, statusFlight))
					{
						system("cls");
						printf("Modificacion realizada\n");
						system("pause");
					}
					break;

				case 7:
					*go = 0;
					break;
				default:
					printf("Opcion Invalida\n");
					system("pause");
					system("cls");
					break;
				}
			}
		}
	}

	free(id);
	free(index);
	free(name);
	free(lastName);
	free(price);
	free(flycode);
	free(typePassenger);
	free(statusFlight);
	free(option);

    return isOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{

    return 1;
}


int controller_listPassenger(LinkedList* pArrayListPassenger)
{
    Passenger* aPassenger;
    int isOk = 0;
    int size;
    size = ll_len(pArrayListPassenger);

    if(pArrayListPassenger != NULL)
    {
    	isOk = 1;
		for(int i=0; i< size; i++)
		{
			aPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_printOne(aPassenger);
		}
    }


    return isOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

int controller_findPassengerById(LinkedList* pArrayListPassenger, int id)
{
	int index = 0;
	int* size = (int*) malloc(sizeof(int));
	int* idAux = (int*) malloc(sizeof(int));
	int* error = (int*) malloc(sizeof(int));

	*error = 1;
	Passenger* aPassenger;

	if(pArrayListPassenger!=NULL && size!=NULL && idAux!=NULL && error!=NULL && id>0)
	{
		*size = ll_len(pArrayListPassenger);

		for(int i = 0; i < *size; i++)
		{
			aPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

			if(aPassenger != NULL)
			{
				*error = Passenger_getId(aPassenger, idAux);

				if(!(*error) && *idAux == id)
				{
					index = i;
					break;
				}
			}
		}
	}
	free(size);
	free(idAux);
	free(error);

    return index;
}

int controller_getNextId(LinkedList* pArrayListPassenger)
{
	int nextId = 0;
	int* size = (int*) malloc(sizeof(int));
	int* idAux = (int*) malloc(sizeof(int));
	int* isOK = (int*) malloc(sizeof(int));
	int* index = (int*) malloc(sizeof(int));


	Passenger* aPassenger;

	if(pArrayListPassenger!=NULL && size!=NULL && idAux!=NULL && isOK!=NULL && index!=NULL)
	{
		*isOK = 1;
		*size = ll_len(pArrayListPassenger);

		for(int i = 0; i < *size; i++)
		{
			aPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

			if(aPassenger != NULL)
			{
				*isOK = Passenger_getId(aPassenger, idAux);

				if(*isOK)
				{
					if(*idAux > nextId)
					{
						nextId = *idAux;
					}
				}
			}
		}
	}
	free(size);
	free(idAux);
	free(isOK);
	free(index);

    return nextId;
}
