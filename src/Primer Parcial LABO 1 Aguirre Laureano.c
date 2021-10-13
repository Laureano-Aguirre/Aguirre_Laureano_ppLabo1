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
#include "Hardcodear.h"
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

	hardcodearMarca(arrayMarcas, TAMM);
	hardcodearViaje(arrayViajes, TAMV);
	if(hardcodearAviones(arrayAviones, TAMA, &idAvion, 6)>0)
	{
		puts("\nDatos cargados.");
	}



	do
	{
		getInt(" \n  Menu de opciones: "
				"\n 1. Alta avion."
				"\n 2. Modificar avion."
				"\n 3. Baja avion."
				"\n 4. Listar avion."
				"\n 5. Listar viajes."
				"\n 6. Listar marcas."
				"\n 7. Mostrar todos los aviones Boeing."
				"\n 8. Mostrar aviones de una marca seleccionada."
				"\n 9. Mostrar la matricula y marca de los aviones que viajaron a Neuquen."
				"\n 10. Informar los kms totales recorridos por los aviones marca ATR."
				"\n 11. Informar la cantidad total de asientos para un modelo de avión seleccionado."
				"\n 12. Salir."
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
			puts("\nUsted ha elegido la opcion mostrar todos los aviones Boeing.");
			mostrarBoeing(arrayAviones, TAMA, arrayViajes, TAMV, arrayMarcas, TAMM);
			break;
		case 8:
			puts("\nUsted ha elegido la opcion mostrar aviones de una marca seleccionada.");
			mostrarAvionesMarcaSeleccionada(arrayAviones, TAMA, arrayViajes, TAMV, arrayMarcas, TAMM);
			break;
		case 9:
			puts("\nUsted ha elegido la opcion mostrar la matricula y marca de los aviones que viajaron a Neuquen.");
			mostrarMatriculasYMarca(arrayAviones, TAMA, arrayViajes, TAMV, arrayMarcas, TAMM);
			break;
		case 10:
			puts("\nUsted ha elegido la opcion informar los kms totales recorridos por los aviones marca ATR.");
			informarKmsTotalesATR(arrayAviones, TAMA, arrayViajes, TAMV);
			break;
		case 11:
			puts("\nUsted ha elegido la opcion Informar la cantidad total de asientos para un modelo de avión seleccionado.");
			cantidadTotalAsientosAvionSeleccionado(arrayAviones, TAMA, arrayViajes, TAMV, arrayMarcas, TAMM);
			break;
		case 12:
			puts("\nCerrando el programa...");
			puts("\nSALUDOS!!!");
			break;
		}

		if(opcion<1 || opcion>12)
		{
			puts("\n Operacion ingresada incorrecta");
		}
		fflush(stdin);
		getchar();
		system("cls");
	}while(opcion!=12);

	return EXIT_SUCCESS;
}
