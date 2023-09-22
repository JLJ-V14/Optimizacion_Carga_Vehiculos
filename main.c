#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "OSQPLIB.lib")
#include <stdio.h>
#include "definiciones_globales.h"
#include "inicializar_programa.h"
#include "leer_entradas.h"
#include "liberar_memoria.h"
#include "tipos_optimizacion.h"
#include "verificar_entradas.h"

int main() {

    // Se crean variables para almacenar los datos de los CSV
    datos_csv_t* datos_algoritmo = NULL;
    datos_csv_t* datos_vehiculos = NULL;
    datos_csv_t* datos_baterias = NULL;
    datos_csv_t* datos_restricciones = NULL;
    datos_csv_t* datos_precio_compra = NULL;
    datos_csv_t* datos_precio_venta = NULL;
    datos_csv_t* datos_terminales = NULL;

    int estado = EXITO;  // Se asume éxito inicialmente.

    // Inicialización de variables y memoria
    if (inicializar_algoritmo(&datos_algoritmo, &datos_vehiculos, &datos_baterias,
        &datos_restricciones, &datos_precio_compra,
        &datos_precio_venta, &datos_terminales) == ERROR) {
        printf("Fallo en la inicialización del algoritmo\n");
        estado = SALIDA_ERROR;
    }

    // Lectura y validación de datos de entrada
    if (estado == EXITO && leer_entradas(datos_algoritmo, datos_vehiculos, datos_baterias,
        datos_restricciones, datos_precio_compra,
        datos_precio_venta, datos_terminales) == ERROR) {
        printf("Fallo en la lectura de las entradas\n");
        estado = SALIDA_ERROR;
    }

    // Verificación de las entradas
    if (estado == EXITO && verificar_entradas(datos_algoritmo, datos_vehiculos, datos_baterias,
        datos_terminales, datos_restricciones,
        datos_precio_compra, datos_precio_venta) == ERROR) {
        printf("Fallo en la validación de las entradas\n");
        estado = SALIDA_ERROR;
    }

    // En caso de error, liberar la memoria reservada
    if (estado == SALIDA_ERROR) {
        liberar_memoria_csvs(datos_vehiculos, datos_algoritmo, datos_baterias,
            datos_precio_compra, datos_precio_venta,
            datos_restricciones, datos_terminales);
    }

    return estado;
}
