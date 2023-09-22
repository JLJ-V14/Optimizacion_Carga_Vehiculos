


#include <errno.h>
#include <wchar.h>
#include <stdio.h>
#include "definiciones_globales.h"
#include "liberar_memoria.h"
#include "tipos_optimizacion.h"
#define  MAX_LONGITUD_LINEA 1024
#define  MAX_NUM_FILAS_INICIAL 10
#define  DELIMITADOR L","


static int leer_csv(const char* nombre_archivo, wchar_t delimitador, datos_csv_t* datos_csv) {
    //Este subprograma se utiliza para leer los contenidos de los
    //CSV recibe de parametros de entrada el nombre del archivo 
    //el delimitador de los elementos en este caso es la "," 
    //y la variable en la cual almacenar los datos.

    FILE* archivo = fopen(nombre_archivo, "r");
    if (!archivo) {
        fprintf(stderr, "fopen: %s: %s\n", nombre_archivo, strerror(errno));
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
        token = wcstok(linea, delimitador_str, &next_token);
        int current_columns = 0;
        while (token != NULL) {
            current_columns++;
            token = wcstok(NULL, delimitador_str, &next_token);
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

        token = wcstok(linea, delimitador_str, &next_token);
        for (int j = 0; j < numero_columnas; j++) {
            if (token != NULL) {
                datos_csv->datos[i][j] = wcsdup(token);
                if (datos_csv->datos[i][j] == NULL) {
                    perror("Error reservando memoria\n");
                    liberar_memoria_csv_individual(datos_csv);
                    fclose(archivo);
                    return ERROR;
                }
                token = wcstok(NULL, delimitador_str, &next_token);
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




int leer_entradas(datos_csv_t* datos_algoritmo, datos_csv_t* datos_vehiculos, datos_csv_t* datos_baterias,
                  datos_csv_t* datos_restricciones, datos_csv_t *datos_precio_compra, datos_csv_t *datos_precio_venta,
                  datos_csv_t* datos_terminales) {

    //Este subprograma se utiliza para leer las diferentes
    //datos de entrada contenidos en los archivos csvs.

    if (leer_csv(INFORMACION_TERMINALES, DELIMITADOR, datos_terminales) == ERROR) {
        goto error;
    }
    
    if (leer_csv(INFORMACION_VEHICULOS, DELIMITADOR, datos_vehiculos) == ERROR) {
        goto error;
    }
    
    if (leer_csv(INFORMACION_BATERIAS, DELIMITADOR, datos_baterias) == ERROR) {
        goto error;
    }

    if (leer_csv(INFORMACION_ALGORITMO, DELIMITADOR, datos_algoritmo) == ERROR) {
        goto error;
    }

    if (leer_csv(INFORMACION_RESTRICCIONES_SISTEMA, DELIMITADOR, datos_restricciones) == ERROR) {
        goto error;
    }

    if (leer_csv(INFORMACION_PRECIO_COMPRA, DELIMITADOR, datos_precio_compra) == ERROR) {
        goto error;
    }
    
    if (leer_csv(INFORMACION_PRECIO_VENTA, DELIMITADOR, datos_precio_venta) == ERROR) {
        goto error;
    
    }



    return EXITO;

    error:

    liberar_memoria_csvs(datos_vehiculos, datos_algoritmo,
                         datos_baterias,datos_precio_compra, 
                         datos_precio_venta,datos_restricciones, 
                         datos_terminales);
    return ERROR;

}