
#include "Definiciones_Globales.h"
#include "Tipos_Optimizacion.h"

static int Comprobar_Dimension_CSV_Restricciones(Datos_CSV * Datos_Restricciones) {
	//Este subprograma se utiliza
	//para verificar que las dimensiones
	//del CSV de las restricciones son
	//correctas.

	int Numero_Columnas = Datos_Restricciones->Columnas;
	int Numero_Filas    = Datos_Restricciones->Filas;
	if ((Numero_Columnas != Numero_Columnas_Csv_Restricciones) || (Numero_Filas != Numero_Filas_Csv_Restricciones)) {
		printf("Error el csv de las restricciones ha de tener %d columnas y %d filas \n",
	    Numero_Columnas_Csv_Restricciones,Numero_Filas_Csv_Restricciones);
		return ERROR;
	}
	return EXITO;
}

int Verificar_Datos_Restricciones(Datos_CSV* Datos_Restricciones) {
	//Este subprograma se utiliza
	//para verificar que los datos
	//en el CSV de las restricciones
	//son correctas->


}