#ifndef RLE_ALL_H
#define RLE_ALL_H

#include <string>

std::string RLE(std::string cadena);
std::string anti_RLE(std::string cadena);
void integrador_RLE(const char* archivoEntrada, const char* archivoSalida, int n, char clave);

#endif // RLE_ALL_H
