
//En este archivo se definen funciones auxiliares que se usan
//frecuentemente a lo largo del codigo.

#include "Definiciones_Globales.h"
#include "Portabilidad.h"
#include "Tipos_Optimizacion.h"
#include "time.h"
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//Se definen que funciones hay 
//que utilizar en funcion del 
//sistema operativo.

#ifdef _WIN32
#define strcasecmp _stricmp
#define wcsdup _wcsdup
#endif

bool Strings_Iguales(const wchar_t* String_1, const wchar_t* String_2) {
	//Este subprograma se utiliza para comprobar
	//que dos string son iguales, si lo son
	//se devuelve true si no se devuelve false.

	//Se configura que el lenguaje utilizado
	//es español y UTF-8 para los caracteres.

	//Ademas se configura que funcione tanto en 
	//Linux como en windows.
 

	if (setlocale(LC_ALL, NULL) == NULL) {
		// Handle error
		printf("No se ha podido configurar en Español\n");
		return false;
	}

	wchar_t* u1 = wcsdup(String_1);
	wchar_t* u2 = wcsdup(String_2);

	if (u1 == NULL || u2 == NULL) {
		free(u1);
		free(u2);
		return false;
	}

	for (size_t i = 0; u1[i] != L'\0'; i++) {
		u1[i] = towupper(u1[i]);
	}

	for (size_t i = 0; u2[i] != L'\0'; i++) {
		u2[i] = towupper(u2[i]);
	}

	int Resultado = wcscoll(u1, u2);

	free(u1);
	free(u2);

	return Resultado == 0;
}

/* De momento se queda comentada
bool Strings_Iguales(const char* String_1, const char* String_2) {
	//Este subprograma se utiliza para comprobar
	//que dos string son iguales, si lo son
	//se devuelve true si no se devuelve false.

	return strcasecmp (String_1, String_2) == 0;
}
*/
int  Convertir_A_Entero(wchar_t* Str, int *Num) {
	//Este subprograma se utiliza
	//para convertir un dato de 
	//tipo wchar a una variable de
	//tipo int.

	//Puntero_Final se utiliza para comprobar
	//que la conversión fue exitosa.
	wchar_t* Puntero_Final;
	*Num = wcstol(Str, &Puntero_Final, 10);
	return *Puntero_Final == L'\0' ? EXITO : ERROR;
	
}

int  Convertir_A_Decimal(wchar_t* str, double *Num) {
	//Este subprograma se utiliza
	//para convertir un dato de 
	//tipo string a unva variable 
	//de tipo double.

	//Puntero Final se utiliza para comprobar
	//que la conversion fue exitosa.
	wchar_t* Puntero_Final;
	*Num = wcstod(str, &Puntero_Final);
	return *Puntero_Final == L'\0' ? EXITO : ERROR;
}

bool  Es_Negativo(double Numero) {
	//Este subprograma se utiliza
	//para comprobar si un numero
	//es negativo

	return Numero < 0;
}
int  Comprobar_Dimensiones_CSV_Fijo(Datos_CSV *Datos_Excel, const int Numero_Filas,
	                                const int  Numero_Columnas,const char *Tipo_Csv) {

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

int  Comprobar_Dimensiones_CSV_Variable(Datos_CSV* Datos_Excel,const int Minimo_Filas, 
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

	if ((Tiempo_Anterior == -1) || (Tiempo_Posterior == -1)) {
		return ERROR;
	}

	if (Tiempo_Anterior < Tiempo_Posterior) {
		return EXITO;
	}
	
    return (Tiempo_Anterior == Tiempo_Posterior) && (Incluir_Igual == Incluir_Fecha_Igual) ? EXITO : ERROR;
	
	
}


void Cargar_Fecha(const Datos_CSV* Datos_Entrada, struct tm* Fecha, const int Columna_Csv_Anyo,
	const int Columna_Csv_Mes, const int Columna_Csv_Dia, const int Columna_Csv_Hora,
	const int Columna_Csv_Minuto, const int Numero_Fila, const int Incluir_Minuto) {

	//Este subprograma se utiliza para cargar la informacion de una fecha de un CSV.

	
		Fecha->tm_year = wcstol(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Anyo],NULL,10) - Offset_Anyo;
		Fecha->tm_mon = wcstol(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Mes],  NULL,10) - Offset_Mes;
		Fecha->tm_mday = wcstol(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Dia], NULL,10);
		Fecha->tm_hour = wcstol(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Hora],NULL,10);
		Fecha->tm_sec = 0;
		//Este campo sirve para detectar si la fecha es un
		//dia de cambio de hora.
		Fecha->tm_isdst = -1;

		if (Incluir_Minuto) {
	    Fecha->tm_min = wcstol(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Minuto],NULL,10);
	    }
		else {
		Fecha->tm_min = 0;
		}
}



bool Es_Un_Numero(const wchar_t* str, int Permitir_Decimal) {
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
			return false; // No es un numero
		}
	}
	return true;

}

int Verificar_Encabezado_CSV(Datos_CSV* Datos_Excel, const wchar_t* Valores_Encabezado[],
	const int Numero_Encabezados, const char *Nombre_CSV) {
	// Este subprograma se utiliza para comprobar
	// que los encabezados de un archivo CSV sean
	// correctos.

	if (Datos_Excel == NULL || Valores_Encabezado == NULL || Numero_Encabezados <= 0||
		Nombre_CSV  == NULL) {
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

bool Comprobar_Porcentaje_Bateria(const double Porcentaje_Bateria) {
    //Este subprograma se utiliza para
	//comprobar que el porcentaje de 
	//bateria se encuentra entre 0 y 1

	return ((Porcentaje_Bateria >= 0) && (Porcentaje_Bateria <= 1));
}


int Verificar_Numero_Terminal (const wchar_t *Numero_Terminal,const int Numero_Fila) {
	//Este subprograma se utiliza
	//para verificar que el dato 
	//de terminal es correcto.

	//Se comprueba que el numero 
	//del terminal esté dentro del 
	//rango y que sea un dato numerico
	//no decimal.
	
	if (!Es_Un_Numero(Numero_Terminal, Decimal_No_Incluido)) {
		printf("El numero de Terminal en la fila %d no es un numero natural\n", Numero_Fila);
		return ERROR;
	}
	int Num_Terminal = 0;

	if (Convertir_A_Entero(Numero_Terminal, &Num_Terminal) == ERROR) {
		printf("El Dato del terminal no se pudo convertir a dato numerico\n");
		return ERROR;
	}


	if ((Num_Terminal < 1) || (Num_Terminal > Numero_Terminales)) {
		printf("Error el numero de terminales ha de estar entre 1 y"
		"%d en el CSV de los vehiculos\n", Numero_Terminales);
		return ERROR;
	}
	return EXITO;
}

void Cargar_Fecha_Algoritmo(Datos_CSV *Datos_Algoritmo,struct tm *Fecha_Inicial_Algoritmo,
	                        struct tm *Fecha_Final_Algoritmo) {
	//Este subprograma se utiliza para 
	//cargar la fecha de inicio y finalizacion
	//del Algoritmo en dos variables.

	Cargar_Fecha(Datos_Algoritmo, Fecha_Inicial_Algoritmo, Columna_Anyo_Inicio_Algoritmo,
	Columna_Mes_Inicio_Algoritmo, Columna_Dia_Inicio_Algoritmo, Columna_Hora_Inicio_Algoritmo,
	Columna_Minuto_Inicio_Algoritmo, Fila_Datos_Algoritmo, Si_Incluir_Minuto);


	Cargar_Fecha(Datos_Algoritmo, Fecha_Final_Algoritmo, Columna_Anyo_Final_Algoritmo,
	Columna_Mes_Final_Algoritmo, Columna_Dia_Final_Algoritmo, Columna_Hora_Final_Algoritmo,
	Columna_Minuto_Final_Algoritmo, Fila_Datos_Algoritmo, Si_Incluir_Minuto);

}

void Cargar_Fecha_Carga(Datos_CSV *Datos_Carga, struct tm *Fecha_Inicial_Carga,
	                    struct tm *Fecha_Final_Carga, const int Numero_Fila) {

	//Este subprograma se utiliza para 
	//cargar la fecha de inicio o
	//finalizacion de un vehiculo 
	//o bateria.

	Cargar_Fecha(Datos_Carga, Fecha_Inicial_Carga, Columna_Csv_Carga_Anyo_Inicial,
		Columna_Csv_Carga_Mes_Inicial, Columna_Csv_Carga_Dia_Inicial,
		Columna_Csv_Carga_Hora_Inicial, Columna_Csv_Carga_Minuto_Inicial,
		Numero_Fila, Si_Incluir_Minuto);

	Cargar_Fecha(Datos_Carga, Fecha_Final_Carga, Columna_Csv_Carga_Anyo_Final,
		Columna_Csv_Carga_Mes_Final, Columna_Csv_Carga_Dia_Final,
		Columna_Csv_Carga_Hora_Final, Columna_Csv_Carga_Minuto_Final,
		Numero_Fila, Si_Incluir_Minuto);
}

int Comprobar_Fecha_Carga(struct tm Fecha_Inicial_Algoritmo, struct tm Fecha_Final_Algoritmo,
	                      struct tm Fecha_Inicial_Carga,     struct tm Fecha_Final_Carga) {

	//Para un vehiculo o bateria se comprueba que:
	//Las fechas de inicio y finalizacion de carga 
	//estan dentro de la ventana temporal del algoritmo
	//La fecha de inicio y finalizacion tienen sentido 
	//es decir la fecha de finalizacion es posterior a 
	//la de inicio.

	if (Comprobar_Orden_Fechas(Fecha_Inicial_Algoritmo, Fecha_Inicial_Carga,
		Incluir_Fecha_Igual) == ERROR) {
		printf("Error la carga del vehiculo no puede empezar "
		"antes que el inicio del algoritmo\n");
		return ERROR;
	}
	if (Comprobar_Orden_Fechas(Fecha_Final_Carga, Fecha_Final_Algoritmo,
		Incluir_Fecha_Igual) == ERROR) {
		printf("Error la carga del vehiculo no puede terminar más tarde"
		"que el fin del algoritmo\n");
		return ERROR;
	}
	if (Comprobar_Orden_Fechas(Fecha_Inicial_Carga, Fecha_Final_Carga,
		Incluir_Fecha_Igual) == ERROR) {
		printf("Error la fecha de inicio de la carga debe ser"
		"anterior a la fecha del posterior\n");
		return ERROR;
	}
	return EXITO;
}
int Verificar_Fecha_Carga(Datos_CSV *Datos_Carga, Datos_CSV * Datos_Algoritmo,
	                      const int Numero_Fila) {
	//Este subprograma se utiliza
	//para verificar que la fecha
	//de carga de un vehiculo o 
	//bateria es correcta.

	//Para un vehiculo o bateria se comprueba que:
	//Las fechas de inicio y finalizacion de carga 
	//estan dentro de la ventana temporal del algoritmo
	//La fecha de inicio y finalizacion tienen sentido 
	//es decir la fecha de finalizacion es posterior a 
	//la de inicio.

	//Las entradas para este subprograma son:
	
	//1. Los datos del CSV que contiene la informacion 
	//de los vehiculos o baterias,
	//2. El CSV que contiene la informacion del algoritmo
	//3. El numero de fila del CSV de los vehiculos o baterias
	//en otras palabras el numero de vehiculo o bateria a revisar

	struct tm Fecha_Inicial_Algoritmo = { 0 };
	struct tm Fecha_Final_Algoritmo   = { 0 };
	struct tm Fecha_Inicial_Carga     = { 0 };
	struct tm Fecha_Final_Carga       = { 0 };

	Cargar_Fecha_Algoritmo(Datos_Algoritmo, &Fecha_Inicial_Algoritmo,
    &Fecha_Final_Algoritmo);

	Cargar_Fecha_Carga(Datos_Carga, &Fecha_Inicial_Carga,
	&Fecha_Final_Carga,Numero_Fila);

	//Se pasa a comprobar que el orden de fechas es correcto
	if (Comprobar_Fecha_Carga(Fecha_Inicial_Algoritmo,
		Fecha_Final_Algoritmo,Fecha_Inicial_Carga,
		Fecha_Final_Carga) == ERROR) {
		return ERROR;
	}
	return EXITO;
}

