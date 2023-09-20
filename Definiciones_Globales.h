
#ifndef DEFINICIONES_GLOBALES_H
#define DEFINICIONES_GLOBALES_H

//En este archivo se definen constantes que se van a usar 
// por todo el codigo->

//Constantes para los codigos de error del main

#define Salida_Error 1 
//Una constante para el subprograma que compara
//las fechas

#define No_Incluir_Fecha_Igual 0 
#define Incluir_Fecha_Igual    1

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

#define No_Incluir_Minuto        0
#define Si_Incluir_Minuto        1
//Numero de segundos que hay en una hora->

#define Segundos_Hora           3600
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
#define Columna_Resolucion_Tiempo_Simulacion 10 

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

//Defino la fila donde se encuentran los
//encabezados en los CSVs
#define Fila_Encabezados 0

//Defino las columnas donde se encuentra
//la informacion en el CSV de los vehiculos
#define Columna_Csv_Vehiculos_Terminal         0
#define Columna_Csv_Vehiculos_Modo_Carga       1
#define Columna_Csv_Vehiculos_Capacidad        2
#define Columna_Csv_Vehiculos_Bateria_Inicial  3
#define Columna_Csv_Vehiculos_Bateria_Final    4
#define Columna_Csv_Vehiculos_Maxima_Potencia  5
#define Columna_Csv_Vehiculos_Anyo_Inicial     6
#define Columna_Csv_Vehiculos_Mes_Inicial      7
#define Columna_Csv_Vehiculos_Dia_Inicial      8
#define Columna_Csv_Vehiculos_Hora_Inicial     9
#define Columna_Csv_Vehiculos_Minuto_Inicial   10 
#define Columna_Csv_Vehiculos_Anyo_Final       11
#define Columna_Csv_Vehiculos_Mes_Final        12
#define Columna_Csv_Vehiculos_Dia_Final        13
#define Columna_Csv_Vehiculos_Hora_Final       14
#define Columna_Csv_Vehiculos_Minuto_Final     15

//Defino la informacion donde se encuentra la
//informacion en el CSV de los vehiculos
#define Columna_Csv_Baterias_Terminal               0 
#define Columna_Csv_Baterias_Objetivo_Carga         1 
#define Columna_Csv_Baterias_Capacidad              2
#define Columna_Csv_Baterias_Bateria_Inicial        3
#define Columna_Csv_Baterias_Bateria_Final          4
#define Columna_Csv_Baterias_Maxima_Potencia        5
#define Columna_Csv_Baterias_Anyo_Inicial           6
#define Columna_Csv_Baterias_Mes_Inicial            7
#define Columna_Csv_Baterias_Dia_Inicial            8
#define Columna_Csv_Baterias_Hora_Inicial           9
#define Columna_Csv_Baterias_Minuto_Inicial         10 
#define Columna_Csv_Baterias_Anyo_Final             11
#define Columna_Csv_Baterias_Mes_Final              12
#define Columna_Csv_Baterias_Dia_Final              13
#define Columna_Csv_Baterias_Hora_Final             14
#define Columna_Csv_Baterias_Minuto_Final           15


#endif
