/*
 * Avion.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Lau
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Aguirre.h"
#include "Marca.h"
#include "Viaje.h"
#include "Fecha.h"
#ifndef AVION_H_
#define AVION_H_

typedef struct{
	int idAvion;
	int matricula;
	eFecha fecha;
	int idViaje;
	int idMarca;
	int modelo;
	int cantAsientos;
	int isEmpty;
}eAvion;
int inicializarAviones(eAvion arrayAviones [], int tam);
void mostrarAvion(eAvion unAvion, eViaje arrayViajes[], int tamV, eMarca arrayMarcas[], int tamM);
int mostrarAviones(eAvion arrayAviones[], int tamA, eViaje arrayViajes[], int tamV, eMarca arrayMarcas[], int tamM);
int avionesLen(eAvion arrayAviones[], int tam);
int buscarLibreAvion(eAvion arrayAviones [], int tam);
int altaAvion(eAvion arrayAviones[], int tamA,eMarca arrayMarcas[], int tamM, eViaje arrayViajes[], int tamV, int* idAvion);
int buscarAvionID(eAvion arrayAviones[], int tam, int id);
int modificarAvion(eAvion arrayAviones[], int tamA, eViaje arrayViajes[], int tamV,eMarca arrayMarcas[], int tamM);
int bajaAvion(eAvion arrayAviones[],int tamA, eViaje arrayViajes[], int tamV, eMarca arrayMarcas[], int tamM);
int buscarAvionMatricula(eAvion arrayAviones[], int tam, int matricula);
int ordenamientoMarcaYMatricula(eAvion arrayAviones[], int tamA, eViaje arrayViajes[], int tamV, eMarca arrayMarcas[], int tamM);

#endif /* AVION_H_ */
