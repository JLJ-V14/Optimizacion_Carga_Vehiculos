
#ifndef DEFINICIONES_GLOBALES_H
#define DEFINICIONES_GLOBALES_H

//En este archivo se definen constantes que se van a usar 
// por todo el codigo->

//Constantes para los codigos de error del main

#define SALIDA_ERROR 1 
//Una constante para el subprograma que compara
//las fechas

#define NO_INCLUIR_FECHA_IGUAL 0 
#define INCLUIR_FECHA_IGUAL    1

//Constantes relacionadas con el subprograma que
//obtiene si los datos del CSV son numeros 

#define Decimal_Incluido      0
#define Decimal_No_Incluido   1



//Constantes relacionadas con el uso de la libreria
//time .h

//Una constante para rellenar informacion
//en un campo que no proceda
//Defino ademas 
#define Primera_Fila             1
#define No_Procede              -1
//Defino si se incluye el minuto en una fecha
// o no

#define NO_INCLUIR_MINUTO        0
#define SI_INCLUIR_MINUTO        1
//Numero de segundos que hay en una hora->

#define Segundos_Hora           3600
//En esta libreria los años van a partir de 1900
//y los meses a partir de 0. Luego hay que restar
//esas cantidades.

#define DESPLAZAMIENTO_ANYO 1900
#define DESPLAZAMIENTO_MES  1

//Constantes para los valores que retornan las funciones
//tipo int.

typedef enum {
    EXITO,
    ERROR
} Resultado;

//Defino las filas y columnas en donde se encuentran los 
//diferentes datos de entrada en los diferentes CSVS.
// 
//Datos_Algoritmo:
#define Num_Columnas_Csv_Info_Algoritmo 11
#define Num_Filas_Csv_Info_Algoritmo    2





//Defino donde se encuentra los distintos tipos
//de informacion en el CSV de los precios

#define Columna_Anyo_Precio    0
#define Columna_Mes_Precio     1
#define Columna_Dia_Precio     2
#define Columna_Hora_Precio    3
#define Columna_Precio         4

//Defino donde se encuentra la informacion en el CSV de las restricciones->
#define Primera_Columna_Datos_Restricciones 1
#define Fila_Informacion_Csv_Restricciones  1

//Se define informacion relacionada con los
//terminales de la placa de redistribucion.
#define Numero_Terminales 12
#define  Columna_Numero_Terminal 0
#define  Columna_Fase            1







//Se define el nombre de los archivos.csv que
//contienen la informacion de entrada

#define INFORMACION_TERMINALES            "Informacion_Terminales.csv"
#define INFORMACION_VEHICULOS             "Informacion_Vehiculos.csv"
#define INFORMACION_BATERIAS              "Informacion_Baterias.csv"
#define INFORMACION_ALGORITMO             "Informacion_Algoritmo.csv"
#define INFORMACION_PRECIO_COMPRA         "Precio_Compra_Kilovatio.csv"
#define INFORMACION_PRECIO_VENTA          "Precio_Venta_Kilovatio.csv"
#define INFORMACION_RESTRICCIONES_SISTEMA "Restricciones_Sistema.csv"
#define REGISTRO_ERRORES                  "registro_errores.log"




#endif
