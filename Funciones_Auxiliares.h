

#ifndef FUNCIONES_AUXILIARES_H
#define FUNCIONES_AUXILIARES_H

/* Include files */

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Tipos_Optimizacion.h"

#ifdef __cplusplus
extern "C" {
#endif
	int Es_Un_Numero(const char* str, int Permitir_Decimal);
	void Cargar_Fecha(const Datos_CSV* Datos_Entrada, struct tm* Fecha, const int Columna_Csv_Anyo,
		const int Columna_Csv_Mes, const int Columna_Csv_Dia, const int Columna_Csv_Hora,
		const int Columna_Csv_Minuto, const int Numero_Fila,  const int Incluir_Minuto);
	int Comprobar_Orden_Fechas(const struct tm Fecha_Anterior, const struct tm Fecha_Posterior,
		const int    Incluir_Igual);
	int Comprobar_Dimension_CSV(const int Numero_Filas, const int Numero_Columnas,
		const int Minimo_Filas, const int Numero_Exacto_Columnas,
		const char* Tipo_Precio);
	int  Convertir_A_Decimal(char* str, double* Num);
	int  Convertir_A_Entero(char* Str, int* Num);
	bool  Es_Negativo(double Numero);

#ifdef __cplusplus
}
#endif

#endif