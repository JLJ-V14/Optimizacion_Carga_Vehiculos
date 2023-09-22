
#ifndef INICIALIZAR_VARIABLES_H
#define INICIALIZAR_VARIABLES_H

/* Include files */

#include <stddef.h>
#include <stdlib.h>
#include "Tipos_Optimizacion.h"

#ifdef __cplusplus
extern "C" {
#endif
	int inicializar_algoritmo(datos_csv_t** datos_algoritmo, datos_csv_t** datos_vehiculos,
		datos_csv_t** datos_baterias, datos_csv_t** datos_restricciones,
		datos_csv_t** datos_precio_compra, datos_csv_t** datos_precio_venta,
		datos_csv_t** datos_terminales);


#ifdef __cplusplus
}
#endif

#endif