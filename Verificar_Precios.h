#pragma once
#ifndef VERIFICAR_PRECIOS_H
#define VERIFICAR_PRECIOS_H

/* Include files */

#include <stddef.h>
#include <stdlib.h>
#include "Tipos_Optimizacion.h"

#ifdef __cplusplus
extern "C" {
#endif
	int Verificar_Precios(Datos_CSV* Datos_Precio_Compra, Datos_CSV* Datos_Precio_Venta,
		                  Datos_CSV* Datos_Algoritmo);


#ifdef __cplusplus
}
#endif

#endif