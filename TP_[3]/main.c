#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Parser.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

	int* option = (int*) malloc(sizeof(int));
	int* fail = (int*) malloc(sizeof(int));
	int* nextId = (int*) malloc(sizeof(int));
    LinkedList* pArrayListPassenger = ll_newLinkedList();

    if(nextId!=NULL && pArrayListPassenger!=NULL)
    {
    	do
    	{
    		system("cls");
			printf("*** Menu de Opciones ***\n\n");
			printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
			printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
			printf("3. Alta de empleado\n");
			printf("4. Modificar datos de empleado\n");
			printf("5. Baja de empleado\n");
			printf("6. Listar empleados\n");
			printf("7. Ordenar empleados\n");
			printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
			printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
			printf("10. Finalizar programa\n\n");
			printf("Elija una opcion: ");
			scanf("%d", option);

			switch(*option)
			{
				case 1:
					if(ll_isEmpty(pArrayListPassenger) || ask("Ya hay empleados cargados, desea sobreescribirlos?"))
					{
						if(!controller_loadFromText("data.csv", pArrayListPassenger))
						{
							system("cls");
							printf("Hubo un error\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("Datos cargados exitosamente\n");
							system("pause");
						}
					}
					break;

				case 2:
					if(ll_isEmpty(pArrayListPassenger) || ask("Ya hay empleados cargados, desea sobreescribirlos?"))
					{
						if(!controller_loadFromBinary("data.bin", pArrayListPassenger))
						{
							system("cls");
							printf("Hubo un error\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("Datos cargados exitosamente\n");
							system("pause");
						}
					}
					break;

				case 3:
					*nextId = controller_getNextId(pArrayListPassenger) + 1;

					if(!controller_addPassenger(pArrayListPassenger, *nextId))
					{
						system("cls");
						printf("Hubo un error\n");
						system("pause");
					}
					else
					{
						system("cls");
						printf("Alta exitosa\n");
						system("pause");
					}
					break;

				case 4:
					if(!ll_isEmpty(pArrayListPassenger))
					{
						if(!controller_editPassenger(pArrayListPassenger))
						{
							system("cls");
							printf("Hubo un error\n");
							system("pause");
						}
					}
					else
					{
						system("cls");
						printf("No hay empleados cargados\n");
						system("pause");
					}
					break;

				case 5:
					if(!ll_isEmpty(pArrayListPassenger))
					{
						if(!controller_removePassenger(pArrayListPassenger))
						{
							system("cls");
							printf("Hubo un error\n");
							system("pause");
						}
					}
					else
					{
						system("cls");
						printf("No hay empleados cargados\n");
						system("pause");
					}
					break;
				case 6:
					if(!ll_isEmpty(pArrayListPassenger))
					{
						controller_listPassenger(pArrayListPassenger);
					}
					else
					{
						system("cls");
						printf("No hay empleados cargados\n");
						system("pause");
					}
					break;
				case 7:
					if(!ll_isEmpty(pArrayListPassenger))
					{
						controller_sortPassenger(pArrayListPassenger);
					}
					else
					{
						system("cls");
						printf("No hay empleados cargados\n");
						system("pause");
					}
					break;
				case 8:
					if(!ll_isEmpty(pArrayListPassenger))
					{
						if(!controller_saveAsText("data.csv", pArrayListPassenger))
						{
							system("cls");
							printf("Hubo un error\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("Los datos se guardaron exitosamente\n");
							system("pause");
						}
					}
					else
					{
						system("cls");
						printf("No hay empleados cargados\n");
						system("pause");
					}

					break;
				case 9:
					if(!ll_isEmpty(pArrayListPassenger))
					{
						if(!controller_saveAsBinary("data.bin", pArrayListPassenger))
						{
							system("cls");
							printf("Hubo un error\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("Los datos se guardaron exitosamente\n");
							system("pause");
						}
					}
					else
					{
						system("cls");
						printf("No hay empleados cargados\n");
						system("pause");
					}

					break;
				case 10:
					system("cls");
					printf("Saliendo\n\n");
					system("pause");
					break;
				default:
					system("cls");
					printf("Opcion invalida\n");
					system("pause");
					break;
			}
    	}while(*option != 10);
    }
    else
    {
    	printf("No se pudo inicializar el programa.");
    }

    free(option);
    free(fail);
    free(nextId);

    return 0;
}

