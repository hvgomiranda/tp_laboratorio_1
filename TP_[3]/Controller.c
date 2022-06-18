#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
	int isOk = 0;
	int* id = (int*) malloc(sizeof(int));
	int* index = (int*) malloc(sizeof(int));
	Passenger* aPassenger;

	if(pArrayListPassenger!=NULL && id!=NULL && index!=NULL)
	{
		isOk=1;
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
				Passenger_printOne(aPassenger);
				printf("\n\n");
				if(ask("Eliminar al pasajero?"))
				{
					ll_remove(pArrayListPassenger, *index);
					Passenger_delete(aPassenger);
					printf("Baja realizada\n");
					system("pause");
					system("cls");
				}
				else
				{
					printf("Baja cancelada\n");
					system("pause");
					system("cls");
				}
			}
		}
	}

	free(id);
	free(index);

	return isOk;
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
	int isOk = 0;
	int* option = (int*) malloc(sizeof(int));
	*option = 0;

	if(pArrayListPassenger!=NULL && option!=NULL)
	{
		isOk=1;
		while(*option != 9)
		{
			printf("Ordenar pasajeros\n\n");
			printf("1. ID ascendente\n");
			printf("2. ID descendente\n");
			printf("3. NOMBRE ascendente\n");
			printf("4. NOMBRE descendente\n");
			printf("5. APELLIDO ascendente\n");
			printf("6. APELLIDO descendente\n");
			printf("7. PRECIO ascendente\n");
			printf("8. PRECIO descendente\n");
			printf("9. CODIGO DE VUELO ascendente\n");
			printf("10. CODIGO DE VUELO descendente\n");
			printf("11. TIPO DE PASAJERO ascendente\n");
			printf("12. TIPO DE PASAJERO descendente\n");
			printf("13. ESTADO DE VUELO ascendente\n");
			printf("14. ESTADO DE VUELO descendente\n");
			printf("15. SALIR\n\n");
			printf("Elija una opcion: ");
			fflush(stdin);
			scanf("%d", option);

			switch(*option)
			{
			case 1:

				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				break;
			case 14:
				break;
			case 15:
				break;
			default:
				break;
			}
		}


	}

	return isOk;

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

		for(int i=0; i<*size; i++)
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

int controller_compareIds(void* first, void* second)
{
	int idCompared;
	int result;
	int* firstId = (int*) malloc(sizeof(int));
	int* secondId = (int*) malloc(sizeof(int));
	Passenger* firstPassenger;
	Passenger* secondPassenger;

	if(first!=NULL && second!=NULL && firstId!=NULL && secondId!=NULL)
	{
		firstPassenger = (Passenger*) first;
		secondPassenger = (Passenger*) second;

		if(Passenger_getId(firstPassenger, firstId) && Passenger_getId(secondPassenger, secondId))
		{
			idCompared = *firstId - *secondId;
		}
		if(idCompared==0)
		{
			result = 0;
		}
		else if(idCompared>0)
		{
			result = 1;
		}
		else if(idCompared<0)
		{
			result = -1;
		}
	}

	free(firstId);
	free(secondId);

	return result;
}

int controller_compareNames(void* first, void* second)
{
	int nameCompared;
	int result;
	char* firstName = (char*) malloc(sizeof(char)*51);
	char* secondName = (char*) malloc(sizeof(char)*51);
	Passenger* firstPassenger;
	Passenger* secondPassenger;

	if(first!=NULL && second!=NULL && firstName!=NULL && secondName!=NULL)
	{
		firstPassenger = (Passenger*) first;
		secondPassenger = (Passenger*) second;

		if(Passenger_getName(firstPassenger, firstName) && Passenger_getName(secondPassenger, secondName))
		{
			nameCompared = strcmp(firstName, secondName);
		}
		if(nameCompared==0)
		{
			result = 0;
		}
		else if(nameCompared>0)
		{
			result = 1;
		}
		else if(nameCompared<0)
		{
			result = -1;
		}
	}

	free(firstName);
	free(secondName);

	return result;
}

int controller_compareLastNames(void* first, void* second)
{
	int lastNameCompared;
	int result;
	char* firstLastName = (char*) malloc(sizeof(char)*51);
	char* secondLastName = (char*) malloc(sizeof(char)*51);
	Passenger* firstPassenger;
	Passenger* secondPassenger;

	if(first!=NULL && second!=NULL && firstLastName!=NULL && secondLastName!=NULL)
	{
		firstPassenger = (Passenger*) first;
		secondPassenger = (Passenger*) second;

		if(Passenger_getName(firstPassenger, firstLastName) && Passenger_getName(secondPassenger, secondLastName))
		{
			lastNameCompared = strcmp(firstLastName, secondLastName);
		}
		if(lastNameCompared==0)
		{
			result = 0;
		}
		else if(lastNameCompared>0)
		{
			result = 1;
		}
		else if(lastNameCompared<0)
		{
			result = -1;
		}
	}

	free(firstLastName);
	free(secondLastName);

	return result;
}

int controller_comparePrices(void* first, void* second)
{
	int priceCompared;
	int result;
	float* firstPrice = (float*) malloc(sizeof(float));
	float* secondPrice = (float*) malloc(sizeof(float));
	Passenger* firstPassenger;
	Passenger* secondPassenger;

	if(first!=NULL && second!=NULL && firstPrice!=NULL && secondPrice!=NULL)
	{
		firstPassenger = (Passenger*) first;
		secondPassenger = (Passenger*) second;

		if(Passenger_getPrice(firstPassenger, firstPrice) && Passenger_getPrice(secondPassenger, secondPrice))
		{
			priceCompared = *firstPrice - *secondPrice;
		}
		if(priceCompared==0)
		{
			result = 0;
		}
		else if(priceCompared>0)
		{
			result = 1;
		}
		else if(priceCompared<0)
		{
			result = -1;
		}
	}

	free(firstPrice);
	free(secondPrice);

	return result;
}
