//#include "definiciones_Globales.h"
//#include "operaciones_csv.h"
//#include "operaciones_string.h"
//#include "registrar_errores.h"
//#include "tipos_optimizacion.h"
//#include <stdio.h>
//#include <wchar.h>
//Se definen una serie de constantes
//El numero de columnas que ha de
//tener el CSV del precio
//
//El numero de filas que ha de tener 
//el CSV de las columnas.
//
//La primera fila donde comienza la
//informacion
//
//#define NUMERO_COLUMNAS_TIEMPO_PRECIO 4
//#define NUMERO_COLUMNAS_PRECIO        5
//#define NUMERO_MINIMO_FILAS_PRECIO    2
//#define PRIMERA_FILA_CSV_PRECIO       1
//
//#define PRIMERA_COLUMNA               0
//#define FILA_ENCABEZADOS              0
//#define SEGUNDOS_DOS_HORAS            7200
//
//
//
//
//Este subprograma se utiliza para comprobar 
//que los datos de los encabezados son
//correctos.
//
//static int Comprobar_Encabezados_Csv_Precios (datos_csv_precio_t *datos_precio) {
//	
//	Defino variables que indican en que posiciones del csv
//	se encuentra la informacion
//	int fila_encabezados = datos_precio->posiciones_informacion_precio.fila_encabezados;
//	int numero_columnas = datos_precio->informacion_precio.columnas;
//
//	Obtengo el puntero que apunta a la memoria donde se
//	encuentra la informacion relativa a los precios de 
//	la electricidad.
//
//	datos_csv_t* informacion_precio = &(datos_precio->informacion_precio.datos);
//	const wchar_t* encabezados [] = { L"Año",L"Mes",L"Dia",L"Hora",L"Precio kWh"};
//
//	for (int numero_columna = 0; numero_columna < numero_columna; numero_columnas++) {
//
//		if (!strings_iguales(informacion_precio->datos[fila_encabezados][numero_columna], 
//			encabezados[numero_columna])) {
//			
//			char mensaje_error[512];
//			snprintf(mensaje_error, sizeof(mensaje_error), "Error el encabezado en la columna %d",
//			"deberia ser %ls y es %ls", encabezados[numero_columna],
//			informacion_precio->datos[fila_encabezados][numero_columna]);
//			printf("%s\n",mensaje_error);
//			registrar_error(mensaje_error, REGISTRO_ERRORES);
//			return ERROR;
//		}
//	}
//	return EXITO;
//}
//
//Este subprograma se utiliza para comprobar que 
//los datos temporales relacionados con los
//precios son numeros enteros, sin decimales.
//
//static int comprobar_formato_dato_tiempo_precio(Datos_CSV *Datos_Precio, const int Numero_Columna) {
//
//
//	int Numero_Filas = Datos_Precio->Filas;
//
//		for (int Numero_Fila = Primera_Fila_Csv_Precio; Numero_Fila < Numero_Filas; Numero_Fila++) {
//
//			if (!Es_Un_Numero(Datos_Precio->Datos[Numero_Fila][Numero_Columna], Decimal_No_Incluido)) {
//				printf("Error en fila %d, columna %d: Los Datos temporales no pueden tener decimales \n", Numero_Fila + 1, Numero_Columna + 1);
//				return ERROR;
//			}
//
//
//		
//	}
//	return EXITO;
//}
//
//static int Comprobar_Precio(const Datos_CSV *Datos_Precio, const char *Nombre_Archivo) {
//	En este subprograma se comprueba 
//	que el dato de precio en el CSV
//	es correcto, es decir que sea
//	un numero y que ademas no sea
//	negativo.
//
//	Declaro variables auxiliares
//	En una se guarda el precio 
//	en formato string otra en 
//	formato numerico
//	
//	wchar_t*  Precio_String;
//	double Precio_Num;
//
//	int Numero_Filas = Datos_Precio->Filas;
//
//	Se comprueba que:
//	Los precios sean valores numericos.
//	Se pueden convertir a numeros.
//	Que no sean negativos.
//
//	for (int Numero_Fila = 1; Numero_Fila < Numero_Filas; Numero_Fila++) {
//
//		Precio_String = Datos_Precio->Datos[Numero_Fila][Columna_Precio];
//		if ((!Es_Un_Numero(Precio_String, Decimal_Incluido))) {
//			printf("En la fila %d del CSV de %s de los precios hay un precio que no es un numero",Numero_Fila,Nombre_Archivo);
//			return ERROR;
//		}
//		if ((Convertir_A_Decimal(Precio_String,&Precio_Num)) == ERROR) {
//			printf("El precio de la fila %d del Csv de %s no se ha podido convertir a numero correctamente", Numero_Fila,Nombre_Archivo);
//			return ERROR;
//		}
//
//		if (Es_Negativo(Precio_Num)) {
//			printf("El precio de la fila %d del Csv de %s no puede ser negativo", Numero_Fila, Nombre_Archivo);
//			return ERROR;
//		}
//	}
//	return EXITO;
//}
//static int Comprobar_Formato_Precios(const Datos_CSV* Datos_Precio_Compra,const Datos_CSV* Datos_Precio_Venta) {
//	Se comprueba que el formato de dato
//	en el CSV de los precios es correcto
//	Que los datos de tiempo no tengan 
//	decimales.
//	
//
//	for (int Numero_Columna = PRIMERA_COLUMNA; Numero_Columna < Numero_Columnas_Tiempo_Precio; Numero_Columna++) {
//		if (Comprobar_Formato_Dato_Tiempo_Precio(Datos_Precio_Compra, Numero_Columna) == ERROR) {
//			printf("Error en el CSV de los precios de compra \n");
//			return ERROR;
//		}
//		if (Comprobar_Formato_Dato_Tiempo_Precio(Datos_Precio_Venta, Numero_Columna) == ERROR) {
//			printf("Error en el CSV de los precios de venta \n");
//			return ERROR;
//		}
//	}
//	Se pasa a comprobar que:
//	Los precios no son negativos:
//	Son valores numericos.
//
//	if (Comprobar_Precio(Datos_Precio_Compra, "Precio de compra del kilovatio") == ERROR) {
//		return ERROR;
//	}
//	if (Comprobar_Precio(Datos_Precio_Venta, "Precio de venta del kilovatio") == ERROR) {
//		return ERROR;
//	}
//	return EXITO;
//}
//
//static int Comprobar_Dimensiones_Csv_Precios(Datos_CSV * Datos_Precio_Compra, Datos_CSV *Datos_Precio_Venta) {
//	Este subprograma se utiliza para 
//	verificar que el numero de filas
//	y columnas en el csv de los precios
//	son correctos.
//	int Numero_Filas_Precio_Compra    = Datos_Precio_Compra->Filas;
//	int Numero_Columnas_Precio_Compra = Datos_Precio_Compra->Columnas;
//	int Numero_Filas_Precio_Venta     = Datos_Precio_Venta->Filas;
//	int Numero_Columnas_Precio_Venta  = Datos_Precio_Venta->Columnas;
//
//	if (Comprobar_Dimensiones_CSV_Variable(Numero_Filas_Precio_Compra, 
//		Numero_Columnas_Precio_Compra,Numero_Minimo_Filas_Precio, Numero_Columnas_Precio,
//		"Compra") == ERROR) {
//		return ERROR;
//	}
//
//	if (Comprobar_Dimensiones_CSV_Variable(Numero_Filas_Precio_Venta, Numero_Columnas_Precio_Venta,
//		Numero_Minimo_Filas_Precio, Numero_Columnas_Precio,
//		"Venta") == ERROR) {
//		return ERROR;
//	}
//	return EXITO;
//}
//
//static int Comprobar_Fecha_Inicial_Precio(Datos_CSV* Datos_Precios,Datos_CSV *Datos_Algoritmo) {
//	Este subprograma se utiliza para
//	comprobar que la fecha inicial de
//	precio es correcto, es decir que
//	la hora inicial del algoritmo esta 
//	cubierta.
//
//	struct tm Fecha_Inicial_Precio    = { 0 };
//	struct tm Fecha_Inicial_Algoritmo = { 0 };
//
//	Cargar_Fecha(Datos_Precios, &Fecha_Inicial_Precio, Columna_Anyo_Precio,
//		Columna_Mes_Precio, Columna_Dia_Precio, Columna_Hora_Precio,
//		No_Procede,Primera_Fila, No_Incluir_Minuto);
//
//	Cargar_Fecha(Datos_Algoritmo, &Fecha_Inicial_Algoritmo, Columna_Anyo_Inicio_Algoritmo,
//		         Columna_Mes_Inicio_Algoritmo, Columna_Dia_Inicio_Algoritmo,
//		         Columna_Hora_Inicio_Algoritmo, No_Procede,Primera_Fila, No_Incluir_Minuto);
//
//	if (Comprobar_Orden_Fechas(Fecha_Inicial_Precio, Fecha_Inicial_Algoritmo, Incluir_Fecha_Igual) == ERROR) {
//		printf("El primer dato de precios es posterior en el tiempo al inicio del algoritmo \n");
//		printf("La fecha inicial del algoritmo es Año %d Mes %d: Dia %d Hora %d \n",
//			Fecha_Inicial_Algoritmo.tm_year + Offset_Anyo,
//			Fecha_Inicial_Algoritmo.tm_mon  + Offset_Mes,
//			Fecha_Inicial_Algoritmo.tm_mday,
//			Fecha_Inicial_Algoritmo.tm_hour);
//
//		printf("La fecha final del CSV de los precios es Año %d Mes %d Dia%d Hora %d \n",
//			Fecha_Inicial_Precio.tm_year + Offset_Anyo,
//			Fecha_Inicial_Precio.tm_mon  + Offset_Mes,
//			Fecha_Inicial_Precio.tm_mday,
//			Fecha_Inicial_Precio.tm_hour);
//		return ERROR;
//	}
//	return EXITO;
//}
//
//    Este subprograma se utiliza
//	para comprobar que la fecha
//	final del algoritmo esta cubierta
//	en el CSV de los precios
//
//
//static int comprobar_fecha_final_precio(datos_csv_precio_t* datos_precios, datos_csv_algoritmo_t* datos_algoritmo) {
//	
//	struct tm fecha_final_algoritmo = { 0 };
//	struct tm fecha_final_precio    = { 0 };
//
//	Cargo las columnas donde se encuentran la informacion del CSV.
//	
//	int columna_anyo_precio = datos_precios->posiciones_informacion_precio.ubicacion_fecha_precios.columna_anyo;
//	int columna_mes_precio  = datos_precios->posiciones_informacion_precio.
//	 Cargar la fila final del CSV de precios
//	int Fila_Final = Datos_Precios->Filas ;
//
//	Cargar_Fecha(Datos_Precios, &Fecha_Final_Precio, Columna_Anyo_Precio,
//		         Columna_Mes_Precio, Columna_Dia_Precio, Columna_Hora_Precio,
//		         No_Procede,Fila_Final, No_Incluir_Minuto);
//
//	Cargar_Fecha(Datos_Algoritmo, &Fecha_Final_Algoritmo, Columna_Anyo_Final_Algoritmo,
//		         Columna_Mes_Final_Algoritmo, Columna_Dia_Final_Algoritmo,
//		         Columna_Hora_Final_Algoritmo, No_Procede, Primera_Fila, No_Incluir_Minuto);
//
//	if (Comprobar_Orden_Fechas(Fecha_Final_Algoritmo, Fecha_Final_Precio, Incluir_Fecha_Igual) == ERROR) {
//		printf("La fecha final del algoritmo es posterior a la fecha final de los precios disponibles\n");
//		printf("La fecha final del algoritmo es Año %d Mes %d Dia %d Hora %d \n",
//			   Fecha_Final_Algoritmo.tm_year + Offset_Anyo,
//			   Fecha_Final_Algoritmo.tm_mon  + Offset_Mes,
//			   Fecha_Final_Algoritmo.tm_mday,
//			   Fecha_Final_Algoritmo.tm_hour);
//
//		printf("La fecha final del CSV de los precios es Año %d Mes %d Dia%d Hora %d \n",
//			   Fecha_Final_Precio.tm_year + Offset_Anyo,
//			   Fecha_Final_Precio.tm_mon  + Offset_Mes,
//			   Fecha_Final_Precio.tm_mday,
//			   Fecha_Final_Precio.tm_hour);
//		
//		return ERROR;
//	}
//	return EXITO;
//}
///*
//* En este subprograma se imprime que error ha habido con el precio de entrada
//* y se guarda en el registro.log de errores.
//*/
//static void imprimir_mensaje_error_precio (const struct tm fecha_1_temp, const struct tm fecha_2_temp) {
//	printf("Los precios no son consecutivos \n");
//	printf("La fecha del primer precio es Año %d Mes %d Dia %d Hora %d \n",
//	fecha_1_temp.tm_year + DESPLAZAMIENTO_ANYO,
//	fecha_1_temp.tm_mon  + DESPLAZAMIENTO_MES,
//	fecha_1_temp.tm_mday,
//	fecha_1_temp.tm_hour);
//	printf("La fecha del segundo precio es Año %d Mes %d Dia %d Hora %d \n",
//	fecha_2_temp.tm_year + DESPLAZAMIENTO_ANYO,
//	fecha_2_temp.tm_mon  + DESPLAZAMIENTO_MES,
//	fecha_2_temp.tm_mday,
//	fecha_2_temp.tm_hour);
//
//	char mensaje_error[512];
//	snprintf(mensaje_error, sizeof(mensaje_error), "Error los precios no son consecutivos",
//	"la fecha del primer precio es año  %d mes %d dia %d hora %d\n",
//	"la fecha del segundo precio es año %d mes %d dia %d hora %d\n",
//	fecha_1_temp.tm_year + DESPLAZAMIENTO_ANYO, fecha_1_temp.tm_mon + DESPLAZAMIENTO_MES,
//	fecha_1_temp.tm_mday, fecha_1_temp.tm_hour,
//	fecha_2_temp.tm_year + DESPLAZAMIENTO_ANYO, fecha_2_temp.tm_mon + DESPLAZAMIENTO_MES,
//	fecha_2_temp.tm_mday, fecha_2_temp.tm_hour);
//
//	registrar_error(mensaje_error,REGISTRO_ERRORES);
//     
//}
//
//    Este subprograma se utiliza para comprobar 
//	que las dos fechas de entrada solo se llevan
//	una hora de diferencia.
//
//static int comprobar_consecutividad_horas(const struct tm fecha_1, const struct tm fecha_2) {
//
//	struct tm fecha_1_temp = fecha_1;
//	struct tm fecha_2_temp = fecha_2;
//
//	time_t fecha_1_normalizada = mktime(&fecha_1_temp);
//	time_t fecha_2_normalizada = mktime(&fecha_2_temp);
//
//	double diferencia_tiempo = difftime(fecha_1_normalizada, fecha_2_normalizada);
//
//	Se revisa que en la fecha
//	que se esta comprobando 
//	no coincida con un dia 
//	que hay un cambio de hora->
//
//	if (fecha_1_temp.tm_isdst != fecha_2_temp.tm_isdst) {
//	Si hay una trancision
//	de cambio de hora
//	puede haber un tramo horario
//	que no exista.
//
//	if (abs(diferencia_tiempo) <= SEGUNDOS_DOS_HORAS) {
//	return EXITO;
//	}
//	else{
//		imprimir_mensaje_error_precio(fecha_1_temp, fecha_2_temp);
//	return ERROR;
//	}
//	}
//	else if (diferencia_tiempo != SEGUNDOS_DOS_HORAS) {
//		imprimir_mensaje_error_precio(fecha_1_temp, fecha_2_temp);
//		return ERROR;
//	}
//
//	return EXITO;
//}
//
//
//    En este subprograma se comprueba
//	que los datos del CSV de los precios
//	sean en horas consecutivas->
//
//static int comprobar_consecutividad_precios(datos_csv_precio_t* datos_precio) {
//	
//	Creo el puntero que apunta a la posicion de memoria donde se encuentra
//	la informacion del precio
//	datos_csv_t* informacion_precio = &(datos_precio->informacion_precio);
//
//	Cargo las filas y columnas donde se encuentra la informacion
//	int columna_anyo_precio = datos_precio->posiciones_informacion_precio.ubicacion_fecha_precios.columna_anyo;
//	int columna_mes_precio = datos_precio->posiciones_informacion_precio.ubicacion_fecha_precios.columna_mes;
//	int columna_dia_precio = datos_precio->posiciones_informacion_precio.ubicacion_fecha_precios.columna_dia;
//	int columna_hora_precio = datos_precio->posiciones_informacion_precio.ubicacion_fecha_precios.columna_hora;
//
//
//	Cargo el numero de filas->
//	int numero_filas = datos_precio->informacion_precio.filas;
//
//	Si solo se tiene una fila con datos
//	no es necesario comprobar la consecutividad
//	ya que solo hay una hora.
//	
//	struct tm fecha_1 = { 0 };
//	struct tm fecha_2 = { 0 };
//
//	Se itera por todas las filas 
//	del CSV
//	for (int numero_fila = 1; numero_fila < numero_filas - 1; numero_fila++) {
//
//	cargar_fecha(informacion_precio, &fecha_1, columna_anyo_precio,
//	columna_mes_precio, columna_dia_precio,
//	columna_hora_precio, NO_PROCEDE, numero_fila,
//	NO_INCLUIR_MINUTO);
//
//	cargar_fecha(datos_precio, &fecha_2, columna_anyo_precio,
//	columna_mes_precio, columna_dia_precio,
//    columna_hora_precio, NO_PROCEDE, numero_fila+1,
//	NO_INCLUIR_MINUTO);
//
//	if (Comprobar_Consecutividad_Horas(fecha_1, fecha_2) == ERROR) {
//	printf("Las fechas no son consecutivas \n");
//	return ERROR;
//			}
//	   }
//	return EXITO;
//	}
//
//
//static int comprobar_fecha_precios(datos_csv_precio_t *datos_precio_compra, datos_csv_precio_t *datos_precio_venta,
//	                               datos_csv_precio_t *datos_algoritmo) {
//	En este subprograma se comprueba que
//	la fecha a las que estan asociadas los
//	precios tienen sentido.
//	
//	Se comprueba que:
//	1.Todas las horas de ejecucion del 
//	Algoritmo tienen un precio asociado.
//	2.Los precios estan en orden cronologico.
//
//	if (comprobar_fecha_inicial_precio(datos_precio_compra, datos_algoritmo) == ERROR) {
//		printf("En el CSV de compra el algoritmo empieza antes que el primer precio\n");
//		return ERROR;
//	}
//
//	if (comprobar_fecha_inicial_precio(datos_precio_venta, datos_algoritmo) == ERROR) {
//		printf("En el CSV de venta el algoritmo empieza antes que el primer precio\n");
//		registrar_error("En el CSV de venta el algoritmo empieza antes que el primer precio\n",REGISTRO_ERRORES);
//		return ERROR;
//	}
//
//	if (comprobar_fecha_final_precio(datos_precio_compra, datos_algoritmo) == ERROR) {
//		printf("En el CSV de compra el algoritmo termina más tarde que el ultimo precio\n");
//		registrar_error("En el CSV de compra el algoritmo termina más tarde que el ultimo precio", REGISTRO_ERRORES);
//		return ERROR;
//	}
//	if (comprobar_fecha_final_precio(datos_precio_venta, datos_algoritmo) == ERROR) {
//		printf("En el CSV de venta el algoritmo termina más tarde que el ultimo precio\n");
//		registrar_error("En el CSV de venta el algoritmo termina más tarde que el ultimo precio\n", REGISTRO_ERRORES);
//		return ERROR;
//	}
//
//	if (comprobar_consecutividad_precios(datos_precio_compra) == ERROR ){
//		printf("Los precios no son consecutivos en el CSV de los precios de compra\n");
//		registrar_error("Los precios no son consecutivos en el CSV de los precios de compra\n", REGISTRO_ERRORES);
//		return ERROR;
//		}
//
//	if (comprobar_consecutividad_precios(datos_precio_venta) == ERROR) {
//		printf("Los precios no son consecutivos en el CSV de los precios de venta\n");
//		registrar_error("Los precios no son consecutivos en el CSV de los precios de venta\n", REGISTRO_ERRORES);
//		return ERROR;
//	}
//	return EXITO;
//}
//
//    Este subprograma se utiliza para comprobar
//	que los encabezados del CSV de los precios
//	son los correctos-> Primero se definen los
//	valores de estos encabezados y despues se 
//	llama al subprograma que comprueba que los
//	encabezados del CSV coinciden.
//
//
//int comprobar_encabezados_precios(datos_csv_precio_t *datos_precio_compra,datos_csv_precio_t *datos_precio_venta) {
//
//	
//
//	const wchar_t* valores_aceptables[] = { L"Año",L"Mes",L"Dia",L"Hora",L"Precio kWh" };
//	const int numero_encabezados = sizeof(valores_aceptables) / sizeof(valores_aceptables[0]);
//	datos_csv_t* informacion_precio = &(datos_precio_compra->informacion_precio);
//	
//	if (verificar_encabezado_csv(informacion_precio, valores_aceptables,
//		numero_encabezados, "Datos de los Precios de compra") == ERROR) {
//		printf("Los encabezados del CSV de los precios de compra son incorrectos\n");
//		return ERROR;
//	}
//
//    if (verificar_encabezado_csv(informacion_precio, valores_aceptables,
//	numero_encabezados, "Datos de los Precios de Venta") == ERROR) {
//	printf("Los encabezados del CSV de los precios de venta son incorrectos\n");
//	return ERROR;
//    }
//
//
//    return EXITO;
//
//}
//
//    Este subprograma se utiliza para
//	verificar que los datos de los 
//	precios en el csv que contiene
//	los datos de los precios son 
//	correctos->
//
//	Para ello se comprueba que:
//	1.El numero de filas y 
//	columnas es correcto.
//	2.Los datos del Csv tienen
//	sentido. (Son datos numericos)
//	y no hay precios negativos.
//	3.El orden cronologio de los 
//	precios tiene sentido.
//
//int verificar_precios(datos_csv_precio_t* datos_precio_compra,datos_csv_precio_t *datos_precio_venta,
//	                  datos_csv_algoritmo_t* datos_algoritmo) {
//	
//
//
//	if (comprobar_dimensiones_csv_precios(datos_precio_compra, datos_precio_venta) == ERROR) {
//		return ERROR;
//	}
//	if (comprobar_encabezados_precios(datos_precio_compra,datos_precio_venta)==ERROR) {
//		return ERROR;
//	}
//	if (comprobar_formato_precios(datos_precio_compra, datos_precio_venta) == ERROR) {
//		return ERROR;
//	}
//	
//	if (comprobar_fecha_precios(datos_precio_compra, datos_precio_venta, datos_algoritmo) == ERROR) {
//		return ERROR;
//	}
//	return EXITO;
//
//}