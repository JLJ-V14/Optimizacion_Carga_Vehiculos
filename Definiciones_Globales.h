
#ifndef DEFINICIONES_GLOBALES_H
#define DEFINICIONES_GLOBALES_H

//En este archivo se definen constantes que se van a usar por todo el codigo->

//Constantes relacionadas con el uso de la libreria
//time .h

//En esta libreria los años van a partir de 1900
//y los meses a partir de 0. Luego hay que restar
//esas cantidades.

#define Offset_Anyo 1900
#define Offset_Mes  1

//Constantes para los valores que retornan las funciones
//tipo int.
#define EXITO  0
#define ERROR -1
//Defino las filas y columnas en donde se encuentran los 
//diferentes datos de entrada en los diferentes CSVS.
// 
//Datos_Algoritmo:
#define Num_Columnas_Csv_Info_Algoritmo 11
#define Num_Filas_Csv_Info_Algoritmo    2
//Defino la fila donde se encuentran los datos.
#define Fila_Datos_Algoritmo 1   

//Defino las columnas en donde se encuentran 
//los diferentes tipos de datos del algoritmo
#define Columna_Anyo_Inicio_Algoritmo   0
#define Columna_Mes_Inicio_Algoritmo    1
#define Columna_Dia_Inicio_Algoritmo    2
#define Columna_Hora_Inicio_Algoritmo   3
#define Columna_Minuto_Inicio_Algoritmo 4
#define Columna_Anyo_Final_Algoritmo    5
#define Columna_Mes_Final_Algoritmo     6
#define Columna_Dia_Final_Algoritmo     7
#define Columna_Hora_Final_Algoritmo    8
#define Columna_Minuto_Final_Algoritmo  9
#define Columna_Delta_Tiempo_Simulacion 10 
#endif
