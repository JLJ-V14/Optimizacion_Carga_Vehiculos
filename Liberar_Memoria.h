/*
   En este archivo.h y el correspondiente.c se encuentran los
   archivos relacionados con liberar espacio en memoria reservado
   a las diferentes variables que se usan en el programa.
*/

#ifndef LIBERAR_MEMORIA_H
#define LIBERAR_MEMORIA_H

#include "tipos_optimizacion.h"

#ifdef __cplusplus
extern "C" {
#endif

    // Libera memoria para un solo conjunto de datos CSV.
    void liberar_memoria_csv_individual(datos_csv_t* datos_csv);

    // Libera memoria para múltiples conjuntos de datos CSV.
    void liberar_memoria_csvs(datos_csv_t* datos_vehiculos, datos_csv_t* datos_algoritmo,
        datos_csv_t* datos_baterias, datos_csv_t* datos_precio_compra,
        datos_csv_t* datos_precio_venta, datos_csv_t* restricciones_sistema,
        datos_csv_t* datos_restricciones);

#ifdef __cplusplus
}
#endif

#endif 
