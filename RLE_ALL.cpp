#include <iostream>
#include <string>
#include "RLE_ALL.h"
#include "ENCRI_DESIN.h"
#include "Archivos.h"
#include "excepciones.h"
using namespace std;

string RLE(string cadena) {
    if(cadena.empty()){
        return "";
    }

    string resultado;
    int i = 0;

    int longitud = cadena.length();

    while(i < longitud) {
        char actual = cadena[i];
        int contador = 1;

        while(i + contador < longitud && cadena[i + contador] == actual) {
            contador++;
        }

        resultado += to_string(contador);
        resultado += actual;

        i += contador;
    }

    return resultado;
}


string anti_RLE(string cadena) {
    if(cadena.empty()) {
        return "";
    }

    string resultado;
    int i = 0;
    int longitud = cadena.length();

    while(i < longitud) {
        string sub;
        while(i < longitud && isdigit(cadena[i])) {
            sub += cadena[i];
            i++;
        }

        int veces = stoi(sub);

        char letra = cadena[i];
        i++;

        for(int j = 0; j < veces; j++) {
            resultado += letra;
        }
    }

    return resultado;
}


void integrador_RLE(const char* archivoEntrada, const char* archivoSalida, int n, char clave) {
    try {
        char* texto = leerArchivo(archivoEntrada);
        string original(texto);
        delete[] texto;

        cout << "Texto original: " << original << endl;

        string comprimido = RLE(original);
        cout << "Comprimido RLE: " << comprimido << endl;

        string rotado = rotar_RLE(comprimido, n);
        string encriptado = xor_RLE(rotado, clave);
        cout<<"Aplicacion de Xor y rotacion de "<<n<<" bits: "<<encriptado<<endl;

        string desencriptadoXOR = anti_xor_RLE(encriptado, clave);
        string descomprimidoRLE = anti_rotar_RLE(desencriptadoXOR, n);
        cout<<"Desrotacion y 2da aplicacion de la clave xor: "<<descomprimidoRLE<<endl;

        string final = anti_RLE(descomprimidoRLE);

        if (original == final) {
            cout << "VERIFICACION EXITOSA" << endl;
            escribirArchivo(archivoSalida, final.c_str());
            cout << "Resultado guardado en: " << archivoSalida << endl;
        } else {
            cout << "VERIFICACION FALLIDA" << endl;
        }

    } catch (int e) {
        cerr << obtenerMensajeError(e) << endl;
    } catch (const char* e) {
        cerr << e << endl;
    }
}





