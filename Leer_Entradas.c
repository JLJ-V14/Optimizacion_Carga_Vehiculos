


#include <errno.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definiciones_globales.h"
#include "funciones_plataforma_dependiente.h"
#include "leer_entradas.h"
#include "liberar_memoria.h"
#include "registrar_errores.h"
#include "tipos_optimizacion.h"



#define  MAX_LONGITUD_LINEA 1024
#define  MAX_NUM_FILAS_INICIAL 10
#define  DELIMITADOR L","



//Se define el numero de csvs que se tiene.
#define NUM_CSVS (sizeof(csvs) / sizeof(csvs[0]))


static int leer_csv(const char* nombre_archivo, wchar_t delimitador, datos_csv_t* datos_csv) {
    //Este subprograma se utiliza para leer los contenidos de los
    //CSV recibe de parametros de entrada el nombre del archivo 
    //el delimitador de los elementos en este caso es la "," 
    //y la variable en la cual almacenar los datos.

    //FILE* archivo = fopen(nombre_archivo, "r");
    FILE* archivo;
    int resultado = abrir_archivo(nombre_archivo, "r", &archivo);
    if (!archivo) {
        char mensaje_error[256]; //Se define un buffer lo suficientemente largo para almacenar el mensaje 
        snprintf(mensaje_error, sizeof(mensaje_error), "No se ha podido abrir el archivo %s", nombre_archivo);
        printf("No se ha podido abrir el archivo %s\n", nombre_archivo);
        registrar_error(mensaje_error,REGISTRO_ERRORES);
        return ERROR;
    }

    int numero_lineas = 0;
    int numero_columnas = 0;
    datos_csv->filas = 0;
    datos_csv->columnas = 0;

    wchar_t linea[MAX_LONGITUD_LINEA];
    int i = 0;

    int capacidad = MAX_NUM_FILAS_INICIAL;
    datos_csv->datos = malloc(capacidad * sizeof(wchar_t**));
    if (datos_csv->datos == NULL) {
        perror("Error reservando memoria");
        fclose(archivo);
        return ERROR;
    }

    while (fgetws(linea, MAX_LONGITUD_LINEA, archivo)) {
        if (linea[0] == L'\n') continue;

        if (numero_lineas == capacidad) {
            capacidad *= 2;
            wchar_t*** temp = realloc(datos_csv->datos, capacidad * sizeof(wchar_t**));
            if (temp == NULL) {
                perror("Error reservando memoria\n");
                liberar_memoria_csv_individual(datos_csv);
                fclose(archivo);
                return ERROR;
            }
            datos_csv->datos = temp;
        }

        wchar_t delimitador_str[2] = { delimitador, L'\0' };
        wchar_t* token;
        wchar_t* next_token;
        token = wcstok_seguro(linea, delimitador_str, &next_token);
        int current_columns = 0;
        while (token != NULL) {
            current_columns++;
            token = wcstok_seguro(NULL, delimitador_str, &next_token);
        }

        if (current_columns > numero_columnas) {
            numero_columnas = current_columns;
        }
        numero_lineas++;

        datos_csv->datos[i] = malloc(numero_columnas * sizeof(wchar_t*));
        if (datos_csv->datos[i] == NULL) {
            perror("Error reservando memoria");
            liberar_memoria_csv_individual(datos_csv);
            fclose(archivo);
            return ERROR;
        }

        token = wcstok_seguro(linea, delimitador_str, &next_token);
        for (int j = 0; j < numero_columnas; j++) {
            if (token != NULL) {
                datos_csv->datos[i][j] = wcsdup_plataforma(token);
                if (datos_csv->datos[i][j] == NULL) {
                    perror("Error reservando memoria\n");
                    liberar_memoria_csv_individual(datos_csv);
                    fclose(archivo);
                    return ERROR;
                }
                token = wcstok_seguro(NULL, delimitador_str, &next_token);
            }
            else {
                datos_csv->datos[i][j] = NULL;
            }
        }
        i++;
    }

    datos_csv->filas = numero_lineas;
    datos_csv->columnas = numero_columnas;

    fclose(archivo);
    return EXITO;
}




int leer_entradas(informacion_entrada_t *informacion_sistema) {

    //Este subprograma se utiliza para leer las diferentes
    //datos de entrada contenidos en los archivos csvs.

    entrada_csv csvs[] = {
    {INFORMACION_TERMINALES, &(informacion_sistema->datos_terminales.informacion_terminales)},
    {INFORMACION_VEHICULOS, &(informacion_sistema->datos_vehiculos.informacion_vehiculos)},
    {INFORMACION_BATERIAS, &(informacion_sistema->datos_baterias.informacion_baterias)},
    {INFORMACION_ALGORITMO, &(informacion_sistema->datos_algoritmo.informacion_algoritmo)},
    {INFORMACION_RESTRICCIONES_SISTEMA, &(informacion_sistema->datos_restricciones.informacion_restricciones)},
    {INFORMACION_PRECIO_COMPRA, &(informacion_sistema->datos_precio_compra.informacion_precio_compra)},
    {INFORMACION_PRECIO_VENTA, &(informacion_sistema->datos_precio_venta.informacion_precio_venta)}
    
    };

    for (int i = 0; i < NUM_CSVS; i++) {
        if (leer_csv(csvs[i].nombre_archivo, DELIMITADOR, csvs[i].datos) == ERROR) {
            
            return ERROR;
        }
    }


    return EXITO;

    

}