
#ifndef INICIALIZAR_VARIABLES_H
#define INICIALIZAR_VARIABLES_H

/* Include files */

#include <stddef.h>
#include <stdlib.h>
#include "Tipos_Optimizacion.h"

#ifdef __cplusplus
extern "C" {
#endif
	int Inicializar_Csvs(Datos_CSV** Datos_Algoritmo, Datos_CSV** Datos_Vehiculos,
		Datos_CSV** Datos_Baterias, Datos_CSV** Datos_Restricciones,
		Datos_CSV** Datos_Precio_Compra, Datos_CSV** Datos_Precio_Venta,
		Datos_CSV** Datos_Terminales);


#ifdef __cplusplus
}
#endif

#endif