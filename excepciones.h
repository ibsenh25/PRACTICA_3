#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

const int ERR_LECTURA = 1;
const int ERR_ESCRITURA = 2;
const int ERR_VACIO = 3;
const int ERR_OPCION_INVALIDA = 4;


const char* obtenerMensajeError(int codigo);

#endif // EXCEPCIONES_H
