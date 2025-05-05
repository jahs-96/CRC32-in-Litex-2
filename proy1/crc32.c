#include <string.h>
#include <stddef.h>
#include <stdint.h>
// Llamado de los encabezados propios
#include "crc32.h"

// Declaracion de la funcion en ensamblador del codigo
extern uint32_t my_crc32_asm(const void  *puntero, int longi);

// Obtiene la palabra y cuenta la cantidad de caracteres presentes; despues se lo pasa al ensamblador
uint32_t my_crc32(const char *palabra) {
    
    int longi = strlen(palabra);

    // Entrada al ensamblador
    return my_crc32_asm(palabra, longi);

}
