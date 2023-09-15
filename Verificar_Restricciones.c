
//*+++++++++++++++++++++++ Pendiente de revision
#include "Definiciones_Globales.h"
#include "Funciones_Auxiliares.h"
#include "Tipos_Optimizacion.h"
#include <stdio.h>

//Defino las dimensiones que ha de tener
//el CSV de las restricciones 

#define Numero_Filas_Csv_Restricciones    2
#define Numero_Columnas_Csv_Restricciones 14


static int Comprobar_Dimension_CSV_Restricciones(Datos_CSV * Datos_Restricciones) {
	//Este subprograma se utiliza
	//para verificar que las dimensiones
	//del CSV de las restricciones son
	//correctas.

	int Numero_Columnas = Datos_Restricciones->Columnas;
	int Numero_Filas    = Datos_Restricciones->Filas;
	if ((Numero_Columnas != Numero_Columnas_Csv_Restricciones) || (Numero_Filas != Numero_Filas_Csv_Restricciones)) {
		printf("Error el csv de las restricciones ha de tener %d columnas y %d filas \n",
	    Numero_Columnas_Csv_Restricciones,Numero_Filas_Csv_Restricciones);
		return ERROR;
	}
	return EXITO;
}

static int Comprobar_Valores_Csv_Restricciones(Datos_CSV* Datos_Restricciones) {
	
}

static int Comprobar_Dato_Restricciones(char *Dato) {
	//Subprograma que se utiliza para
	//comprobar si un dato del CSV de
	//restricciones es un numero no
	//negativo.
	if (!Es_Un_Numero(Dato, Decimal_Incluido)) {
		return ERROR;
	}

	double Valor = Convertir_A_Decimal(Dato, &Valor);
	if (Es_Negativo(Valor)) {
		return ERROR;
	}
	return EXITO;
}
static int Comprobar_Formato_Csv_Restricciones(Datos_CSV* Datos_Restricciones) {
	//Este subprograma se utiliza para
	//comprobar que los datos del
	//CSV de las restricciones son
	//Numeros validos.
	int Numero_Filas    = Datos_Restricciones->Filas;
	int Numero_Columnas = Datos_Restricciones->Columnas;

	for (int Numero_Columna = Primera_Columna_Datos_Restricciones; Numero_Columna < Numero_Columnas; Numero_Columna++) {
		
		
		if(Comprobar_Dato_Restricciones(Datos_Restricciones->Datos[Fila_Informacion_Csv_Restricciones]
		                               [Numero_Columna])==ERROR){

			printf("Error el dato en la fila %d y la columna %d el dato ha de ser numerico y positivo", 
			Fila_Informacion_Csv_Restricciones, Numero_Columna);
			printf("Decimal con '.' \n");
			
			return ERROR;
		}
	}
	return EXITO;
}

int Verificar_Datos_Restricciones(Datos_CSV* Datos_Restricciones) {
	//Este subprograma se utiliza
	//para verificar que los datos
	//en el CSV de las restricciones
	//son correctas->

	if (Comprobar_Dimensiones_CSV_Fijo(Datos_Restricciones, Numero_Filas_Csv_Restricciones,
		Numero_Columnas_Csv_Restricciones,"Restricciones del Sistema") == ERROR) {
		printf("Error en las dimensiones del CSV de las restricciones \n");
		return ERROR;
	}

	if (Comprobar_Formato_Csv_Restricciones(Datos_Restricciones)) {
		printf("Error en los datos de las Restricciones \n");
		return ERROR;
	}

	return EXITO;
}