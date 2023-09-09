
//En este archivo se definen funciones auxiliares que se usan
//frecuentemente a lo largo del codigo.

#include "Definiciones_Globales.h"
#include "Tipos_Optimizacion.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void Cargar_Fecha(const Datos_CSV* Datos_Entrada, struct tm* Fecha, const int Columna_Csv_Anyo,
	const int Columna_Csv_Mes, const int Columna_Csv_Dia, const int Columna_Csv_Hora,
	const int Columna_Csv_Minuto, const int Numero_Fila) {

	//Este subprograma se utiliza para cargar la informacion de una fecha de un CSV.


	Fecha->tm_year = atoi(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Anyo] - Offset_Anyo);
	Fecha->tm_mon = atoi(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Mes] - Offset_Mes);
	Fecha->tm_mday =atoi(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Dia]);
	Fecha->tm_hour =atoi(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Hora]);
	Fecha->tm_min = atoi(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Minuto]);
	Fecha->tm_sec = 0;
}

int Es_Un_Numero_Entero(const char* str) {
	//Este subprograma sirve para comprobar
	//que un valor del csv es de tipo 
	//entero
	int Numero_Puntos = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (!isdigit(str[i])) {
			return ERROR; // No es un numero
		}
	}
	return EXITO;
}

int Es_Un_Numero_Decimal(const char* str) {
	//Este subprograma sirve para comprobar
	//que un valor del csv es de tipo
	//entero
	int Numero_Puntos = 0;

	for (int i = 0; str[i] != '\0';i++) {
		if (!isdigit(str[i]) && (str[i] != '.' || Numero_Puntos++ > 0)) {
			return ERROR; // No es un numero
		}
	}
	return EXITO;
}

