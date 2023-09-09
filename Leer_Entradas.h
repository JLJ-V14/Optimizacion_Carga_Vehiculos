
#ifndef LEER_ENTRADAS_H
#define LEER_ENTRADAS_H

/* Include files */

#include <stddef.h>
#include <stdlib.h>
#include "Tipos_Optimizacion.h"

#ifdef __cplusplus
extern "C" {
#endif

	int Leer_CSV(const char* Nombre_Archivo, char Delimitador, Datos_CSV* Datos_Excel);

#ifdef __cplusplus
}
#endif

#endif