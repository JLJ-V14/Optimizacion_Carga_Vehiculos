#ifndef PORTABILIDAD_H
#define PORTABILIDAD_H

//Se utiliza este subprograma para
//hacer que las funciones usadas
//sean validas tanto en windows como
//en Linux.


/* Include files */

#include <stddef.h>
#include <stdlib.h>

#ifdef _WIN32
#define strcasecmp _stricmp
#define wcsdup _wcsdup
#endif


#ifdef __cplusplus
extern "C" {
#endif

	/* Add your function declarations here */


#ifdef __cplusplus
}
#endif

#endif
