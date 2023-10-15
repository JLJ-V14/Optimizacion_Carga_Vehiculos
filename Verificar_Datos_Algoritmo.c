//#include "Definiciones_Globales.h"
//#include "Funciones_Auxiliares.h"
//#include "Tipos_Optimizacion.h"
//#include <time.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//
//
//
//static int Comprobar_Resolucion_Tiempo_Simulacion(Datos_CSV *Datos_Algoritmo) {
//	//Este subprograma se utiliza con el proposito de
//	//comprobar que la diferencia temporal entre los
//	//puntos de la simulacion es de 1 a 60 minutos.
//
//	int Resolucion_Minutos = Datos_Algoritmo->Datos[Fila_Datos_Algoritmo][Columna_Resolucion_Tiempo_Simulacion];
//	if ((Resolucion_Minutos > 60) || (Resolucion_Minutos < 1)) {
//		return ERROR;
//	}
//	else {
//		return EXITO;
//	}
//}
//
//static int Verificar_Encabezados_Algoritmo(Datos_CSV* Datos_Algoritmo) {
//    //Este subprograma se utiliza
//	//para verificar que los datos
//	//del Array son correctos. Se 
//	//Define los valores que han de 
//	//tener los encabezados y se llama
//	//al subprograma que se encarga de
//	//comprobarlo.
//
//	const wchar_t* Valores_Aceptables[] = { L"Año Inicial",L"Mes Inicial",L"Hora Inicial",
//	                                        L"Minuto Inicial",L"Año Final",L"Mes Final",
//	                                        L"Dia Final",L"Minuto Final", L"Resolucion Minutos"};
//	const int Numero_Encabezados = sizeof(Valores_Aceptables) / sizeof(Valores_Aceptables[0]);
//
//
//	if (Verificar_Encabezado_CSV(Datos_Algoritmo, Valores_Aceptables,
//		Numero_Encabezados, "Datos del Algoritmo") == ERROR) {
//		printf("Los encabezados del CSV de los datos del algoritmo son incorrectos\n");
//		return ERROR;
//	}
//
//
//	return EXITO;
//
//}
//static int Verificar_Tipo_Datos_Csv_Algoritmo(Datos_CSV *Datos_Algoritmo) {
//     //Este subprograma se utiliza para verificar
//     //que  los datos de un CSV son del tipo 
//     //correcto (numerico o string)
//	for (int Columna = 0; Columna < Num_Columnas_Csv_Info_Algoritmo; Columna++) {
//
//		if (!Es_Un_Numero(Datos_Algoritmo->Datos[Fila_Datos_Algoritmo][Columna],Decimal_No_Incluido)) {
//			printf("Hay valores no numericos o decimales en la segunda fila del CSV de los datos del algoritmo \n");
//			return ERROR;
//		}
//	}
//	return EXITO;
//}
//
//static int Verificar_Parametros_Temporales(Datos_CSV * Datos_Algoritmo) {
//	//Este subprograma se utiliza para verificar
//	//que los datos temporales del algoritmo 
//	//son correctos
//
//	//Se comprueba que la fecha inicial y final
//	//del algoritmo son correctos.
//
//	//Tambien se comprueba que la diferencia
//	//temporal entre los puntos de calculo
//	//del algoritmo es de 1 a 60 minutos.
//
//	struct tm Fecha_Inicial;
//	struct tm Fecha_Final;
//
//	
//	Cargar_Fecha(Datos_Algoritmo, &Fecha_Inicial, Columna_Anyo_Inicio_Algoritmo,
//		Columna_Mes_Inicio_Algoritmo, Columna_Dia_Inicio_Algoritmo,
//		Columna_Hora_Inicio_Algoritmo, Columna_Minuto_Inicio_Algoritmo,
//		Fila_Datos_Algoritmo,Si_Incluir_Minuto);
//
//	Cargar_Fecha(Datos_Algoritmo, &Fecha_Final, Columna_Anyo_Final_Algoritmo,
//		         Columna_Mes_Final_Algoritmo, Columna_Dia_Final_Algoritmo,
//		         Columna_Hora_Final_Algoritmo, Columna_Minuto_Final_Algoritmo,
//		         Fila_Datos_Algoritmo,Si_Incluir_Minuto);
//
//	if (Comprobar_Orden_Fechas(Fecha_Inicial, Fecha_Final, Incluir_Fecha_Igual) == ERROR) {
//		return ERROR;
//	}
//
//	if (Comprobar_Resolucion_Tiempo_Simulacion(Datos_Algoritmo) == ERROR) {
//		return ERROR;
//	}
//
//	return EXITO;
//	
//}
//
//
// int Verificar_Datos_Algoritmo(Datos_CSV * Datos_Algoritmo) {
//	//En este subprograma se verifica que el formato de 
//	//de los datos introducidos en el CSV que contiene
//    //la informacion del algoritmo es correcta
//
//	 if (Comprobar_Dimensiones_CSV_Fijo(Datos_Algoritmo, Num_Filas_Csv_Info_Algoritmo,
//		 Num_Columnas_Csv_Info_Algoritmo,"Informacion Algoritmo") == ERROR) {
//
//		 printf("Las Dimensiones del CSV de los datows del algoritmo son incorrectas\n");
//		 return ERROR;
//	}
//	
//	 if (Verificar_Encabezados_Algoritmo(Datos_Algoritmo) == ERROR) {
//		 printf("Los encabezados del algoritmo no son correctos \n");
//		 return ERROR;
//	}
//	if ((Verificar_Tipo_Datos_Csv_Algoritmo(Datos_Algoritmo)) == ERROR) {
//		printf("Hay valores incorrectos en el CSV de datos del algoritmo \n");
//		return ERROR;
//	}
//
//	if ((Verificar_Parametros_Temporales(Datos_Algoritmo)) == ERROR) {
//		printf("Los paremtros temporales del algorimto son incorrectos \n");
//		return ERROR;
//	}
//	return EXITO;
//}
//
//
