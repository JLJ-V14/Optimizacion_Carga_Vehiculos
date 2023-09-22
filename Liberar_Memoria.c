

#include <stdlib.h>
#include "tipos_optimizacion.h"

    /*
    Este subprograma se utiliza para liberar la memoria
    reservada a almacenar la informacion del CSV.
    */
void liberar_memoria_csv_individual (datos_csv_t* datos_csv) {

    if (datos_csv == NULL) {
        return; //Si el dato de entrada que es un puntero es NULL se sale de la funcion.
    }
    int numero_filas = datos_csv->filas;
    int numero_columnas = datos_csv->columnas;

    for (int i = 0; i < numero_filas; i++) {
        for (int j = 0; j < numero_columnas; j++) {
            free(datos_csv->datos[i][j]);
            datos_csv->datos[i][j] = NULL;
        }
        free(datos_csv->datos[i]);
    }
    free(datos_csv->datos);
    datos_csv->filas = 0;
    datos_csv->columnas = 0;
}

/*
Este subprograma se utiliza para liberar espacio en memoria para
los datos que se leen de los CSVs
*/

void liberar_memoria_csvs(datos_csv_t* datos_vehiculos, datos_csv_t* datos_algoritmo,
    datos_csv_t* datos_baterias, datos_csv_t* datos_precio_compra,
    datos_csv_t* datos_precio_venta, datos_csv_t* datos_restricciones_sistema,
    datos_csv_t* datos_terminales) {

  
    if (datos_vehiculos != NULL) {
        liberar_memoria_csv_individual(datos_vehiculos);
    }
    if (datos_algoritmo != NULL) {
        liberar_memoria_csv_individual(datos_algoritmo);
    }
    if (datos_baterias != NULL) {
        liberar_memoria_csv_individual(datos_baterias);
    }
    if (datos_precio_compra != NULL) {
        liberar_memoria_csv_individual(datos_precio_compra);
    }
    if (datos_precio_venta != NULL) {
        liberar_memoria_csv_individual(datos_precio_venta);
    }
    if (datos_restricciones_sistema != NULL) {
        liberar_memoria_csv_individual(datos_restricciones_sistema);
    }
    if (datos_terminales != NULL) {
        liberar_memoria_csv_individual(datos_terminales);
    }
}