/*
 * Marca.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Lau
 */

#ifndef MARCA_H_
#define MARCA_H_
#include "Aguirre.h"

typedef struct{
	int id;
	char descripcion [20];
}eMarca;

void hardcodearMarca (eMarca arrayMarcas[], int tam);
void mostrarMarca(eMarca unaMarca);
void mostrarMarcas(eMarca arrayMarcas[],int tam);
int cargarMarca(eMarca arrayMarcas[], int tamM, char descripcion[], int idMarca);

#endif /* MARCA_H_ */
