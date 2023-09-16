#pragma once
#include <wchar.h>
#include <wctype.h>
//Tipo que sirve para definir el tipo de variable donde se almacenan los datos del CSV.
typedef struct {
    wchar_t *** Datos;
    int Filas;
    int Columnas;
} Datos_CSV;