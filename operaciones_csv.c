//En este archivo se incluyen las funciones
//auxiliares relacionadas con el manejo de
//los CSVs.

#include "Definiciones_Globales.h"
#include "Operaciones_String.h"
#include "Tipos_Optimizacion.h"
#include <stdio.h>

int  Comprobar_Dimensiones_CSV_Fijo(datos_csv* Datos_Excel, const int Numero_Filas,
	const int  Numero_Columnas, const char* Tipo_Csv) {

	//Este subprograma se utiliza para
	//comprobar si las dimensiones de
	//un CSV son correctas, se utiliza
	//para aquellos CSVs en los que las 
	//dimensiones son fijas, y no dependen
	//del numero de vehiculos o baterias o 
	//horas.

	if ((Datos_Excel->Columnas != Numero_Columnas) ||
		(Datos_Excel->Filas != Numero_Filas)) {
		printf("Error el Csv de %s debe tener %d filas y %d columnas", Tipo_Csv, Numero_Filas, Numero_Columnas);
		return ERROR;
	}

	return EXITO;

}

int  Comprobar_Dimensiones_CSV_Variable(datos_csv* Datos_Excel, const int Minimo_Filas,
	const int Numero_Columnas_Exactas, const char* Tipo_CSV) {
	//Este subprograma se utiliza para
	//comprobar si las dimensiones de 
	//los CSVs de los precios
	// que se leen son los 
	//correctos, 
	//el numero de columnas es fijo
	//y el numero de filas es variables
	//pero debe haber más de dos filas
	//(una fila para la información) y
	//otra fila para los datos.

	int Numero_Filas = Datos_Excel->Filas;
	int Numero_Columnas = Datos_Excel->Columnas;

	//El minimo de filas incluye la fila con los
	//encabezados.

	if (Numero_Filas < Minimo_Filas) {
		printf("Debe haber al menos %d filas con informacion en el CSV  de %s\n", Minimo_Filas, Tipo_CSV);
		printf("Actualmente tiene %d Filas \n", Numero_Filas);
		return ERROR;
	}

	if (Numero_Columnas != Numero_Columnas_Exactas) {
		printf("Debe haber %d columnas en el Csv de  %s\n", Numero_Columnas_Exactas, Tipo_CSV);
		printf("Actualmente tiene %d Columnas \n", Numero_Columnas);
		return ERROR;
	}

	return EXITO;
}

int Verificar_Encabezado_CSV(datos_csv* Datos_Excel, const wchar_t* Valores_Encabezado[],
	const int Numero_Encabezados, const char* Nombre_CSV) {
	// Este subprograma se utiliza para comprobar
	// que los encabezados de un archivo CSV sean
	// correctos.

	if (Datos_Excel == NULL || Valores_Encabezado == NULL || Numero_Encabezados <= 0 ||
		Nombre_CSV == NULL) {
		printf("Error: Parámetros de entrada no válidos en la comprobacion de los encabezados.\n");
		return ERROR;
	}


	for (int Numero_Columna = 0; Numero_Columna < Numero_Encabezados; Numero_Columna++) {
		if (!Strings_Iguales(Datos_Excel->Datos[Fila_Encabezados][Numero_Columna],
			Valores_Encabezado[Numero_Columna])) {
			printf("Error en la columna %d del CSV %s el encabezado deberia ser %ls y es %ls\n",
				Numero_Columna, Nombre_CSV, Valores_Encabezado[Numero_Columna],
				Datos_Excel->Datos[Fila_Encabezados][Numero_Columna]);
			return ERROR;
		}
	}
	return EXITO;
}
