
#include "Definiciones_Globales.h"
#include "Funciones_Auxiliares.h"
#include "Tipos_Optimizacion.h"
#include <stdbool.h>
#include <stdio.h>

//Defino las dimensiones que tiene el CSV de la informacion de los terminales
#define   Numero_Filas_Csv_Terminales    13
#define   Numero_Columnas_Csv_Terminales 2

//Defino los valores que han de tener los encabezados->

#define  Encabezado_Numero_Terminal "Numero Terminal"
#define  Encabezado_Fase            "Fase "
//Defino las posiciones en el CSV donde se encuentra alguna
//informacion->

#define  Columna_Encabezados  0


static int Comprobar_Numero_Terminal(const char *Terminal, const int Terminal_Actual) {
	//Este subprogram se utiliza para commprobar
	//que  el dato de numero de terminal es
	//correcto, comprobando que :
	//Es un numero y que
	//Los terminales son consecutivos.

	if (!Es_Un_Numero(Terminal, Decimal_No_Incluido)) {
		printf("El numero del terminal ha de ser un dato numerico \n");
		return ERROR;
	}
    
	int Numero_Terminal;
	if (Convertir_A_Entero(Terminal, &Numero_Terminal) == ERROR) {
		printf("La conversión de caracter a numero entero no ha sido exitosa \n");
		return ERROR;
	}

	if (Numero_Terminal != Terminal_Actual) {
		printf("Error el numero de terminal ha de ser %d y es %d\n",Terminal_Actual,Numero_Terminal);
		return ERROR;
	}
	return EXITO;
}
static int Comprobar_Fase_Terminal(const char *Fase) {
	//Este subprograma se utiliza para comprobar
	//que la fase asignada a cada terminal 
	//corresponde con R S T N o Neutro y Nada

	const char* Valores_Aceptables[] = { "R","S","T","Neutro","Nada" };
	const int Numero_Valores_Aceptables = sizeof(Valores_Aceptables) / sizeof(Valores_Aceptables[0]);
	bool Es_Valido = false;

	for (int i = 0; i < Numero_Valores_Aceptables; i++) {
		if (Strings_Iguales(Fase, Valores_Aceptables[i])) {
			return EXITO;
		}
	}

	printf("Error la fase debe ser R,S,T,Neutro o Nada\n");
	return ERROR;

}
static int Comprobar_Informacion_Terminales(Datos_CSV *Datos_Terminales) {
	//Este subprograma se utiliza para comprobar
	//que la informacion de los diferentes terminales
	//es correcta.
    //Se comprueba que los numeros de los terminales
	//estan asignados correctamente, y la fase de estos
	//es un valor valido, R S T Neutro o nada.

	for (int Numero_Terminal = 1; Numero_Terminal <= Numero_Terminales; Numero_Terminal++) {
		if (Comprobar_Numero_Terminal(Datos_Terminales->Datos[Fila_Numero_Terminal][Numero_Terminal], 
			Numero_Terminal) == ERROR) {
			printf("Error el Numero de terminal en la columna %d no es correcto\n", Numero_Terminal);
			return ERROR;
		}
		if (Comprobar_Fase_Terminal(Datos_Terminales->Datos[Fila_Fase]
			[Numero_Terminal])==ERROR) {
			printf("Error la fase del terminal en la columna %d no es correcta\n", Numero_Terminal);
			return ERROR;

		}
	}
	return EXITO;
}

static int Verificar_Encabezados(Datos_CSV *Datos_Terminales) {
	//Este subprograma se utiliza para
	//verificar que los encabezados del 
	//CSV de los terminales son correctos->
	
	if (Strings_Iguales(Datos_Terminales->Datos[Fila_Numero_Terminal][Columna_Encabezados],
	   Encabezado_Numero_Terminal)==false) {
		printf("Error en la primera fila y primera columna, debe poner Numero_Terminal \n");
		return ERROR;
	}
	if (Strings_Iguales(Datos_Terminales->Datos[Fila_Fase][Columna_Encabezados],
		Encabezado_Fase) == false) {
		printf("Error en la primera fila y segunda columna, debe poner Fase \n");
		return ERROR;
	}
	return EXITO;
}
int Verificar_Datos_Terminales(Datos_CSV* Datos_Terminales) {
	//Este subprograma se utiliza para verificar que la 
	//informacion en el CSV de los terminales es correcto:

	//Se verificara que las dimensiones del CSV son las esperadas
	//y que los terminales estan en orden consecutivo, y que las fases
	//son las esperadas.

	if (Comprobar_Dimensiones_CSV_Fijo(Datos_Terminales,Numero_Filas_Csv_Terminales,
		                              Numero_Columnas_Csv_Terminales,"Informacion Terminales") ==ERROR) {
		printf("Las Dimensiones del CSV de los terminales son incorrectas \n ");
		return ERROR;
	}

	if (Verificar_Encabezados(Datos_Terminales) == ERROR) {
		printf("Los encabezados en el CSV de los terminales son incorrectos \n");
		return ERROR;
	}

	if (Comprobar_Informacion_Terminales(Datos_Terminales) == ERROR) {
		printf("Los Datos del CSV de los terminales son incorrectos\n");
		return ERROR;
	}

	return EXITO;
}