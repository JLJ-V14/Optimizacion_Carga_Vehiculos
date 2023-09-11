#include "Definiciones_Globales.h"
#include "Funciones_Auxiliares.h"
#include "Tipos_Optimizacion.h"
#include <stdio.h>

//Se definen una serie de constantes
//El numero de columnas que ha de
//tener el CSV del precio

//El numero de filas que ha de tener 
//el CSV de las columnas.

//La primera fila donde comienza la
//informacion

#define Numero_Columnas_Tiempo_Precio 4
#define Numero_Columnas_Precio        5
#define Numero_Minimo_Filas_Precio    2
#define Primera_Fila_Csv_Precio       1

#define PRIMERA_COLUMNA               0
static int Comprobar_Formato_Dato_Tiempo_Precio(Datos_CSV *Datos_Precio, const int Numero_Columna) {
	//Este subprograma se utiliza para comprobar que 
	//los datos temporales relacionados con los
	//precios son numeros enteros, sin decimales.

	int Numero_Filas = Datos_Precio->Filas;

		for (int Numero_Fila = Primera_Fila_Csv_Precio; Numero_Fila < Numero_Filas; Numero_Fila++) {

			if (Es_Un_Numero(Datos_Precio->Datos[Numero_Fila][Numero_Columna], Decimal_No_Incluido) == ERROR) {
				printf("Error en fila %d, columna %d: Los Datos temporales no pueden tener decimales \n", Numero_Fila + 1, Numero_Columna + 1);
				return ERROR;
			}


		
	}
	return EXITO;
}

static int Comprobar_Precio(const Datos_CSV *Datos_Precio, const char *Nombre_Archivo) {
	//En este subprograma se comprueba 
	//que el dato de precio en el CSV
	//es correcto, es decir que sea
	//un numero y que ademas no sea
	//negativo.

	//Declaro variables auxiliares
	//En una se guarda el precio 
	//en formato string otra en 
	//formato numerico
	
	char*  Precio_String;
	double Precio_Num;

	int Numero_Filas = Datos_Precio->Filas;

	//Se comprueba que:
	//Los precios sean valores numericos.
	//Se pueden convertir a numeros.
	//Que no sean negativos.

	for (int Numero_Fila = 1; Numero_Fila < Numero_Filas; Numero_Fila++) {

		Precio_String = Datos_Precio->Datos[Numero_Fila][Columna_Precio];
		if ((Es_Un_Numero(Precio_String, Decimal_Incluido)) == ERROR) {
			printf("En la fila %d del CSV de %s de los precios hay un precio que no es un numero",Numero_Fila,Nombre_Archivo);
			return ERROR;
		}
		if ((Convertir_A_Decimal(Precio_String,&Precio_Num)) == ERROR) {
			printf("El precio de la fila %d del Csv de %s no se ha podido convertir a numero correctamente", Numero_Fila,Nombre_Archivo);
			return ERROR;
		}

		if (Es_Negativo(Precio_Num)) {
			printf("El precio de la fila %d del Csv de %s no puede ser negativo", Numero_Fila, Nombre_Archivo);
			return ERROR;
		}
	}
	return EXITO;
}
static int Comprobar_Formato_Precios(const Datos_CSV* Datos_Precio_Compra,const Datos_CSV* Datos_Precio_Venta) {
	//Se comprueba que el formato de dato
	//en el CSV de los precios es correcto
	//Que los datos de tiempo no tengan 
	//decimales.
	

	for (int Numero_Columna = PRIMERA_COLUMNA; Numero_Columna < Numero_Columnas_Tiempo_Precio; Numero_Columna++) {
		if (Comprobar_Formato_Dato_Tiempo_Precio(Datos_Precio_Compra, Numero_Columna) == ERROR) {
			printf("Error en el CSV de los precios de compra \n");
			return ERROR;
		}
		if (Comprobar_Formato_Dato_Tiempo_Precio(Datos_Precio_Venta, Numero_Columna) == ERROR) {
			printf("Error en el CSV de los precios de venta \n");
			return ERROR;
		}
	}
	//Se pasa a comprobar que:
	//Los precios no son negativos:
	//Son valores numericos.

	if (Comprobar_Precio(Datos_Precio_Compra, "Precio de compra del kilovatio") == ERROR) {
		return ERROR;
	}
	if (Comprobar_Precio(Datos_Precio_Venta, "Precio de venta del kilovatio") == ERROR) {
		return ERROR;
	}
	return EXITO;
}

static int Comprobar_Dimensiones_Csv_Precios(Datos_CSV * Datos_Precio_Compra, Datos_CSV *Datos_Precio_Venta) {
	//Este subprograma se utiliza para 
	//verificar que el numero de filas
	//y columnas en el csv de los precios
	//son correctos.
	int Numero_Filas_Precio_Compra    = Datos_Precio_Compra->Filas;
	int Numero_Columnas_Precio_Compra = Datos_Precio_Compra->Columnas;
	int Numero_Filas_Precio_Venta     = Datos_Precio_Venta->Filas;
	int Numero_Columnas_Precio_Venta  = Datos_Precio_Venta->Columnas;

	if (Comprobar_Dimension_CSV(Numero_Filas_Precio_Compra, Numero_Columnas_Precio_Compra,
		Numero_Minimo_Filas_Precio, Numero_Columnas_Precio,
		"Compra") == ERROR) {
		return ERROR;
	}

	if (Comprobar_Dimension_CSV(Numero_Filas_Precio_Venta, Numero_Columnas_Precio_Venta,
		Numero_Minimo_Filas_Precio, Numero_Columnas_Precio,
		"Venta") == ERROR) {
		return ERROR;
	}
	return EXITO;
}

static int Comprobar_Fecha_Inicial_Precio(Datos_CSV* Datos_Precios,Datos_CSV *Datos_Algoritmo) {
	//Este subprograma se utiliza para
	//comprobar que la fecha inicial de
	//precio es correcto, es decir que
	//la hora inicial del algoritmo esta 
	//cubierta.

	struct tm Fecha_Inicial_Precio    = { 0 };
	struct tm Fecha_Inicial_Algoritmo = { 0 };

	Cargar_Fecha(Datos_Precios, &Fecha_Inicial_Precio, Columna_Anyo_Precio,
		Columna_Mes_Precio, Columna_Dia_Precio, Columna_Hora_Precio,
		No_Procede,Primera_Fila, No_Incluir_Minuto);

	Cargar_Fecha(Datos_Algoritmo, &Fecha_Inicial_Algoritmo, Columna_Anyo_Inicio_Algoritmo,
		         Columna_Mes_Inicio_Algoritmo, Columna_Dia_Inicio_Algoritmo,
		         Columna_Hora_Inicio_Algoritmo, No_Procede,Primera_Fila, No_Incluir_Minuto);

	if (Comprobar_Orden_Fechas(Fecha_Inicial_Precio, Fecha_Inicial_Algoritmo, Incluir_Fecha_Igual) == ERROR) {
		printf("El primer dato de precios es posterior en el tiempo al inicio del algoritmo \n");
		printf("La fecha inicial del algoritmo es \n");
		printf("Año : %d", Fecha_Inicial_Algoritmo.tm_year);
		printf("Mes : %d", Fecha_Inicial_Algoritmo.tm_mon);
		printf("Dia : %d", Fecha_Inicial_Algoritmo.tm_mday);
		printf("Hora: %d", Fecha_Inicial_Algoritmo.tm_hour);
		printf("La fecha inicial del CSV de los precios es \n");
		printf("Año : %d", Fecha_Inicial_Precio.tm_year);
		printf("Mes : %d", Fecha_Inicial_Precio.tm_mon);
		printf("Dia : %d", Fecha_Inicial_Precio.tm_mday);
		printf("Hora : %d", Fecha_Inicial_Precio.tm_hour);
		return ERROR;
	}
	return EXITO;
}

static int Comprobar_Fecha_Precios(Datos_CSV *Datos_Precio_Compra, Datos_CSV *Datos_Precio_Venta) {
	//En este subprograma se comprueba que
	//la fecha a las que estan asociadas los
	//precios tienen sentido.
	
	//Se comprueba que:
	//1.Todas las horas de ejecucion del 
	//Algoritmo tienen un precio asociado.
	//2.Los precios estan en orden cronologico.

}
void Verificar_Precios(Datos_CSV* Datos_Precio_Compra, Datos_CSV *Datos_Precio_Venta) {
	//Este subprograma se utiliza para
	//verificar que los datos de los 
	//precios en el csv que contiene
	//los datos de los precios son 
	//correctos->

	//Para ello se comprueba que:
	//1.El numero de filas y 
	//columnas es correcto.
	//2.Los datos del Csv tienen
	//sentido. (Son datos numericos)
	//y no hay precios negativos.
	//3.El orden cronologio de los 
	//precios tiene sentido.
	if (Comprobar_Dimensiones_Csv_Precios(Datos_Precio_Compra, Datos_Precio_Venta) == ERROR) {
		return ERROR;
	}

	if (Comprobar_Formato_Precios(Datos_Precio_Compra, Datos_Precio_Venta) == ERROR) {
		return ERROR;
	}
	
	return EXITO;

}