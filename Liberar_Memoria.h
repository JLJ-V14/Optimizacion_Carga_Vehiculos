

#ifndef LIBERAR_MEMORIA_H
#define LIBERAR_MEMORIA_H

/* Include files */

#include <stddef.h>
#include <stdlib.h>
#include "Tipos_Optimizacion.h"

#ifdef __cplusplus
extern "C" {
#endif
	void Liberar_Memoria_Csv(Datos_CSV* Datos_Excel);
    void Liberar_Memoria_Csvs(Datos_CSV* Datos_Vehiculos, Datos_CSV* Datos_Algoritmo,
        Datos_CSV* Datos_Baterias, Datos_CSV* Datos_Precio_Compra,
        Datos_CSV* Datos_Precio_Venta, Datos_CSV* Restricciones_Sistema,
        Datos_CSV* Datos_Restricciones);

#ifdef __cplusplus
}
#endif

#endif