#include <iostream>
#include <fstream>
#include "Archivos.h"
#include "LZ78_ALL.h"
#include "excepciones.h"
using namespace std;

char* leerArchivo(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw ERR_LECTURA;
    }

    string contenido;
    string linea;
    while (getline(archivo, linea)) {
        contenido += linea + "\n";
    }
    archivo.close();

    if (contenido.empty()) {
        throw ERR_VACIO;
    }

    // Copiar a char*
    char* buffer = new char[contenido.length() + 1];
    for (size_t i = 0; i < contenido.length(); i++) {
        buffer[i] = contenido[i];
    }
    buffer[contenido.length()] = '\0';

    return buffer;
}

void escribirArchivo(const char* nombreArchivo, const char* contenido) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw ERR_ESCRITURA;
    }

    archivo << contenido;
    archivo.close();
}
