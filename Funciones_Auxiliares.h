

#ifndef FUNCIONES_AUXILIARES_H
#define FUNCIONES_AUXILIARES_H

/* Include files */

#include "Tipos_Optimizacion.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <wchar.h>


#ifdef __cplusplus
extern "C" {
#endif

	bool Strings_Iguales(const wchar_t * String_1, const wchar_t* String_2);
	bool Es_Un_Numero(const wchar_t * str, int Permitir_Decimal);
	bool Es_Negativo(double Numero);
	bool Comprobar_Porcentaje_Bateria(const double Porcentaje_Bateria);
	void Cargar_Fecha(const Datos_CSV* Datos_Entrada, struct tm* Fecha, const int Columna_Csv_Anyo,
		const int Columna_Csv_Mes, const int Columna_Csv_Dia, const int Columna_Csv_Hora,
		const int Columna_Csv_Minuto, const int Numero_Fila,  const int Incluir_Minuto);
	int Verificar_Encabezado_CSV(Datos_CSV* Datos_Excel, const wchar_t* Valores_Encabezado[],
		                         const int Numeros_Encabezados, const char* Nombre_CSV);
	int Comprobar_Orden_Fechas(const struct tm Fecha_Anterior, const struct tm Fecha_Posterior,
		const int    Incluir_Igual);
	int  Comprobar_Dimensiones_CSV_Fijo(Datos_CSV* Datos_Excel, const int Numero_Filas,
		const int  Numero_Columnas, const char* Tipo_CSV);
	int  Comprobar_Dimensiones_CSV_Variable(Datos_CSV* Datos_Excel, const int Minimo_Filas, 
		const int Numero_Columnas_Exactas, const char* Tipo_CSV);
	int  Convertir_A_Decimal(wchar_t* str, double* Num);
	int  Convertir_A_Entero(wchar_t* Str, int* Num);
	int Verificar_Fecha_Carga(Datos_CSV* Datos_Carga, Datos_CSV* Datos_Algoritmo,
		const int Numero_Fila);
	int Verificar_Numero_Terminal(const wchar_t* Numero_Terminal, const int Numero_Fila);
	
	
	

#ifdef __cplusplus
}
#endif

#endif