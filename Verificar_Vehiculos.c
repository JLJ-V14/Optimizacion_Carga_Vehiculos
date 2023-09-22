
#include "Definiciones_Globales.h"
#include "Funciones_Auxiliares.h"
#include "Tipos_Optimizacion.h"
#include <stdio.h>

#define Minimo_Filas_Csv_Vehiculos    1
#define Numero_Columnas_Csv_Vehiculos 16

static int Comprobar_Dimensiones_Csv_Vehiculos(Datos_CSV *Datos_Vehiculos) {
	//Este subprograma se utiliza para
	//comprobar que las dimensiones
	//del CSV de los vehiculos son
	//correctos.

	if (Comprobar_Dimensiones_CSV_Variable(Datos_Vehiculos, Minimo_Filas_Csv_Vehiculos,
		Numero_Columnas_Csv_Vehiculos, "Vehiculos") == ERROR) {
		printf("El CSV de los vehiculos no tienen dimensiones correctas \n");
		return ERROR;
	}
	return EXITO;
}
int Comprobar_Encabezados_Vehiculos(Datos_CSV *Datos_Vehiculos) {
	//Este subprograma se utiliza para 
	//verificar que los encabezados del 
	//CSV que contiene la informacion
	//de los vehiculos es correcta.

	const wchar_t* Valores_Aceptables[] = { L"Terminal",L"Modo Carga",L"Capacidad Bateria",
										   L"Bateria Inicial",L"Bateria Final",L"Maxima Potencia",
										   L"Año Inicial Carga",L"Mes Inicial Carga",L"Dia Inicial Carga",
										   L"Hora Inicial Carga",L"Minuto Inicial Carga",L"Año Final Carga",
										   L"Mes Final Carga",L"Dia Final Carga",L"Hora Final Carga",
										   L"Minuto Final Carga" };
	const int Numero_Encabezados = sizeof(Valores_Aceptables) / sizeof(Valores_Aceptables[0]);

	if (Verificar_Encabezado_CSV(Datos_Vehiculos, Valores_Aceptables, Numero_Encabezados,
		"Vehiculos") == ERROR) {
		printf("Los encabezados del CSV de los vehiculos son incorrectos");
		return ERROR;
	}
	return EXITO;
}

static int Verificar_Modo_Carga(const wchar_t* Modo_Carga, const int Numero_Fila) {
	//Este subprograma se utiliza
	//para verificar que los modos
	//de carga de los Vehiculos 
	//estan escritos correctamente.

	if (Strings_Iguales(Modo_Carga, L"Rapida")  ||
		Strings_Iguales(Modo_Carga, L"Normal"))  {
		return EXITO;
	}
	printf("Error el Modo de carga de los vehiculos debe ser Normal o Rapida");
	return ERROR;
}


static int Verificar_Datos_Bateria_Vehiculo(Datos_CSV *Datos_CSV,const int Numero_Fila) {
	//Este subprograma se utiliza para verificar los
	//datos relacionados con la bateria y la maxima
	//potencia que puede intercambiar el vehiculo.
	
	wchar_t* Capacidad_Bateria = Datos_CSV->Datos[Numero_Fila][Columna_Csv_Vehiculos_Capacidad];
	wchar_t* Maxima_Potencia   = Datos_CSV->Datos[Numero_Fila][Columna_Csv_Vehiculos_Maxima_Potencia];
	wchar_t* Bateria_Inicial   = Datos_CSV->Datos[Numero_Fila][Columna_Csv_Vehiculos_Bateria_Inicial];
	wchar_t* Bateria_Deseada     = Datos_CSV->Datos[Numero_Fila][Columna_Csv_Vehiculos_Bateria_Final];

	if (!Es_Un_Numero(Capacidad_Bateria, Decimal_Incluido)) {
		printf("Error la bateria del vehiculo de la fila %d del CSV de los vehiculos"
	    "no es un numero valido", Numero_Fila);
		return ERROR;
	}

	if (!Es_Un_Numero(Maxima_Potencia, Decimal_Incluido)) {
		printf("Error la maxima potencia que puede intercambiar el vehiculo "
		"de la fila %d del CSV de los vehiculos no es un numero valido", Numero_Fila);
		return ERROR;
	}
	if (!Es_Un_Numero(Bateria_Inicial, Decimal_Incluido)) {
		printf("Error el porcentaje de bateria inicial del vehiculo de la fila %d"
		"del CSV de los vehiculos no es un numero valido", Numero_Fila);
		return ERROR;
	}
	if (!Es_Un_Numero(Bateria_Deseada, Decimal_Incluido)) {
		printf("Error el porcentaje de bateria deseada del vehiculo de la fila %d"
	   "del CSV de los vehiculos no es un numero valido", Numero_Fila);
		return ERROR;
	}

	double Capacidad_Bateria_Num = 0;
	double Maxima_Potencia_Num   = 0;
	double Bateria_Inicial_Num   = 0;
	double Bateria_Deseada_Num   = 0;

	if ((Convertir_A_Decimal(Capacidad_Bateria,&Capacidad_Bateria_Num) ==ERROR)||
		(Convertir_A_Decimal(Maxima_Potencia, &Maxima_Potencia_Num)    ==ERROR)||
	    (Convertir_A_Decimal(Bateria_Inicial,&Bateria_Inicial_Num)     ==ERROR)||
	    (Convertir_A_Decimal(Bateria_Deseada,&Bateria_Deseada_Num)     ==ERROR)){

		printf("No se ha podido convertir a dato numerico la informacion de la bateria\n");
		return ERROR;
	}

	if (!Comprobar_Porcentaje_Bateria(Bateria_Inicial_Num)) {
		printf("Error en la fila %d\n", Numero_Fila);
		printf("El porcentaje de bateria inicial ha de estar entre 0 y 1\n");
		return ERROR;
	}

	if (!Comprobar_Porcentaje_Bateria(Bateria_Deseada_Num)) {
		printf("Error en la fila %d\n", Numero_Fila);
		printf("El porcentaje de bateria inicial ha de estar entre 0 y 1\n");
		return ERROR;
	}

	if (Es_Negativo(Capacidad_Bateria_Num)) {
		printf("Error en la fila %d del CSV de los vehiculos\n", Numero_Fila);
		printf("La capacidad de la bateria no puede ser negativa\n");
		return ERROR;
	}

	if (Es_Negativo(Maxima_Potencia_Num)) {
		printf("Error en la fila %d del CSV de los vehiculos\n", Numero_Fila);
		printf("La Potencia máxima que puede aceptar el vehiculo no puede ser negativa\n");
		return ERROR;
	}
	return EXITO;

}



static int Comprobar_Datos_Csv_Vehiculos(Datos_CSV* Datos_Vehiculos, Datos_CSV* Datos_Algoritmo) {
	//Este subprograma se utiliza para
	//comprobar que los datos de los 
	//vehiculos son correctos.
    
	int Numero_Filas = Datos_Vehiculos->Filas;

	//Se van comprobando los datos de 
	//la fila del CSV, para comprobar
	//que son correctos.

	for (int Numero_Fila = 1; Numero_Fila < Numero_Filas; Numero_Fila++) {

		if (Verificar_Numero_Terminal(Datos_Vehiculos->Datos[Numero_Fila][Columna_Csv_Vehiculos_Terminal],
			Numero_Fila )== ERROR) {
			printf("El campo del numero del terminal en la fila %d"
			"es incorrecto",Numero_Fila);
			return ERROR;
		}


		if (Verificar_Modo_Carga(Datos_Vehiculos->Datos[Numero_Fila][Columna_Csv_Baterias_Objetivo_Carga],
		    Numero_Fila) == ERROR) {
			printf("El Modo de carga en la fila %d del CSV de los vehiculos"
			"es incorrecto\n", Numero_Fila);
			return ERROR;
		}

		if (Verificar_Datos_Bateria_Vehiculo(Datos_Vehiculos, Numero_Fila) == ERROR) {
			printf("Los Datos de la bateria del vehiculo en la fila %d son incorrectos",Numero_Fila);
			return ERROR;
		}

		if (Verificar_Fecha_Carga(Datos_Vehiculos, Datos_Algoritmo, Numero_Fila) == ERROR) {
			printf("Los Datos de fecha del vehiculo en la fila %d son incorrectos", Numero_Fila);
			return ERROR;
		}
		

	}
	return EXITO;
}

void Verificar_Datos_Vehiculos(Datos_CSV* Datos_Vehiculos,Datos_CSV *Datos_Algoritmo) {
	//Este subprograma se utiliza para
	//comprobar que el CSV 
	//que contiene los datos de los 
	//vehiculos es correcto->

	if (Comprobar_Dimensiones_Csv_Vehiculos(Datos_Vehiculos) == ERROR) {
		return ERROR;
	}
	if (Comprobar_Encabezados_Vehiculos(Datos_Vehiculos) == ERROR) {
		return ERROR;
	}


}