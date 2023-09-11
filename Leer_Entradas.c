#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Definiciones_Globales.h"
#include "Liberar_Memoria.h"
#include "Tipos_Optimizacion.h"
#include "Verificar_Entradas.h"


static int Leer_CSV(const char* Nombre_Archivo, char Delimitador, Datos_CSV* Datos_Excel) {
    //Este subprograma se utiliza para leer los datos de un CSV.
    FILE* Archivo = fopen(Nombre_Archivo, "r");
    if (!Archivo) {
        perror("No se pudo abrir el archivo \n");
        return ERROR;
    }

    int Numero_Lineas = 0;
    int Numero_Columnas = 0;
    Datos_Excel->Filas = 0;
    Datos_Excel->Columnas = 0;

    char Linea[1024];
    int i = 0;

    int capacidad = 10;
    Datos_Excel->Datos = malloc(capacidad * sizeof(char**));
    if (Datos_Excel->Datos == NULL) {
        perror("Error allocating memory");
        fclose(Archivo);
        return ERROR;
    }

    while (fgets(Linea, 1024, Archivo)) {
        if (Linea[0] == '\n') continue;

        if (Numero_Lineas == capacidad) {
            capacidad *= 2;
            char*** temp = realloc(Datos_Excel->Datos, capacidad * sizeof(char**));
            if (temp == NULL) {
                perror("Error reallocating memory");
                Liberar_Memoria_Csv(Datos_Excel);
                fclose(Archivo);
                return ERROR;
            }
            Datos_Excel->Datos = temp;
        }

        //Se cuenta el numero de columnas
        char DelimitadorStr[2] = { Delimitador, '\0' };
        char* Token = strtok(Linea, DelimitadorStr);
        int current_columns = 0;
        while (Token != NULL) {
            current_columns++;
            Token = strtok(NULL, DelimitadorStr);
        }

        if (current_columns > Numero_Columnas) {
            Numero_Columnas = current_columns;
        }
        //Se cuenta el numero de filas.
        Numero_Lineas++;

        Datos_Excel->Datos[i] = malloc(Numero_Columnas * sizeof(char*));
        if (Datos_Excel->Datos[i] == NULL) {
            perror("Error allocating memory");
            Liberar_Memoria_Csv(Datos_Excel, Numero_Lineas, Numero_Columnas);
            fclose(Archivo);
            return ERROR;
        }

        Token = strtok(Linea, DelimitadorStr);
        for (int j = 0; j < Numero_Columnas; j++) {
            if (Token != NULL) {
                Datos_Excel->Datos[i][j] = malloc(strlen(Token) + 1); // Allocate memory
                if (Datos_Excel->Datos[i][j] == NULL) {
                    perror("Error allocating memory");
                    Liberar_Memoria_Csv(Datos_Excel, Numero_Lineas, Numero_Columnas);
                    fclose(Archivo);
                    return ERROR;
                }
                strcpy(Datos_Excel->Datos[i][j], Token); // Copy the string
                Token = strtok(NULL, DelimitadorStr);
            }
            else {
                Datos_Excel->Datos[i][j] = NULL;
            }
        }
        i++;
    }

    Datos_Excel->Filas = Numero_Lineas;
    Datos_Excel->Columnas = Numero_Columnas;

    fclose(Archivo);
    return EXITO;
}



int Leer_Entradas(Datos_CSV* Datos_Algoritmo, Datos_CSV* Datos_Vehiculos, Datos_CSV* Datos_Baterias,
                  Datos_CSV* Datos_Restricciones, Datos_CSV *Datos_Precio_Compra, Datos_CSV *Datos_Precio_Venta,
                  Datos_CSV* Datos_Terminales) {

    //Este subprograma se utiliza para leer las diferentes
    //datos de entrada contenidos en los archivos csvs.

    if (Leer_CSV("Informacion_Terminales.csv", ",", Datos_Terminales) == ERROR) {
        goto error;
    }
    
    if (Leer_CSV("Informacion_Vehiculos.csv", ",", Datos_Vehiculos) == ERROR) {
        goto error;
    }
    
    if (Leer_CSV("Informacion_Baterias.csv", ",", Datos_Baterias) == ERROR) {
        goto error;
    }

    if (Leer_CSV("Informacion_Algoritmo.csv", ",", Datos_Algoritmo) == ERROR) {
        goto error;
    }

    if (Leer_CSV("Restricciones_Sistema.csv", ",", Datos_Restricciones) == ERROR) {
        goto error;
    }

    if (Leer_CSV("Precio_Compra_Kilovatio.csv", ",", Datos_Precio_Compra) == ERROR) {
        goto error;
    }
    
    if (Leer_CSV("Precio_Venta_Kilovatio.csv", ",", Datos_Precio_Venta) == ERROR) {
        goto error;
    
    }



    return EXITO;

    error:

    Liberar_Memoria_Csvs(Datos_Vehiculos, Datos_Algoritmo,
                         Datos_Baterias,Datos_Precio_Compra, 
                         Datos_Precio_Venta,Datos_Restricciones, 
                         Datos_Terminales);
    return ERROR;

}