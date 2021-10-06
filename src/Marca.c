/*
 * Marca.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Lau
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Marca.h"
#include "Avion.h"
#include "Viaje.h"
#include "Aguirre.h"
#define VACIO 1
#define LLENO 0

void hardcodearMarca (eMarca arrayMarcas[], int tam)
{
	int i;
	eMarca marcaLocal[4]={{1000,"Boeing"},
						  {1001,"Airbus"},
						  {1002,"ATR"},
						  {1003,"Bombardier"}};

	for(i=0;i<tam;i++)
	{
		arrayMarcas[i]=marcaLocal[i];
	}
}

void mostrarMarca(eMarca unaMarca)
{
	printf("\n id: %d descripcion: %s ", unaMarca.id,
										 unaMarca.descripcion);
}

void mostrarMarcas(eMarca arrayMarcas[],int tam)
{
	int i;

	puts("\nListando marcas...");
	for(i=0;i<tam;i++)
	{
		mostrarMarca(arrayMarcas[i]);
	}
}

int cargarMarca(eMarca arrayMarcas[], int tamM, char descripcion[], int idMarca)
{
	int retorno=-1;
	int i;

	for(i=0;i<tamM;i++)
	{
		if(idMarca==arrayMarcas[i].id)
		{
			strcpy(descripcion, arrayMarcas[i].descripcion);
			retorno=1;
			break;
		}
	}

	return retorno;
}
