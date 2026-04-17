#ifndef LZ78_ALL_H
#define LZ78_ALL_H

#include "Entry.h"

int largo(const char* arr);
char* lz78(char* input);
char* anti_lz78(char* entrada);
void integrador_LZ78(const char* archivoEntrada, const char* archivoSalida, int n);

#endif // LZ78_ALL_H
