#ifndef RLE_ALL_H
#define RLE_ALL_H

#include <string>

std::string RLE(std::string cadena);
std::string anti_RLE(std::string cadena);
std::string verificar_des(std::string cadena);
void integrador_RLE(const char* archivoEntrada, const char* archivoSalida, int n);

#endif // RLE_ALL_H
