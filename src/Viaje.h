/*
 * Viaje.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Lau
 */

#ifndef VIAJE_H_
#define VIAJE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Aguirre.h"

typedef struct{
	int idViaje; //comienza en 100
	char descripcion[25];
	float kilometros;
}eViaje;

void hardcodearViaje (eViaje arrayViajes[], int tam);
void mostrarViaje(eViaje unViaje);
int mostrarViajes(eViaje arrayViajes[], int tam);
int cargarViaje(eViaje arrayViajes[], int tamV, char descripcion[], int idViaje);


#endif /* VIAJE_H_ */
