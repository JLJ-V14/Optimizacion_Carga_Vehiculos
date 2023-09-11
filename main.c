#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Inicializar_Variables.h"
#include "Definiciones_Globales.h"
#include "Liberar_Memoria.h"
#include "Leer_Entradas.h"
#include "osqp.h"
#include "csv.h"
#include "Tipos_Optimizacion.h"
#include "Verificar_Entradas.h"

#pragma comment(lib, "OSQPLIB.lib")



int main() {
  //Primeramente se definen las variables en donde se almacenan 
  //los datos leídos de los CSVs
	Datos_CSV *Datos_Algoritmo;
	Datos_CSV *Datos_Vehiculos;
	Datos_CSV *Datos_Baterias;
	Datos_CSV *Datos_Restricciones;
	Datos_CSV *Datos_Precio_Compra;
	Datos_CSV *Datos_Precio_Venta;
	Datos_CSV *Datos_Terminales;

	//Se reserva espacio en memoria para las variables
	//que almacenan los CSVs.

	if (Inicializar_Csvs(&Datos_Algoritmo, &Datos_Vehiculos, &Datos_Baterias,
		&Datos_Restricciones, &Datos_Precio_Compra,
		&Datos_Precio_Venta, &Datos_Terminales) == ERROR) {
		printf("No se ha podido reservar memoria para los Datos de los Csv \n");
		return(Salida_Error);

	}

	//Se Leen los datos de entrada->
	if (Leer_Entradas(Datos_Algoritmo, Datos_Vehiculos, Datos_Baterias,
		Datos_Restricciones, Datos_Precio_Compra,
		Datos_Precio_Venta, Datos_Terminales) == ERROR) {
		printf("La lectura de las entradas ha sido incorrecta \n");
		return(Salida_Error);
	};

	//Se verifica que las entradas sean correctas->
	if (Verificar_Entradas(Datos_Algoritmo, Datos_Vehiculos,
		Datos_Baterias, Datos_Terminales,
		Datos_Restricciones, Datos_Precio_Compra,
		Datos_Precio_Venta) == ERROR) {
		return(Salida_Error);
	}

}
