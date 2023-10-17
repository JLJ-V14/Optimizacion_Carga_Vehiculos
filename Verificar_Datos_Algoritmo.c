#include "definiciones_globales.h"
#include "operaciones_fecha.h"
#include "operaciones_csv.h"
#include "registrar_errores.h"
#include "tipos_optimizacion.h"
#include "validaciones.h"
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


	//Este subprograma se utiliza con el proposito de
	//comprobar que la diferencia temporal entre los
	//puntos de la simulacion es de 1 a 60 minutos.

static int comprobar_resolucion_tiempo_simulacion(datos_csv_algoritmo_t *datos_algoritmo) {

	//Cargo el puntero que apunta a la posicion de memoria
	//donde se encuentra la informaciond de el algoritmo
	datos_csv_t* informacion_algoritmo = &(datos_algoritmo->informacion_algoritmo);
	
	//Cargo la fila y columna donde se encuentra la informacion del algoritmo
	int fila_datos_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.fila_informacion;
	int columna_resolucion_minutos = datos_algoritmo->posiciones_informacion_algoritmo.resolucion_minutos;

	int resolucion_minutos = informacion_algoritmo->datos[fila_datos_algoritmo][columna_resolucion_minutos];

	if ((resolucion_minutos > 60) || (resolucion_minutos < 1)) {
		return ERROR;
	}
	else {
		return EXITO;
	}
}

    //Este subprograma se utiliza
	//para verificar que los datos
	//del Array son correctos. Se 
	//Define los valores que han de 
	//tener los encabezados y se llama
	//al subprograma que se encarga de
	//comprobarlo.



static int verificar_encabezados_algoritmo(datos_csv_t* datos_algoritmo) {

	const wchar_t* valores_aceptables[] = { L"A�o Inicial",L"Mes Inicial",L"Dia Inicial",
	                                        L"Hora Inicial",L"Minuto Inicial",L"A�o Final",L"Mes Final",
	                                        L"Dia Final",L"Hora Final",L"Minuto Final", L"Resolucion Minutos"};

	const int Numero_Encabezados = sizeof(valores_aceptables) / sizeof(valores_aceptables[0]);

	printf("-------------------Prueba----------------------------");
	wprintf(L"%ls\n",datos_algoritmo->datos[0][0]);
	wprintf(L"%ls\n", datos_algoritmo->datos[0][1]);

	if (verificar_encabezado_csv(datos_algoritmo, valores_aceptables,
		Numero_Encabezados, "Datos del Algoritmo") == ERROR) {
		printf("Los encabezados del CSV de los datos del algoritmo son incorrectos\n");
		registrar_error("Fallo en la lectura de los datos de entrada", REGISTRO_ERRORES);
		return ERROR;
	}


	return EXITO;

}
    //Este subprograma se utiliza para verificar
    //que  los datos de un CSV son del tipo 
    //correcto (numerico o string)

 static int verificar_tipo_datos_csv_algoritmo(datos_csv_algoritmo_t*datos_algoritmo) {

	 //Cargo el puntero que apunta a la posiciones de memoria donde se encuentra la informacion del algoritmo
	 datos_csv_t* informacion_algoritmo = &(datos_algoritmo->informacion_algoritmo);
	 int fila_datos_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.fila_informacion;

	for (int columna = 0; columna < NUM_COLUMNAS_CSV_INFO_ALGORITMO; columna++) {

		if (!es_un_numero(informacion_algoritmo->datos[fila_datos_algoritmo][columna],DECIMAL_NO_INCLUIDO)) {
			printf("Hay valores no numericos o decimales en la segunda fila del CSV de los datos del algoritmo \n");
			return ERROR;
		}
	}
	return EXITO;
}
//
static int verificar_parametros_temporales(datos_csv_algoritmo_t * datos_algoritmo) {
	//Este subprograma se utiliza para verificar
	//que los datos temporales del algoritmo 
	//son correctos

	//Se comprueba que la fecha inicial y final
	//del algoritmo son correctos.

	//Tambien se comprueba que la diferencia
	//temporal entre los puntos de calculo
	//del algoritmo es de 1 a 60 minutos.

	struct tm fecha_inicial;
	struct tm fecha_final;

	//Cargo el puntero a donde apunta la posicion de memoria donde se encuentra la informacion
	//del algoritmo
	
	datos_csv_t* informacion_algoritmo = &(datos_algoritmo->informacion_algoritmo);
	//Cargo la fila donde se encuentra la informacion
	int fila_datos_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.fila_informacion;

	//Cargo las columnas en donde se encuentra la informacion de inicio del algoritmo
	int columna_anyo_inicio_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.ubicacion_fecha_inicial_algoritmo.columna_anyo;
	int columna_mes_inicio_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.ubicacion_fecha_inicial_algoritmo.columna_mes;
	int columna_dia_inicio_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.ubicacion_fecha_inicial_algoritmo.columna_dia;
	int columna_hora_inicio_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.ubicacion_fecha_inicial_algoritmo.columna_hora;
	int columna_minuto_inicio_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.ubicacion_fecha_inicial_algoritmo.columna_minuto;

	//Cargo las columnas en donde se ecuentra la informacion de finalizaicon del algoritmo
	int columna_anyo_final_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.ubicacion_fecha_final_algoritmo.columna_anyo;
	int columna_mes_final_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.ubicacion_fecha_final_algoritmo.columna_mes;
	int columna_dia_final_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.ubicacion_fecha_final_algoritmo.columna_dia;
	int columna_hora_final_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.ubicacion_fecha_final_algoritmo.columna_hora;
	int columna_minuto_final_algoritmo = datos_algoritmo->posiciones_informacion_algoritmo.ubicacion_fecha_final_algoritmo.columna_minuto;

	//Se procede a cargar la fecha inicial y final del algoritmo en las variables.
	cargar_fecha(informacion_algoritmo, &fecha_inicial, columna_anyo_inicio_algoritmo,
	columna_mes_inicio_algoritmo, columna_dia_inicio_algoritmo,
	columna_hora_inicio_algoritmo,columna_minuto_inicio_algoritmo,
	fila_datos_algoritmo,SI_INCLUIR_MINUTO);

	cargar_fecha(informacion_algoritmo, &fecha_final, columna_anyo_final_algoritmo,
	columna_mes_final_algoritmo, columna_dia_final_algoritmo,
    columna_hora_final_algoritmo, columna_minuto_final_algoritmo,
    fila_datos_algoritmo,SI_INCLUIR_MINUTO);

	if (verificar_orden_fechas(fecha_inicial, fecha_final, INCLUIR_FECHA_IGUAL) == ERROR) {
		return ERROR;
	}

	if (comprobar_resolucion_tiempo_simulacion(datos_algoritmo) == ERROR) {
		return ERROR;
	}

	return EXITO;
	
}


 int verificar_datos_algoritmo(datos_csv_algoritmo_t * datos_algoritmo) {
	//En este subprograma se verifica que el formato de 
	//de los datos introducidos en el CSV que contiene
    //la informacion del algoritmo es correcta
	
	 datos_csv_t *datos_algoritmo_informacion = &(datos_algoritmo->informacion_algoritmo);

	 if (comprobar_dimensiones_csv_fijo(datos_algoritmo_informacion, NUM_FILAS_CSV_INFO_ALGORITMO,
		 NUM_COLUMNAS_CSV_INFO_ALGORITMO,"Informacion Algoritmo") == ERROR) {

		 printf("Las Dimensiones del CSV de los datos del algoritmo son incorrectas\n");
		 registrar_error("Las Dimensiones del CSV de los datos del algoritmo son incorrectas", REGISTRO_ERRORES);
		 return ERROR;
	}
	
	 if (verificar_encabezados_algoritmo(datos_algoritmo_informacion) == ERROR) {
		 printf("Los encabezados del algoritmo no son correctos \n");
		 registrar_error("Los encabezados del algoritmo no son correctos\n", REGISTRO_ERRORES);
		 return ERROR;
	}
      if (verificar_tipo_datos_csv_algoritmo(datos_algoritmo_informacion) == ERROR) {
		printf("Hay valores incorrectos en el CSV de datos del algoritmo\n");
		registrar_error("Hay valores incorrectos en el CSV de datos del algoritmo\n", REGISTRO_ERRORES);
		return ERROR;
	}

	if ((verificar_parametros_temporales(datos_algoritmo)) == ERROR) {
		printf("Los paremtros temporales del algorimto son incorrectos\n");
		registrar_error("Los parametors temporales del algoritmo son incorrectos\n",REGISTRO_ERRORES);
		return ERROR;
	}
	return EXITO;
}


