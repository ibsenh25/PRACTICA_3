#include <iostream>
#include "ENCRI_DESIN.h"
#include "LZ78_ALL.h"
using namespace std;

char* rotar_bits(const char* entrada, int n) {
    int len = largo(entrada);
    char* salida = new char[len + 1];

    for (int i = 0; i < len; i++) {
        unsigned char c = entrada[i];
        salida[i] = ((c << n) | (c >> (8 - n))) & 0xFF;
    }
    salida[len] = '\0';

    return salida;
}

char* xor_cadena(const char* entrada, char clave) {
    int len = largo(entrada);
    char* salida = new char[len + 1];

    for (int i = 0; i < len; i++) {
        salida[i] = entrada[i] ^ clave;
    }
    salida[len] = '\0';

    return salida;
}

char* anti_rotar(const char* entrada, int n) {
    int len = largo(entrada);
    char* salida = new char[len + 1];

    for (int i = 0; i < len; i++) {
        unsigned char c = entrada[i];
        salida[i] = ((c >> n) | (c << (8 - n))) & 0xFF;
    }
    salida[len] = '\0';

    return salida;
}

char* anti_xor(const char* entrada, char clave) {
    return xor_cadena(entrada, clave);
}


string rotar_RLE(const string& entrada, int n) {
    int len = entrada.length();
    string salida;
    salida.resize(len);

    for (int i = 0; i < len; i++) {
        unsigned char c = entrada[i];
        salida[i] = ((c << n) | (c >> (8 - n))) & 0xFF;
    }

    return salida;
}

string xor_RLE(const string& entrada, char clave) {
    int len = entrada.length();
    string salida;
    salida.resize(len);

    for (int i = 0; i < len; i++) {
        salida[i] = entrada[i] ^ clave;
    }

    return salida;
}

string anti_rotar_RLE(const string& entrada, int n) {
    int len = entrada.length();
    string salida;
    salida.resize(len);

    for (int i = 0; i < len; i++) {
        unsigned char c = entrada[i];
        salida[i] = ((c >> n) | (c << (8 - n))) & 0xFF;
    }

    return salida;
}

string anti_xor_RLE(const string& entrada, char clave) {
    return xor_RLE(entrada, clave);
}
