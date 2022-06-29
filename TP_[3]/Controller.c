#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int isOk=-1;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pFile;
		pFile=fopen(path,"r");
		if(pFile!=NULL)
		{
			int loadError = parser_PassengerFromText(pFile,pArrayListPassenger);
			fclose(pFile);
			if(loadError==0)
			{
				puts("\nArchivo cargado con exito.");
				isOk=0;
			}
			else
				puts("\nSe detectaron errores al cargar algunos de los datos del archivo.");
		}
		else
			puts("Error, no se ha encontrado el archivo.");
	}
	else
		puts(ERRORMESSAGE);


    return isOk;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int isOk=-1;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pFile;
		pFile=fopen(path,"rb");
		if(pFile!=NULL)
		{
			int loadError = parser_PassengerFromBinary(pFile,pArrayListPassenger);
			fclose(pFile);
			if(loadError==0)
			{
				puts("\nArchivo cargado con exito.");
				isOk=0;
			}
			else
				puts("\nSe detectaron errores al cargar algunos de los datos del archivo.");
		}
		else
			puts("Error, no se ha encontrado el archivo.");
	}
	else
		puts(ERRORMESSAGE);

    return isOk;
}

int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int isOk=-1;
	if(pArrayListPassenger!=NULL)
	{
		Passenger* newPassenger = Passenger_new();
		if(newPassenger!=NULL)
		{
			system("cls");
			printf("%59s","ALTA DE PASAJEROS");
			puts("\n---------------------------------------------------------------------------------------------------");

			char stringAux[30];

			int errorGetCheck[7];

			errorGetCheck[0] = Passenger_setId(newPassenger,passengerMaxId());
			errorGetCheck[1] = Passenger_setName(newPassenger, stringImput("\nIngrese el Nombre del pasajero: ", stringAux, 1));
			errorGetCheck[2] = Passenger_setLastName(newPassenger, stringImput("\nIngrese el Apellido del pasajero: ", stringAux, 1));
			errorGetCheck[3] = Passenger_setPrice(newPassenger, floatImput("\nIngrese el Precio del Vuelo: ", 1, 10000000));
			errorGetCheck[4] = Passenger_setFlyCode(newPassenger, stringImput("\nIngrese el Codigo de Vuelo: (Formato: AB1234C)", stringAux, 2));
			errorGetCheck[5] = Passenger_setTypePassenger(newPassenger, stringImput("\nIngrese el Tipo de pasajero: (FirstClass, EconomyClass, ExecutiveClass)", stringAux, 3));
			errorGetCheck[6] = Passenger_setStatusFlight(newPassenger, stringImput("\nIngrese el Estado del Vuelo: (En Horario, En vuelo, Demorado, Aterrizado)", stringAux, 4));

			if(!errorGetCheck[0] && !errorGetCheck[1] && !errorGetCheck[2] && !errorGetCheck[3] && !errorGetCheck[4] && !errorGetCheck[5] && !errorGetCheck[6])
			{
				ll_add(pArrayListPassenger,newPassenger);
				puts("\nPasajero agregado con exito.");
				isOk=0;
			}
			else
				puts("Hubo un error al guardar los datos del pasajero.");
		}
		else
			puts(ERRORMESSAGE);
	}
	else
		puts(ERRORMESSAGE);

    return isOk;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int isOk=-1;
	if(pArrayListPassenger!=NULL)
	{
		int index,
			listLen,
			editOption;

		system("cls");
		printf("%65s","MODIFICACION DE PASAJEROS");
		puts("\n---------------------------------------------------------------------------------------------------");
		puts("\nIngrese el indice del pasajero a editar: ");
		scanf("%d",&index);

		listLen = ll_len(pArrayListPassenger);
		while(index>listLen-1)
		{
			puts("\nIndice invalido o no encontrado, reingrese: ");
			scanf("%d",&index);
		}

		Passenger* passengerAux = (Passenger*)ll_get(pArrayListPassenger, index-1);
		if(passengerAux!=NULL)
		{
			unsigned int id;
			char name[50],
			     lastName[50],
				 flyCode[9],
				 statusFlight[12],
				 typePassenger[15],
				 stringAux[30];
			float price;

			int errorGetCheck[7];

			errorGetCheck[0] = Passenger_getId(passengerAux,&id);
			errorGetCheck[1] = Passenger_getName(passengerAux,name);
			errorGetCheck[2] = Passenger_getLastName(passengerAux,lastName);
			errorGetCheck[3] = Passenger_getPrice(passengerAux,&price);
			errorGetCheck[4] = Passenger_getFlyCode(passengerAux,flyCode);
			errorGetCheck[5] = Passenger_getTypePassenger(passengerAux, typePassenger);
			errorGetCheck[6] = Passenger_getStatusFlight(passengerAux,statusFlight);

			if(!errorGetCheck[0] && !errorGetCheck[1] && !errorGetCheck[2] && !errorGetCheck[3] && !errorGetCheck[4] && !errorGetCheck[5] && !errorGetCheck[6])
			{
				puts("\n\nDatos del pasajero a editar:");
				printf("%4s  %13s  %16s  %10s  %11s  %17s  %14s","ID","NAME","LASTNAME","PRICE","FLYCODE","TYPEPASSENGER","STATUSFLIGHT");
				printf("\n%4d  %15s  %15s  %10.2f  %10s  %17s  %13s",id,name,lastName,price,flyCode,typePassenger,statusFlight);

				puts("\n\nIngrese la opcion que quiera modificar: "
					 "\n1.Nombre"
					 "\n2.Apellido"
					 "\n3.Precio"
					 "\n4.Codigo de Vuelo"
					 "\n5.Tipo de pasajero"
					 "\n6.Estado de Vuelo"
					 "\n\n7.Salir");

			    int errorSetCheck=-1;
				editOption=intImput("\n\nOpcion: ",1,7);
				switch(editOption)
				{
					case 1:
						errorSetCheck = Passenger_setName(passengerAux, stringImput("\nIngrese el nuevo Nombre del pasajero: ", stringAux, 1));
						break;

					case 2:
						errorSetCheck = Passenger_setLastName(passengerAux, stringImput("\nIngrese el nuevo Apellido del pasajero: ", stringAux, 1));
						break;

					case 3:
						errorSetCheck = Passenger_setPrice(passengerAux, floatImput("\nIngrese el nuevo Precio del Vuelo: ", 1, 10000000));
						break;

					case 4:
						errorSetCheck = Passenger_setFlyCode(passengerAux, stringImput("\nIngrese el nuevo Codigo de Vuelo: (Formato: AB1234C)", stringAux, 2));
						break;

					case 5:
						errorSetCheck = Passenger_setTypePassenger(passengerAux, stringImput("\nIngrese el nuevo Tipo de pasajero: (FirstClass, EconomyClass, ExecutiveClass)", stringAux, 3));
						break;

					case 6:
						errorSetCheck = Passenger_setStatusFlight(passengerAux, stringImput("\nIngrese el nuevo Estado del Vuelo: (En Horario, En vuelo, Demorado, Aterrizado)", stringAux, 4));
						break;

					case 7:
						puts("\n...");
						isOk=0;
						errorSetCheck=0;
						break;
				}

				if(errorSetCheck==-1)
					puts("Hubo un error al guardar los datos del pasajero.");
				else if(editOption!=7)
				{
					puts("\nSe ha cambiado el elemento con exito.");
					isOk=0;
				}
			}
			else
				puts("Hubo un error al cargar los datos del pasajero.");
		}
		else
			puts(ERRORMESSAGE);
	}
	else
		puts(ERRORMESSAGE);

    return isOk;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int isOk=-1;
	if(pArrayListPassenger!=NULL)
	{
		int index,
			listLen;

		listLen = ll_len(pArrayListPassenger);

		system("cls");
		printf("%58s","ELIMINACION DE PASAJEROS");
		puts("\n-------------------------------------------------------------------------------------------");
		index= intImput("\nIngrese el indice del pasajero a eliminar: ",0,listLen-1);

		Passenger* aux = (Passenger*)ll_get(pArrayListPassenger,index-1);
		Passenger_delete(aux);
		ll_remove(pArrayListPassenger, index-1);
		puts("\nSe ha removido con exito al pasajero.");
		isOk=0;
	}
	else
		puts(ERRORMESSAGE);

    return isOk;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int isOk=0;
	if(pArrayListPassenger!=NULL)
	{
		Passenger* auxPassenger=NULL;
		unsigned int id;
		char name[50],
			 lastName[50],
			 flyCode[9],
			 statusFlight[12],
			 typePassenger[15];
		float price;

		int listLen = ll_len(pArrayListPassenger),
			i;

		system("cls");
		printf("%59s","LISTADO DE PASAJEROS");
		puts("\n---------------------------------------------------------------------------------------------------");
		printf("%4s  %13s  %16s  %10s  %11s  %17s  %14s","ID","NAME","LASTNAME","PRICE","FLYCODE","TYPEPASSENGER","STATUSFLIGHT");
		puts("\n---------------------------------------------------------------------------------------------------");
		for(i=0;i<listLen;i++)
		{
			auxPassenger = (Passenger*)ll_get(pArrayListPassenger,i);
			if(auxPassenger!=NULL)
			{
				int errorGetCheck[7];

				errorGetCheck[0] = Passenger_getId(auxPassenger,&id);
				errorGetCheck[1] = Passenger_getName(auxPassenger,name);
				errorGetCheck[2] = Passenger_getLastName(auxPassenger,lastName);
				errorGetCheck[3] = Passenger_getPrice(auxPassenger,&price);
				errorGetCheck[4] = Passenger_getFlyCode(auxPassenger,flyCode);
				errorGetCheck[5] = Passenger_getTypePassenger(auxPassenger, typePassenger);
				errorGetCheck[6] = Passenger_getStatusFlight(auxPassenger,statusFlight);

				if(!errorGetCheck[0] && !errorGetCheck[1] && !errorGetCheck[2] && !errorGetCheck[3] && !errorGetCheck[4] && !errorGetCheck[5] && !errorGetCheck[6])
					printf("\n%4d  %15s  %15s  %10.2f  %10s  %17s  %13s",id,name,lastName,price,flyCode,typePassenger,statusFlight);
				else
					isOk=-1;
			}
			else
				isOk=-1;
		}
		puts("\n---------------------------------------------------------------------------------------------------");
	}
	else
	{
		puts(ERRORMESSAGE);
		isOk=-1;
	}

    return isOk;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int isOk=-1;
	if(pArrayListPassenger!=NULL)
	{
		int option,
			order;

		system("cls");
		printf("%58s","ORDEN DE PASAJEROS");
		puts("\n-------------------------------------------------------------------------------------------------");

		option= sortMenu();
		puts("Como quiere ordernar la lista? (1 = Orden Ascendente / 0 = Orden Descendente)");
		scanf("%d",&order);
		switch(option)
		{
			case 0:
				ll_sort(pArrayListPassenger,idOrder,order);
				break;

			case 1:
				ll_sort(pArrayListPassenger,nameOrder,order);
				break;

			case 2:
				ll_sort(pArrayListPassenger,lastNameOrder,order);
				break;

			case 3:
				ll_sort(pArrayListPassenger,priceOrder,order);
				break;

			case 4:
				ll_sort(pArrayListPassenger,flyCodeOrder,order);
				break;

			case 5:
				ll_sort(pArrayListPassenger,typePassengerOrder,order);
				break;

			case 6:
				ll_sort(pArrayListPassenger,statusFlightOrder,order);
				break;

			case 7:
				break;
		}
		isOk=0;
	}

    return isOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int isOk=-1,
		saveError=0;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pFile;
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			Passenger* auxPassenger=NULL;
			unsigned int id;
			char name[50],
				 lastName[50],
				 flyCode[9],
				 statusFlight[12],
				 typePassenger[15];
			float price;

			int listLen = ll_len(pArrayListPassenger),
				i;
			fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			for(i=0;i<listLen;i++)
			{
				auxPassenger = (Passenger*)ll_get(pArrayListPassenger,i);
				if(auxPassenger!=NULL)
				{
					int errorGetCheck[7];

					errorGetCheck[0] = Passenger_getId(auxPassenger,&id);
					errorGetCheck[1] = Passenger_getName(auxPassenger,name);
					errorGetCheck[2] = Passenger_getLastName(auxPassenger,lastName);
					errorGetCheck[3] = Passenger_getPrice(auxPassenger,&price);
					errorGetCheck[4] = Passenger_getFlyCode(auxPassenger,flyCode);
					errorGetCheck[5] = Passenger_getTypePassenger(auxPassenger, typePassenger);
					errorGetCheck[6] = Passenger_getStatusFlight(auxPassenger,statusFlight);

					if(!errorGetCheck[0] && !errorGetCheck[1] && !errorGetCheck[2] && !errorGetCheck[3] && !errorGetCheck[4] && !errorGetCheck[5] && !errorGetCheck[6])
					{
						fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",id,name,lastName,price,flyCode,typePassenger,statusFlight);
					}
					else
						saveError=-1;

					//if(!(i==listLen-1))
					//	fprintf(pFile,"\n");
				}
				else
					saveError=-1;
			}
			fclose(pFile);

			if(saveError==0)
			{
				puts("\nArchivo guardado con exito.");
				isOk=0;
			}
			else
				puts("\nSe detectaron errores al guardar algunos de los datos al archivo.");
		}
		else
			puts(ERRORMESSAGE);
	}

    return isOk;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int isOk=-1,
		saveError=0;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pFile;
		pFile=fopen(path,"wb");
		if(pFile!=NULL)
		{
			int listLen = ll_len(pArrayListPassenger),
				i;
			Passenger* auxPassenger=NULL;

			char columnNames[]="id,name,lastname,price,flycode,typePassenger,statusFlight\n";
			fwrite(columnNames, sizeof(columnNames),1,pFile);

			for(i=0;i<listLen;i++)
			{
				auxPassenger = (Passenger*)ll_get(pArrayListPassenger,i);
				if(auxPassenger!=NULL)
					fwrite(auxPassenger, sizeof(Passenger),1,pFile);
				else
					saveError=-1;
			}
			fclose(pFile);
			if(saveError==0)
			{
				puts("\nArchivo guardado con exito.");
				isOk=0;
			}
			else
				puts("\nSe detectaron errores al guardar algunos de los datos al archivo.");
		}
		else
			puts(ERRORMESSAGE);
	}

    return isOk;
}
