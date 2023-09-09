#include "Definiciones_Globales.h"
#include "Funciones_Auxiliares.h"
#include "Tipos_Optimizacion.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



static int Verificar_Numero_Filas_Columnas_Datos_Algoritmo (Datos_CSV *Datos_Algoritmo)
//Este subprograma se utiliza para verificar que
//el numero de filas y columnas del algoritmo
//es correcto.
{
	if ((Datos_Algoritmo->Columnas != Num_Columnas_Csv_Info_Algoritmo) || 
		(Datos_Algoritmo->Filas != Num_Filas_Csv_Info_Algoritmo)) {
		return ERROR;
	}
	else {
		return EXITO;
	}
}

static int Verificar_Tipo_Datos_Csv_Algoritmo(Datos_CSV *Datos_Algoritmo) {
//Este subprograma se utiliza para verificar
//que  los datos de un CSV son del tipo 
//correcto (numerico o string)
	for (int Columna = 0; Columna < Num_Columnas_Csv_Info_Algoritmo; Columna++) {

		if (Es_Un_Numero_Entero(Datos_Algoritmo->Datos[Fila_Datos_Algoritmo][Columna]) == ERROR) {
			printf("Hay valores no numericos o decimales en la segunda fila del CSV de los datos del algoritmo \n");
			return ERROR;
		}
	}
	return EXITO;
}

static int Verificar_Parametros_Temporales(Datos_CSV * Datos_Algoritmo) {
	//Este subprograma se utiliza para verificar
	//que los datos temporales del algoritmo 
	//son correctos

	//Se comprueba que la fecha inicial y final
	//del algoritmo son correctos.

	struct tm Fecha_Inicial;
	struct tm Fecha_Final;

	Cargar_Fecha(Datos_Algoritmo, &Fecha_Inicial, Columna_Anyo_Inicio_Algoritmo,
		Columna_Mes_Inicio_Algoritmo, Columna_Dia_Inicio_Algoritmo,
		Columna_Hora_Inicio_Algoritmo, Columna_Minuto_Inicio_Algoritmo,
		Fila_Datos_Algoritmo);


}
static int Verificar_Formato_Datos_Algoritmo(Datos_CSV * Datos_Algoritmo) {
	//En este subprograma se verifica que el formato de 
	//de los datos introducidos en el CSV que contiene
    //la informacion del algoritmo es correcta
	if ((Verificar_Numero_Filas_Columnas_Datos_Algoritmo(Datos_Algoritmo))==ERROR) {
		printf("El numero de filas y columnas del algoritmo es incorrecto.");
		return ERROR;
	}
	if ((Verificar_Tipo_Datos_Csv_Algoritmo(Datos_Algoritmo)) == ERROR) {
		printf("Hay valores incorrectos en el CSV de datos del algoritmo");
		return ERROR;
	}
	return EXITO;
}


int Verificar_Datos_Algoritmo(Datos_CSV* Datos_Algoritmo) {
	return EXITO;
}