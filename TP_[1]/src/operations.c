/*
 * operations.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include "header.h"

float precioDebito(float precio)
{
	precio = precio*0.9;
	return precio;
}

float precioCredito(float precio)
{
	precio = precio*1.25;
	return precio;
}

float precioBitcoin(float precio)
{
	precio = precio/4606954.55;
	return precio;
}

float precioUnitario(float precio, float kilometros)
{
	precio = precio/kilometros;
	return precio;
}

float diferenciaDePrecios(float precioAerolineas, float precioLatam)
{
	float diferencia;

	diferencia = precioAerolineas - precioLatam;
	if(diferencia<0)
	{
		diferencia=diferencia*-1;
	}
	return diferencia;
}
