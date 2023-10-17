
#ifndef validaciones_h
#define validaciones_h

/* include files */

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif
	bool es_un_numero(const wchar_t* str, int permitir_decimal);


#ifdef __cplusplus
}
#endif

#endif