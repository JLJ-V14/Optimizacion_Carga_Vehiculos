//
//bool Comprobar_Porcentaje_Bateria(const double Porcentaje_Bateria) {
//	//Este subprograma se utiliza para
//	//comprobar que el porcentaje de 
//	//bateria se encuentra entre 0 y 1
//
//	return ((Porcentaje_Bateria >= 0) && (Porcentaje_Bateria <= 1));
//}
//
//int Verificar_Numero_Terminal(const wchar_t* Numero_Terminal, const int Numero_Fila) {
//	//Este subprograma se utiliza
//	//para verificar que el dato 
//	//de terminal es correcto.
//
//	//Se comprueba que el numero 
//	//del terminal esté dentro del 
//	//rango y que sea un dato numerico
//	//no decimal.
//
//	if (!Es_Un_Numero(Numero_Terminal, Decimal_No_Incluido)) {
//		printf("El numero de Terminal en la fila %d no es un numero natural\n", Numero_Fila);
//		return ERROR;
//	}
//	int Num_Terminal = 0;
//
//	if (Convertir_A_Entero(Numero_Terminal, &Num_Terminal) == ERROR) {
//		printf("El Dato del terminal no se pudo convertir a dato numerico\n");
//		return ERROR;
//	}
//
//
//	if ((Num_Terminal < 1) || (Num_Terminal > Numero_Terminales)) {
//		printf("Error el numero de terminales ha de estar entre 1 y"
//			"%d en el CSV de los vehiculos\n", Numero_Terminales);
//		return ERROR;
//	}
//	return EXITO;
//}
//
//bool  Es_Negativo(double Numero) {
//	//Este subprograma se utiliza
//	//para comprobar si un numero
//	//es negativo
//
//	return Numero < 0;
//}
//bool Es_Un_Numero(const wchar_t* str, int Permitir_Decimal) {
//	//Este subprograma se utiliza para 
//	//comprobar si el dato del csv leido
//	//es un numero o no. Ademas se 
//	//diferencia si el numero leido 
//	//puede tener decimales o no.
//
//	int Numero_Puntos = 0;
//
//	for (int i = 0; str[i] != '\0'; i++) {
//		if (!isdigit(str[i])) {
//			if (Permitir_Decimal && str[i] == '.' && Numero_Puntos++ == 0) {
//				continue;
//			}
//			return false; // No es un numero
//		}
//	}
//	return true;
//
//}
