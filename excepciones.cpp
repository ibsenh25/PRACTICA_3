#include <iostream>
#include "excepciones.h"
using namespace std;

const char* obtenerMensajeError(int codigo) {
    switch (codigo) {
    case ERR_LECTURA:
        return "Excepcion 1: No se pudo abrir el archivo de entrada.";
    case ERR_ESCRITURA:
        return "Excepcion 2: No se pudo abrir el archivo de salida.";
    case ERR_VACIO:
        return "Excepcion 3: El archivo proporcionado no contiene datos.";
    case ERR_OPCION_INVALIDA:
        return "Excepcion 4: La opcion seleccionada en el menu es invalida.";
    default:
        return "Excepcion Desconocida.";
    }
}
