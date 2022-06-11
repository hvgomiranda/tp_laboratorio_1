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
    LinkedList* pArrayListPassenger = ll_newLinkedList();
    int* nextId = (int*) malloc(sizeof(int));

    controller_loadFromText("data.csv", pArrayListPassenger);

    controller_listPassenger(pArrayListPassenger);


    *nextId = controller_getNextId(pArrayListPassenger);
    controller_addPassenger(pArrayListPassenger, *nextId);

    controller_listPassenger(pArrayListPassenger);

    controller_editPassenger(pArrayListPassenger);

    controller_listPassenger(pArrayListPassenger);

    ll_deleteLinkedList(pArrayListPassenger);

    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;
        }
    }while(option != 10);*/
    return 0;
}

