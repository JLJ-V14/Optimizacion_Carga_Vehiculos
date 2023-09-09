

#ifndef FUNCIONES_AUXILIARES_H
#define FUNCIONES_AUXILIARES_H

/* Include files */

#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "Tipos_Optimizacion.h"

#ifdef __cplusplus
extern "C" {
#endif
	int Es_Un_Numero_Entero(const char* str);
	void Cargar_Fecha(const Datos_CSV* Datos_Entrada, struct tm* Fecha, const int Columna_Csv_Anyo,
		const int Columna_Csv_Mes, const int Columna_Csv_Dia, const int Columna_Csv_Hora,
		const int Columna_Csv_Minuto, const int Numero_Fila);
	int Es_Un_Numero_Decimal(const char* str);

#ifdef __cplusplus
}
#endif

#endif