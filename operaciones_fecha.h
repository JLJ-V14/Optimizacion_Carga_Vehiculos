#ifndef OPERACIONES_FECHA_H
#define OPERACIONES_FECHA_H

/* Include files */

#include "Tipos_Optimizacion.h"
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif
	void Cargar_Fecha_Algoritmo(datos_CSV* Datos_Algoritmo, struct tm* Fecha_Inicial_Algoritmo,
		 struct tm* Fecha_Final_Algoritmo);
	void Cargar_Fecha_Carga(Datos_CSV* Datos_Carga, struct tm* Fecha_Inicial_Carga,
		 struct tm* Fecha_Final_Carga, const int Numero_Fila);
	int Comprobar_Fecha_Carga(struct tm Fecha_Inicial_Algoritmo, struct tm Fecha_Final_Algoritmo,
		struct tm Fecha_Inicial_Carga, struct tm Fecha_Final_Carga);
	int Verificar_Fecha_Carga(Datos_CSV* Datos_Carga, Datos_CSV* Datos_Algoritmo,
		const int Numero_Fila);
	void Cargar_Fecha(const Datos_CSV* Datos_Entrada, struct tm* Fecha, const int Columna_Csv_Anyo,
		const int Columna_Csv_Mes, const int Columna_Csv_Dia, const int Columna_Csv_Hora,
		const int Columna_Csv_Minuto, const int Numero_Fila, const int Incluir_Minuto);
	int  Comprobar_Orden_Fechas(const struct tm Fecha_Anterior, const struct tm Fecha_Posterior,
		const int    Incluir_Igual);
#ifdef __cplusplus
}
#endif

#endif
