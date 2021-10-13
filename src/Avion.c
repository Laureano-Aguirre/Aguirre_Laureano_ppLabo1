/*
 * Avion.c
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
#include "Avion.h"
#define VACIO 1
#define LLENO 0

int inicializarAviones(eAvion arrayAviones [], int tam) //ok
{
	int retorno=0;
	int i;

	for(i=0;i<tam;i++)
	{
		arrayAviones[i].isEmpty=VACIO;
		retorno=1;
	}
	return retorno;
}

void mostrarAvion(eAvion unAvion, eViaje arrayViajes[], int tamV, eMarca arrayMarcas[], int tamM)
{
	int retornoV;
	int retornoM;
	char descripcionViaje[25];
	char descripcionMarca[20];

	retornoM=cargarMarca(arrayMarcas, tamM, descripcionMarca, unAvion.idMarca);
	retornoV=cargarViaje(arrayViajes, tamV, descripcionViaje, unAvion.idViaje);
	if(retornoM!=-1 && retornoV!=-1)
	{

		printf("\n id: %d matricula: %d fecha: %d/%d/%d viaje: %s marca: %s modelo: %d cant. asientos: %d ", unAvion.idAvion,
																											   unAvion.matricula,
																											   unAvion.fecha.dia,
																											   unAvion.fecha.mes,
																											   unAvion.fecha.anio,
																											   descripcionViaje,
																											   descripcionMarca,
																											   unAvion.modelo,
																											   unAvion.cantAsientos);
	}
}

int avionesLen(eAvion arrayAviones[], int tam)
{
	int retorno=0;
	int i;

	for(i=0;i<tam;i++)
	{
		if(arrayAviones[i].isEmpty==LLENO)
		{
			retorno++;
		}
	}
	return retorno;
}

int mostrarAviones(eAvion arrayAviones[], int tamA, eViaje arrayViajes[], int tamV, eMarca arrayMarcas[], int tamM)
{
	int retorno=-1;
	int i;
	int len;

	ordenamientoMarcaYMatricula(arrayAviones, tamA, arrayViajes, tamV, arrayMarcas, tamM);
	len=avionesLen(arrayAviones, tamA);
	if(len>0)
	{
		puts("\nListando aviones...");
		for(i=0;i<tamA;i++)
		{
			if(arrayAviones[i].isEmpty==LLENO)
			{
				mostrarAvion(arrayAviones[i], arrayViajes, tamV, arrayMarcas, tamM);
				retorno=1;
			}
		}
	}
	else
	{
		puts("\nNo hay aviones cargados para mostrar.");
	}

	return retorno;
}

int buscarLibreAvion(eAvion arrayAviones [], int tam)
{
	int retorno=-1;
	int i;

	for(i=0;i<tam;i++)
	{
		if(arrayAviones[i].isEmpty==VACIO)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

int altaAvion(eAvion arrayAviones[], int tamA,eMarca arrayMarcas[], int tamM, eViaje arrayViajes[], int tamV, int* idAvion)
{
	int retorno=-1;
	int pos;

	pos=buscarLibreAvion(arrayAviones, tamA);
	if(pos!=-1)
	{
		puts("\nLugar libre encontrado.");
		getInt("\nIngrese la matricula del avion: ", &arrayAviones[pos].matricula);
		getInt("\nIngrese el dia del viaje: ", &arrayAviones[pos].fecha.dia);
		while(arrayAviones[pos].fecha.dia>31 || arrayAviones[pos].fecha.dia<1)
		{
			getInt("\nError, ingrese el dia del viaje: ", &arrayAviones[pos].fecha.dia); //validamos la fehca

		}
		getInt("\nIngrese el mes del viaje: ", &arrayAviones[pos].fecha.mes);
		while(arrayAviones[pos].fecha.mes>12 || arrayAviones[pos].fecha.mes<1)
		{
			getInt("\nError, ingrese el mes del viaje: ", &arrayAviones[pos].fecha.mes); //validamos el mes
		}
		getInt("\nIngrese el anio del viaje: ", &arrayAviones[pos].fecha.anio);
		while(arrayAviones[pos].fecha.anio>2022 || arrayAviones[pos].fecha.anio<2021)
		{
			getInt("\nError, ingrese el anio del viaje: ", &arrayAviones[pos].fecha.anio); //validamos el anio, solo en 2021
		}
		mostrarViajes(arrayViajes, tamV);
		getInt("\nIngrese el ID del viaje: ", &arrayAviones[pos].idViaje);
		mostrarMarcas(arrayMarcas, tamM);
		getInt("\nIngrese el ID de la marca del avion: ", &arrayAviones[pos].idMarca);
		while(arrayAviones[pos].idMarca!=1000 && arrayAviones[pos].idMarca!=1001 && arrayAviones[pos].idMarca!=1002 && arrayAviones[pos].idMarca!=1003)
		{
			getInt("\nError, ingrese el ID de la marca del avion: ", &arrayAviones[pos].idMarca);
		}
		getInt("\nIngrese el anio de fabricacion (modelo del avion): ", &arrayAviones[pos].modelo);
		getInt("\nIngrese la cantidad de asientos que tiene el avion: ", &arrayAviones[pos].cantAsientos);
		printf("\nEl ID de su avion es: %d", *idAvion);
		arrayAviones[pos].idAvion=*idAvion;
		arrayAviones[pos].isEmpty=LLENO;
		(*idAvion)++;
		retorno=1;
		if(retorno==1)
		{
			puts("\nSe agrego el avion exitosamente!");
		}
		else
		{
			puts("\nHubo un error a la hora de cargar el avion.");
			retorno=0;
			arrayAviones[pos].isEmpty=VACIO;
		}
	}
	else
	{
		puts("\nNo se encontro un lugar disponible para cargar un nuevo avion.");
	}
	return retorno;
}

int buscarAvionID(eAvion arrayAviones[], int tam, int id)
{
	int retorno=-1;
	int i;

	for(i=0;i<tam;i++)
	{
		if(arrayAviones[i].isEmpty==LLENO)
		{
			if(id==arrayAviones[i].idAvion)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int buscarAvionMatricula(eAvion arrayAviones[], int tam, int matricula)
{
	int retorno=-1;
	int i;

	for(i=0;i<tam;i++)
	{
		if(arrayAviones[i].isEmpty==LLENO)
		{
			if(matricula==arrayAviones[i].matricula)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int modificarAvion(eAvion arrayAviones[], int tamA, eViaje arrayViajes[], int tamV,eMarca arrayMarcas[], int tamM)
{
	int retorno=-1;
	int matricula;
	int pos;
	int len;
	int respuesta;

	len=avionesLen(arrayAviones, tamA); //buscamos que haya aviones cargados para avisar en caso de que no haya ningun alta
	if(len>0)
	{
		mostrarAviones(arrayAviones, tamA, arrayViajes, tamV, arrayMarcas, tamM);
		getInt("\nIngrese la matricula del avion que desea modificar: ", &matricula);
		pos=buscarAvionMatricula(arrayAviones, tamA, matricula); //buscamos por la matricula, al avion que desea modificar
		if(pos!=1)
		{
			getInt("\nQue desea modificar, el modelo o la cantidad de asientos? 1 por modelo 2 por cantidad de asientos: ", &respuesta);
			while(respuesta!=1 && respuesta!=2)
			{
				getInt("\nError, que desea modificar, el modelo o la cantidad de asientos? 1 por modelo 2 por cantidad de asientos: ", &respuesta); //preguntamos que desea modificar y lo validamos
			}
			if(respuesta==1)
			{
				puts("\nUsted ha seleccionado el modelo.");
				getInt("\nIngrese el nuevo modelo (anio de fabricacion): ", &arrayAviones[pos].modelo);
				retorno=1;
			}
			else if(respuesta==2)
			{
				puts("\nUsted ha seleccionado la cantidad de asientos.");
				getInt("\nIngrese la nueva cantidad de asientos: ", &arrayAviones[pos].cantAsientos);
				retorno=1;
			}
			if(retorno==1)
			{
				puts("\nEl avion fue modificado exitosamente!"); //confirmacion de modificacion
			}
			else
			{
				puts("\nHubo un inconveniente a la hora de cargar el avion.");
			}
		}
		else
		{
			puts("\nNo se encontro el avion con ese ID.");
		}
	}
	else
	{
		puts("\n No hay aviones disponibles para modificar.");
	}
	return retorno;
}

int bajaAvion(eAvion arrayAviones[],int tamA, eViaje arrayViajes[], int tamV, eMarca arrayMarcas[], int tamM)
{
	int retorno=-1;
	int len;
	int matricula;
	int pos;
	int respuesta;

	len=avionesLen(arrayAviones, tamA);
	if(len>0)
	{
		mostrarAviones(arrayAviones, tamA, arrayViajes, tamV, arrayMarcas, tamM);
		getInt("\nIngrese la matricula del avion que desea dar de baja: ", &matricula);
		pos=buscarAvionMatricula(arrayAviones, tamA, matricula);
		puts("\nBuscando avion...");
		if(pos!=-1)
		{
			mostrarAvion(arrayAviones[pos], arrayViajes, tamV, arrayMarcas, tamM);
			getInt("\nDesea borrar este avion? 1 por si 2 por no: ",&respuesta);
			if(respuesta==1)
			{
				arrayAviones[pos].isEmpty=VACIO;
				retorno=1;
				puts("\nAvion borrado con exito!");
			}
			else if(respuesta==2)
			{
				puts("\nOperacion cancelada.");
			}
		}
		else
		{
			puts("\nNo se encontro una avion con esa matricula.");
		}
	}
	else
	{
		puts("\nNo hay aviones cargados para dar de baja.");
	}
	return retorno;
}

int ordenamientoMarcaYMatricula(eAvion arrayAviones[], int tamA, eViaje arrayViajes[], int tamV, eMarca arrayMarcas[], int tamM)
{
	int retorno=-1;
	int i;
	int j;
	eAvion aux;

	for(i=0;i<tamA;i++)
	{
		for(j=i+1;j<tamA;j++)
		{
			if(arrayAviones[i].idMarca>arrayAviones[j].idMarca)
			{
				aux=arrayAviones[i];
				arrayAviones[i]=arrayAviones[j];
				arrayAviones[j]=aux;
				if((arrayAviones[i].idMarca=arrayAviones[j].idMarca) && (arrayAviones[i].matricula>arrayAviones[j].matricula))
				{
					aux=arrayAviones[i];
					arrayAviones[i]=arrayAviones[j];
					arrayAviones[j]=aux;
					retorno=1;
				}
			}
		}
	}

	return retorno;
}

int mostrarBoeing(eAvion arrayAviones[], int tamA,eViaje arrayViajes[], int tamV,eMarca arrayMarcas[], int tamM)
{
	int retorno=-1;
	int i;

	for(i=0;i<tamA;i++)
	{
		if(arrayAviones[i].idMarca==1000) //si se cumple la condicion de que dentro del array, el idMarca sea igual al que tiene asignado Boeing, entra al if
		{
			mostrarAvion(arrayAviones[i], arrayViajes, tamV, arrayMarcas, tamM); //mostramos los aviones de la marca boeing
			retorno++;
		}
	}
	if(retorno==-1)
	{
		puts("\nNo hay aviones Boeing cargados.");
	}
	return retorno;
}

int mostrarAvionesMarcaSeleccionada(eAvion arrayAviones[], int tamA, eViaje arrayViajes[], int tamV, eMarca arrayMarcas[], int tamM)
{
	int i;
	int retorno=-1;
	int idMarca;

	mostrarMarcas(arrayMarcas, tamM);
	getInt("\nIngrese el ID de la marca de el/los aviones que desea mostrar: ", &idMarca);
	while(idMarca!=1000 && idMarca!=1001 && idMarca!=1002 && idMarca!=1003)
	{
		getInt("\nError, ingrese el ID de la marca de el/los aviones que desea mostrar: ", &idMarca);
	}
	puts("\nListando aviones con la marca seleccionada...");
	for(i=0;i<tamA;i++)
	{
		if(idMarca==arrayAviones[i].idMarca)
		{
			mostrarAvion(arrayAviones[i], arrayViajes, tamV, arrayMarcas, tamM);
			retorno++;
		}
	}
	if(retorno==-1)
	{
		puts("\nNo hay aviones cargados con la marca que selecciono.");
	}
	return retorno;
}

void mostrarMatriculaYMarca(eAvion unAvion, eMarca arrayMarcas[], int tamM)
{
	char descripcionMarca[20];

	cargarMarca(arrayMarcas, tamM, descripcionMarca, unAvion.idMarca);

	printf("\n  matricula: %d  marca: %s ",	unAvion.matricula,
											descripcionMarca);
}

int mostrarMatriculasYMarca(eAvion arrayAviones[], int tamA, eViaje arrayViajes[], int tamV, eMarca arrayMarcas[], int tamM)
{
	int retorno=-1;
	int i;
	int len;

	len=avionesLen(arrayAviones, tamA);
	if(len>0)
	{
		puts("\nListando aviones...");
		for(i=0;i<tamA;i++)
		{
			if(arrayAviones[i].isEmpty==LLENO)
			{
				if(arrayAviones[i].idViaje==102)
				{
					mostrarAvion(arrayAviones[i], arrayViajes, tamV, arrayMarcas, tamM);
					retorno=1;
				}
			}
		}
	}
	else
	{
		puts("\nNo hay aviones cargados para mostrar.");
	}
	if(retorno==-1)
	{
		puts("\nNo hay aviones cargados que hayan viajado a Neuquen para mostrar.");
	}

	return retorno;
}

int informarKmsTotalesATR(eAvion arrayAviones[], int tamA, eViaje arrayViajes[], int tamV)
{
	int retorno=-1;
	int i;
	int j;
	int len;
	float acumuladorATR=0;

	len=avionesLen(arrayAviones, tamA);
	if(len>0)
	{
		puts("\nSumando los kilometros totales recorridos por los aviones marca ATR...");
		for(i=0;i<tamA;i++)
		{
			if(arrayAviones[i].idMarca==1002)
			{
				for(j=0;j<tamV;j++)
				{
					if(arrayAviones[i].idViaje==arrayViajes[j].idViaje)
					{
						acumuladorATR=acumuladorATR+arrayViajes[j].kilometros;
						retorno++;
					}
				}
			}
		}
	}
	else
	{
		puts("\nNo hay aviones cargados para mostrar.");
	}
	if(retorno==-1)
	{
		puts("\nNo hay aviones cargados de la marca ATR para mostrar.");
	}
	else
	{
		printf("\nLos kilometros totales recorridos por el avion ATR son: %.2f kilometros", acumuladorATR);
	}
	return retorno;
}

int cantidadTotalAsientosAvionSeleccionado(eAvion arrayAviones[], int tamA, eViaje arrayViajes[], int tamV, eMarca arrayMarcas[], int tamM)
{
	int retorno=-1;
	//int i;
	int len;
	int modelo;
	int cantidadDeAsientos;

	len=avionesLen(arrayAviones, tamA);
	if(len>0)
	{
		mostrarAviones(arrayAviones, tamA, arrayViajes, tamV, arrayMarcas, tamM);
		getInt("\nSeleccione el modelo del avion que desea saber la cantidad de asientos que tiene: ", &modelo);
		cantidadDeAsientos=buscarAvionPorModelo(arrayAviones, tamA, modelo);
		if(cantidadDeAsientos!=-1)
		{
			printf("\nLa cantidad total de asientos del modelo que selocciono es: %d asientos.", cantidadDeAsientos);
			retorno=1;
		}
	}
	else
	{
		puts("\nNo hay aviones cargados para mostrar.");
	}
	return retorno;
}

int buscarAvionPorModelo(eAvion arrayAviones[], int tamA, int modelo)
{
	int retorno=-1;
	int i;
	int todoOk=-1;

	for(i=0;i<tamA;i++)
	{
		if(modelo==arrayAviones[i].modelo)
		{
			retorno=arrayAviones[i].cantAsientos;
			todoOk=1;
			break;
		}
	}
	if(todoOk!=-1)
	{
		puts("\nNo se encontro un avion con ese modelo, por favor, intente nuevamente.");
	}
	return retorno;
}
