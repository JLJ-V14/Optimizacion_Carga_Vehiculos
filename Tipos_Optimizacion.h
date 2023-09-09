#pragma once

//Tipo que sirve para definir el tipo de variable donde se almacenan los datos del CSV.
typedef struct {
    char*** Datos;
    int Filas;
    int Columnas;
} Datos_CSV;