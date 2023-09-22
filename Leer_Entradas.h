/*
Este es el archivo tipo h del archivo leer_entradas.c
en este archivo estan los subprogramas que se encargan
de leer los datos de entrada del csv 
*/

#ifndef LEER_ENTRADAS_H
#define LEER_ENTRADAS_H
#include "tipos_optimizacion.h"

#ifdef __cplusplus
extern "C" {
#endif

    int leer_entradas(datos_csv_t* datos_algoritmo, datos_csv_t* datos_vehiculos, 
                      datos_csv_t* datos_baterias,datos_csv_t* datos_restricciones,
                      datos_csv_t* datos_precio_compra, datos_csv_t* datos_precio_venta,
                      datos_csv_t* datos_terminales);

#ifdef __cplusplus
}
#endif

#endif