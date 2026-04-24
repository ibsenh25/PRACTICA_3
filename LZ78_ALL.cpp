#include <iostream>
#include "LZ78_ALL.h"
#include "ENCRI_DESIN.h"
#include "Archivos.h"
#include "excepciones.h"
using namespace std;

int largo(const char* arr) {
    int l = 0;
    while (arr[l] != '\0'){
        l++;
    }
    return l;
}

int leerNumero(char* entrada, int& pos) {
    int num = 0;
    while (entrada[pos]>='0' && entrada[pos]<='9') {
        num = num * 10 + (entrada[pos] - '0');
        pos++;
    }
    return num;
}


int findEntry(Entry* dict, int size, int prefix, char c) {
    for (int i = 1; i < size; i++) {
        if (dict[i].prefix == prefix && dict[i].c == c) {
            return i;
        }
    }
    return -1;
}

char* lz78(char* input) {
    int len = 0;
    while (input[len] != '\0') len++;

    Entry* dict = new Entry[len + 1];
    int dictSize = 1;
    dict[0].prefix = -1;
    dict[0].c = '\0';

    Entry* salidaPares = new Entry[len + 1];
    int numPares = 0;

    int currentPrefix = 0;

    for (int i = 0; i < len; i++) {
        char c = input[i];
        int index = findEntry(dict, dictSize, currentPrefix, c);

        if (index != -1) {
            currentPrefix = index;
        } else {
            salidaPares[numPares].prefix = currentPrefix;
            salidaPares[numPares].c = c;
            numPares++;

            dict[dictSize].prefix = currentPrefix;
            dict[dictSize].c = c;
            dictSize++;

            currentPrefix = 0;
        }
    }

    if (currentPrefix != 0) {
        salidaPares[numPares].prefix = currentPrefix;
        salidaPares[numPares].c = '\0';   // marcador de final
        numPares++;
    }

    int cap_salida = 100;
    char* salida = new char[cap_salida];
    int pos = 0;
    salida[0] = '\0';

    for (int i = 0; i < numPares; i++) {
        int prefijo = salidaPares[i].prefix;
        char c = salidaPares[i].c;

        int esp_necesitado = 0;
        int temp = prefijo;
        if (temp == 0) esp_necesitado = 1;
        else while (temp > 0) { esp_necesitado++; temp /= 10; }
        esp_necesitado += 5;

        if (pos + esp_necesitado >= cap_salida) {
            int nuevaCap = cap_salida * 2;
            char* nueva = new char[nuevaCap];
            for (int j = 0; j < pos; j++) nueva[j] = salida[j];
            delete[] salida;
            salida = nueva;
            cap_salida = nuevaCap;
        }

        salida[pos++] = '(';

        if (prefijo == 0) {
            salida[pos++] = '0';
        } else {
            char buf[12];
            int bufLen = 0;
            int n = prefijo;
            while (n > 0) {
                buf[bufLen++] = (n % 10) + '0';
                n /= 10;
            }
            for (int j = bufLen - 1; j >= 0; j--) {
                salida[pos++] = buf[j];
            }
        }

        salida[pos++] = ',';
        salida[pos++] = ' ';

        if (c == '\0') {
            salida[pos++] = '?';
        } else {
            salida[pos++] = c;
        }

        salida[pos++] = ')';
        salida[pos++] = '\n';
    }

    salida[pos] = '\0';

    delete[] dict;
    delete[] salidaPares;

    return salida;
}


char* anti_lz78(char* entrada) {
    int capacidad = 10;
    Entry* diccionario = new Entry[capacidad];
    char** frases = new char*[capacidad];
    int tamDic = 1;
    frases[0] = new char[1];
    frases[0][0] = '\0';
    diccionario[0].prefix = -1;
    diccionario[0].c = '\0';

    int pos = 0;
    int len = largo(entrada);
    int capSalida = 100;
    char* salida = new char[capSalida];
    int posSalida = 0;
    salida[0] = '\0';

    while (pos < len) {
        while (pos < len && entrada[pos] != '('){
            pos++;
            if (pos >= len){
                break;
            }
        }
        pos++;


        int prefijo = 0;
        while (pos < len && entrada[pos] >= '0' && entrada[pos] <= '9'){
            prefijo = prefijo * 10 + (entrada[pos] - '0');
            pos++;
        }


        while (pos < len && entrada[pos] != ','){
            pos++;
        }
        if (pos < len){
            pos++;
        }
        while (pos < len && entrada[pos] == ' '){
            pos++;
        }

        char c = entrada[pos];
        pos++;


        while (pos < len && entrada[pos] != '('){
            pos++;
        }

        char* frasePrefijo = frases[prefijo];
        int lenPrefijo = 0;
        while (frasePrefijo[lenPrefijo] != '\0'){
            lenPrefijo++;
        }

        if (c == '?') {
            int needed = lenPrefijo;
            if (posSalida + needed >= capSalida){
                int nuevaCap = capSalida * 2;
                char* nueva = new char[nuevaCap];
                for (int i = 0; i < posSalida; i++){
                    nueva[i] = salida[i];
                }
                delete[] salida;
                salida = nueva;
                capSalida = nuevaCap;
            }
            for (int i = 0; i < needed; i++){
                salida[posSalida++] = frasePrefijo[i];
            }
            salida[posSalida] = '\0';
        }
        else {
            int nuevaLen = lenPrefijo + 2;
            char* nuevaFrase = new char[nuevaLen];
            int idx = 0;
            for (int i = 0; i < lenPrefijo; i++){
                nuevaFrase[idx++] = frasePrefijo[i];
            }
            nuevaFrase[idx++] = c;
            nuevaFrase[idx] = '\0';

            if (tamDic >= capacidad) {
                int nuevaCap = capacidad * 2;
                Entry* nuevoDict = new Entry[nuevaCap];
                char** nuevasFrases = new char*[nuevaCap];
                for (int i = 0; i < capacidad; i++) {
                    nuevoDict[i] = diccionario[i];
                    nuevasFrases[i] = frases[i];
                }
                delete[] diccionario;
                delete[] frases;
                diccionario = nuevoDict;
                frases = nuevasFrases;
                capacidad = nuevaCap;
            }

            diccionario[tamDic].prefix = prefijo;
            diccionario[tamDic].c = c;
            frases[tamDic] = nuevaFrase;
            tamDic++;

            int needed = nuevaLen - 1;
            if (posSalida + needed >= capSalida) {
                int nuevaCap = capSalida * 2;
                char* nueva = new char[nuevaCap];
                for (int i = 0; i < posSalida; i++) nueva[i] = salida[i];
                delete[] salida;
                salida = nueva;
                capSalida = nuevaCap;
            }
            for (int i = 0; i < needed; i++) {
                salida[posSalida++] = nuevaFrase[i];
            }
            salida[posSalida] = '\0';
        }
    }

    for (int i = 0; i < tamDic; i++){
        delete[] frases[i];
    }
    delete[] diccionario;
    delete[] frases;

    return salida;
}


bool verificar(char* A, char* B) {
    int i = 0;
    while (A[i] != '\0' && B[i] != '\0') {
        if (A[i] != B[i]) return false;
        i++;
    }
    return (A[i] == '\0' && B[i] == '\0');
}



void integrador_LZ78(const char* archivoEntrada, const char* archivoSalida, int n, char clave) {
    try {
        char* original = leerArchivo(archivoEntrada);
        cout << "Texto original: " << original << endl;

        char* comprimido = lz78(original);
        cout << "Comprimido LZ78:"<<endl << comprimido << endl;

        char* rotado = rotar_bits(comprimido, n);
        char* encriptado = xor_cadena(rotado, clave);
        cout<<"Aplicacion de Xor y rotacion de "<<n<<" bits: "<<encriptado<<endl;

        char* desencriptadoXOR = anti_xor(encriptado, clave);
        char* desrotado = anti_rotar(desencriptadoXOR, n);
        cout<<"Desrotacion y 2da aplicacion de la clave xor: "<<desrotado<<endl;

        char* final = anti_lz78(desrotado);

        if (verificar(original, final)) {
            cout << "VERIFICACION EXITOSA" << endl;
            escribirArchivo(archivoSalida, final);
        } else {
            cout << "VERIFICACION FALLIDA" << endl;
        }

        delete[] original;
        delete[] comprimido;
        delete[] rotado;
        delete[] encriptado;
        delete[] desencriptadoXOR;
        delete[] desrotado;
        delete[] final;

    } catch (int e) {
        cerr << obtenerMensajeError(e) << endl;
    } catch (const char* e) {
        cerr << e << endl;
    }
}

