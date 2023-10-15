#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
/*
 * En este archivo se definen las funciones que cambian en funci�n de si el sistema en el que
 * est�n siendo ejecutado el c�digo es tipo Windows o Linux.
 */

 /*
  * Funci�n que sirve para implementar la funci�n wcsdup
  * y que funcione en Windows o Linux. Esta funci�n sirve
  * para duplicar un string.
  */

wchar_t* wcstok_seguro(wchar_t* str, const wchar_t* delimitador, wchar_t** token) {
   
#ifdef _WIN32
    return wcstok_s(str, delimitador, token);
#else
    return wcstok(str, delimitador, token);
#endif
}

/*
  * Funci�n que sirve para implementar la funci�n wcstok
  * y que funcione en Windows o Linux. Esta funci�n sirve
  * para duplicar un string.
  */

wchar_t* wcsdup_plataforma(const wchar_t* src) {
#ifdef _WIN32
    return _wcsdup(src);
#else
    return wcsdup(src);
#endif
}

/*
  * Funci�n que sirve para implementar la funci�n wcstok
  * y que funcione en Windows o Linux. Esta funci�n sirve
  * para abrir un archivo.
  */

int abrir_archivo(const char* nombre_archivo, const char* modo, FILE** archivo) {
#ifdef _WIN32
    return fopen_s(archivo, nombre_archivo, modo);
#else
    *archivo = fopen(nombre_archivo, modo);
    return (*archivo) ? 0 : errno;  // Retorna 0 en caso de  exito, codigo de error con facraso
#endif
}

/*
  * Funci�n que sirve para implementar la funci�n wcstok
  * y que funcione en Windows o Linux. Esta funci�n sirve
  * para imprimir un codigo de error por pantalla
  */

void imprimir_error(int codigo_error) {
#ifdef _WIN32
    char buffer[256];
    strerror_s(buffer, sizeof(buffer), codigo_error);
    fprintf(stderr, "Error: %s\n", buffer);
#else
    fprintf(stderr, "Error: %s\n", strerror(codigo_error));
#endif
}

/*
  * Funci�n que sirve para obtener el dato de tiempo
  * en formato string.
  */


const char* obtener_tiempo_string(time_t* tiempo) {
    static char buffer[26]; // ctime_s recommends a buffer of at least 26 bytes.

#ifdef _WIN32
    errno_t err = ctime_s(buffer, sizeof(buffer), tiempo);
    if (err) {
        return NULL;
    }
    return buffer;
#else
    return ctime(tiempo);  // ctime returns a static buffer on non-Windows platforms.
#endif
}