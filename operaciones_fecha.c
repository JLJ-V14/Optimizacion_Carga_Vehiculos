///*
//En este subprograma se encuentran
//las funciones auxiliares relacionadas 
//con operar las fechas.
//*/
//
//#include "definiciones_globales.h"
//#include "tipos_optimizacion.h"
//#include <stdio.h>
//#include <time.h>
//
///*
//Defino las columnas en donde se encuentran 
//los diferentes tipos de datos del algoritmo
//*/
//
//
////Se convierte los numeros al sistema decimal.
//#define BASE_NUMERO 10 
////Defino la fila donde se encuentran los datos.
//#define FILA_DATOS_ALGORITMO 1   
//
////Hay columnas que son iguales en el CSV de las
////baterias y en el de los vehiculos 
//#define COLUMNA_CSV_CARGA_ANYO_INICIAL    6
//#define COLUMNA_CSV_CARGA_MES_INICIAL     7
//#define COLUMNA_CSV_CARGA_DIA_INICIAL     8
//#define COLUMNA_CSV_CARGA_HORA_INICIAL    9
//#define COLUMNA_CSV_CARGA_MINUTO_INICIAL  10 
//#define COLUMNA_CSV_CARGA_ANYO_FINAL      11
//#define COLUMNA_CSV_CARGA_MES_FINAL       12
//#define COLUMNA_CSV_CARGA_DIA_FINAL       13
//#define COLUMNA_CSV_CARGA_HORA_FINAL      14
//#define COLUMNA_CSV_CARGA_MINUTO_FINAL    15
//
///*
//Verifica si el orden de dos fechas es v�lido.
//Devuelve EXITO si la primera fecha es anterior, ERROR en caso contrario.
//*/
//
//
//
//int  verificar_orden_fechas(const struct tm fecha_anterior, const struct tm fecha_posterior,
//	const int incluir_igual) {
//
//
//
//	struct tm fecha_anterior_aux = fecha_anterior;
//	struct tm fecha_posterior_aux = fecha_posterior;
//	time_t    tiempo_anterior, tiempo_posterior;
//
//	tiempo_anterior = mktime(&fecha_anterior_aux);
//	tiempo_posterior = mktime(&fecha_posterior_aux);
//
//	if ((tiempo_anterior == -1) || (tiempo_posterior == -1)) {
//		return ERROR;
//	}
//
//	if (tiempo_anterior < tiempo_posterior) {
//		return EXITO;
//	}
//
//	return (tiempo_anterior == tiempo_posterior) &&(incluir_igual == INCLUIR_FECHA_IGUAL) ? EXITO : ERROR;
//
//
//}
//
//
///*
//Carga una fecha desde un archivo CSV.
//*/
//
//int cargar_fecha(const datos_csv_t* datos_entrada, struct tm* fecha, const int columna_csv_anyo,
//	const int columna_csv_mes,    const int columna_csv_dia, const int columna_csv_hora,
//	const int columna_csv_minuto, const int numero_fila, const int incluir_minuto) {
//	/*
//    Carga una fecha desde un archivo CSV.
//    */
//
//	// Usando errno para el manejo de errores durante la conversi�n
//	errno = 0;
//
//	fecha->tm_year = wcstol(datos_entrada->datos[numero_fila][columna_csv_anyo],NULL, BASE_NUMERO) - DESPLAZAMIENTO_ANYO;
//	if (errno == ERANGE) {
//		return ERROR;
//	}
//
//	fecha->tm_mon = wcstol(datos_entrada->datos[numero_fila][columna_csv_mes],NULL, BASE_NUMERO) - DESPLAZAMIENTO_MES;
//	if (errno == ERANGE) {
//		return ERROR;
//
//	}
//
//	fecha->tm_mday = wcstol(datos_entrada->datos[numero_fila][columna_csv_dia],NULL, BASE_NUMERO);
//	if (errno == ERANGE) {
//		return ERROR;
//	}
//	fecha->tm_hour = wcstol(datos_entrada->datos[numero_fila][columna_csv_hora],NULL, BASE_NUMERO);
//
//	if (errno == ERANGE) {
//		return ERROR;
//	}
//	fecha->tm_sec  = 0;
//
//	// Indica si la fecha corresponde a un cambio en el horario de verano
//	fecha->tm_isdst = -1;
//
//	if (incluir_minuto) {
//		fecha->tm_min = wcstol(datos_entrada->datos[numero_fila][columna_csv_minuto], NULL, 10);
//		if (errno == ERANGE) return ERROR; {
//			
//		}
//	}
//	else {
//		fecha->tm_min = 0;
//	}
//
//	if (mktime(fecha) == (time_t)-1) {
//		return ERROR;
//	}
//	return EXITO;
//}
//
///* Este subprograma se utiliza para cargar la fecha de inicio y finalizacion*/
///* Puede ser del algoritmo, de un vehiculo o una bateria */
//
//int cargar_fecha_generico(datos_csv_t* datos, struct tm* fecha_inicio, struct tm* fecha_final,
//	int columna_anyo_inicio, int columna_mes_inicio, int columna_dia_inicio,
//	int columna_hora_inicio, int columna_minuto_inicio, int columna_anyo_final,
//	int columna_mes_final, int columna_dia_final, int columna_hora_final,
//	int columna_minuto_final, int numero_fila, int incluir_minuto) {
//
//	if (cargar_fecha(datos, fecha_inicio, columna_anyo_inicio, columna_mes_inicio, columna_dia_inicio,
//		columna_hora_inicio, columna_minuto_inicio, numero_fila, incluir_minuto) == ERROR) {
//		printf("Error al cargar la fecha de inicio\n");
//		return ERROR;
//	}
//
//	if (cargar_fecha(datos, fecha_final, columna_anyo_final, columna_mes_final, columna_dia_final,
//		columna_hora_final, columna_minuto_final, numero_fila, incluir_minuto) == ERROR) {
//		printf("Error al cargar la fecha final\n");
//		return ERROR;
//	}
//
//	return EXITO;
//}
//
//
//
//
//
///*
//Este subprograma se utiliza para
//cargar la fecha de inicio y finalizaci�n
//del Algoritmo en dos variables.
//*/
//
//int cargar_fecha_algoritmo(datos_csv_t* datos_algoritmo, struct tm* fecha_inicial_algoritmo,
//	 struct tm* fecha_final_algoritmo) {
//
//	
//	return cargar_fecha_generico(datos_algoritmo, fecha_inicial_algoritmo, fecha_final_algoritmo,
//		COLUMNA_ANYO_INICIO_ALGORITMO, COLUMNA_MES_INICIO_ALGORITMO,
//		COLUMNA_DIA_INICIO_ALGORITMO, COLUMNA_HORA_INICIO_ALGORITMO,
//		COLUMNA_MINUTO_INICIO_ALGORITMO, COLUMNA_ANYO_FINAL_ALGORITMO,
//		COLUMNA_MES_FINAL_ALGORITMO, COLUMNA_DIA_FINAL_ALGORITMO,
//		COLUMNA_HORA_FINAL_ALGORITMO, COLUMNA_MINUTO_FINAL_ALGORITMO,
//		FILA_DATOS_ALGORITMO, SI_INCLUIR_MINUTO);
//
//}
///*
//Este subprograma se utiliza para
//cargar la fecha de inicio o
//finalizaci�n de un vehiculo
//o bateria.
//*/
//int cargar_fecha_carga(datos_csv_t* datos_carga, struct tm* fecha_inicial_carga,
//	 struct tm* fecha_final_carga, const int numero_fila) {
//	/*
//	Este subprograma se utiliza para 
//	cargar la fecha de inicio o
//	finalizacion de un vehiculo 
//	o bateria.
//	*/
//	return cargar_fecha_generico(datos_carga, fecha_inicial_carga, fecha_final_carga,
//		COLUMNA_CSV_CARGA_ANYO_INICIAL, COLUMNA_CSV_CARGA_MES_INICIAL,
//		COLUMNA_CSV_CARGA_DIA_INICIAL, COLUMNA_CSV_CARGA_HORA_INICIAL,
//		COLUMNA_CSV_CARGA_MINUTO_INICIAL, COLUMNA_CSV_CARGA_ANYO_FINAL,
//		COLUMNA_CSV_CARGA_MES_FINAL, COLUMNA_CSV_CARGA_DIA_FINAL,
//		COLUMNA_CSV_CARGA_HORA_FINAL, COLUMNA_CSV_CARGA_MINUTO_FINAL,
//		numero_fila, SI_INCLUIR_MINUTO);
//}
///*
//Para un vehiculo o bateria se comprueba que :
//Las fechas de inicio y finalizaci�n de carga
//est�n dentro de la ventana temporal del algoritmo.
//La fecha de inicio y finalizaci�n tienen sentido
//es decir la fecha de finalizaci�n es posterior a
//la de inicio.
//*/
//
//int comprobar_fecha_carga(struct tm fecha_inicial_algoritmo, struct tm fecha_final_algoritmo,
//	struct tm fecha_inicial_carga, struct tm fecha_final_carga) {
//
//
//
//	if (verificar_orden_fechas(fecha_inicial_algoritmo, fecha_inicial_carga,
//		INCLUIR_FECHA_IGUAL) == ERROR) {
//		printf("Error la carga del vehiculo no puede empezar "
//			"antes que el inicio del algoritmo\n");
//		return ERROR;
//	}
//	if (verificar_orden_fechas(fecha_final_carga, fecha_final_algoritmo,
//		INCLUIR_FECHA_IGUAL) == ERROR) {
//		printf("Error la carga del vehiculo no puede terminar m�s tarde"
//		"que el fin del algoritmo\n");
//		return ERROR;
//	}
//	if (verificar_orden_fechas(fecha_inicial_carga, fecha_final_carga,
//		INCLUIR_FECHA_IGUAL) == ERROR) {
//		printf("Error la fecha de inicio de la carga debe ser"
//		"anterior a la fecha del posterior\n");
//		return ERROR;
//	}
//	return EXITO;
//}
///*
//Este subprograma se utiliza
//para verificar que la fecha
//de carga de un vehiculo o
//bater�a es correcta.
//
//Para un vehiculo o bater�a se comprueba que:
//Las fechas de inicio y finalizaci�n de carga
//est�n dentro de la ventana temporal del algoritmo.
//La fecha de inicio y finalizaci�n tienen sentido
//es decir la fecha de finalizaci�n es posterior a
//la de inicio.
//
//Las entradas para este subprograma son:
//
//1. Los datos del CSV que contiene la informaci�n
//de los veh�culos o bater�as,
//2. El CSV que contiene la informaci�n del algoritmo
//3. El n�mero de fila del CSV de los veh�culos o bater�as
//en otras palabras el n�mero de veh�culo o bater�a a revisar.
//*/
//int verificar_fecha_carga(datos_csv_t* datos_carga, datos_csv_t* datos_algoritmo,
//	const int numero_fila) {
//
//	struct tm fecha_inicial_algoritmo = {0};
//	struct tm fecha_final_algoritmo = {0};
//	struct tm fecha_inicial_carga = {0};
//	struct tm fecha_final_carga = {0};
//
//	if (cargar_fecha_algoritmo(datos_algoritmo, &fecha_inicial_algoritmo,
//		&fecha_final_algoritmo) == ERROR) {
//		return ERROR;
//	};
//
//	if (cargar_fecha_carga(datos_carga, &fecha_inicial_carga,
//		&fecha_final_carga, numero_fila) == ERROR) {
//		return ERROR;
//	};
//
//	
//	if (comprobar_fecha_carga(fecha_inicial_algoritmo,
//		fecha_final_algoritmo, fecha_inicial_carga,
//		fecha_final_carga) == ERROR) {
//		return ERROR;
//	}
//	return EXITO;
//}
//
//
