
/*En este archivo se encuentran los subprogramas reservados
  a liberar la memoria reservada a almacenar la informacion
  leida de los ficheros csv de entrada*/
#include <stdio.h>
#include <stdlib.h>
#include "tipos_optimizacion.h"

    /*
    Este subprograma se utiliza para liberar la memoria
    reservada a almacenar la informacion de un CSV.
    */
void liberar_memoria_csv_individual (datos_csv_t* datos_csv) {

    if (datos_csv == NULL) {
        return; //Si el dato de entrada que es un puntero es NULL se sale de la funcion.
    }
    int numero_filas = (datos_csv)->filas;
    int numero_columnas = (datos_csv)->columnas;

    for (int i = 0; i < numero_filas; i++) {

        for (int j = 0; j < numero_columnas; j++) {
            printf("prueba bucle\n");
            free((datos_csv)->datos[i][j]);
        }
        free((datos_csv)->datos[i]);
    }

    if (datos_csv->datos != NULL) {
        free(datos_csv->datos);
    }
  
}

/*
Este subprograma se utiliza para liberar espacio en memoria para
los datos que se leen de los CSVs
*/

void liberar_memoria_csvs(informacion_entrada_t *informacion_sistema) {
    datos_csv_t* datos_vehiculos = &(informacion_sistema->datos_vehiculos.informacion_vehiculos);
    datos_csv_t* datos_algoritmo = &(informacion_sistema->datos_algoritmo.informacion_algoritmo);
    datos_csv_t* datos_baterias  = &(informacion_sistema->datos_baterias.informacion_baterias);
    datos_csv_t* datos_precio_compra = &(informacion_sistema->datos_precio_compra.informacion_precio_compra);
    datos_csv_t* datos_precio_venta = &(informacion_sistema->datos_precio_venta.informacion_precio_venta);
    datos_csv_t* datos_terminales = &(informacion_sistema->datos_terminales.informacion_terminales);
    datos_csv_t* datos_restricciones = &(informacion_sistema->datos_restricciones.informacion_restricciones);

  
    datos_csv_t * datos_csvs []= {
    datos_vehiculos, datos_algoritmo, datos_baterias,
    datos_precio_compra, datos_precio_venta,
    datos_restricciones, datos_terminales
    };

    int numero_csvs = sizeof(datos_csvs) / sizeof(datos_csvs[0]);

    for (int i = 0; i < numero_csvs; i++) {
        if (datos_csvs[i] != NULL) {
            liberar_memoria_csv_individual(datos_csvs[i]);
            (datos_csvs[i]) = NULL;
           
        }
    }
    
}