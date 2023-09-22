
//En este subprograma se encuentran
//las funciones auxiliares relacionadas 
//con operar las fechas.

#include "Definiciones_Globales.h"
#include "Tipos_Optimizacion.h"
#include <stdio.h>
#include <time.h>

#define Base_Numero 10 //Se convierte los numeros al sistema decimal.

void Cargar_Fecha_Algoritmo(Datos_CSV* Datos_Algoritmo, struct tm* Fecha_Inicial_Algoritmo,
	struct tm* Fecha_Final_Algoritmo) {
	//Este subprograma se utiliza para 
	//cargar la fecha de inicio y finalizacion
	//del Algoritmo en dos variables.

	Cargar_Fecha(Datos_Algoritmo, Fecha_Inicial_Algoritmo, Columna_Anyo_Inicio_Algoritmo,
		Columna_Mes_Inicio_Algoritmo, Columna_Dia_Inicio_Algoritmo, Columna_Hora_Inicio_Algoritmo,
		Columna_Minuto_Inicio_Algoritmo, Fila_Datos_Algoritmo, Si_Incluir_Minuto);


	Cargar_Fecha(Datos_Algoritmo, Fecha_Final_Algoritmo, Columna_Anyo_Final_Algoritmo,
		Columna_Mes_Final_Algoritmo, Columna_Dia_Final_Algoritmo, Columna_Hora_Final_Algoritmo,
		Columna_Minuto_Final_Algoritmo, Fila_Datos_Algoritmo, Si_Incluir_Minuto);

}

void Cargar_Fecha_Carga(Datos_CSV* Datos_Carga, struct tm* Fecha_Inicial_Carga,
	struct tm* Fecha_Final_Carga, const int Numero_Fila) {

	//Este subprograma se utiliza para 
	//cargar la fecha de inicio o
	//finalizacion de un vehiculo 
	//o bateria.

	Cargar_Fecha(Datos_Carga, Fecha_Inicial_Carga, Columna_Csv_Carga_Anyo_Inicial,
		Columna_Csv_Carga_Mes_Inicial, Columna_Csv_Carga_Dia_Inicial,
		Columna_Csv_Carga_Hora_Inicial, Columna_Csv_Carga_Minuto_Inicial,
		Numero_Fila, Si_Incluir_Minuto);

	Cargar_Fecha(Datos_Carga, Fecha_Final_Carga, Columna_Csv_Carga_Anyo_Final,
		Columna_Csv_Carga_Mes_Final, Columna_Csv_Carga_Dia_Final,
		Columna_Csv_Carga_Hora_Final, Columna_Csv_Carga_Minuto_Final,
		Numero_Fila, Si_Incluir_Minuto);
}

int Comprobar_Fecha_Carga(struct tm Fecha_Inicial_Algoritmo, struct tm Fecha_Final_Algoritmo,
	struct tm Fecha_Inicial_Carga, struct tm Fecha_Final_Carga) {

	//Para un vehiculo o bateria se comprueba que:
	//Las fechas de inicio y finalizacion de carga 
	//estan dentro de la ventana temporal del algoritmo
	//La fecha de inicio y finalizacion tienen sentido 
	//es decir la fecha de finalizacion es posterior a 
	//la de inicio.

	if (Comprobar_Orden_Fechas(Fecha_Inicial_Algoritmo, Fecha_Inicial_Carga,
		Incluir_Fecha_Igual) == ERROR) {
		printf("Error la carga del vehiculo no puede empezar "
			"antes que el inicio del algoritmo\n");
		return ERROR;
	}
	if (Comprobar_Orden_Fechas(Fecha_Final_Carga, Fecha_Final_Algoritmo,
		Incluir_Fecha_Igual) == ERROR) {
		printf("Error la carga del vehiculo no puede terminar más tarde"
			"que el fin del algoritmo\n");
		return ERROR;
	}
	if (Comprobar_Orden_Fechas(Fecha_Inicial_Carga, Fecha_Final_Carga,
		Incluir_Fecha_Igual) == ERROR) {
		printf("Error la fecha de inicio de la carga debe ser"
			"anterior a la fecha del posterior\n");
		return ERROR;
	}
	return EXITO;
}
int Verificar_Fecha_Carga(Datos_CSV* Datos_Carga, Datos_CSV* Datos_Algoritmo,
	const int Numero_Fila) {
	//Este subprograma se utiliza
	//para verificar que la fecha
	//de carga de un vehiculo o 
	//bateria es correcta.

	//Para un vehiculo o bateria se comprueba que:
	//Las fechas de inicio y finalizacion de carga 
	//estan dentro de la ventana temporal del algoritmo
	//La fecha de inicio y finalizacion tienen sentido 
	//es decir la fecha de finalizacion es posterior a 
	//la de inicio.

	//Las entradas para este subprograma son:

	//1. Los datos del CSV que contiene la informacion 
	//de los vehiculos o baterias,
	//2. El CSV que contiene la informacion del algoritmo
	//3. El numero de fila del CSV de los vehiculos o baterias
	//en otras palabras el numero de vehiculo o bateria a revisar

	struct tm Fecha_Inicial_Algoritmo = { 0 };
	struct tm Fecha_Final_Algoritmo = { 0 };
	struct tm Fecha_Inicial_Carga = { 0 };
	struct tm Fecha_Final_Carga = { 0 };

	Cargar_Fecha_Algoritmo(Datos_Algoritmo, &Fecha_Inicial_Algoritmo,
		&Fecha_Final_Algoritmo);

	Cargar_Fecha_Carga(Datos_Carga, &Fecha_Inicial_Carga,
		&Fecha_Final_Carga, Numero_Fila);

	//Se pasa a comprobar que el orden de fechas es correcto
	if (Comprobar_Fecha_Carga(Fecha_Inicial_Algoritmo,
		Fecha_Final_Algoritmo, Fecha_Inicial_Carga,
		Fecha_Final_Carga) == ERROR) {
		return ERROR;
	}
	return EXITO;
}



void Cargar_Fecha(const Datos_CSV* Datos_Entrada, struct tm* Fecha, const int Columna_Csv_Anyo,
	const int Columna_Csv_Mes, const int Columna_Csv_Dia, const int Columna_Csv_Hora,
	const int Columna_Csv_Minuto, const int Numero_Fila, const int Incluir_Minuto) {

	//Este subprograma se utiliza para cargar 
	//la informacion de una fecha de un CSV.


	Fecha->tm_year = wcstol(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Anyo], NULL,Base_Numero) - Offset_Anyo;
	Fecha->tm_mon = wcstol(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Mes], NULL,Base_Numero) - Offset_Mes;
	Fecha->tm_mday = wcstol(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Dia], NULL,Base_Numero);
	Fecha->tm_hour = wcstol(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Hora], NULL,Base_Numero);
	Fecha->tm_sec = 0;
	//Este campo sirve para detectar si la fecha es un
	//dia de cambio de hora.
	Fecha->tm_isdst = -1;

	if (Incluir_Minuto) {
		Fecha->tm_min = wcstol(Datos_Entrada->Datos[Numero_Fila][Columna_Csv_Minuto], NULL, 10);
	}
	else {
		Fecha->tm_min = 0;
	}
}




int  Comprobar_Orden_Fechas(const struct tm Fecha_Anterior, const struct tm Fecha_Posterior,
	const int    Incluir_Igual) {
	//Este subprograma se utiliza para 
	//comprobar si el orden de dos fechas
	//es correcto, si la fecha anterior es
	//efectivamente anterior al parametro de
	//entrada denominado fecha posterior, se 
	//devuelve un 0, lo que significa que es 
	//correcto, si no es un -1.

	//Se incluye un parametro adicional (Incluir_Igual)
	//que sirve para diferenciar si se permite que 
	//la fecha anterior y posterior coincidan


	struct tm Fecha_Anterior_Aux = Fecha_Anterior;
	struct tm Fecha_Posterior_Aux = Fecha_Posterior;
	time_t    Tiempo_Anterior, Tiempo_Posterior;

	Tiempo_Anterior = mktime(&Fecha_Anterior_Aux);
	Tiempo_Posterior = mktime(&Fecha_Posterior_Aux);

	if ((Tiempo_Anterior == -1) || (Tiempo_Posterior == -1)) {
		return ERROR;
	}

	if (Tiempo_Anterior < Tiempo_Posterior) {
		return EXITO;
	}

	return (Tiempo_Anterior == Tiempo_Posterior) && 
	(Incluir_Igual == Incluir_Fecha_Igual) ? EXITO : ERROR;


}
