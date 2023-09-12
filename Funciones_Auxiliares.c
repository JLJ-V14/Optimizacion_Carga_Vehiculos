
//En este archivo se definen funciones auxiliares que se usan
//frecuentemente a lo largo del codigo.

#include "Definiciones_Globales.h"
#include "Tipos_Optimizacion.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int  Convertir_A_Entero(char* Str, int *Num) {
	//Este subprograma se utiliza
	//para convertir un dato de 
	//tipo string a una variable de
	//tipo int.

	//Puntero_Final se utiliza para comprobar
	//que la conversión fue exitosa.
	char* Puntero_Final;
	*Num = strtol(Str, &Puntero_Final, 10);
	return *Puntero_Final == '\0' ? EXITO : ERROR;
	
}

int  Convertir_A_Decimal(char* str, double *Num) {
	//Este subprograma se utiliza
	//para convertir un dato de 
	//tipo string a unva variable 
	//de tipo double.

	//Puntero Final se utiliza para comprobar
	//que la conversion fue exitosa.
	char* Puntero_Final;
	*Num = strtod(str, &Puntero_Final);
	return *Puntero_Final == '\0' ? EXITO : ERROR;
}

bool  Es_Negativo(double Numero) {
	//Este subprograma se utiliza
	//para comprobar si un numero
	//es negativo

	return Numero < 0;
}
int  Comprobar_Dimensiones_CSV_Fijo(Datos_CSV *Datos_Excel, const int Numero_Filas,
	                                const int  Numero_Columnas) {

	//Este subprograma se utiliza para
	//comprobar si las dimensiones de
	//un CSV son correctas, se utiliza
	//para aquellos CSVs en los que las 
	//dimensiones son fijas, y no dependen
	//del numero de vehiculos o baterias o 
	//horas.

	if ((Datos_Excel->Columnas != Numero_Columnas) ||
		(Datos_Excel->Filas != Numero_Filas)) {
		return ERROR;
	}
	
		return EXITO;
	
}

int  Comprobar_Dimension_CSV_Variable(Datos_CSV* Datos_Excel,const int Minimo_Filas, 
	                                  const int Numero_Columnas_Exactas, const char * Tipo_CSV) {
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

	int Numero_Filas    = Datos_Excel->Filas;
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

int  Comprobar_Orden_Fechas  (const struct tm Fecha_Anterior, const struct tm Fecha_Posterior,
	                          const int    Incluir_Igual) {
	//Este subprograma se utiliza para 
	//comprobar si el orden de dos fechas
	//es correcto, si la fecha anterior es
	//efectivamente anterior al parametro de
	//entrada denominado fecha posterior, se 
	//devuelve un 0, lo que significa que es 
	//correcto, si no es un -1.

	//Se incluye un parametro adicional (Incluir_Igual)
	//que sirve para diferenciar si se permite que 
	//la fecha anterior y posterior coincidan


	struct tm Fecha_Anterior_Aux  = Fecha_Anterior;
	struct tm Fecha_Posterior_Aux = Fecha_Posterior;
	time_t    Tiempo_Anterior, Tiempo_Posterior;

	Tiempo_Anterior  = mktime(&Fecha_Anterior_Aux);
	Tiempo_Posterior = mktime(&Fecha_Posterior_Aux);

	if (Tiempo_Anterior < Tiempo_Posterior) {
		return EXITO;
	}
	
    return (Tiempo_Anterior == Tiempo_Posterior) && (Incluir_Igual == Incluir_Fecha_Igual) ? EXITO : ERROR;
	
	
}


void Cargar_Fecha(const Datos_CSV* Datos_Entrada, struct tm* Fecha, const int Columna_Csv_Anyo,
	const int Columna_Csv_Mes, const int Columna_Csv_Dia, const int Columna_Csv_Hora,
	const int Columna_Csv_Minuto, const int Numero_Fila, const int Incluir_Minuto) {

	//Este subprograma se utiliza para cargar la informacion de una fecha de un CSV.

	
		Fecha->tm_year = atoi(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Anyo]) - Offset_Anyo;
		Fecha->tm_mon = atoi(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Mes]) - Offset_Mes;
		Fecha->tm_mday = atoi(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Dia]);
		Fecha->tm_hour = atoi(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Hora]);
		Fecha->tm_sec = 0;
		//Este campo sirve para detectar si la fecha es un
		//dia de cambio de hora.
		Fecha->tm_isdst = -1;

		if (Incluir_Minuto) {
	    Fecha->tm_min = atoi(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Minuto]);
	    }
		else {
		Fecha->tm_min = 0;
		}
}



int Es_Un_Numero(const char* str, int Permitir_Decimal) {
	//Este subprograma se utiliza para 
	//comprobar si el dato del csv leido
	//es un numero o no. Ademas se 
	//diferencia si el numero leido 
	//puede tener decimales o no.

	int Numero_Puntos = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (!isdigit(str[i])) {
			if (Permitir_Decimal && str[i] == '.' && Numero_Puntos++ == 0) {
				continue;
			}
			return ERROR; // No es un numero
		}
	}
	return EXITO;

}

