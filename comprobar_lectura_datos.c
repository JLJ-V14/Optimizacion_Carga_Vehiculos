#include "definiciones_globales.h"
#include "funciones_plataforma_dependiente.h"
#include "registrar_errores.h"
#include "tipos_optimizacion.h"
#include <stdio.h>
#include <wchar.h>

/* En este archivo se incluyen las funciones 
*  para comprobar que informacion de entrada
*  se esta leyendo de los csvs.
*  Informacion a comprobar:
*  datos_algoritmo
*  datos_vehiculos
*  datos_baterias
*  datos_restricciones
*  datos_terminales
*  datos_precio_compra
*  datos_precio_venta
*/

/* Se definen los nombres de los CSVs en los cuales
*  se va a escribir la informacion que se ha leido
*/
#define ARCHIVO_COMPROBACION_ALGORITMO       "comprobacion_datos_algoritmo"
#define ARCHIVO_COMPROBACION_VEHICULOS       "comprobacion_datos_vehiculos"
#define ARCHIVO_COMPROBRACION_BATERIA        "comprobacion_datos_baterias"
#define ARCHIVO_COMPROBACION_RESTRICCIONES   "comprobacion_datos_restricciones"
#define ARCHIVO_COMPROBACION_TERMINALES      "comprobacion_datos_terminales"
#define ARCHIVO_COMPROBACION_PRECIO_COMPRA   "comprobacion_datos_precio_compra"
#define ARCHIVO_COMPROBACION_PRECIO_VENTA    "comprobacion_datos_precio_venta"


/*
* Se escribe los subprogramas que escriben los datos
* en los csvs.
*/

static void comprobar_datos(FILE* comprobacion_datos, datos_csv_t * datos) {
	
	
	for (int fila = 0; fila < datos->filas; fila++) {
		for (int columna = 0; columna < datos->columnas; columna++) {
		
			fwprintf(comprobacion_datos, L"%ls",datos->datos[fila][columna]);
		}
	}
	printf("Numero de filas es %d\n",datos->filas);
}
/*
*  En el subprograma comprobar_informacion_entrada
*  se escribe la informacion de entrada en unos
*  archivos tipo csv.
*/

int comprobar_informacion_entrada(informacion_entrada_t* informacion_sistema) {
	FILE* comprobacion_datos_algoritmo;
	FILE* comprobacion_datos_vehiculos;
	FILE* comprobacion_datos_baterias;
	FILE* comprobacion_datos_restricciones;
	FILE* comprobacion_datos_terminales;
	FILE* comprobacion_datos_precio_compra;
	FILE* comprobacion_datos_precio_venta;

	if (abrir_archivo(ARCHIVO_COMPROBACION_ALGORITMO, "w", &comprobacion_datos_algoritmo) != 0) {
		printf("Error en la comprobacion de los datos del algoritmo\n");
		registrar_error("Fallo en la comprobacion de los datos del algoritmo", REGISTRO_ERRORES);
		fclose(comprobacion_datos_algoritmo);
		return ERROR;
	}
	if (abrir_archivo(ARCHIVO_COMPROBACION_VEHICULOS, "w", &comprobacion_datos_vehiculos) != 0) {
		printf("Error en la comprobacion de los datos de los vehiculo\n");
		registrar_error("Fallo en la comprobación de los datos del vehículo", REGISTRO_ERRORES);
		fclose(comprobacion_datos_algoritmo);
		fclose(comprobacion_datos_vehiculos);
		return ERROR;
	}
	if (abrir_archivo(ARCHIVO_COMPROBRACION_BATERIA, "w", &comprobacion_datos_baterias) != 0) {
		printf("Error en la comprobacion de los datos de baterias\n");
		registrar_error("Fallo en la comprobación de los datos de las baterías", REGISTRO_ERRORES);
		fclose(comprobacion_datos_algoritmo);
		fclose(comprobacion_datos_vehiculos);
		fclose(comprobacion_datos_baterias);
		return ERROR;
	}
	if (abrir_archivo(ARCHIVO_COMPROBACION_RESTRICCIONES, "w", &comprobacion_datos_restricciones) != 0) {
		printf("Error en la comprobacion de los datos de restricciones\n");
		registrar_error("Fallo en la comprobación de los datos de las restricciones", REGISTRO_ERRORES);
		fclose(comprobacion_datos_algoritmo);
		fclose(comprobacion_datos_vehiculos);
		fclose(comprobacion_datos_baterias);
		fclose(comprobacion_datos_restricciones);
		return ERROR;
	}
	if (abrir_archivo(ARCHIVO_COMPROBACION_TERMINALES, "w", &comprobacion_datos_terminales) != 0) {
		printf("Error en la comprobacion de los datos de los terminales\n");
		registrar_error("Fallo en la comprobación de los datos de los terminales", REGISTRO_ERRORES);
		fclose(comprobacion_datos_algoritmo);
		fclose(comprobacion_datos_vehiculos);
		fclose(comprobacion_datos_baterias);
		fclose(comprobacion_datos_restricciones);
		fclose(comprobacion_datos_terminales);
		return ERROR;
	}
	if (abrir_archivo(ARCHIVO_COMPROBACION_PRECIO_COMPRA, "w", &comprobacion_datos_precio_compra) != 0) {
		printf("Error en la comprobacion de los datos de los precio de compra\n");
		registrar_error("Fallo en la comprobación de los datos de precio de compra", REGISTRO_ERRORES);
		fclose(comprobacion_datos_algoritmo);
		fclose(comprobacion_datos_vehiculos);
		fclose(comprobacion_datos_baterias);
		fclose(comprobacion_datos_restricciones);
		fclose(comprobacion_datos_terminales);
		fclose(comprobacion_datos_precio_compra);
		return ERROR;
	}
	if (abrir_archivo(ARCHIVO_COMPROBACION_PRECIO_VENTA, "w", &comprobacion_datos_precio_venta) != 0) {
		printf("Error en la comprobacion de los datos de los precios de venta\n");
		registrar_error("Fallo en la comprobación de los datos de precio de venta", REGISTRO_ERRORES);
		fclose(comprobacion_datos_algoritmo);
		fclose(comprobacion_datos_vehiculos);
		fclose(comprobacion_datos_baterias);
		fclose(comprobacion_datos_restricciones);
		fclose(comprobacion_datos_terminales);
		fclose(comprobacion_datos_precio_compra);
		fclose(comprobacion_datos_precio_venta);
		return ERROR;
	}
	/*
	* Se definen los punteros que apuntan a la localizacion en 
	* memoria, donde se encuentran la informacion.
	*/
	datos_csv_algoritmo_t*      datos_algoritmo      = &(informacion_sistema->datos_algoritmo);
	datos_csv_vehiculos_t*      datos_vehiculo       = &(informacion_sistema->datos_vehiculos);
	datos_csv_baterias_t*       datos_baterias       = &(informacion_sistema->datos_baterias);
	datos_csv_restricciones_t*  datos_restricciones  = &(informacion_sistema->datos_restricciones);
	datos_csv_terminales_t*     datos_terminales     = &(informacion_sistema->datos_terminales);
	datos_csv_precio_compra_t*  datos_precio_compra  = &(informacion_sistema->datos_precio_compra);
	datos_csv_precio_venta_t*   datos_precio_venta   = &(informacion_sistema->datos_precio_venta);

	/*
	* Se escribe los datos de los csvs.
	*/
	comprobar_datos(comprobacion_datos_algoritmo,datos_algoritmo);
	comprobar_datos(comprobacion_datos_vehiculos, datos_vehiculo);
	comprobar_datos(comprobacion_datos_baterias, datos_baterias);
	comprobar_datos(comprobacion_datos_restricciones, datos_restricciones);
	comprobar_datos(comprobacion_datos_terminales, datos_terminales);
	comprobar_datos(comprobacion_datos_precio_compra, datos_precio_compra);
	comprobar_datos(comprobacion_datos_precio_venta, datos_precio_venta);


	fclose(comprobacion_datos_algoritmo);
	fclose(comprobacion_datos_vehiculos);
	fclose(comprobacion_datos_baterias);
	fclose(comprobacion_datos_restricciones);
	fclose(comprobacion_datos_terminales);
	fclose(comprobacion_datos_precio_compra);
	fclose(comprobacion_datos_precio_venta);
	
	return EXITO;
}