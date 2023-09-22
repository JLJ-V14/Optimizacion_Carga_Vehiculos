#include <stdio.h>
#include <stdlib.h>

void Registrar_Error(const char* Msg, const char* filename) {
    // Este subprograma se utiliza para 
    // registrar los errores en un archivo
    //de tipo log.

    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Error: %s\n", Msg);
    fclose(file);
}


