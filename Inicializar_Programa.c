#include "Definiciones_Globales.h"
#include "Tipos_Optimizacion.h"
#include <locale.h>
#include "Liberar_Memoria.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void Inicializar_Numero_Filas_Columnas(Datos_CSV* Datos_Algoritmo,     Datos_CSV* Datos_Vehiculos,
	                                          Datos_CSV* Datos_Baterias,      Datos_CSV* Datos_Restricciones,
	                                          Datos_CSV* Datos_Precio_Compra, Datos_CSV* Datos_Precio_Venta,
	                                          Datos_CSV* Datos_Terminales) {
	//Se usa este subprograma para
	//inicializar el numero de filas y
	//columnas que tiene cada CSV 
	// a 0.

	Datos_Algoritmo->Filas = 0;
	Datos_Algoritmo->Columnas = 0;
	Datos_Vehiculos->Filas = 0;
	Datos_Vehiculos->Columnas = 0;
	Datos_Baterias->Filas = 0;
	Datos_Baterias->Columnas = 0;
	Datos_Restricciones->Filas = 0;
	Datos_Restricciones->Columnas = 0;
	Datos_Precio_Compra->Filas = 0;
	Datos_Precio_Compra->Columnas = 0;
	Datos_Precio_Venta->Filas = 0;
	Datos_Precio_Venta->Columnas = 0;
	Datos_Terminales->Filas = 0;
	Datos_Terminales->Columnas = 0;


}
int Inicializar_Csvs (Datos_CSV ** Datos_Algoritmo,     Datos_CSV **Datos_Vehiculos,
	                  Datos_CSV ** Datos_Baterias,      Datos_CSV **Datos_Restricciones,
	                  Datos_CSV ** Datos_Precio_Compra, Datos_CSV **Datos_Precio_Venta,
	                  Datos_CSV ** Datos_Terminales) {
	
	*Datos_Algoritmo     = malloc(sizeof(Datos_CSV));
	*Datos_Vehiculos     = malloc(sizeof(Datos_CSV));
	*Datos_Baterias      = malloc(sizeof(Datos_CSV));
	*Datos_Restricciones = malloc(sizeof(Datos_CSV));
	*Datos_Precio_Compra = malloc(sizeof(Datos_CSV));
	*Datos_Precio_Venta  = malloc(sizeof(Datos_CSV));
	*Datos_Terminales    = malloc(sizeof(Datos_CSV));

	if (!(*Datos_Algoritmo) || !(*Datos_Vehiculos) || !(*Datos_Baterias) ||
		!(*Datos_Restricciones) || !(*Datos_Precio_Compra) || !(*Datos_Precio_Venta) ||
		!(*Datos_Terminales)) {
		printf("Error reservando memoria\n");

		Liberar_Memoria_Csvs(Datos_Vehiculos, Datos_Algoritmo,
			Datos_Baterias, Datos_Precio_Compra,
			Datos_Precio_Venta, Datos_Restricciones,
			Datos_Terminales);
		return ERROR;
	}
	Inicializar_Numero_Filas_Columnas(Datos_Algoritmo, Datos_Vehiculos, Datos_Baterias,
		                              Datos_Restricciones, Datos_Precio_Compra,
		                              Datos_Precio_Venta, Datos_Terminales);

	return EXITO;
}

static void Ajustes_Idioma() {
	//Para almacenar los caracteres
	//se esta utilizando la libreria
	//wchar.

    #ifdef _WIN32
	setlocale(LC_ALL, "Spanish");
    #elif __linux__
	setlocale(LC_ALL, "es_ES.UTF-8");
    #endif

}

int Inicializar_Algoritmo(Datos_CSV** Datos_Algoritmo, Datos_CSV** Datos_Vehiculos,
	                      Datos_CSV** Datos_Baterias, Datos_CSV** Datos_Restricciones,
	                      Datos_CSV** Datos_Precio_Compra, Datos_CSV** Datos_Precio_Venta,
	                      Datos_CSV** Datos_Terminales) {
	//Se utiliza este subprograma para
	//inicializar las variables y ajustes
	//del programa.
	Ajustes_Idioma();

	if (Inicializar_Csvs(&Datos_Algoritmo, &Datos_Vehiculos, &Datos_Baterias,
		&Datos_Restricciones, &Datos_Precio_Compra,
		&Datos_Precio_Venta, &Datos_Terminales) == ERROR) {
		printf("No se ha podido reservar memoria para los Datos de los Csv \n");
		return ERROR;

	}
	return EXITO;
}