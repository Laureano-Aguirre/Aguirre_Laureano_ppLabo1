/*
 * Viaje.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Lau
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Aguirre.h"
#include "Viaje.h"
#include "Avion.h"
#include "Fecha.h"
#include "Marca.h"
#define VACIO 1
#define LLENO 0
void hardcodearViaje (eViaje arrayViajes[], int tam)
{
	int i;

	eViaje viajeLocal[5]={{100,"Salta",1462.5},
			{101,"Tucuman",1247.6},
			{102,"Neuquen",1139.4},
			{103,"Corrientes",670},
			{104,"Chubut", 1735.8}};

	for(i=0;i<tam;i++)
	{
		arrayViajes[i]=viajeLocal[i];
	}
}

void mostrarViaje(eViaje unViaje)
{
	printf("\n id: %d descripcion: %s kilometros: %0.2f", unViaje.idViaje,
			unViaje.descripcion,
			unViaje.kilometros);
}

int mostrarViajes(eViaje arrayViajes[], int tam)
{
	int retorno=-1;
	int i;

	puts("\nListando viajes...");
	for(i=0;i<tam;i++)
	{
		mostrarViaje(arrayViajes[i]);
		retorno=1;
	}
	return retorno;
}

int cargarViaje(eViaje arrayViajes[], int tamV, char descripcion[], int idViaje)
{
	int retorno=-1;
	int i;

	for(i=0;i<tamV;i++)
	{
		if(idViaje==arrayViajes[i].idViaje)
		{
			strcpy(descripcion, arrayViajes[i].descripcion);
			retorno=1;
			break;
		}
	}
	return retorno;
}
