/*
 * Hardcodear.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Lau
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Hardcodear.h"
#include "Aguirre.h"
#define VACIO 1
#define LLENO 0

int idMarca[6]={1001,1003,1000,1000,1002,1001};

int idViaje[6]={101,103,104,100,102,101};

int matricula[6]={30,69,50,79,10,19};

int cantidadAsientos[6]={400,350,500,250,150,200};

int modelo[6]={2000,1995,1991,2005,2007,2015};

eFecha fecha[6]={{10,10,2021},
				 {15,11,2021},
				 {5,2,2021},
				 {8,7,2021},
				 {29,5,2021},
				 {17,9,2021}};

int hardcodearAviones(eAvion arrayAviones[], int tam, int* idAvion, int cantidad)
{
	int i;
	int retorno=0;

	if(arrayAviones!= NULL && tam>0 && idAvion!= NULL && cantidad>=0 && cantidad<=tam)
	{
		for(i=0;i<cantidad;i++)
		{
			arrayAviones[i].idAvion=*idAvion;
			(*idAvion)++;
			arrayAviones[i].matricula=matricula[i];
			arrayAviones[i].fecha=fecha[i];
			arrayAviones[i].idMarca=idMarca[i];
			arrayAviones[i].idViaje=idViaje[i];
			arrayAviones[i].cantAsientos=cantidadAsientos[i];
			arrayAviones[i].modelo=modelo[i];
			arrayAviones[i].isEmpty=LLENO;
			retorno++;
		}
	}
	return retorno;
}


