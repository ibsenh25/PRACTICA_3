#ifndef ENCRI_DESIN_H
#define ENCRI_DESIN_H

#include <string>

char* rotar_bits(const char* entrada, int n);
char* xor_cadena(const char* entrada);
char* anti_rotar(const char* entrada, int n);
char* anti_xor(const char* entrada);

std::string rotar_RLE(const std::string& entrada, int n);
std::string xor_RLE(const std::string& entrada);
std::string anti_rotar_RLE(const std::string& entrada, int n);
std::string anti_xor_RLE(const std::string& entrada);

#endif // ENCRI_DESIN_H
