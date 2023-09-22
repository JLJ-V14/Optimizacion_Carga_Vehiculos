#include <locale.h>
#include <stdio.h>
#include "definiciones_globales.h"
#include "portabilidad.h"
#include "tipos_optimizacion.h"

static void inicializar_numero_filas_columnas(datos_csv_t* datos_csv[], int num_csvs) {
    //Se inicializa el numero de filas y columnas de la 
    //variable que almacena el csv a 0.
    for (int i = 0; i < num_csvs; i++) {
        datos_csv[i]->filas = 0;
        datos_csv[i]->columnas = 0;
    }
}

int inicializar_csvs(datos_csv_t** datos_csv[], int num_csvs) {
    //Se reserva espacio en memoria para las variables que
    //almacenan los datos de los CSVs.
    for (int i = 0; i < num_csvs; i++) {
        *datos_csv[i] = malloc(sizeof(datos_csv_t));
        if (!(*datos_csv[i])) {
            printf("Error reservando memoria\n");
            return ERROR;
        }
    }

    inicializar_numero_filas_columnas(*datos_csv, num_csvs);
    return EXITO;
}

static void ajustes_idioma() {

#ifdef _WIN32
    setlocale(LC_ALL, "Spanish");
#elif __linux__
    setlocale(LC_ALL, "es_ES.UTF-8");
#endif
}

int inicializar_algoritmo(datos_csv_t** datos_algoritmo, datos_csv_t** datos_vehiculos,
    datos_csv_t** datos_baterias, datos_csv_t** datos_restricciones,
    datos_csv_t** datos_precio_compra, datos_csv_t** datos_precio_venta,
    datos_csv_t** datos_terminales) {
    
    //Se inicializa los datos del algoritmo. El idioma, 
    //y la reserva en memoria.

    ajustes_idioma();

    datos_csv_t* datos_csvs[] = { datos_algoritmo, datos_vehiculos, datos_baterias,
                                  datos_restricciones, datos_precio_compra,
                                  datos_precio_venta, datos_terminales };

    if (inicializar_csvs(&datos_csvs, 7) == ERROR) {
        printf("No se ha podido reservar memoria para los Datos de los Csv \n");
        return ERROR;
    }
    return EXITO;
}
