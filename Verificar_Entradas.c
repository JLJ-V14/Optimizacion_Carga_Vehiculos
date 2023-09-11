#include "Definiciones_Globales.h"
#include "Verificar_Datos_Algoritmo.h"
#include "Tipos_Optimizacion.h"
#include <stdlib.h>
#include <stdio.h>

int Verificar_Entradas(Datos_CSV* Datos_Algoritmo, Datos_CSV* Datos_Vehiculos,
	Datos_CSV* Datos_Baterias,      Datos_CSV* Datos_Terminales,
	Datos_CSV* Datos_Restricciones, Datos_CSV* Datos_Precio_Compra,
    Datos_CSV* Datos_Precio_Venta) {

	//Este subprograma se utiliza para verificar
	//los datos que vienen en los ficheros CSV.

	if (Verificar_Datos_Algoritmo(Datos_Algoritmo)) {
		printf("Los Datos del algoritmo son incorrectos \n");
		return ERROR;
	}
	return EXITO;
}