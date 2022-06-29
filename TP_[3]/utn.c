#include "utn.h"

char* getPath(char* pathAux, int option, char* typeOfFile)
{
	system("cls");
	if(option==1)
		printf("%59s %s","LECTURA DE ARCHIVO", typeOfFile);
	else
		printf("%57s %s","ESCRITURA DE ARCHIVO", typeOfFile);
	puts("\n---------------------------------------------------------------------------------------------------");

	stringImput("\nIngrese la ruta del archivo: ", pathAux, 5);

	return pathAux;
}

int intImput(char* message, int min, int max)
{
	int isNum;
	int num;

	puts(message);
	isNum=scanf("%d",&num);

	while(isNum!=1 || num<min || num>max)
	{
		puts("\nValor invalido, reingrese: ");
		fflush(stdin);
		isNum=scanf("%d",&num);
	}

	return num;
}

float floatImput(char* message, int min, int max)
{
	int isNum;
	float num;

	puts(message);
	isNum=scanf("%f",&num);

	while(isNum!=1 || num<min || num>max)
	{
		puts("\nValor invalido, reingrese: ");
		fflush(stdin);
		isNum=scanf("%f",&num);
	}

	return num;
}

char* stringImput(char* message, char* string, int stringType)
{
	int i,
		j,
		error=1,
		stringSize;

	char codeError[]="Error, Codigo de vuelo invalido. Reingrese: ",
		 fileExtension[6]="";

	puts(message);
	do
	{
		fflush(stdin);
		gets(string);
		while(strcmp(string,"")==0 || strcmp(string," ")==0)
		{
			puts("No es posible ingresar un espacio en blanco. Reingrese: ");
			fflush(stdin);
			gets(string);
		}
		switch(stringType)
		{
			case 1:
				for(i=0;i<strlen(string);i++)
				{
					if(isdigit(string[i])==1)
					{
						puts("\nError, Nombre/Apellido invalido. Reingrese: ");
						break;
					}
				}

				if(i==strlen(string))
				{
					string[0]=toupper(string[0]);
					for(i=1;i<strlen(string);i++)
					{
						string[i]=tolower(string[i]);
					}
					error=0;
				}
				break;

			case 2:
				for(i=0;i<strlen(string);i++)
				{
					if((i==0 || i==1 || i==6) && isdigit(string[i])==1)
					{
						puts(codeError);
						break;
					}
					else if(i>1 && i<6 && isdigit(string[i])==0)
					{
						puts(codeError);
						break;
					}
				}

				if(i==strlen(string))
				{
					string[0]=toupper(string[0]);
					string[1]=toupper(string[1]);
					string[6]=toupper(string[6]);
					error=0;
				}
				break;

			case 3:
				error = validateString(string, "FirstClass", "firstclass", "FIRSTCLASS", 5);
				if(error==1)
				{
					error = validateString(string,"ExecutiveClass", "executiveclass", "EXECUTIVECLASS", 9);
					if(error==1)
					{
						error = validateString(string, "EconomyClass", "economyclass", "ECONOMYCLASS", 7);
						if(error==1)
							puts("\nError, Tipo de pasajero invalido. Reingrese: ");
					}
				}
				break;

			case 4:
				error = validateString(string, "Aterrizado", "aterrizado", "ATERRIZADO", 0);
				if(error==1)
				{
					error = validateString(string,"En Horario", "en horario", "EN HORARIO", 3);
					if(error==1)
					{
						error = validateString(string, "En Vuelo", "en vuelo", "EN VUELO", 3);
						if(error==1)
						{
							error = validateString(string, "Demorado", "demorado", "DEMORADO", 0);
							if(error==1)
								puts("\nError, Estado de Vuelo invalido. Reingrese: ");
						}
					}
				}
				break;

			case 5:
				j=3;
				stringSize = strlen(string);
				for(i=stringSize-1;i>stringSize-5;i--)
				{
					fileExtension[j]=string[i];
					j--;
				}
				if(strcmp(fileExtension, ".bin")==0 || strcmp(fileExtension, ".csv")==0 || strcmp(fileExtension, ".dat")==0 || strcmp(fileExtension, ".txt")==0)
					error=0;
				else
					puts("\nError, formato de archivo invalido. Reingrese: ");
				break;
		}
	}while(error);

	return string;
}

int validateString(char* stringToValidate, char* string1, char* string2, char* string3, int index)
{
	int i,
		error=1;
	if(strcmp(string1,stringToValidate)==0 || strcmp(string2,stringToValidate)==0 || strcmp(string3,stringToValidate)==0)
	{
		stringToValidate[0]=toupper(stringToValidate[0]);
		stringToValidate[index]=toupper(stringToValidate[index]);
		for(i=1;i<strlen(stringToValidate);i++)
		{
			if(i!=index)
			{
				stringToValidate[i]=tolower(stringToValidate[i]);
			}
		}
		error=0;
	}

	return error;
}

unsigned int passengerMaxId(void)
{
	char maxIdAux[10];
	unsigned int maxIdExcel=1000,
				 newMaxId;

	FILE* pFileId;
	if((pFileId=fopen("./MaxID.txt","r"))==NULL)
	{
		pFileId=fopen("./MaxID.txt","w");
		newMaxId=maxIdExcel+1;
	}
	else
	{
		fscanf(pFileId,"%[^\n]", maxIdAux);
		newMaxId=atoi(maxIdAux);
		newMaxId++;
	}
	fclose(pFileId);

	pFileId=fopen("./MaxID.txt","w");
	fprintf(pFileId,"%d\n",newMaxId);
	fclose(pFileId);

	return (newMaxId);
}


int idOrder(void* element1, void* element2)
{
	int isOk=-1;
	if(element1!=NULL && element2!=NULL)
	{
		unsigned int id1,
					 id2;

		Passenger_getId((Passenger*)element1,&id1);
		Passenger_getId((Passenger*)element2,&id2);

		if(id1>id2)
			isOk=1;
	}
	return isOk;
}

int nameOrder(void* element1, void* element2)
{
	int isOk=0;
	if(element1!=NULL && element2!=NULL)
	{
		char name1[50],
			 name2[50];

		Passenger_getName((Passenger*)element1,name1);
		Passenger_getName((Passenger*)element2,name2);

		isOk=strcmp(name1,name2);
	}
	return isOk;
}

int lastNameOrder(void* element1, void* element2)
{
	int isOk=0;
	if(element1!=NULL && element2!=NULL)
	{
		char lastName1[50],
			 lastName2[50];

		Passenger_getLastName((Passenger*)element1,lastName1);
		Passenger_getLastName((Passenger*)element2,lastName2);

		isOk=strcmp(lastName1,lastName2);
	}
	return isOk;
}

int priceOrder(void* element1, void* element2)
{
	int isOk=-1;
	if(element1!=NULL && element2!=NULL)
	{
		float price1,
			  price2;

		Passenger_getPrice((Passenger*)element1,&price1);
		Passenger_getPrice((Passenger*)element2,&price2);

		if(price1>price2)
			isOk=1;
		else if(price1==price2)
			isOk=0;
	}
	return isOk;
}

int flyCodeOrder(void* element1, void* element2)
{
	int isOk=0;
	if(element1!=NULL && element2!=NULL)
	{
		char flyCode1[9],
			 flyCode2[9];

		Passenger_getFlyCode((Passenger*)element1,flyCode1);
		Passenger_getFlyCode((Passenger*)element2,flyCode2);

		isOk=strcmp(flyCode1,flyCode2);
	}
	return isOk;
}

int typePassengerOrder(void* element1, void* element2)
{
	int isOk=0;
	if(element1!=NULL && element2!=NULL)
	{
		char typePassenger1[15],
			 typePassenger2[15];

		Passenger_getTypePassenger((Passenger*)element1,typePassenger1);
		Passenger_getTypePassenger((Passenger*)element2,typePassenger2);

		isOk=strcmp(typePassenger1,typePassenger2);
	}
	return isOk;
}

int statusFlightOrder(void* element1, void* element2)
{
	int isOk=0;
	if(element1!=NULL && element2!=NULL)
	{
		char statusFlight1[12],
			 statusFlight2[12];

		Passenger_getStatusFlight((Passenger*)element1,statusFlight1);
		Passenger_getStatusFlight((Passenger*)element2,statusFlight2);

		isOk=strcmp(statusFlight1,statusFlight2);
	}
	return isOk;
}

int optionMenu(void)
{
	int option;

	system("cls");
	puts( "---LISTA DE PASAJEROS----------------------------------------------------------------------------"
			"\n\n1. Cargar datos del archivo -data.csv- (modo texto)"
			"\n2. Cargar datos del archivo -data.csv- (modo binario)"
		    "\n3. Alta de Pasajero"
		    "\n4. Modificar datos de un Pasajero"
			"\n5. Baja de Pasajero"
			"\n6. Listado"
			"\n7. Ordenar Pasajeros"
			"\n8. Guardar los datos en el archivo -data.csv- (modo texto)"
			"\n9. Guardar los datos en el archivo -data.csv- (modo binario)"
			"\n\n10. Salir"
			"\n-------------------------------------------------------------------------------------------------");

	option=intImput("\n\nOpcion: ", 1, 10);

	return option;
}

int sortMenu(void)
{
	int option;
	puts( 	"Ingrese el criterio por el cual quiere ordenar la lista: "
			"\n\n0. ID"
			"\n1. NOMBRE"
		    "\n2. APELLIDO"
		    "\n3. PRECIO"
			"\n4. CODIGO DE VUELO"
			"\n5. TIPO DE PASAJERO"
			"\n6. ESTADO DE VUELO"
			"\n\n7. Salir"
			"\n-------------------------------------------------------------------------------------------------");

	option=intImput("\n\nOpcion: ", 0, 7);

	return option;
}

int exitMenu(int binSaveFlag, int txtSaveFlag)
{
	int option=11,
		stay=1;
	char answer[3];

	if(!binSaveFlag && !txtSaveFlag)
		puts("\n\nTodavia no se han guardado los datos en ningun archivo. Si realizo algun cambio, lo perdera al salir.");
	else if(binSaveFlag && !txtSaveFlag)
		puts("\n\nTodavia no se han guardado los datos en el archivo de texto.");
	else if(!binSaveFlag && txtSaveFlag)
		puts("\n\nTodavia no se han guardado los datos en el archivo binario.");

	puts ("Esta seguro que desea salir?");
	fflush(stdin);
	gets(answer);
	if(toupper(answer[0])=='S' && toupper(answer[1])=='I')
	{
		stay=0;
		option=10;
	}

	if(stay==0)
	{
		exitMessage();
	}
	return option;
}

void exitMessage(void)
{
	system("cls");
	printf("Adios!");
	system("pause");
}
