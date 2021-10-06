/*
 ============================================================================
 Name        : Primer.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Aguirre.h"
#include "Marca.h"
#include "Viaje.h"
#include "Fecha.h"
#include "Avion.h"
#define TAMM 4
#define TAMV 5
#define TAMA 10

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	eMarca arrayMarcas[TAMM];
	eAvion arrayAviones[TAMA];
	eViaje arrayViajes[TAMV];
	int idAvion=50;

	inicializarAviones(arrayAviones, TAMA);
	//int hardcodearAviones={{}}
	hardcodearMarca(arrayMarcas, TAMM);
	hardcodearViaje(arrayViajes, TAMV);

	do
	{
		getInt(" \n  Menu de opciones: "
				"\n 1. Alta avion."
				"\n 2. Modificar avion."
				"\n 3. Baja avion."
				"\n 4. Listar avion."
				"\n 5. Listar viajes."
				"\n 6. Listar marcas."
				"\n 7. Salir"
				"\n Ingresar la operacion que desea ejecutar: ", &opcion);

		switch(opcion)
		{
		case 1:
			puts("\nUsted ha ingresado la opcion de dar el alta .");
			altaAvion(arrayAviones, TAMA, arrayMarcas, TAMM, arrayViajes, TAMV, &idAvion);
			break;
		case 2:
			puts("\nUsted ha ingresado la opcion de modificar.");
			modificarAvion(arrayAviones, TAMA, arrayViajes, TAMV, arrayMarcas, TAMM);
			break;
		case 3:
			puts("\nUsted ha ingresado la opcion de dar la baja .");
			bajaAvion(arrayAviones, TAMA, arrayViajes, TAMV, arrayMarcas, TAMM);
			break;
		case 4:
			puts("\nUsted ha ingresado la opcion de listar aviones.");
			mostrarAviones(arrayAviones, TAMA, arrayViajes, TAMV, arrayMarcas, TAMM);
			break;
		case 5:
			puts("\nUsted ha ingresado la opcion listar viajes.");
			mostrarViajes(arrayViajes, TAMV);
			break;
		case 6:
			puts("\nUsted ha elegido la opcion listar marcas.");
			mostrarMarcas(arrayMarcas, TAMM);
			break;
		case 7:
			puts("\nCerrando el programa...");
			puts("\nSALUDOS!!!");
			break;
		}

		if(opcion<1 || opcion>7)
		{
			puts("\n Operacion ingresada incorrecta");
		}
		fflush(stdin);
		getchar();
		system("cls");
	}while(opcion!=7);

	return EXIT_SUCCESS;
}
