
#pragma warning  (disable: 6001)  //Deshabilitar advertencia 6001
#include <stdlib.h>
#include "Tipos_Optimizacion.h"

void Liberar_Memoria_Csv (Datos_CSV* Datos_Excel) {
    //Este subprograma se utiliza para liberar la memoria
    //reservada a almacenar la informacion del CSV.

    int Numero_Filas = Datos_Excel->Filas;
    int Numero_Columnas = Datos_Excel->Columnas;

    for (int i = 0; i < Numero_Filas; i++) {
        for (int j = 0; j < Numero_Columnas; j++) {
            free(Datos_Excel->Datos[i][j]);
        }
        free(Datos_Excel->Datos[i]);
    }
    free(Datos_Excel->Datos);
    Datos_Excel->Filas = 0;
    Datos_Excel->Columnas = 0;
}
void Liberar_Memoria_Csvs(Datos_CSV* Datos_Vehiculos, Datos_CSV* Datos_Algoritmo,
    Datos_CSV* Datos_Baterias, Datos_CSV* Datos_Precio_Compra,
    Datos_CSV* Datos_Precio_Venta, Datos_CSV* Restricciones_Sistema,
    Datos_CSV* Datos_Terminales) {

    //Este subprograma se utiliza para reservar espacio en memoria para 
    //los datos que se leen de los CSVs

    Liberar_Memoria_Csv(Datos_Vehiculos);
    Liberar_Memoria_Csv(Datos_Algoritmo);
    Liberar_Memoria_Csv(Datos_Baterias);
    Liberar_Memoria_Csv(Datos_Precio_Compra);
    Liberar_Memoria_Csv(Datos_Precio_Venta);
    Liberar_Memoria_Csv(Restricciones_Sistema);

}