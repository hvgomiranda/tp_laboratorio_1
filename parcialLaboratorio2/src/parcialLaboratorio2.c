/*
 ============================================================================
 Name        : parcialLaboratorio2.c
 Author      : Hugo Miranda Campos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"
#include "computer.h"

int main(void)
{
	setbuf(stdout, NULL);

	LinkedList* pArrayListComputer = ll_newLinkedList();

	controller_loadFromText(pArrayListComputer);
	system("pause");
	//ll_sort(pArrayListComputer, computer_compareTipoId, 1);
	controller_listComputer(pArrayListComputer);
}
